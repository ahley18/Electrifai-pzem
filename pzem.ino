#include <PZEM004Tv30.h>

/* Use hardware serial for the PZEM
 * Pin D1 (GPIO 5) - RX (Connects to the Tx pin on the PZEM)
 * Pin D2 (GPIO 4) - TX (Connects to the Rx pin on the PZEM)
*/

#define PZEM_RX_PIN 5  // D1 on ESP8266
#define PZEM_TX_PIN 4  // D2 on ESP8266

PZEM004Tv30 pzem(PZEM_TX_PIN, PZEM_RX_PIN);

void setup() {
    /* Debugging serial */
    Serial.begin(74880);
    delay(100);
}

void loop() {
    Serial.print("Custom Address: ");
    Serial.println(pzem.readAddress(), HEX);

    // Read the data from the sensor
    float voltage = pzem.voltage();
    float current = pzem.current();
    float power = pzem.power();
    float energy = pzem.energy();
    float frequency = pzem.frequency();
    float pf = pzem.pf();

    // Check if the data is valid
    if(isnan(voltage)){
        Serial.println("Error reading voltage");
    } else if (isnan(current)) {
        Serial.println("Error reading current");
    } else if (isnan(power)) {
        Serial.println("Error reading power");
    } else if (isnan(energy)) {
        Serial.println("Error reading energy");
    } else if (isnan(frequency)) {
        Serial.println("Error reading frequency");
    } else if (isnan(pf)) {
        Serial.println("Error reading power factor");
    } else {
        // Print the values to the Serial console
        Serial.print("Voltage: ");      Serial.print(voltage);      Serial.println("V");
        Serial.print("Current: ");      Serial.print(current);      Serial.println("A");
        Serial.print("Power: ");        Serial.print(power);        Serial.println("W");
        Serial.print("Energy: ");       Serial.print(energy, 3);    Serial.println("kWh");
        Serial.print("Frequency: ");    Serial.print(frequency, 1); Serial.println("Hz");
        Serial.print("PF: ");           Serial.println(pf);
    }

    Serial.println();
    delay(2000);
}
