void setup() {
  for (int i = 2; i <= 4; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  for (int i = 8; i <= 10; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {

  while (digitalRead(3)); // ждем нажатия на кнопку
  //выключаем все светодиоды
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);

  delay(random(1000, 4000)); // ждем случайное время от 1000 до 4000 мс
  digitalWrite(9, HIGH); // зажигаем стартовый светодиод
  // защита от читеров: если игрок держал кнопку нажатой до зажигания светодиода
  // то победа достается его сопернику
  if (!digitalRead(2)) {
    digitalWrite(10, HIGH);
    return;
  }
  if (!digitalRead(4)) {
    digitalWrite(8, HIGH);
    return;
  }

  while (digitalRead(2) && digitalRead(4)); // ждем, пока кто-нибудь нажмет на кнопку
  // выявляем победителя, зажигаем соответствующий светодиод
  if (!digitalRead(2) && digitalRead(4)) {
    digitalWrite(8, HIGH);
  }
  if (digitalRead(2) && !digitalRead(4)) {
    digitalWrite(10, HIGH);
  }
  // если нажали одновременно, то зажигаются светодиоды обоих игроков
  if (!digitalRead(2) && !digitalRead(4)) {
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
  }
}
