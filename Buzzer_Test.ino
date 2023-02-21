#define Buzzer_Pin 4
int Buzz = 1;
int counter =0;
int sur = 500;
void setup() {
  // put your setup code here, to run once:
pinMode( Buzzer_Pin, OUTPUT);// Motor-1 Phase A
}

void loop() {
for(int i=1;i<=sur;i++){// Sa = 240(4166),270(3703),300(3333),320(3125),360(2777),400(2500),450(2222),480(2083)
  play(416/2);
}
delay(150);
for(int i=1;i<=1.2*sur;i++){//Re
  play(370/2);
}
delay(150);
for(int i=1;i<=1.25*sur;i++){//Ga
  play(333/2);
}
delay(150);
for(int i=1;i<=1.3*sur;i++){//Ma
  play(312/2);
}
delay(150);
for(int i=1;i<=1.5*sur;i++){//Pa
  play(277/2);
}
delay(150);
for(int i=1;i<=2*sur;i++){//Da
  play(250/2);
}
delay(150);
for(int i=1;i<=2.5*sur;i++){//Ni
  play(222/2);
}
delay(150);
for(int i=1;i<=3*sur;i++){//Sa
  play(200/2);
}
delay(150);

for(int i=1;i<=3*sur;i++){//Sa
  play(200/2);
}
delay(150);
for(int i=1;i<=2.5*sur;i++){//Ni
  play(222/2);
}
delay(150);
for(int i=1;i<=2*sur;i++){//Da
  play(250/2);
}
delay(150);
for(int i=1;i<=1.5*sur;i++){//Pa
  play(277/2);
}
delay(150);
for(int i=1;i<=1.3*sur;i++){//Ma
  play(312/2);
}
delay(150);
for(int i=1;i<=1.25*sur;i++){//Ga
  play(333/2);
}
delay(150);
for(int i=1;i<=1.2*sur;i++){//Re
  play(370/2);
}
delay(150);
for(int i=1;i<=sur;i++){// Sa = 240(4166),270(3703),300(3333),320(3125),360(2777),400(2500),450(2222),480(2083)
  play(416/2);
}
delay(150);
}
void play(int f){
digitalWrite(Buzzer_Pin,HIGH);
delayMicroseconds(f);
digitalWrite(Buzzer_Pin,LOW);
delayMicroseconds(f);
}
