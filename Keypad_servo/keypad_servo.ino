#include <Keypad.h>
#include <Servo.h>
 

Servo servo;
const byte qtdLinhas = 4;
const byte qtdColunas = 4;

bool estadoServo = 0;

char matriz_teclas[qtdLinhas][qtdColunas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},  
  {'*', '0', '#', 'D'}, 
};


byte Linhas[qtdLinhas]= {16, 5, 4, 0};
byte Colunas[qtdColunas] = {2, 14, 12, 13}; 


Keypad teclado = Keypad(makeKeymap(matriz_teclas), Linhas, Colunas, qtdLinhas, qtdColunas);
String senha;
boolean statuss = false;
void setup () 
{
  servo.attach(15);
  Serial.begin(115200);





  Serial.println("#### MENU ####");
  Serial.println("Precione: '*' para criar senhar ou encerrar processo.");
  Serial.println("Precione: '#' para alterar senhar.");
  Serial.println("Precione: 'A' para altenticar.");

  
}

void loop () 
{



  
    char tecla_pressionada = teclado.getKey();
    servo.write(90);

    if (tecla_pressionada == 'A') 
    {
        Serial.println();
        Serial.print("informe sua senha : ");
        String temp;
        while (true) 
        {
            char digito = teclado.getKey();
            if (digito) 
            {
                Serial.print("*");
                temp += digito;
            }
            if (temp.length() >= 6) 
            {
            if (temp == senha)
            {
                Serial.println();
                Serial.println("Sucesso!");
                estadoServo = 1;
                break;
            }
            else{
                Serial.println();
                Serial.println("Senha incorrecta!");
                break;
            }
            if (digito == '*') {
                break;
            }
        }
    }
}

if (tecla_pressionada == '*') {
    Serial.print("informe a senha : ");
    senha = "";
    while (true) {
        char digito = teclado.getKey();
        if (digito) {
            Serial.print("*");
            senha += digito;
        }
        if (senha.length() >= 6) {
            Serial.println();
            Serial.println("feito!");
            break;
        }
        if (digito == '*') {
            senha = "";
            break;
        }
    }
}

if (tecla_pressionada == '#') {
    Serial.println();
    Serial.print("Informe sua senha : ");
    String temp;
    while (true) {
        char digito = teclado.getKey();
        if (digito) {
            Serial.print("*");
            temp  += digito;
        }
        if (temp.length() >= 6) {
            if (temp == senha)
            {
                Serial.println();
                Serial.println("Informe a nova senha: ");
                senha = "";
                while (true) {
                  char digito2 = teclado.getKey();
                  if (digito2) {
                    Serial.print("*");
                    senha += digito2;
                  }
                  if (senha.length() >= 6) {
                    Serial.println();
                    Serial.println("Senha alterada");
                    break;
                  }
                }
                   break;
                 }
                 else {
                  Serial.println();
                  Serial.println("Senha incorrecta");
                  break;
                }
              }
              if (digito == '*') {
                break;
              }
            }
          }   
if (tecla_pressionada == 'D') {
    estadoServo = 0;
}


switch (estadoServo){

case 0:
    servo.write(90);
    break;
    
case 1:
    servo.write(180);
    break;

}        
}
