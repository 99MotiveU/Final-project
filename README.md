# 🔑 Smart Doorlock Project: Biometric Access Control System

[![Static Badge](https://img.shields.io/badge/Project%20Type-IoT%20%7C%20Mobile%20Intergration-blue)](https://github.com/99MotiveU/Final-project)
[![Static Badge](https://img.shields.io/badge/Hardware-Arduino-orange)](https://www.arduino.cc/)
[![Static Badge](https://img.shields.io/badge/Mobile-Android%20%26%20Kotlin-green)](https://developer.android.com/)

**스마트 도어락 프로젝트**는 아두이노와 안드로이드 스마트폰을 블루투스로 연동하여 구현한 **생체 인식 기반 도어락 시스템**입니다. 스마트폰의 **지문 인증** 기능을 활용하여 사용자 접근 권한을 검증하고, 검증된 사용자만이 무선으로 솔레노이드 밸브를 제어하여 문을 잠금 해제할 수 있습니다.

---

## 💡 프로젝트 개요

### 시스템 목표

* **보안 강화:** 단순 비밀번호 방식이 아닌, 스마트폰의 **지문 인식 센서**를 활용하여 보안 수준을 높입니다.
* **무선 제어:** **블루투스 통신**을 이용하여 물리적 접촉 없이 편리하게 도어락을 제어합니다.
* **하드웨어 제어 학습:** 안드로이드 앱에서 아두이노로 명령을 전송하고, 아두이노가 릴레이와 솔레노이드 밸브와 같은 **외부 장치를 제어하는 과정**을 학습하고 구현합니다.

### 핵심 기능

| 기능 | 상세 설명 |
| :--- | :--- |
| **지문 기반 사용자 인증** | 안드로이드 앱 실행 시, **등록된 지문**을 통해서만 도어락 제어 화면에 접근 가능합니다. |
| **블루투스 무선 통신** | 스마트폰과 아두이노는 **HC-06 모듈**을 사용하여 안전하게 명령(예: "unlock")을 주고받습니다. |
| **도어락 잠금 제어** | 앱에서 인증 성공 후 전송된 명령을 아두이노가 수신하여 **솔레노이드 밸브**를 작동(문 열림/잠김)시킵니다. |
| **명령 기반 작동** | 아두이노는 블루투스 시리얼 통신으로 수신한 "unlock" 또는 "lock"과 같은 **특정 문자열 명령**에 반응합니다. |

---

## 🛠️ 기술 스택 (Tech Stack)

이 프로젝트는 하드웨어 제어와 모바일 애플리케이션 개발을 결합한 스택을 사용합니다.

| 구분 | 사용 기술 | 상세 내용 |
| :--- | :--- | :--- |
| **Mobile App** | ![Kotlin](https://img.shields.io/badge/Kotlin-7F52FF?style=for-the-badge&logo=kotlin&logoColor=white) ![Android Studio](https://img.shields.io/badge/Android%20Studio-3DDC84?style=for-the-badge&logo=android-studio&logoColor=white) | 지문 인증 로직 구현, 블루투스 클라이언트 역할 |
| **Hardware** | ![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white) ![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white) | HC-06 데이터 수신 및 솔레노이드 구동 제어 |
| **Communication** | ![Bluetooth](https://img.shields.io/badge/Bluetooth-0080FF?style=for-the-badge&logo=bluetooth&logoColor=white) (HC-06) | 스마트폰과 아두이노 간의 무선 명령 전송 |
| **Actuator** | Solenoid Valve, Relay Module | 물리적인 잠금/해제 동작 수행 |

---

## ⚙️ 시스템 구성 및 하드웨어 설정

### 하드웨어 목록

* **Arduino (Uno/Nano)**
* **솔레노이드 밸브 (12V)**
* **블루투스 모듈 (HC-06)**
* **릴레이 모듈**
* **외부 전원 공급 장치** (솔레노이드 구동용)

### 배선 요약

| 연결 지점 (Arduino) | 연결 지점 (Module/Device) | 역할 |
| :--- | :--- | :--- |
| **Digital Pin 9** | 릴레이 제어 핀 | 솔레노이드 밸브의 전원 ON/OFF 신호 |
| **Digital Pin 10 (RX)** | HC-06 **TX** | 아두이노가 스마트폰의 명령 수신 |
| **Digital Pin 11 (TX)** | HC-06 **RX** | (옵션) 아두이노가 스마트폰으로 상태 전송 |



---

## 📂 파일 구조 및 핵심 코드

이 프로젝트는 아두이노 제어 코드와 안드로이드 앱 코드로 나뉩니다.

Final-project/ ├── final project/ │ ├── smart_doorlock.ino # 🔌 아두이노 메인 스케치 (블루투스 명령 수신 로직) │ └── AndroidStudioProjects/ │ └── bluetoothsolenoid/ # 📱 안드로이드 앱 프로젝트 (Kotlin) │ └── app/src/main/java/.../bluetoothsolenoid/ │ └── MainActivity.kt # 지문 인증 및 블루투스 "unlock" 명령 전송 └── btdoorlock1104/ └── btdoorlock1104.ino # 🔌 아두이노 스케치

---

## 🚀 시작 가이드

### 1. 하드웨어 준비 및 업로드

1.  위에 명시된 대로 하드웨어 배선을 완료합니다.
2.  아두이노 IDE를 열고 **`smart_doorlock.ino`** 스케치를 아두이노 보드에 업로드합니다.
3.  솔레노이드 밸브가 정상적으로 릴레이를 통해 전원을 공급받을 수 있는지 확인합니다.

### 2. 안드로이드 앱 설정 및 실행

1.  Android Studio에서 `bluetoothsolenoid` 프로젝트를 엽니다.
2.  **스마트폰 설정:** 사용하려는 스마트폰의 **블루투스 설정**에서 HC-06 모듈과 **미리 페어링**을 완료합니다.
3.  앱을 빌드하여 스마트폰에 설치합니다.
4.  앱을 실행하고 지문 인증을 수행합니다. 인증 성공 시, 블루투스를 통해 아두이노로 **`unlock`** 명령이 전송되어 도어락이 해제됩니다.

---

## 🔮 추후 개선할 점 (Future Improvements)

### 1. 보안 및 안정성 강화
* **블루투스 연결 암호화:** 현재 HC-06 모듈은 기본적인 페어링만 사용하고 있으나, **AES 등의 암호화**를 적용하여 통신 패킷의 보안을 강화해야 합니다.
* **인증된 MAC 주소 사용:** 앱에서 특정 **HC-06의 MAC 주소**만 연결하도록 로직을 구현하여, 다른 블루투스 장치에 의한 **오작동 및 해킹 시도**를 차단합니다.

### 2. 기능 확장
* **원격 제어 (Wi-Fi/Internet):** 블루투스 대신 **ESP32 또는 ESP8266 모듈**을 사용하여 Wi-Fi 통신으로 전환하고, **외부에서도 도어락을 제어**할 수 있는 기능을 추가합니다.
* **상태 피드백:** 문이 열렸는지/닫혔는지, 잠금 상태인지 등의 **상태 정보를 아두이노에서 앱으로 전송**하여 사용자에게 시각적으로 표시합니다.
* **로그 기록:** 문이 열린 시간, 사용자 등의 **접근 기록을 저장**하고 앱에서 조회할 수 있도록 데이터베이스 연동을 고려합니다.

---

## 💭 프로젝트를 통해 느낀 점 (Lessons Learned)

* **하드웨어-소프트웨어 통합의 어려움:** 모바일 앱에서 완벽하게 작동하는 코드가 하드웨어(아두이노, 릴레이, 솔레노이드)의 **전기적/물리적 특성** 때문에 예상치 못한 오류를 일으킬 수 있음을 경험했습니다. 특히 솔레노이드 밸브를 구동하기 위한 **외부 전원 및 릴레이의 중요성**을 깨닫고, 시스템 안정화에 집중했습니다.
* **블루투스 시리얼 통신의 이해:** 안드로이드의 블루투스 API를 사용하여 **직렬 통신(SPP)**을 구현하는 과정에서, 데이터 패킷의 형식과 전송/수신 버퍼 처리에 대한 깊이 있는 이해가 필요함을 체감했습니다. 문자열 명령(e.g., "unlock")을 파싱(Parsing)하여 아두이노에서 정확히 처리하는 로직을 구현하는 것이 핵심이었습니다.
* **지문 인증의 활용:** 모바일 디바이스의 **생체 인식 API**를 단순 앱 로그인뿐만 아니라 **IoT 장치를 제어하는 보안 수단**으로 활용하는 실질적인 경험을 쌓았습니다.

---
