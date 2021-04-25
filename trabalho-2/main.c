#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3

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
        int *ponteiroAuxiliar = vetorAuxiliar;

        estruturaAuxiliar.tamanho = tamanho;
        estruturaAuxiliar.indiceAtual = 0;
        estruturaAuxiliar.ponteiroParaOVetorAuxiliar = ponteiroAuxiliar;

        // adiciono o novo elemento no índice do vetor auxiliar e incremento ele para a pŕoxima adição
//        estruturaAuxiliar.elementos[estruturaAuxiliar.indiceAtual++] = elemento;
//        vetorAuxiliar[estruturaAuxiliar.indiceAtual++] = elemento;

        // cria o ponteiro pata o vetor auxiliar
//        EstruturaAuxiliar *ponteiroParaOVetorAux = &estruturaAuxiliar;

        // armazena o ponteiro para o vetor auxiliar na estrutura principal
//        vetorPrincipal[posicaoDoVetorPrincipal] = ponteiroParaOVetorAux;

        vetorPrincipal[posicaoDoVetorPrincipal]=estruturaAuxiliar;
    }
    //descomentar para possibilitar a adição em vetores auxiliares já criados:
//    else{
//        //crio uma variável do vetor auxiliar para facilitar seu acesso
//        EstruturaAuxiliar *vetorAux = vetorPrincipal[posicaoDoVetorPrincipal];
//
//        //verifico se há espaço para adições no vetor auxiliar
//        if (vetorAux->tamanho==vetorAux->indiceAtual){
//            printf("Esse vetor auxiliar nao comporta mais adicoes\n");
//        }
//        else{
//            // adiciono o novo elemento no índice do vetor auxiliar e incremento ele para a pŕoxima adição
//            vetorAux->elementos[vetorAux->indiceAtual++] = elemento;
//        }
//    }

}

void listarVetoresAuxiliares(EstruturaAuxiliar vetorPrincipal[]) {
    for (int indiceDoVetorPrincipal = 0; indiceDoVetorPrincipal < TAM; ++indiceDoVetorPrincipal) {
        int quantidadeDeElementos = vetorPrincipal[indiceDoVetorPrincipal].tamanho;
        printf("a posição %d tem %d espaços \n", indiceDoVetorPrincipal, quantidadeDeElementos);
        for(int indiceDoVetorAuxiliar = 0; indiceDoVetorAuxiliar < quantidadeDeElementos; indiceDoVetorAuxiliar++){
            int valorInserido = vetorPrincipal[indiceDoVetorPrincipal].ponteiroParaOVetorAuxiliar[indiceDoVetorAuxiliar];
            if(valorInserido >-1){
                printf("valores contidos na posição %d: %d \n", indiceDoVetorPrincipal, valorInserido);
            }
        }
    }
}

int main(){
    // declara um array de tamanho 10 cujo valor em cada índice é um ponteiro de valor 0
    EstruturaAuxiliar estruturaAuxiliarInicial;
    estruturaAuxiliarInicial.tamanho = 0;
    estruturaAuxiliarInicial.ponteiroParaOVetorAuxiliar = 0;
    estruturaAuxiliarInicial.indiceAtual = 0;
    EstruturaAuxiliar vetorPrincipal[TAM] = {estruturaAuxiliarInicial, estruturaAuxiliarInicial, estruturaAuxiliarInicial };
    insereElemento(2, 9, vetorPrincipal);
    listarVetoresAuxiliares(vetorPrincipal);
    return 42;
}

//
// Created by caio on 4/25/21.
//

