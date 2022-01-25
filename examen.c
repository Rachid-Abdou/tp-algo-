#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

typedef struct date{
    int jour;
    int month;
    int annee;
} date;

typedef struct ouvrage{
    int cote__;
    char titre;  
    int nombre_exemplaire_dans_la_bibliothèque;
    int nombre_exemplaires_empruntés;
}ouvrage;

typedef struct etudient{
    int matricule;
    char abonnement; // P = Premium   or   C = classique
    int pénalité;
}etudient;

typedef struct emprunts_des_ouvrages {
    int matricule_de_étudiant;
    int cote_de_ouvrage_emprunté;
    date date_emprunt;
    date date_retour;
}emprunts_des_ouvrages;


void Ajouter_un_étudiants(etudient list[]){
    
}



int main(){

    etudient list_of_etudient[10000];

    list_of_etudient[0].matricule = 123;
    list_of_etudient[0].abonnement = 'e';
    list_of_etudient[0].pénalité = 2;


    return 0;
}



