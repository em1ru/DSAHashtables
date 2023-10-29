#include "interface.h"
#include <stdio.h>
#include <time.h>

int main() {
    HashTable table;
    initHashTable(&table);

    FILE* file = fopen("placasMercosul.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char plate[8];
    clock_t start, end;
    double cpu_time_used;
    int totalPlatesInserted, totalPlatesSearched, totalPlatesRemoved;

    int plateCounts[] = { 128, 256, 512 };
    for (int k = 0; k < 3; k++) {
        int collisions = 0;
        int count = 0;

        // Reinicializa a tabela para cada novo conjunto de placas
        initHashTable(&table);

        // Medi��o do tempo de inclus�o
        start = clock();
        while (fscanf(file, "%7s< >\n", plate) == 1 && count < plateCounts[k]) {
            collisions += insertPlate(&table, plate);
            count++;
        }
        end = clock();
        totalPlatesInserted = count;
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Para %d placas: \n", plateCounts[k]);
        printf("Colis�es: %d\n", collisions);
        printf("Total de placas inseridas: %d\n", totalPlatesInserted);
        printf("Tempo de inclus�o: %f segundos\n", cpu_time_used);

        // Medi��o do tempo de busca
        rewind(file);
        count = 0;
        start = clock();
        while (fscanf(file, "%7s< >\n", plate) == 1 && count < plateCounts[k]) {
            searchPlate(&table, plate);
            count++;
        }
        end = clock();
        totalPlatesSearched = count;
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Total de placas buscadas: %d\n", totalPlatesSearched);
        printf("Tempo de busca: %f segundos\n", cpu_time_used);

        // Medi��o do tempo de remo��o
        rewind(file);
        count = 0;
        start = clock();
        while (fscanf(file, "%7s< >\n", plate) == 1 && count < plateCounts[k]) {
            removePlate(&table, plate);
            count++;
        }
        end = clock();
        totalPlatesRemoved = count;
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Total de placas removidas: %d\n", totalPlatesRemoved);
        printf("Tempo de remo��o: %f segundos\n", cpu_time_used);
        printf("------------------------------------\n");

        rewind(file); // Retorna ao in�cio do arquivo para a pr�xima itera��o
    }

    fclose(file);

    return 0;
}
