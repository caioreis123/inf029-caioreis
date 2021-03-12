#include<stdio.h>

int subtracao(int valor1, int valor2, int valor3){
    return valor1 - valor2 - valor3;
}

void main(){
    int valor1, valor2, valor3, resultado = 0;
    printf("Digite o primeiro valor \n");
    scanf("%d", &valor1);
    printf("Digite o segundo valor \n");
    scanf("%d", &valor2);
    printf("Digite o terceiro valor \n");
    scanf("%d", &valor3);

    resultado = subtracao(valor1, valor2, valor3);

    printf("o resultado da subtracao e: %d", resultado);
}