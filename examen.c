#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

struct person
{
    int id;
    char fname[20];
    char lname[20];
};

typedef struct date{
    int jour;
    int month;
    int annee;
} date;

typedef struct ouvrage{
    int cote__;
    char titre;  
    int nombre_exemplaire_dans_la_bib;
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

    list_of_etudient[0].matricule = 1234;
    list_of_etudient[0].abonnement = 'e';
    list_of_etudient[0].pénalité = 2;

    FILE *ouvrage_file;
    FILE *etudient_file;
    FILE *emprunts_file;

    ouvrage_file = fopen("ouvrage_file.dat", "w");
    etudient_file = fopen("etudient_file.dat", "w");
    emprunts_file = fopen("emprunts_file.dat", "w");




    printf("\n\n                                              bienvenue dans votre programme \n");
    printf("=============================================================================================================================\n\n");
    printf("                                             !!comment nous pouvons t'aider!!\n\n");
    printf("1==>Ajouter des ouvrages \n");
    printf("2==>Consulter la liste de tous les ouvrages \n");
    printf("3==>Supprimer un ouvrage \n");
    printf("4==>Vérifier la disponibilité des exemplaires \n");
    printf("5==>Ajouter des étudiants \n");
    printf("6==>Consulter un membre \n");
    printf("7==>Supprimer un membre \n");
    printf("8==>Modifier un membre \n");
    printf("9==>Ajouter des emprunts \n");
    printf("10==>Consulter un emprunt \n");
    printf("11==>Supprimer un emprunt \n");
    printf("12==>Modifier un emprunt \n");
    printf("13==>Retourner un emprunt \n");
    printf("14==>Ajouter une pénalité \n");
    printf("15==>Supprimer une pénalité \n");
    printf("16==>Consulter la liste des pénalités \n");
    printf("17==>Définir la durée des emprunts \n");
    printf("18==>Définir le maximum d’ouvrage à emprunter \n");
    printf("19====Pour quitter le programme\n\n");


    FILE *outfile;
     
    // open file for writing
    outfile = fopen ("person.docs", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }
 
    struct person input1 = {1, "rohan", "sharma"};
    struct person input2 = {2, "mahendra", "dhoni"};
     
    // write struct to file
    fwrite (&input1, sizeof(struct person), 1, outfile);
    fwrite (&input2, sizeof(struct person), 1, outfile);
    
    if(&fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");

    // close file
    fclose (outfile);
 

    return 0;
}



