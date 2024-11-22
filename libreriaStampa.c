#include "libreriaMacroComuni.h"
#include "libreriaStampa.h"
#include "libreriaInserimentoControllo.h"

/**
 *
 * @param dipendente variabile con i dati del dipendente
 */
void stampaDipendente(RecordDipendente dipendente)
{
    //Stampa tutti i campi della struttura RecordDipendente
    printf("\n-------------------------------------------------------------------------");
    printf("\n SCHEDA RECORD DIPENDENTE:");
    printf("\n-------------------------------------------------------------------------");
    printf("\nNOME: %s", dipendente.nome);
    printf("\nCOGNOME: %s", dipendente.cognome);
    printf("\nCODICE FISCALE: %s", dipendente.codiceFiscale);
    printf("\nPOSIZIONE: ");
    stampaPosizione(dipendente.posizione);
    printf("\nDATA DI ASSUNZIONE: %d/%d/%d",dipendente.dataAssunzione.giorno,dipendente.dataAssunzione.mese,dipendente.dataAssunzione.anno);
    printf("\nSTIPENDIO: %.2f",dipendente.stipendio);
    printf("\nDIPARTIMENTO: %d",dipendente.dipartimento);
    printf("\nTEMPO INDETERMINATO: ");
    stampaBooleano(dipendente.tempoIndeterminato);
    printf("\n-------------------------------------------------------------------------");

}

/**
 *
 * @param posizione variabile con la posizione del dipendente - stampa i valori enum
 */
void stampaPosizione(Posizione posizione)
{
    switch (posizione)
    {
    case STAGISTA:
        printf("Stagista");
        break;
    case IMPIEGATO:
        printf("Impiegato");
        break;
    case MANAGER:
        printf("Manager");
        break;
    case DIRIGENTE:
        printf("Dirigente");
        break;
    case ALTRO:
        printf("Altro");
        break;
    default:
        printf("Nessuna posizione valida");
    }
}

/**
 *
 * @param booleano booleano passato alla funzione - stampa in italiano
 */
void stampaBooleano(_Bool booleano)
{
    if (booleano)printf("Si");
    else printf("No");
}

/**
 *
 * @param dipendenti indirizzo al vettore stringa dipendenti da stampare
 * @param dim dimensione del vettore dipendenti
 */
void stampaDipendenti(RecordDipendente dipendenti[],int dim)
{
    int i;
    for (i = 0; i < dim; ++i)
    {
        stampaDipendente(dipendenti[i]);
    }
}

/**
 *
 * @param dipendenti il vettore con i dati di tutti i dipendenti
 * @param dim la dimensione del vettore
 */
void calcolaStipendi(RecordDipendente dipendenti[N_DIPENDENTI], int dim)
{
    float totaleStipendi = 0;
    int i;

    for (i = 0; i < dim; ++i)
    {
        totaleStipendi += dipendenti[i].stipendio;
    }
    //Stampa il totale di tutti gli stipendi dei dipendenti
    printf("\n-------------------------------------------------------------------------");
    printf("\n TOTALE STIPENDI:");
    printf("\nTotale stipendi dei dipendenti: %.2f",totaleStipendi);
    printf("\n-------------------------------------------------------------------------");
}

/**
 *
 * @param dipendenti il vettore con i dati di tutti i dipendenti
 * @param dim la dimensione del vettore
 */
void distribuzionePosizioni(RecordDipendente dipendenti[N_DIPENDENTI], int dim)
{
    //STAGISTA, IMPIEGATO, MANAGER, DIRIGENTE, ALTRO
    int distPosizioni[NUM_POSIZIONI] ={0}; //mappa per il conteggio delle posizioni trovate
    int i,j;

    for (i = 0; i < dim; ++i)
    {
        switch (dipendenti[i].posizione)
        {
        case STAGISTA:
            distPosizioni[STAGISTA]++;
            break;
        case IMPIEGATO:
            distPosizioni[IMPIEGATO]++;
            break;
        case MANAGER:
            distPosizioni[MANAGER]++;
            break;
        case DIRIGENTE:
            distPosizioni[DIRIGENTE]++;
            break;
        case ALTRO:
            distPosizioni[ALTRO]++;
            break;
        default:
            break;
        }
    }

    printf("\n-------------------------------------------------------------------------");
    printf("\n DISTRIBUZIONE POSIZIONI:");
    printf("\n-------------------------------------------------------------------------");
    for (j = 0; j < NUM_POSIZIONI; ++j)
    {
        printf("\n");
        stampaPosizione(j);
        printf(" - N. dipendenti: %d",distPosizioni[j]);
    }

}

/**
 *
 * @param dipendenti il vettore con i dati di tutti i dipendenti
 * @param dim la dimensione del vettore
 * @param dipartimento il dipartimento da stampare
 */
void stampaDipartimento(RecordDipendente dipendenti[N_DIPENDENTI], int dim, int dipartimento)
{
    int i;
    printf("\n-------------------------------------------------------------------------");
    printf("\n DIPARTIMENTO N.%d",dipartimento);
    //printf("\n-------------------------------------------------------------------------");
    for (i = 0; i < dim; ++i)
    {
        if (dipendenti[i].dipartimento == dipartimento)
            stampaDipendente(dipendenti[i]);
    }

}

/**
 *
 * @param dipendenti array dei dipoendenti da stampare
 * @param dim dimensione dell'array da stampare
 */
void stampaOrdineAlfabetico(RecordDipendente dipendenti[], int dim)
{
    int k,i,j;
    char tempCognome[LUNGHEZZA_COGNOME+1];
    RecordDipendente tempDipendente;
    RecordDipendente tempDipendenti[dim];

    //copia fisica array dipendenti in tempDipendenti
    for ( k = 0; k < dim; ++k)
    {
        tempDipendenti[k] = dipendenti[k];
    }

    for (j = 1; j < dim; ++j)
    {
        strcpy(tempCognome,tempDipendenti[j].cognome); //copio il valore al 2o posto nell'array da analizzare
        tempDipendente = tempDipendenti[j];

        i = j - 1; // i=0
        while (i >= 0 && strcmp(tempDipendenti[i].cognome,tempCognome) > 0) //confronto tra el[0] e el[1]
        {
            //strcpy(tempDipendenti[N_DIPENDENTI].cognome,tempDipendenti[N_DIPENDENTI-1].cognome);
            tempDipendenti[i+1] = tempDipendenti[i]; //shifta a destra l'elemento precedente
            i= i-1; //l'indice scorre a sinistra per analizzare l'elemento successivo verso sx
        }
        tempDipendenti[i+1] = tempDipendente; //qunado trova un elemento piu piccolo si ferma e scrive l'elemento nella posizione trovata
        //stampaDipendente(tempDipendente);
    }

    printf("\n\n ######################### ORDINAMENTO ###ALFABETICO ### COGNOME ###############################################");
    stampaDipendenti(tempDipendenti,dim);

}

/**
 *
 * @param dipendenti array dei dipoendenti da stampare
 * @param dim dimensione dell'array da stampare
 */
void stampaOrdineDataAssunzione(RecordDipendente dipendenti[], int dim)
{
    int k,i,j;
    //char tempCognome[LUNGHEZZA_COGNOME+1];
    Data tempData;

    RecordDipendente tempDipendente;
    RecordDipendente tempDipendenti[dim];

    //copia fisica array dipendenti in tempDipendenti
    for ( k = 0; k < dim; ++k)
    {
        tempDipendenti[k] = dipendenti[k];
    }

    for (j = 1; j < dim; ++j)
    {
        tempData = tempDipendenti[j].dataAssunzione; //copio il valore al 2° posto nell'array da analizzare
        tempDipendente = tempDipendenti[j];

        i = j - 1; // i=0
        while (i >= 0 && !isDataMinore(tempDipendenti[i].dataAssunzione,tempData)) //confronto tra el[0] e el[1]
        {
            //strcpy(tempDipendenti[N_DIPENDENTI].cognome,tempDipendenti[N_DIPENDENTI-1].cognome);
            tempDipendenti[i+1] = tempDipendenti[i]; //shifta a destra l'elemento precedente
            i= i-1; //l'indice scorre a sinistra per analizzare l'elemento successivo verso sx
        }
        tempDipendenti[i+1] = tempDipendente; //qunado trova un elemento piu piccolo si ferma e scrive l'elemento nella posizione trovata
        //stampaDipendente(tempDipendente);
    }

    printf("\n\n ######################### ORDINAMENTO ###DATA DI ASSUNZIONE #################################################");
    stampaDipendenti(tempDipendenti,dim);
}
