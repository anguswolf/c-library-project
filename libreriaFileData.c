#include "libreriaMacroComuni.h"
#include "libreriaFileData.h"

/**
 *
 * @param elenco array RecordDipendente da salvare
 * @param dim dimensione dell'array
 * @param nomeFile nome del file binario da creare nel quale salvare i dati
 */
void salvaDati(RecordDipendente elenco[], int dim, char nomeFile[])
{
	RecordDipendente dipendenteTemp;
	int i;
	FILE *fd;

	/* apre il file */
	fd=fopen(nomeFile, "w");

	if( fd==NULL ) {
	   perror("Errore in apertura del file");
	   exit(1);
	 }

	for (i = 0; i < dim; ++i)
	{
		dipendenteTemp = elenco[i];
		/* scrive l'elemento RecordDipendente */
		fwrite(&dipendenteTemp, sizeof(RecordDipendente), 1, fd);
	}

	/* chiude il file */
	fclose(fd);

}

/**
 *
 * @param elenco array RecordDipendente nel quale caricare i dati
 * @param dim dimensione dell'array
 * @param nomeFile nome del file binario dal quale leggere/caricare i dati
 */
void caricaDati(RecordDipendente elenco[], int dim, char nomeFile[])
{
	FILE *fd;
	int res;
	int i;
	RecordDipendente recDipTemp;

	/* apre il file in lettura */
	fd=fopen(nomeFile, "r");
	if( fd==NULL ) {
		perror("Errore in apertura del file");
		exit(1);
	}

	for (i = 0; i < dim; ++i)
	{
		/* lettura del primo elemento RecordDipendente */
		res=fread(&elenco[i], sizeof(RecordDipendente), 1, fd);
		if( res!=1 ) {
			perror("Errore in lettura");
			exit(1);
		}
	}

	/* chiude il file */
	fclose(fd);

}

/**
 *
 * @param elenco array RecordDipendente con i dati da stampare nel file
 * @param dim dimensione dell'array
 * @param nomeFile nome del file di testo da creare nel quale stampare i dati
 */
void stampaSuFile(RecordDipendente elenco[], int dim, char nomeFile[])
{
	FILE *fd;
	RecordDipendente dipendenteTemp;
	int i;

	/* apre il file in scrittura */
	fd=fopen(nomeFile, "w");
	if( fd==NULL ) {
		perror("Errore in apertura del file");
		exit(1);
	}

	for (i = 0; i < dim; ++i)
	{
		dipendenteTemp = elenco[i];
		/* scrive i dati nel file di testo */
		fprintf(fd, "%d - %s ",i, dipendenteTemp.nome);
		fprintf(fd, "%s ", dipendenteTemp.cognome);
		fprintf(fd, "- %s ", dipendenteTemp.codiceFiscale);
		fprintf(fd, "- %d ", dipendenteTemp.dipartimento);
		fprintf(fd, "- %d ", dipendenteTemp.posizione);
		fprintf(fd, "- %.2f ", dipendenteTemp.stipendio);
		fprintf(fd, "-Tempo indeterminato: %d ", dipendenteTemp.tempoIndeterminato);
		fprintf(fd, "- %d", dipendenteTemp.dataAssunzione.anno);
		fprintf(fd, "/%d", dipendenteTemp.dataAssunzione.mese);
		fprintf(fd, "/%d ", dipendenteTemp.dataAssunzione.giorno);
		fprintf(fd, "\n");
	}

	/* chiude il file */
	fclose(fd);

}