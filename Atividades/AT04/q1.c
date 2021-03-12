#include <stdio.h>

/*1) Crie um programa que tenha uma função soma e a função main. A função main deve ler dois
valores, enviar para a função soma. A função soma deve realizar a soma e retornar o valor. A
Função main deve imprimir o resultado da soma.*/

int soma(int valor1, int valor2);

int main() {
	int valor1, valor2, resultado = 0;

	printf("Digite o primeiro valor: ");
	scanf("%d", &valor1);

	printf("Digite o segundo valor: ");
	scanf("%d", &valor2);

	resultado = soma(valor1, valor2);
	printf("Resultado da soma: %d", resultado);

	return 0;
}

int soma(int valor1, int valor2){	
	int resultado = 0;
	resultado = valor1 + valor2;
	return resultado;
}