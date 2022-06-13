
#include "MCP_i2c.h"
#include <Arduino.h>


void MCP_i2c::i2c_init(uint8_t bus, uint8_t address_)
{

    int sda2 = 18;
    int scl2 = 19;    
    int sda = 33;
    int scl = 32;
    Wire.begin(sda, scl);
    Serial.println("I2C 1 bus initialized");

    Wire1.begin(sda2, scl2);
    Serial.println("I2C 2 bus initialized");
}

uint8_t MCP_i2c::readByte(uint8_t reg, uint8_t mcp_bus, uint8_t address)
{

    uint8_t buf = 0;
        if (mcp_bus == 1)
        {   
            Wire.beginTransmission(address);
            Wire.write(reg);
            Wire.endTransmission();
            Wire.requestFrom(address, 1);
            return Wire.read();
        }
        else if(mcp_bus == 2)
        {
            Wire1.beginTransmission(address);
            Wire1.write(reg);
            Wire1.endTransmission();
            Wire1.requestFrom(address, 1);
            return Wire.read();
        }
        
    
    
    return buf;
}


void MCP_i2c::writeByte(uint8_t reg, uint8_t buf, uint8_t mcp_bus, uint8_t address)
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
