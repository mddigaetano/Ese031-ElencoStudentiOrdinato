#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente{
    char nome[MAX_STRLEN];
    char cognome[MAX_STRLEN];
    unsigned int eta;
    char classe[MAX_STRLEN];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

// Dichiara il prototipo della funzione di ordinamento
void SelectionCognomi(studente v[], int n);

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    int i;
    studente elenco[N];
    
    // Codice per l'inserimento, da parte dell'utente, dei dati
    for(i=0;i<N;i++){
        printf("Inserisci il %d° nome: ",i+1);
        scanf("%s", (elenco[i].nome));
        printf("Inserisci il %d° cognome: ",i+1);
        scanf("%s", (elenco[i].cognome));
        printf("Inserisci la %da eta': ",i+1);
        scanf("%d", &(elenco[i].eta));
        printf("Inserisci la %da classe: ",i+1);
        scanf("%s", (elenco[i].classe));
    }
    
    // Ordina l'elenco (con funzione)
    SelectionCognomi(elenco,N);
    
    // Codice per la stampa dei dati (uno studente per riga)
    printf("\n");
    
    for(i=0;i<N;i++){
        printf("%s; %s; %d; %s\n", elenco[i].nome,elenco[i].cognome,elenco[i].eta,elenco[i].classe);
    }
    return (EXIT_SUCCESS);
}

// Definisci la funzione di ordinamento
void SelectionCognomi(studente v[],int n){
    int i,min,j;
    studente scambio;
    
    for(i=0;i<n-1;i++){
        min=i;
        
        for(j=i+1;j<n;j++){
            if(strcmp(v[j].cognome,v[min].cognome)<0){
                min=j;
            }
        }
        
        scambio=v[i];
        v[i]=v[min];
        v[min]=scambio;
    }
}