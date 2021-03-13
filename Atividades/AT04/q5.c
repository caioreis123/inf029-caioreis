#include <stdio.h>

typedef struct
{
	int _1;
	int _2;
	int _3;
	int _4;
}valores;

valores ler4Numeros() {

	valores valores;

	printf("Digite o primeiro valor: ");
	scanf("%d", &valores._1);

	printf("Digite o segundo valor: ");
	scanf("%d", &valores._2);

	printf("Digite o terceiro valor: ");
	scanf("%d", &valores._3);

	printf("Digite o quarto valor: ");
	scanf("%d", &valores._4);

	return valores;
}

void main() {

	valores valores;

	valores = ler4Numeros();

	printf("Primeiro valor: %d\n", valores._1);
	printf("Segundo valor: %d\n", valores._2);
	printf("Terceiro valor: %d\n", valores._3);
	printf("Quarto valor: %d", valores._4);
}
