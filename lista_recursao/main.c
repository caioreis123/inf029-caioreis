#include <stdio.h>
#include <math.h>



int questao1(int n) {
    if(n<3) return n;
    return questao1(n-1)*n;
}

void teste_q1() {
    printf("%d\n", questao1(1) == 1);
    printf("%d\n", questao1(2) == 2);
    printf("%d\n", questao1(4) == 24);
    printf("%d\n", questao1(5) == 120);
}


int questao2(int n) {
    if(n==1) return 0;
    if(n<4) return 1;
    return questao2(n-1)+ questao2(n-2);
}


void teste_q2() {
    printf("%d\n", questao2(1) == 0);
    printf("%d\n", questao2(2) == 1);
    printf("%d\n", questao2(3) == 1);
    printf("%d\n", questao2(4) == 2);
    printf("%d\n", questao2(5) == 3);
    printf("%d\n", questao2(12) == 89);
}

double questao3(int n) {
    if(!n) return 0;
    int ultimo_digito = n%10;
    int qtd_digitos_menos1 = (int)log10(n);
    double futuro_primeiro_numero= pow(10, qtd_digitos_menos1) * ultimo_digito;
    int primeiros_digitos_sem_o_ultimo = n / 10;
    double invertido = futuro_primeiro_numero + questao3(primeiros_digitos_sem_o_ultimo);
    return invertido;
}

void teste_q3() {
    printf("%d\n", questao3(123)==321);
}

int main() {
    teste_q1();
    teste_q2();
    teste_q3();
    return 42;
}
