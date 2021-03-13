#include<stdio.h>

typedef struct{
    char nome[30];
    char dataNascimento[30];
    char cpf[30];
    char sexo[30];
}dados;

dados cadastrarCliente(){
    dados dados;

    printf("digite o nome \n");
    fgets(dados.nome, 30, stdin);

    printf("digite a data de nascimento \n");
    fgets(dados.dataNascimento, 30, stdin);

    printf("digite o cpf \n");
    fgets(dados.cpf, 30, stdin);
    
    printf("digite o sexo \n");
    fgets(dados.sexo, 30, stdin);

    return dados;
}

void main(){
    dados dados;
    dados = cadastrarCliente();
    printf("%s", dados.nome);
    printf("%s", dados.dataNascimento);
    printf("%s", dados.cpf);
    printf("%s", dados.sexo);
}