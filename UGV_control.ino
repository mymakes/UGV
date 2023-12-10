
// Define PWM pins for each side of motor 

//UGV LEFT
int M1 = 9; // PWM pin 9, 
int M2 = 10; //PWM pin 10, 

int state = 0;

//UGV RIGHT
int M3 = 5; //PWM pin 5, 
int M4 = 6; //PWM pin 6, 

void setup() {

  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);

  // For left motor off:
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);

    // For right motor off
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);

}

void loop() {

   if(Serial.available() > 0) { // Checking if available data
    state = Serial.read(); // Reads the data from serial 

    if(state == 'F'){
    
    // For left motor forward:
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);

    // For right motor forward
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
    }

    if(state == 'B'){
    
    // For left motor reverse:
    digitalWrite(M1, LOW);
    digitalWrite(M2, HIGH);

    // For right motor reverse
    digitalWrite(M3, LOW);
    digitalWrite(M4, HIGH);
    }

    // For right hand turn, want left motor forward, right motor off
    if(state == 'R'){ 
    
    // For left motor forward:
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);

    // For right motor off
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
    }


    // For left hand turn, want right motor forward, left motor off
    if(state == 'L'){ 
    
    // For left motor off:
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);

    // For right motor forward
    digitalWrite(M3, HIGH);
    digitalWrite(M4, LOW);
    }

    // Full Stop
    if(state == 'S'){ 
    
    // For left motor off:
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);

    // For right motor off
    digitalWrite(M3, LOW);
    digitalWrite(M4, LOW);
    }
   }

  

}

   








