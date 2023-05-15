/*
 * Neste projeto, será utilizado um display de 7 segmentos com cátodo comum.
 * É configurada todos os pinos do LED e analisado a combinação dos LEDs no display para a formação do dígito
 * Quando iniciado o sistema, o display irá aparecer o valor 0
 * Na medida que é apertado o botão, a variável contar e o display acrescentarão 1
 * Quando a variável contar chegar a 10, a variável contar é defiinida a 0, e o display mostrará o dígito 0, reiniciando a contagem.
*/

/*
 * Observar se o display tem como ponto comum o ânodo ou cátodo. Neste protótipo é utilizado o cátodo comum.
 * Caso seja ânodo comum, alterar estado de todos os pinos de HIGH para LOW.
 */

//Declaração de variáveis globais
int contar = 0; // Será a variável que armazenará o valor apresentado no Display

int pinoBotao = 12; // Pino de leitura do botão

int pinoA = 2; // Pino do LED A do Display
int pinoB = 3; // Pino do LED B do Display
int pinoC = 4; // Pino do LED C do Display
int pinoD = 5; // Pino do LED D do Display
int pinoE = 6; // Pino do LED E do Display
int pinoF = 7; // Pino do LED F do Display
int pinoG = 8; // Pino do LED G do Display


void setup()
{
  //Atribuição do pino do botão como entrada
  pinMode(pinoBotao, INPUT);

  //Atribuição do pino do LED A do Display  como saída
  pinMode(pinoA, OUTPUT);
  
  //Atribuição do pino do LED B do Display  como saída
  pinMode(pinoB, OUTPUT);
  
  //Atribuição do pino do LED C do Display  como saída
  pinMode(pinoC, OUTPUT);
  
  //Atribuição do pino do LED D do Display  como saída
  pinMode(pinoD, OUTPUT);
  
  //Atribuição do pino do LED E do Display  como saída
  pinMode(pinoE, OUTPUT);
  
  //Atribuição do pino do LED F do Display  como saída
  pinMode(pinoF, OUTPUT);
  
  //Atribuição do pino do LED G do Display  como saída
  pinMode(pinoG, OUTPUT);
}


void loop()
{
  //Condicional que verifica o estado do Botão. Se o botão for pressionado, acrescenta 1 na variável contar
  if (digitalRead(pinoBotao) == HIGH) {
    //Argumento que acrescenta 1 na variável contar
    contar += 1; //contar = contar + 1

    //Condicional que verifica se contar chegou a 10; Caso chegar, reinicia o valor para 0
    if(contar>=10){
      contar=0;
    }
  }

  //Condicional que verifica se o valor de contar é 0 para apresentar 0 no display
  if (contar == 0) {
      digitalWrite(pinoA, HIGH); //Liga LED A
      digitalWrite(pinoB, HIGH); //Liga LED B
      digitalWrite(pinoC, HIGH); //Liga LED C
      digitalWrite(pinoD, HIGH); //Liga LED D
      digitalWrite(pinoE, HIGH); //Liga LED E
      digitalWrite(pinoF, HIGH); //Liga LED F
      digitalWrite(pinoG, LOW); //Desliga LED G
    }

    //Condicional que verifica se o valor de contar é 1 para apresentar 1 no display
    if (contar == 1) {
      digitalWrite(pinoA, LOW); //Desliga LED A
      digitalWrite(pinoB, HIGH); //Liga LED B
      digitalWrite(pinoC, HIGH); //Liga LED C
      digitalWrite(pinoD, LOW); //Desliga LED D
      digitalWrite(pinoE, LOW); //Desliga LED E
      digitalWrite(pinoF, LOW); //Desliga LED F
      digitalWrite(pinoG, LOW); //Desliga LED G
    }
    if (contar == 2) {
      digitalWrite(pinoA, HIGH); //Liga LED A
      digitalWrite(pinoB, HIGH); //Liga LED B
      digitalWrite(pinoC, LOW); //Desliga LED C
      digitalWrite(pinoD, HIGH); //Liga LED D
      digitalWrite(pinoE, HIGH); //Liga LED E
      digitalWrite(pinoF, LOW); //Desliga LED F
      digitalWrite(pinoG, HIGH); //Liga LED G
    }    
  	if (contar == 3) {
      digitalWrite(pinoA, HIGH); //Liga LED A
      digitalWrite(pinoB, HIGH); //Liga LED B
      digitalWrite(pinoC, HIGH); //Liga LED C
      digitalWrite(pinoD, HIGH); //Liga LED D
      digitalWrite(pinoE, LOW); //Desliga LED E
      digitalWrite(pinoF, LOW); //Desliga LED F
      digitalWrite(pinoG, HIGH); //Liga LED G
    }
  	if (contar == 4) {
      digitalWrite(pinoA, LOW); //Desliga LED A
      digitalWrite(pinoB, HIGH); //Liga LED B
      digitalWrite(pinoC, HIGH); //Liga LED C
      digitalWrite(pinoD, LOW); //Desliga LED D
      digitalWrite(pinoE, LOW); //Desliga LED E
      digitalWrite(pinoF, HIGH); //Liga LED F
      digitalWrite(pinoG, HIGH); //Liga LED G
    }
  	if (contar == 5) {
      digitalWrite(pinoA, HIGH); //Liga LED A
      digitalWrite(pinoB, LOW); //Desliga LED B
      digitalWrite(pinoC, HIGH); //Liga LED C
      digitalWrite(pinoD, HIGH); //Liga LED D
      digitalWrite(pinoE, LOW); //Desliga LED E
      digitalWrite(pinoF, HIGH); //Liga LED F
      digitalWrite(pinoG, HIGH); //Liga LED G
    }
   	if (contar == 6) {
      digitalWrite(pinoA, HIGH); //Liga LED A
      digitalWrite(pinoB, LOW); //Desliga LED B
      digitalWrite(pinoC, HIGH); //Liga LED C
      digitalWrite(pinoD, HIGH); //Liga LED D
      digitalWrite(pinoE, HIGH); //Liga LED E
      digitalWrite(pinoF, HIGH); //Liga LED F
      digitalWrite(pinoG, HIGH); //Liga LED G
    }
  	if (contar == 7) {
      digitalWrite(pinoA, HIGH);  //Liga LED A
      digitalWrite(pinoB, HIGH); //Liga LED B
      digitalWrite(pinoC, HIGH); //Liga LED C
      digitalWrite(pinoD, LOW); //Desliga LED D
      digitalWrite(pinoE, LOW); //Desliga LED E
      digitalWrite(pinoF, LOW); //Desliga LED F
      digitalWrite(pinoG, LOW); //Desliga LED G
    }
  	if (contar == 8) {
      digitalWrite(pinoA, HIGH); //Liga LED A
      digitalWrite(pinoB, HIGH); //Liga LED B
      digitalWrite(pinoC, HIGH); //Liga LED C
      digitalWrite(pinoD, HIGH); //Liga LED D
      digitalWrite(pinoE, HIGH); //Liga LED E
      digitalWrite(pinoF, HIGH); //Liga LED F
      digitalWrite(pinoG, HIGH); //Liga LED G
    }
  	if (contar == 9) {
      digitalWrite(pinoA, HIGH); //Liga LED A
      digitalWrite(pinoB, HIGH); //Liga LED B
      digitalWrite(pinoC, HIGH); //Liga LED C
      digitalWrite(pinoD, HIGH); //Liga LED D
      digitalWrite(pinoE, LOW); //Desliga LED E
      digitalWrite(pinoF, HIGH); //Liga LED F
      digitalWrite(pinoG, HIGH); //Liga LED G
    }
  
  delay(100); // Contagem de tempo dedicada para melhor desempenho do protótipo
}
