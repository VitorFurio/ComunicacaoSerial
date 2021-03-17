#include <Embedded_Protocol_2.h>

/*   Embedded_Protocol_2 example

   Biblioteca que cria crenças e envia crenças ja no formato "literal" --> CrençaExemplo(parametro1, parametro2, ... ,parametroN).
     
      Para criar uma crença com essa biblioteca utilizamos tres funcoes:
         - startBelief(String beliefName) :  cria a creça com o nome que lhe e passado.
         - beliefAdd(String msg | int Int | float Float) : adiciona parametros a crença criada anteriormente. Pode ser chamada quantas vezes for necessario e pode receber dados do tipo String, int e float.
         - endBelief() : fecha a crença em que estavamos adicionando paramentros e adiciona-a (amazena-a) ao conjunto de crenças, deixando-a pronta para ser enviada.
     
     Para enviarmos o conjunto de crenças que criamos atraves dos passos acima usamos a funçao sendMessage(). 
     Depois de invocada essa funçao limpa todas as crenças que estao armazenadas.    
 */
 
 
  
  Communication com;
  
  int parametro1 = 10;
  float parametro2 = 13.1416;
  String parametro3 = "teste";
  
  void setup() {
    Serial.begin(9600);
  }
  
  void loop() {
    com.startBelief("belief");
    com.beliefAdd(parametro1);
    com.beliefAdd(parametro2);
    com.beliefAdd(parametro3);
    com.endBelief();
    
    com.sendMessage();
    delay(100);
  }
