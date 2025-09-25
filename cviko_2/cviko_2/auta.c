#include "auta.h"



void pridej_auto(KARTOTEKA* k) {
    k->head.pocet_aut++;

    k->data = realloc(k->data, k->head.pocet_aut * sizeof(AUTO));
    if (k->data == NULL) {
        printf("Chyba alokace pameti.\n");
        exit(1);
    }

    AUTO* nove_auto = &k->data[k->head.pocet_aut - 1];

    // Zadej znacku auta (nesmi byt prazdna)
    while (1) {
        printf("Zadejte znacku auta: ");
        fgets(nove_auto->znacka, MAX_NAME_LEN, stdin);
        nove_auto->znacka[strcspn(nove_auto->znacka, "\n")] = 0;
        if (strlen(nove_auto->znacka) > 0) break;
        printf("Znaèka nesmí být prázdná. Zkuste to znovu.\n");
    }

    // Zadej typ auta (nesmi byt prazdny)
    while (1) {
        printf("Zadejte typ auta: ");
        fgets(nove_auto->typ, MAX_NAME_LEN, stdin);
        nove_auto->typ[strcspn(nove_auto->typ, "\n")] = 0;
        if (strlen(nove_auto->typ) > 0) break;
        printf("Typ nesmí být prázdný. Zkuste to znovu.\n");
    }

    // Zadej rok vyroby (1886 - 2100)
    while (1) {
        printf("Zadejte rok vyroby: ");
        if (scanf_s("%d", &nove_auto->rok_vyroby) == 1 &&
            nove_auto->rok_vyroby >= 1886 && nove_auto->rok_vyroby <= 2100) {
            while (getchar() != '\n'); // vyèištìní bufferu
            break;
        }
        else {
            printf("Neplatný rok. Zadejte èíslo mezi 1886 a 2100.\n");
            while (getchar() != '\n'); // vyèištìní bufferu
        }
    }

    // Zadej objem motoru (kladne float)
    while (1) {
        printf("Zadejte objem motoru: ");
        if (scanf_s("%f", &nove_auto->motor.objem) == 1 && nove_auto->motor.objem > 0) {
            while (getchar() != '\n');
            break;
        }
        else {
            printf("Neplatný objem. Zadejte kladné èíslo.\n");
            while (getchar() != '\n');
        }
    }

    while (1) {
        printf("Zadejte pocet valcu motoru: ");
        if (scanf_s("%d", &nove_auto->motor.pocet_valcu) == 1 && nove_auto->motor.pocet_valcu > 0) {
            while (getchar() != '\n');
            break;
        }
        else {
            printf("Neplatný poèet válcù. Zadejte kladné èíslo.\n");
            while (getchar() != '\n');
        }
    }

    while (1) {
        char vstup[64];
        char* endptr;

        printf("Zadejte pocet ventilu motoru: ");
        if (fgets(vstup, sizeof(vstup), stdin) == NULL) {
            printf("Chyba vstupu. Zkuste znovu.\n");
            continue;
        }

        vstup[strcspn(vstup, "\n")] = 0;

        long ventily = strtol(vstup, &endptr, 10);

        if (endptr != vstup && *endptr == '\0' && ventily > 0) {
            nove_auto->motor.pocet_ventilu = (int)ventily;
            break;
        }

        printf("Neplatny pocet ventilu. Zadejte cele kladne cislo.\n");
    }

    // Pocet km (nezaporne int)
    while (1) {
        printf("Zadejte pocet km: ");
        if (scanf_s("%d", &nove_auto->pocet_km) == 1 && nove_auto->pocet_km >= 0) {
            while (getchar() != '\n');
            break;
        }
        else {
            printf("Neplatny pocet km. Zadejte nezaporné cislo.\n");
            while (getchar() != '\n');
        }
    }

    // Jmeno majitele (nesmi byt prazdne)
    while (1) {
        printf("Zadejte jmeno majitele: ");
        fgets(nove_auto->majitel, MAX_NAME_LEN, stdin);
        nove_auto->majitel[strcspn(nove_auto->majitel, "\n")] = 0;
        if (strlen(nove_auto->majitel) > 0) break;
        printf("Jméno nesmí být prázdné. Zkuste to znovu.\n");
    }

    printf("Auto bylo pridano do kartoteky.\n\n");
}




void smaz_auto(KARTOTEKA* k) {
    if (k->head.pocet_aut == 0) {
        printf("Kartoteka je prazdna.\n");
        return;
    }

    printf("\nSeznam aut:\n");
    for (int i = 0; i < k->head.pocet_aut; i++) {
        printf("%d) %s\n", i + 1, k->data[i].znacka);  // Zmìnìno: jen poøadí a znaèka
    }

    printf("Zadejte cislo auta, ktere chcete smazat (nebo 0 pro navrat do menu): ");

    while (1) {
        char vstup[16];
        char* endptr;
        long volba;

        if (fgets(vstup, sizeof(vstup), stdin) == NULL) {
            printf("Chyba cteni vstupu. Zkuste to znovu: ");
            continue;
        }

        vstup[strcspn(vstup, "\n")] = '\0';

        volba = strtol(vstup, &endptr, 10);

        if (endptr == vstup || *endptr != '\0') {
            printf("Neplatny vstup. Zadejte cislo: ");
            continue;
        }

        if (volba == 0) {
            printf("Zpet do hlavniho menu.\n\n");
            return;
        }

        if (volba < 1 || volba > k->head.pocet_aut) {
            printf("Neexistujici cislo. Zkuste to znovu: ");
            continue;
        }

        int index = (int)volba - 1;

        for (int i = index; i < k->head.pocet_aut - 1; i++) {
            k->data[i] = k->data[i + 1];
        }

        k->head.pocet_aut--;

        if (k->head.pocet_aut == 0) {
            free(k->data);
            k->data = NULL;
        }
        else {
            k->data = realloc(k->data, k->head.pocet_aut * sizeof(AUTO));
        }

        printf("Auto bylo smazano.\n\n");
        return;
    }
}

