#pragma once
#include <Wire.h>

class MCP_i2c{
    private:
        int file_i2c;
        int length=2;
        uint8_t mcp_bus;
        uint8_t address;
    
    private:
        void print(uint8_t v);
    
    public:
        void i2c_init(uint8_t bus, uint8_t address_);
        
        uint8_t readByte(uint8_t reg);
        void writeByte(uint8_t side, uint8_t buffer_);
        
        uint16_t readWord(uint8_t reg);
        void writeWord(uint8_t reg, uint16_t buffer_);

};

