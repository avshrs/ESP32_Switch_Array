
#pragma once

#include "MCPdev.h"
#include "vars.h"
#include "MCP_config.h"
#include "PubSubClient.h"

class MCP_Manager
{
    
    private:
        MCP_CONFIG *mcp_config;
        PubSubClient *client;

        MCP *mcpc_in[9];
        MCP *mcpc_out[9];

        MCP mcpc_in_0;
        MCP mcpc_in_1;
        MCP mcpc_in_2;
        MCP mcpc_in_3;
        
        
        MCP mcpc_out_0;
        MCP mcpc_out_1;
        MCP mcpc_out_2;
        MCP mcpc_out_3;
        MCP mcpc_out_4;
        MCP mcpc_out_5;
        MCP mcpc_out_6;
        MCP mcpc_out_7;

        
        MCP_Data mcp_data;

        bool in_states[128] = {true};
        bool out_states_real[128] = {false};
        bool out_states[128] = {false};
        uint8_t out_states_forced[128] = {false};
        
    public:
        void MCP_Init();
        void scan_all_inputs();
        void update_io();
        void write_output(int output, bool value, int input, bool force);

        bool read_output_buffer(uint8_t output);
        bool read_input_buffer(uint8_t input);

        bool read_input_direct(uint8_t input);
        void write_output_direct(uint8_t output, bool state);
        
        void register_mcp_config(MCP_CONFIG *config);
        void register_mqtt_client(PubSubClient *client);
        
    private:
        MCP_Data get_address(uint8_t io);
};

