#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include "mainJoueur.h"
#include <string>

using namespace std;

class Joueur{
	private:
		string pseudo;
		size_t score;
		size_t jetons;
		bool humain;

	public:
		MainJoueur main;

		Joueur();
		~Joueur();
		void setPseudo(string);
		void setJetons(int);
		string getPseudo() const;
		int getJetons() const;
		int getScore() const;
		void setScore(int);
		void setHumain(bool);
		bool estHumain() const;
		void afficherJoueur() const;
		Joueur& operator=(const Joueur&);

	//ensemble des méthodes gérant les bots

		bool jaiUnRoi() const;
		int suiteLaPlusLongue(bool) const;
		int jePeutJouer(int) const;
		int launchBot(int) const;
		bool jaiJouerCarteSpec(Carte c) const;
};
#endif
