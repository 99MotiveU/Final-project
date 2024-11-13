#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX 핀 설정
int solenoidPin = 9;

void setup() {
    Serial.begin(9600);  // 기본 시리얼 통신 초기화
    bluetooth.begin(9600);  // HC-06 블루투스 모듈 통신 시작
    pinMode(solenoidPin, OUTPUT);  // 솔레노이드 핀 출력 설정

    // Bluetooth 연결 확인
    Serial.println("Bluetooth Test Start");
}

void unlockDoor() {
    digitalWrite(solenoidPin, HIGH);  // 문을 열기
    delay(1000);
    digitalWrite(solenoidPin, LOW);   // 문을 잠그기
    Serial.println("Door Unlocked");
}

void lockDoor() {
    digitalWrite(solenoidPin, LOW);   // 문을 잠그기
    Serial.println("Door Locked");
}

void loop() {
    if (bluetooth.available()) {  // Bluetooth로 데이터 수신
        String message = bluetooth.readString();  // 수신한 메시지

        if (message == "CONNECTED") {
            Serial.println("Bluetooth connected");
        } else if (message == "U") {  // Unlock 명령 수신
            unlockDoor();
        } else if (message == "L") {  // Lock 명령 수신
            lockDoor();
        }
    }
}
