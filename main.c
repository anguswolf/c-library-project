#include "libreriaMacroComuni.h"
#include "libreriaGenerazioneRandom.h"
#include "libreriaInserimentoControllo.h"
#include "libreriaStampa.h"
#include "libreriaFileData.h"

int main(void)
{
    //generazione del seed random
    srand(time(NULL));

    RecordDipendente dipendente ={};
    RecordDipendente elenco[N_DIPENDENTI] ={};
	char nomeFileBinario[] = "filebinario.dat";
	char nomeFilediTesto[] = "fileditesto.txt";


    //allocazione dinamica della memoria (heap)
    RecordDipendente* pElenco;
    pElenco = (RecordDipendente* ) malloc(sizeof(RecordDipendente) * N_DIPENDENTI);

	/*dipendente = generaDipendente();
    stampaDipendente(dipendente);*/
	generaDipendenti(elenco,N_DIPENDENTI);

    //pInserisciDipendenti(&pElenco,2); //modifica la dimensione del vettore pElenco dinamicamente
    pGeneraDipendenti(&pElenco,DIM_P_ELENCO); //modifica la dimensione del vettore pElenco dinamicamente

	//salvadati(elenco,N_DIPENDENTI);
	salvaDati(pElenco,DIM_P_ELENCO,nomeFileBinario);
	printf("\n\n ######################DATI SALVATI IN FILE DA P_ELENCO##################");
    stampaDipendenti(pElenco,DIM_P_ELENCO);


    printf("\n\n ######################DATI CARICATI IN ELENCO DA P_ELENCO###############");
    caricaDati(elenco,DIM_P_ELENCO,nomeFileBinario);

	stampaSuFile(elenco,N_DIPENDENTI,nomeFilediTesto);

    //inserisciDipendenti(pElenco,N_DIPENDENTI);
    /*generaDipendenti(pElenco,N_DIPENDENTI);
    stampaDipendenti(pElenco,N_DIPENDENTI);*/

    //dipendente = generaDipendente();
    //dipendente = inserisciDipendente();
    //stampaDipendente(dipendente);

    //inserisciDipendenti(dipendenti,N_DIPENDENTI);
    //generaDipendenti(elenco,N_DIPENDENTI);
    //stampaDipendenti(elenco,N_DIPENDENTI);

    /*stampaOrdineAlfabetico(elenco,N_DIPENDENTI);
    printf("\n\n ################################ ARRAY ORGNALE NON ORDINATO ###############################");
    stampaDipendenti(elenco,N_DIPENDENTI);*/

    //stampaOrdineDataAssunzione(elenco,N_DIPENDENTI);
    //printf("\n\n ################################ ARRAY ORIGINALE NON ORDINATO ###############################");
    //stampaDipendenti(elenco,N_DIPENDENTI);

    //cercaDipendente(dipendenti, N_DIPENDENTI);

    /*calcolaStipendi(dipendenti,N_DIPENDENTI);
    distribuzionePosizioni(dipendenti,N_DIPENDENTI);
    dipendenti[0].dipartimento = 2;
    dipendenti[1].dipartimento = 2;
    dipendenti[2].dipartimento = 2;
    dipendenti[3].dipartimento = 3;
    dipendenti[4].dipartimento = 3;
    stampaDipartimento(dipendenti,N_DIPENDENTI,2);
    stampaDipartimento(dipendenti,N_DIPENDENTI,3);*/

    return 0;
}









