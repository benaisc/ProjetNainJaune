#ifndef __MAIN_JOUEUR__
#define __MAIN_JOUEUR__


#include "cell.h"
#include "carte.h"
using namespace std;

class MainJoueur{

  public:
    typedef Cell* Place;  

  private:

    Place tete;
    Place queue;
    int nbCartes;

    void setSuivant(Place p, Place suiv){if(p != NULL){p->setSuiv(suiv);}};
    void setPrecedent(Place p, Place prec){if(p != NULL){p->setPrec(prec);}};

  public:

    MainJoueur();
    ~MainJoueur();
    bool estVide() const;
    int longueur() const;
    Place premier() const;
    Place dernier() const;
    Place suivant(Place) const;
    Place precedent(Place) const;
    TypeVal valeur(Place) const;
    void ajoutAvant(Place, TypeVal);
    void ajoutApres(Place, TypeVal);
    void ajoutDebut(TypeVal);
    void ajoutFin(TypeVal);
    void enleve(Place);
    void enlevePremier();
    void enleveDernier();
    void vider();//new
    void afficheMain() const;
    void triMain();
    Place chercheVal(int) const;
    void jouerCarte(int);
};

#endif
