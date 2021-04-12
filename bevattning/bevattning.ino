
const int dry = 320; 

const int pumpPin1 = 2;
const int pumpPin2 = 4;
const int pumpPin3 = 3; 
const int pumpPin4 = 2;

const int tempAndHumiditySensor = 7;

const int tempAndHumiditySensor2 = 13;

const int soilSensor1 = A0;
const int soilSensor2 = A1;
const int soilSensor3 = A2;
const int soilSensor4 = A3;


#include <DHT.h>
#define DHTPIN 7 //Kan ändras...
#define DHTPIN2 13
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);

int chk;
float hum; 
float temp; 

int chk2;
float hum2; 
float temp2; 



void setup() {

  Serial.begin(9600);
  dht.begin();
  dht2.begin();
  pinMode(pumpPin1, OUTPUT);
  pinMode(pumpPin2, OUTPUT);
  pinMode(pumpPin3, OUTPUT);
  //pinMode(pumpPin4, OUTPUT);

  pinMode(tempAndHumiditySensor, INPUT);
  pinMode(tempAndHumiditySensor2, INPUT);
  
  pinMode(soilSensor1, INPUT);
  pinMode(soilSensor2, INPUT);
  pinMode(soilSensor3, INPUT);
  //pinMode(soilSensor4, INPUT);
  
  
  
  digitalWrite(pumpPin1, HIGH);
  digitalWrite(pumpPin2, HIGH);
  digitalWrite(pumpPin3, HIGH);
  //digitalWrite(pumpPin4, HIGH);
  delay(5000);
}

void loop() {

 
  
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  
  Serial.print("Luftfuktighet: ");
    Serial.print(hum);
    Serial.print(" %, Temperatur: ");
    Serial.print(temp);
    Serial.println(" °C");  

  // hämta värden
  int moisture1 = analogRead(soilSensor1);
  int moisture2 = analogRead(soilSensor2);
  int moisture3 = analogRead(soilSensor3);
  //int moisture4 = analogRead(soilSensor4);

  
  
  Serial.println(moisture1);
  Serial.println(moisture2);
  Serial.println(moisture3);
  //Serial.println(moisture4);

  delay(5000);

  //////////////////////////////

  hum2 = dht2.readHumidity();
  temp2 = dht2.readTemperature();
  
  Serial.print("Luftfuktighet: ");
    Serial.print(hum2);
    Serial.print(" %, Temperatur: ");
    Serial.print(temp2);
    Serial.println(" °C");  
  

//  if(hum > 80.00)
//  {
//    Serial.println("Fuktigheten är för hög. Startar fläkt. Fuktigheten är: " + String(hum));
//    digitalWrite(fanPin, HIGH);
//    delay(30000);
//    digitalWrite(fanPin, LOW);    
//  }

/////////////////////////
  
  if (moisture1 >= dry) {
    
    Serial.println("Startar bevattning..fuktigheten är: " + String(moisture1));
    digitalWrite(pumpPin1, LOW);

    // kör pump i fem sekunder
    delay(2500);

    // avsluta bevattningen 
    digitalWrite(pumpPin1, HIGH);
    Serial.println("Bevattning klar.");
  } else {
    Serial.println("Jorden är fuktig. Bevattning krävs ej " + String(moisture1));
    delay(2500);
  }
  
/////////////////////////

  if (moisture2 >= dry) {
    // the soil is too dry, water!
    Serial.println("Startar bevattning..fuktigheten är: " + String(moisture2));
    digitalWrite(pumpPin2, LOW);

    // kör pump i fem sekunder
    delay(2500);

    // avsluta bevattningen 
    digitalWrite(pumpPin2, HIGH);
    Serial.println("Bevattning klar.");
  } else {
    Serial.println("Jorden är fuktig. Bevattning krävs ej " + String(moisture2));
  }
  
/////////////////////////

  if (moisture3 >= dry) {
    // the soil is too dry, water!
    Serial.println("Startar bevattning..fuktigheten är: " + String(moisture3));
    digitalWrite(pumpPin3, LOW);

    // kör pump i fem sekunder
    delay(2500);

    // avsluta bevattningen 
    digitalWrite(pumpPin3, HIGH);
    Serial.println("Bevattning klar.");
  } else {
    Serial.println("Jorden är fuktig. Bevattning krävs ej " + String(moisture3));
  }
  
/////////////////////////

//  if (moisture4 >= dry) {
//    // the soil is too dry, water!
//    Serial.println("Startar bevattning..fuktigheten är: " + String(moisture4));
//    digitalWrite(pumpPin4, LOW);
//
//    // kör pump i fem sekunder
//    delay(5000);
//
//    // avsluta bevattningen 
//    digitalWrite(pumpPin4, HIGH);
//    Serial.println("Bevattning klar.");
//  } else {
//    Serial.println("Jorden är fuktig. Bevattning krävs ej " + String(moisture4));
//  }

  
///////////////////////


   delay(33333333);//Vänta med att köra loopen..
}
