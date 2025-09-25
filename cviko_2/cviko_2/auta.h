#pragma once

#include <stdio.h>
#include "stdlib.h"

#define MAX_NAME_LEN					32

#define MAX_LINE_LEN					MAX_NAME_LEN



typedef struct
{
	float objem;

	int pocet_valcu;

	int pocet_ventilu;
}MOTOR;

typedef struct
{
	char znacka[MAX_NAME_LEN];

	char typ[MAX_NAME_LEN];

	int rok_vyroby;

	MOTOR motor;

	int pocet_km;

	char majitel[MAX_NAME_LEN];

}AUTO;

typedef struct
{
	float verze;

	int pocet_aut;

}HEAD;

typedef struct
{
	HEAD head;

	AUTO* data;

}KARTOTEKA;


void pridej_auto(KARTOTEKA * kartoteka, AUTO * auto);
void smaz_auto(AUTO * auto, int index);


