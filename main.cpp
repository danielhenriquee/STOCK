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
  
        cout << "Type an option: ";
        cin >> option;
        switch (option) {
        case 1:
            clear();
            Stock_print(list);
            Stock_create(list, prod);
            Stock_insert(list, prod);
            break;
    
        case 2:
            clear();
            Stock_print(list);
      
            cout << "Type product code: ";
            cin >> cod;
            Stock_search(list, cod);
            back2menu();
            break;
  
        case 3:
            clear();
            Stock_print(list);
      
            cout << "Type product code: ";
            cin >> cod;
            while (cod <= 0 ) {
              cout << "Invalid code, must be > 0!\n";
              cin >> cod;
            }
            Stock_remove(list, cod);
            back2menu();
            break;
        }
    } while (option != 4); 
  
    Stock_save(list, file);
    Stock_destroy(list);
  
    clear();
    animation03();
    this_thread::sleep_for(chrono::seconds(3));
    clear();
    animation01();
    this_thread::sleep_for(chrono::seconds(3));
    clear();
  
    file.close();
    return 0;
}
