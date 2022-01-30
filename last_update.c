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
    char titre[50];
    int nombre_ouvrage;
    int nombre_exemplaires_empruntés;
}ouvrage;

typedef struct etudient{
    char nom[50];
    char prenom [50];
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
    char cote_de_ouvrage_emprunte[50];
    date date_emprunt;
    date date_retour;
}emprunts_des_ouvrages;


                        // ================== help fuctions ===================== //
void lower_word(char word[]){
    int i = 0;
    while(word[i] != '\0'){
        if(word[i]>=65 && word[i]<=90){
            word[i]= word[i] + 32;
        }
        i++;
    }
}

                        // =================== function 1 ======================== //
void Ajouter_un_etudiant(etudient list[] , int *p) {
    char f,m;
    int size = *p, i;
    
    do{
        int flag=0;
        printf("\n\t Ajout d'un etudiant\n\t~~~~~~~~~~");
        printf("\n\tLe matricule d'etudiant  ");
        scanf("%d", &list[size].matricule);

        for(i=0; i<size; i++){
            if(list[size].matricule==list[i].matricule){
                flag=1;
                break;
            }
        }

        if(flag==0){
            printf("\n\t entrer le nom de member: ");
            scanf("%s", list[size].nom);
            printf("\n\t entrer le prenom de member: ");
            scanf("%s", list[size].prenom);
            printf("\n\t preciser le type d'abonnement d'etudiant (p:pour le type premium || c:pour le type classic): ");
            scanf("%s", &list[size].abonnement);
            list[size].penalite =0 ;     // <<=============================   normalement = NULL

            if(list[size].abonnement == 'c' || list[size].abonnement == 'C'){
                printf("\n\t entrer le nombre des penalites: ");
                scanf("%d", &list[size].penalite);
            }
            (*p)++;

            do{
                printf("\n voulez vous l'enregistrer : (y/n) ");
                scanf("%s", &m);
                if(m=='y'||m=='Y'){
                        printf("voulez vous un autre etudiant: ");
                        scanf("%s", &f);
                }
                else{
                    printf("\n s'il vous plait entre y ou Y pour enregistrer l'information");
                }
            }while(m=='n'||m=='N');
            
        }
        else if(flag!=0){
            printf("\n l'etudiant existe deja \n"); 
            f = 'n';
        }

    }while(f=='y'||m=='Y');
}


                        // =================== function 2 ======================== //
void Ajouter_un_ouvrage(ouvrage list[1000], int *p){
    char f,m;
    int  i;
    int size = *p;
    do{    
        int flag=0;
        printf("\n Ajout d'un ouvrage\n");
        printf("titre: ");
        scanf("%s", list[size].titre);

        for( i=0; i<size; i++){
            if(strcmp(list[size].titre, list[i].titre)==0){
                flag=1;
                printf("\nil existe\n");
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
                        printf("voulez vous un autre ouvrage: ");
                        scanf("%s", &f);
                }
                else{
                    printf("\n s'il vous plait entre y ou Y pour enregistrer l'information");
                }
            }while(m=='n'||m=='N');
        }    

        else if(flag!=0){
            printf("\n l'ouvrage existe deja ");
        }
    }while(f=='y'||m=='Y');
}


                        // =================== function 4 ======================== //
void Ajouter_penalite(etudient list[], int size){
    int matricule, flag=0, i;

    printf("\n\t matricule de member: \n");
    scanf("%d",&matricule);

    for(i=0; i<size; i++){
        if(matricule == list[i].matricule){
            list[i].penalite --;
            flag = 1;
            break;
        }
    }
    if(flag==1){
        printf("on ajouter un penalite pour l'etudient: %s %s. le neveau penelite est %d \n",list[i].nom, list[i].prenom, list[i].penalite );
    }

    else if(flag==0){
        printf("l'etudient n'exist pas\n");
    }
}


                        // =================== function 5 ======================== //
void consulter_tous_ouvrages(ouvrage list[], int size){
    printf("\n\t List des ouvrages: \n");
    printf("   Titre d'ouvrage \t\t Cote \t\t Nombre des ouvrages \t\t ouvrages disponible ");
    for(int i=0; i<size; i++){
        printf("\n%d ==> %s \t\t\t %d \t\t\t %d \t\t\t %d ", i+1, list[i].titre, list[i].cote__, list[i].nombre_ouvrage, list[i].nombre_ouvrage-list[i].nombre_exemplaires_empruntés);
    }
}



                        // =================== function 6 ======================== //
void consulter_un_member(etudient list[], int size){
    int matricule, flag=0;

    printf("\n\t matricule de member: \n");
    scanf("%d",&matricule);

    for(int i=0; i<size; i++){
        if(matricule == list[i].matricule){
            printf("nom:%s \nprenom:%s \nmatricule:%d \n abonnement:%c \npenalite:%d\n\n",list[i].nom ,list[i].prenom, list[i].matricule ,list[i].abonnement, list[i].penalite);
            flag = 1;
        }
    }
    if(flag==0){
        printf("l'etudient n'exist pas\n");
    }
}



                        // =================== function 8 ======================== //
void consulter_list_des_penalites(etudient list[], int size){
    printf("\n\t List des penalites: \n");
    printf(" matricule        penalite :\n");
    for(int i=0; i<size; i++){
        printf("%d   =====>   %d \n", list[i].matricule, list[i].penalite);
    }
}


                        // =================== function 9 ======================== //
void verifier_dispo_de_ouvrage(ouvrage list[], int *p){
    int size = *p, flag=0, i;
    char sup_ouvrage[50];

    printf("\n\ninput your book title: ");
    scanf("%s", sup_ouvrage);
    lower_word(sup_ouvrage);

    for(i=0; i<=size-1; i++){
            if(strcmp(list[i].titre,sup_ouvrage)==0){
                flag=1;
                break;
            }
    }

    if(flag == 1){
        printf("\noui, ce ouvrege exist.\n");
    }
    else if(flag==0){
        printf("\n ce ouvrege n'exist pas.\n");
    }


}



                        // =================== function 10 ======================== //
void suppprimer_ouvrage(ouvrage list[], int *p){
    int size = *p, flag=0, i;
    char sup_ouvrage[50];

    printf("\n\ninput your book title: ");
    scanf("%s", sup_ouvrage);

    for(i=0; i<=size-1; i++){
            if(strcmp(list[i].titre,sup_ouvrage)==0){
                flag=1;
                break;
            }
    }

    if(flag == 1){
        while(i<size){
            list[i] = list[i+1];
            i++;
        }
        (*p)--;
        printf("OK\n");
    }
    else if(flag==0){
        printf("\n ce ouvrege n'exist pas.\n");
    }
}


                        // =================== function 11 ======================== //
void suppprimer_member(etudient list[1000], int *p){
    int size = *p, flag=0, i;
    int sup_etudient;

    printf("\n\ninput your etudient matricule: ");
    scanf("%d", &sup_etudient);

    for(i=0; i<=size-1; i++){
            if(list[i].matricule == sup_etudient){
                flag=1;
                break;
            }
    }

    if(flag == 1){
        while(i<size){
            list[i] = list[i+1];
            i++;
        }
        (*p)--;
        printf("OK\n");
    }
    else if(flag==0){
        printf("\n ce etudient n'exist pas.\n");
    }
}



                        // =================== function 12 ======================== //
void suppprimer_emprunts(emprunts_des_ouvrages list[], int *p){
    int size = *p, flag=0, i;
    int sup_etudient;

    printf("\n\ninput your etudient matricule: ");
    scanf("%d", &sup_etudient);

    for(i=0; i<=size-1; i++){
            if(list[i].matricule_de_etudiant == sup_etudient){
                flag=1;
                break;
            }
    }

    if(flag == 1){
        while(i<size){
            list[i] = list[i+1];
            i++;
        }
        (*p)--;
        printf("OK\n");
    }
    else if(flag==0){
        printf("\n ce etudient n'exist pas.\n");
    }
}


                        // =================== function 13 ======================== //
void suppprimer_penalite(etudient list[], int *p){
    int size = *p, flag=0, i;
    int sup_etudient;

    printf("\n\ninput your etudient matricule: ");
    scanf("%d", &sup_etudient);

    for(i=0; i<=size-1; i++){
            if(list[i].matricule == sup_etudient){
                list[i].penalite = 0;
                flag=1;
                break;
            }
    }

    if(flag==0){
        printf("\n ce etudient n'exist pas.\n");
    }
}



                        // =================== function 14 ======================== //
void modifier_member(etudient list[], int *p){
    int size = *p, flag=0, answer, i;
    int modifier_etudient;

    printf("\n\ninput your etudient matricule: ");
    scanf("%d", &modifier_etudient);

    for(i=0; i<=size-1; i++){
            if(list[i].matricule == modifier_etudient){
                printf("nom: %s \nprenom: %s \nmatricule: %d \n abonnement: %c \npenalite: %d\n\n",list[i].nom ,list[i].prenom, list[i].matricule ,list[i].abonnement, list[i].penalite);            
                printf("you would like to change: \n");
                printf("1=>nom \n2=>prenom \n3=>matricule \n4=>abonnement \n5=>npenalite \n");
                scanf("%d",&answer);
                
                switch(answer){
                    case 1 : 
                        printf("print new nom: ");
                        scanf("%s",list[i].nom);
                    case 2 :
                        printf("print new prenom: ");
                        scanf("%s",list[i].prenom);
                    case 3 :
                        printf("print new matricule: ");
                        scanf("%d",&list[i].matricule);
                    case 4 :
                        printf("print new abonnement: ");
                        scanf("%c",&list[i].abonnement);
                    case 5 :
                        printf("print new penalite: ");
                        scanf("%d",&list[i].penalite);
                    default: printf("your answer is not correct\n");
                }
                flag=1;
                break;
            }
    }

    if(flag==0){
        printf("\n ce etudient n'exist pas.\n");
    }
}


                        // =================== function 15 ======================== //
void modifier_emprunt(emprunts_des_ouvrages list[], int *p){
    int size = *p, flag=0, answer, i;
    int modifier_emp;

    printf("\n\ninput your etudient matricule: ");
    scanf("%d", &modifier_emp);

    for(i=0; i<=size-1; i++){
            if(list[i].matricule_de_etudiant == modifier_emp){
                printf("matricule_de_etudiant: %d \ncote_de_ouvrage_emprunte: %s \n date emprunt: %d/%d/%d \n date retour: %d/%d/%d \n\n",list[i].matricule_de_etudiant   ,list[i].cote_de_ouvrage_emprunte,          list[i].date_emprunt.jour, list[i].date_emprunt.month, list[i].date_emprunt.annee,       list[i].date_retour.jour, list[i].date_retour.month, list[i].date_retour.annee);
                printf("you would like to change: \n");
                printf("1=>matricule de etudiant \n2=>cote_de_ouvrage_emprunte \n3=>date_emprunt \n4=>date_retour\n");
                scanf("%d",&answer);
                
                switch(answer){
                    case 1 : 
                        printf("print new matricule de etudiant: ");
                        scanf("%d",&list[i].matricule_de_etudiant);
                    case 2 :
                        printf("print new cote_de_ouvrage_emprunte: ");
                        scanf("%s",list[i].cote_de_ouvrage_emprunte);
                    case 3 :
                        printf("print new date_emprunt: ");
                        printf("jour: ");
                        scanf("%d",&list[i].date_emprunt.jour);
                        printf("month: ");
                        scanf("%d",&list[i].date_emprunt.month);
                        printf("annee: ");
                        scanf("%d",&list[i].date_emprunt.annee);

                    case 4 :
                        printf("print new date retour: ");
                        printf("jour: ");
                        scanf("%d",&list[i].date_retour.jour);
                        printf("month: ");
                        scanf("%d",&list[i].date_retour.month);
                        printf("annee: ");
                        scanf("%d",&list[i].date_retour.annee);

                    default: printf("your answer is not correct\n");
                }
                flag=1;
                break;
            }
    }

    if(flag==0){
        printf("\n ce emprunt n'exist pas.\n");
    }
}



 // =================== test function  ======================== //
void consulter_tout_members(etudient list[], int size){
    for(int i=0; i<size; i++){
        printf("nom:%s \nprenom:%s \nmatricule:%d \n abonnement:%c \npenalite:%d\n\n",list[i].nom ,list[i].prenom, list[i].matricule ,list[i].abonnement, list[i].penalite);    
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
printf("\nsize =  %d\n",size);
    verifier_dispo_de_ouvrage(list_of_ouvrage , &size);
    verifier_dispo_de_ouvrage(list_of_ouvrage , &size);
    consulter_tous_ouvrages(list_of_ouvrage,size);

    suppprimer_ouvrage(list_of_ouvrage , &size);

    consulter_tous_ouvrages(list_of_ouvrage,size);

//printf("\n%d\n",strcmp("asdf","asdsf"));


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
    printf("2==>Ajouter des étudiants \n");
    printf("3==>Ajouter des emprunts \n");
    printf("4==>Ajouter une pénalité \n");

    printf("5==>Consulter la liste de tous les ouvrages \n");
    printf("6==>Consulter un membre \n");
    printf("7==>Consulter un emprunt \n");
    printf("8==>Consulter la liste des pénalités \n");
    
    printf("9==>Vérifier la disponibilité des exemplaires \n");
    
    printf("10==>Supprimer un ouvrage \n");
    printf("11==>Supprimer un membre \n");
    printf("12==>Supprimer un emprunt \n");
    printf("13==>Supprimer une pénalité \n");
    
    printf("14==>Modifier un membre \n");
    printf("15==>Modifier un emprunt \n");
    
    printf("16==>Définir la durée des emprunts \n");
    printf("17==>Définir le maximum d’ouvrage à emprunter \n");

    printf("18==>Retourner un emprunt \n");

    printf("19====Pour quitter le programme\n\n");


*/

// example for write struct in file:
/*
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
*/ 

    return 0;
}



