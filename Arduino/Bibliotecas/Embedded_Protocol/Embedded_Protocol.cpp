/*
 *  Embedded_Protocol.cpp
 *  
 *  T: biblioteca usada pelo atuador (arduino) para mandar os dados "para cima"
 */

#include "Arduino.h"
#include "Embedded_Protocol.h"


void Communication::send_message(String message)
{
  Serial.print(_preamble 
	+ get_message_length(message) 
	+ _start_message 
	+ message 
	+ _end_message);
}

void Communication::create_belief(String belief)
{
  String message = belief;
  send_message(message);
}

void Communication::create_belief(String belief, String value_1)
{
  String message = belief + "(" + value_1 + ")";
  send_message(message);
}

void Communication::create_belief(String belief, float value_1)
{
  String message = belief + "(" + value_1 + ")";
  send_message(message);
}

void Communication::create_belief(String belief, double value_1)
{
  String message = belief + "(" + value_1 + ")";
  send_message(message);
}

void Communication::create_belief(String belief, int value_1)
{
  String message = belief + "(" + value_1 + ")";
  send_message(message);
}

void Communication::create_belief(String belief, String value_1, String value_2)
{
  String message = belief + "(" + value_1 + "," + value_2 + ")";
  send_message(message);
}

void Communication::create_belief(String belief, String value_1, String value_2, String value_3)
{
  String message = belief + "(" + value_1 + "," + value_2 + "," + value_3 + ")";
  send_message(message);
}

void Communication::create_belief(String belief, String value_1, String value_2, String value_3, String value_4)
{
  String message = belief + "(" + value_1 + "," + value_2 + "," + value_3 + "," + value_4 + ")";
  send_message(message);
}

void Communication::create_belief(String belief, String value_1, String value_2, String value_3, String value_4, String value_5)
{
  String message = belief + "(" + value_1 + "," + value_2 + "," + value_3 + "," + value_4 + "," + value_5 + ")";
  send_message(message);
}

int Communication::get_message_length(String msg)
{
  return msg.length();
}
