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

typedef struct ouvrage{
    int cote__;
    char titre[30];
    int nombre_ouvrage;
    int nombre_exemplaires_empruntés;
}ouvrage;

typedef struct etudient{
    int matricule;
    char abonnement; // P = Premium   or   C = classique
    int penalite;
}etudient;

typedef struct date{
    int jour;
    int month;
    int annee;
} date;

typedef struct emprunts_des_ouvrages {
    int matricule_de_etudiant;
    int cote_de_ouvrage_emprunté;
    date date_emprunt;
    date date_retour;
}emprunts_des_ouvrages;


void Ajouter_un_etudiant(etudient list_of_etudient[] , int size) {
    char f,m;
    int i;

    do{
        int flag=0;
        printf("\n\t\t\t\t Ajout d'un etudiant\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\tLe matricule d'etudiant  ");
        scanf("%d", &list_of_etudient[size].matricule);
        printf("\t~~~~~~~~~~~~~~~~");
        for(i=0; i>=size-1; i++){
            if(list_of_etudient[size].matricule==list_of_etudient[i].matricule){
                flag=1;
                break;
            }
        }

        if(flag==0){
            printf("\n\t preciser le type d'abonnement d'etudiant (p:pour le type premium || c:pour le type classic) ");
            scanf("%s", &list_of_etudient[size].abonnement);
            printf("\n\t entrer le nombre des penalites");
            scanf("%d", &list_of_etudient[size].penalite);
            size++;

            do{
                printf("\n voulez vous l'enregistrer : (y/n) ");
                scanf("%s", &m);
                if(m=='y'||m=='Y'){
                        printf("voulez vous un autre etudiant \n");
                        scanf("%s", &f);
                }
                else{
                    printf("\n s'il vous plait entre y ou Y pour enregistrer l'information");
                }
            }while(m=='n'||m=='N');
            
            if(flag!=0){
                printf("\n l'etudiant existe deja \n"); 
            }
        }
    }while(f=='y'||m=='Y');
}


void Ajouter_un_ouvrage(ouvrage list[1000], int *p){
    char f,m;
    int  i;
    int size = *p;
    do{    
        int flag=0;
        printf("\n Ajout d'un ouvrage\n");
        printf("titre: ");
        scanf("%s", list[size].titre);

        for( i=0; i>size; i++){
            if(list[size].titre==list[i].titre){
                flag=1;
                break;
            }
        }

        if(flag==0){
            printf("\n la cote ");
            scanf("%d", &list[size].cote__);
            printf("\n le nombre que voulez vous l'ajouter ");
            scanf("%d", &list[size].nombre_ouvrage);
            (*p)++;
            do{
                printf("\n\n voulez vous l'enregistrer : (y/n) ");
                scanf("%s", &m);
                if(m=='y'||m=='Y'){
                        printf("voulez vous un autre ouvrage");
                        scanf("%s", &f);
                }
                else{
                    printf("\n s'il vous plait entre y ou Y pour enregistrer l'information");
                }
            }while(m=='n'||m=='N');

            if(flag!=0){
                printf("\n l'ouvrage existe deja ");
            }
        }    
    }while(f=='y'||m=='Y');
}

void consulter_tous_ouvrages(ouvrage list[], int size){
    printf("\n\t List des ouvrages: \n");
    printf("   Titre d'ouvrage \t\t Cote \t\t Nombre des ouvrages \t\t ouvrages disponible ");
    for(int i=0; i<size; i++){
        printf("\n%d ==> %s \t\t\t %d \t\t\t %d \t\t\t %d ", i+1, list[i].titre, list[i].cote__, list[i].nombre_ouvrage, list[i].nombre_ouvrage-list[i].nombre_exemplaires_empruntés);
    }
}

int main(){

    int size=0;
    int *p = &size;
    ouvrage list_of_ouvrage[10000];
    etudient list_of_etudient[10000];
    emprunts_des_ouvrages list_of_emprunts[1000];


// test function 1:
//    Ajouter_un_etudiant(list_of_etudient , 2);
  //  printf("matricule: %d\n",list_of_etudient[2].matricule);
    //printf("abonnement: %c\n",list_of_etudient[2].abonnement);
   // printf("penality: %d\n",list_of_etudient[2].penalite);

// test function 2:
    Ajouter_un_ouvrage(list_of_ouvrage , &size);
    Ajouter_un_ouvrage(list_of_ouvrage , &size);
    Ajouter_un_ouvrage(list_of_ouvrage , &size);
printf("size =  %d",size);
    consulter_tous_ouvrages(list_of_ouvrage,size);

/*
    printf("cote: %d\n",list_of_ouvrage[2].cote__);
    printf("titre: %s\n",list_of_ouvrage[2].titre);
    printf("lib: %d\n",list_of_ouvrage[2].nombre_ouvrage);
    printf("no lib: %d\n",list_of_ouvrage[2].nombre_exemplaires_empruntés);
*/

/*
    printf("\n\n                                              bienvenue dans votre programme \n");
    printf("================================================================================================================\n\n");
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




*/

// example for write struct in file:

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



