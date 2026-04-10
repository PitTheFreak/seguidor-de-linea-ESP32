//PINES DE LOS SENSORES
const int s1 =15;
const int s2 =2;
const int s3 =4;
const int s4 =16;
const int s5 =17;
const int s6 =5;

//PINES DEL PUENTE H
const int IN1 = 25;
const int IN2 = 26;
const int IN3 = 32;
const int IN4 = 33;

//VARIABLE DE VELOCIDAD
int velocidadNormal = 230;


void setup() {

// SENSORES
pinMode (s1 , INPUT);
pinMode (s2 , INPUT);
pinMode (s3 , INPUT);
pinMode (s4 , INPUT);
pinMode (s5 , INPUT);
pinMode (s6 , INPUT);

//MOTORES
pinMode (IN1 , OUTPUT);
pinMode (IN2 , OUTPUT);
pinMode (IN3 , OUTPUT);
pinMode (IN4 , OUTPUT);

Serial.begin (9600);

}

void loop() {
int lectura1 = digitalRead (s1);
int lectura2 = digitalRead (s2);
int lectura3 = digitalRead (s3);
int lectura4 = digitalRead (s4);
int lectura5 = digitalRead (s5);
int lectura6 = digitalRead (s6);


if (lectura1 == LOW && lectura2 == LOW && lectura3 == HIGH && lectura4 == HIGH && lectura5 == LOW && lectura6 == LOW){
  Serial.println("LINEA DETECTADA: AVANZANDO");
  Avanzar();  
}

else if (lectura1 == HIGH && lectura2 == HIGH && lectura3 == LOW && lectura4 == LOW && lectura5 == LOW && lectura6 == LOW){
  Serial.println("LINEA A LA IZQUIERDA: CURVEADA A LA IZQUIERDA");
  Girarizquirda ();
}

else if (lectura1 == LOW && lectura2 == LOW && lectura3 == LOW && lectura4 == LOW && lectura5 == HIGH && lectura6 == HIGH){
  Serial.println("LINEA A LA DERECHA: CURVEADA A LA DEREECHA");
  Girarderecha ();
}

else if (lectura1 == HIGH && lectura2 == LOW && lectura3 == LOW && lectura4 == LOW && lectura5 == LOW && lectura6 == LOW){
  Serial.print
}




}