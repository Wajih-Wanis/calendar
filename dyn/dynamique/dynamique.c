#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include "dynamique.h"
#define alloc(t) (t*)malloc(sizeof(t))


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


trep* saisiecontact(trep* tete)
{

    trep *q,*cellule;
    int i;
    i=0;
    q=tete;

        cellule=alloc(trep);
        cellule->suiv=NULL;
        printf("donner le nom du contact %d \n",i+1);
        scanf("%s",cellule->c.nom);
        printf("donner le prenom du contact %d \n ",i+1);
        scanf("%s",cellule->c.prenom);
        printf("donner le numero du contact %d \n",i+1);
        scanf("%d",&cellule->c.numero);
        printf("donner la date de naissance du contact %d : jour / mois / annee : \n ",i+1);
        do{
        printf("jour : \n");
        scanf("%d",&cellule->c.date_de_naissance.jour);
        }while (cellule->c.date_de_naissance.jour>31);
        do {
        printf("mois : \n");
        scanf("%d",&cellule->c.date_de_naissance.mois);
        }while(cellule->c.date_de_naissance.mois >12);
        printf("annee:\n");
        scanf("%d",&cellule->c.date_de_naissance.annee);

        if (tete==NULL)
        {
            tete=cellule;
        }
        else
        {
            while(q->suiv!=NULL)
            {
                q=q->suiv;
            }
            q->suiv=cellule;
        }
     return tete;
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

tagenda* A_A_Contact( trep* tete){
    int i ;
    char d[200]="anniversaire: ";
    tagenda* cellule,*prec,*teteagenda;
    trep *q;
    q=tete;
    i=0;

    while (q->suiv!=NULL)
    {
        cellule=alloc(tagenda);
        cellule->suiv=NULL;
        i++;
        strcat(d,q->c.nom);
        strcat(d,q->c.prenom);

        strcat(cellule->event,d);
        cellule->date.jour=q->c.date_de_naissance.jour;
        cellule->date.mois=q->c.date_de_naissance.mois;
        cellule->date.annee=q->c.date_de_naissance.annee;
        cellule->periode=1;

        if (i==1)
        {
            teteagenda=cellule;
            prec=cellule;
        }

        else
        {   prec->suiv=cellule;
            prec=cellule;
            q=q->suiv;
        }

    }

    return teteagenda;

    }

tagenda* Ajout_event(tagenda *teteagenda)
{

    tagenda *q,*cellule;

    q=teteagenda;
    cellule=alloc(tagenda);
    cellule->suiv=NULL;
    printf("Nom de l'évènement : ");
    scanf("%s",q->event);
    do{
    printf("jour de l evenement : \t");
    scanf("%d",&q->date.jour);
    }while(q->date.jour>31);
    do{
    printf("mois de l evenement : \t");
    scanf("%d",&q->date.mois);
    }while(q->date.mois>12);
    printf("annne de l evenement : \t");
    scanf("%d",&q->date.annee);
    printf("periode de l evenement : \t");
    scanf("%d",&q->periode);
    if(q==NULL)
        return cellule;
    else
    {
         while(q->suiv!=NULL)
    {
        q=q->suiv;
    }
    q->suiv=cellule;
    }

return teteagenda;

}

tagenda* Supression_Evts(tagenda*teteagenda,char nom_evnt[])
{
    tagenda *q,*p;
    p=teteagenda;
    q=NULL;

    while(p->suiv!=NULL)
    {
        if((strcmp(p->event,nom_evnt))==0)
        {
            if(p==teteagenda)
            {
                teteagenda=p->suiv;
                free(p);
                p=teteagenda;
            }
            else if(p->suiv==NULL)
            {
                q->suiv=NULL;
                free(p);
            }

            else
            {
                q->suiv=p->suiv;
                free(p);
                p=q->suiv;
            }
            return teteagenda;
        }
        else
        {
            q=p;
            p=p->suiv;
        }
        return teteagenda;
    }
}
tagenda* Modification_Programme(Date Nouvelle_Date,int nv_p,tagenda *teteagenda,char event[90]){

     teteagenda=Supression_Evts(teteagenda,event);

    teteagenda=Ajout_event( teteagenda);
    return teteagenda;
}

void Affichage_date(tagenda *teteagenda){

    tagenda *q;
    int a,m,j;
    q=teteagenda;
    printf("donner la date de l evenement :\n");
    do {
    printf("jour : \t");
    scanf("%d",&j);
    }while(j>31);
     do{
     printf("mois : \t");
    scanf("%d",&m);
     }while(m>12);
     printf("annnee : \t");
    scanf("%d",&a);

    while(q!=NULL)
    {
        if((q->date.annee==a)&&(q->date.mois==m)&&(q->date.jour==j))
        {
            printf("%s",q->event);
            break;
        }
        q=q->suiv;
    }


}
void Affichage_event(tagenda *teteagenda ,char evt[])
{
    tagenda *q;
    q=teteagenda;
    while(q!=NULL)
    {
        if (strcmp(q->event,evt)==0)
        {
            printf("%d / %d /%d",q->date.jour,q->date.mois,q->date.annee);
        }
        q=q->suiv;
    }
}



void afficher_menu()
{

    printf("----------------------------------------------------------------------------------------------------------------------\n");
    printf(" \t\t *  BIENVENUE EN CALENDRIER *                              \n");
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
