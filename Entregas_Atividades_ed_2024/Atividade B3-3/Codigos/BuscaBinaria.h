# include <stdio.h>
# include <stdlib.h>


int buscaBinaria(int *a, int n, int x){
  
  int esq = 0;
  int dir = n;
  
  while(esq <= dir){
    
    int meio = (esq + dir) / 2;
    
    if (a[meio] == x){
      printf("Valor encontrado BB\n");
      return meio;
    }
      
    else if(x >a[meio]){
      esq = meio + 1;
    }
      
    else {
      dir = meio-1;
    }
    
    break;
  }
  printf("Valor não encontrado BB\n");
  return -1;
}
