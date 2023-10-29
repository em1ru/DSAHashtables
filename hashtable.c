#include "interface.h"
#include <string.h>

void initHashTable(HashTable* table) {
    table->num_items = 0;
    for (int i = 0; i < M; i++) {
        table->items[i].isOccupied = 0;
        strcpy(table->items[i].plate, "");
    }
}

int hashFunction(const char* plate, int attempt) {
    unsigned int hashValue = 0;
    int i = 0;
    while (plate[i] != '\0') {
        hashValue = (hashValue * 31) + plate[i]; // Multiplica pelo número primo 31 e adiciona o código ASCII do caractere
        i++;
    }
    return (hashValue + attempt) % M;
}


int insertPlate(HashTable* table, const char* plate) {
    int attempt = 0;
    while (attempt < M) {
        int index = hashFunction(plate, attempt);
        if (!table->items[index].isOccupied) {
            strcpy(table->items[index].plate, plate);
            table->items[index].isOccupied = 1;
            table->num_items++;
            return attempt; // Retorna o número de tentativas até a inserção.
        }
        attempt++;
    }
    return attempt; // Hashtable cheia.
}


int searchPlate(const HashTable* table, const char* plate) {
    int attempt = 0;
    while (attempt < M) {
        int index = hashFunction(plate, attempt);
        if (table->items[index].isOccupied && strcmp(table->items[index].plate, plate) == 0) {
            return 1; // Placa encontrada.
        }
        if (!table->items[index].isOccupied) {
            return 0; // Placa não está na hashtable.
        }
        attempt++;
    }
    return 0; // Placa não encontrada após todas tentativas.
}

int removePlate(HashTable* table, const char* plate) {
    int attempt = 0;
    while (attempt < M) {
        int index = hashFunction(plate, attempt);
        if (table->items[index].isOccupied && strcmp(table->items[index].plate, plate) == 0) {
            table->items[index].isOccupied = 0;
            strcpy(table->items[index].plate, "");
            table->num_items--;
            return 1; // Placa removida.
        }
        attempt++;
    }
    return 0; // Placa não encontrada.
}
