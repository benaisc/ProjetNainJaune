﻿#ifndef __PLATEAU_H__
#define __PLATEAU_H__

#include "carte.h"
#include "joueur.h"
#include <cstdlib>//pour melangerJeu
#include <time.h>
#include <fstream>//pour enterScore et clog
//#include <regex>pour la partie mise en commentaire de enterScore
#define SHRT_MAX 32767

using namespace std;

class Plateau{

	private:
		Carte* jeu;
		Carte* plateau;
		int* mises;
		Carte defausse;

	public:
		size_t nbJoueurs;
		Joueur *tabJoueurs;

		Plateau();
		~Plateau();
		void afficherPlateau() const;
		void afficherJeu() const;
		void melangerJeu();
		void initJoueurs();
		Joueur* enleverJoueur(string);
		void changerPlaceJoueurs();
		void premDonneur();
		void miseInit();
		void distribuer();
		size_t longMain(int) const;
		void viderMains();
		void initDefausse();
		void afficheDefausse() const;
		void setDefausse(Carte);
		int valDefausse() const;
		Carte getDefausse() const;
		void scoreGagnant(Joueur &j);
		void payerGagnant(Joueur &win);
		void retirerMise(int indJ);
		bool autorisationJouer(int nb) const;
		void enterScores();
};
void HELP();
#endif
