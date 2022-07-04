#pragma once

#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <Wire.h>

#include "passwd.h"
#include "Esp.h"
EspClass ESP2;

#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
unsigned long currentMillis;

WiFiClient espClient;
PubSubClient client(espClient);
String IpAddress2String(const IPAddress& ipAddress)
{
  return String(ipAddress[0]) + String(".") +\
  String(ipAddress[1]) + String(".") +\
  String(ipAddress[2]) + String(".") +\
  String(ipAddress[3])  ; 
}

String HexString2ASCIIString(String hexstring) {
  String temp = "", sub = "", result;
  char buf[3];
  for(int i = 0; i < hexstring.length(); i += 2){
    sub = hexstring.substring(i, i+2);
    sub.toCharArray(buf, 3);
    char b = (char)strtol(buf, 0, 16);
    if(b == '\0')
      break;
    temp += b;
  }
  return temp;
}

unsigned long old_mils = 60000;





void reconnect() 
{
  // Loop until we're reconnected
    if (!client.connected())
    { 
        if (millis() - old_mils > 60000)
        {
            old_mils = millis();
            Serial.print("Attempting MQTT connection...");
            // Create a random client ID
            String clientId = "ESP_Avshrs_switch_gate";
            
            clientId += String(random(0xffff), HEX);
            // Attempt to connect
            if (client.connect(clientId.c_str(),"mqttuser", "mqttuser")) 
            {
                Serial.println("connected to MQTT server");
                // MQTT subscription

                // prepare_conf();

            } 
        }
    }
}

String uptime(unsigned long milli)
{
  static char _return[32];
  unsigned long secs=milli/1000, mins=secs/60;
  unsigned int hours=mins/60, days=hours/24;
  milli-=secs*1000;
  secs-=mins*60;
  mins-=hours*60;
  hours-=days*24;
  sprintf(_return,"Uptime %d days %2.2d:%2.2d:%2.2d.%3.3d", (byte)days, (byte)hours, (byte)mins, (byte)secs, (int)milli);
  String ret =  _return;
  return ret;
}
     

void wifi_status()
{
    String ip = IpAddress2String(WiFi.localIP());
    client.publish("avshrs/devices/switch_array_01/status/wifi_ip", ip.c_str());
    String mac = WiFi.macAddress();
    client.publish("avshrs/devices/switch_array_01/status/wifi_mac", mac.c_str());
    snprintf (msg, MSG_BUFFER_SIZE, "%i", WiFi.RSSI());
    client.publish("avshrs/devices/switch_array_01/status/wifi_rssi", msg);
    int signal = 2*(WiFi.RSSI()+100);
    snprintf (msg, MSG_BUFFER_SIZE, "%i", signal);
    client.publish("avshrs/devices/switch_array_01/status/wifi_signal_strength", msg);
    
    client.publish("avshrs/devices/switch_array_01/status/uptime", uptime(currentMillis).c_str(), true);

    snprintf (msg, MSG_BUFFER_SIZE, "%i", ESP2.getFreeHeap());
    client.publish("avshrs/devices/switch_array_01/status/FreeHeap", msg, true);

    snprintf (msg, MSG_BUFFER_SIZE, "%i", ESP2.getHeapSize());
    client.publish("avshrs/devices/switch_array_01/status/HeapSize", msg, true);

    snprintf (msg, MSG_BUFFER_SIZE, "%i", ESP2.getMinFreeHeap());
    client.publish("avshrs/devices/switch_array_01/status/MinFreeHeap", msg, true);

    snprintf (msg, MSG_BUFFER_SIZE, "%i", ESP2.getMaxAllocHeap());
    client.publish("avshrs/devices/switch_array_01/status/MaxAllocHeap", msg, true);
    
    snprintf (msg, MSG_BUFFER_SIZE, "%i", ESP2.getMaxAllocHeap());
    client.publish("avshrs/devices/switch_array_01/status/MaxAllocHeap", msg, true);

    client.publish("avshrs/devices/switch_array_01/status/ChipModel", ESP2.getChipModel(), true);

}


void setup_wifi() 
{
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    randomSeed(micros());

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}
void wifi_fast_reconnect() 
{
    if(WiFi.status() != WL_CONNECTED)
    {
    WiFi.disconnect();
    WiFi.reconnect();
    }
}