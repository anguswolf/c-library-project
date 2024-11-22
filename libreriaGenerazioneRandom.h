#ifndef LIBRERIAGENERAZIONERANDOM_H
#define LIBRERIAGENERAZIONERANDOM_H

char carattereRandom();
void generaStrAlfaNumericaRandom(char stringa[],int lung);
char generaCfCharRandom();
void generaCfRandom(char stringa[],int lung);
int generaPosizioneRandom(int nPosizioni);
float generaStipendioRandom();
Data generaDataRandom();
_Bool generaBoolRandom();
RecordDipendente generaDipendente();
void generaDipendenti(RecordDipendente dipendenti[],int dim);
void generaNomeRandom(char stringa[]);
void generaCognomeRandom(char vettCognome[LUNGHEZZA_NOME+1]);
void generaCodiceFiscaleRandom(char vettCodiceFiscale[LUNGHEZZA_CF+1], int dim);

void pGeneraDipendenti(RecordDipendente **p,int dim);

#endif //LIBRERIAGENERAZIONERANDOM_H
