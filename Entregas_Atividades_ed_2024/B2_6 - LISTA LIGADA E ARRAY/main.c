#include <stdio.h>
#include <stdlib.h>

typedef struct numero{
  int num;
  struct numero *next;
}NUMERO;

NUMERO* listaCria(void){
    return NULL;
}

void listar(NUMERO *array) {
    NUMERO *temp;
    for (temp = array; temp != NULL; temp = temp->next) {
        printf("%d ", temp->num);
    }
}

NUMERO* listInsert(NUMERO* array,int tam,int val){    
    NUMERO *temp = array;
    NUMERO *valor = (NUMERO *)malloc(sizeof(NUMERO));
    valor->num = val;
    valor->next = NULL;

    if (array == NULL || val < array->num) {
        valor->next = temp;
        return valor;
    } 
    while (temp->next != NULL && temp->next->num < val) {
        temp = temp->next;
    } 
    valor->next = temp->next;
    temp->next = valor;

    return array;
    
}

int main(void) {
    NUMERO * p;
    p = listaCria();

    int array[5] = {10, 25, 40, 80};
    int val;

    printf("Enter a value to insert into the array: ");
    scanf("%d", &val);
    int tam = sizeof(array)/sizeof(array[0]); 

    p = listInsert(p, tam, val); // when insert number in the array, the array is sorted

    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        if (val <= array[i]) {
            for (int j = sizeof(array)/sizeof(array[0]) - 1; j > i; j--) {
                array[j] = array[j - 1];
            }
            array[i] = val;
            break;
        }
    }

    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    listar(p);

    return 0;
}
