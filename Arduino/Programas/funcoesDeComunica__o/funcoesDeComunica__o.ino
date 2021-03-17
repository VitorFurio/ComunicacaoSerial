  /* Biblioteca que cria crenças ja no formato "literal" --> CrençaExemplo(parametro1, parametro2, ... ,parametroN).
     
      Para criar uma crença com essa biblioteca utilizamos tres funcoes:
         - startBelief(String beliefName) :  cria a creça com o nome que lhe e passado.
         - beliefAdd(String msg | int Int | float Float) : adiciona parametros a crença criada anteriormente. Pode ser chamada quantas vezes for necessario e pode receber dados do tipo String, int e float.
         - endBelief() : fecha a crença em que estavamos adicionando paramentros e adiciona-a (amazena-a) ao conjunto de crenças, deixando-a pronta para ser enviada.
     
     Para enviarmos o conjunto de crenças que criamos atraves dos passos acima usamos a funçao sendMessage(). 
     Depois de invocada essa funçao limpa todas as crenças que estao armazenadas.    
      
  */
  
  String _beliefBuffer;
  String _allBeliefs;
  
  String _preamble = "==";
  String _start_message = "::";
  String _end_message = "--";
  String _separator = "/";
  
  
  int a = 10;
  float b = 13.1416;
  String c = "teste";
  
  void setup() {
    Serial.begin(9600);
  }
  
  void loop() {
    delay(100);
    startBelief("teste");
    beliefAdd(a);
    beliefAdd(b);
    beliefAdd(c);
    endBelief();
    
    sendMessage();
    
  }
  
  void startBelief(String beliefName){ // inicia uma crença
    _beliefBuffer = "";
    _beliefBuffer.concat(beliefName);
    _beliefBuffer.concat('(');
  }
  
   void endBelief(){ // finaliza uma crença
    _beliefBuffer.setCharAt(_beliefBuffer.length()-1,')');
    _allBeliefs.concat(_beliefBuffer);
    _allBeliefs.concat(_separator);
    _beliefBuffer = "";
  }
  
  void beliefAdd(String msg){ // adiciona um parametro do tipo string a crença. 
    _beliefBuffer.concat(msg);
    _beliefBuffer.concat(',');
  }
  
  void beliefAdd(int Int){ // adiciona um parametro do tipo inteiro (int) a crença.
    _beliefBuffer.concat(String(Int));
    _beliefBuffer.concat(',');
  }
  
   void beliefAdd(float Float){ // adiciona um parametro de ponto flutuante (float) a crença.
     char result[8];
     dtostrf(Float, 6, 3, result);
     _beliefBuffer.concat(result);
     _beliefBuffer.concat(',');
  }
  
  void sendMessage(){
    Serial.print(_preamble);
    Serial.print(_allBeliefs.length());
    Serial.print(_start_message);
    Serial.print(_allBeliefs);
    Serial.println(_end_message);
	
    _allBeliefs = "";
  }
