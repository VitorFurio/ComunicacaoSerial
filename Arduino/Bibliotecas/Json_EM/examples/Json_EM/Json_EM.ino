  /* Biblioteca que cria crenças ja no formato "literal" --> CrençaExemplo(parametro1, parametro2, ... ,parametroN).
     
      Para criar uma crença com essa biblioteca utilizamos tres funcoes:
         - startBelief(String beliefName) :  cria a creça com o nome que lhe e passado.
         - beliefAdd(String msg | int Int | float Float | double Double) : adiciona parametros a crença criada anteriormente. Pode ser chamada quantas vezes for necessario e pode receber dados do tipo String, int e float.
         - endBelief() : fecha a crença em que estavamos adicionando paramentros e adiciona-a (amazena-a) ao conjunto de crenças, deixando-a pronta para ser enviada.
     
     Para enviarmos o conjunto de crenças que criamos atraves dos passos acima usamos a funçao sendMessage(). 
     Depois de invocada essa funçao limpa todas as crenças que estao armazenadas.  
   
     Obs: os dados devem estar em um dos tres formatos aceitaves (String, int, double ou float). Utilize casting se necessario.
      
  */
  #include<Json_EM.h>
  
  Communication com;
  
  int a = 10;
  float b = 13.1416;
  String c = "teste";
  
  void setup() {
    Serial.begin(9600);
  }
  
  void loop() {
    delay(100);
    com.startBelief("belief1");
    com.beliefAdd(a);
    com.beliefAdd(b);
    com.beliefAdd(c);
    com.endBelief();
    
    com.startBelief("belief2");
    com.beliefAdd("teste2");
    com.beliefAdd("$");
    com.beliefAdd(34.125487);
    com.endBelief();
    
    com.startBelief("belief3");
    com.beliefAdd("true");
    com.endBelief();
    
    com.sendMessage();
  }
