#ifndef HASHTABLE_H
#define HASHTABLE_H

#define M 1024 // O número primo após 1024 é 1031. Mas para simplificação, usaremos 1024.

typedef struct {
    char plate[8]; // Para armazenar placas no formato “CCCNNNN”.
    int isOccupied; // Para saber se a posição está ocupada.
} HashItem;

typedef struct {
    HashItem items[M];
    int num_items;
} HashTable;

// Inicializa a hashtable.
void initHashTable(HashTable* table);

// Insere uma placa na hashtable.
int insertPlate(HashTable* table, const char* plate);

// Procura uma placa na hashtable. Retorna 1 se encontrar, 0 caso contrário.
int searchPlate(const HashTable* table, const char* plate);

// Remove uma placa da hashtable.
int removePlate(HashTable* table, const char* plate);

// Função hash.
int hashFunction(const char* plate, int attempt);

#endif
