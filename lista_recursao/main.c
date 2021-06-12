#include <stdio.h>
#include <math.h>


int q1(int n) {
    if(n<3) return n;
    return q1(n-1)*n;
}

void teste_q1() {
    printf("%d\n", q1(1) == 1);
    printf("%d\n", q1(2) == 2);
    printf("%d\n", q1(4) == 24);
    printf("%d\n", q1(5) == 120);
}


int q2(int n) {
    if(n==1) return 0;
    if(n<4) return 1;
    return q2(n-1)+ q2(n-2);
}


void teste_q2() {
    printf("%d\n", q2(1) == 0);
    printf("%d\n", q2(2) == 1);
    printf("%d\n", q2(3) == 1);
    printf("%d\n", q2(4) == 2);
    printf("%d\n", q2(5) == 3);
    printf("%d\n", q2(12) == 89);
}

double q3(int n) {
    if(!n) return 0;
    int ultimo_digito = n%10;
    int qtd_digitos_menos1 = (int)log10(n);
    double futuro_primeiro_numero= pow(10, qtd_digitos_menos1) * ultimo_digito;
    int primeiros_digitos_sem_o_ultimo = n / 10;
    double invertido = futuro_primeiro_numero + q3(primeiros_digitos_sem_o_ultimo);
    return invertido;
}

void teste_q3() {
    printf("%d\n", q3(123)==321);
}



int q4(int vetor[], int tam) {
    if(tam==0) return 0;
    return vetor[--tam] + q4(vetor, tam);
}

void teste_q4() {
    int vetor[3] = {1,2,5};
    printf("%d\n", q4(vetor, 3)==8);
}

int q5(int n) {
    if(n==1) return n;
    return n+ q5(n-1);
}

void teste_q5() {
    printf("%d\n", q5(5)==15);
    printf("%d\n", q5(6)==21);
}

int q6(int k, int n) {
    if(n==1) return k;
    return k * q6(k, n-1);
}

void teste_q6() {
    printf("%d\n", q6(2,3)==8);
    printf("%d\n", q6(3,3)==27);
}
void q7(int vetor[], int primeiro_indice, int ultimo_indice) {
    if(ultimo_indice<=primeiro_indice) return;
    int aux = vetor[ultimo_indice];
    vetor[ultimo_indice] = vetor[primeiro_indice];
    vetor[primeiro_indice] = aux;
    q7(vetor, primeiro_indice+1, ultimo_indice-1);
}

void teste_q7() {
    int vetor[4] = {1,2,3,4};
    q7(vetor, 0, 3);
    int teste = vetor[0]==4 && vetor[1]==3 && vetor[2]==2 && vetor[3]==1;
    printf("%d\n", teste);
}

int q8(int x, int y) {
    if(y==0) return x;
    q8(y, x%y);
}

void teste_q8() {
    printf("%d\n", q8(10,5)==5);
    printf("%d\n", q8(10,4)==2);
}

int q9(int n) {
    if(n==1) return n;
    return n+ q9(n-1);
}

void teste_q9() {
    printf("%d\n", q9(5)==15);
    printf("%d\n", q9(6)==21);
}

int q10(int k, int n, int contador_de_aparicoes) {
    int qtd_digitos = (int)log10(n)+1;
    if(qtd_digitos==1) return contador_de_aparicoes;
    int ultimo_digito = n%10;
    if(ultimo_digito==k)contador_de_aparicoes++;
    q10(k, n/10, contador_de_aparicoes);
}


void teste_q10() {
    printf("%d\n", q10(2, 762021192, 0)==3);
}

int q11(int n1, int n2, int somatorio) {
    if(n2==0) return somatorio;
    somatorio +=n1;
    q11(n1, --n2, somatorio);
}


void teste_q11() {
    printf("%d\n", q11(2, 4, 0)==8);
    printf("%d\n", q11(3, 4, 0)==12);
}

void q12(int comeco, int fim) {
    if(comeco>fim) return;
    printf("%d", comeco++);
    q12(comeco, fim);
}


void teste_q12() {
    q12(0, 3);
}


void q13(int comeco, int fim) {
    if(fim<comeco) return;
    printf("%d", fim--);
    q13(comeco, fim);
}


void teste_q13() {
    q13(0, 3);
}

int main() {
//    teste_q1();
//    teste_q2();
//    teste_q3();
//    teste_q4();
//    teste_q5();
//    teste_q6();
//    teste_q7();
//    teste_q8();
//    teste_q9();
//    teste_q10();
//    teste_q11();
//    teste_q12();
    teste_q13();
    return 42;
}
