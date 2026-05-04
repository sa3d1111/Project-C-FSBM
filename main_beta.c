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
void sauvegarderPatients(repertoire_de_patients *rep) {
    FILE *f = fopen("patients.txt", "w");//nom fichier patient.txt avec permission ta3e w liki te3ti l'acces writting
    if (!f) {
        printf("Erreur fichier.\n");
        return;
    }
    for (int i = 0; i < rep->nbPatients; i++) {
        fprintf(f, "%d;%s;%s;%02d/%02d/%d;%d;%s;%s\n",
                rep->liste[i].numero_de_dossier,
                rep->liste[i].nom,
                rep->liste[i].prenom,
                rep->liste[i].dateNaissance.jour,
                rep->liste[i].dateNaissance.mois,
                rep->liste[i].dateNaissance.annee,
                rep->liste[i].n_telephone,
                rep->liste[i].adresse,
                rep->liste[i].groupe_sanguin);
    }
    fclose(f);
    printf("Sauvegarde terminee.\n");
}
void chargerPatients(repertoire_de_patients *rep) {
    FILE *f = fopen("patients.txt", "r");
    if (f == NULL) {
        printf("Aucun fichier trouve.\n");
        return;
    }

    rep->nbPatients = 0;

    while (rep->nbPatients < MAX) {

        patient p;

        int res = fscanf(f,
            "%d;%49[^;];%49[^;];%d/%d/%d;%d;%99[^;];%9[^\n]\n",
            &p.numero_de_dossier,
            p.nom,
            p.prenom,
            &p.dateNaissance.jour,
            &p.dateNaissance.mois,
            &p.dateNaissance.annee,
            &p.n_telephone,
            p.adresse,
            p.groupe_sanguin
        );

        if (res == EOF) {
            break; 
        }

        if (res != 9) {
            printf("Ligne corrompue ignoree.\n");
        
            int c;
            while ((c = fgetc(f)) != '\n' && c != EOF);
            continue;
        }

        rep->liste[rep->nbPatients++] = p;
    }

    fclose(f);
    printf("Chargement termine (%d patients).\n", rep->nbPatients);
}
//Afficher le plus jeune ou le plus âgé des patients
    void Afficher_le_plus_jeune_st_le_plus_age(repertoire_de_patients *rep){

        int plus_jeune = 0;
        int plus_age = 0;

        for (int i = 1; i < rep->nbPatients; i++) {

            Date d = rep->liste[i].dateNaissance;

            Date d_jeune = rep->liste[plus_jeune].dateNaissance;
            Date d_age   = rep->liste[plus_age].dateNaissance;

        
            if (d.annee > d_jeune.annee ||
                (d.annee == d_jeune.annee && d.mois > d_jeune.mois) ||
                (d.annee == d_jeune.annee && d.mois == d_jeune.mois && d.jour > d_jeune.jour)) {

                plus_jeune = i;
            }

        
            if (d.annee < d_age.annee ||
                (d.annee == d_age.annee && d.mois < d_age.mois) ||
                (d.annee == d_age.annee && d.mois == d_age.mois && d.jour < d_age.jour)) 
            {

                plus_age = i;
            }
        }

        

        printf("\n    Plus jeune    \n");
        printf("Nom            : %s\n", rep->liste[plus_jeune].nom);
        printf("Prenom         : %s\n", rep->liste[plus_jeune].prenom);
        printf("Date naissance : %02d/%02d/%d\n",
            rep->liste[plus_jeune].dateNaissance.jour,
            rep->liste[plus_jeune].dateNaissance.mois,
            rep->liste[plus_jeune].dateNaissance.annee);
        printf("\n------------------------------------------\n");

        printf("\n    Plus age    \n");
        printf("Nom            : %s\n", rep->liste[plus_age].nom);
        printf("Prenom         : %s\n", rep->liste[plus_age].prenom);
        printf("Date naissance : %02d/%02d/%d\n",
            rep->liste[plus_age].dateNaissance.jour,
            rep->liste[plus_age].dateNaissance.mois,
            rep->liste[plus_age].dateNaissance.annee);
        }


int main(){
    repertoire_de_patients rep;
    rep.nbPatients = 0;

    int choix;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Ajouter patient\n");
        printf("2. Supprimer patient\n");
        printf("3. Modifier telephone\n");
        printf("4. Modifier adresse\n");
        printf("5. Rechercher par numero\n");
        printf("6. Rechercher par nom\n");
        printf("7. Afficher\n");
        printf("8. Trier\n");
        printf("9. Sauvegarder\n");
        printf("10. Charger\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch(choix){
            case 1: Ajout_un_patient(&rep); break;
            case 2: del_Patient(&rep); break;
            case 3: modifierTelephone(&rep); break;
            case 4: modifierAdresse(&rep); break;
            case 5: RecherchePar_N_Dossier(&rep); break;
            case 6: RecherchePar_Nom(&rep); break;
            case 7: affichage(&rep); break;
            case 8: trierPatients(&rep); break;
            case 9: sauvegarderPatients(&rep); break;
            case 10: chargerPatients(&rep); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide\n");
        }

    } while(choix != 0);

    return 0;
}
