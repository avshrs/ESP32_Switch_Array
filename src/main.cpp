#include "passwd.h"
#include "wifi_mqtt.h"
#include "MCP_Manager.h"
#include "MCP_config.h"
// #include "Esp32MQTTClient.h"

int d = 1; 
unsigned long previousMillis = 60001;  
unsigned long previousMillis2 = 600001;  
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
            String binary_sensor = "\"state_topic\":\"~/in_"+ (String)i+"/state\",\"device_class\":\"";
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
            String switch_dev = "\"command_topic\":\"~/out_"+ (String)i +"/set_state\",\"state_topic\":\"~/out_"+ (String)i+"/state\",\"device_class\":\"";
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

void subscribe_switches()
{
    for(int i = 0; i < (int)mcp_config.get_output_len(); i++)
    {
        if(mcp_config.get_out_enabled(i))
        {
            String topic = "avshrs/devices/switch_array_01/out_" + (String)i + (String)"/set_state";

            client.subscribe(topic.c_str());
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
    
    
    pinMode(BUILTIN_LED, OUTPUT);  
    digitalWrite(BUILTIN_LED, LOW);   
    setup_wifi();

    client.setServer(mqtt_server, 1883);
    client.setBufferSize(2048);
    client.setCallback(callback);
    mcp_config.init();
    mcp.register_mcp_config(&mcp_config);
    mcp.MCP_Init();
    mcp.register_mqtt_client(&client);
    mcp.update_io();
    delay(1000);
}


void loop() 
{
    currentMillis = millis();
    mcp.MCP_Init();
    if (!client.connected()) 
    {
        reconnect();
        if(client.connected())
        {
            subscribe_switches();
            publish_mqtt_discover();
        }
    }
    
    if (currentMillis - previousMillis >= 60000) 
    {
        previousMillis = currentMillis;
        wifi_status();


    }

    if (currentMillis - previousMillis2 >= 600000) 
    {
        previousMillis2 = currentMillis;
        client.publish("avshrs/devices/switch_array_01/status/connected", "true");
        publish_mqtt_discover();
        Serial.println("in serice if- main");
    }
    
    Serial.println("before client loop");
    client.loop();
    Serial.println("after client loop");
    Serial.println("before scan loop");
    mcp.scan_all_inputs();
    Serial.println("after scan loop");
    
}