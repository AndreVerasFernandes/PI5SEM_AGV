// Definição dos pinos de controle do motor
#define M1 9 // Pino_Velocidade 1º Motor ( 0 a 255)_ Porta ATV_A ponte H;
#define M2 11 //Pino_Velocidade 2º Motor ( 0 a 255) _ Porta ATV_B ponte H;
#define dir1 8 //Pino_Direção do 1º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN1 ponte H;
#define dir2 10 //Pino_Direção do 2º Motor: Para frente / Para trás (HIGH ou LOW)_ porta IN3 ponte H;

// Definição dos pinos dos sensores
#define pin_S1 7
#define pin_S2 6
#define pin_S3 5 // Sensor do meio para seguir a linha
bool Sensor1 = 0;
bool Sensor2 = 0;
bool Sensor3 = 0; // Variável para o sensor do meio


int velocidade = 100;

void setup(){
 
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

  // Setamos a direção inicial do motor como 0, isso fará com que ambos os motores girem para frente
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);

  
  pinMode(pin_S1, INPUT);
  pinMode(pin_S2, INPUT);
  pinMode(pin_S3, INPUT); // Sensor do meio


  Serial.begin(9600);
  delay(100);
}

void loop(){
  Sensor1 = digitalRead(pin_S1);
  Sensor2 = digitalRead(pin_S2);
  Sensor3 = digitalRead(pin_S3); // Leitura do sensor do meio

  if(Sensor3 == 1){ 
    analogWrite(M1, velocidade); 
    analogWrite(M2, velocidade);
  }
  if((Sensor1 == 1) && (Sensor3 == 0)){ 
    analogWrite(M1, 0); // O motor 1 desliga
    analogWrite(M2, velocidade); // O motor 2 fica ligado, fazendo assim o carrinho virar
  }
  if((Sensor2 == 1) && (Sensor3 == 0)){ 
    analogWrite(M1, velocidade); //O motor 1 fica ligado
    analogWrite(M2, 0); // O motor 2 desliga, fazendo assim o carrinho virar no outro sentido
  }
}
