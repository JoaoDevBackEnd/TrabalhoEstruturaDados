#include "cabesalho.h"
#include "lista.h"
#include <stdio.h>

#define bd_RodneysMercenaria "produtos.txt"

TipoLista lista_de_produtos;

void sairPrograma() {
    salvarListaEmArquivo(&lista_de_produtos, bd_RodneysMercenaria);
    exit(0);
}
int main() {
    system("cls");
    tela_Principal();
    gerenciador.telaAtual = menu_Principal;
    carregarListaDeArquivo(&lista_de_produtos, bd_RodneysMercenaria);
    // Loop principal do programa
    while (1) {
        // Chama a tela atual
        gerenciador.telaAtual();
    }

    return 0;
}
