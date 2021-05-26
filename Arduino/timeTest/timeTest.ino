#include<Embedded_Protocol.h>
#include<ArduinoJson.h>

#define led 13

Communication communication;
const int capacity = JSON_OBJECT_SIZE(6);
StaticJsonDocument<capacity> doc;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  doc["milis"] = millis();
  String output = doc.as<String>();
  communication.create_belief(output);
  delay(200);
}
