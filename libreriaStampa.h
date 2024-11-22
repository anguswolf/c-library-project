#ifndef LIBRERIASTAMPA_H
#define LIBRERIASTAMPA_H
void stampaPosizione(Posizione posizione);
void stampaDipendente(RecordDipendente dipendente);
void stampaBooleano(_Bool booleano);
void stampaDipendenti(RecordDipendente dipendenti[],int dim);
void calcolaStipendi(RecordDipendente dipendenti[N_DIPENDENTI], int dim);
void distribuzionePosizioni(RecordDipendente dipendenti[N_DIPENDENTI], int dim);
void stampaDipartimento(RecordDipendente dipendenti[N_DIPENDENTI], int dim, int dipartimento);
void stampaOrdineAlfabetico(RecordDipendente dipendenti[N_DIPENDENTI+1], int dim);
void stampaOrdineDataAssunzione(RecordDipendente dipendenti[], int dim);
#endif //LIBRERIASTAMPA_H
