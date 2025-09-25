#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auta.h"

#define MAX_AUT 100

// Globální kartotéka
KARTOTEKA kartoteka;

// Jednoduchý výpis všech aut (aby bylo vidìt indexy)
void vypisAuta() {
    if (kartoteka.head.pocet_aut == 0) {
        printf("\nKartoteka je prazdna.\n");
        return;
    }

    printf("\nSeznam aut (%d):\n", kartoteka.head.pocet_aut);
    for (int i = 0; i < kartoteka.head.pocet_aut; i++) {
        AUTO* a = &kartoteka.data[i];
        printf("%d) %s %s, rok %d, motor: %.1fL, valcu %d, ventilu %d, %d km, majitel: %s\n",
            i, a->znacka, a->typ, a->rok_vyroby,
            a->motor.objem, a->motor.pocet_valcu, a->motor.pocet_ventilu,
            a->pocet_km, a->majitel);
    }
    printf("\n");
}

// Pøidání auta na konec pole
void pridejAuto() {
    if (kartoteka.head.pocet_aut >= MAX_AUT) {
        printf("Kartoteka je plna!\n");
        return;
    }

    AUTO nove;

    printf("Zadej znacku: ");
    scanf_s("%31s", nove.znacka, (unsigned)_countof(nove.znacka));

    printf("Zadej typ: ");
    scanf_s("%31s", nove.typ, (unsigned)_countof(nove.typ));

    printf("Zadej rok vyroby: ");
    scanf_s("%d", &nove.rok_vyroby);

    printf("Zadej objem motoru (napr. 1.6): ");
    scanf_s("%f", &nove.motor.objem);

    printf("Zadej pocet valcu: ");
    scanf_s("%d", &nove.motor.pocet_valcu);

    printf("Zadej pocet ventilu: ");
    scanf_s("%d", &nove.motor.pocet_ventilu);

    printf("Zadej pocet km: ");
    scanf_s("%d", &nove.pocet_km);

    printf("Zadej jmeno majitele: ");
    scanf_s("%31s", nove.majitel, (unsigned)_countof(nove.majitel));

    kartoteka.data[kartoteka.head.pocet_aut] = nove;
    kartoteka.head.pocet_aut++;

    printf("Auto bylo pridano!\n");
}

// Smazání auta podle indexu (posun zbytku doleva)
void smazAuto() {
    if (kartoteka.head.pocet_aut == 0) {
        printf("Neni co mazat, kartoteka je prazdna.\n");
        return;
    }

    int index;
    printf("Zadej cislo auta ke smazani (0 az %d): ", kartoteka.head.pocet_aut - 1);
    scanf_s("%d", &index);

    if (index < 0 || index >= kartoteka.head.pocet_aut) {
        printf("Spatny index!\n");
        return;
    }

    for (int i = index; i < kartoteka.head.pocet_aut - 1; i++) {
        kartoteka.data[i] = kartoteka.data[i + 1];
    }

    kartoteka.head.pocet_aut--;
    printf("Auto bylo smazano!\n");
}

int main() {
    // Inicializace kartotéky
    kartoteka.head.verze = 1.0f;
    kartoteka.head.pocet_aut = 0;
    kartoteka.data = (AUTO*)malloc(sizeof(AUTO) * MAX_AUT);
    if (!kartoteka.data) {
        printf("Chyba alokace pameti!\n");
        return 1;
    }

    // Hlavní smyèka menu
    while (1) {
        int volba;

        printf("\n===== MENU KARTOTEKY AUT =====\n");
        printf("1 - Pridat auto\n");
        printf("2 - Smazat auto\n");
        printf("3 - Vypsat vsechna auta\n");
        printf("0 - Konec\n");
        printf("Tvoje volba: ");
        if (scanf_s("%d", &volba) != 1) {
            // Pokud se neco spatne nacte, ukoncime bezpecne
            printf("Chyba vstupu.\n");
            break;
        }

        if (volba == 1) {
            pridejAuto();
        }
        else if (volba == 2) {
            smazAuto();
        }
        else if (volba == 3) {
            vypisAuta();
        }
        else if (volba == 0) {
            printf("Konec programu.\n");
            break;
        }
        else {
            printf("Neznama volba!\n");
        }
    }

    // Uvolnìní pamìti
    free(kartoteka.data);
    return 0;
}


