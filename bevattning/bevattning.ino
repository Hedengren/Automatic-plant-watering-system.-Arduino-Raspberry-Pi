
// Fixed value for when the soil is "dry".  
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


//#include <LiquidCrystal.h> // To be implemented.. LCD-display.
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

/* To be implemented.. LCD. Pins will need to be altered. 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
*/ 

void setup() {

  Serial.begin(9600);
  
  // lcd.begin(16, 2); // Setup for the LCD-display 
  
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
  
  displayTempHumStart(); // Sends temperature and humidity values to display.
  
 
  // Fetch moisture values.
  int moisture1 = analogRead(soilSensor1);
  int moisture2 = analogRead(soilSensor2);
  int moisture3 = analogRead(soilSensor3);
  //int moisture4 = analogRead(soilSensor4);

  
  
  Serial.println(moisture1);
  Serial.println(moisture2);
  Serial.println(moisture3);
  //Serial.println(moisture4);

  delay(5000);


/*  
  // Second humidity and temperature sensor, not in use.
  hum2 = dht2.readHumidity();
  temp2 = dht2.readTemperature();
  
  Serial.print("Luftfuktighet: ");
    Serial.print(hum2);
    Serial.print(" %, Temperatur: ");
    Serial.print(temp2);
    Serial.println(" °C");  
 */
  

//  if(hum > 80.00)
//  {
//    Serial.println("Fuktigheten är för hög. Startar fläkt. Fuktigheten är: " + String(hum));
//    digitalWrite(fanPin, HIGH);
//    delay(30000);
//    digitalWrite(fanPin, LOW);    
//  }

  checkMoistureIfWaterNeeded(moisture1, pumpPin1);
  
  checkMoistureIfWaterNeeded(moisture2, pumpPin2);
  
  checkMoistureIfWaterNeeded(moisture3, pumpPin3);
  
  // checkMoistureIfWaterNeeded(moisture4, pumpPin4); 
  
  displayTempHumEnd(); 
  
}



void checkMoistureIfWaterNeeded(int moistIncoming, int pumpPinIncoming)
{
  if(moistIncoming >= dry)
  {
    lcd.print("Watering.. " + String(moistIncoming));
    digitalWrite(pumpPinIncoming, LOW);
    delay(2500);   
    digitalWrite(pumpPinIncoming, HIGH); 
    lcd.clear();
  }
  else
  {
    lcd.print("Water not needed " + String(moistIncoming));
    delay(2500);
    lcd.clear()
  }
   
}

void displayTempHumStart()
{
    hum = dht.readHumidity();
    temp = dht.readTemperature();
    lcd.setCursor(0,0);
    lcd.print("AirHum: "+hum);
    lcd.setCursor(0,1);
    lcd.print("Temp: "+temp);
    delay(6000);
    lcd.clear();
}

void displayTempHumEnd()
{
  unsigned long currentTime = millis();
  constant unsigned long timeSpan = 25000;
  
  while(currentTime < currentTime+timeSpan)
  {
    Serial.println(currentTime);
    hum = dht.readHumidity();
    temp = dht.readTemperature();
    lcd.setCursor(0,0);
    lcd.print("AirHum: "+hum);
    lcd.setCursor(0,1);
    lcd.print("Temp: "+temp);
    delay(5000);
  }
    
}

}




  
