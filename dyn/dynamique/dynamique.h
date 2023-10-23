#ifndef DYNAMIQUE_H_INCLUDED
#define DYNAMIQUE_H_INCLUDED

typedef struct  {
    int jour ;
    int mois ;
    int annee;
}Date;


typedef struct  {
    char nom[200];
    char prenom[200] ;
    int numero ;
    Date date_de_naissance ;



}contact ;
typedef struct repertoire
{
    contact c;
    struct repertoire *suiv;
}trep;


typedef struct agenda
{
    char event[90];
    Date date;
    int periode;
    struct agenda *suiv;
}tagenda;




void suprEspace(char *expr);
trep* saisiecontact(trep* tete);
int check_leapYear(int annee);
int Nbre_jour(int mois,int annee);
tagenda* A_A_Contact( trep* tete);
tagenda* Ajout_event(tagenda *teteagenda);
tagenda* Supression_Evts(tagenda*teteagenda,char nom_evnt[]);
tagenda* Modification_Programme(Date Nouvelle_Date,int nv_p,tagenda *teteagenda,char event[90]);
void Affichage_date(tagenda *teteagenda);
void Affichage_event(tagenda *teteagenda ,char evt[]);
void afficher_menu();




#endif // DYNAMIQUE_H_INCLUDED
