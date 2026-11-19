/**
 * VÍ DỤ 5-1b: VỆ TINH GỬI DỮ LIỆU TELEMETRY QUA THƯ VIỆN PTITCUBE
 */
#include <Arduino.h>
#include <PTITCube.h>

PTIT_CDH cdh;
PTIT_COM myLoRa;

void setup() {
    cdh.begin(115200);
    myLoRa.init();
    cdh.println("[COM] LoRa TX ready.");
}

void loop() {
    static int counter = 0;
    counter++;

    String payload = "PACKET #" + String(counter) + " - CUBESAT TELEMETRY";
    cdh.println("[TX] " + payload);

    myLoRa.sendMessage(payload);
    delay(2000);
}
