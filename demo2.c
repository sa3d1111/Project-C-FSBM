#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

struct Date {
    int jour, mois, annee;
};

struct patient {
    char nom[50];
    char prenom[50];
    char numero_de_telephone[20];
    struct Date dateNaissance;
    struct Date date_dinscription;
    int numero_de_dossier;
    char adresse[100];
    char groupe_sanguin[50];
    char date_dinscription_str[50]; 
};

struct repertoire_de_patients {
    struct patient liste[MAX];
    int nbPatients;
};

void Ajout_un_patient(struct repertoire_de_patients *rep) {
    int numero_de_dossier, jour, mois, annee;
    char nom[50], prenom[50], adresse[100], Groupe_sanguin[10], numero_de_telephone[15];

    struct patient p;

    printf("Entrez votre Numero de dossier: ");
    scanf("%d", &numero_de_dossier);

    printf("\nEntrez votre Nom: ");
    scanf("%s", nom);

    printf("\nEntrez votre Prenom: ");
    scanf("%s", prenom);

    printf("\nEntrez votre Date de naissance (JJ/MM/AAAA): ");
    scanf("%d/%d/%d", &jour, &mois, &annee);

    printf("\nEntrez votre Numero de telephone: ");
    scanf("%s", numero_de_telephone);

    printf("\nEntrez votre Adresse: ");
    scanf("%s", adresse);

    printf("\nEntrez votre Groupe sanguin: ");
    scanf("%s", Groupe_sanguin);

    p.numero_de_dossier = numero_de_dossier;
    strcpy(p.nom, nom);
    strcpy(p.prenom, prenom);
    p.dateNaissance.jour  = jour;
    p.dateNaissance.mois  = mois;
    p.dateNaissance.annee = annee;
    strcpy(p.numero_de_telephone, numero_de_telephone);
    strcpy(p.adresse, adresse);
    strcpy(p.groupe_sanguin, Groupe_sanguin);

    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(p.date_dinscription_str, sizeof(p.date_dinscription_str), "%Y-%m-%d %H:%M:%S", t); 

    
    rep->liste[rep->nbPatients] = p;
    rep->nbPatients++;

    printf("\n%s %s ajoute avec succes (inscription: %s)\n",
           p.prenom, p.nom, p.date_dinscription_str);
}

int main() {
    struct repertoire_de_patients rep;
    rep.nbPatients = 0;
    Ajout_un_patient(&rep);
    return 0;
}
