#define RELAY_ALPHA 2
#define RELAY_BRAVO 3
#define RELAY_CHARLIE 4
#define RELAY_DELTA 5
#define RELAY_ECHO 6
#define RELAY_FOXTROT 7
#define RELAY_GOLF 8
#define RELAY_HOTEL 9

#define RELAY_ON 0
#define RELAY_OFF 1

#define DELAY 500

int RELAYS[] = {RELAY_ALPHA, RELAY_BRAVO, RELAY_CHARLIE, RELAY_DELTA, RELAY_ECHO, RELAY_FOXTROT, RELAY_GOLF, RELAY_HOTEL};

long patternCount = 0L;

void setup() {
  int i;
  for (i = 0; i < sizeof(RELAYS) - 1; i++){
    digitalWrite(RELAYS[i], RELAY_OFF);
  }

  for (i = 0; i < sizeof(RELAYS) - 1; i++){
    pinMode(RELAYS[i], OUTPUT);
  }
    
  Serial.begin(9600);
}

void loop() {

  int i;
  for (i = 0; i < sizeof(RELAYS) - 1; i++) {
    if (patternCount % RELAYS[i] == 0) {
      digitalWrite(RELAYS[i], RELAY_ON);  
      Serial.println(i + ' on');
    }
    else {
      digitalWrite(RELAYS[i], RELAY_OFF);    
      Serial.println(i + ' off');
    }
  }
  patternCount++;
  
  delay(DELAY);
}
