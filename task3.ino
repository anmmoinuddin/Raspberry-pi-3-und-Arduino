/*Solange die LED eingeschaltet ist soll sie zwischen 20% und 80% hin und her faden. (Stichwort PWM)  
 As long as the Led is on,it should be faded between 20% and 80%. */

const int buttonpin1=12;
const int ledpin = 9;//using pwm pin to have fading effects

 
int currentstate = 0; 
int previousstate = 0; 
int i = 0; 
int j = 0;

void setup() { 
pinMode (buttonpin1, INPUT); 
pinMode (ledpin, OUTPUT); 
Serial.begin(9600);
}

void loop() { 

 
currentstate = digitalRead(12); 

if (currentstate != previousstate) { 

if (currentstate==HIGH and i==0) { 

for( i=0; i<204; i++){
    analogWrite(ledpin, i);
    delay(22);
  }

  for( i=204; i>51; i--){
    analogWrite(ledpin, i);
    delay(18);
  } 
j=1; 
}
 

else if (currentstate==LOW and j==1) { 
i=1; 
}
 
else if (currentstate==HIGH and i==1) { 
digitalWrite (ledpin, LOW); 
j=0; 
} 



else if (currentstate==LOW and j==0) { 
i=0; 
} 

 



previousstate=currentstate; //updating the status of the state
 
  }
/*Serial.print("Button ");

Serial.println(digitalRead(buttonpin1));
if(analogRead(ledpin)){
  Serial.println("led leucht");
}
  
  else
  {
    Serial.println("led leucht nicht");
    }*/
  }
 
  
  
