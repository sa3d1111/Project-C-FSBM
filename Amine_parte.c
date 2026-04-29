#include<stdio.h>
#include<string.h>
#include<stdlib.h>


    
    #define MAX 100 //  5tarit lmax diyal patients howa 100 ta ykmel lcode wnbadloha  
    struct Date
    {
        int jour, mois, annee ;
    };
    struct patient
    {
        char nom[50];
        char prenom[50];
        char numero_de_telephone[15];
        struct Date dateNaissance;
        int numero_de_dossier;
        char adresse[100];
        char groupe_sanguin[10];
    };
    struct repertoire_de_patients
    {
        struct patient liste[MAX];
        int nbPatients;
    };
    
    

    void Ajout_un_patient(struct repertoire_de_patients *rep){
        int numero_de_dossier,jour, mois, annee;
        char nom[50], prenom[50], adresse[100], Groupe_sanguin[10], numero_de_telephone[15];

        struct patient p;

        printf("Entrez votre Numero de dossier: ");
        scanf("%d",&numero_de_dossier);

        printf("\nEntrez votre Nom: ");
        scanf("%s",nom);

        printf("\nEntrez votre Prenom: ");
        scanf("%s",prenom);
        
        printf("\nEntrez votre Date de naissance (JJ/MM/AAAA) : ");
        scanf("%d/%d/%d",&jour, &mois, &annee);

        printf("\nEntrez votre Numero de telephone: ");
        scanf("%s", numero_de_telephone);

        printf("\nEntrez votre Adresse: ");
        getchar();
        fgets(adresse, sizeof(adresse), stdin);// partie fach siaftha l ai gal li 5asek dirha bhal hoka mais ama mafahemch syntax so dert liha copy paste tal mn be3d wnchofo blanha
        adresse[strcspn(adresse, "\n")] = 0;
        

        printf("\nEntrez votre Groupe sanguin: ");
        scanf("%s",Groupe_sanguin);

       

        p.numero_de_dossier = numero_de_dossier;
        strcpy(p.nom, nom);
        strcpy(p.prenom, prenom);
        p.dateNaissance.jour = jour;
        p.dateNaissance.mois = mois;
        p.dateNaissance.annee = annee;
        strcpy(p.numero_de_telephone, numero_de_telephone);
        strcpy(p.adresse, adresse);
        strcpy(p.groupe_sanguin, Groupe_sanguin);

        (*rep).liste[(*rep).nbPatients] = p; // kanhato lmrid fblasto 
        (*rep).nbPatients++; // kanzido lindex b 1 bach yb9a 4adi tasalsoul m9ad 
        
        
        printf("\n %s %s ajoute avec succes\n",prenom,nom);
        
        
    }





int main(){
    struct repertoire_de_patients rep ;
    rep.nbPatients = 0 ;
    Ajout_un_patient(&rep);
    return 0; 
  
  // saliti msah l comments wa5a manaf3in bwalo w5ali comment li wralk 


}
