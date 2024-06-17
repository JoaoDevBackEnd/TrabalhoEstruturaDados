#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int cd_produto;
    char ds_produto[50];
    char ds_unid_med[3];
    char dt_validade[11];
    float qt_produto;
    float vl_CustoMedio;
    float vl_total;
} reg_produto;

typedef struct TipoItem *TipoApontador;

typedef struct TipoItem {
    reg_produto conteudo;
    TipoApontador proximo;
} TipoItem;

typedef struct {
    TipoApontador Primeiro;
    TipoApontador Ultimo;
} TipoLista;

void inicializarLista(TipoLista *lista);
void inserirProduto(TipoLista *lista, reg_produto produto);
void listarProdutos(TipoLista *lista);
void salvarListaEmArquivo(TipoLista *lista, const char *nomeArquivo);
void carregarListaDeArquivo(TipoLista *lista, const char *nomeArquivo);
#endif