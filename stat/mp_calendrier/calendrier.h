#ifndef CALENDRIER_H_INCLUDED
#define CALENDRIER_H_INCLUDED


typedef struct  {
    int jour ;
    int mois ;
    int annee;


}Date;


typedef struct  {
    char nom[300] ;
    char prenom[300] ;
    int numero ;
    Date date_de_naissance ;



}contact ;

 void SetColor(int ForgC);
void suprEspace(char *expr);
void saisiecontact(int n,contact repertoire[]);
int check_leapYear(int annee);
int Nbre_jour(int mois,int annee);
void A_A_Contact(char anniv[][800],int n,contact repertoire []);
void Ajout_event(char agenda[][800],char evt[],int j,int m,int a,int p);
int recherche(char nom_evnt[],char agenda[][800]);
void Supression_Evts(char agenda[][800],char nom_evnt[]);
void Modification_Programme(Date Nouvelle_Date,int nv_p,char agenda[][800],char eevt[90]);
void Affichage_date(char agenda[][800],Date d);
void Affichage_semaine(char agenda[][800],int sem);
void Affichage_event(char agenda[][800],char event[90],int a);
void afficher_menu();







#endif // CALENDRIER_H_INCLUDED
