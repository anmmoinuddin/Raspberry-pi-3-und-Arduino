/*Beim Einschalten soll die LED über 2 Sekunden von 0% auf 100% faden und dann dort bleiben. Beim Ausschalten soll die LED über 3 Sekunden von 100% auf 0% faden.   
   
 */
const int buttonpin1=12;
const int ledpin = 9;//using pwm pin to have fading effects

int currentstate = 0; 
int previousstate = 0; 
int i = 0; 
int j = 0;

void setup() { 
pinMode (buttonpin1, INPUT); 
pinMode (ledpin, OUTPUT); 
}

void loop() { 

 
currentstate = digitalRead(12); 

if (currentstate != previousstate) { 

if (currentstate==HIGH and i==0) { 

for( i=0; i<255; i++){
    analogWrite(ledpin, i);
    delay(8);
  }

 
j=1; 
}
 

else if (currentstate==LOW and j==1) { 
i=1; 
}
 
else if (currentstate==HIGH and i==1) { 
 

  for( i=255; i>0; i--){
    analogWrite(ledpin, i);
    delay(12);
  } 
j=0; 
} 



else if (currentstate==LOW and j==0) { 
i=0; 
} 

 



previousstate=currentstate; //updating the status of the state
 
  }

  
}
