
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include "carte.h"
#include "plateau.h"
#include "joueur.h"
#include "cell.h"
#include "mainJoueur.h"

using namespace std;

int main(int argc, char* argv[])
{
 Joueur j1,j2,j3;
j1.setPseudo("Jules");
j2.setPseudo("Matthieu");
j3.setPseudo("Charles");
j1.setJetons(40);
j2.setJetons(40);
j3.setJetons(40);
cout<<"Pseudo de j1: "<<j1.getPseudo()<<endl;
cout<<"Jetons de j2: "<<j2.getJetons()<<endl;
cout<<"Score de j3: "<<j3.getScore()<<endl;
j1.setHumain(1);
cout<<"Bool pour savoir si j2 est humain: "<<j2.estHumain()<<endl;
j1.afficherJoueur();
j2.afficherJoueur();
j1=j2;
cout<<"Copie de j2 dans j1: "<<endl;
j1.afficherJoueur();
j2.afficherJoueur();

}
