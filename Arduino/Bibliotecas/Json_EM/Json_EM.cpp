/*
 *  Json_EM.cpp
 *  
 *  T: biblioteca usada pelo atuador (arduino) para mandar os dados "para cima"
 */

#include "Arduino.h"
#include "Json_EM.h"


void Communication::startBelief(String beliefName){
if(_allBeliefs.length() != 0){
      _allBeliefs.concat(_separator);
    }
    
    _beliefBuffer = "";
    _beliefBuffer.concat("\"");
    _beliefBuffer.concat(beliefName);
    _beliefBuffer.concat("\"");
    _beliefBuffer.concat(": [");
}

void Communication::endBelief(){
    _beliefBuffer.setCharAt(_beliefBuffer.length()-1,']');
    _allBeliefs.concat(_beliefBuffer);
    _beliefBuffer = "";
}

void Communication::beliefAdd(String msg){
   _beliefBuffer.concat("\"");
    _beliefBuffer.concat(msg);
    _beliefBuffer.concat("\"");
    _beliefBuffer.concat(',');
}

void Communication::beliefAdd(int Int){
	_beliefBuffer.concat(String(Int));
	_beliefBuffer.concat(',');
}

void Communication::beliefAdd(float Float){
	char result[8];
	dtostrf(Float, 6, 3, result);
	_beliefBuffer.concat(result);
	_beliefBuffer.concat(',');
}

void Communication::beliefAdd(double Double){
     char result[16];
     dtostrf(Double, 6, 5, result);
     _beliefBuffer.concat(result);
     _beliefBuffer.concat(',');
}

void Communication::sendMessage(){
    
    Serial.print(_preamble);
    Serial.print(_allBeliefs.length());
    Serial.print(_start_message);
    Serial.print('{');
    Serial.print(_allBeliefs);
    Serial.print("\n}");
    Serial.println(_end_message);
	
    _allBeliefs = "";
}

