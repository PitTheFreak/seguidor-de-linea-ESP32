//pines de sensores
const int S1 = 15;
const int S2 = 2;
const int S3 = 4;
const int S4 = 16;
const int S5 = 17;
const int S6 = 5;

//pines puente H
const int IN1 = 25;
const int IN2 = 26;
const int IN3 = 32;
const int IN4 = 33;

//canales PWM
const int CH_IN1 = 0;
const int CH_IN2 = 1;
const int CH_IN3 = 2;
const int CH_IN4 = 3;
const int PWM_FREQ = 1000;
const int PWM_RES = 8;

//velocidades
const int NORMAL = 200;
const int GIRO = 180;
const int CURVA = 150;
const int QUIETA = 0;

//linea perdida
const unsigned long TIEMPO_PERDIDO = 2000;
unsigned long tiempoUltimaLinea = 0;

//====================
//SETUP
//====================
void setup(){
  Serial.begin(115200);

  //sensores
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(S6, INPUT);

  //canales PWM para el DVR8833
  ledcSetup(CH_IN1, PWM_FREQ, PWM_RES);
  ledcSetup(CH_IN2, PWM_FREQ, PWM_RES);
  ledcSetup(CH_IN3, PWM_FREQ, PWM_RES);
  ledcSetup(CH_IN4, PWM_FREQ, PWM_RES);

  ledcAttacPin(IN1, CH_IN1);
  ledcAttacPin(IN2, CH_IN2);
  ledcAttacPin(IN3, CH_IN3);
  ledcAttacPin(IN4, CH_IN4);

  detener();
  Serial.println("iniando sistema gei");

}

//==========
//loop
//==========

void loop(){
  //leer sensores de vergazo
  bool s[7];
  s[1] = digitalRead(S1);
  s[2] = digitalRead(S2);
  s[3] = digitalRead(S3);
  s[4] = digitalRead(S4);
  s[5] = digitalRead(S5);
  s[6] = digitalRead(S6);

  //contar sensores por si se perdio el mampo
  int activos = s[1] + s[2] + s[3] + s[4] + s[5] + s[6];
  if (activos > 0) teimpoUltimaLinea = millis();

}