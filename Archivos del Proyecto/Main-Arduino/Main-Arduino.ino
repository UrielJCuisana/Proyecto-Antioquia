#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>
#include <RF24.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

Adafruit_BMP280 bme;

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "12312";

LiquidCrystal_I2C lcd(0x27, 16, 2); // Cambiar el Address de I2c

void setup() {
  Serial.begin(9600);
  dht.begin();
  /*if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }*/

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  lcd.init();                      // Inicializar LCD
  lcd.backlight();                 // Apagar Backlight
  lcd.setCursor(0, 0);             // Poner cursor a primera columna, primera fila
  lcd.print("LCD is working!");    // Probar LCD
}

void loop() {
  delay(5000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float p = bme.readPressure() / 100.0F;
  
  lcd.clear();                     // Clear LCD
  lcd.setCursor(0, 0);             // Poner cursor a primera columna, primera fila
  lcd.print("Temperature: ");      // Exibir Label temperatura
  lcd.print(t);                    // Exibir valor temperatura
  lcd.setCursor(0, 1);             // poner cursor a primera columna, segunda fila
  lcd.print("Humidity: ");         // Exibir Label Humedad
  lcd.print(100-h);                // Exibir valor Humedad
  lcd.setCursor(8, 1);             // Poner cursor en la novena columna, segunda fila
  lcd.print("%");                  // Exibir simbolo porcentaje
  
  // Transmitir datos sobre NRF24L01
  String message = String(t) + "," + String(h) + "," + String(p);
  radio.write(&message, sizeof(message));
  Serial.print(t);
  Serial.print(",");
  Serial.print(100-h);
  Serial.print(",");
  Serial.println("1013"); // Sensor de presion fallo, hay que arreglar.
  Serial.println();
}
