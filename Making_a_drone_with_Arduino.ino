#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

// Motor pinleri
int motor1 = 3; // Ön Sol
int motor2 = 5; // Ön Sağ
int motor3 = 6; // Arka Sol
int motor4 = 9; // Arka Sağ

void setup() {
  // Seri haberleşmeyi başlat
  mySerial.begin(9600);
  // Motorları kontrol için pinleri çıkış olarak ayarla
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
}

void loop() {
  // Bluetooth'tan veri geldiğinde
  if (mySerial.available()) {
    char command = mySerial.read(); // komutu oku

    // Komuta göre motorları kontrol et
    switch (command) {
      case 'U':
        // yukarı hareket, tüm motorları maksimum hıza ayarla
        analogWrite(motor1, 255);
        analogWrite(motor2, 255);
        analogWrite(motor3, 255);
        analogWrite(motor4, 255);
        break;
      case 'D':
        // aşağı hareket, tüm motorları minimum hıza ayarla
        analogWrite(motor1, 0);
        analogWrite(motor2, 0);
        analogWrite(motor3, 0);
        analogWrite(motor4, 0);
        break;
      case 'R':
        // sağa hareket, motorların bir kısmını yavaşlat
        analogWrite(motor1, 255);
        analogWrite(motor2, 200);
        analogWrite(motor3, 255);
        analogWrite(motor4, 200);
        break;
      case 'L':
        // sola hareket, motorların bir kısmını yavaşlat
        analogWrite(motor1, 200);
        analogWrite(motor2, 255);
        analogWrite(motor3, 200);
        analogWrite(motor4, 255);
        break;
      case 'F':
        // ileri hareket, arka motorları hızlandır
        analogWrite(motor1, 200);
        analogWrite(motor2, 200);
        analogWrite(motor3, 255);
        analogWrite(motor4, 255);
        break;
      case 'B':
        // geriye hareket, ön motorları hızlandır
        analogWrite(motor1, 255);
        analogWrite(motor2, 255);
        analogWrite(motor3, 200);
        analogWrite(motor4, 200);
        break;
      case 'Y':
        // yana kayma komutu
        // örneğin, motorları asimetrik hızlarda çalıştırabilirsiniz
        analogWrite(motor1, 255);
        analogWrite(motor2, 255);
        analogWrite(motor3, 200);
        analogWrite(motor4, 200);
        break;
      case 'E':
        // acil durumda iniş, tüm motorları yavaşça sıfırla
        for (int i = 255; i >= 0; i--) {
          analogWrite(motor1, i);
          analogWrite(motor2, i);
          analogWrite(motor3, i);
          analogWrite(motor4, i);
          delay(10); // yavaşça sıfırla
        }
        break;
      default:
        // Bilinmeyen komut
        break;
    }
  }
}
