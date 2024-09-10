/*  09/09/2024    São Caetano do Sul
    Prof Carlos   Esturura de Dados
       BIG O - codigo e graficos
    Aluno: Enzo Dorta e Vicente Pascoal
*/




#include <stdio.h>
#include <stdlib.h>

#include "BuscaLinear.h"
#include "BuscaLinearOrdem.h"
#include "BuscaBinaria.h"

int main(void) {
  
  int x = 10;
  int arr[5] = {2,3,4,5,9}; // array universal
  
  int n = sizeof(arr) / sizeof(arr[0]);
  
  printf("-Busca Linear:\n");
  buscaLinear(arr, &n, &x);

  printf("-Busca Linear Ordenado:\n");
  buscaLinearOrdenada(arr, &n, &x);

  printf("-Busca Binária:\n");
  buscaBinaria(arr, &n, &x);

      
} 
