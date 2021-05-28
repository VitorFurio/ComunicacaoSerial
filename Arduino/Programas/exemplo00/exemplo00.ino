   #include<Ultrasonic.h>
   
   #define led 13
   
   //sensores
   #define trigFrente 7
   #define echoFrente 8
   #define trigEsq 3
   #define echoEsq 4
   #define trigDir 11
   #define echoDir 12

   //motores
   #define motorEsqFrente 6
   #define motorEsqTras 5
   #define motorDirFrente 10
   #define motorDirTras 9
   
   Ultrasonic sensorFrente(trigFrente,echoFrente);
   Ultrasonic sensorEsq(trigEsq,echoEsq);
   Ultrasonic sensorDir(trigDir,echoDir);
   
   //Dados que seram transportados pela serial
  String tipoDado = "$STS";
  long distanciaFrente = 0;
  long distanciaEsq = 0;
  long distanciaDir = 0;
  String movimentacao = "parado"; //status da movimentacao do carro
  
  String separador = ",";
  int velocidade = 200; //varia de 0 a 255
  
  void setup() {
    Serial.begin(9600);
    pinMode(motorEsqFrente,OUTPUT);
    pinMode(motorEsqTras,OUTPUT);
    pinMode(motorDirFrente,OUTPUT);
    pinMode(motorDirTras,OUTPUT);
    pinMode(led,OUTPUT);
    
    digitalWrite(led,LOW);
  }
  
  void loop() {
    delay(100);
    atualizaDados();
    enviaDadosSerial();
  }
  
  void serialEvent() {
    while(Serial.available()>0){
     switch (Serial.read()){
        case 'w': //ir para frente
             digitalWrite(motorEsqTras,LOW);
             digitalWrite(motorDirTras,LOW);
             analogWrite(motorEsqFrente,velocidade);
             analogWrite(motorDirFrente,velocidade);
             movimentacao = "indoParaFrente";
           break;
  
         case 's':// ir para tras
             digitalWrite(motorEsqFrente,LOW);
             digitalWrite(motorDirFrente,LOW);
             analogWrite(motorEsqTras,velocidade);
             analogWrite(motorDirTras,velocidade);
             movimentacao = "indoParaTras";
           break;

         case 'a':// gira para a esquerda
             digitalWrite(motorEsqFrente,LOW);
             digitalWrite(motorDirTras,LOW);
             analogWrite(motorEsqTras,velocidade);
             analogWrite(motorDirFrente,velocidade);
             movimentacao = "girandoParaEsquerda";
           break;

         case 'd':// gira para a direita
             digitalWrite(motorEsqTras,LOW);
             digitalWrite(motorDirFrente,LOW);
             analogWrite(motorEsqFrente,velocidade);
             analogWrite(motorDirTras,velocidade);
             movimentacao = "girandoParaDireira";
           break;

         case 'e'://para o carro
             digitalWrite(motorEsqFrente,LOW);
             digitalWrite(motorDirFrente,LOW);
             digitalWrite(motorEsqTras,LOW);
             digitalWrite(motorDirTras,LOW);
              movimentacao = "parado";
           break;
           
         default:
           break;
     }
   }
  }
  
  void atualizaDados(){
     distanciaFrente = sensorFrente.Ranging(CM);
     distanciaEsq = sensorEsq.Ranging(CM);
     distanciaDir = sensorDir.Ranging(CM);
  }

  void enviaDadosSerial(){
    Serial.print(tipoDado);
    Serial.print(separador);
    Serial.print("Frente: ");
    Serial.print(distanciaFrente);
    Serial.print(separador);
    Serial.print("Esquerda: ");
    Serial.print(distanciaEsq);
    Serial.print(separador);
    Serial.print("Direita: ");
    Serial.print(distanciaDir);
    Serial.print(separador);
    Serial.print("Movimentacao: ");
    Serial.print(movimentacao);
    Serial.println();
  }
  
  
