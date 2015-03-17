#include "joueur.h"

Joueur::Joueur():pseudo("inconnu"),score(0),jetons(0),humain(false),main(MainJoueur()){}

Joueur::~Joueur(){}

void Joueur::setPseudo(string nomJoueur){
  pseudo = nomJoueur;
}

void Joueur::setJetons(int nombre){
  jetons = nombre;
}

string Joueur::getPseudo() const{
  return pseudo;
}

int Joueur::getJetons() const{
  return jetons;
}

int Joueur::getScore() const{
  return score ;
}

void Joueur::setScore(int scr){
  score=scr;
}

void Joueur::setHumain(bool h){
  humain = h;
}

bool Joueur::estHumain() const{
  return humain ;
}

void Joueur::afficherJoueur() const{
  cout <<"Pseudo : "<< pseudo << " || Score : "<< score << "|| Jetons : "<<jetons << endl;
}

Joueur& Joueur::operator=(const Joueur &jr){

  this->pseudo=jr.pseudo;
  this->score=jr.score;
  this->jetons=jr.jetons;
  this->humain=jr.humain;
  this->main=jr.main;
  
  return *this;
}

bool Joueur::jaiUnRoi() const
{
  Carte c=this->main.valeur(this->main.chercheVal(this->main.longueur()));//c=val(queue)
  bool b=false;
  if(c.getNumero() == 13){
    b=true;
  }
  return b;
}

int Joueur::suiteLaPlusLongue(bool check) const
{
  size_t lm=this->main.longueur();                       //lmain=indice de queue dans la main
  int result=1;                                          //s'il n'à pas de suite il pose la 1ere carte de sa main
  if(check)                                              //il a un roi
    {
      Cell* c=this->main.chercheVal(lm);
      result=lm;                                         //indice du roi dans la main
      int valCherch=12;                                  //dame
      while(lm>1)                                        //tant qu'ya des cartes à zieuter
	{
	  c=c->getPrec();
	  lm--;
	  if(c->getVal().getNumero() == valCherch)
	    {
	      valCherch--;
	      result=lm;                                 //indice de la carte recherchee ds la main
	    }
	}
    }
  else                                                  //pas de roi
    {
      size_t ind=0;
      short cpt;                                        //check la taille de la suite
      short indCHK=1;                                   //taille de la plus longue suite checkee
      Cell* c;
      int valCherch;
      
      for(size_t i=1; i<=lm; i++)                       //pour toutes les cartes
	{
	  c=this->main.chercheVal(i);
	  cpt=1;
	  ind=i;
	  valCherch=c->getVal().getNumero()+1;
	  
	  while(ind<lm && c->getVal().getNumero() < valCherch)  //tant qu'ya des cartes à zieuter
	    {
	      c=c->getSuiv();
	      ind++;
	      if(c->getVal().getNumero() == valCherch)
		{
		  valCherch++;
		  cpt++;
		}
	    }
	  if(indCHK<=cpt)
	    {
	      indCHK=cpt;
	      result=i;
	    }
	}
    }
  return result;
}

int Joueur::jePeutJouer(int valD) const
{
  int result=0;
  int lm=this->main.longueur();
  if(lm != 0)
    {
      Cell* c=this->main.chercheVal(lm);
      int val=valD+1;
      while(lm>0 && c->getVal().getNumero()>valD)
	{
	  if(c->getVal().getNumero() == val)
	    {
	      result=lm;
	      lm=0;
	    }
	  else
	    {
	      c=c->getPrec();
	      lm--;
	    }
	}
    }
  return result;
}

int Joueur::launchBot(int valD) const
{
  if(valD!=0 && valD!=13)
    {   //si la défausse n'est pas vide ni roi
      return jePeutJouer(valD);
    }
  else{
    return suiteLaPlusLongue(jaiUnRoi());
  }
}

bool Joueur::jaiJouerCarteSpec(Carte c) const
{
  bool result=false;
  
  if(c.getNumero()==10 && c.getSigne()=='d')
    {
      result=true;
    }
  if(!result){
    if(c.getNumero()==11 && c.getSigne()=='c')
      {
	result=true;
      }
  }
  if(!result){
    if(c.getNumero()==12 && c.getSigne()=='s')
      {
	result=true;
      }
  }
  if(!result){
    if(c.getNumero()==13 && c.getSigne()=='h')
      {
	result=true;
      }
  }
  if(!result){
    if(c.getNumero()==7 && c.getSigne()=='d')
      {
	result=true;
      }
  }
  return result;
}
