
#include "cabesalho.h"
#include "lista.h" // Se necessário, inclua outros cabeçalhos aqui
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int static x=0;
extern TipoLista lista_de_produtos;
struct GerenciadorDeTelas gerenciador;
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
TipoItem* encontrarProduto(int cd_produto) {
    TipoItem *atual = lista_de_produtos.Primeiro;
    while (atual != NULL) {
        if (atual->conteudo.cd_produto == cd_produto) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL; 
}
void alterarProduto(int cd_produto) {
   
    //printf("Quantidade: ");
   // scanf("%d", &produto->conteudo.qt_produto);
   // gotoxy(9, 27);
    //printf("Custo Medio: ");
    //scanf("%f", &produto->conteudo.vl_CustoMedio);
    //produto->conteudo.vl_total = produto->conteudo.qt_produto * produto->conteudo.vl_CustoMedio;
}
void RemoverultimoProdutoLista(){
    TipoItem *ultimoProduto = lista_de_produtos.Ultimo;
    if (ultimoProduto != NULL) {
        // Exibe os dados do último produto
        gotoxy(44, 7);
        printf("CD: %d", ultimoProduto->conteudo.cd_produto);
        gotoxy(48, 9);
        printf("Descrição: %s", ultimoProduto->conteudo.ds_produto);
        gotoxy(45, 11);
        printf("Unidade de Medida: %s", ultimoProduto->conteudo.ds_unid_med);
        gotoxy(43, 13);
        printf("Data de Validade: %s", ultimoProduto->conteudo.dt_validade);
        gotoxy(29, 15);
        printf("Quantidade: %d", ultimoProduto->conteudo.qt_produto);
        gotoxy(45, 15);
        printf("Custo Médio: %.2f", ultimoProduto->conteudo.vl_CustoMedio);
        gotoxy(63, 15);
        printf("Valor Total: %.2f", ultimoProduto->conteudo.vl_total);
}
}
void tela_Principal() {
    
    int t;
    system("color 0F");
    system("cls");
    gotoxy(1, 1);
    printf("+----------------------------------------------------------------------------------------------------+");
    gotoxy(1, 2);
    printf("| JOAO VICTOR DE SOUZA");
    gotoxy(35, 3);
    printf("ERP - RODNEY's MARCENARIA");
    gotoxy(80, 2);
    printf("Estrutura de Dados");
    gotoxy(102, 2);
    printf("|");
    gotoxy(1, 3);
    printf("|");
    gotoxy(40, 2);
    printf("  UNICV");
    gotoxy(102, 3);
    printf("|");
    gotoxy(102, 4);
    printf("|");
    gotoxy(1, 4);
    printf("|");
    gotoxy(1, 5);
    printf("+----------------------------------------------------------------------------------------------------+");
    for (t = 5; t < 28; t++) {
        gotoxy(1, t);
        printf("|");
        gotoxy(102, t);
        printf("|");
    }
    gotoxy(1, 26);
    printf("+----------------------------------------------------------------------------------------------------+");
    gotoxy(2, 27);
    printf("MSG.:");
    gotoxy(1, 28);
    printf("|");
    gotoxy(102, 28);
    printf("|");
    gotoxy(1, 29);
    printf("+----------------------------------------------------------------------------------------------------+");
}

void limpaTelaInterna() {
    for (int t = 6; t < 26; t++) {
        gotoxy(2, t);
        printf("                                                                                                    ");
    }
}

void menu_Principal() { 
    limpaTelaInterna();  
    gotoxy(40, 4);
    printf("MENU PRINCIPAL");
    gotoxy(40, 10);
    printf("1  - Menu Cadastro de Produto");
    gotoxy(40, 12);
    printf("2  - Menu de Movimentacao de Estoque");
    gotoxy(40, 14);
    printf("3  - Finalizar Programa");
  
    int choice;
    gotoxy(9, 27);
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
        listarProdutos(&lista_de_produtos);
        case 1:
            navegaPara(menu_Produto);
            break;
        case 2:
            navegaPara(menu_movimentacao_Estoque);
            break;
        case 3:
            sairPrograma();
            break;
        default:
            printf("Opcao invalida. Por favor, escolha uma opcao valida.\n");
            break;
    }
}

void menu_Produto() {
    limpaTelaInterna();
    gotoxy(40, 4);
    printf("MENU CADASTRO DE PRODUTO");
    gotoxy(32, 7);
    printf("1  - CADASTRAR PRODUTO NO FINAL DA LISTA");
    gotoxy(32, 9);
    printf("2  - CADASTRAR PRODUTO NO INÍCIO DA LISTA");
    gotoxy(32, 11);
    printf("3  - CADASTRAR PRODUTO EM UMA POSICAO DA LISTA");
    gotoxy(32, 13);
    printf("4  - REMOVER PRODUTO NO FINAL DA LISTA");
    gotoxy(32, 15);
    printf("5  - REMOVER PRODUTO NA POSICAO DA LISTA");
    gotoxy(32, 17);
    printf("6  - REMOVER PRODUTO NO INICIO DA LISTA");
    gotoxy(32, 19);
    printf("7  - CONSULTAR TODOS PRODUTOS");
    gotoxy(32, 21);
    printf("8  - ALTERA DADOS DO PRODUTO");
    gotoxy(32, 25);
    printf("9  - RETORNAR AO MENU PRINCIPAL");

    int choice;
    gotoxy(9, 27);
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: case 2: case 3:
            x=choice;
            navegaPara(menu_cadastro_Consulta);
            break;
        case 4: case 5: case 6: case 8:
            x=choice;
            navegaPara(remover_ProdutoLista);
            break;
        case 7:
            navegaPara(menu_consultar_Produtos);
            break;
        case 9:
            navegaPara(menu_Principal);
            break;
        default:
            navegaPara(menu_Produto);
            break;
    }
}

void consultar_Produtos() {
    limpaTelaInterna();
    gotoxy(40, 4);
    printf("SUB MENU DE CONSULTA PRODUTO");
    gotoxy(32, 7);
    printf("1  - CONSULTAR FICHARIO DO PRODUTO GERAL");
    gotoxy(32, 9);
    printf("2  - CONSULTAR EM ORDEM DE CODIGO");
    gotoxy(32, 11);
    printf("3  - CONSULTAR EM ORDEM ALFÁBETICA");
    gotoxy(32, 13);
    printf("4  - CONSULTAR O CODIGO ESPECIFICO");
    gotoxy(32, 25);
    printf("9  - RETORNAR AO MENU");

    int choice;
    gotoxy(9, 27);
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: case 2: case 3: case 4:
            navegaPara(menu_cadastro_Consulta);
            break;
        case 9:
            navegaPara(menu_Produto);
            break;
        default:
            navegaPara(consultar_Produtos);
            break;
    }
}
void remover_ProdutoLista() {
    limpaTelaInterna();
    gotoxy(40, 4);
    printf("REMOVER PRODUTO");
    gotoxy(20, 7);
    printf("CODIGO DO PRODUTO:....: ");
    gotoxy(18, 9);
    printf("1- DESCRICAO DO PRODUTO:....: ");
    gotoxy(18, 11);
    printf("2- UNIDADE DE MEDIDA:....: ");
    gotoxy(18, 13);
    printf("3- DATA DE VALIDADE:....: ");
    gotoxy(24, 15);
    printf("+-----------------------------------------------+");
    gotoxy(24, 16);
    printf("|");
    gotoxy(72, 16);
    printf("|");
    gotoxy(40, 16);
    printf("SALDO DO ESTOQUE");
    gotoxy(24, 17);
    printf("+-----------------------------------------------+");
    gotoxy(24, 18);
    printf("|  QUANTIDADE  |  CUSTO MEDIO  |   VALOR TOTAL  |");
    gotoxy(24, 19);
    printf("+-----------------------------------------------+");
    gotoxy(24, 20);
    printf("|              |              |                 |");
    gotoxy(24, 21);
    printf("+-----------------------------------------------+");

    gotoxy(32, 23);
    printf("9  - RETORNAR AO MENU");

    if (x == 4) {
        TipoItem *ultimoProduto = lista_de_produtos.Ultimo;
        if (ultimoProduto != NULL) {
            // Exibe os dados do último produto
            gotoxy(44, 7);
            printf("%d", ultimoProduto->conteudo.cd_produto);
            gotoxy(48, 9);
            printf("%s", ultimoProduto->conteudo.ds_produto);
            gotoxy(45, 11);
            printf("%s", ultimoProduto->conteudo.ds_unid_med);
            gotoxy(43, 13);
            printf("%s", ultimoProduto->conteudo.dt_validade);
            gotoxy(29, 20);
            printf("%d", ultimoProduto->conteudo.qt_produto);
            gotoxy(45, 20);
            printf("%.2f", ultimoProduto->conteudo.vl_CustoMedio);
            gotoxy(63, 20);
            printf("%.2f", ultimoProduto->conteudo.vl_total);
            
            char escolha;
            gotoxy(32, 23);
            printf("DESEJA REMOVER ESSE PRODUTO? S/N ");
            scanf(" %c", &escolha);
            if (escolha == 'S' || escolha == 's') {
               removerProdutoFinalLista();
            } else if(escolha=='N' || escolha=='n'){
                gotoxy(32, 25);
                printf("Produto não removido.\n");
            }else{
                gotoxy(32, 25);
                printf("OPCAO INVALIDA\n");
                getchar();
                return;
            }
        } else {
            gotoxy(32, 23);
            printf("Lista de produtos vazia.\n");
        }
    }
    if(x==5){
        int cd_produto;
        gotoxy(9, 27);
        printf("DIGITE O CD DO PRODUTO A SER REMOVIDO: ");
        scanf("%d", &cd_produto);

        encontrarProduto(cd_produto);

        char escolha;
        gotoxy(32, 25);
        printf("DESEJA REMOVER ESSE PRODUTO? S/N ");
        scanf(" %c", &escolha);
        if (escolha == 'S' || escolha == 's') {
            removerProdutoNaPosicao(cd_produto);
        } else {
            gotoxy(32, 27);
            printf("Produto não removido.\n");
        }
    }
    if(x==6){
            TipoItem *primeiroProduto = lista_de_produtos.Primeiro;
            if (primeiroProduto != NULL) {
                // Exibe os dados do último produto
                gotoxy(44, 7);
                printf("%d", primeiroProduto->conteudo.cd_produto);
                gotoxy(48, 9);
                printf("%s", primeiroProduto->conteudo.ds_produto);
                gotoxy(45, 11);
                printf("%s", primeiroProduto->conteudo.ds_unid_med);
                gotoxy(43, 13);
                printf("%s", primeiroProduto->conteudo.dt_validade);
                gotoxy(29, 20);
                printf("%d", primeiroProduto->conteudo.qt_produto);
                gotoxy(45, 20);
                printf("%.2f", primeiroProduto->conteudo.vl_CustoMedio);
                gotoxy(63, 20);
                printf("%.2f", primeiroProduto->conteudo.vl_total);
        }
        char escolha;
        gotoxy(32, 25);
        printf("DESEJA REMOVER ESSE PRODUTO? S/N ");
        scanf(" %c", &escolha);
        if (escolha == 'S' || escolha == 's') {
            removerProdutoNoInicioFila();
        } else {
            gotoxy(32, 27);
            printf("Produto não removido.\n");
        }    
    }
    if(x==8){
        gotoxy(40, 4);
        printf("ALTERAR DADOS DO PRODUTO");
        int cd_produto;
        gotoxy(9, 27);
        printf("DIGITE O CD DO PRODUTO PARA SER ALTERADO: ");
        scanf("%d", &cd_produto);
        TipoItem *produto = encontrarProduto(cd_produto);
            if (produto == NULL) {
                gotoxy(9, 27);
                printf("Produto com CD %d não encontrado.\n", cd_produto);
                return;
            }

        // Exibe os dados atuais do produto
        gotoxy(44, 7);
        printf("%d", produto->conteudo.cd_produto);
        gotoxy(48, 9);
        printf("%s", produto->conteudo.ds_produto);
        gotoxy(45, 11);
        printf("%s", produto->conteudo.ds_unid_med);
        gotoxy(43, 13);
        printf("%s", produto->conteudo.dt_validade);
        gotoxy(29, 20);
        printf("%d", produto->conteudo.qt_produto);
        gotoxy(45, 20);
        printf("%.2f", produto->conteudo.vl_CustoMedio);
        gotoxy(63, 20);
        printf("%.2f", produto->conteudo.vl_total);

        // Pedir novos valores ao usuário
        gotoxy(48, 9);
        printf("                              ");
        gotoxy(48, 9);
        scanf(" %[^\n]s", produto->conteudo.ds_produto);
        gotoxy(45, 11);
        printf("                              ");
        gotoxy(45, 11);
        scanf(" %[^\n]s", produto->conteudo.ds_unid_med);
        gotoxy(43, 13);
        printf("                              ");
        gotoxy(43, 13);
        scanf(" %[^\n]s", produto->conteudo.dt_validade);
    }


    int choice;
    gotoxy(9, 27);
    printf("DIGITE opcao: ");
    scanf("%d", &choice);

    switch (choice) {
        case 9:
            navegaPara(menu_Produto);
            break;
        default:
            gotoxy(9, 27);
            printf("OPCAO INVALIDA\n");
            break;
    }
}

void menu_cadastro_Consulta() {
    limpaTelaInterna();
    gotoxy(40, 4);
    printf("CADASTRO / CONSULTA PRODUTO");
    gotoxy(20, 7);
    printf("CODIGO DO PRODUTO:....: ");
    gotoxy(18, 9);
    printf("1- DESCRICAO DO PRODUTO:....: ");
    gotoxy(18, 11);
    printf("2- UNIDADE DE MEDIDA:....: ");
    gotoxy(18, 13);
    printf("3- DATA DE VALIDADE:....: ");
    gotoxy(24, 15);
    printf("+-----------------------------------------------+");
    gotoxy(24, 16);
    printf("|");
    gotoxy(72, 16);
    printf("|");
    gotoxy(40, 16);
    printf("SALDO DO ESTOQUE");
    gotoxy(24, 17);
    printf("+-----------------------------------------------+");
    gotoxy(24, 18);
    printf("|  QUANTIDADE  |  CUSTO MEDIO  |   VALOR TOTAL  |");
    gotoxy(24, 19);
    printf("+-----------------------------------------------+");
    gotoxy(24, 20);
    printf("|              |              |                 |");
    gotoxy(24, 21);
    printf("+-----------------------------------------------+");

    gotoxy(32, 23);
    printf("9  - RETORNAR AO MENU");

    reg_produto novo_produto;
    if (x == 1 || x == 2 || x==3 ) { 
        gotoxy(44, 7);
        scanf("%d", &novo_produto.cd_produto); 
        gotoxy(48, 9);
        scanf(" %[^\n]", novo_produto.ds_produto); 
        gotoxy(45, 11);
        scanf(" %[^\n]", novo_produto.ds_unid_med); 
        gotoxy(43, 13);
        scanf(" %[^\n]", novo_produto.dt_validade); 
        novo_produto.qt_produto = 0;
        novo_produto.vl_CustoMedio = 0; 
        novo_produto.vl_total = 0; 
        if (x == 1) {
            cadastrarProdutoFinalLista(novo_produto);
        } else if (x == 2) {
            cadastrarProdutoInicioLista(novo_produto);
        }
        else if(x==3){
            int cd;
            gotoxy(9, 27);
            printf("DIGITE O CD PRODUTO PARA SER INSERIDO ACIMA");
            scanf("%d", &cd);
            if(cd==1){
                cadastrarProdutoInicioLista(novo_produto);
            }else{
                 cadastrarProdutoMeioLista(novo_produto,cd);
            }
        }
       
    }
    int choice;
    gotoxy(9, 27);
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
        case 9:
            navegaPara(menu_Produto);
            break;
        default:
            navegaPara(menu_consultar_Produtos);
            break;
    }
}

void menu_consultar_Produtos() {
    limpaTelaInterna();
    gotoxy(40, 4);
    printf("CONSULTAR PRODUTOS");
    gotoxy(2, 6);
    printf("CD DESCRICAO DO PRODUTO             Unid    Data Valid     Quantidade     Valor.Unit    Valor Total ");
    gotoxy(2, 7);
    printf("== ============================== ======= ============= =============== =============== =========== ");

    gotoxy(32, 25);
    printf("9  - RETORNAR AO MENU");
    listarProdutos(&lista_de_produtos);
    int choice;
    gotoxy(9, 27);
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
        case 9:
            navegaPara(menu_Produto);
            break;
        default:
            navegaPara(menu_consultar_Produtos);
            break;
    }
}

void menu_movimentacao_Estoque() {
    limpaTelaInterna();
    gotoxy(40, 4);
    printf("MENU MOVIMENTACAO DE ESTOQUE");
    gotoxy(40, 10);
    printf("1  - CADASTRAR MOVIMENTACAO DE ESTOQUE");
    gotoxy(40, 12);
    printf("2  - LISTA DE MOVIMENTACAO DE ESTOQUE");
    gotoxy(40, 14);
    printf("3  - RETORNAR AO MENU PRINCIPAL");

    int choice;
    gotoxy(9, 27);
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            navegaPara(cadastrar_movimentacao_Produto);
            break;
        case 2:
            navegaPara(menu_consultar_movimentacao);
            break;
        case 3:
            navegaPara(menu_Principal);
            break;
        default:
            navegaPara(menu_movimentacao_Estoque);
            break;
    }
}

void cadastrar_movimentacao_Produto() {
    limpaTelaInterna();
    gotoxy(40, 4);
    printf("CADASTRAR NOVA MOVIMENTACAO");
    gotoxy(20, 8);
    printf("CODIGO DO PRODUTO.....:");
    gotoxy(20, 10);
    printf("DATA DA MOVIMENTACAO..:");
    gotoxy(20, 12);
    printf("TIPO DE MOVIMENTACAO..:");
    gotoxy(20, 14);
    printf("QUANTIDADE............:");
    gotoxy(20, 16);
    printf("VALOR UNITARIO........:");
    gotoxy(20, 18);
    printf("VALOR TOTAL...........:");
    gotoxy(24, 21);
    printf("+-----------------------------------------------+");
    gotoxy(24, 22);
    printf("|  QUANTIDADE  |  CUSTO MEDIO  |   VALOR TOTAL  |");
    gotoxy(24, 23);
    printf("+-----------------------------------------------+");
    gotoxy(24, 24);
    printf("|              |              |                 |");
    gotoxy(24, 25);
    printf("+-----------------------------------------------+");

    gotoxy(32, 27);
    printf("9  - RETORNAR AO MENU");

    int choice;
    gotoxy(9, 27);
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
        case 9:
            navegaPara(menu_movimentacao_Estoque);
            break;
        default:
            navegaPara(cadastrar_movimentacao_Produto);
            break;
    }
}

void menu_consultar_movimentacao() {
    limpaTelaInterna();
    gotoxy(40, 4);
    printf("CONSULTAR MOVIMENTACAO");
    gotoxy(2, 6);
    printf("  DATA    TIPO    QUANTIDADE     VL.UNITARIO     VL.TOTAL    QTDE ESTOQUE    CUSTO MEDIO    VL.TOTAL");
    gotoxy(2, 7);
    printf("======= =======  ============  ==============  ===========  ==============  ============   =========");

    gotoxy(32, 25);
    printf("9  - RETORNAR AO MENU");

    int choice;
    gotoxy(9, 27);
    printf("Escolha uma opcao: ");
    scanf("%d", &choice);

    switch (choice) {
        case 9:
            navegaPara(menu_movimentacao_Estoque);
            break;
        default:
            navegaPara(menu_consultar_movimentacao);
            break;
    }
}

void navegaPara(TelaFunc novaTela) {
    gerenciador.telaAtual = novaTela;
    system("cls");
    tela_Principal();
}




