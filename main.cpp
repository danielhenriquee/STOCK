// Daniel Henrique da Silva, Samuel Alfonso Werner Stuhlert, Victor Menezes Ferreira

/*
- Armazenar um número indeterminado de produtos (a inserção no início da list
- Permitir a eliminação de qualquer produto da list, identificando-o pelo código
- A relação dos produtos deve estar sempre presente na tela, mostrando todos os produtos da list (junto com o menu de opções)
- Opção de consulta, onde o usuário informa um código e o sistema informa o preço do produto ou 0 (zero) caso o produto não exista
- Armazenar a list completa em fileuivo (texto) que deve ser recuperado toda vez que o programa for iniciado

Utilize uma biblioteca para as operações da list e Structs da list.
- Utilize Recursividade.
- Utilize alocação dinâmica de memória e ponteiros.
- Utilize sub-rotinas.
- Não utilize variáveis globais.
*/

#include <iostream>
#include <fstream>
#include <chrono> 
#include <thread>
#include "stock.h"
#include "menu.h"

using namespace std;
#define reset_color "\033[0m"
#define blue_color "\033[0;34m"
#define green_color "\033[38;5;150m"

int main() {
    Stock_list list;
    int option = 0;
    
    fstream file;
    file.open("list.txt", fstream::out|fstream::in); 
    if (!file.is_open()) {
        cout << "Error, could not open the file\n";
        return 1;
    }
    
    Stock_boot(list);
    Stock_load(list, file);
  
    animation01(); 
    this_thread::sleep_for(chrono::seconds(3));
    clear();
    animation02();
    this_thread::sleep_for(chrono::seconds(3));
    clear();
  
    do {
      produto *prod = new produto;
      int cod;
  
      clear();
      imprime_menu();
      imprime_list(list);
  
      cout << "Digite a opção desejada: ";
      cin >> option;
      switch (option) {
      case 1:
        clear();
        imprime_list(list);
        criar_produto(list, prod);
        insere_elemento_list(list, prod);
        break;
  
      case 2:
        clear();
        imprime_list(list);
  
        cout << "Digite o código do produto: ";
        cin >> cod;
        consultar_produto(list, cod);
        voltarMenu();
        break;
  
      case 3:
        clear();
        imprime_list(list);
  
        cout << "Digite o código do produto: ";
        cin >> cod;
        while (cod <= 0 ) {
          cout << "Código inválido. Digite um código > 0!\n";
          cin >> cod;
        }
        remover_produto(list, cod);
        voltarMenu();
        break;
      }
    } while (option != 4); 
  
    gravar_list(list, file);
    limpar_list(list);
  
    clear();
    encerraPrograma();
    this_thread::sleep_for(chrono::seconds(3)); // Exibe a tela de saida por 3 segundos
    clear();
    pcDesligado();
    this_thread::sleep_for(chrono::seconds(3)); // Exibe o pc desligado por 3 segundos
    clear();
  
    file.close(); // Fecha o fileuivo
    return 0;
}
