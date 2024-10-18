void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  pinMode(7, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(11, LOW);
  digitalWrite(5, LOW);
  
  /*desligando a ultima parte do codigo p/ continuar o loop*/
  
  digitalWrite(2, HIGH); //verde para carros1
  digitalWrite(8, HIGH);
  digitalWrite(13, HIGH);
  delay(5000);
  
  digitalWrite(7, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);//amarelo acende
  delay(2000);
 
  digitalWrite(2, LOW); 
  digitalWrite(4, LOW);
  digitalWrite(8, LOW);//verde p/ pedestre sem piscar
  digitalWrite(7, HIGH);
  digitalWrite(5, HIGH);
  delay(4000);
  
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  delay(400);
  digitalWrite(8, HIGH);
  delay(400);
  digitalWrite(8, LOW);//passagem do pedestre p/ vermelho
  delay(400);
  digitalWrite(8, HIGH);
  delay(400);
  digitalWrite(8, LOW);
  delay(400);
  
  digitalWrite(13, LOW);
  digitalWrite(8, HIGH);//verde p/ carros2
  digitalWrite(10, HIGH);
  delay(5000);
  
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);//amarelo acende verde apaga
  delay(2000);
  
}

  //PEDRESTES
  //Verde: 7
  //Vermelho: 8

  //CARROS
  //Verde: 2
  //Amarelo: 4
  //Vermelho: 5
  
  //CARROS 2
  //Verde: 10
  //Amarelo: 11
  //Vermelho: 13
