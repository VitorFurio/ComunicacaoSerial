/*
 *  Json_EM.h
 *  
 *  T: biblioteca usada pelo atuador (arduino) para mandar os dados "para cima"
 */

#ifndef Json_EM_h    
#define Json_EM_h 

#include "Arduino.h"

class Communication {

        public:
        
          void startBelief(String beliefName);
          void beliefAdd(String msg);
          void beliefAdd(int Int);
          void beliefAdd(float Float);
          void beliefAdd(double Double);
          void endBelief();
          void sendMessage();
      
        private:
	  String _beliefBuffer = "";
	  String _allBeliefs = "";
          
          String _preamble = "==";
          String _start_message = "::";
          String _end_message = "--";
           String _separator = ",\n  ";
};

#endif
