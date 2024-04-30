/* 
Enzo Dorta Stevanato de Brito     Prof° Verissimo
Programa: calculadora HP12C       28/04/2024
Materia: Estrutura de dados
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMIT 50

typedef struct PILHA{
  int topo;
  float pElem[MAX_LIMIT];
}PILHA;

 PILHA * criarPilha(){
   PILHA * pilha = (PILHA*) malloc(sizeof(PILHA));
   pilha -> topo --;
   return pilha;
 }

float pushPilha(PILHA *pilha, float cot){
    pilha-> topo++;
    pilha -> pElem [pilha->topo] = cot;
  return 0;
}

float popPilha(PILHA *pilha){
  float topElement = pilha->pElem[pilha->topo]; 
  pilha->topo--;
  return topElement;
}

//oparit(){
  
}

float calcular(int elem1, int elem2, char operador){
  float resultado;
  switch(operador){

      case '+':
        resultado = elem1 + elem2;
        printf("Soma: %d + %d = %.1f\n", elem1, elem2, resultado);
      break;    

      case '-':
        resultado = elem1 - elem2;
        printf("Soma: %d - %d = %.1f\n", elem1, elem2, resultado);
      break;

      case '/':
        resultado = elem1 / elem2;
        printf("Soma: %d / %d = %.1f\n", elem1, elem2, resultado);
      break;

      case '*':
        resultado = elem1 * elem2;
        printf("Soma: %d * %d = %.1f\n", elem1, elem2, resultado);
      break;
      }
  return resultado;
    }
  


void processoHP(char rpn[],PILHA * pilha){

  char *ptr = strtok(rpn, " ");
  float resultado;
  
  while(ptr != NULL)
        {
    
          
        if(ptr[0] <= '9' && ptr[0] >= '0')
        {
          float continha = atof(ptr);
          pushPilha(pilha,continha);
        }
          
        else if(ptr[0] == '-' || ptr[0] == '+'|| ptr[0] == '*' || ptr[0] == '/')
        {
          int  elemento1 = popPilha(pilha);
          int  elemento2 = popPilha(pilha);

          resultado = calcular(elemento1,elemento2,ptr[0]);
          pushPilha(pilha,resultado);
        }
         ptr = strtok(NULL," ");
}
  oparit(resultado);
  printf("%.1f",resultado);
}

int main(void) {
  
  PILHA *pilha; 
  pilha = criarPilha();
  char rpn[MAX_LIMIT];

  printf("Insira sua expressão RPN:\n");
  scanf("%[^\n]s",rpn);

  processoHP(rpn, pilha);
  return 0;
}


/*int estaCheia(PILHA * pilha){
  int retorno;
  if (pilha->topo == pilha->capa-1){
    retorno = 1;
  }
  else {
    retorno = 0;
  }
  return retorno;
}

int estaVazia(PILHA * pilha){
  int retorno;
  if(pilha -> topo --)
  {
    retorno = 1;
  }
  else{
    retorno = 0;
  }
  return retorno;
}

fflush(stdin);
fgets(rpn, sizeof(rpn), stdin);

printf("%s\n", rpn);
fflush(stdin);
printf("%lu\n", strlen(rpn));
//printf("%c", rpn[0]);
int init_size = sizeof(ptr);


//char delim[] = " ";

printf("A forma aritmetica: %d x %d = %f", elemento1, elemento2, resultado);
        sprintf(ptr, "%f", resultado);
        pushPilha(pilha,ptr);
        ptr = strtok(NULL, " ");*/
