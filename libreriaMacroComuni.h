#ifndef LIBRERIAMACROCOMUNI_H
#define LIBRERIAMACROCOMUNI_H

#define N_NOMI 5
#define N_COGNOMI 5
#define LUNGHEZZA_NOME 63
#define LUNGHEZZA_COGNOME 63
#define LUNGHEZZA_CF 16
#define NUM_POSIZIONI 5
#define MIN_GIORNO 1
#define MAX_GIORNO 31
#define MIN_MESE 1
#define MAX_MESE 12
#define MIN_ANNO 1900
#define MAX_ANNO 2024
#define MIN_STIPENDIO 1
#define N_DIPENDENTI 50
#define DIM_FILTRO_SCAN 16
#define BUFFER_OVERFLOW 1
//#define N_CHAR_CF 26+10
#define N_CHAR_CF 36
#define LUNGHEZZA_CHAR 1
#define DIM_P_ELENCO 3

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int anno;
    int mese;
    int giorno;
} Data;

typedef enum
{
    STAGISTA, IMPIEGATO, MANAGER, DIRIGENTE, ALTRO
}
Posizione;

typedef struct
{
    char nome[LUNGHEZZA_NOME + 1];
    char cognome[LUNGHEZZA_COGNOME + 1];
    char codiceFiscale[LUNGHEZZA_CF + 1];
    Posizione posizione;
    Data dataAssunzione;
    float stipendio;
    int dipartimento;
    _Bool tempoIndeterminato;

} RecordDipendente;

#endif //LIBRERIAMACROCOMUNI_H
