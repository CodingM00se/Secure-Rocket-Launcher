
int buzzPin = 8;
int lightPinAlert = 4;
int pinSuccess = 2;
int unlockPin = 7;
int relayPin = 5;

int wait1 = 1;
int wait2 = 2;
int wait3 = 100;
int unlockTime = 7000;
int intro = 0;
int transition = 2000;
int teeMinus = 200;
int launchEnd = 500;

int j;
int i;
int c;

String password;
String launch;
String msg1 = "Welcome to the secure rocket launch platform! Check rocket connections and gain distance before proceeding.";
String msg2 = "Please enter the launch password: ";
String alert = "INCORRECT PASSWORD";
String correctPass = "PASSWORD AUTHENTICATED";
String instruction = "Please try again.";
String error = "Launch aborted.";
String liftoff = "Liftoff init. . .";
String success = "Launch completed!";
String confirmLaunch = "Enter Y to launch. Enter any other key to abort.";
String countdownInit = "Launch confirmed. Pull USB out to ABORT. KEEP AWAY FROM ROCKET.";
String countdownGo = "Countdown...";
String launchInit = "LAUNCH INITIATED";
String relayClosed = "GO LAUNCH";
String getMoney = "YEET";

String initPassword = "f345";

void setup() {
Serial.begin(9600);
pinMode(buzzPin,OUTPUT);
pinMode(lightPinAlert,OUTPUT);
pinMode(pinSuccess,OUTPUT);
pinMode(unlockPin,OUTPUT);
pinMode(relayPin,OUTPUT);
Serial.println(msg1);
Serial.println();
}

void loop() {
delay(intro);
Serial.println(msg2);
while(Serial.available() == 0) {}
password = Serial.readString();

//Password Fail
if(password != initPassword) {
  Serial.println(alert); 
  Serial.println(instruction);
  Serial.println();
 for(i = 1; i<=3; i = i + 1) {
  
  for(j = 1; j<=100; j = j + 1) {
  digitalWrite(buzzPin,HIGH);
  delay(wait1);
  digitalWrite(buzzPin,LOW);
  delay(wait1);
  }
  for(j = 1; j<=100; j = j + 1) {
    digitalWrite(buzzPin,HIGH);
    digitalWrite(lightPinAlert,HIGH);
    delay(wait2);
    digitalWrite(buzzPin,LOW);
    digitalWrite(lightPinAlert,LOW);
    delay(wait2);
   }
  }
}
//Password Success
else {
Serial.println(correctPass);
digitalWrite(lightPinAlert,LOW);
digitalWrite(buzzPin,LOW);

  for(j = 1; j <= 2; j = j + 1){
    digitalWrite(pinSuccess,HIGH);
    delay(wait3);
    digitalWrite(pinSuccess,LOW);
    delay(wait3);
  }
  
Serial.println();
Serial.println(confirmLaunch);
while(Serial.available() == 0) {}
launch = Serial.readString();

if(launch == "Y" || launch == "y") {

// Launch Initiated
Serial.println(countdownInit);
delay(transition);
Serial.println();
Serial.println(countdownGo);

for(i = 1; i<=5; i = i + 1) {
  
  for(j = 1; j<=100; j = j + 1) {
    digitalWrite(buzzPin,HIGH);
    delay(wait1);
    digitalWrite(buzzPin,LOW);
    delay(wait1);
  }
  for(j = 1; j<=100; j = j + 1) {
    digitalWrite(buzzPin,HIGH);
    digitalWrite(unlockPin,HIGH);
    delay(wait2);
    digitalWrite(buzzPin,LOW);
    digitalWrite(unlockPin,LOW);
    delay(wait2);
   }
  }

delay(transition);
//Countodwn  
  for(c = 10; c>=1; c = c - 1) {
    digitalWrite(pinSuccess,HIGH);
    Serial.println(c);
    delay(teeMinus);
    digitalWrite(pinSuccess,LOW);
    delay(teeMinus);
}

// Launch Trigger
  Serial.println(launchInit);
  digitalWrite(pinSuccess,HIGH);
  delay(transition);
  digitalWrite(pinSuccess,LOW);
  delay(teeMinus);

  Serial.println(relayClosed);
  digitalWrite(unlockPin,HIGH);
  delay(transition);
  Serial.println(getMoney);
  digitalWrite(relayPin,HIGH);
  delay(unlockTime);
  digitalWrite(unlockPin,LOW);
  digitalWrite(relayPin,LOW);
  delay(launchEnd);
  Serial.println(success);
      for(j = 1; j <= 1; j = j + 1){
      digitalWrite(pinSuccess,HIGH);
      delay(wait3);
      digitalWrite(pinSuccess,LOW);
      delay(wait3);
// Launch End
  }
  
}
//Launch abort
else{
Serial.println(error);   
  for(j = 1; j<=100; j = j + 1) {
    digitalWrite(buzzPin,HIGH);
    delay(wait1);
    digitalWrite(buzzPin,LOW);
    delay(wait1);
  }
  
  for(j = 1; j<=100; j = j + 1) {
    digitalWrite(buzzPin,HIGH);
    digitalWrite(lightPinAlert,HIGH);
    delay(wait2);
    digitalWrite(buzzPin,LOW);
    digitalWrite(lightPinAlert,LOW);
    delay(wait2);
   }

}
  }
Serial.println();
    }
