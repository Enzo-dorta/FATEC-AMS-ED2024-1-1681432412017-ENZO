#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int *a, int n, int x){
  int i = 1;
  
  while (i <= n) {
    
    if (a[i] == x) {
      printf("Valor encontrado BL\n");
      return i;
    }
    
    i = i + 1;
  }
  printf("Valor não encontrado BL\n");
  return -1;
}