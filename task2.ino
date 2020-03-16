  
 //checking the current and previous state

int currentstate = 0; 
int previousstate = 0; 
int i = 0; 
int j = 0;

void setup() { 
pinMode (2, INPUT); 
pinMode (7, OUTPUT); 
}

void loop() { 
currentstate = digitalRead(2); 

if (currentstate != previousstate) { 
if (currentstate==HIGH and i==0) { 
digitalWrite (7, HIGH); 
j=1; 
} 

else if (currentstate==LOW and j==1) { 
i=1; 
} 
else if (currentstate==HIGH and i==1) { 
digitalWrite (7, LOW); 
j=0; 
} 
else if (currentstate==LOW and j==0) { 
i=0; 
} 
} 
previousstate=currentstate; //updating the status of the state
}
