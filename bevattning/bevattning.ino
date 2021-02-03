
const int dry = 270; 

const int pumpPin1 = 12;
const int pumpPin2 = ;
const int pumpPin3 = ; 
const int pumpPin4 = ;

const int tempAndHumiditySensor = ;

const int soilSensor1 = A4;
const int soilSensor2 = A4;
const int soilSensor3 = A4;
const int soilSensor4 = A4;


#include <DHT.h>;
#define DHTPIN 7 //Kan ändras...
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int chk;
float hum; 
float temp; 

void setup() {

  dht.begin();
  pinMode(pumpPin1, OUTPUT);
  pinMode(pumpPin2, OUTPUT);
  pinMode(pumpPin3, OUTPUT);
  pinMode(pumpPin4, OUTPUT);

  pinMode(tempAndHumiditySensor, INPUT);
  
  pinMode(soilSensor1, INPUT);
  pinMode(soilSensor2, INPUT);
  pinMode(soilSensor3, INPUT);
  pinMode(soilSensor4, INPUT);
  
  Serial.begin(9600);
  
  digitalWrite(pumpPin1, HIGH);
  digitalWrite(pumpPin2, HIGH);
  digitalWrite(pumpPin3, HIGH);
  digitalWrite(pumpPin4, HIGH);
  delay(5000);
}

void loop() {

  delay(180000);//Vänta med att köra loopen..

  hum = dht.readHumidity();
  temp = dht.readTemperature();
  
  Serial.print("Room humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temperature: ");
    Serial.print(temp);
    Serial.println(" Celsius");  

  // hämta värdet
  int moisture1 = analogRead(soilSensor1);
  int moisture2 = analogRead(soilSensor2);
  int moisture3 = analogRead(soilSensor3);
  int moisture4 = analogRead(soilSensor4);

  
  
  Serial.println(moisture1);
  Serial.println(moisture2);
  Serial.println(moisture3);
  Serial.println(moisture4);

  delay(5000);
  
  if (moisture1 >= dry) {
    
    Serial.println("Startar bevattning..fuktigheten är: " + String(moisture1));
    digitalWrite(pumpPin1, LOW);

    // kör pump i fem sekunder
    delay(5000);

    // avsluta bevattningen 
    digitalWrite(pumpPin1, HIGH);
    Serial.println("Done watering.");
  } else {
    Serial.println("Jorden är torr. Bevattning krävs ej " + String(moisture1));
  }
---------------------------------
  if (moisture2 >= dry) {
    // the soil is too dry, water!
    Serial.println("Startar bevattning..fuktigheten är: " + String(moisture2));
    digitalWrite(pumpPin2, LOW);

    // kör pump i fem sekunder
    delay(5000);

    // avsluta bevattningen 
    digitalWrite(pumpPin2, HIGH);
    Serial.println("Done watering.");
  } else {
    Serial.println("Jorden är torr. Bevattning krävs ej " + String(moisture2));
  }
----------------------------------
  if (moisture3 >= dry) {
    // the soil is too dry, water!
    Serial.println("Startar bevattning..fuktigheten är: " + String(moisture3));
    digitalWrite(pumpPin3, LOW);

    // kör pump i fem sekunder
    delay(5000);

    // avsluta bevattningen 
    digitalWrite(pumpPi3, HIGH);
    Serial.println("Done watering.");
  } else {
    Serial.println("Jorden är torr. Bevattning krävs ej " + String(moisture3));
  }
-----------------------------------
  if (moisture4 >= dry) {
    // the soil is too dry, water!
    Serial.println("Startar bevattning..fuktigheten är: " + String(moisture4));
    digitalWrite(pumpPin4, LOW);

    // kör pump i fem sekunder
    delay(5000);

    // avsluta bevattningen 
    digitalWrite(pumpPin4, HIGH);
    Serial.println("Done watering.");
  } else {
    Serial.println("Startar bevattning..fuktigheten är: " + String(moisture4));
  }
}
