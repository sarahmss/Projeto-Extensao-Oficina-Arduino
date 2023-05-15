/*
 * Neste projeto, será utilizado um display de 7 segmentos com cátodo comum.
 * É configurada todos os pinos do LED e analisado a combinação dos LEDs no display para a formação do dígito
 * Quando iniciado o sistema, o display irá aparecer o valor 9
 * Na medida que é apertado o botão, a variável contar e o display diminuirá em 1
 * Quando a variável contar chegar a -1, a variável contar é redefiinida a 9, e o display mostrará o dígito 9, reiniciando a contagem.
 * Neste exemplo, será utilizado funções, vetores e repetição for
*/

/*
 * Observar se o display tem como ponto comum o ânodo ou cátodo. Neste protótipo é utilizado o cátodo comum.
 * Caso seja ânodo comum, inverter os números 1 e 0 na matriz int numeros.
 */

//Declaração de variáveis globais
int contar = 9; // Será a variável que armazenará o valor apresentado no Display

int pinoBotao = 12; // Pino de leitura do botão

					            //a,b,c,d,e,f,g
int pinoSegmentos[7] = {2,3,4,5,6,7,8}; //Vetor com os pinos de acionamento do dispaly de 7 segmentos

//Matriz com a combinação dos números binários de acordo com os números decimais
int numeros[10][7]={{1,1,1,1,1,1,0}, //0
                   {0,1,1,0,0,0,0}, //1
                   {1,1,0,1,1,0,1}, //2
                   {1,1,1,1,0,0,1}, //3
                   {0,1,1,0,0,1,1}, //4
                   {1,0,1,1,0,1,1}, //5
                   {1,0,1,1,1,1,1}, //6
                   {1,1,1,0,0,0,0}, //7
                   {1,1,1,1,1,1,1}, //8
                   {1,1,1,1,0,1,1} //9
                  };

//Função criada para quando chamada, acionar os LEDs do display exibindo o valor da variável contar
void acenderSegmentos(){
  
  /*A função for é uma estrutura de repetição que se repete verificando se a condição central for verdadeira.
   * Enquanto a condição for falsa, a função for acrescenta 1 a variável local i e executa as instruções na função.
   * O valor 7 corresponde ao tamanho do vetor pinoSegmentos que são 7 espaços.
   */
  for(int i=0;i<7;i++){
    /*Para cada segmento, lê-se o local do seu pino no vetor pinoSegmentos
     *Para cada número para ser exibido, lê se a matriz numeros na linha com endereço da variável contar, e na coluna no qual o segmento atual na repetição está.
     *Se for 1, o segmento irá ligar, se for 0, o segmento irá desligar.
     */
    digitalWrite(pinoSegmentos[i], numeros[contar][i]); 
  }
}
                  
// Função principal de configuração do sistema
void setup()
{
  //Atribuição do pino do botão como entrada
  pinMode(pinoBotao, INPUT);

  //Atribuição dos pinos do display como saidas.
  /*A função for é uma estrutura de repetição que se repete verificando se a condição central for verdadeira.
   * Enquanto a condição for falsa, a função for acrescenta 1 a variável local i e executa as instruções na função.
   * O valor 7 corresponde ao tamanho do vetor pinoSegmentos que são 7 espaços.
   */
  for(int i=0;i<7;i++){
  	pinMode(pinoSegmentos[i], OUTPUT);  
  }

  //Função criada para acender o display com o valor armazenado na variável contar
  acenderSegmentos();
}

// Função de repetição contínua do sistema
void loop()
{
  //Condicional que verifica o estado do Botão. Se o botão for pressionado, diminuirá 1 na variável contar
  if (digitalRead(pinoBotao) == HIGH) {
    
    //Argumento que acrescenta 1 na variável contar
    contar --; //contar = contar - 1

    //Condicional que verifica se contar chegou a 0; Caso chegar, reinicia o valor para 9
    if(contar<0){
      contar=9;
    }
  //Função criada para acender o display com o valor armazenado na variável contar
    acenderSegmentos();
  }
  
  delay(100); // Contagem de tempo dedicada para melhor desempenho do protótipo evitando o efeito boucing
}
