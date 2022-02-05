#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>


void summm(int *p){
    (*p) ++;
    printf("%d",*p);
}


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

void consulter_tous_etudients(etudient list[], int size){
    printf("\n\t List des etudents: \n");
    printf(" nom:   ||  prenom: || matricule: || abonnement: || penalite:\n");
    for(int i=0; i<size; i++){
        printf("%d ==> %s || %s    || %d || \t %c || \t %d \n", i+1,list[i].nom ,list[i].prenom, list[i].matricule ,list[i].abonnement, list[i].penalite);
    }
}


                        // =================== function 1 ======================== //
void Ajouter_un_ouvrage(ouvrage list[], int *pp){
    char f;
    int  i, flag;

        flag=0;
        printf("\n========= Ajout d'un ouvrage ==========\n");
        printf("titre: ");
        scanf("%s", list[*pp].titre);

        for( i=0; i<*pp; i++){
            if(strcmp(list[*pp].titre, list[i].titre)==0){
                flag=1;
                printf("il existe\n");
                break;
            }
        }

        if(flag==0){
            printf("la cote ");
            scanf("%d", &list[*pp].cote__);
            printf("le nombre que voulez vous l'ajouter ");
            scanf("%d", &list[*pp].nombre_ouvrage);
            list[*pp].nombre_exemplaires_empruntés = 0;  
            (*pp)++; 
        }    

        else if(flag!=0){
            printf(" l'ouvrage existe deja\n ");
        }

        printf("voulez vous l'enregistrer : (y/n) ");
        scanf("%c", &f);
}

                        // =================== function 2 ======================== //
void Ajouter_un_etudiant(etudient list[] , int *p) {
    char f;
    int size = *p , i;
    int flag;
    int *null = NULL;
    
        flag=0;
        printf("\n=========== Ajout d'un etudiant ===========\n\n");
        printf("Le matricule d'etudiant  ");
        scanf("%d", &list[size].matricule);

        for(i=0; i<size; i++){
            if(list[size].matricule==list[i].matricule){
                flag=1;
                break;
            }
        }

        if(flag==0){
            printf("entrer le nom de member: ");
            scanf("%s", list[size].nom);
            printf("entrer le prenom de member: ");
            scanf("%s", list[size].prenom);
            printf("preciser le type d'abonnement d'etudiant (p:pour le type premium || c:pour le type classic): ");
            scanf("%s", &list[size].abonnement);
            list[size].penalite = 0;     // <<=============================   normalement = NULL

            if(list[size].abonnement == 'c' || list[size].abonnement == 'C'){
                printf("entrer le nombre des penalites: ");
                scanf("%d", &list[size].penalite);
            }     
            (*p)++;
        }

        else if(flag!=0){
            printf("l'etudiant existe deja \n"); 
        }

        //printf("voulez vous l'enregistrer : (y/n) ");
        //scanf("%s", &f);

}





                        // =================== function 3 ======================== //
void Ajouter_emprunt(etudient list_etud[], ouvrage list_ouvrage[], emprunts_des_ouvrages list_empr[] , int size_etud , int size_ouvr  , int *p){
    int f, i, etud_mat, flag_etud=0, flag_ouvr=0 , size = *p;
    char empru_titre[50];

    printf("\n ================ Ajout un emprunt d'ouvrages ============\n");
        
    printf("matricule d'etudient: ");
    scanf("%d",&etud_mat);

    for(i=0; i<size_etud; i++){
        if(list_etud[i].matricule == etud_mat && list_etud[i].penalite <= 7 ){
            flag_etud = 1;
            printf("il existe\n");
            break;
        }
    }
        
    printf("titre d'ouvrage: ");
    scanf("%s",empru_titre);

    for(f=0; f<=size_ouvr; f++){
        if(strcmp(empru_titre, list_ouvrage[f].titre)==0 && list_ouvrage[f].nombre_ouvrage > list_ouvrage[f].nombre_exemplaires_empruntés ){ 
            flag_ouvr = 1;
            printf("il existe\n");
            break;
        }
    }


    if(flag_ouvr==1 && flag_etud==1){

        list_empr[size].matricule_de_etudiant = etud_mat;
        strcpy(list_empr[size].cote_de_ouvrage_emprunte, empru_titre);

        printf("print new date_emprunt: ");
        printf("jour: ");
        scanf("%d",&list_empr[size].date_emprunt.jour);
        printf("month: ");
        scanf("%d",&list_empr[size].date_emprunt.month);
        printf("annee: ");
        scanf("%d",&list_empr[size].date_emprunt.annee);

        printf("print new date retour: ");
        printf("jour: ");
        scanf("%d",&list_empr[size].date_retour.jour);
        printf("month: ");
        scanf("%d",&list_empr[size].date_retour.month);
        printf("annee: ");
        scanf("%d",&list_empr[size].date_retour.annee);

        list_ouvrage[f].nombre_exemplaires_empruntés ++;
        (*p)++; 
    }

    else if(flag_ouvr==0 && flag_etud==1){
        printf("\n ce ouvrage est Indisponible ");
    }

    else if(flag_ouvr==0 && flag_etud==1){
        printf("\n le penalite est > 7 ");
    }

    else if(flag_ouvr==0 && flag_etud==0){
        printf("\nce ouvrage est Indisponible, et le penalite est > 7. \n");
    }
}




                        // =================== function 4 ======================== //
void Ajouter_penalite(etudient list[], int size){
    int matricule, flag=0, i;
    printf("\n============ Ajouter penalite ============= \n");
    
    printf("matricule de member: ");
    scanf("%d",&matricule);

    for(i=0; i<size; i++){
        if(matricule == list[i].matricule){
            list[i].penalite ++;
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
    printf("\n============ consulter tous ouvrages ============= \n");

    printf("List des ouvrages: \n");
    printf("   Titre d'ouvrage \t\t Cote \t\t Nombre des ouvrages \t\t ouvrages disponible \n");
    int i=0;
    for(i=0; i<size; i++){
        printf("%d ==> %s \t\t\t %d \t\t\t %d \t\t\t %d \n", i+1, list[i].titre, list[i].cote__, list[i].nombre_ouvrage, list[i].nombre_ouvrage-list[i].nombre_exemplaires_empruntés);
    }
}



                        // =================== function 6 ======================== //
void consulter_un_member(etudient list[], int size){
    int matricule, flag=0;
    printf("\n============ consulter un member ============= \n");
    
    printf("matricule de member: ");
    scanf("%d",&matricule);

    for(int i=0; i<size; i++){
        if(matricule == list[i].matricule){
            printf("nom:%s \nprenom:%s \nmatricule:%d \n abonnement:%c \npenalite:%d\n",list[i].nom ,list[i].prenom, list[i].matricule ,list[i].abonnement, list[i].penalite);
            flag = 1;
        }
    }
    if(flag==0){
        printf("l'etudient n'exist pas\n");
    }
}


                        // =================== function 7 ======================== //
void consulter_emprunt(emprunts_des_ouvrages list_emp[], int size_emp){
    int matricule, flag=0;
    printf("\n========= consulter emprunt ==========\n");
    printf("matricule de member: ");
    scanf("%d",&matricule);

    for(int i=0; i<size_emp; i++){
        if(matricule == list_emp[i].matricule_de_etudiant){
            printf("matricule_de_etudiant:%d \ncote_de_ouvrage_emprunte:%s \ndate_emprunt:%d/%d/%d \ndate_retour:%d/%d/%d \n\n",list_emp[i].matricule_de_etudiant ,list_emp[i].cote_de_ouvrage_emprunte     , list_emp[i].date_emprunt.jour ,list_emp[i].date_emprunt.month, list_emp[i].date_emprunt.annee,           list_emp[i].date_retour.jour ,list_emp[i].date_retour.month, list_emp[i].date_retour.annee );
            flag = 1;
        }
    }
    if(flag==0){
        printf("l'etudient n'exist pas\n");
    }
    
}


                        // =================== function 8 ======================== //
void consulter_list_des_penalites(etudient list[], int size){
    printf("\n========= consulter list des penalites ==========\n");
    printf("List des penalites: \n");
    printf(" matricule    penalite :\n");
    for(int i=0; i<size; i++){
        printf("%d   =====>   %d \n", list[i].matricule, list[i].penalite);
    }
}


                        // =================== function 9 ======================== //
void verifier_dispo_de_ouvrage(ouvrage list[], int *p){
    int size = *p, flag=0, i;
    char sup_ouvr[50];

    printf("\n========= verifier dispo de ouvrage ==========\n");
    printf("input your book title: ");
    scanf("%s", sup_ouvr);
    lower_word(sup_ouvr);

    for(i=0; i<=size-1; i++){
            if(strcmp(list[i].titre, sup_ouvr)==0 && list[i].nombre_ouvrage > list[i].nombre_exemplaires_empruntés){
                flag=1;
                break;
            }
            else if(strcmp(list[i].titre,sup_ouvr)==0 && list[i].nombre_ouvrage <= list[i].nombre_exemplaires_empruntés){
                flag=-1;
                break;
            }
    }

    if(flag == 1){
        printf("oui, ce ouvrege est disponible.\n");
    }
    else if(flag==-1){
        printf("ce ouvrege n'est pas disponible.\n");
    }
    else if(flag==0){
        printf("ce ouvrege n'exist pas.\n");
    }
}



                        // =================== function 10 ======================== //
void suppprimer_ouvrage(ouvrage list[], int *p){
    int size = *p, flag=0, i;
    char sup_ouvr[50];

    printf("\n========= suppprimer ouvrage ==========\n");
    printf("input your book title: ");
    scanf("%s", sup_ouvr);

    for(i=0; i<=size-1; i++){
            if(strcmp(list[i].titre,sup_ouvr)==0){
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
void suppprimer_member(etudient list[], int *p){
    int size = *p, flag=0, i;
    int sup_etudient;
    printf("\n========= suppprimer_member ==========\n");
    printf("input your etudient matricule: ");
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
        printf("ce etudient n'exist pas.\n");
    }
}



                        // =================== function 12 ======================== //
void suppprimer_emprunts(emprunts_des_ouvrages list[], int *p){
    int size = *p, flag=0, i;
    int sup_etudient;

    printf("\n========= suppprimer emprunts ==========\n");
    printf("input your etudient matricule: ");
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
        printf("ce etudient n'exist pas.\n");
    }
}


                        // =================== function 13 ======================== //
void suppprimer_penalite(etudient list[], int *p){
    int size = *p, flag=0, i;
    int sup_etudient;

    printf("\n========= suppprimer penalite ==========\n");
    printf("input your etudient matricule: ");
    scanf("%d", &sup_etudient);

    for(i=0; i<=size-1; i++){
            if(list[i].matricule == sup_etudient){
                list[i].penalite = 0;
                flag=1;
                break;
            }
    }

    if(flag==0){
        printf("ce etudient n'exist pas.\n");
    }
}



                        // =================== function 14 ======================== //
void modifier_member(etudient list[], int *p){
    int size = *p, flag=0, answer, i, con=1;
    int modifier_etudient;

    printf("\n========= modifier_member ==========\n");
    printf("input your etudient matricule: ");
    scanf("%d", &modifier_etudient);

    for(i=0; i<size; i++){
            if(list[i].matricule == modifier_etudient){
                printf("nom: %s \nprenom: %s \nmatricule: %d \n abonnement: %c \npenalite: %d\n",list[i].nom ,list[i].prenom, list[i].matricule ,list[i].abonnement, list[i].penalite);            
                printf("you would like to change: \n");
                
                while (con == 1){
                    printf("1=>nom \n2=>prenom \n3=>matricule \n4=>abonnement \n5=>npenalite \n");
                    scanf("%d",&answer);
                    switch(answer){
                        case 1 : 
                            printf("print new nom: ");
                            scanf(" %s",list[i].nom);
                            break;
                        case 2 :
                            printf("print new prenom: ");
                            scanf(" %s",list[i].prenom);
                            break;
                        case 3 :
                            printf("print new matricule: ");
                            scanf("%d",&list[i].matricule);
                            break;
                        case 4 :
                            printf("print new abonnement: ");
                            scanf(" %c",&list[i].abonnement);
                            break;
                        case 5 :
                            printf("print new penalite: ");
                            scanf("%d",&list[i].penalite);
                            break;
                        case 6 : 
                            printf("exit");
                            con = 0;
                            break;
                        default: printf("your answer is not correct\n");
                    }
                    flag=1;
                }    
                break;
        }    
    }

    if(flag==0){
        printf("\n ce etudient n'exist pas.\n");
    }
}


                        // =================== function 15 ======================== //
void modifier_emprunt(ouvrage list_ouv[] ,etudient list_etud[], emprunts_des_ouvrages list[], int *p, int size_ouv, int size_etud){
    int size = *p, flag=0, answer, i, con=1, flag_etud, flag_ouv;
    int modifier_emp, modifier_etud;
    char modifier_ouvr[50];

    printf("\n========= modifier emprunt ==========\n");
    printf("input your etudient matricule: ");
    scanf("%d", &modifier_emp);

    for(i=0; i<=size-1; i++){
            if(list[i].matricule_de_etudiant == modifier_emp){
                printf("matricule_de_etudiant: %d \ncote_de_ouvrage_emprunte: %s \n date emprunt: %d/%d/%d \n date retour: %d/%d/%d \n\n",list[i].matricule_de_etudiant   ,list[i].cote_de_ouvrage_emprunte,          list[i].date_emprunt.jour, list[i].date_emprunt.month, list[i].date_emprunt.annee,       list[i].date_retour.jour, list[i].date_retour.month, list[i].date_retour.annee);
                printf("you would like to change: \n");
                    
                while(con == 1){
                    printf("1=>matricule de etudiant \n2=>cote_de_ouvrage_emprunte \n3=>date_emprunt \n4=>date_retour\n");
                    scanf("%d",&answer);
                    switch(answer){
                        case 1 : 
                            flag_etud = 0;
                            printf("print new matricule de etudiant: ");
                            scanf("%d",&modifier_etud);
                            for(int f=0; f<size_etud; f++){
                                if(modifier_etud==list_etud[f].matricule){
                                    flag_etud=1;
                                    break;
                                }
                            }
                            if(flag_etud==1){list[i].matricule_de_etudiant = modifier_etud;}
                            else {printf("ce etudient n'exist pas\n");}
                            break;

                        case 2 :
                            flag_ouv = 0;
                            printf("print new cote_de_ouvrage_emprunte: ");
                            scanf("%s",modifier_ouvr);
                            for(int g=0; g<size_ouv; g++){
                                if(strcmp(modifier_ouvr,list_ouv[g].titre)==0){
                                    flag_ouv=1;
                                    break;
                                }
                            }
                            if(flag_etud==1){strcpy(list[i].cote_de_ouvrage_emprunte, modifier_ouvr);}
                            else {printf("ce etudient n'exist pas\n");};
                            break;

                        case 3 :
                            printf("print new date_emprunt: ");
                            printf("jour: ");
                            scanf("%d",&list[i].date_emprunt.jour);
                            printf("month: ");
                            scanf("%d",&list[i].date_emprunt.month);
                            printf("annee: ");
                            scanf("%d",&list[i].date_emprunt.annee);
                            break;

                        case 4 :
                            printf("print new date retour: ");
                            printf("jour: ");
                            scanf("%d",&list[i].date_retour.jour);
                            printf("month: ");
                            scanf("%d",&list[i].date_retour.month);
                            printf("annee: ");
                            scanf("%d",&list[i].date_retour.annee);
                            break;

                        case 5: 
                            printf("exit");
                            con = 0;
                            break;
                        default: printf("your answer is not correct\n");
                    }
                    flag=1;
                }
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

    int size_ouvrage, size_member, size_emprunt, n;
    //int *p_ouvrage = &size_ouvrage, *p_member = &size_member, *p_emprunt = &size_emprunt;

    size_ouvrage = 0; 
    size_member = 0; 
    size_emprunt = 0;

    summm(&size_ouvrage);
    printf("\n =====> %d\n", size_ouvrage);

    ouvrage list_of_ouvrage[10000];
    etudient list_of_etudient[10000];
    emprunts_des_ouvrages list_of_emprunts[1000];



// test function 1:
//    Ajouter_un_etudiant(list_of_etudient , 2);
  //  printf("matricule: %d\n",list_of_etudient[2].matricule);
    //printf("abonnement: %c\n",list_of_etudient[2].abonnement);
   // printf("penality: %d\n",list_of_etudient[2].penalite);

// test function 2:
/*
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
*/

/*
    printf("cote: %d\n",list_of_ouvrage[2].cote__);
    printf("titre: %s\n",list_of_ouvrage[2].titre);
    printf("lib: %d\n",list_of_ouvrage[2].nombre_ouvrage);
    printf("no lib: %d\n",list_of_ouvrage[2].nombre_exemplaires_empruntés);
*/


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

    printf("30==>consulter_emprunt \n");

    /*
    printf("16==>Définir la durée des emprunts \n");
    printf("17==>Définir le maximum d’ouvrage à emprunter \n");

    printf("18==>Retourner un emprunt \n");

    printf("19====Pour quitter le programme\n\n");
*/

    while(n!=19){
        printf("n = ");
        scanf("%d", &n);
        switch(n){

            case 1 : 
                printf("%d\n",size_ouvrage);
                Ajouter_un_ouvrage(list_of_ouvrage, &size_ouvrage);
                printf("%d\n",size_ouvrage);
                break;
            case 2 : 
                Ajouter_un_etudiant(list_of_etudient , &size_member);
                break;
            case 3 : Ajouter_emprunt( list_of_etudient, list_of_ouvrage, list_of_emprunts ,size_ouvrage, size_member, &size_emprunt);
                break;
            case 4 : Ajouter_penalite(list_of_etudient, size_member) ;
                break;

            case 5 : consulter_tous_ouvrages(list_of_ouvrage, size_ouvrage);
                break;
            case 6 : consulter_un_member(list_of_etudient, size_member) ;
                break;
            case 7 : consulter_emprunt(list_of_emprunts, size_emprunt);
                consulter_tous_etudients(list_of_etudient, size_member) ;
                break;
            case 8 : consulter_list_des_penalites(list_of_etudient, size_member); ;
                break;

            case 9 : verifier_dispo_de_ouvrage(list_of_ouvrage, &size_ouvrage);
                break;

            case 10 : suppprimer_ouvrage(list_of_ouvrage, &size_ouvrage);
                break;
            case 11: suppprimer_member(list_of_etudient, &size_member);
                break;
            case 12 : suppprimer_emprunts(list_of_emprunts, &size_emprunt);
                break;
            case 13 : suppprimer_penalite(list_of_etudient, &size_member);
                break;
                
            case 14 : modifier_member(list_of_etudient, &size_member);
                break;
            case 15 : modifier_emprunt(list_of_ouvrage, list_of_etudient ,list_of_emprunts, &size_emprunt, size_ouvrage, size_member);
                break;
            case 30 : consulter_emprunt(list_of_emprunts, size_emprunt);
                break;
            
        };
        printf("\n===============================\n\n");};


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



