#include "libreriaMacroComuni.h"
#include "libreriaGenerazioneRandom.h"

/**
 * 
 * @return RecordDipendente - ritorna il dipendente con i valori generati random
 */
RecordDipendente generaDipendente()
{
    RecordDipendente dipendente;

    char nomeGenerato[LUNGHEZZA_NOME+1];//Il nome e il cognome possono contenere solo spazi e lettere (maiuscole o minuscole), 64 caratteri, compreso terminatore
    char cognomeGenerato[LUNGHEZZA_COGNOME+1]; //63+1
    char codiceFiscaleGenerato[LUNGHEZZA_CF+1] ={""};//Il codice fiscale deve contenere esattamente 16 caratteri alfanumerici maiuscoli;

    //GENERAZIONE RANDOM STRINGHE
    generaNomeRandom(nomeGenerato);
    generaCognomeRandom(cognomeGenerato);
    generaCodiceFiscaleRandom(codiceFiscaleGenerato,LUNGHEZZA_CF+1);
    //generaCfRandom(codiceFiscaleGenerato,LUNGHEZZA_CF);
    //generaStrAlfaNumericaRandom(nomeGenerato,LUNGHEZZA_NOME);
    //generaStrAlfaNumericaRandom(cognomeGenerato,LUNGHEZZA_COGNOME);

    // INIZIALIZZAZIONE STRUCT DIPENDENTE
    strcpy(dipendente.nome,nomeGenerato);
    strcpy(dipendente.cognome,cognomeGenerato);
    strcpy(dipendente.codiceFiscale,codiceFiscaleGenerato);

    dipendente.posizione = generaPosizioneRandom(NUM_POSIZIONI);
    dipendente.dataAssunzione = generaDataRandom();
    dipendente.stipendio = generaStipendioRandom();
    dipendente.dipartimento = rand()%11; //non vi sono specifiche sul n. di dipartimenti - 0-10
    dipendente.tempoIndeterminato = generaBoolRandom();

    return dipendente;
}

/**
 * 
 * @param stringa il vettore da popolare con i dati random
 * @param lung la lungehzza della stringa da generare
 */
void generaStrAlfaNumericaRandom(char stringa[],int lung)
{
    int i;
    for (i = 0; i < lung; ++i)
    {
        stringa[i] = carattereRandom();
    }
    stringa[lung] = '\0';

}

void generaNomeRandom(char vettNome[LUNGHEZZA_NOME + 1]) //vettNome viene creato di 8 caratteri!!(dim del puntatore)
{
    char nomi[N_NOMI][LUNGHEZZA_NOME + 1] = {"Franco","Maria","Pino","Valeria","Giovannino"};
    int indiceRandom = rand()%N_NOMI;

    strcpy(vettNome,nomi[indiceRandom]);
}

void generaCognomeRandom(char vettCognome[LUNGHEZZA_COGNOME+1])
{
    char cognomi[N_COGNOMI][LUNGHEZZA_COGNOME+1] = {"Rossi", "Verdi", "Gialli","Neri","Arancionissimi"};
    int indiceRandom = rand()%N_COGNOMI;

    strcpy(vettCognome,cognomi[indiceRandom]);
}

void generaCodiceFiscaleRandom(char vettCodiceFiscale[LUNGHEZZA_CF+1], int dim)
{
    char carattereCf[N_CHAR_CF][LUNGHEZZA_CHAR+1] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P",
        "Q","R","S","T","U","V","W","X","Y", "Z","0","1","2","3","4","5","6","7","8","9"};
    int i;
    char tempCf[dim];

    for (i = 0; i < LUNGHEZZA_CF; ++i)
    {
        //strcat(tempCf,carattereCf[(rand()%N_CHAR_CF)]);
        strcat(vettCodiceFiscale,carattereCf[(rand()%N_CHAR_CF)]);
        //printf("\n %s",carattereCf[(rand()%N_CHAR_CF)]);
    }

    //strcpy(vettCodiceFiscale,tempCf);
}

/**
 * 
 * @return genera un carattere random di tipo alfabetico - spazio ammesso
 */
char carattereRandom()
{
    int tipo = rand()% 3; // tipo varia da 0 a 2

    if (tipo == 0)
    {
        return 'A' + rand()% ('Z' - 'A' +1);
    }
    else if (tipo == 1)
    {
        return 'a' + rand()% ('z' - 'a' +1);
    }else
        return ' ';
}

/**
 * 
 * @return genera un carattere random valido per il codice fiscale
 */
char generaCfCharRandom()
{
    int tipo = rand()% 2; // tipo varia da 0 a 1

    if (tipo == 0)
    {
        return 'A' + rand()% ('Z' - 'A' +1);
    }
    else
    {
        return '0' + rand()% ('9' - '0' +1);
    }
}

/**
 * 
 * @param stringa popola il vettore stringa con un codice fiscale random valido
 * @param dim la launghezza del codice fiscale generato
 */
void generaCfRandom(char stringa[],int dim)
{
    int i;
    for (i = 0; i < dim; ++i)
    {
        stringa[i] = generaCfCharRandom();
        //printf("\n%c", stringa[i]);
    }
    stringa[dim] = '\0';

}

/**
 * 
 * @param nPosizioni numero di posizioni
 * @return genera una Posizione random (valore numerico int)
 */
int generaPosizioneRandom(int nPosizioni)
{
    int tipo = rand()% nPosizioni; // tipo varia da 0 a (nPosizioni-1)

    switch (tipo)
    {
        case STAGISTA:
            return STAGISTA;
            break;
        case IMPIEGATO:
            return IMPIEGATO;
            break;
        case MANAGER:
            return MANAGER;
            break;
        case DIRIGENTE:
            return DIRIGENTE;
            break;
        case ALTRO:
            return ALTRO;
            break;
        default:
            return -1; // Errore
    }
}

/**
 * 
 * @return float genera un valore numerico maggiore di zero
 */
float generaStipendioRandom()
{
    float stipendioGenerato;

    stipendioGenerato = (float)(1 + rand()) /10; // il divisore per avere numeri oltre il punto

    return stipendioGenerato;
}

/**
 * 
 * @return genera una data popolata con valori di giorno, mese e anno random pseudo-validi
 */
Data generaDataRandom()
{
    Data dataRandom;

    int giorno = MIN_GIORNO + rand() % (MAX_GIORNO - MIN_GIORNO +1); // valore random da 1 a 31 per il giorno
    int mese = MIN_MESE + rand() % (MAX_MESE - MIN_MESE +1); // valore random da 1 a 12 per il mese
    int anno = MIN_ANNO + rand() % (MAX_ANNO - MIN_ANNO +1); // valore random da 1900 a 2024 per l'anno

    dataRandom.giorno = giorno;
    dataRandom.mese = mese;
    dataRandom.anno = anno;

    return dataRandom;
}

/**
 * 
 * @return genera un booleano true/false random
 */
_Bool generaBoolRandom()
{
    if (rand()% 2)  // varia da 1 a 0 - true/false
    {
        return true;
    }
    return false;
}

/**
 *
 * @param dipendenti indirizzo al vettore stringa dipendenti su cui salvare l'elenco generato
 * @param dim dimensione del vettore dipendenti
 */
void generaDipendenti(RecordDipendente dipendenti[],int dim)
{
    int i;
    for (i = 0; i < dim; ++i)
    {
        dipendenti[i] = generaDipendente();
    }
}

void pGeneraDipendenti(RecordDipendente **p,int dim) //il puntatore alla var puntatore dell'array di dipendenti - poichè il puntatore è passato per valore
{
    int i;

    *p = realloc(*p,sizeof(RecordDipendente) * dim);

    for (i = 0; i < dim; ++i)
    {
        //(*p)[i] = generaDipendente();

        *((*p)+i) = generaDipendente();

    }
}
