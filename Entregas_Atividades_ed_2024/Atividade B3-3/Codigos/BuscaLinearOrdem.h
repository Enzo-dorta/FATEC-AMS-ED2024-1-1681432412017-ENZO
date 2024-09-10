# include <stdio.h>
# include <stdlib.h>


int buscaLinearOrdenada(int *a, int n, int x){
  
  int i;
  
  while ( x >= a[i] && i <= n){
  
    if (a[i] == x){
      printf("Valor encontrado BLO\n");
      return i;
    }
    
    i++;
  }
  printf("Valor não encontrado BLO\n");
  return -1;
}
