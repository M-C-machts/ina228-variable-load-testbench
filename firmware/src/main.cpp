
#include <string>

#include <Arduino.h>
#include <Adafruit_INA228.h>
#include <Wire.h>

Adafruit_INA228 ina;
const uint8_t LED_PIN = 25;   // on‑board LED

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
	delay(500);

    Wire.setClock(400000);
	Wire.begin();

    if (!ina.begin(0x40)) {
        Serial.println("INA228 not found!");
        while (true) { 
			digitalWrite(LED_PIN, HIGH);
			Serial.println("INA228 not found!");
			delay(200); 
			digitalWrite(LED_PIN, LOW); 
			delay(200); }
    }

    ina.setShunt(0.015);   // 15 mΩ external shunt
}

void loop() {
    float busVoltage 	= ina.readBusVoltage();	// [V]
    // float shuntVoltage 	= ina.readShuntVoltage();
    float current 		= ina.readCurrent();	// [mA]
    float power   		= ina.readPower();
	float resistance	= busVoltage / current;

	

	char temp[64];
	sprintf(temp, "%.2f,%.3f,%.3f,%.3f", busVoltage, current, power, resistance);
	std::string buffer = temp;
	Serial.println(buffer.c_str());

    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(400);
}
