#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // HC-06의 RX, TX 핀 설정
int solenoidPin = 9; // 솔레노이드가 연결된 핀
bool isLocked = true; // 잠금 상태를 저장하는 변수

void setup() {
  BTSerial.begin(9600); // HC-06 통신 속도 설정
  pinMode(solenoidPin, OUTPUT);
  digitalWrite(solenoidPin, LOW); // 처음에는 잠금 상태 유지
}

void loop() {
  if (BTSerial.available()) {
    String command = BTSerial.readString(); // 블루투스 데이터 읽기
    if (command == "unlock" && isLocked) {
      digitalWrite(solenoidPin, HIGH); // 솔레노이드 잠금 해제
      isLocked = false; // 잠금 해제 상태로 변경
    }
    else if (command == "lock" && !isLocked) {
      digitalWrite(solenoidPin, LOW); // 솔레노이드 잠금
      isLocked = true; // 잠금 상태로 변경
    }
  }
}
