#define POTENCIOMETRO A0
#define MOTOR 3
#define SPEED 7

const unsigned long sampleTime = 2000;
int out= 0;
int input = 0;
unsigned int rpm = 0;
float velocidadAngular, velocidadLineal;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR, OUTPUT);
  pinMode(POTENCIOMETRO, INPUT);
  pinMode(SPEED, INPUT);
}

void loop() {
  rpm = getRPM();
  input = analogRead(POTENCIOMETRO);
  calcularPwm();
  analogWrite(MOTOR, out);
  
    
    
    velocidadAngular = (rpm*6.283183)/60;
    velocidadLineal = velocidadAngular*0.00385;
  
    Serial.print("Velocidad Angular: ");
    Serial.print(velocidadAngular);
    Serial.println("rad/s");
    Serial.print("Velocidad Lineal ");
    Serial.print(velocidadLineal);
    Serial.println("m/s");
    Serial.print("speed: ");
}

void calcularPwm() {
  out = input / 4;
  if(out < 15 ) {
    out = 0;
  } else if(out > 255) {
    out = 255;
  }
}

int getRPM() {
  int kount = 0;
  boolean kflag = LOW;
  unsigned long currentTime = 0;
  unsigned long startTime = millis();
  
  while(currentTime<=sampleTime) {
    if(digitalRead(SPEED)==LOW) {
      kflag = HIGH;
    }
    if(digitalRead(SPEED)==HIGH && kflag==HIGH) {
      kount++;
      kflag = LOW;
    }
    currentTime = millis() - startTime;
  }
  unsigned int kountrpm = int(60000./float(sampleTime))*kount;
  return kountrpm;
}

