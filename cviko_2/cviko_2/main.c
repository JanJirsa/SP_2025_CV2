#define _CRT_SECURE_NO_WARNINGS
#include "auta.h"

int main() {
    KARTOTEKA kartoteka;
    kartoteka.head.verze = 1.0f;
    kartoteka.head.pocet_aut = 0;
    kartoteka.data = NULL;

    int volba;
    do {
        printf("\n--- MENU ---\n");
        printf("1 - Pridat auto\n");
        printf("2 - Smazat auto\n");
        printf("3 - Vypis vsech aut\n");
        printf("0 - Konec\n");
        printf("Zadej volbu: ");
        scanf("%d", &volba);
        while (getchar() != '\n'); // vyèistí zbytek vstupu

        switch (volba) {
        case 1:
            pridej_auto(&kartoteka);
            break;
        case 2: {
            int index;
            printf("Zadej index auta ke smazani: ");
            scanf("%d", &index);
            while (getchar() != '\n'); // vyèistí zbytek vstupu
            smaz_auto(&kartoteka, index);
            break;
        }
        case 3:
            vypis_aut(&kartoteka);
            break;
        case 0:
            printf("Konec programu.\n");
            break;
        default:
            printf("Neplatna volba!\n");
        }
    } while (volba != 0);

    free(kartoteka.data);
    return 0;
}

