#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include "calendrier.h"


void suprEspace(char *expr)
{int i,j,n;
n=strlen(expr);
for (i=0;i<n;i++)
  if (expr[i]==' ')
                   {
                    for(j=i;j<(n-1);j++)
                     expr[j]=expr[j+1];
                   }
}



void saisiecontact(int n,contact repertoire[])
{

    int i;
    for (i=0;i<n;i++)
    {
        system("Cls");
        system("color 03");
        printf("donner le nom du contact %d\t :",i+1);
        scanf("%s",repertoire[i].nom);
        suprEspace(repertoire[i].nom);
        fflush(stdin);
        printf("donner le prenom du contact %d \t :",i+1);
        gets(repertoire[i].prenom);
        suprEspace(repertoire[i].prenom);
        fflush(stdin);
        printf("donner le numero du contact %d",i+1);
        scanf("%d",&repertoire[i].numero);
        printf("donner la date de naissance du contact %d : jour / mois / annee \n",i+1);
        do{
        printf("jour : ");
        scanf("%d",&repertoire[i].date_de_naissance.jour);
        }while(repertoire[i].date_de_naissance.jour>31);
        do{
        printf("mois : ");
        scanf("%d",&repertoire[i].date_de_naissance.mois);
        }while(repertoire[i].date_de_naissance.mois>12);
        printf("annee : ");
        scanf("%d",&repertoire[i].date_de_naissance.annee);

    }
}


int check_leapYear(int annee){
    if(annee % 400 == 0 || ((annee % 100!=0) & (annee % 4 ==0)))
       return 1;
    return 0;
}

int Nbre_jour(int mois,int annee){
   switch(mois){
      case 1 : return(31);
      case 2 : if(check_leapYear(annee)==1)
		 return(29);
	       else
		 return(28);
      case 3 : return(31);
      case 4 : return(30);
      case 5 : return(31);
      case 6 : return(30);
      case 7 : return(31);
      case 8 : return(31);
      case 9 : return(30);
      case 10: return(31);
      case 11: return(30);
      case 12: return(31);
      default: return(-1);
   }
}


void A_A_Contact(char anniv[][800],int n,contact repertoire []){
    int i,k,j ;
    char d[200]="anniversaire: ";

    for (i=0;i<n;i++)
    {
        j=repertoire[i].date_de_naissance.jour;

        for (k=1;k< repertoire[i].date_de_naissance.mois;k++){
            j+=Nbre_jour(k,repertoire[i].date_de_naissance.annee);

        }
        strcat(d,repertoire[i].nom);
        strcat(d,repertoire[i].prenom);

        strcpy(anniv[j],d);

    }


}


void Ajout_event(char agenda[][800],char evt[],int j,int m,int a,int p)
{
    int i =0;
    int k;
    i+= j;
    system("color 05");
    for (k=0;k< m;k++){
        i+=Nbre_jour(k,a);
    }
    for (k=0;k<p;k++)
    {
        strcpy(agenda[i+k],evt);
    }
}






int recherche(char nom_evnt[],char agenda[][800])
{
    int j;
    j=0;
    while ((strcmp(nom_evnt,agenda[j])!=0)&&(j<366))
    {
        j+=1;
    }
    if (strcmp(nom_evnt,agenda[j])==0)
        return j;
    else return -1;




}

void Supression_Evts(char agenda[][800],char nom_evnt[]){

    int i ;
    system("color 06");
    i=recherche(nom_evnt, agenda);
    if (i!=-1)
    {
        while (strcmp(agenda[i],agenda[i+1])==0)
    {
        strcpy(agenda[i],"");

        i+=1;
    }
    strcpy(agenda[i],"");

    }


}


void Modification_Programme(Date Nouvelle_Date,int nv_p,char agenda[][800],char eevt[90]){


    system("color 07");

    suprEspace(eevt);
    fflush(stdin);
    if (recherche(eevt,agenda)==-1)
        printf("event non trouvé");

    else {
    Supression_Evts(agenda,eevt);

    Ajout_event( agenda,eevt,Nouvelle_Date.jour,Nouvelle_Date.mois,Nouvelle_Date.annee,nv_p);
    printf("evenement modifie");
}
}

void Affichage_date(char agenda[][800],Date d){
    int i,j;
    i=d.jour;

    for (j=0;j<d.mois;j++)
    {
        i+=Nbre_jour(j,d.annee);
    }
    if (agenda[i]==NULL)
        printf("pas d evenement");
    else
       printf("VOTRE EVENEMENT EST : \t %s",agenda[i]);

}

void Affichage_semaine(char agenda[][800],int sem)
{
    int j,i,trv;
    i=sem*7;
    printf("les events de cette semaine : \n");
    trv=0;
    for (j=i;j<i+7;j++)
    {
        if (agenda[j]!=NULL)
          {
              trv=1;
          }  printf("VOTRE EVENEMENT EST : \t %s \n",agenda[j]);


    }
    if (trv==0)
        printf("pas d evenement pour cette seamine");
}

void Affichage_event(char agenda[][800],char event[90],int a)
{
    int i,m;
   i=recherche(event,agenda);
   m=1;
   while ((i>=Nbre_jour(m,a))&&(m<12))
   {

    i-=Nbre_jour(m,a);


    m++;

   }
   if (recherche(event,agenda)==-1)
        printf("event non trouve");

    else {
         i++;
        printf("votre evenement sera le %d /%d/%d",i,m,a);
    }
//    if (check_leapYear(a))
//    {
//        if(i-31<=31)
//        {
//            printf("l event sera le %d janvier ",i);
//        }
//        else if (i-60<=29)
//        {
//            i-=31;
//            printf("l event sera le %d fevrier ",i);
//        }
//        else if (i-91<=31)
//        {
//            i-=60;
//            printf("l event sera le %d mars ",i);
//        }
//        else if (i-121<=30)
//        {
//            i-=91;
//            printf("l event sera le %d avril ",i);
//        }
//        else if (i-152<=31)
//        {
//            i-=121;
//            printf("l event sera le %d mai ",i);
//        }
//        else if (i-182<=30)
//        {
//            i-=152;
//            printf("l event sera le %d JUIN ",i);
//        }
//        else if (i-213<=31)
//        {
//            i-=182;
//            printf("l event sera le %d juillet ",i);
//        }
//        else if (i-244<=31)
//        {
//            i-=213;
//            printf("l event sera le %d AOUT ",i);
//        }
//        else if (i-274<=30)
//        {
//            i-=244;
//            printf("l event sera le %d septembre ",i);
//        }
//        else if (i-305<=31)
//        {
//            i-=274;
//            printf("l event sera le %d OCTOBRE ",i);
//        }
//        else if (i-335<=30)
//        {
//            i-=305;
//            printf("l event sera le %d novembre ",i);
//        }
//        else
//        {
//            i-=335;
//            printf("l event sera le %d decembre ",i);
//
//        }
//    }
//    else
//    {
//        if(i-31<=31)
//        {
//            printf("l event sera le %d janvier ",i);
//        }
//        else if (i-60<=28)
//        {
//            i-=31;
//            printf("l event sera le %d fevrier ",i);
//        }
//        else if (i-90<=31)
//        {
//            i-=59;
//            printf("l event sera le %d mars ",i);
//        }
//        else if (i-120<=30)
//        {
//            i-=90;
//            printf("l event sera le %d avril ",i);
//        }
//        else if (i-151<=31)
//        {
//            i-=120;
//            printf("l event sera le %d mai ",i);
//        }
//        else if (i-181<=30)
//        {
//            i-=151;
//            printf("l event sera le %d JUIN ",i);
//        }
//        else if (i-212<=31)
//        {
//            i-=181;
//            printf("l event sera le %d juillet ",i);
//        }
//        else if (i-243<=31)
//        {
//            i-=212;
//            printf("l event sera le %d AOUT ",i);
//        }
//        else if (i-273<=30)
//        {
//            i-=243;
//            printf("l event sera le %d septembre ",i);
//        }
//        else if (i-304<=31)
//        {
//            i-=273;
//            printf("l event sera le %d OCTOBRE ",i);
//        }
//        else if (i-334<=30)
//        {
//            i-=304;
//            printf("l event sera le %d novembre ",i);
//        }
//        else
//        {
//            i-=334;
//            printf("l event sera le %d decembre ",i);
//
//        }
//    }

}
void afficher_menu()
{

    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf(" \t\t *  BIENVENUE DANS VOTRE CALENDRIER *                              \n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf(" \t \t * Veuillez choisir un choix *                                        \n\n");
    printf(" \t 1- Ajouter les anniversaires de vos contacts     \n\n");
    printf(" \t 2- Ajouter un evenement         \n\n");
    printf(" \t 3- supprimer un evenement        \n\n");
    printf(" \t 4- modifier un evenement                        \n\n");
    printf("\t 5- visualisation de vos evenements                        \n\n");
    printf(" \t 0- Quitter                                                     \n\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------------------------------------------------------------------------------\n");

}

