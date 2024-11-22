#ifndef LIBRERIAINSERIMENTOCONTROLLO_H
#define LIBRERIAINSERIMENTOCONTROLLO_H

_Bool checkNome(char nome[]);
_Bool checkCognome(char cognome[]);
_Bool checkCf(char cf[]);
void svuotaBuffer();
RecordDipendente inserisciDipendente();
void inserisciDipendenti(RecordDipendente dipendenti[],int dim);
void inserisciCf(char codiceFiscale[], int dim);
void inserisciNome(char nome[], int dim);
void inserisciCognome(char cognome[], int dim);
int inserisciPosizione();
int inserisciGiorno();
int inserisciMese();
int inserisciAnno();
float inserisciStipendio();
int inserisciDipartimento();
_Bool inserisciTempoIndeterminato();
void cercaDipendente(RecordDipendente dipendenti[N_DIPENDENTI], int dim);
void inserisciStringa(char stringa[], int dim, char testo[]);
_Bool isDataMinore(Data a, Data b);
void pInserisciDipendenti(RecordDipendente **p,int dim);

#endif //LIBRERIAINSERIMENTOCONTROLLO_H
