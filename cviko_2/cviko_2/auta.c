#define _CRT_SECURE_NO_WARNINGS
#include "auta.h"

void pridej_auto(KARTOTEKA* kartoteka)
{
    AUTO nove;
    printf("Zadej znacku: ");
    scanf("%31s", nove.znacka);
    printf("Zadej typ: ");
    scanf("%31s", nove.typ);
    printf("Rok vyroby: ");
    scanf("%d", &nove.rok_vyroby);
    printf("Objem motoru: ");
    scanf("%f", &nove.motor.objem);
    printf("Pocet valcu: ");
    scanf("%d", &nove.motor.pocet_valcu);
    printf("Pocet ventilu: ");
    scanf("%d", &nove.motor.pocet_ventilu);
    printf("Pocet km: ");
    scanf("%d", &nove.pocet_km);
    printf("Majitel: ");
    scanf("%31s", nove.majitel);

    kartoteka->data = realloc(kartoteka->data, (kartoteka->head.pocet_aut + 1) * sizeof(AUTO));
    kartoteka->data[kartoteka->head.pocet_aut] = nove;
    kartoteka->head.pocet_aut++;

    printf("Auto bylo pridano!\n");
}

void smaz_auto(KARTOTEKA* kartoteka, int index)
{
    if (index < 0 || index >= kartoteka->head.pocet_aut) {
        printf("Chyba: index mimo rozsah!\n");
        return;
    }

    for (int i = index; i < kartoteka->head.pocet_aut - 1; i++) {
        kartoteka->data[i] = kartoteka->data[i + 1];
    }

    kartoteka->head.pocet_aut--;
    kartoteka->data = realloc(kartoteka->data, kartoteka->head.pocet_aut * sizeof(AUTO));

    printf("Auto na indexu %d bylo smazano.\n", index);
}

void vypis_aut(const KARTOTEKA* kartoteka)
{
    if (kartoteka->head.pocet_aut == 0) {
        printf("Kartoteka je prazdna.\n");
        return;
    }

    for (int i = 0; i < kartoteka->head.pocet_aut; i++) {
        AUTO a = kartoteka->data[i];
        printf("%d) %s %s, rok %d, motor %.1fL (%dV/%dV), %d km, majitel: %s\n",
            i, a.znacka, a.typ, a.rok_vyroby,
            a.motor.objem, a.motor.pocet_valcu, a.motor.pocet_ventilu,
            a.pocet_km, a.majitel);
    }
}
