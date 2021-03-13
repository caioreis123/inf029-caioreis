#include<stdio.h>

typedef struct{
    char _1[30];
    char _2[30];
    char _3[30];
}palavras;

palavras ler3palavras(){
    palavras palavras;
    printf("digite a letra 1 \n");
    fgets(palavras._1, 30, stdin);

    printf("digite a letra 2 \n");
    fgets(palavras._2, 30, stdin);

    printf("digite a letra 3 \n");
    fgets(palavras._3, 30, stdin);

    return palavras;
}

void main(){
    palavras palavras;
    palavras = ler3palavras();
    printf("%s", palavras._1);
    printf("%s", palavras._2);
    printf("%s", palavras._3);
}