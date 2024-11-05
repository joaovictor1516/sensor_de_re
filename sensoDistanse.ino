#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);


int echo = 4;
int trigger = 5;

int buzzer = 2;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(buzzer, OUTPUT);
}

void loop() {
  lcd.begin(16, 2);
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  float duracao = pulseIn(echo, HIGH);
  float distancia = duracao * 0.034 / 2;

  if(distancia <= 10.0 && distancia > 5.0){
    tone(buzzer, 1500);
    delay(250);
    noTone(buzzer);
    delay(250);
  } else if(distancia <= 5.0){
    tone(buzzer, 1500);
    delay(250);
    noTone(buzzer);
    delay(10);
  } else {
    noTone(buzzer);
  }

  lcd.print(distancia);
  lcd.print(" cm");
  delay(1000);
}
