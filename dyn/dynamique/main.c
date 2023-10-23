#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "dynamique.h"

#define alloc(t) (t*)malloc(sizeof(t))




int main()
{


    int n,nv_p,z,e,x;
    char nom_evnt[90];
    char evt[90];
    char event[90];
    char nom_event[90];
    char evenement[90];
    Date Nouvelle_Date;
    trep *tete;
    tagenda * teteagenda;

    tete=alloc(trep);
    tete->suiv=NULL;
    teteagenda=alloc(tagenda);
    teteagenda->suiv=NULL;
    Beep(1000,500);
    system("color 04");
   printf("\t\t\t\t\t------------BIENVENUE AU CALENDRIER-------------|\n\n\n");
    printf("\t\t\t\t\t---------Veuillez remplir votre repertoire---------|\n\n\n");


    system("color 03");
    printf("saisir le nombre de contact à saisir : \n");
    scanf("%d",&n);
    system("Cls");
    tete=saisiecontact(tete);
    printf("contact ajoute avec succee \n");
    system("Cls");
    //ajout les anniversaires des contacts comme event
 do {
     afficher_menu();
     printf("votre choix : ");
     scanf("%d",&e);
     switch (e)
     {
         case 1 : system("color 03");
         Beep(1000,500);
             teteagenda=A_A_Contact( tete);
         printf("anniversaire ajooute \n");

         break;
         case 2 :  system("color 05");
         Beep(1000,500);
             printf("ajouter un evenement \n");
   do {
         teteagenda=Ajout_event(teteagenda);
   printf("continuez  1/0 ?:");
   scanf("%d",&x);
   }while (x==1);
   break;
   case 3 : system("color 06");
   Beep(1000,500);
       printf("supprimer un evenemnet \n");
   printf("donner le nom de l'event à supprimer \t");
   scanf("%s",nom_event);
   suprEspace(nom_event);
   fflush(stdin);
   teteagenda=Supression_Evts(teteagenda,nom_evnt);
   printf("evenement suprrime \n");
   break;
   case 4:    system("color 08");
   Beep(1000,500);
       printf("modifier un evenement \n");
   printf("donner le nom de l'event");
    scanf("%s",evenement);
   printf("donner la nouvelle date\n");
   do{
   printf("jour : \t");
   scanf("%d",&Nouvelle_Date.jour);
   }while(Nouvelle_Date.jour>31);
   do{
   printf("mois : \t");
   scanf("%d",&Nouvelle_Date.mois);
   }while(Nouvelle_Date.mois>12);
   printf("annnee : \t");
   scanf("%d",&Nouvelle_Date.annee);
   printf("periode : \t");
   scanf("%d",&nv_p);

   teteagenda=Modification_Programme(Nouvelle_Date,nv_p,teteagenda,evenement);
   printf("evenement modifie \n");

   break;
   case 5:  system("color 09");
   Beep(1000,500);
       printf("visualisation des evenements \n");
   printf("affichage par date tapez 1 \n  ");
   printf("si affichage par nom de l event tapez 2 \n");
   scanf("%d",&z);
   if (z==1)
   {

        Affichage_date(teteagenda);
       printf("\n");
   }

   else if (z==2)
   {
       printf("donner le nom de l event ");
        scanf ("%s",event);

        Affichage_event(teteagenda ,evt);
   }
   else{
    printf("choix non valide");
    break;
   }

    case 0 : printf("au revoir !!!");
    break;

}
     }while(e!=0);



     }





