#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>
#include <RF24.h>
#include <LiquidCrystal_I2C.h>
#include <SD.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

Adafruit_BMP280 bme;

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "12312";

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address y tamaño pantalla 16x2

File dataFile;
unsigned long counter = 0; // Counter Para incrementar "timestamp"
float gh = A0;
void setup() {
  pinMode(gh, INPUT);
  Serial.begin(9600);
  dht.begin();

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  // Initializar la LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();

  // Initializar la tarjeta SD
  if (!SD.begin(4)) {
    Serial.println("Inicializacion SD Fallada!");
    lcd.setCursor(0,0);
    lcd.print("N/A");
    while (1);
  }

  // Crear y abrir un nuevo file CSV
  String fileName = "data.csv";
  dataFile = SD.open(fileName, FILE_WRITE);
  if (dataFile) {
    dataFile.println("time,temperature,humidity,pressure");
    dataFile.close();
    //Serial.println("Sdcardcorrect");
  } else {
    Serial.println("Error creating data.csv file!");
    while (1);
  }
}

void loop() {
  delay(5000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float p = bme.readPressure() / 100.0F;
  // Incrementar timestamp por 5 segundos
  counter += 5;
  
  //Exponer la información en el monitor Serial
  //Serial.print(counter);
  //Serial.print(",");
  Serial.print(t);
  Serial.print(",");
  Serial.print(100 - h);
  Serial.print(",");
  Serial.print(gh);
  Serial.println();

  //Write la data a el doc CSV
  dataFile = SD.open("data.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.print(counter);
    dataFile.print(",");
    dataFile.print(t);
    dataFile.print(",");
    dataFile.print(100 - h);
    dataFile.print(",");
    dataFile.println(gh);
    dataFile.close();
  } else {
    Serial.println("Error opening data.csv file!");
  }

  // Transmitir data sobre nRF24L01
  String message = String(t) + "," + String(h) + "," + String(p);
  radio.write(&message, sizeof(message));

  // exponer data en la LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(100 - h);
  lcd.print("%");
}
