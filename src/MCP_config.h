#include <Arduino.h>


struct MCP_I2C_CONFIG
{
    uint8_t bus; // 1 | 2 
    char *type;  //in | out
    uint8_t address; //0x20
};




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


class MCP_CONFIG
{
    public
}