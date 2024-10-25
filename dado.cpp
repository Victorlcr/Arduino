int esq_inf = 3;
int esq_centro = 4;
int esq_sup = 6;
int centro = 7;
int dir_inf = 11;
int dir_centro = 9;
int dir_sup = 8;
int aleat;
int botao = 2;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode (esq_inf, OUTPUT);
  pinMode (esq_centro, OUTPUT);
  pinMode (esq_sup, OUTPUT);
  pinMode (centro, OUTPUT);
  pinMode (dir_centro, OUTPUT);
  pinMode (dir_sup, OUTPUT);
  pinMode (dir_inf, OUTPUT);
  pinMode (botao, INPUT_PULLUP);
  randomSeed(analogRead(0));
}

void loop()
{
    digitalWrite(esq_inf, LOW);
    digitalWrite(esq_centro, LOW);
    digitalWrite(esq_sup, LOW);
    digitalWrite(dir_centro, LOW);
    digitalWrite(dir_inf, LOW);
    digitalWrite(dir_sup, LOW);
    digitalWrite(centro, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100); // Wait for 1000 millisecond(s)
    digitalWrite(LED_BUILTIN, LOW);
    delay(100); // Wait for 1000 millisecond(s)


    if (digitalRead(botao) == HIGH)
    {
        aleat = random(1, 7);

        if (aleat == 1) {
            digitalWrite(centro, HIGH);  
        }

        if (aleat == 2) {
            digitalWrite(esq_sup, HIGH);
            digitalWrite(dir_inf, HIGH);
        }

        if (aleat == 3) {
            digitalWrite(centro, HIGH);
            digitalWrite(esq_sup, HIGH);
            digitalWrite(dir_inf, HIGH);
        }

        if (aleat == 4) {
            digitalWrite(dir_sup, HIGH);
            digitalWrite(esq_sup, HIGH);
            digitalWrite(dir_inf, HIGH);
            digitalWrite(esq_inf, HIGH);
        }

        if (aleat == 5) {
            digitalWrite(dir_sup, HIGH);
            digitalWrite(esq_sup, HIGH);
            digitalWrite(dir_inf, HIGH);
            digitalWrite(esq_inf, HIGH);
            digitalWrite(centro, HIGH);
        }

        if (aleat == 6) {
            digitalWrite(dir_sup, HIGH);
            digitalWrite(esq_sup, HIGH);
            digitalWrite(dir_inf, HIGH);
            digitalWrite(esq_inf, HIGH);
            digitalWrite(dir_centro, HIGH);
            digitalWrite(esq_centro, HIGH);
        }

        delay(2500);
    }
}