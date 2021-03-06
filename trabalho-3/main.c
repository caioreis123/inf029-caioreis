#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define TAM 10
typedef struct s{
    int *lista;
    int tamanho;
    int qtdInseridos;
} EstruturaSecundaria;

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

int posicionaPivot(int *vetor, int inicio, int fim) {
    //quicksort - Lomuto
    //pegamos o primeiro elemento, mas podemos pegar a mediana para ser mais eficiente
    int pivot = vetor[inicio];
    int indiceASerTrocado = inicio;
    for (int indiceASerAnalisado = inicio + 1; indiceASerAnalisado <= fim; indiceASerAnalisado++) {
        if (vetor[indiceASerAnalisado] < pivot) {
            indiceASerTrocado++;
            int aux = vetor[indiceASerTrocado];
            vetor[indiceASerTrocado] = vetor[indiceASerAnalisado];
            vetor[indiceASerAnalisado] = aux;
        }
    }
    vetor[inicio] = vetor[indiceASerTrocado];
    vetor[indiceASerTrocado] = pivot;
    return indiceASerTrocado;
}

void ordenaVetor(int *vetor, int inicio, int fim) {
    if(inicio<fim){
        int indicePivot = posicionaPivot(vetor, inicio, fim);
        ordenaVetor(vetor, inicio, indicePivot);
        ordenaVetor(vetor, indicePivot+1, fim);
    }
}

void ordenarSecundaria() {
    int indicePrimaria;
    printf("Qual estrutura secundaria voce deseja ordenar?\n");
    scanf("%d", &indicePrimaria);
    ordenaVetor(estruturaPrimaria[indicePrimaria].lista, 0, estruturaPrimaria[indicePrimaria].tamanho);
}

void ordenarTodosSecundarios() {
    for(int indicePrimario = 0; indicePrimario<TAM;indicePrimario++){
        if(estruturaPrimaria[indicePrimario].lista !=NULL){
            ordenaVetor(estruturaPrimaria[indicePrimario].lista, 0, estruturaPrimaria[indicePrimario].tamanho);
        }
    }
}


void salvarEstruturaSecundaria(EstruturaSecundaria estruturaSecundaria, int indicePrincipal, FILE *arquivo) {
    fprintf(arquivo, "%d;", indicePrincipal);
    fprintf(arquivo, "%d;", estruturaSecundaria.tamanho);
    fprintf(arquivo, "%d;", estruturaSecundaria.qtdInseridos);
    for(int i=0; i<estruturaSecundaria.qtdInseridos;i++){
        fprintf(arquivo, "%d;", estruturaSecundaria.lista[i]);
    }
    fprintf(arquivo,"\n");
    fclose(arquivo);
}

void salvarTodosValores() {
    FILE *arquivo = fopen("dados.txt", "w");
    for(int indicePrincipal = 0; indicePrincipal<TAM; indicePrincipal++){
        if (estruturaPrimaria[indicePrincipal].lista == NULL) continue;
        salvarEstruturaSecundaria(estruturaPrimaria[indicePrincipal], indicePrincipal, arquivo);
    }
    fclose(arquivo);
}

void lerDados() {
    char linha[1001];
    char vetorAux[1000];
    FILE *arquivo = fopen("dados.txt", "r");
    if(arquivo==NULL) return;
    while(!feof(arquivo)){
        int singleInput=0;
        int indiceAux=0;
        fgets(linha, 1001, arquivo);
        int indicePrincipal = (int)(linha[0]);
        singleInput++;
        while (linha[singleInput]!=';'){
            vetorAux[indiceAux] = linha[singleInput];
            indiceAux++;
            singleInput++;
        }
        estruturaPrimaria[indicePrincipal].tamanho = atoi(vetorAux);
        indiceAux = 0;
        singleInput++;
        while (linha[singleInput]!=';'){
            vetorAux[indiceAux] = linha[singleInput];
            indiceAux++;
            singleInput++;
        }
        estruturaPrimaria[indicePrincipal].qtdInseridos = atoi(vetorAux);
        indiceAux = 0;
        while (linha[singleInput]!='\n'){
            estruturaPrimaria[indicePrincipal].lista[indiceAux] = (int)(linha[singleInput]);
            indiceAux++;
            singleInput++;
        }
    }
    fclose(arquivo);
}

int main(){
    int sair = 0;
    int escolha;
    lerDados();
    while (!sair){
        escolha = menu();
        switch (escolha){
            case 0:{
                printf("Finalizando...");
                salvarTodosValores();
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
            case 6:{
                ordenarTodosSecundarios();
                break;
            }
        }
    }

}