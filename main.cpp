#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4  // Pin 4 para el bus OneWire
#define CONTROL_PIN 2   // Pin para controlar el encendido/apagado

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);  // Inicia el monitor serie
  sensors.begin();       // Inicia la biblioteca DallasTemperature
  pinMode(CONTROL_PIN, OUTPUT); // Configura el pin de control como salida
  digitalWrite(CONTROL_PIN, LOW); // Asegura que el pin esté apagado inicialmente
}

void loop() {
  sensors.requestTemperatures(); // Solicita la temperatura al sensor
  float celsius = sensors.getTempCByIndex(0); // Obtiene la temperatura del primer sensor

  if (celsius == DEVICE_DISCONNECTED_C) {
    Serial.println("Error: Sensor desconectado");
    delay(1000);
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(celsius);
  Serial.println(" °C");

  // Control de temperatura
  if (celsius < 25.0) {
    digitalWrite(CONTROL_PIN, HIGH); // Enciende el pin de control
    Serial.println("Encendiendo...");
  } else {
    digitalWrite(CONTROL_PIN, LOW); // Apaga el pin de control
    Serial.println("Apagando...");
  }

  delay(5000); // Espera 1 segundo antes de la siguiente lectura
}
