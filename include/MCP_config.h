#pragma once
#include <Arduino.h>
#include "vars.h"



class MCP_CONFIG
{

    public:
        MCP_IN_CONFIG mcp_in_config[64];
        MCP_OUT_CONFIG mcp_out_config[128];
        void init();
        
        String get_out_name(uint8_t out);
        String get_out_unique_id(uint8_t out);
        String get_out_dev_class(uint8_t out);
        String get_out_dev_group(uint8_t out);
        bool get_out_define_state(uint8_t out);
        bool get_out_enabled(uint8_t out);
        bool get_out_bistable(uint8_t out);
        bool get_out_input_rel(uint8_t out);

        
        String get_in_name(uint8_t in);
        String get_in_unique_id(uint8_t in);
        String get_in_dev_class(uint8_t in);
        bool get_in_enabled(uint8_t in);
        bool get_in_enabledOutputRelated(uint8_t in);
        uint8_t get_in_output_related(uint8_t in);
    
        uint8_t get_input_len();
        uint8_t get_output_len();
        
        
};