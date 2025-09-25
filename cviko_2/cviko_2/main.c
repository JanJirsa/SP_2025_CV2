

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auta.h"

int main() {
    KARTOTEKA seznam;
    seznam.head.verze = 1;
    seznam.head.pocet_aut = 0;
    seznam.data = NULL;

    while (1) {
        if (seznam.head.pocet_aut == 0) {
            printf("Kartoteka je prazdna.\n");
        }
        else {
            printf("\nSeznam aut:\n");
            for (int i = 0; i < seznam.head.pocet_aut; i++) {
                printf("%d) %s\n", i + 1, seznam.data[i].znacka);
            }
        }

        char prikaz[10];
        printf("Zadejte prikaz (pridat, smazat, konec): ");
        fgets(prikaz, sizeof(prikaz), stdin);
        prikaz[strcspn(prikaz, "\n")] = 0;

        if (strcmp(prikaz, "pridat") == 0) {
            pridej_auto(&seznam);
        }
        else if (strcmp(prikaz, "smazat") == 0) {
            smaz_auto(&seznam);
        }
        else if (strcmp(prikaz, "konec") == 0) {
            printf("Ukonèuji program.\n");
            break;
        }
        else {
            printf("Neplatny prikaz, zkuste to znovu.\n");
        }
    }

    free(seznam.data);
    return 0;
}
