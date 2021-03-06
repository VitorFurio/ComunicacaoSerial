/*
 *  Embedded_Protocol_2.h
 *  
 *  T: biblioteca usada pelo atuador (arduino) para mandar os dados "para cima"
 */

#ifndef Embedded_Protocol_2_h    
#define Embedded_Protocol_2_h 

#include "Arduino.h"

class Communication {

        public:
        
          void startBelief(String beliefName);
          void beliefAdd(String msg);
          void beliefAdd(int Int);
          void beliefAdd(float Float);
          void endBelief();
          void sendMessage();
      
        private:
	  String _beliefBuffer = "";
	  String _allBeliefs = "";
          
          String _preamble = "==";
          String _start_message = "::";
          String _end_message = "--";
          String _separator = "/";
};

#endif
