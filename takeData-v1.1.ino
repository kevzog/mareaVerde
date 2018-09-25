//switch
int pinSwitch = 2;
int valSwitch;

//tomar primer click
bool firstClick = false;

//printear el inicio
bool doPrint = true;

//generacion de un nuevo millis
unsigned long newMillis = 0;
int sampleTime = 1000;

//para tomar solo un valor de millis con el switch en high
bool takeit = true;

//cuando llega a mil, avisar
int pinLed = 13;
int already = 0;

void setup() {
  pinMode(pinSwitch, INPUT);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  digitalWrite(pinLed, LOW);
}

void loop() {
  readSwitch();
  takeClick();
  printStart();
  startTime();
  takeMillis();
  done();
}

void readSwitch() {
  valSwitch = digitalRead(pinSwitch);
}

void takeClick() {
  if (valSwitch == 1) {
    firstClick = true;
  }
}

void printStart() {
  if (firstClick && doPrint) {
    Serial.println("EMPIEZA");
    doPrint = false;
  }
}

void startTime() {
  if (firstClick) {
    newMillis++;
    delay(1);
  }
}

void takeMillis() {
  if (valSwitch && newMillis > sampleTime) {
    if (takeit) {
      Serial.print(newMillis);
      Serial.print(", ");
      takeit = false;
      already++;
    }
  } else {
    takeit = true;
  }
}

void done() {
  if (already == 1000) {
    digitalWrite(pinLed, HIGH);
  }
}
