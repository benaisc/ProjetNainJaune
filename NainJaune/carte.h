#ifdef DEBUG
#undef DEBUG
#endif
#define DEBUG 0 // Niveau 0: pas de debug
                // Niveau 1 : debug sans le pas à pas et peu détaillé
                // Niveau 2 : debug peu détaillé avec pas à pas
                // Niveau 3 : le plus détaillé avec pas à pas

#ifndef __CARTE_H__
#define __CARTE_H__

#include <iostream>
#include <limits>

using namespace std;

class Carte{
	private:
		int numero;
		char signe;	// 's' spade (pique) 'd' diamond (carreau) 
				// 'h' heart (coeur) 'c' club (trefle)
	public:
		Carte();
		Carte(int numero, char signe);
		~Carte();

		void afficherCarte() const;
		int getNumero() const;
		char getSigne() const;
};

void echangerCarte(Carte &a,Carte &b);

#endif
