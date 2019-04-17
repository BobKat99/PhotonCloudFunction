//make variables to use them more easily in the later code
int led1 = D6;
int led2 = D5;
int led3 = D4;

void setup() {
    //make the led as output
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    //create the function led
    Particle.function("led",ledToggle);
    //set all the light off at first 
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
}

void loop() {
  //nothing here
}

//change the result based on the input which is a string
int ledToggle(String command) {
    
    //turn the first light-red light near photon on
    if (command=="one") {
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        return 1;
    }
    //turn the second light-white light on
    else if (command=="two") {
        digitalWrite(led2,HIGH);
        digitalWrite(led1,LOW);
        digitalWrite(led3,LOW);
        return 2;
    }
    //turn the third light-red light far photon on
    else if (command=="three") {
        digitalWrite(led3,HIGH);
        digitalWrite(led2,LOW);
        digitalWrite(led1,LOW);
        return 3;
    }
    //incase of any problem will return -1
    else {
        return -1;
    }
}