#define NOTE_FS4 370
#define NOTE_GS4 415
#define NOTE_B4  494
#define NOTE_D4  294
#define NOTE_D5  587
#define NOTE_CS4 277
#define NOTE_CS5 554
#define NOTE_E4  330
#define NOTE_E5  659
#define NOTE_A4  440

#define REST      0

#include <Servo.h> 
Servo servo1;

int led0 = 12;
int led1 = 10;
int led2 = 8;
int led3 = 7;
int led4 = 5;
int led5 = 3;
int pinoPOT = A0;
int buzzer = 13;
float valorPot = 0;

int tempo = 180;

int melody[] = {
    NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4, 
    NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4, 
    NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
    NOTE_A4, 2,
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;


void setup()
{
    pinMode(led0,OUTPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
    pinMode(led4,OUTPUT);
    pinMode(led5,OUTPUT);
    pinMode(pinoPOT, INPUT);
    servo1.attach(2);
    Serial.begin(9600);
}

void loop()
{
    valorPot = map(analogRead(pinoPOT), 0, 1023, 0, 255);
    analogWrite(led0, valorPot);
    Serial.println(valorPot);

    if (valorPot <=19) {
        digitalWrite(led0, LOW);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
    }

    if (valorPot >= 20 && valorPot <= 41) {
        digitalWrite(led0, HIGH);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
    }

    if (valorPot >= 42 && valorPot <= 83) {
        digitalWrite(led0, HIGH);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
    }

    if (valorPot >= 84 && valorPot <= 125) {
        digitalWrite(led0, HIGH);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
    }

    if (valorPot >= 126 && valorPot <= 167) {
        digitalWrite(led0, HIGH);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
        digitalWrite(led5, LOW);
    }

    if (valorPot >= 168 && valorPot <= 209) {
        digitalWrite(led0, HIGH);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, LOW);
    }

    if (valorPot >= 210) {
        digitalWrite(led0, HIGH);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        digitalWrite(led5, HIGH);

        for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
            divider = melody[thisNote + 1];

            if (divider > 0) {
                noteDuration = (wholenote) / divider;
            }
            else if (divider < 0) {
                noteDuration = (wholenote) / abs(divider);
                noteDuration *= 1.5; 
            }

            tone(buzzer, melody[thisNote], noteDuration * 0.9);

            delay(noteDuration);

            noTone(buzzer);
        }
    }
}


/* 
        Super Mario Bros - Overworld theme 
    Connect a piezo buzzer or speaker to pin 11 or select a new pin.
    More songs available at https://github.com/robsoncouto/arduino-songs/tree/master/nokia                                                                                          
                                                            Robson Couto, 2019
*/