/*
 *  Embedded_Protocol.h
 *  
 *  T: biblioteca usada pelo atuador (arduino) para mandar os dados "para cima"
 */

#ifndef Embedded_Protocol_h    
#define Embedded_Protocol_h 

#include "Arduino.h"

class Communication {

        public:
          void send_message(String message);
	  void create_belief(String belief);

	  void create_belief(String belief, int value_1);
	  void create_belief(String belief, float value_1);
	  void create_belief(String belief, double value_1);
	  void create_belief(String belief, String value_1);

	  void create_belief(String belief, String value_1, String value_2);
	  void create_belief(String belief, String value_1, String value_2, String value_3);
	  void create_belief(String belief, String value_1, String value_2, String value_3, String value_4);
	  void create_belief(String belief, String value_1, String value_2, String value_3, String value_4, String value_5);
          
          
        private:
          int get_message_length(String msg);
  
          String _preamble = "==";
          String _start_message = "::";
          String _end_message = "--";
};

#endif
