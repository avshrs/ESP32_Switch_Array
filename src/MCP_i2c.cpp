
#include "MCP_i2c.h"
#include <Arduino.h>


void MCP_i2c::i2c_init(uint8_t bus, uint8_t address_)
{
    
    address = address_;
    mcp_bus = bus;
    int sda = 33;
    int scl = 32;
    int sda2 = 18;
    int scl2 = 19;
    if (mcp_bus == 1)
    {
        Wire.begin(sda, scl);
    }
    else if(mcp_bus == 2)
    {
        Wire1.begin(sda2, scl2);
    }
}

uint8_t MCP_i2c::readByte(uint8_t reg)
{
    uint8_t buf[1] = {0};
    if (mcp_bus == 1)
    {
        Wire.beginTransmission(address);
        Wire.requestFrom(reg, 1);
        Wire.readBytes(buf, 1);
        Wire.endTransmission();

    }
    else if(mcp_bus == 2)
    {
        Wire1.beginTransmission(address);
        Wire1.requestFrom(reg, 1);
        Wire1.readBytes(buf, 1);
        Wire1.endTransmission();
        
    }
    uint8_t d = buf[0];
    return d;
}


void MCP_i2c::writeByte(uint8_t reg, uint8_t buf)
{
        if (mcp_bus == 1)
    {
        Wire.beginTransmission(address);
        Wire.write(reg);
        Wire.write(buf);
        Wire.endTransmission();        
        
    }
    else if(mcp_bus == 2)
    {
        Wire1.beginTransmission(address);
        Wire1.write(reg);
        Wire1.write(buf);
        Wire1.endTransmission();        
        
    }
    
    
}
