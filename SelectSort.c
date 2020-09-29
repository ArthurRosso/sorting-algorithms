#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include <windows.h>

#define MAX 20
#define CHAR_BAR '#'
#define CHAR_EMPTY ' '
#define FLOOR 25

// modelo: https://youtu.be/kPRA0W1kECg

void drawBar(int tam, int x);
void drawTitle(int comp, int acess);

int main ( ) {
    int arranjo[MAX]= {16, 11, 3, 9, 18, 20, 7, 13, 7, 4, 13, 10, 6, 5, 6, 1, 14, 8, 5, 19};
    int x, i, j, k, menor, menor_indice=0, aux, cmp=0, acs=0;
    char c;

    drawTitle(cmp, acs);
    for (k = 0; k < MAX; k++) {
        drawBar(arranjo[k], k+1);
    }
    Sleep(750);
    clrscr();

    for (i = 0; i < MAX-1; i++) {
        menor=arranjo[i];
        for (j = i; j < MAX; j++) {
            cmp++;
            if (arranjo[j] < menor) {
                menor=arranjo[j];
                acs++;
                menor_indice=j;
                acs++;
            }
        }
        cmp++;
        if (arranjo[i] > menor) {
            aux=arranjo[menor_indice];
            acs++;
            arranjo[menor_indice]=arranjo[i];
            acs++;
            arranjo[i]=aux;
            acs++;
        }
        drawTitle(cmp, acs);
        for (k = 0; k < MAX; k++) {
            drawBar(arranjo[k], k+1);
        }
        Sleep(750);
        clrscr();
    }

    drawTitle(cmp, acs);
    for (i = 0; i < MAX; i++) {
        drawBar(arranjo[i], i+1);
    }

    return 0;
}

void drawBar(int tam, int x) {
    int y;
    for(y=1; y <= MAX; y++) {
        if(y<=MAX-tam) {
            putchxy(x, y, CHAR_EMPTY);
        } else {
            putchxy(x, y, CHAR_BAR);
        }
    }
}

void drawTitle(int comp, int acess) {
    char display[100], snum[5];

    strcpy(display, "Ordenacao por Selecao - ");
    sprintf(snum, "%d", MAX);
    strcat(display, snum);
    strcat(display, " elementos - ");

    sprintf(snum, "%d", comp);
    strcat(display, snum);
    strcat(display, " comparacoes - ");

    sprintf(snum, "%d", acess);
    strcat(display, snum);
    strcat(display, " arranjos acessados\n");

    cputsxy(FLOOR, FLOOR-4, display);
}

