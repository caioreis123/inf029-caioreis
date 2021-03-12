#include<stdio.h>

void ler3numeros(int vetor[]){
    for (int i=0;i<3;i++){
        printf("Digite um valor \n");
        scanf("%d", &vetor[i]);
    }
}

void main(){
    int vetor[3];
    
    ler3numeros(vetor);

    for (int i=0;i<3;i++){
        printf("%d \n", vetor[i]);
    }
}