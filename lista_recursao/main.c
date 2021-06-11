#include <stdio.h>

int questao1(int n);

void teste_q1();
void teste_q2();

int questao2(int n);

int main() {
    teste_q1();
    teste_q2();
    return 42;
}

void teste_q1() {
    printf("%d\n", questao1(1) == 1);
    printf("%d\n", questao1(2) == 2);
    printf("%d\n", questao1(4) == 24);
    printf("%d\n", questao1(5) == 120);
}
void teste_q2() {
    printf("%d\n", questao2(1) == 0);
    printf("%d\n", questao2(2) == 1);
    printf("%d\n", questao2(3) == 1);
    printf("%d\n", questao2(4) == 2);
    printf("%d\n", questao2(5) == 3);
    printf("%d\n", questao2(12) == 89);
}

int questao2(int n) {
    if(n==1) return 0;
    if(n<4) return 1;
    return questao2(n-1)+ questao2(n-2);
}

int questao1(int n) {
    if(n<3) return n;
    return questao1(n-1)*n;
}
