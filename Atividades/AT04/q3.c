#include<stdio.h>

int fatorial(int valor1){
    int fatorial = 1;

    if (valor1 < 1){
        return -1;
    }
    for(; valor1 > 1; valor1 = valor1 - 1) {
			fatorial = fatorial * valor1;
		}
		return fatorial;
}

void main(){
    int valor1, resultado = 0;

	printf("Digite o valor: ");
	scanf("%d", &valor1);

    resultado = fatorial(valor1);

    if (resultado==-1){
        printf("nao e possivel calcular o fatorial desse valor \n");
    }
    printf("o resultado e: %d", resultado);
}