/**
 * VÍ DỤ 5-1b: VỆ TINH GỬI DỮ LIỆU TELEMETRY QUA THƯ VIỆN PTITCUBE
 */
#include <Arduino.h>
#include <PTITCube.h>

PTIT_CDH cdh;
PTIT_EPS eps;
PTIT_COM myLoRa;

void setup() {
    cdh.begin();

    // Kích hoạt hạ áp cấp nguồn ngoại vi trên PCB vệ tinh qua thư viện EPS
    eps.setBuckState(true);

    myLoRa.init();
}

void loop() {
    static int counter = 0;
    counter++;

    String payload = "PACKET #" + String(counter) + " - CUBESAT TELEMETRY";
    cdh.println("TX: " + payload);

    myLoRa.sendMessage(payload);
    delay(2000);
}
