   #include<Ultrasonic.h>
   
   #define led 13
   #define trig01 8
   #define echo01 7
   
   Ultrasonic sensor01(trig01,echo01);
   
   //Dados que seram transportados pela serial
  String tipoDado = "$STS";
  int tempo = 0;
  long distancia = 0;
  String luminosidade = "off";
  
  String separador = ",";

  void setup() {
    Serial.begin(9600);
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
        case 'a': // liga led
             digitalWrite(led,HIGH);
             luminosidade = "on";
           break;
  
         case 'b':// desliga led
             digitalWrite(led,LOW);
             luminosidade = "off";
           break;
           
         default:
           break;
     }
   }
  }
  
  void atualizaDados(){
   //  tempo = millis();
     distancia = sensor01.Ranging(CM);
  }

  void enviaDadosSerial(){
    Serial.print(tipoDado);
    Serial.print(separador);
    Serial.print(tempo);
    Serial.print(separador);
    Serial.print(distancia);
    Serial.print(separador);
    Serial.print(luminosidade);
    Serial.println();
  }
  
  
