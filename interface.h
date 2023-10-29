#ifndef HASHTABLE_H
#define HASHTABLE_H

#define M 1024 // O n�mero primo ap�s 1024 � 1031. Mas para simplifica��o, usaremos 1024.

typedef struct {
    char plate[8]; // Para armazenar placas no formato �CCCNNNN�.
    int isOccupied; // Para saber se a posi��o est� ocupada.
} HashItem;

typedef struct {
    HashItem items[M];
    int num_items;
} HashTable;

// Inicializa a hashtable.
void initHashTable(HashTable* table);

// Insere uma placa na hashtable.
int insertPlate(HashTable* table, const char* plate);

// Procura uma placa na hashtable. Retorna 1 se encontrar, 0 caso contr�rio.
int searchPlate(const HashTable* table, const char* plate);

// Remove uma placa da hashtable.
int removePlate(HashTable* table, const char* plate);

// Fun��o hash.
int hashFunction(const char* plate, int attempt);

#endif
