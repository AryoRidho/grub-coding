/*
 * Robot pengikut garis (line follower)
 * Pin 8 dan 9 adalah input sensor garis
 * Pin 4 dan 5 untuk drive motor kiri
 * Pin 6 dan 7 untuk drive motor kanan
 * free to use
 * jangn lupa Subscribe ya bro
 * dukung channel saya 
 */

#define motorkif 4  //motor kiri maju
#define motorkib 5  //motor kiri mundur
#define motorkaf 6  //motor kanan maju
#define motorkab 7  //motor kanan mundur

void setup() {
//Menentukan mode untuk masing-masing pin
pinMode(motorkif,OUTPUT);
pinMode(motorkib,OUTPUT);
pinMode(motorkaf,OUTPUT);
pinMode(motorkab,OUTPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
}

void loop() {
 
int sensorki=digitalRead(7); //baca sensor kiri
int sensorka=digitalRead(8); //baca sensor kanan

if((sensorki==LOW) && (sensorka==LOW))
{
//kedua sensor tidak mengenai garis hitam
//gerak maju
digitalWrite(motorkaf,HIGH);
digitalWrite(motorkab,LOW);
digitalWrite(motorkif,HIGH);
digitalWrite(motorkib,LOW);
}

else if((sensorki==HIGH) && (sensorka==LOW))
{
//sensor kiri mendeteksi garis hitam
//belok kiri
digitalWrite(motorkaf,HIGH);
digitalWrite(motorkab,LOW);
digitalWrite(motorkif,LOW);
digitalWrite(motorkib,HIGH);
}

else if((sensorki==LOW) && (sensorka==HIGH))
{
//sensor kanan mendeteksi garis hitam
//belok kanan
digitalWrite(motorkaf,LOW);
digitalWrite(motorkab,HIGH);
digitalWrite(motorkif,HIGH);
digitalWrite(motorkib,LOW);
}

else
{
//kedua sensor mendeteksi garis
//stop
digitalWrite(motorkaf,LOW);
digitalWrite(motorkif,LOW);
digitalWrite(motorkab,LOW);
digitalWrite(motorkib,LOW);

}

}
