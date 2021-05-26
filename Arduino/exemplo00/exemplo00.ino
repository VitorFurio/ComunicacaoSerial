String tipoDado = "$STS";
int tempo = 0;
int distancia = 0;
int luminosidade = 0;

String separador = ",";

void setup() {
 Serial.begin(9600);
}

void loop() {
  delay(500);
  //set os dados
  
  enviaDadosSerial();
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
