#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Structure for a symbol table entry
typedef struct Symbol {
    char name[50];
    char type[20];
    int address;
    struct Symbol* next;
} Symbol;

// Hash table
typedef struct {
    Symbol* table[TABLE_SIZE];
} SymbolTable;

// Hash function
int hashFunction(char* name) {
    int sum = 0;
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum % TABLE_SIZE;
}

// Insert symbol into the table
void insert(SymbolTable* symTable, char* name, char* type, int address) {
    int index = hashFunction(name);
    Symbol* newSymbol = (Symbol*)malloc(sizeof(Symbol));
    strcpy(newSymbol->name, name);
    strcpy(newSymbol->type, type);
    newSymbol->address = address;
    newSymbol->next = symTable->table[index];
    symTable->table[index] = newSymbol;
    printf("Inserted: %s, Type: %s, Address: %d\n", name, type, address);
}

// Search for a symbol
Symbol* search(SymbolTable* symTable, char* name) {
    int index = hashFunction(name);
    Symbol* temp = symTable->table[index];
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Display the symbol table
void display(SymbolTable* symTable) {
    printf("Symbol Table:\n");
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        Symbol* temp = symTable->table[i];
        if (temp) {
            printf("Index %d:\n", i);
            while (temp) {
                printf("  Name: %s, Type: %s, Address: %d\n", temp->name, temp->type, temp->address);
                temp = temp->next;
            }
        }
    }
}

// Main function
int main() {
    SymbolTable symTable = {0};
    
    insert(&symTable, "x", "int", 100);
    insert(&symTable, "y", "float", 104);
    insert(&symTable, "sum", "function", 200);
    
    display(&symTable);
    
    Symbol* found = search(&symTable, "y");
    if (found) {
        printf("Found: %s, Type: %s, Address: %d\n", found->name, found->type, found->address);
    } else {
        printf("Symbol not found\n");
    }
    
    return 0;
}
