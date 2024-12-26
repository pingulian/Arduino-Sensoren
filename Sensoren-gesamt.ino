#include <Arduino_HS300x.h> //Temperatur + Luftfeuchtigkeit
#include <Arduino_LPS22HB.h> //Druck

//für Temp. + Leuftf.
float old_temp = 0;
float old_hum = 0;

void setup() {
  Serial.begin(9600);

  //Temperatur & Luftfeuchtigkeit
  while (!Serial);

  if (!HS300x.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }

  //Druck
  while (!Serial);

  if (!BARO.begin()) {
    Serial.println("Failed to initialize pressure sensor!");
    while (1);
  }
}

void loop() {

  //Temperatur & Luftfeuchtigkeit
  // read all the sensor values
  float temperature = HS300x.readTemperature();
  float humidity    = HS300x.readHumidity();
  if (abs(old_temp - temperature) >= 0.5 || abs(old_hum - humidity) >= 1 )
  {
  // print each of the sensor values
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity    = ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println();
  }



  //Druck
  // read the sensor value
  float pressure = BARO.readPressure();
  
  Serial.print("Pressure in kPa = ");
  Serial.println(pressure);

  Serial.println();

  // wait 1 second to print again
  delay(1000);
}
