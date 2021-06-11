#include <stdio.h>

int questao1(int n);

void teste_q1();

int main() {
    teste_q1();
    return 42;
}

void teste_q1() {
    printf("%d\n", questao1(1) == 1);
    printf("%d\n", questao1(2) == 2);
    printf("%d\n", questao1(4) == 24);
    printf("%d\n", questao1(5) == 120);
}

int questao1(int n) {
    if(n<3) return n;
    return questao1(n-1)*n;
}
