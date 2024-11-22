#include "libreriaMacroComuni.h"
#include "libreriaInserimentoControllo.h"
#include "libreriaStampa.h"

/**
 *
 * @return RecordDipendente - ritorna il RecordDipendente inizializzato da input utente, esegue i controlli sui dati inseriti
 */
RecordDipendente inserisciDipendente()
{
    RecordDipendente dipendente;

    /*inserisciNome(dipendente.nome, LUNGHEZZA_NOME +1);
    inserisciCognome(dipendente.cognome, LUNGHEZZA_COGNOME+1);*/

    inserisciStringa(dipendente.nome,LUNGHEZZA_NOME+1,"nome");
    inserisciStringa(dipendente.cognome,LUNGHEZZA_COGNOME+1,"cognome");
    inserisciCf(dipendente.codiceFiscale, LUNGHEZZA_CF +1);
    dipendente.posizione = inserisciPosizione();
    printf("\n---- Inserisci La data di assunzione ----");
    dipendente.dataAssunzione.giorno = inserisciGiorno();
    dipendente.dataAssunzione.mese = inserisciMese();
    dipendente.dataAssunzione.anno = inserisciAnno();
    dipendente.stipendio = inserisciStipendio();
    dipendente.dipartimento = inserisciDipartimento();
    dipendente.tempoIndeterminato = inserisciTempoIndeterminato();

    return dipendente;
}

/**
 *
 * @param nome stringa del nome da controllare
 * @return true/false - ritorna true se il nome è conforme alle specifiche
 */
_Bool checkNome(char nome[])
{
    int lenght = strlen(nome);
    int i;
    if (lenght>LUNGHEZZA_NOME)
        return false;

    for ( i = 0; i < lenght; ++i)
    {
        //se il carattere e' tra quelli NON ammessi ritorna subito false
        if (nome[i] != ' ' && (nome[i] < 'a' || nome[i] > 'z')
           && (nome[i] < 'A' || nome[i] > 'Z'))
       {
            return false;
       }

    }
    return true;
}

/**
 *
 * @param cognome stringa del cognome da controllare
 * @return true/false - ritorna true se il nome è conforme alle specifiche
 */
_Bool checkCognome(char cognome[])
{
    int lenght = strlen(cognome);
    int i;

    if (lenght>LUNGHEZZA_COGNOME)
        return false;

    for ( i = 0; i < lenght; ++i)
    {
        //se il carattere e' tra quelli NON ammessi ritorna subito false
        if (cognome[i] != ' ' && (cognome[i] < 'a' || cognome[i] > 'z')
           && (cognome[i] < 'A' || cognome[i] > 'Z'))
        {
            return false;
        }

    }
    return true;
}

/**
 *
 * @param cf stringa codice fiscale - da controllare
 * @return true/false - verifica se il cf è conforme alle specifiche
 */
_Bool checkCf(char cf[])
{
    int lenght = strlen(cf);
    int i;

    if (lenght != LUNGHEZZA_CF)
        return false;

    for ( i = 0; i < lenght; ++i)
    {
        //se il carattere e' tra quelli NON ammessi ritorna subito false
        if ((cf[i] < '0' || cf[i] > '9')
           && (cf[i] < 'A' || cf[i] > 'Z'))
        {
            return false;
        }

    }
    return true;
}

/**
 * Procedura svuota buffer di input
 */
void svuotaBuffer(){
    char c;
    int contatore = 0;
    do{
        c = getchar();
        contatore++;
    }while(c != '\n');
    if(contatore > 1)
        printf("\nHo eliminato i caratteri in piu'...");
}

/**
 *
 * @param dipendenti vettore stringa da popolare con i dati inseriti dall'utente
 * @param dim dimensione del vettore dipendenti
 */
void inserisciDipendenti(RecordDipendente dipendenti[],int dim)
{
    int i;
    for (i = 0; i < dim; ++i)
    {
        dipendenti[i] = inserisciDipendente();
    }
}

void pInserisciDipendenti(RecordDipendente **p,int dim)
{
    int i;

    *p = realloc(*p,sizeof(RecordDipendente) * dim);

    for (i = 0; i < dim; ++i)
    {
        *((*p) + i) = inserisciDipendente();
    }
}

/**
 *
 * @param nome il vettore stringa da popolare con dati inseriti dall'utente
 * @param dim lunghezza del vettore passato
 */
/*
 * Non posso sapere la dimensione del vettore stringa di ingresso, quindi mi devo far passare una variabile dim.
 * Lo scanf utente registrera' dentro il vettore temporaneo il massimo numero di caratteri consentito (LUNGHEZZA_NOME).
 * Svuotabuffer eliminera' dal buffer i caratteri in eccesso rimasti nel buffer.
 * Avviene il controllo sulla stringa inserita se corrisponde alle specifiche di formattazione.
 * A questo punto verifica se il vettore passato esternamente alla procedura puo' contenere la stringa acquisita in input utente.
 * Se il check e' positivo copia la stringa dentro il vettore passato. Alternativamente stampa un messaggio di errore.
 */
void inserisciNome(char nome[], int dim)
{
    char tempNome[LUNGHEZZA_NOME+1];
    char filtro[DIM_FILTRO_SCAN];// stringa filtro con l'espressione regolare per limitare l'input

    sprintf(filtro,"%%%d[^\n]s",LUNGHEZZA_NOME); //-  filtro = %63[^\n]s
    do
    {   //Check Nome
        printf("\nInserisci Il nome (max %d caratteri solo maisucoli minuscoli e spazi:",LUNGHEZZA_NOME);
        scanf(filtro, tempNome); //"%[^\n]s" - scannerizza anche gli spazi
        svuotaBuffer();
    }
    while (!checkNome(tempNome));
    //printf("\n %s",nome);

    if (dim > strlen(tempNome))
    {
        strcpy(nome,tempNome);
    }
    else
    {
        printf("\nErrore dimensione vettore per InserisciNome(char[]) // strcpy();");
        exit(-1); //errore
    }
}



/**
 *
 * @param cognome il vettore stringa da popolare con dati inseriti dall'utente
 * @param dim lunghezza del vettore passato
 */
void inserisciCognome(char cognome[], int dim)
{
    char tempCognome[LUNGHEZZA_COGNOME+1];
    char filtro[DIM_FILTRO_SCAN];// stringa filtro con l'espressione regolare per limitare l'input

    sprintf(filtro,"%%%d[^\n]s",LUNGHEZZA_COGNOME); //-  filtro = %63[^\n]s
    do
    {   //Check Nome
        printf("\nInserisci Il cognome (max %d caratteri solo maisucoli minuscoli e spazi:",LUNGHEZZA_COGNOME);
        scanf(filtro, tempCognome); //"%[^\n]s" - scannerizza anche gli spazi
        svuotaBuffer();
    }
    while (!checkNome(tempCognome));

    if (dim > strlen(tempCognome))
    {
        strcpy(cognome,tempCognome);
    }
    else
    {
        printf("\nErrore dimensione vettore per InserisciNome(char[]) // strcpy();");
        exit(-1); //errore
    }

}

/**
 *
 * @param stringa il vettore stringa da popolare con dati inseriti dall'utente
 */
void inserisciStringa(char stringa[], int dim, char testo[])
{
    char tempStringa[dim];
    char filtro[DIM_FILTRO_SCAN];// stringa filtro con l'espressione regolare per limitare l'input

    sprintf(filtro,"%%%d[^\n]s",dim-1); //-  filtro = %dim-1[^\n]s
    do
    {   //Check Nome
        printf("\nInserisci il %s (max %d caratteri solo maisucoli minuscoli e spazi:",testo,dim-1);
        scanf(filtro, tempStringa); //"%[^\n]s" - scannerizza anche gli spazi
        svuotaBuffer();
    }
    while (!checkNome(tempStringa));

    if (dim > strlen(tempStringa))
    {
        strcpy(stringa,tempStringa);
    }
    else
    {
        printf("\nErrore dimensione vettore per InserisciStringa() // strcpy();");
        exit(-1); //errore
    }

}

/**
 *
 * @param codiceFiscale il vettore stringa da popolare con dati inseriti dall'utente
 * @param dim
 */
void inserisciCf(char codiceFiscale[], int dim)
{
    char tempCf[LUNGHEZZA_CF+1];
    char filtro[DIM_FILTRO_SCAN]; // stringa filtro con l'espressione regolare per limitare a LUNGHEZZA_CF (16) l'input

    sprintf(filtro,"%%%ds",LUNGHEZZA_CF); //%16s - permette max 16 caratteri NO spazi- stampa dentro filtro

    do
    {   //Check Codice fiscale
        printf("\nInserisci il CF (16 caratteri alfanumerici in maiuscolo):");
        scanf(filtro, tempCf); // acquisisce solo i primi LUNGHEZZA_CF (16) caratteri max
        svuotaBuffer();
    }
    while (!checkCf(tempCf));

    if (dim > strlen(tempCf))
    {
        strcpy(codiceFiscale,tempCf);
    }
    else
    {
        printf("\nErrore dimensione vettore per InserisciCf() // strcpy();");
        exit(-1); //errore
    }

}

/**
 *
 * @return int posizione inserita dall'utente
 */
int inserisciPosizione()
{
    int posizione;
    do
    {   //Check Posizione
        printf("\nInserisci La posizione [STAGISTA = 0, IMPIEGATO = 1, MANAGER = 2, DIRIGENTE = 3, ALTRO = 4]:");
        scanf("%d", &posizione);
        svuotaBuffer();
    }
    while (!(posizione >= 0 && posizione < NUM_POSIZIONI));

    return posizione;
}

/**
 *
 * @return int giorno inserito dall'utente
 */
int inserisciGiorno()
{
    int giorno;
    do
    {   //Check Giorno
        printf("\nInserisci giorno:");
        scanf("%d", &giorno);
        svuotaBuffer();
    }
    while (!(giorno >= MIN_GIORNO && giorno <= MAX_GIORNO));

    return giorno;
}

/**
 *
 * @return int mese inserito dall'utente
 */
int inserisciMese()
{
    int mese;
    do
    {   //Check Mese
        printf("\nInserisci mese:");
        scanf("%d", &mese);
        svuotaBuffer();
    }
    while (!(mese >= MIN_MESE && mese <= MAX_MESE));

    return mese;
}

/**
 *
 * @return int anno inserito dall'utente
 */
int inserisciAnno()
{
    int anno;
    do
    {   //Check Anno
        printf("\nInserisci anno (%d-%d):",MIN_ANNO, MAX_ANNO);
        scanf("%d", &anno);
        svuotaBuffer();
    }
    while (!(anno >= MIN_ANNO && anno <= MAX_ANNO));

    return anno;
}

/**
 *
 * @return float stipendio inserito dall'utente
 */
float inserisciStipendio()
{
    float stipendio;
    do
    {   //Check Stipendio
        printf("\nInserisci Lo stipendio:");
        scanf("%f", &stipendio);
        svuotaBuffer();
    }
    while (!(stipendio >= MIN_STIPENDIO));

    return stipendio;
}

/**
 *
 * @return int dipartimento con dati inseriti dall'utente
 */
int inserisciDipartimento()
{
    int dipartimento;
    printf("\nInserisci Il numero di dipartimento:");
    scanf("%d", &dipartimento);
    svuotaBuffer();

    return dipartimento;
}

/**
 *
 * @return _Bool tempoIndeterminato con dati inseriti dall'utente
 */
_Bool inserisciTempoIndeterminato()
{
    int tempoIndeterminato;
    do
    {   //Check Tempo indeterminato
        printf("\nInserisci Tempo indeterminato [NO = 0/ SI = 1]:");
        scanf("%d", &tempoIndeterminato);
        svuotaBuffer();
    }
    while (!(tempoIndeterminato == 0 || tempoIndeterminato == 1));

    return tempoIndeterminato;
}

/**
 *
 * @param dipendenti vettore stringa con i dati di tutti i dipendenti
 * @param dim dimensione del vettore stringa
 */
void cercaDipendente(RecordDipendente dipendenti[N_DIPENDENTI], int dim)
{
    char codiceFiscale[LUNGHEZZA_CF+1];
    int i;

    printf("\n-------------------------------------------------------------------------");
    printf("\nRICERCA DIPENDENTE");
    printf("\n-------------------------------------------------------------------------");

    inserisciCf(codiceFiscale, LUNGHEZZA_CF+1);

    for (i = 0; i < dim; ++i)
    {
        if (strcmp(dipendenti[i].codiceFiscale,codiceFiscale) == 0)
        {
            stampaDipendente(dipendenti[i]);
            break;
        }
    }
}

_Bool isDataMinore(Data a, Data b)
{
    //controlla la data piu vecchia tra il primo e il secondo delle date inserite nell'anno, mese e giorno
    if (a.anno < b.anno) return true;
    else if (a.anno > b.anno) return false;
    else // entra in questo ramo solo se gli anni sono uguali
    {
        if (a.mese < b.mese) return true;
        else if (a.mese > b.mese) return false;
        else // entra in questo ramo solo se i mesi sono uguali
        {
            if (a.giorno < b.giorno) return true;
            else return false;
        }
    }
}



