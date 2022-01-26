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




void Ajouter_un_ouvrage(ouvrage list[1000]){
    char f,p;
    int  i;
    do{
        system("cls");
    int flag=0;
    printf("\n\n\n\n\n\n\n Ajout d'ouvrage \n\n\n\n\n\n\n");
    printf("\n\n\n titre: \n\n\n");
    scanf("%s", &ouvrage[size].titre);
            for( i=0; i=size-1; i++){
                if(ouvrage[size].titre==ouvrage[i].titre){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                printf("\n\n la cote ");
                scanf("%l", &ouvrage[size].cote);
                printf("\n\n le nombre que voulez vous l'ajouter ");
                scanf("%c", &ouvrage[size].nbe_bib);
                ++size;
                do{
                    printf("\n\n voulez vous l'enregistrer : (y/n) ");
                    scanf("%s", &m);
                    if(m=='y'||m=='Y'){
                            printf("voulez vous un autre ouvrage");
                            scanf("%s", &f);


                    }
                    else{
                        printf("\n s'il vous plait entre y ou Y pour enregistrer vous information");

                    }
                    while(m=='n'||m=='N');
                }
                 if(flag!=0){
                    printf("\n l'ouvrage existe deja ");
                    getch();
                }
            }while(f=='y'||m=='Y');



    }
}



void consulter la liste de tout les ouvrages (){
    int i;
    printf("\n\n\t\t\t\t\t List des ouvrages \n\t\t\t\t\t~~~~~~~~~~~~~~~~\n\nTitre d'ouvrage\t\t\tCote\t\t\tNombre des ouvrages");
    for(i=0; i<size; i++){
        printf("\n\n %d  %s     \t\t\t%s    \t\t\t%d    \n          \t\t\tStatus: nombre des ouvrages disponible : %d ", ouvrage[i].titre,ouvrage[i].cote,ouvrage[i].nbe_bib,ouvrage[i].nbe_empruntes-ouvrage[i].nbe_empruntes);
        printf("\n");
    }
    getch()
}



int main(){
    int n;

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
    printf("===================================================================================================================================================================================================================\n\n");
    printf("                                             !!comment nous pouvons t'aider!!\n\n");
    printf("01 ==> Ajouter des ouvrages \n");
    printf("02 ==> Consulter la liste de tous les ouvrages \n");
    printf("03 ==> Supprimer un ouvrage \n");
    printf("04 ==> Verifier la disponibilite des exemplaires \n");
    printf("05 ==> Ajouter des etudiants \n");
    printf("06 ==> Consulter un membre \n");
    printf("07 ==> Supprimer un membre \n");
    printf("08 ==> Modifier un membre \n");
    printf("09 ==> Ajouter des emprunts \n");
    printf("10 ==> Consulter un emprunt \n");
    printf("11 ==> Supprimer un emprunt \n");
    printf("12 ==> Modifier un emprunt \n");
    printf("13 ==> Retourner un emprunt \n");
    printf("14 ==> Ajouter une penalite \n");
    printf("15 ==> Supprimer une penalite \n");
    printf("16 ==> Consulter la liste des penalites \n");
    printf("17 ==> Definir la duree des empruntes \n");
    printf("18 ==> Definir le maximum d’ouvrage a emprunter \n");
    printf("19 ==> Pour quitter le programme\n\n");

    scanf("%d", &n);

    while(n==19){

            switch(n){

                    case 1 : ;
                        break;
                    case 2 : ;
                        break;
                    case 3 : ;
                        break;
                    case 4 : ;
                        break;
                    case 5 : ;
                        break;
                    case 6 : ;
                        break;
                    case 7 : ;
                        break;
                    case 8 : ;
                        break;
                    case 9 : ;
                        break;
                    case 10 : ;
                        break;
                    case 11: ;
                        break;
                    case 12 : ;
                        break;
                    case 13 : ;
                        break;
                    case 14 : ;
                        break;
                    case 15 : ;
                        break;
                    case 16 : ;
                        break;
                    case 17 : ;
                        break;
                    case 18 : ;
                        break;
                    case 19 : ;
                        break;


            }
    }

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



