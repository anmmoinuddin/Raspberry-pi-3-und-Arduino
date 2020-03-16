   //Solang die LED ausgeschaltet ist soll der Taster leuchten. Solange sie eingeschaltet ist, soll der Taster nicht leuchten. Während des Einschalt- und Ausschaltfadings soll der Taster blinken. 

const int buttonpin1=12;
const int ledpin = 9;//using pwm pin to have fading effects
const int taster1=10;

int currentstate = 0; 
int previousstate = 0; 
int i = 0; 
int j = 0;

void setup() { 
pinMode (buttonpin1, INPUT); 
pinMode (ledpin, OUTPUT); 
pinMode(taster1, OUTPUT);
}

void loop() { 

 
currentstate = digitalRead(12); 

if (currentstate != previousstate) { 

if (currentstate==HIGH and i==0) { 

for( i=0; i<255; i++){
    analogWrite(ledpin, i);
    analogWrite(taster1,i);
    delay(8);}

     
   
    
digitalWrite(taster1,LOW); // turn off Taster
 
j=1; 
}
 

else if (currentstate==LOW and j==1) { 
i=1; 
}
 
else if (currentstate==HIGH and i==1) { 
 

  for( i=255; i>0; i--){
    analogWrite(ledpin, i);
    analogWrite(taster1,i);
    delay(12);
  
    
   
  digitalWrite(taster1,HIGH);//turn on Taster
  } 
j=0; 
} 



else if (currentstate==LOW and j==0) { 
i=0; 


} 

 
  
  


previousstate=currentstate; //updating the status of the state
 
  }

  
}
