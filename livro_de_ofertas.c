#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int posicao;
    double valor;
    int quantidade;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} ListaLigada;

void inicializarLista(ListaLigada *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

No* criarNo(int pos, double valor, int qtd) {
    No *novo = (No*)malloc(sizeof(No));
    novo->posicao = pos;
    novo->valor = valor;
    novo->quantidade = qtd;
    novo->prox = NULL;
    
    return novo;
}

void atualizarPosicoes(ListaLigada *lista) {
    No *atual = lista->inicio;
    int pos = 1;
    
    while (atual != NULL) {
        atual->posicao = pos++;
        atual = atual->prox;
    }
}

void inserirOferta(ListaLigada *lista, int pos, double valor, int qtd) {
    No *novo = criarNo(pos, valor, qtd);
    
    if (lista->inicio == NULL || pos == 1) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
    } 
    
    else {
        No *anterior = lista->inicio;
        int i;
        
        for (i = 1; i < pos - 1 && anterior->prox != NULL; i++) {
            anterior = anterior->prox;
        }
        
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }
    
    lista->tamanho++;
    atualizarPosicoes(lista);
}

void modificarOferta(ListaLigada *lista, int pos, double valor, int qtd) {
    No *atual = lista->inicio;
    int i;
    
    for (i = 1; i < pos && atual != NULL; i++) {
        atual = atual->prox;
    }
    
    if (atual != NULL) {
        atual->valor = valor;
        atual->quantidade = qtd;
    }
}

void deletarOferta(ListaLigada *lista, int pos) {
    if (lista->inicio == NULL) return;
    
    No *temp;
    
    if (pos == 1) {
        temp = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(temp);
        
    } 
    
    else {
       
        No *anterior = lista->inicio;
        int i;
        
        for (i = 1; i < pos - 1 && anterior->prox != NULL; i++) {
            anterior = anterior->prox;
        }
        
        if (anterior->prox != NULL) {
            temp = anterior->prox;
            anterior->prox = temp->prox;
            free(temp);
        }
    }
    
    lista->tamanho--;
    atualizarPosicoes(lista);
}

void imprimirLista(ListaLigada *lista) {
    No *atual = lista->inicio;
    
    while (atual != NULL) {
        printf("%d,%.2f,%d\n", atual->posicao, atual->valor, atual->quantidade);
        atual = atual->prox;
    }
}

void liberarLista(ListaLigada *lista) {
    No *atual = lista->inicio;
    
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int main() {
    ListaLigada lista;
    int numNotificacoes, i;
    int posicao, acao, quantidade;
    double valor;
    
    inicializarLista(&lista);
    
    scanf("%d", &numNotificacoes);
    
    for (i = 0; i < numNotificacoes; i++) {
        scanf("%d,%d,%lf,%d", &posicao, &acao, &valor, &quantidade);
        
        if (acao == 0) {
            inserirOferta(&lista, posicao, valor, quantidade);
        }
        
        else if (acao == 1) {
            modificarOferta(&lista, posicao, valor, quantidade);
        }
        
        else if (acao == 2) {
            deletarOferta(&lista, posicao);
        }
    }
    
    printf("\nOutput: \n");
    imprimirLista(&lista);
    
    liberarLista(&lista);
    
    return 0;
}