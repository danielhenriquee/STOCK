# STOCK
Project for Algorithms and Programming II - 2023/2

A C++ console-based system for managing a dynamic list of products, supporting insertion, removal, search, and file persistence.  
Developed with dynamic memory allocation, pointers, recursion, and modular programming.

**Project Structure**

├─ main.cpp // Main program logic and menu loop

├─ stock.h // Product list structures and operations

├─ menu.h // Menu display and UI animations

└─ list.txt // Persistent storage for product data

**Features**
- Dynamic insertion of products at the beginning of the list
- Removal of products by code
- Real-time listing of all products with menu always displayed
- Search function to find a product's price by its code
- Persistent storage: product list saved to 'list.txt' and loaded on startup
- Recursive operations for list processing
- Dynamic memory allocation using pointers
- No global variables: clean modular design
- ANSI escape codes for colored output
- Startup and exit "animations"

**How to Compile and Run**
- g++ main.cpp -o stock
- ./stock

**Notes**
- Ensure that list.txt exists in the same directory as the executable. If it doesn’t exist, the program will create an empty file automatically.
- Tested on Linux and Windows (via MinGW/G++).
