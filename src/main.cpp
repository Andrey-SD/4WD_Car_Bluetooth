#include <Arduino.h>

// Пины моторов
const int motorL_dir1 = 8; // Направление мотора A
const int motorL_dir2 = 9;
const int motorL_speed = 10; // Скорость мотора A (PWM)

const int motorR_dir1 = 12; // Направление мотора B
const int motorR_dir2 = 13;
const int motorR_speed = 11; // Скорость мотора B (PWM)

// Инициализация
void setup()
{
  Serial.begin(9600);

  // Настраиваем пины как выходы
  pinMode(motorL_dir1, OUTPUT);
  pinMode(motorL_dir2, OUTPUT);
  pinMode(motorL_speed, OUTPUT);

  pinMode(motorR_dir1, OUTPUT);
  pinMode(motorR_dir2, OUTPUT);
  pinMode(motorR_speed, OUTPUT);

}

void driveMotor(int speedL, int speedR)
{
  // Управление левым мотором
  if (speedL > 0)
  {
    digitalWrite(motorL_dir1, HIGH); // Вперёд
    digitalWrite(motorL_dir2, LOW);
    analogWrite(motorL_speed, constrain(speedL, 0, 255)); // Устанавливаем скорость
  }
  else if (speedL < 0)
  {
    digitalWrite(motorL_dir1, LOW);
    digitalWrite(motorL_dir2, HIGH);                           // Назад
    analogWrite(motorL_speed, constrain(abs(speedL), 0, 255)); // Устанавливаем скорость
  }
  else
  {
    // Полный стоп
    digitalWrite(motorL_dir1, LOW);
    digitalWrite(motorL_dir2, LOW);
    analogWrite(motorL_speed, 0);
  }

  // Управление правым мотором
  if (speedR > 0)
  {
    digitalWrite(motorR_dir1, HIGH); // Вперёд
    digitalWrite(motorR_dir2, LOW);
    analogWrite(motorR_speed, constrain(speedR, 0, 255)); // Устанавливаем скорость
  }
  else if (speedR < 0)
  {
    digitalWrite(motorR_dir1, LOW);
    digitalWrite(motorR_dir2, HIGH);                           // Назад
    analogWrite(motorR_speed, constrain(abs(speedR), 0, 255)); // Устанавливаем скорость
  }
  else
  {
    // Полный стоп
    digitalWrite(motorR_dir1, LOW);
    digitalWrite(motorR_dir2, LOW);
    analogWrite(motorR_speed, 0);
  }
}

// Основной цикл
void loop()
{

  // Движение вперёд
  driveMotor(255, 255); // Мотор A на скорости 200

  delay(2000);

  // Поворот направо
  driveMotor(255, -255); // Мотор A вперёд

  delay(1000);

  // Движение назад
  driveMotor(-255, -255); // Мотор A назад
  delay(2000);

  // Стоп
  driveMotor(-255, 255); // Остановить мотор A
  delay(1000);
}
