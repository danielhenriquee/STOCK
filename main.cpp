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
    
    fstream file("list.txt", ios::in);
    if (!file.is_open()) {
        ofstream create("list.txt");
        create.close();
        file.open("list.txt", ios::in);
    }
    
    Stock_boot(list);
    Stock_load(list, file);
    file.close();
    
    animation01(); 
    this_thread::sleep_for(chrono::seconds(3));
    clear();
    animation02();
    this_thread::sleep_for(chrono::seconds(3));
    clear();
  
    do {
        int cod;
        clear();
        imprime_menu();
        imprime_list(list);
  
        cin >> option;
        switch (option) {
        case 1:
            Stock_product *prod = new Stock_product;
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
            do {
                cout << "Type product code (> 0): ";
                cin >> cod;
            } while (cod <= 0);
            Stock_remove(list, cod);
            back2menu();
            break;

        case 4:
            break;
            
        default: 
            cout << "Invalid option!\n";
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
    return 0;
}
