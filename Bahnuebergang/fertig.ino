 //declaration of PIN-        Erklaerung von PIN
const int ledpin1=9;
const int ledpin2=10;
const int tasterpin = 2;
unsigned int buttonstate=0;
int i=0;
int buttonread=0;
int state = 0; 
int ms = 5;
                                                                                              
                                                                                              
//declaration of Input/Output & Interrupt
void setup()
{
      // Set the switch pin as input
      pinMode(ledpin1, OUTPUT);
      pinMode(ledpin2, OUTPUT);
      //Interrupt
      attachInterrupt(digitalPinToInterrupt(tasterpin),buttonpress,RISING);  
}
//  There are actually 6 step functions. 
//Es gibt eigentlich 6 step Funktions.
//step functions  -   step Funktions


//When the pushbutton is pressed again, it goes back to state 11. 
//Wenn der Taster wieder gedrueckt wird, geht es wieder in den Zustand 11.

void step0() {
  if(buttonstate) {
    state = 11;
  }
}
                                                                                       
//This is state 1 where LED1 is dimming while LED2 is shinning gradually. It then goes to state 2.
//In dieser State LED1 dimmt hoch und LED2 dimmt unter. Danach es geht in den Zustand 2. 

void step1()
{ 
  for(i=0; i<=255;i=i+5)
  {
    analogWrite(ledpin1, 255-i); 
    analogWrite(ledpin2, i);  
    delay(ms);   
  }
  state = 2;
}

/*This is state 2 where LED1 is turned off while LED2 is turned on for half second, it then goes to state 3. 
If buttonstate is low it goes to state 21 which function name is stop_after2()
In dieser State LED1 ist ausgeschaltet  und LED2 ist eingeschaltet. Wenn buttonstate High ist, geht es in den Zustand 3. 
Im anderem fall, es geht in den Zustand 21 welcher Funktion Name stop_after2() ist. */
void step2()
{
  digitalWrite(ledpin1, LOW);
  digitalWrite(ledpin2, HIGH); 
  delay(500);
  if(buttonstate) {
    state = 3;       
  }else{
    state = 21;
  }
}

//This is state 1 where LED1 is shinning while LED2 is dimming gradually. It then goes to state 4.
//In dieser State LED1 dimmt unter und LED2 dimmt hoch. Danach geht es in den Zustand 4. 
void step3()
{   
  for(i=0; i<=255;i=i+5)
  {
    analogWrite(ledpin1, i);    
    analogWrite(ledpin2, 255-i);
    delay(ms);     
  }
  state = 4;
}
/*This is state 4 where LED1 is turned on while LED2 is turned off for half second, it then goes to state 1. 
If buttonstate is low it goes to state 22 which function name is stop_after4().
In dieser State LED1 ist fuer Halbe Sekunden eingeschaltet  und LED1 ist fuer Halbe Sekunden ausgeschaltet. 
Wenn buttonstate niedrig ist, geht es zu state 1. Im anderem fall, es geht zu state 22.  */

void step4() 
{
  digitalWrite(ledpin1, HIGH);
  digitalWrite(ledpin2, LOW); 
  delay(500);
    if(buttonstate) {
    state = 1;       
  }else{
    state = 22;
  }
}
//This is step 21 where LED2 is dimming gradually and at the end goes state 0.
void stop_after2() {
  for(i=0; i<=255;i=i+5)
  {
    analogWrite(ledpin2, 255-i);
    delay(ms);     
  }
  state = 0;
}
//This is step22 where LED1 is dimming gradually and at the end goes to state 0.
void stop_after4() {
  for(i=0; i<=255;i=i+5)
  {
    analogWrite(ledpin1, 255-i);
    delay(ms);     
  }
  state = 0;
}

//This is the starting stage of LED1 where LED1 is shinning gradually and then turned on for half second. After this step it goes to step 1. 
//Das ist die initiale Schritte von LED1 wo LED1 dimmt hoch und danach eingeschaltet fuer Halbe Sekunden. Nach dieser Step, es geht zu step1.
void start()
{
  for(i=0; i<=255;i=i+5)
  {
    analogWrite(ledpin1, i);
    delay(ms);
  }
  digitalWrite(ledpin1, 1);
  delay(500);
  state = 1;
}

//Main function       -Main Funktion
void loop()
{
  switch(state) {
    case 0:
      step0();
      break;
    case 11:
      start();
      break;
    case 1:
      step1();
      break;
    case 2:
      step2();
      break;   
    case 3:
      step3();
      break;   
    case 4:
      step4();
      break;   
    case 21:
      stop_after2();
      break;     
    case 22:
      stop_after4();
      break;                                                         
  }
}
//This is interrupt function.
//Das ist Interrupt Funktion.

long milli;
void buttonpress()
{
  
  buttonread=digitalRead(tasterpin);   
  if(buttonread==HIGH and milli < (millis()-1000))
  {
    buttonstate=!buttonstate; 
    milli = millis();
  }
}
