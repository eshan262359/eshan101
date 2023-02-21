//Gyrodrive Machineries Private Limited
//Gyro/DC/V1 Programmable Dual DC Motor Driver
//Code for testing DC Motor Speed Control
//Written by Eshan Dhar
//Date: 11/11/22
// Define Motor PWM Pins for Speed and Direction
#define M1_PWM1 5
#define M1_PWM2 6
#define M2_PWM1 10
#define M2_PWM2 11
// Motor PWM Pins Initialized
#include <PWM.h>
int32_t frequency = 1000; //frequency (in Hz)
// Define Motor Intrupt Pins for Speed and Direction
#define M1_INTP 2
#define M2_INTP 3
// Motor Intrupt Pins Initialized
#define Battery A0
#define Buzzer 4
#define POD_M1 A7
#define POD_M2 A6
#define Current A1
unsigned long previous_time=0;
unsigned int Speed = 0;
volatile int count = 0;//if the interrupt will change this value, it must be volatile
int Speed_Setpoint = 500;
int counter1=0;
int counter=0;
void setup() {
pinMode(M1_INTP, INPUT); //set as input
digitalWrite(M1_INTP, HIGH);//enable internal pullup resistor
Serial.begin(9600);
previous_time=0;
//InitTimers(); 
//bool success = SetPinFrequency(M2_PWM1, frequency);
}
void loop() {
Speed_Setpoint = analogRead(POD_M1);
analogWrite(M2_PWM1,map(Speed_Setpoint,0,1023,0,255));
analogWrite(M2_PWM2,0);
delay(1000);
detachInterrupt(digitalPinToInterrupt(2));//Interrupt initialization
Speed = (count*60000/80)/(millis()-previous_time);
previous_time=millis();
count=0;
//Serial.println(Speed);//see the counts advance
Serial.print("page0.z0.val="+String(Speed));
Serial.write(0xff);
Serial.write(0xff);
Serial.write(0xff);
//Serial.println(Speed);//see the counts advance
Serial.print("page0.z1.val="+String(Speed_Setpoint));
Serial.write(0xff);
Serial.write(0xff);
Serial.write(0xff);
attachInterrupt(digitalPinToInterrupt(2), interruptName, RISING);//Interrupt initialization
}
void interruptName()
{
 ++count;
}//end Interrupt Service Routine (ISR)
