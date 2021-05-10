#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define TAM 3
typedef struct s{
    int *lista;
    int tamanho;
    int qtdInseridos;
} EstruturaSecundaria;

typedef struct no {
    int valor;
    struct no *proximoNo;
} No;

EstruturaSecundaria estruturaPrimaria[TAM];

int menu(){
    int escolha;
    printf("\nO que deseja?\n");
    printf("0 - Sair\n");
    printf("1 - Inserir elemento em determinada estrutura\n");
    printf("2 - Listar tamanho e elementos de todas estruturas\n");
    printf("3 - Excluir elemento de determinada estrutura\n");
    printf("4 - Aumentar tamanho de determinada estrutura\n");
    printf("5 - Listar ordenadamente os elementos de determinada estrutura\n");
    printf("6 - Listar ordenadamente todos os elementos de todas estruturas\n");
    scanf("%d", &escolha);
    return escolha;
}

int pegaValor() {
    int info;
    printf("Informe um valor : ");
    scanf("%i", &info);
    return info;
}

int pegaPosicao() {
    int pos;
    printf("Informe a posicao do vetor principal em que será inserido o valor: ");
    scanf("%i", &pos);
    return pos;
}

int validarPosicao(int posicao) {
    if ((posicao>0) && (posicao<=TAM)) return 1;
    return 0;
}

void criaEstruturaSecundaria(int posicao) {
    int tamanho;
    printf("Deseja criar estrutura secundaria com que tamanho?\n");
    scanf("%d", &tamanho);
    estruturaPrimaria[posicao].lista = (int*) malloc(tamanho*sizeof(int));
    estruturaPrimaria[posicao].tamanho = tamanho;
    estruturaPrimaria[posicao].qtdInseridos = 0;
}

void inserirElementos() {
    int valor = pegaValor();
    int posicao = pegaPosicao();
    int qtdInseridos;
    if(estruturaPrimaria[posicao].lista == NULL){
        criaEstruturaSecundaria(posicao);
    }
    qtdInseridos = estruturaPrimaria[posicao].qtdInseridos;
    estruturaPrimaria[posicao].lista[qtdInseridos] = valor;
    estruturaPrimaria[posicao].qtdInseridos = qtdInseridos+1;
}

void listarTodasSecundarias() {
    for(int i=0;i<TAM;i++){
        int qtdInseridos = estruturaPrimaria[i].qtdInseridos;
        int *listaAuxiliar = estruturaPrimaria[i].lista;
        int tamanhoDaLista = estruturaPrimaria[i].tamanho;
        printf("Na posicao %d temos %i elementos, sendo eles:", i, tamanhoDaLista);
        for(int j=0;j<qtdInseridos;j++){
            int elemento = listaAuxiliar[j];
            if(elemento!=0){
                printf("%i ", elemento);
            }
        }
        printf("\n");
    }
}

void removerElemento() {
    int indicePrincipal;
    int elementoASerRemovido;
    printf("Qual índice do vetor principal deseja acessar?\n");
    scanf("%d", &indicePrincipal);
    printf("Qual elemento deseja remover?\n");
    scanf("%d", &elementoASerRemovido);
    int tamanhoDaAuxiliar = estruturaPrimaria[indicePrincipal].tamanho;
    for(int i=0;i<tamanhoDaAuxiliar;i++){
        int elementoAtual = estruturaPrimaria[indicePrincipal].lista[i];
        if(elementoAtual==elementoASerRemovido){
            estruturaPrimaria[indicePrincipal].lista[i] = 0;
        }
    }
}

void aumentarTamanhoDeSecundaria() {
    int indicePrincipal;
    int novoTamanho;
    printf("Qual índice do vetor principal deseja aumentar?\n");
    scanf("%d", &indicePrincipal);
    printf("Qual o novo tamanho?\n");
    scanf("%d", &novoTamanho);
    estruturaPrimaria[indicePrincipal].lista = (int*) realloc(estruturaPrimaria[indicePrincipal].lista, novoTamanho*sizeof(int));
    estruturaPrimaria[indicePrincipal].tamanho = novoTamanho;
}

void ordenaVetor(int *vetor) {

}

void ordenarSecundaria() {
    int indicePrimaria;
    printf("Qual estrutura secundaria voce deseja ordenar?\n");
    scanf("%d", &indicePrimaria);
    ordenaVetor(estruturaPrimaria[indicePrimaria].lista);
}

int main(){
    int sair = 0;
    int escolha;
    while (!sair){
        escolha = menu();
        switch (escolha){
            case 0:{
                printf("vc saiu!");
                sair = 1;
                break;
            }
            case 1:{
                inserirElementos();
                break;
            }
            case 2:{
                listarTodasSecundarias();
                break;
            }
            case 3:{
                removerElemento();
                break;
            }
            case 4:{
                aumentarTamanhoDeSecundaria();
                break;
            }
            case 5:{
                ordenarSecundaria();
                break;
            }
        }
    }

}