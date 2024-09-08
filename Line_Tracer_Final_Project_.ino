// 센서 핀 설정
const int sensorLeft = 8;  // 왼쪽 센서 핀

const int sensorRight = 10;  // 오른쪽 센서 핀

// 모터 핀 설정
const int EA = 3;  // 모터 A 속도 제어 (EA)
const int M_IN1 = 4;  // 모터 A 방향 제어 1 (M_IN1)
const int M_IN2 = 5;  // 모터 A 방향 제어 2 (M_IN2)
const int M_IN3 = 13; // 모터 B 방향 제어 1 (M_IN3)
const int M_IN4 = 12; // 모터 B 방향 제어 2 (M_IN4)
const int EB = 11; // 모터 B 속도 제어 (EB)

// 모터 속도 설정
int motorSpeed = 100;
int motorA_vector = 1;
int motorB_vector = 1;


void setup() {
  // 센서 핀 입력 모드로 설정
  pinMode(sensorLeft, INPUT);
  pinMode(sensorRight, INPUT);

  // 모터 핀 출력 모드로 설정
  pinMode(EA, OUTPUT);
  pinMode(M_IN1, OUTPUT);
  pinMode(M_IN2, OUTPUT);
  pinMode(M_IN3, OUTPUT);
  pinMode(M_IN4, OUTPUT);
  pinMode(EB, OUTPUT);

  // 모터 속도 초기화
  analogWrite(EA, motorSpeed);
  analogWrite(EB, motorSpeed);
}

void loop() {
  // 센서 값 읽기 (LOW: 검은색, HIGH: 하얀색)
 int leftValue = digitalRead(sensorLeft);
  int rightValue = digitalRead(sensorRight);

  // 상황에 따른 모터 제어

   if (rightValue == LOW) {
    // 오른쪽 센서가 검은색을 감지 (오른쪽 회전)
  digitalWrite(EA, HIGH); //모터구동ON, DC모터 정회전
  digitalWrite(M_IN1, motorA_vector); //  M_IN1에 HIGH(or LOW)
  digitalWrite(M_IN2, !motorA_vector); //  M_IN2에는 M_IN1과 반대되는 값 기입
  digitalWrite(EB, HIGH);
  digitalWrite(M_IN3, !motorB_vector);
  digitalWrite(M_IN4, motorB_vector);
    delay(100); 
  } else if (leftValue == LOW) {
    // 왼쪽 센서가 검은색을 감지 (왼쪽 회전)
  digitalWrite(EA, HIGH); //모터구동ON, DC모터 정회전
  digitalWrite(M_IN1, !motorA_vector); //  M_IN1에 HIGH(or LOW)
  digitalWrite(M_IN2, motorA_vector); //  M_IN2에는 M_IN1과 반대되는 값 기입
  digitalWrite(EB, HIGH);
  digitalWrite(M_IN3, motorB_vector);
  digitalWrite(M_IN4, !motorB_vector);
    delay(100);
    
  } else  {
    // 무조건 전진
  digitalWrite(EA, HIGH); //모터구동ON, DC모터 정회전
  digitalWrite(M_IN1, !motorA_vector); //  M_IN1에 HIGH(or LOW)
  digitalWrite(M_IN2, motorA_vector); //  M_IN2에는 M_IN1과 반대되는 값 기입
  digitalWrite(EB, HIGH);
  digitalWrite(M_IN3, !motorB_vector);
  digitalWrite(M_IN4, motorB_vector);
  }

}
