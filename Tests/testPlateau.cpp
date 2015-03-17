#include "plateau.h"
#include <fstream> //pour clog
using namespace std;

int main(int argc, char* argv[])
{
  string sep="\n";
  string sep2="\n------------------------------------\n\n";

	//Test d'ouverture
	if(argc > 1){
		cerr << "Echec de la création du plateau" <<endl;
		return 1;
  	}

    streambuf *newbuf, *backup;
    ofstream logFile;
    logFile.open("log.txt");

    backup=clog.rdbuf();
    newbuf=logFile.rdbuf();
    clog.rdbuf(newbuf);


	Plateau plateau;

  plateau.initJoueurs();

	cout<<"Affichage du plateau:"<<sep<<endl;
  plateau.afficherPlateau();

	cout<<sep2<<"Affichage du jeu de cartes:"<<sep<<endl;
	plateau.afficherJeu();

	cout<<sep2<< "Affichage du jeu de cartes mélangé:"<<sep<<endl;
	plateau.melangerJeu();
	plateau.afficherJeu();

	cout<<sep2<<"Distribution des cartes aux joueurs:"<<endl;
	plateau.distribuer();
	for(size_t i=1;i<=plateau.nbJoueurs;i++){
		cout<<"Main de "<<plateau.tabJoueurs[i].getPseudo()<<": "<<sep;
		plateau.tabJoueurs[i].main.afficheMain();
		cout<<sep;
	}

	cout<<sep2<<"Affichage du talon de cartes:"<<sep;
	plateau.tabJoueurs[0].main.afficheMain();
  cout<<sep2;

  cout<<"Simulation d'un coup pour le joueur 1 :"<<endl;
  plateau.tabJoueurs[1].afficherJoueur();
  plateau.afficherPlateau();
  plateau.tabJoueurs[1].main.afficheMain();
	bool bonneCarte;
  short nCarteJouee;
  cout<<"L'indice d'une carte :";
	do
	{
		cin>>nCarteJouee;
    bonneCarte=(nCarteJouee>=1 || nCarteJouee<plateau.longMain(1));
		if(!bonneCarte)
		{
			cout<<"Tu n'as pas cette carte"<<sep<<"Saisi une nouvelle carte :";
		}
	}while(!bonneCarte);
  plateau.setDefausse(plateau.tabJoueurs[1].main.valeur(plateau.tabJoueurs[1].main.chercheVal(nCarteJouee)));
	plateau.tabJoueurs[1].main.jouerCarte(nCarteJouee);
  cout<<"Carte jouee: ";
  plateau.afficheDefausse();
	cout<<sep<<sep<<"Nouvelle main de "<<plateau.tabJoueurs[1].getPseudo()<<" :"<<endl;
	plateau.tabJoueurs[1].main.afficheMain();
	cout<<sep2;

  cout<<"On vide les mains :"<<endl;
  plateau.viderMains();
  for(size_t i=1;i<=plateau.nbJoueurs;i++){
    cout<<"Main de "<<plateau.tabJoueurs[i].getPseudo()<<": "<<sep;
    plateau.tabJoueurs[i].main.afficheMain();
    cout<<sep;
  }

  cout<<"On retire "<<plateau.tabJoueurs[1].getPseudo()<<" du tabJoueurs :"<<endl;
  plateau.tabJoueurs=plateau.enleverJoueur(plateau.tabJoueurs[1].getPseudo());
  cout<<"Joueurs restants :"<<endl;
  for(size_t i=1;i<=plateau.nbJoueurs;i++){
    plateau.tabJoueurs[i].afficherJoueur();
  }

  clog.rdbuf(backup);
  logFile.close();
return 0;
}
