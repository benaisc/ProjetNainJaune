#include "mainJoueur.h"


MainJoueur::MainJoueur()
{
    tete=queue=NULL;
    nbCartes=0;
}

MainJoueur::~MainJoueur()
{
    Place p=tete;
    while (p !=NULL)
    {
        p = suivant(p);
        delete tete;
        tete = p;
    }
}

bool MainJoueur::estVide() const
{
    return tete==NULL;
}

int MainJoueur::longueur() const
{
    return nbCartes;
}

MainJoueur::Place MainJoueur::premier() const
{
    return tete;
}

MainJoueur::Place MainJoueur::dernier() const
{
    return queue;
}

MainJoueur::Place MainJoueur::suivant(Place p) const
{
    return p->getSuiv();
}

MainJoueur::Place MainJoueur::precedent(Place p) const
{
    return p->getPrec();
}

TypeVal MainJoueur::valeur(Place p) const
{
    return p->getVal();
}

void MainJoueur::ajoutAvant(Place p,TypeVal val)
{
  Cell *elt = new Cell(val);
  nbCartes++;
  if(DEBUG == 3){
    cout << "Avant ajout de ";
    val.afficherCarte();
    cout << "  avant la place p :"<< endl << endl;
    afficheMain();
  }
  if(p == NULL){
    tete=queue=elt;
  }
  else{
    if(p == tete)
      {
	setSuivant(elt,p);
	setPrecedent(p,elt);
	tete=elt;
      }
    else{
      setSuivant(elt,p);
      setPrecedent(elt,precedent(p));
      setSuivant(precedent(p),elt);
      setPrecedent(p,elt);
    }
  }
  if(DEBUG == 3){
    cout << endl << "Après ajout : "<<endl;
    afficheMain();
    cout << "-----------------------------------"<<endl;
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
  }
}

void MainJoueur::ajoutApres(Place p,TypeVal val)
{
  Cell *elt = new Cell(val);
  if(DEBUG == 3){
    cout << "Avant ajout de ";
    val.afficherCarte();
    cout<< "  après la place p :"<< endl << endl;
    afficheMain();
  }
  if(p == NULL){
    tete=elt;
    queue=elt;
  }
  else{
    if(p == queue){
      p->setSuiv(elt);
      elt->setPrec(p);
      queue=elt;
    }
    else{
      setPrecedent(elt,p);
      setSuivant(elt,suivant(p));
      setPrecedent(suivant(p),elt);
      setSuivant(p,elt);
    }
  }
  nbCartes++;
    if(DEBUG == 3){
      cout << endl << "Après ajout : "<<endl;
      afficheMain();
    cout << "-----------------------------------"<<endl;
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
  }
}

void MainJoueur::ajoutDebut(TypeVal v)
{
    ajoutAvant(tete,v);

    if(DEBUG == 3){
      cout << "Ajout au début de la carte  ";
      v.afficherCarte();
      cout<<" :"<<endl<<endl;
      afficheMain();
      cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    }
}

void MainJoueur::ajoutFin(TypeVal v)
{
  Cell *elt = new Cell(v);
  
  if(tete == NULL && queue == NULL){
    tete=elt;
    queue=elt;
  }
  else{
    queue->setSuiv(elt);
    elt->setPrec(queue);
    queue=elt;
  }
  nbCartes++;

  if(DEBUG == 3){
    cout << "Ajout à la fin de  ";
    v.afficherCarte();
    cout<<" :"<<endl<<endl;
    afficheMain();
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
  }
}

void MainJoueur::enleve(Place p)
{
  if(DEBUG == 3){
    cout<<"ENLEVE"<<endl<<"-------"<<endl;
    cout<<"Avant :"<<endl;
    afficheMain();
  }

  if(nbCartes ==1){
    tete=queue=NULL;
  }
  else{
    if(p == tete){
      tete=suivant(p);
      setPrecedent(tete,NULL);
    }
    else{
      if(p == queue){
	queue=precedent(p);
	setSuivant(queue,NULL);
      }
      else{
	setSuivant(precedent(p),suivant(p));
	setPrecedent(suivant(p), precedent(p));
      }
    }
  }
  nbCartes--;
  delete p;
  if(DEBUG == 3){
    cout<< endl << endl << "Après :"<<endl;
    afficheMain();
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
  }
}
void MainJoueur::enlevePremier()
{
  if(DEBUG == 3){
    cout << endl << "enlevePremier" << endl << "-------------" <<endl;
  }
  enleve(tete);
}
void MainJoueur::enleveDernier()
{
  if(DEBUG == 3){
    cout << endl << "enleveDernier" << endl << "-------------" <<endl;
  }
  enleve(queue);
}

void MainJoueur::vider()
{
  if(DEBUG == 1 || DEBUG == 2 || DEBUG == 3){
    cout << endl << "VIDER" << endl << "------" <<endl;
    cout <<"Avant :";
    afficheMain();
    cout << endl << endl;
  }
  if(tete != NULL)
    {
      Place p=suivant(tete);
      if(p != NULL)
	{
	  do{
	    delete tete;
	    tete = p;
	    p = suivant(p);
	  }while(p != NULL);
	  delete tete;
	}
      else
	{
	  delete tete;
	}
      tete=queue=NULL;
      nbCartes=0;
    }
    if(DEBUG == 1 || DEBUG == 2 || DEBUG == 3){
    cout <<"Après :";
    afficheMain();
    cout << endl << endl;
    if(DEBUG ==2 || DEBUG == 3){
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    }
  }
}

void MainJoueur::afficheMain()const
{
  Place tmp=tete;
  if(tmp != NULL)
    {
      string sep="[";
      do
	{
	  cout<<sep;
	  sep="  ";
	  valeur(tmp).afficherCarte();
	  tmp=suivant(tmp);
	}while(tmp!=NULL);
      cout<<" ]"<<endl;
      //indication du numero de la carte au joueur:
      size_t i=1;
      tmp=tete;
      cout<<" ";
      do
	{
	  if(i<10)
	    sep="  ";
	  else(sep=" ");
	  cout<<i++<<sep;
	  tmp=suivant(tmp);
	}while(tmp!=NULL);
      cout<<sep<<endl;
    }
  else{cout<<"[]"<<endl;}
}

void MainJoueur::triMain() {
  Place i=suivant(tete);
  Place j=tete;
  if(DEBUG == 1 || DEBUG == 2 || DEBUG == 3){
    cout << "TRIMAIN" << endl <<"-------"<<endl;
    cout << "MAIN DESORDONNEE : "<< endl;
    afficheMain();
  }
  while(j !=NULL && suivant(j) != NULL)
    {
      while(i != NULL)
	{
	  if((valeur(j).getNumero())>(valeur(i).getNumero()))
	    {
	      ajoutApres(j,valeur(i));
	      ajoutApres(i,valeur(j));
	      j=suivant(j);
	      i=suivant(i);
	      enleve(precedent(j));
	      enleve(precedent(i));
	    }
	  i=suivant(i);
	}
      j=suivant(j);
      i=suivant(j);
    }
    if(DEBUG == 1 || DEBUG == 2 || DEBUG == 3){
      cout << "MAIN ORDONNEE :"<<endl;
      afficheMain();
      cout << "TRIMAIN END"<<endl << "-----------"<<endl;
    if(DEBUG == 2 || DEBUG == 3){
      cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    }
  }
}

MainJoueur::Place MainJoueur::chercheVal(int v)const
{
  int i=1;
  Place tmp=tete;
  while(i<v)
    {
      tmp=suivant(tmp);
      i++;
    }
  return tmp;
}

void MainJoueur::jouerCarte(int nCarteJouee)
{
  Place tmp= chercheVal(nCarteJouee);
  enleve(tmp);
}
