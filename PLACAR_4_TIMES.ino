

// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// DEFINIÇÕES de portas Arduino
#define endereco  0x27 // Endereços comuns: 0x27, 0x3F
#define colunas 16
#define linhas 2
#define botao1 6
#define botao2 10
#define botao3 11
#define botao4 4
#define botaolimpa 12
#define som 9

//lcd

//Variavel 'x,F' determina soma do botão botao2
int x = 0; // variavel time 1
int f = 0; // variavel time 2
int z = 0; // variavel time 3
int y = 0; // variavel time 4
int leiturabotaolimpa; //botão limpa tudo
int leiturabotao1 = 0;
int leiturabotao2 = 0;
int leiturabotao3 = 0;
int leiturabotao4 = 0;



// INSTANCIANDO OBJETOS
LiquidCrystal_I2C lcd(endereco, colunas, linhas);


void setup() {
  pinMode(botao1, INPUT_PULLUP); // INPUT_PULLUP usado para receber dados só quando pressionado
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(botao4, INPUT_PULLUP);
  pinMode(botaolimpa, INPUT_PULLUP);
  pinMode(som, OUTPUT);

  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY

  lcd.print("Carregando");// primeira mensagem
  delay(1000); // DELAY DE 2 SEGUNDOS
  //lcd.setCursor(0, 0);

  // Animação carregando....

  lcd.print(".");
  delay(500);
  lcd.setCursor(11, 0);
  lcd.print(".");
  delay(500);
  lcd.setCursor(12, 0);
  lcd.print(".");
  delay(500);
  lcd.setCursor(13, 0);
  lcd.print(".");
  delay(500);
  lcd.setCursor(14, 0);
  lcd.print(".");
  delay(500);
  lcd.setCursor(15, 0);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  lcd.setCursor(16, 0);




  lcd.clear(); // LIMPA O DISPLAY

  lcd.print(" *.*   Ola   ^.^ ");
  delay(1000); // DELAY DE 2 SEGUNDOS
  lcd.setCursor(4, 1);
  lcd.print(" Pessoal ");
  delay(4000); // DELAY DE 2 SEGUNDOS
  lcd.clear();

  lcd.setCursor(0, 0); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("Sejam Bem Vindos");
  delay(2000); // DELAY DE 2 SEGUNDOS

  lcd.clear(); // LIMPA O DISPLAY
  //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY



  lcd.print("Jogo: Familia");
  delay(1000); // DELAY DE 5 SEGUNDOS
  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("do Barulho");
  delay(4000); // DELAY DE 5 SEGUNDOS
  lcd.clear();

  lcd.setCursor(3, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("Boa Sorte");
  delay(2000); // DELAY DE 5 SEGUNDOS

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Para Iniciar ");
  delay(2000); // DELAY DE 5 SEGUNDOS

  lcd.setCursor(0, 1);
  lcd.print("Botao Branco");
  delay(2000); // DELAY DE 5 SEGUNDOS


  // leitura led times
  lcd.clear(); // LIMPA O DISPLAY
  //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY

  lcd.setCursor(0, 0); // POSICIONA  O CURSOR NA PRIMEIRA COLUNA DA LINHA 1
  lcd.print("Time1");

  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 1
  lcd.print("Time2");

  lcd.setCursor(10, 0); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 1
  lcd.print("Time3");

  lcd.setCursor(10, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 1
  lcd.print("Time4");

  lcd.setCursor(7, 0); // 'x' fixo na posição do placar
  lcd.print("x");

  lcd.setCursor(7, 1); // 'x' fixo na posição do placar
  lcd.print("x");

}

void loop() {



  //leitura botões
  leiturabotaolimpa = digitalRead(botaolimpa);


  if (!digitalRead(botaolimpa)) {

    if (leiturabotaolimpa == 0) {
      tone(som, 300, 500);//som de limpar
      delay(10);

      lcd.clear(); // LIMPA O DISPLAY
      //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY

      lcd.setCursor(0, 0); // POSICIONA  O CURSOR NA PRIMEIRA COLUNA DA LINHA 1
      lcd.print("Time1");

      lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 1
      lcd.print("Time2");

      lcd.setCursor(10, 0); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 1
      lcd.print("Time3");

      lcd.setCursor(10, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 1
      lcd.print("Time4");

      lcd.setCursor(7, 0); // 'x' fixo na posição do placar
      lcd.print("x");

      lcd.setCursor(7, 1); // 'x' fixo na posição do placar
      lcd.print("x");

      x = 0;
      f = 0;
      z = 0;
      y = 0;

      //Placar incia 0 a 0
      lcd.setCursor(6, 0); // time 1
      lcd.print("0");
      delay(500);

      lcd.setCursor(6, 1); // time 2
      lcd.print("0");
      delay(500);

      lcd.setCursor(8, 0); // time 3
      lcd.print("0");
      delay(500);

      lcd.setCursor(8, 1); // time 4
      lcd.print("0");
      delay(500);


    }

  }




  //Inicio botao1
  if (!digitalRead(botao1)) {

    x++; // Soma inicia em 0 e soma + 1 a cada clique.
    if (x == 10) {

      tone(som, 250);
      delay(200);
      noTone(som);
      x = 0;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("Time 1 Ganhou");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Para Reiniciar");
      lcd.setCursor(0, 1);
      lcd.print("Botao Branco");
    }

    //leitura botão 1
    leiturabotao1 = digitalRead(botao1);
    tone(som, 250); //som de clique no botao
    delay(50);
    noTone(som);

    if (!digitalRead(botao1)) {

      if (leiturabotao1 == 0) {
        lcd.setCursor(6, 0);
        lcd.print(x);
       
        
        delay(500);
      }
    }
  }


  //variavel soma botao 2
  if (!digitalRead(botao2)) {

    f++;
    if (f == 10) {
      tone(som, 250);
      delay(200);
      noTone(som);
      f = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Time 2 Ganhou");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Para Reiniciar");
      lcd.setCursor(0, 1);
      lcd.print("Botao Branco");
    }

    //leitura botão 2
    leiturabotao2 = digitalRead(botao2);
    tone(som, 250); //som de clique no botao
    delay(50);
    noTone(som);

    if (!digitalRead(botao2)) {

      if (leiturabotao2 == 0) {

        lcd.setCursor(6, 1);
        lcd.print(f);
        delay(500);
      }
    }
  }



  //Leitura BOtão 3
  if (!digitalRead(botao3)) {

    z++;
    if (z == 10) {
      tone(som, 250);
      delay(200);
      noTone(som);
      z = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Time 3 Ganhou");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Para Reiniciar");
      lcd.setCursor(0, 1);
      lcd.print("Botao Branco");
    }

    //leitura botão 2
    leiturabotao3 = digitalRead(botao3);
    tone(som, 250); //som de clique no botao
    delay(50);
    noTone(som);

    if (!digitalRead(botao3)) {

      if (leiturabotao3 == 0) {

        lcd.setCursor(8, 0);
        lcd.print(z);
        delay(500);
      }
    }
  }



  //Leitura Botão 4
  if (!digitalRead(botao4)) {

    y++;
    if (y == 10) {
      tone(som, 250);
      delay(200);
      noTone(som);
      y = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Time 4 Ganhou");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Para Reiniciar");
      lcd.setCursor(0, 1);
      lcd.print("Botao Branco");
    }

    //leitura botão 4
    leiturabotao4 = digitalRead(botao4);
    tone(som, 250); //som de clique no botao
    delay(50);
    noTone(som);

    if (!digitalRead(botao4)) {

      if (leiturabotao4 == 0) {

        lcd.setCursor(8, 1);
        lcd.print(y);
        delay(500);
      }
    }
  }
}
