// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém exemplos de testes das questões do trabalho.
//  o aluno pode incrementar os testes

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 19/08/2016 - 12/12/2018

// #################################################

#include<stdio.h>
#include<string.h>

//renomeie o arquivo do include abaixo para PrimeiroUltimoNomeMATRICULA.c
#include "CaioReis-2019116005-T1.h"

void testSomar(); //função utilizada para testes
void testFatorial(); //função utilizada para testes
void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main(){
    // testQ1();
    // testQ2();
    // testQ3();
    // testQ4();
    // testQ5();
    testQ6();
    // testSomar();
    // testFatorial();
}


void testSomar(){
    printf("%d\n",somar(3, 4) == 7);
    printf("%d\n",somar(-1, 3) == 2);
    printf("%d\n",somar(-6, 6) == 0);
    printf("%d\n",somar(74, 9) == 83);
    printf("%d\n",somar(30, -9) == 21);
}

void testFatorial(){
    printf("%d\n",fatorial(3) == 6);
    printf("%d\n",fatorial(1) == 1);
    printf("%d\n",fatorial(5) == 120);
}

void testQ1(){
    char str[11];
    strcpy(str,"29/02/15");
    printf("%d\n",q1(str));
    strcpy(str,"29/02/12");
    printf("%d\n",q1(str));
    strcpy(str,"9/13/21");
    printf("%d\n",q1(str));
    strcpy(str,"45/4/99");
    printf("%d\n",q1(str));
}

void testQ2(){
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    int retorno;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"01/06/2015");
    strcpy(datafinal,"01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    printf("retorno: %d\n",retorno);
    printf("qtdDias: %d\n",qtdDias);
    printf("qtdMeses: %d\n",qtdMeses);
    printf("qtdAnos: %d\n",qtdAnos);

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"01/30/2015");
    strcpy(datafinal,"01/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    // printf("%d\n",retorno == 2); data inicial inválida
    printf("retorno: %d\n",retorno);
    printf("qtdDias: %d\n",qtdDias);
    printf("qtdMeses: %d\n",qtdMeses);
    printf("qtdAnos: %d\n",qtdAnos);

    strcpy(datainicial,"01/3/2015");
    strcpy(datafinal,"40/06/2016");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    // printf("%d\n",retorno == 3); data final inválida
    printf("retorno: %d\n",retorno);
    printf("qtdDias: %d\n",qtdDias);
    printf("qtdMeses: %d\n",qtdMeses);
    printf("qtdAnos: %d\n",qtdAnos);

    strcpy(datainicial,"01/06/2016");
    strcpy(datafinal,"01/06/2015");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    // printf("%d\n",retorno == 4);
    printf("retorno: %d\n",retorno);
    printf("qtdDias: %d\n",qtdDias);
    printf("qtdMeses: %d\n",qtdMeses);
    printf("qtdAnos: %d\n",qtdAnos);


    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"07/07/2017");
    retorno = q2(datainicial, datafinal, &qtdDias, &qtdMeses, &qtdAnos);
    // printf("%d\n",retorno == 1);   
    printf("retorno: %d\n",retorno);
    printf("qtdDias: %d\n",qtdDias);
    printf("qtdMeses: %d\n",qtdMeses);
    printf("qtdAnos: %d\n",qtdAnos);

}

void testQ3(){
    char str[250];
    strcpy(str,"Renato Lima Novais");
    printf("%d\n",q3(str, 'a', 0));//return==3
    printf("%d\n",q3(str, 'b', 0));//return==0
    printf("%d\n",q3(str, 'l', 1));//return==0
    printf("%d\n",q3(str, 'l', 0));//return==1
    printf("%d\n",q3(str, 'L', 0));//return==1
}

void testQ4(){
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca,"rato");
    // printf("%d\n",q4(strTexto, strBusca, posicoes));//==2
    // printf("%d\n",posicoes[0]);//==5
    // printf("%d\n",posicoes[1]);//==8
    // printf("%d\n",posicoes[2]);//==34
    // printf("%d\n",posicoes[3]);//==37


    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Olá, o mundo é muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca,"mui");
    printf("%d\n",q4(strTexto, strBusca, posicoes));//== 3
    printf("%d\n",posicoes[0]);//==16
    printf("%d\n",posicoes[1]);//==18
    printf("%d\n",posicoes[2]);//==34
    printf("%d\n",posicoes[3]);//==36
    printf("%d\n",posicoes[4]);//==52
    printf("%d\n",posicoes[5]);//==54

}

void testQ5(){
    printf("%d\n",q5(345));//== 543
    printf("%d\n",q5(78));// == 87
    printf("%d\n",q5(3));// == 3
    printf("%d\n",q5(5430));//== 345
}

void testQ6(){
    printf("%d\n",q6(34567368, 3));// == 2
    printf("%d\n",q6(34567368, 4576));// == 0
    printf("%d\n",q6(3539343, 3));// == 4
    printf("%d\n",q6(3539343, 39));// == 1

}
