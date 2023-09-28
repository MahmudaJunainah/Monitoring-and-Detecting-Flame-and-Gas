#include<Servo.h>


Servo motorservo;
int redLight = 6;
int greenLight = 7;
int buzzer = 13;
int gas = 9;
int flame = 10;




void setup() {
 pinMode(flame, INPUT);
 pinMode(gas, INPUT);
 pinMode(redLight, OUTPUT);
 pinMode(greenLight, OUTPUT);
 pinMode(buzzer, OUTPUT);


 Serial.begin(9600);
 motorservo.attach(8);
 motorservo.write(0);

}

void loop() {
  int flame_result = digitalRead(flame);
  int gas_result = digitalRead(gas);

  Serial.print("F V:");
  Serial.println(flame_result);
  Serial.print("G V:");
  Serial.print(gas_result);
  Serial.print(" ");

  if(gas_result==HIGH or flame_result==HIGH ){
    Serial.println("Fire Alarm On !!!!");
    digitalWrite(redLight,HIGH);
    digitalWrite(greenLight,LOW);
    tone(buzzer, 1000, 200);
    motorservo.write(180);





  }else{
    Serial.println("No Fire");
    digitalWrite(redLight,LOW);
    digitalWrite(greenLight,HIGH);
    noTone(buzzer);
    motorservo.write(0);



  }

  delay(500);


}
