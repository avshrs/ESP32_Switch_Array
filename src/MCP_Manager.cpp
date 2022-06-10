#include "MCP_Manager.h"


void MCP_Manager::MCP_Init(){
    MCP_I2C_CONFIG in_i2c_1 = {1, "in", 0x24};
    MCP_I2C_CONFIG in_i2c_2 = {1, "in", 0x25};
    MCP_I2C_CONFIG in_i2c_3 = {1, "in", 0x26};
    MCP_I2C_CONFIG in_i2c_4 = {1, "in", 0x27};

    MCP_I2C_CONFIG out_i2c_1 = {1, "in", 0x20};
    MCP_I2C_CONFIG out_i2c_2 = {1, "in", 0x21}; 
    MCP_I2C_CONFIG out_i2c_3 = {1, "in", 0x22}; 
    MCP_I2C_CONFIG out_i2c_4 = {1, "in", 0x23}; 
    MCP_I2C_CONFIG out_i2c_5 = {2, "in", 0x20}; 
    MCP_I2C_CONFIG out_i2c_6 = {2, "in", 0x21}; 
    MCP_I2C_CONFIG out_i2c_7 = {2, "in", 0x22}; 
    MCP_I2C_CONFIG out_i2c_8 = {2, "in", 0x23}; 

    mcpc_in_0.MCP_Init(in_i2c_1.bus, in_i2c_1.address, MCP_IN, MCP_PULLUP, MCP_IN, MCP_PULLUP);
    mcpc_in[0]= &mcpc_in_0;

    mcpc_in_1.MCP_Init(in_i2c_2.bus, in_i2c_2.address, MCP_IN, MCP_PULLUP, MCP_IN, MCP_PULLUP);
    mcpc_in[1]= &mcpc_in_1;

    mcpc_in_2.MCP_Init(in_i2c_3.bus, in_i2c_3.address, MCP_IN, MCP_PULLUP, MCP_IN, MCP_PULLUP);
    mcpc_in[2]= &mcpc_in_2;

    mcpc_in_3.MCP_Init(in_i2c_4.bus, in_i2c_4.address, MCP_IN, MCP_PULLUP, MCP_IN, MCP_PULLUP);
    mcpc_in[3]= &mcpc_in_3;
    

    mcpc_out_0.MCP_Init(out_i2c_1.bus, out_i2c_1.address, MCP_OUT, MCP_NOT_PULLUP, MCP_OUT, MCP_NOT_PULLUP);
    mcpc_out[0] = &mcpc_out_0;
    mcpc_out_1.MCP_Init(out_i2c_2.bus, out_i2c_2.address, MCP_OUT, MCP_NOT_PULLUP, MCP_OUT, MCP_NOT_PULLUP);
    mcpc_out[1] = &mcpc_out_1;
    mcpc_out_2.MCP_Init(out_i2c_3.bus, out_i2c_3.address, MCP_OUT, MCP_NOT_PULLUP, MCP_OUT, MCP_NOT_PULLUP);    
    mcpc_out[2] = &mcpc_out_2;
    mcpc_out_3.MCP_Init(out_i2c_4.bus, out_i2c_4.address, MCP_OUT, MCP_NOT_PULLUP, MCP_OUT, MCP_NOT_PULLUP); 
    mcpc_out[3] = &mcpc_out_3;
    mcpc_out_4.MCP_Init(out_i2c_5.bus, out_i2c_5.address, MCP_OUT, MCP_NOT_PULLUP, MCP_OUT, MCP_NOT_PULLUP);
    mcpc_out[4] = &mcpc_out_4;    
    mcpc_out_5.MCP_Init(out_i2c_6.bus, out_i2c_6.address, MCP_OUT, MCP_NOT_PULLUP, MCP_OUT, MCP_NOT_PULLUP);
    mcpc_out[5] = &mcpc_out_5;
    mcpc_out_6.MCP_Init(out_i2c_7.bus, out_i2c_7.address, MCP_OUT, MCP_NOT_PULLUP, MCP_OUT, MCP_NOT_PULLUP);    
    mcpc_out[6] = &mcpc_out_6;
    mcpc_out_7.MCP_Init(out_i2c_8.bus, out_i2c_8.address, MCP_OUT, MCP_NOT_PULLUP, MCP_OUT, MCP_NOT_PULLUP); 
    mcpc_out[7] = &mcpc_out_7; 
    

 }


void MCP_Manager::register_mcp_config(MCP_CONFIG *config)
{
    mcp_config = config;
}

void MCP_Manager::update_io()
{
    for(int i=0; i < static_cast<int>(mcp_config->get_output_len());i++)
    {
        if(mcp_config->get_out_enabled(i))
        {
            if (mcp_config->get_out_define_state(i))
            {
                write_output(i, true, 998);
            }
            else
            {
                write_output(i, false, 998);
            }
        }
    }    
    for(int i=0; i < static_cast<int>(mcp_config->get_input_len());i++)
    {
        if(mcp_config->get_in_enabled(i))
        {
            in_states[i] = read_input_direct(i);   
            // mqtt->pub_in_state(i, in_states[i]);             
            if (mcp_config->get_in_enabledOutputRelated(i))
            {
                int out = mcp_config->get_in_output_related(i);
                if (mcp_config->get_out_enabled(out))
                {
                    write_output(out, in_states[i], 998);
                }
            }
        }
    }    
    
}




void MCP_Manager::scan_all_inputs(){
    for(int in = 0; in < static_cast<int>(mcp_config->get_input_len()) ; in++){
        if (mcp_config->get_in_enabled(in)){
            bool value = read_input_direct(in);
            if (in_states[in] != value){
                in_states[in] = value;
                // mqtt->pub_in_state(in, value);
                int out = mcp_config->get_in_output_related(in);
                if (mcp_config->get_in_enabledOutputRelated(in)){
                    write_output(static_cast<uint8_t>(out), value, in);
                }
            }
        }
        usleep(100);
    }
}



void MCP_Manager::change_state(int output, unsigned int timeout){
    if (!read_output_buffer(output)){
        write_output(output, true, 999);
    }
    for(out_states_forced[output] = timeout; out_states_forced[output] > 0 ; out_states_forced[output]--){
        usleep(1000000);
     }
    if (!read_output_buffer(output)){
        write_output(output, false, 999);
    }
}

void MCP_Manager::write_output(int output, bool value, int in = 999){
    if (mcp_config->get_out_enabled(output)){
        if (!mcp_config->get_out_bistable(output) && out_states[output] != value){
            out_states[output] = value;
            write_output_direct(output, value);
        }
        else if (mcp_config->get_out_bistable(output)){
            if (out_states[output] > 0 && value > 0){
                
                out_states[output] = false;
                write_output_direct(output, false);
            }
            else if (value > 0){
                out_states[output] = true;
                write_output_direct(output, true);
            }
        }
    }
}



bool MCP_Manager::read_input_direct(uint8_t in){
    MCP_Data mcp_data = get_address(in);
    return mcpc_in[mcp_data.chipset]->readRaw(mcp_data.side, mcp_data.io);
}

bool MCP_Manager::read_output_buffer(uint8_t out){
    bool value = out_states_real[out];
    return value;
}   
bool MCP_Manager::read_input_buffer(uint8_t input){
    return in_states[input];
}

void MCP_Manager::write_output_direct(uint8_t out, bool state){
    bool value = state;
    if (mcp_config->get_out_define_state(out)){
        if (state){
            value = false; 
        }
        else{
            value = true;
        }
    }
    // mqtt->pub_out_state(out, state);
    MCP_Data mcp_data = get_address(out);
    out_states_real[out] = state;
    mcpc_out[mcp_data.chipset]->writeRaw(mcp_data.side, mcp_data.io, value);
}

MCP_Data MCP_Manager::get_address(uint8_t io){
    mcp_data.chipset = (io-(io%16))/16;
    if(io-(mcp_data.chipset*16)>7)
        mcp_data.side = 0x12;
    else
        mcp_data.side = 0x13;
    mcp_data.io = (io - (mcp_data.chipset * 16)) % 8;
    return mcp_data;
}

