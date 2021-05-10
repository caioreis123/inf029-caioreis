#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <langinfo.h>

#define TAM 2

typedef struct {
    int tamanho;
    int indiceAtual;
    int *ponteiroParaOVetorAuxiliar;
}EstruturaAuxiliar;



int perguntaTamanhoDaEstruturaAuxiliar(){
    int tamanho;
    printf("Nao ha estrutura auxiliar criada para essa posicao. Deseja cria-la com que tamanho? \n");
    scanf("%d", &tamanho);
    return tamanho;
}

void insereElemento(int posicaoDoVetorPrincipal, int elemento, EstruturaAuxiliar vetorPrincipal[]){
    // verifica se já há vetor auxiliar naquele índice da estrutura principal
    if (vetorPrincipal[posicaoDoVetorPrincipal].tamanho == 0){
        // cria e preenche a estrutura auxiliar
        EstruturaAuxiliar estruturaAuxiliar;
        int tamanho = perguntaTamanhoDaEstruturaAuxiliar();
        int vetorAuxiliar[tamanho];
        for (int i = 0; i < tamanho; ++i) {
            vetorAuxiliar[i] = -1;
        }
        vetorAuxiliar[0] = elemento;

        estruturaAuxiliar.tamanho = tamanho;
        estruturaAuxiliar.indiceAtual = 1;
        estruturaAuxiliar.ponteiroParaOVetorAuxiliar = vetorAuxiliar;
        //pelo o que lí assim que saio desse escopo a variável vetorAuxiliar deixa de existir
        //e eu perco minha referencia.

        vetorPrincipal[posicaoDoVetorPrincipal]=estruturaAuxiliar;
    }
    //descomentar para possibilitar a adição em vetores auxiliares já criados:
//    else{
//        //crio uma variável do vetor auxiliar para facilitar seu acesso
//        EstruturaAuxiliar *estruturaAux = &vetorPrincipal[posicaoDoVetorPrincipal];
//
//        //verifico se há espaço para adições no vetor auxiliar
//        if (estruturaAux->tamanho == estruturaAux->indiceAtual){
//            printf("Esse vetor auxiliar nao comporta mais adições\n");
//        }
//        else{
//            // adiciono o novo elemento no índice do vetor auxiliar e incremento ele para a pŕoxima adição
//            estruturaAux->ponteiroParaOVetorAuxiliar[estruturaAux->indiceAtual++] = elemento;
//        }
//    }

}

void listarVetoresAuxiliares(EstruturaAuxiliar vetorPrincipal[]) {
    for (int indiceDoVetorPrincipal = 0; indiceDoVetorPrincipal < TAM; ++indiceDoVetorPrincipal) {
        int quantidadeDeElementos = vetorPrincipal[indiceDoVetorPrincipal].tamanho;
        printf("a posição %d tem %d espaços \n", indiceDoVetorPrincipal, quantidadeDeElementos);
        for(int indiceDoVetorAuxiliar = 0; indiceDoVetorAuxiliar < quantidadeDeElementos; indiceDoVetorAuxiliar++){
//            int *valorInserido = &vetorPrincipal[indiceDoVetorPrincipal].ponteiroParaOVetorAuxiliar[indiceDoVetorAuxiliar];
            EstruturaAuxiliar estruturaAux = vetorPrincipal[indiceDoVetorPrincipal];
            int point = *estruturaAux.ponteiroParaOVetorAuxiliar;
            int valorInserido = point;
            if(valorInserido >-1){
                printf("valores contidos na posição %d: %d \n", indiceDoVetorPrincipal, valorInserido);
            }
        }
    }
}

EstruturaAuxiliar criaEstruturaAuxiliarInicial() {
    EstruturaAuxiliar estruturaAuxiliarInicial;
    estruturaAuxiliarInicial.tamanho = 0;
    estruturaAuxiliarInicial.indiceAtual = 0;
    estruturaAuxiliarInicial.ponteiroParaOVetorAuxiliar = NULL;
    return estruturaAuxiliarInicial;
}

int identificaPosicaoDoVetorPrincipal() {
    int posicao;
    printf("Em que posição deseja adicionar?\n");
    scanf("%d", &posicao);
    return posicao;
}

int identificaElementoASerInserido() {
    int elemento;
    printf("Que elemento deseja adicionar?\n");
    scanf("%d", &elemento);
    return elemento;
}

int menuDeAdicao(EstruturaAuxiliar *vetorPrincipal) {
    int posicaoDoVetorPrincipal = identificaPosicaoDoVetorPrincipal();
    int elemento = identificaElementoASerInserido();
    insereElemento(posicaoDoVetorPrincipal, elemento, vetorPrincipal);
//    int retorno;
//    scanf("%d", &retorno);
    return 0;
}

int draft(){
    // declara um array de tamanho fixo cujo valor em cada índice é um struct
    EstruturaAuxiliar estruturaAuxiliarInicial = criaEstruturaAuxiliarInicial();
    EstruturaAuxiliar vetorPrincipal[TAM] = {estruturaAuxiliarInicial, estruturaAuxiliarInicial};
    int continua = 1;
    while(continua){
        continua = menuDeAdicao(vetorPrincipal);
    }
    listarVetoresAuxiliares(vetorPrincipal);
    return 42;
}

//
// Created by caio on 4/25/21.
//

