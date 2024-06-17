// listaController.c

#include "cabesalho.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

TipoLista lista_de_produtos; 

void salvarListaEmArquivo(TipoLista *lista, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }

    TipoApontador atual = lista->Primeiro;
    while (atual != NULL) {
        fprintf(arquivo, "%d;%s;%s;%s;%d;%.2f;%.2f\n",
                atual->conteudo.cd_produto,
                atual->conteudo.ds_produto,
                atual->conteudo.ds_unid_med,
                atual->conteudo.dt_validade,
                atual->conteudo.qt_produto,
                atual->conteudo.vl_CustoMedio,
                atual->conteudo.vl_total);
        atual = atual->proximo;
    }

    fclose(arquivo);
}
void carregarListaDeArquivo(TipoLista *lista, const char *nomeArquivo) {
   FILE *arquivo = fopen(nomeArquivo, "r");
    inicializarLista(lista);
    reg_produto produto;

    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%d;%f;%f\n",
                  &produto.cd_produto,
                  produto.ds_produto,
                  produto.ds_unid_med,
                  produto.dt_validade,
                  &produto.qt_produto,
                  &produto.vl_CustoMedio,
                  &produto.vl_total) == 7) { // Verifica se leu os 7 campos com sucesso
        inserirProduto(lista, produto);
    }

    fclose(arquivo);
}
void inicializarLista(TipoLista *lista) {
    lista->Primeiro = NULL;
    lista->Ultimo = NULL;
}

void inserirProduto(TipoLista *lista, reg_produto produto) {
    TipoApontador novoItem = (TipoApontador) malloc(sizeof(TipoItem));
    if (novoItem == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return;
    }

    novoItem->conteudo = produto;
    novoItem->proximo = NULL;

    if (lista->Primeiro == NULL) {
        lista->Primeiro = novoItem;
        lista->Ultimo = novoItem;
    } else {
        // Caso contrário, adicionamos o novo item no final
        lista->Ultimo->proximo = novoItem;
        lista->Ultimo = novoItem;
    }
}

void cadastrarProdutoFinalLista(reg_produto produto) {
    inserirProduto(&lista_de_produtos, produto);
}
void cadastrarProdutoInicioLista(reg_produto produto){
    TipoApontador novoItem = (TipoApontador)malloc(sizeof(TipoItem));
    if (novoItem == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return;
    }

    novoItem->conteudo = produto;
    novoItem->proximo = lista_de_produtos.Primeiro;
    lista_de_produtos.Primeiro = novoItem;

    if (lista_de_produtos.Ultimo == NULL) {
        lista_de_produtos.Ultimo = novoItem;
    }
}
void cadastrarProdutoMeioLista(reg_produto produto,int cd_produto){
    TipoApontador novoItem = (TipoApontador)malloc(sizeof(TipoItem));
    if (novoItem == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return;
    }
    novoItem->conteudo = produto;
    novoItem->proximo = NULL;

    if (lista_de_produtos.Primeiro == NULL) {
        lista_de_produtos.Primeiro = novoItem;
        lista_de_produtos.Ultimo = novoItem;
        return;
    }

    TipoApontador aux = lista_de_produtos.Primeiro;
    // Encontra o nó com o cd_produto especificado pelo usuário
    while (aux != NULL && aux->conteudo.cd_produto != cd_produto) {
        aux = aux->proximo;
    }

    if (aux == NULL) {
        printf("Produto com CD %d não encontrado na lista.\n", cd_produto);
        free(novoItem);
        return;
    }
    novoItem->proximo = aux->proximo;
    aux->proximo = novoItem;
    if (novoItem->proximo == NULL) {
        lista_de_produtos.Ultimo = novoItem;
    }
}
void removerProdutoFinalLista() {
    TipoItem *anterior = NULL;
    TipoItem *atual = lista_de_produtos.Primeiro;

    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) { 
        lista_de_produtos.Primeiro = NULL;
        lista_de_produtos.Ultimo = NULL;
    } else {
        anterior->proximo = NULL;
        lista_de_produtos.Ultimo = anterior;
    }
    free(atual);
    printf("Produto removido com sucesso.\n");
}
void listarProdutos(TipoLista *lista) {
    if (lista == NULL || lista->Primeiro == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    TipoApontador atual = lista->Primeiro;
    int linha = 8; // Linha inicial para exibir os produtos

    while (atual != NULL) {
        gotoxy(2, linha);
        printf("%2d %-30s %-7s %-12s %-15d %-15.2f %.2f",
            atual->conteudo.cd_produto,
            atual->conteudo.ds_produto,
            atual->conteudo.ds_unid_med,
            atual->conteudo.dt_validade,
            atual->conteudo.qt_produto,
            atual->conteudo.vl_CustoMedio,
            atual->conteudo.vl_total
        );
        linha++;
        atual = atual->proximo;
    }
}
void removerProdutoNaPosicao(int cd_produto) {  
    TipoItem *anterior = NULL;
    TipoItem *atual = lista_de_produtos.Primeiro;

    while (atual != NULL && atual->conteudo.cd_produto != cd_produto) {
        anterior = atual;
        atual = atual->proximo;
    }
    //SE O PRODUTO ENCONTRADO ESTVER NO INICIO DA FILA 
    if (anterior == NULL) { 
        lista_de_produtos.Primeiro = atual->proximo;
        if (lista_de_produtos.Primeiro == NULL) {
            lista_de_produtos.Ultimo = NULL; // A lista ficou vazia
        }
    } else {
        anterior->proximo = atual->proximo;
        if (anterior->proximo == NULL) {
            lista_de_produtos.Ultimo = anterior; // O produto removido estava no final
        }
    }
    free(atual);
}
void removerProdutoNoInicioFila(){
    TipoItem *atual = lista_de_produtos.Primeiro;
    lista_de_produtos.Primeiro = atual->proximo;
    // Verifica se o elemento removido era o último da lista
    if (atual == lista_de_produtos.Ultimo) {
        lista_de_produtos.Ultimo = NULL;
    }
    free(atual);
}
