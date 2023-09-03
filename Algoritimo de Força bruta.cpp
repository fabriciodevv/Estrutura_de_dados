#include <iostream>
#include <algorithm>

using namespace std;

// Defini��o da estrutura de um item
struct Item {
    int valor;
    int peso;
};

// Fun��o para calcular o valor total de uma combina��o de itens
int valor_combinacao(Item itens[], int combinacao[], int n) {
    int valor = 0;
    for (int i = 0; i < n; i++) {
        if (combinacao[i] == 1) {
            valor += itens[i].valor;
        }
    }
    return valor;
}

// Fun��o para calcular o peso total de uma combina��o de itens
int peso_combinacao(Item itens[], int combinacao[], int n) {
    int peso = 0;
    for (int i = 0; i < n; i++) {
        if (combinacao[i] == 1) {
            peso += itens[i].peso;
        }
    }
    return peso;
}

// Fun��o para resolver o problema da mochila usando o algoritmo de for�a bruta
void forca_bruta_mochila(Item itens[], int n, int capacidade_mochila) {
    int melhor_combinacao[n];
    int melhor_valor = 0;

    // Gerar todas as poss�veis combina��es de itens
    for (int i = 0; i < (1 << n); i++) {
        int combinacao[n];
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                combinacao[j] = 1;
            } else {
                combinacao[j] = 0;
            }
        }

        // Verificar se a combina��o � v�lida e se � a melhor at� o momento
        int valor = valor_combinacao(itens, combinacao, n);
        int peso = peso_combinacao(itens, combinacao, n);
        if (peso <= capacidade_mochila && valor > melhor_valor) {
            for (int j = 0; j < n; j++) {
                melhor_combinacao[j] = combinacao[j];
            }
            melhor_valor = valor;
        }
    }

    // Imprimir os itens selecionados na mochila
    cout << "\n Caixas colocada na mochila:" << endl;
    for (int i = 0; i < n; i++) {
        if (melhor_combinacao[i] == 1) {
            cout << "Caixa " << i << ": valor = " << itens[i].valor << ", peso = " << itens[i].peso << endl;
        }
    }
}

int main() {
    
    int x =0;
    const int n = 20;   
    cout <<"------------------------------------------\n";
    cout <<"ALGORITIMO UTILIZADO: FORCA BRUTA\n";
    cout <<"------------------------------------------\n";
	cout << "Digite a capacidade da mochila: ";
	cin >> x;
    Item itens[n] = {{7, 200}, {9, 250}, {4, 450}, {12, 100}, {10, 300}, {2, 200}, {13, 400}, {1, 100}, {7, 50}, {8, 350}, 
	{11, 250}, {13, 450}, {6, 50}, {4, 400}, {10, 100}, {1, 350}, {6, 200}, {2, 300}, {7, 200}, {8, 150}};

    int capacidade_mochila = x;

    forca_bruta_mochila(itens, n, capacidade_mochila);

    return 0;
}

