#include<Embedded_Protocol.h>
#include<ArduinoJson.h>

#define led 13

Communication communication;
const int capacity = JSON_OBJECT_SIZE(6);
StaticJsonDocument<capacity> doc;

void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop()
{
  if(Serial.available() > 0)
  {  char c = Serial.read();
    if(c == 'a')
    {
      for(int i=0; i<4; i++){
        digitalWrite(led,HIGH);
        delay(200);
        digitalWrite(led,LOW);
        delay(100);
      }
    }
  }  
  
  doc["milis"] = millis();
  String output = doc.as<String>();
  communication.create_belief(output);
  delay(200);
}
