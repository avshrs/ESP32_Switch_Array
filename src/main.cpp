
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
            String binary_sensor = "\"state_topic\":\"~/state/in_"+ (String)i + "\",\"payload_on\":\"ON\",\"payload_off\":\"OFF\",\"device_class\":\"";
            binary_sensor += mcp_config.get_in_dev_class(i) + "\"}";
            String binary_sensor_ = make_discover_json("binary_sensor", "switch_array_01", "AvsHrs-01", mcp_config.get_in_name(i), mcp_config.get_in_unique_id(i), binary_sensor);
            String topic = "homeassistant/binary_sensor/switch_array_01/" + mcp_config.get_in_unique_id(i) + "/config";
            client.publish(topic.c_str(), binary_sensor_.c_str(), true);
        }
    }
    for(int i = 0; i < (int)mcp_config.get_output_len(); i++)
    {
        if(mcp_config.get_out_enabled(i))
        {
            String switch_dev;
            if(mcp_config.get_out_dev_group(i) == "lock")
            {
                switch_dev = "\"command_topic\":\"~/set_state/out_"+ (String)i + "\",\"state_topic\":\"~/state/out_"+ (String)i ;
                switch_dev +="\",\"payload_lock\":\"OFF\",\"payload_unlock\":\"ON\",\"state_locked\":\"OFF\",\"state_unlocked\":\"ON\" }";
            }
                
            else
            {
                switch_dev = "\"command_topic\":\"~/set_state/out_"+ (String)i + "\",\"state_topic\":\"~/state/out_"+ (String)i + "\",\"device_class\":\"";
                switch_dev += mcp_config.get_out_dev_class(i);
                switch_dev += "\"}";
            }
                
            
            String switch_dev_ = make_discover_json("switch", "switch_array_01", "Smart_Switch_Array-01", mcp_config.get_out_name(i), mcp_config.get_out_unique_id(i), switch_dev);
            String topic = "homeassistant/" + mcp_config.get_out_dev_group(i) + "/switch_array_01/";
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
            String topic = "avshrs/devices/switch_array_01/set_state/out_" + (String)i ;

            client.subscribe(topic.c_str());
        }
   
    }

}

void callback(char* topic, byte* payload, unsigned int length) 
{
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    String tp = topic;

    String st;
    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
        st +=(char)payload[i];
    }
    Serial.println();
    if (st !="")
    {
        String nr = tp.substring(tp.indexOf("out_")+4);
        if (st == "ON")
            mcp.write_output(int(nr.toInt()), true, 999, false);
        else if (st == "OFF")
            mcp.write_output(int(nr.toInt()), false, 999, false);
    }
}

void setup() 
{
    Serial.begin(1000000);
    int sda2 = 18;
    int scl2 = 19;    
    int sda = 33;
    int scl = 32;
    Wire.begin(sda, scl);
    Serial.println("I2C 1 bus initialized");

    Wire1.begin(sda2, scl2);
    Serial.println("I2C 2 bus initialized");

    pinMode(BUILTIN_LED, OUTPUT);  
    digitalWrite(BUILTIN_LED, LOW);   

    setup_wifi();

    client.setServer(mqtt_server, 1883);
    client.setBufferSize(2048);
    client.setCallback(callback);

    reconnect();

    mcp_config.init();
    mcp.register_mcp_config(&mcp_config);
    mcp.register_mqtt_client(&client);
    mcp.MCP_Init();
   
    subscribe_switches();
    publish_mqtt_discover();
    
    mcp.update_io();

}

void update_statuses()
{
    for(int i = 0; i < mcp_config.get_input_len(); i++)    
    {
        String topic = "avshrs/devices/switch_array_01/state/in_" + (String)i;
        if(mcp.read_input_buffer(i) && mcp_config.get_in_enabled(i))
        {
            client.publish(topic.c_str(), "ON");
        }
        else
        {
            client.publish(topic.c_str(), "OFF");
        }
    }
    for(int i = 0; i < mcp_config.get_output_len(); i++)    
    {
        String topic = "avshrs/devices/switch_array_01/state/out_" + (String)i;

        if(mcp.read_output_buffer(i) && mcp_config.get_out_enabled(i))
        {
            client.publish(topic.c_str(), "ON");
        }
        else
        {
            client.publish(topic.c_str(), "OFF");
        }
    }
}


void loop() 
{
    currentMillis = millis();
    
    if (!client.connected()) 
    {
        reconnect();
    }
    
    if (currentMillis - previousMillis >= 60000) 
    {
        previousMillis = currentMillis;
        wifi_status();
        client.publish("avshrs/devices/switch_array_01/status/connected", "true");
        update_statuses();
    }
    client.loop();
    mcp.scan_all_inputs();
}