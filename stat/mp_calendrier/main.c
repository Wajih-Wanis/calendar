#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "calendrier.h"



int main()
{
    contact repertoire[100];

    int n,j,m,a,p,nv_p,z,sem,w,x,e;
    char agenda[366][800];
    char anniv [366][800];
    char nom_event[90];
    char event[90];
    char evt[90];
    char eevt[90];
    Date Nouvelle_Date , date;
    system("color C0");
    Beep(220,300);

  Beep(294,300);


  /* */

  Beep(440,300);

  Beep(494,300);



  /* */

     printf("\t\t\t\t\t|------------BIENVENUE AU CALENDRIER-------------|\n\n\n");

  /* */

  Beep(247,300);

    printf("\t\t\t\t\t|---------Veuillez remplir votre repertoire---------|\n\n\n");
     Beep(247,800);





  /* */




    system("Cls");
    system("color 04");
    printf("saisir le nombre de contact à saisir : \n");
    scanf("%d",&n);
    saisiecontact(n, repertoire);
    printf("contact ajoute \n");
    system("color 7");

     do {
     afficher_menu();
     printf("votre choix : ");
     scanf("%d",&e);
     switch (e)
     {
         case 1 : system("color 03");
         Beep(1000,500);
             A_A_Contact(anniv, n,repertoire);
         printf("anniversaire de contact ajoute \n");
         break;
         case 2 :  system("color 05");
         Beep(1000,500);
             printf("ajouter un evenement \n");
   do {
         printf("Nom de l'évènement :\t ");
    scanf("%s",evt);
    suprEspace(evt);
    fflush(stdin);


   printf("donner la date du event \n");
   do{
   printf("jour : \t");
   scanf("%d",&j);
   }while(j>31);
   do{
   printf("mois : \t");
   scanf("%d",&m);
   }while(m>12);
   printf("annnee : \t");
   scanf("%d",&a);
   printf("periode : \t");
   scanf("%d",&p);
   Ajout_event(agenda,evt,j, m, a, p);
   printf("evenement ajoute \n");
   printf("continuez  1/0 ?:");
   scanf("%d",&x);
   }while (x==1);
   break;
   case 3 :  system("color 06");
   Beep(1000,500);
       printf("supprimer un evenemnet \n");
   printf("donner le nom de l'event à supprimer \t");
   scanf("%s",nom_event);
   suprEspace(nom_event);
   fflush(stdin);
   Supression_Evts( agenda,nom_event);
   printf("evenement supprime\n");
   break;
   case 4:    system("color 08");
   Beep(1000,500);
       printf("modifier un evenement \n");
        printf("donner le nom de l'event");
    scanf("%s",eevt);
   printf("donner la nouvelle date\n");
   do{
   printf("jour : \t");
   scanf("%d",&Nouvelle_Date.jour);
   }while(Nouvelle_Date.jour>31);

   do
   {printf("mois : \t");
   scanf("%d",&Nouvelle_Date.mois);
   }while(Nouvelle_Date.mois>12);
   printf("annnee : \t");
   scanf("%d",&Nouvelle_Date.annee);
   printf("periode : \t");
   scanf("%d",&nv_p);
   Modification_Programme(Nouvelle_Date, nv_p, agenda,eevt);
   printf("evenement modifie\n");
   break;
   case 5: system("color 09");
   Beep(1000,500);
        printf("visualisation des evenements \n");
   printf("affichage par date tapez 1 \n  ");
   printf("si affichage par semaine tapez 2 \n");
   printf("si affichage par nom de l event tapez 3 \n");
   scanf("%d",&z);
   if (z==1)
   {

        printf("donner la date du event \n");
   do{
        printf("jour : \t");
   scanf("%d",&date.jour);
   }while(date.jour>31);
   do{
        printf("mois : \t");
   scanf("%d",&date.mois);
   }while(date.mois>12);
   printf("annnee : \t");
   scanf("%d",&date.annee);


       Affichage_date(agenda, date);
       printf("\n");
       Affichage_date(anniv, date);

   }
   else if (z==2)
   {
       do{
       printf("donner la semaine \t");
       scanf("%d",&sem);
       }while(sem>48);
       Affichage_semaine(agenda, sem);
        printf("\n");
       Affichage_semaine(anniv, sem);
   }
   else if (z==3)
   {
       printf("donner le nom de l event ");
        scanf ("%s",event);
       printf("donenr l annee de l event");
       scanf ("%d",&w);

       Affichage_event(agenda,event,w);
       printf("\n");
       Affichage_event(anniv,event,w);

   }
   else{
    printf("choix non valide");
    break;
   }

    case 0 : printf("AU REVOIRM");
    Beep(1000,500);
    break;

}
     }while(e!=0);



     }













