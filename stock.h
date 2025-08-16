#include <iostream>
#include <fstream>
using namespace std;

#define reset_color "\033[0m"
#define blue_color "\033[0;34m"
#define green_color "\033[38;5;150m"

// Stock_product struct
struct Stock_product {
    int code;
    char name[30];
    float price;
    Stock_product *next;
};

// List struct
struct Stock_list {
    Stock_product *start;
};

// Boot list
bool Stock_boot(Stock_list &list) {
    list.start = nullptr;
    return true;
}

// Print all list products
bool Stock_print(const Stock_list &list) {
    Stock_product *p = list.start;
    cout << blue_color << "╔─────────────────────────────────────╗" << endl;
    cout << "│      " << reset_color << "  - list de Stock_products -" << blue_color << "        │" << endl;
    cout << "╚─────────────────────────────────────╝" << endl << reset_color;

    while (p != nullptr) {
        cout << green_color << "  Name: " << reset_color << p->name << endl;
        cout << green_color << "  Price: " << reset_color << "US$ " << p->price << endl;
        cout << green_color << "  Code: " << reset_color << p->code << endl;
        p = p->next;
        cout << blue_color << "-─────────────────────────────────────-" << reset_color  <<  endl;
    }

    return true;
}

// Recursive search to find elements position in the list
Stock_product* Stock_recursiveSearch(Stock_product *p, int cod) {
    if (p == nullptr || p->code == cod) { // If found, return product pointer, else, return nullptr
        return p; 
    }
    return Stock_recursiveSearch(p->next, cod); // Call function to next list element
}

// Create product
void Stock_create(Stock_list &list, Stock_product *prod) {
    cout << green_color << "Type the product name:\n" << reset_color;
    cin.ignore();
    cin.getline(prod->name, 30);

    do {
        cout << green_color << "Type the product code:\n" << reset_color;
        cin >> prod->code;

        if (prod->code <= 0) {
            cout << "Invalid code, must be > 0!\n";
        } 
        else if (Stock_recursiveSearch(list.start, prod->code) != nullptr) {
            cout << "This code already exists, try again.\n";
        } 
        else {
            break;
        }
    } while (true);

    do {
        cout << green_color << "Type the product price:\n" << reset_color;
        cin >> prod->price;

        if (prod->price <= 0) {
            cout << "Invalid price, must be > 0!\n";
        } else {
            break;
        }
    } while (true);
}

// Insert product in the list
bool Stock_insert(Stock_list &list, Stock_product *prod) {
    prod->next = list.start; 
    list.start = prod;
    return true;
}

// Remove product in the list
bool Stock_remove(Stock_list &list, int cod) {
    Stock_product *p = list.start;
    Stock_product *prev = nullptr;
    while (p != nullptr) { // Navigate until the last element
        if (cod == p->code) {
            if (prev == nullptr) { // If true, it is the first element
                list.start = p->next; 
            } else {
                prev->next = p->next;
            }
            delete p;
            return true;
        }
        prev = p;
        p = p->next;
    }
    cout << "There is no product with this code!\n";
    return false;
}

//  Search product
void Stock_search(const Stock_list &list, int cod) {
    Stock_product *p = Stock_recursiveSearch(list.start, cod);

    if (p != nullptr) {
        cout << green_color << "Product found!\n" << reset_color;
        cout << "  Name: " << p->name << endl;
        cout << "  Price: US$ " << p->price << endl;
        cout << "  Code: " << p->code << endl;
    } else {
        cout << "No product found with this code.\n";
    }
}

// Load list from external file
void Stock_load (Stock_list &list, fstream &file) {
    Stock_product fileProd;
    char splitter;
  
    while (file >> fileProd.code) {
        file.ignore(1); // Ignore ,
        file.getline(fileProd.name, 30, ',');
        file >> fileProd.price;
    
        Stock_product *e = new Stock_product;
        *e = fileProd;
        Stock_insert(list, e);
    }
}

// Save list on external file
void Stock_save(const Stock_list &list) {
    ofstream file("list.txt", ios::out | ios::trunc);
    Stock_product *current = list.start;
    while (current != nullptr) {
        file << current->code << "," << current->name << "," << current->price << endl;
        current = current->next;
    }
}


// Destroy list
void Stock_destroy(Stock_list &list) {
    Stock_product *current = list.start;
    while (current != nullptr) {
        Stock_product *next = current->next;
        delete current;
        current = next;
    }
    list.start = nullptr;
}
