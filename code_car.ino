#include <Servo.h>

int com;         //переменная для хранения команды для механизма   

int ina=9;       //управление скоростью
int inb=10;

int en1=2;       //контакты правого мотор-редуктора
int en2=3;

int en3=4;       //контакты левого мотор-редуктора
int en4=5;

Servo klesh;     //имя серво-привода

void setup()
{
pinMode(ina, INPUT);
pinMode(inb, INPUT);
pinMode(en1, OUTPUT);  
pinMode(en2, OUTPUT);  
pinMode(en3, OUTPUT);
pinMode(en4, OUTPUT);
klesh.attach(6);         //подключаем серво к 6 порту ардуино
klesh.write(0);          //поворачиваем серво в положение 0 градусов
Serial.begin(9600);
  
}

void loop()
{
  analogWrite(ina, 255);       //устанавливаем скорость(0-255)
  analogWrite(inb, 255);
  
  if (Serial.available()>0){           //считываем значения в мониторе порта     
    com=Serial.read();
  }
  	if (com=='1'){                      //ВПЕРЕД
    digitalWrite(en1, HIGH);
    digitalWrite(en2, LOW);
      
    digitalWrite(en3, HIGH);
    digitalWrite(en4, LOW);
  }
  
 
  	if (com=='2'){                         //НАЗАД
    digitalWrite(en1, LOW);
    digitalWrite(en2, HIGH);
      
    digitalWrite(en3, LOW);
    digitalWrite(en4, HIGH);
  }
  
  
    if (com=='3'){                         //ВПРАВО
    digitalWrite(en1, HIGH);
    digitalWrite(en2, LOW);
      
    digitalWrite(en3, LOW);
    digitalWrite(en4, HIGH);
  }
  
  
    if (com=='4'){                         //ВЛЕВО
    digitalWrite(en1, LOW);
    digitalWrite(en2, HIGH);
      
    digitalWrite(en3, HIGH);
    digitalWrite(en4, LOW);
  }
  
  if (com=='0'){                         //НАЗАД
    digitalWrite(en1, LOW);
    digitalWrite(en2, LOW);
      
    digitalWrite(en3, LOW);
    digitalWrite(en4, LOW);
  }
  
  
  
      if (com=='5'){                         //ЗАХВАТ
  klesh.write(90);  
      }
  
      if (com=='6'){                         //ЗАХВАТ НАОБОРОТ
  klesh.write(0);  
      }
}