#ifndef CABESALHO_H
#define CABESALHO_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "lista.h"
void gotoxy(int x, int y);
void tela_Principal();
void menu_Principal();
void menu_Produto();
void consultar_Produtos();
void menu_cadastro_Consulta();
void menu_consultar_Produtos();
void menu_movimentacao_Estoque();
void cadastrar_movimentacao_Produto();
void menu_consultar_movimentacao();
void remover_ProdutoLista();

extern TipoLista lista_de_produtos;
void cadastrarProdutoFinalLista(reg_produto produto);
void cadastrarProdutoInicioLista(reg_produto produto);
void cadastrarProdutoMeioLista(reg_produto produto,int posicao);
void removerProdutoFinalLista();
void removerProdutoNaPosicao(int cd_produto);
void removerProdutoNoInicioFila();
TipoItem* encontrarProduto(int cd_produto);  
void alterarProduto(int cd_produto);  


typedef void (*TelaFunc)();
void navegaPara(TelaFunc novaTela);

struct GerenciadorDeTelas {
    TelaFunc telaAtual;
};

extern struct GerenciadorDeTelas gerenciador;


#endif
