/*
 *  Embedded_Protocol_2.cpp
 *  
 *  T: biblioteca usada pelo atuador (arduino) para mandar os dados "para cima"
 */

#include "Arduino.h"
#include "Embedded_Protocol_2.h"


void Communication::startBelief(String beliefName){
	_beliefBuffer = "";
	_beliefBuffer.concat(beliefName);
	_beliefBuffer.concat('(');
}

void Communication::endBelief(){
	_beliefBuffer.setCharAt(_beliefBuffer.length()-1,')');
	_allBeliefs.concat(_beliefBuffer);
	_allBeliefs.concat(_separator);
	_beliefBuffer = "";
}

void Communication::beliefAdd(String msg){
	_beliefBuffer.concat(msg);
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

void Communication::sendMessage(){
	Serial.print(_preamble);
	Serial.print(_allBeliefs.length());
	Serial.print(_start_message);
	Serial.print(_allBeliefs);
	Serial.println(_end_message);
	
	_allBeliefs = "";
}

