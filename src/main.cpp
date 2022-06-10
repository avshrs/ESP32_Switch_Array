#include "passwd.h"
#include "wifi_mqtt.h"
#include "MCP_Manager.h"
#include "MCP_config.h"

int d = 1; 
unsigned long previousMillis = 0;  
String state = "n/a";
MCP_Manager mcp; 
MCP_CONFIG mcp_config; 
String make_discover_json(String dev_type_, String dev_name_, String dev_name_ha, String  sens_name, String  unique_id, String entity_settings)
{
String md = (String)"{\"avty\":{\"topic\":\"avshrs/devices/" + (String)dev_name_ ;
md += (String)"/status/connected\",\"payload_available\":\"true\",\"payload_not_available\":\"false\"},\"~\":\"avshrs/devices/"+(String)dev_name_+"\",";
md += (String)"\"device\":{\"ids\":\"" + (String)dev_name_ + (String)"\",\"mf\":\"Avshrs\",\"name\":\""+ (String)dev_name_ha + (String)"\",\"sw\":\"0.0.1\"},";
md += (String)"\"name\":\""+ (String)sens_name + (String)"\",\"uniq_id\":\""+ (String)unique_id + "\",\"qos\":0," ;
md += (String)entity_settings;
return md;
}

void publish_mqtt_discover()
{
    for(int i = 0; i < (int)mcp_config.get_input_len(); i++)
    {
        if(mcp_config.get_in_enabled(i))
        {
            String binary_sensor = "\"state_topic\":\"~/"+ (String)i+"/state\",\"device_class\":\"";
            binary_sensor += mcp_config.get_in_dev_class(i);
            binary_sensor += "\"}";
            String binary_sensor_ = make_discover_json("binary_sensor", "switch_array_01", "AvsHrs-01", mcp_config.get_in_name(i), mcp_config.get_in_unique_id(i)+(String)"_01", binary_sensor);
            String topic = "homeassistant/binary_sensor/switch_array_01/";
            topic +=  mcp_config.get_in_unique_id(i);
            topic +=  "/config";

            client.publish(topic.c_str(), binary_sensor_.c_str(), true);
        }
   
    }
    for(int i = 0; i < (int)mcp_config.get_output_len(); i++)
    {
        if(mcp_config.get_out_enabled(i))
        {
            String switch_dev = "\"command_topic\":\"~/"+ (String)i +"/set_state\",\"state_topic\":\"~/"+ (String)i+"/state\",\"device_class\":\"";
            switch_dev += mcp_config.get_out_dev_class(i);
            switch_dev += "\"}";
            String switch_dev_ = make_discover_json("switch", "switch_array_01", "AvsHrs-01", mcp_config.get_out_name(i), mcp_config.get_out_unique_id(i)+(String)"_01", switch_dev);
            String topic = "homeassistant/switch/switch_array_01/";
            topic +=  mcp_config.get_out_unique_id(i);
            topic +=  "/config";

            client.publish(topic.c_str(), switch_dev_.c_str(), true);
        }
   
    }
}

void callback(char* topic, byte* payload, unsigned int length) 
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    String st;
    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
        st +=(char)payload[i];
    }
    Serial.println();
}

void setup() 
{
    Serial.begin(1000000);
    
    mcp_config.init();
    mcp.register_mcp_config(&mcp_config);

    pinMode(BUILTIN_LED, OUTPUT);  
    digitalWrite(BUILTIN_LED, LOW);   
    setup_wifi();

    client.setServer(mqtt_server, 1883);
    client.setBufferSize(2048);
    client.setCallback(callback);
    
}


void loop() 
{
    currentMillis = millis();
    mcp.MCP_Init();
    if (!client.connected()) 
    {
        reconnect();
        publish_mqtt_discover();
    }
    client.loop();
    mcp.MCP_Init();
    
}