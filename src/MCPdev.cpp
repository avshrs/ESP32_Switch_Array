#include <Arduino.h>
#include "MCPdev.h"
#include "MCP_i2c.h"

void MCP::MCP_Init(uint8_t bus, uint8_t MCPADDRESS, uint8_t GIPOA_TYPE, uint8_t GIPOA_PULL, uint8_t GIPOB_TYPE, uint8_t GIPOB_PULL){
    mcpAddress = MCPADDRESS;
    mcp_bus = bus;
    // mcp_i2c.i2c_init(bus, mcpAddress);

    mcp_i2c.writeByte(IODIRA, GIPOA_TYPE, mcp_bus,  mcpAddress);   // register 0 is the I/O direction register for Port A

    if (GIPOA_PULL == 0xFF && GIPOA_TYPE == 0xFF){
        mcp_i2c.writeByte(GPPUA, 0xFF, mcp_bus,  mcpAddress);   // register 0 is the I/O direction register for Port A
    }

    mcp_i2c.writeByte(IODIRB, GIPOB_TYPE, mcp_bus,  mcpAddress);   // register 0 is the I/O direction register for Port A

    if (GIPOB_PULL == 0xFF && GIPOB_TYPE == 0xFF){
        mcp_i2c.writeByte(GPPUB, 0xFF, mcp_bus,  mcpAddress);   // register 0 is the I/O direction register for Port A
        
    }
}

bool MCP::readRaw(uint8_t side, uint8_t io_number){
    uint8_t mask = (1 << io_number);
    uint8_t v = ~(convert_bits(mcp_i2c.readByte(side, mcp_bus,  mcpAddress)));

    if ((v & mask) > 0)
        return true;
    else
        return false;
}

void MCP::writeRaw(uint8_t side, uint8_t io_number, bool state){
    uint8_t mask = (1 << io_number);

    if (state && (output[side] & mask) == 0){
            output[side] |= mask;
    }
    else if ((output[side] & mask) > 0){
        output[side] &= ~mask;

    }
    mcp_i2c.writeByte(side, convert_bits(output[side]), mcp_bus,  mcpAddress);   
}



uint8_t MCP::convert_bits(uint8_t bits){
    uint8_t tmp = bits;
    int s = sizeof(bits) * 8 - 1;
    for (bits>>= 1; bits; bits>>= 1){   
        tmp <<= 1;
        tmp |= bits& 1;
        s--;
    }
    tmp <<= s;
    return tmp;
}

void MCP::print(uint8_t v){
    for (uint8_t i = 0 ; i < (sizeof(v)*8) ; ++i){
        if ((v & (1 << i )) > 0) 
            Serial.print("1");
        else
            Serial.print("0");
            
    }
    Serial.println();
}