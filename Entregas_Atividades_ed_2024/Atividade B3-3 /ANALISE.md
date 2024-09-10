# Atividade Contagem de Tempo
## Enzo e Vicente

### -*Explicação BigO:*
- O BigO é uma notação usada para descrever a eficiência de algoritmos, especialmente em termos de tempo de execução ou uso de memória, à medida que o tamanho da entrada aumenta.

---

# -*Busca Linear*

Código Busca Linear:
sh
int buscaLinear(int arr[], int n, int x){
  int i = 1; // 1t
  while (i <= n) { // 1tn
    if (arr[i] == x) { //2tn
      return i; // 1t
    }
    i = i + 1; // 2t(n - 1) 
  }
  return -1; // 1t
}


Resultado da contagem de Tempo (t):
|  | Busca Linear |
| ------ | ------ |
| X ∉ A | 2t + 5tpx |

### BigO (*Pior dos Casos*):

- Quando o elemento está no ultimo lugar do array ou não esta o resultado do BigO é *O(n)*

![Gráfico Busca Linear](./image/BuscaLinear.png)

---
# -*Busca Linear em Ordem*

Código Busca Linear em Ordem:
sh
int buscaLinearOrdenada(int * a, int n, int x){
  int i; // 1t
  while ( x >= a[i] && i <= n){ // 3tn
    if (a[i] == x){ // 2tn
      return i; // 1t
    }
    i = i + 1; // 2t(n - 1)
  }
  return -1; // 1t
}


Resultado da contagem de Tempo (t):
|  | Busca Linear em Ordem |
| ------ | ------ |
| X ∉ A | 5tpx *ou* 8tn + 2t |

### BigO (*Pior dos Casos*):

- Quando o elemento está no ultimo lugar do array ou não esta o resultado do BigO é *O(n)*

![Gráfico Busca Linear em Ordem](./image/BuscaLinearOrdem.png)

---

# -*Busca Binária*

- A busca binária é um algoritmo de pesquisa que encontra um elemento em uma lista ordenada de forma eficiente. 
- Ela funciona dividindo a lista em duas partes, comparando o elemento do meio com o elemento procurado.
- Em seguida, faz uma busca recursiva na metade superior ou inferior da lista. 

Código da Busca Binária:

sh
int buscaBinaria(int * a, int n, int x){
  int esq = 1; // 1t
  int dir = n; // 1t
  while(esq <= dir){ // 1tn
    int meio = (esq + dir) / 2; // 3tn
    if (a[meio] == x){ // 2tn
      return meio; // 1t
    }
    else if(x >a[meio]){ // 2t(n - 1)
      esq = meio + 1; // 2t(n - 1)
    }
    else {
      dir = meio-1; 2t(n - 1)
    }
    break;
  }
  return -1; //1t
}



Resultado da contagem de Tempo (t):

|  | Busca Linear |
| ------ | ------ |
| X ∉ A| Log 2(n) |

### BigO (*Pior dos Casos*):

- Quando o elemento está no ultimo lugar do array ou não esta o resultado do BigO é *O(n)*

![Gráfico Busca Linear em Ordem](./image/BuscaBinaria.png)
