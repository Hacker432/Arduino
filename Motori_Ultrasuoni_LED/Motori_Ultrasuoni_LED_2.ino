#define TRIGGER1 22
#define TRIGGER2 24
#define TRIGGER3 26
#define TRIGGER4 28
#define ECHO1 23
#define ECHO2 25
#define ECHO3 27
#define ECHO4 29
int pinDirA=12;
int pinDirB=13;
int pinPwmA=3;
int pinPwmB=11;
int A;
int D;
int S;
int I;
int i;
const int INCREMENTO=2;

void setup() {

for(i=22; i<29; i+=INCREMENTO)
 pinMode( i,OUTPUT);
for(int j=23; j<30; j+=INCREMENTO) 
 pinMode( j,INPUT);
  Serial.begin( 9600 );
  
}

void loop(){
   /*unsigned long duration = pulseIn( ECHO, HIGH, 1500000 );
   unsigned long distance = duration/68.4;*/

  int ost = checkOstacoli();
  if (ost==S) {
    Serial.println( "TROVATO");
     digitalWrite( pinDirA, HIGH);
     digitalWrite( pinDirB, LOW);
     analogWrite( pinPwmA, 255);
     analogWrite( pinPwmB, 255);
     }
  if (ost==A) {
    Serial.println( "NON trovato");
    digitalWrite( pinDirA, HIGH);
     digitalWrite( pinDirB, HIGH);
     analogWrite( pinPwmA, 255);
     analogWrite( pinPwmB, 255);
     }
  if (ost==D) {
    Serial.println( "TROVATO");
    digitalWrite( pinDirA, LOW);
     digitalWrite( pinDirB, HIGH);
     analogWrite( pinPwmA, 255);
     analogWrite( pinPwmB, 255);
     } 
  if (ost==I) {
    Serial.println( "TROVATO");
     digitalWrite( pinDirA, LOW);
     digitalWrite( pinDirB, LOW);
     analogWrite( pinPwmA, 255);
     analogWrite( pinPwmB, 255);
     } 
     Serial.println("\n");
     delay(100);
}    
int checkOstacoli() {
  //porta bassa l'uscita del trigger
  for(i=22; i<29; i+=INCREMENTO)
 digitalWrite( i,LOW);
  //invia un impulso di 10microsec su trigger
  for(i=22; i<29; i+=INCREMENTO)
 digitalWrite( i,HIGH);
  delayMicroseconds( 10 );
  for(i=22; i<29; i+=INCREMENTO)
 digitalWrite( i,LOW);


   unsigned long duration1 = pulseIn(ECHO1, HIGH, 1500000 );
   unsigned long duration2 = pulseIn(ECHO2, HIGH, 1500000 );
   unsigned long duration3 = pulseIn(ECHO3, HIGH, 1500000 );
   unsigned long duration4 = pulseIn(ECHO4, HIGH, 1500000 );
   unsigned long distance1 = duration1/68.4;
   unsigned long distance2 = duration2/68.4;
   unsigned long distance3 = duration3/68.4;
   unsigned long distance4 = duration4/68.4;


  Serial.print( "DistanceS: " );
  Serial.println( distance1 );
  Serial.print( "DistanceA: " );
  Serial.println( distance2 );
  Serial.print( "DistanceD: " );
  Serial.println( distance3 );
  Serial.print( "DistanceI: " );
  Serial.println( distance4 );
  
  if (distance2==0) {
    
         pinMode(ECHO1, OUTPUT );
         pinMode(ECHO2, OUTPUT );
         pinMode(ECHO3, OUTPUT );
         pinMode(ECHO4, OUTPUT );
         digitalWrite(ECHO1, LOW);
         digitalWrite(ECHO2, LOW);
         digitalWrite(ECHO3, LOW);
         digitalWrite(ECHO4, LOW);
         delay(20);
         pinMode(ECHO1, INPUT );
         pinMode(ECHO2, INPUT );
         pinMode(ECHO3, INPUT );
         pinMode(ECHO4, INPUT );
         
  }
  if (distance2 < 20) {
    if (distance1 < 20) {
      if (distance3 < 20){
        if (distance4 <20){
              checkOstacoli=A;
           else
            checkOstacoli=I;} 
      else
        checkOstacoli=D;}
    else
      checkOstacoli=S;}
  else
    checkOstacoli=A;          
    }  
  //delay(800);
}
