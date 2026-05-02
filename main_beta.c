#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
    typedef struct
    {
        int jour, mois, annee ;
    }Date;
    typedef struct
    {
        char nom[50];
        char prenom[50];
        int n_telephone;
        Date dateNaissance;
        int numero_de_dossier;
        char adresse[100];
        char groupe_sanguin[10];
    }patient;
    typedef struct
    {
        patient liste[MAX];
        int nbPatients;
    }repertoire_de_patients;



    void Ajout_un_patient( repertoire_de_patients *rep){
        int numero_de_dossier,jour, mois, annee,n;
        char nom[50], prenom[50], adresse[100], Groupe_sanguin[10]; int tel;

        patient p;
        do {
           printf("Saisir Le nombre de patients : ");
           scanf("%d",&n);
          }while(n<=0);
        for(int i=0;i<n;i++) {
           if (rep->nbPatients >= MAX){
              printf("\nVous avez atteint le Max Des Patients !\n");
           }
           printf("Entrez votre Numero de dossier: ");
           scanf("%d",&numero_de_dossier);

           printf("\nEntrez votre Nom: ");
           scanf("%s",nom);

           printf("\nEntrez votre Prenom: ");
           scanf("%s",prenom);

           printf("\nEntrez votre Date de naissance (JJ/MM/AAAA) : ");
           scanf("%d/%d/%d",&jour, &mois, &annee);

           printf("\nEntrez votre Numero de telephone: ");
           scanf("%d",&tel);
           printf("\nEntrez votre Adresse: ");
           getchar();
           fgets(adresse, sizeof(adresse), stdin);
           adresse[strcspn(adresse, "\n")] = 0;
           printf("\nEntrez votre Groupe sanguin: ");
           scanf("%s",Groupe_sanguin);
           p.numero_de_dossier = numero_de_dossier;
           strcpy(p.nom, nom);
           strcpy(p.prenom, prenom);
           p.dateNaissance.jour = jour;
           p.dateNaissance.mois = mois;
           p.dateNaissance.annee = annee;
           p.n_telephone = tel;
           strcpy(p.adresse, adresse);
           strcpy(p.groupe_sanguin, Groupe_sanguin);
           rep->liste[rep->nbPatients] = p;
           rep->nbPatients++;
           printf("\n%s %s ajoute avec succes\n",prenom,nom);
    }
  }
    void RecherchePar_N_Dossier(repertoire_de_patients *rep ){
        int n_dossier,tv=0;
        printf("saisir le numero de dossier : ");
        scanf("%d",&n_dossier);
        for(int i=0;i<rep->nbPatients;i++){
            if(n_dossier == rep->liste[i].numero_de_dossier){
                printf("\nPatient Trouve ! \n");
                tv ++;
                break;            }
        }
        if (tv == 0){
            printf("Ce dossier n'existe pas !");
        }
    }
    void RecherchePar_Nom(repertoire_de_patients *rep){
        int tv = 0;char nom[50];
        printf("Saisir le nom du patient : ");
        scanf("%s",nom);
        for (int i=0;i<rep->nbPatients;i++){
            if(strcmp(nom,rep->liste[i].nom) == 0) printf("\nPatient %s Trouve ! \n",nom); tv ++; break;
        }
        if (tv == 0){
            printf("Ce Nom n'existe pas !");

        }
    }
    void del_Patient(repertoire_de_patients *rep){
           int indice_supp = -1,n_dossier;
           printf("saisir le numero de dossier : ");
           scanf("%d",&n_dossier);
           for(int i=0;i<rep->nbPatients;i++){
              if(n_dossier == rep->liste[i].numero_de_dossier){
                   indice_supp = i;
                   break;
            }
        }

           if (indice_supp != -1) {
               rep->liste[indice_supp] = rep->liste[rep->nbPatients - 1];
               rep->nbPatients--;
               printf("\nPatient supprime avec succes !\n");
           }
           else {
               printf("\nCe dossier n'existe pas ! Impossible de supprimer.\n");
    }
}
    void modifierTelephone(repertoire_de_patients *rep) {
        int numDossierRecherche, trouve = 0;

        printf("Saisir le numero de dossier pour modification telephone : ");
        scanf("%d", &numDossierRecherche);

        for (int i = 0; i < rep->nbPatients; i++) {
            if (rep->liste[i].numero_de_dossier == numDossierRecherche) {
               printf("Ancien telephone : %d\n", rep->liste[i].n_telephone);

               printf("Entrez le nouveau numero : ");
               scanf("%d", &rep->liste[i].n_telephone);

               printf("Modification enregistree avec succes !\n");
               trouve = 1;
               break;
        }
    }
    if (trouve == 0) printf("Ce telephone n'existe pas ! %d.\n", numDossierRecherche);
}

    void modifierAdresse(repertoire_de_patients *rep) {
        int numDossierRecherche, trouve = 0;

        printf("Saisir le numero de dossier pour modification adresse : ");
        scanf("%d", &numDossierRecherche);

        for (int i = 0; i < rep->nbPatients; i++) {
            if (rep->liste[i].numero_de_dossier == numDossierRecherche) {
                printf("Ancienne adresse : %s\n", rep->liste[i].adresse);

                printf("Entrez la nouvelle adresse : ");
                getchar();
                fgets(rep->liste[i].adresse, 100, stdin);
                rep->liste[i].adresse[strcspn(rep->liste[i].adresse, "\n")] = 0;

               printf("Adresse mise a jour !\n");
               trouve = 1;
               break;
        }
    }
    if (trouve != 0) printf("Adresse introuvable.\n");
}

    void trierPatients(repertoire_de_patients *rep) {

        patient temp;

        for (int i = 0; i < rep->nbPatients - 1; i++) {
             for (int j = 0; j < rep->nbPatients - i - 1; j++) {
                if (strcmp(rep->liste[j].nom, rep->liste[j+1].nom) > 0) {
                   temp = rep->liste[j];
                   rep->liste[j] = rep->liste[j+1];
                   rep->liste[j+1] = temp;
            }
        }
    }
    printf("Liste des patients triee par nom avec succes.\n");
}
    void affichage(repertoire_de_patients *rep){
       printf("| %-15s | %-15s | %-13s | %-31s |\n", "Nom", "Prenom", "Telephone", "Adresse");
       for(int i=0;i<rep->nbPatients;i++){
        printf("%.10s | %.10s | %.10d | %.10s",rep->liste[i].nom,rep->liste[i].prenom,rep->liste[i].n_telephone,rep->liste[i].adresse);
        printf("\n");
       }
    }

int main(){
    repertoire_de_patients  rep;
    int dossier = 0;
    rep.nbPatients = 0 ;
    Ajout_un_patient(&rep);
    del_Patient(&rep);
    modifierTelephone(&rep);
    modifierAdresse(&rep);
    affichage(&rep);
    trierPatients(&rep);
    affichage(&rep);
    return 0;
}
