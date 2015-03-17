#include "plateau.h"
using namespace std;


int main(int argc, char* argv[])
{
  string help="--help";
  //verification legitimite
  if(argc > 2){
    cerr << "Syntax Error" <<endl;
    return 1;
  }
  else if(argv[1]){
    if(argv[1] == help){
      HELP();
      return 2;
    }
  }
  else{
    //initialisation flux sortie clog
    ofstream logFile;
    logFile.open("log.txt");
    streambuf *newbuf, *backup;
    backup=clog.rdbuf();
    newbuf=logFile.rdbuf();
    clog.rdbuf(newbuf);

    //Initialisation
    string sep="\n";
    string sep2="\n------------------------------------\n\n";

    Plateau table;

    table.initJoueurs();
    table.premDonneur();
    table.miseInit();//chacun pose 15, les joueurs qui ne peuvent pas sont gérés ds la fonction

    //Debut de Partie
    int tempNb=0;
    while(table.autorisationJouer(table.nbJoueurs) && tempNb != -1)
    {
  	table.distribuer();
  	size_t CPTour=table.nbJoueurs;//permet gerer si personne pose de cartes pdt 1 tour
  	size_t IND=1;//indice du joueur
  	size_t ind;//le gagnant
  	do{//tant qu'il à des cartes
  	  ind=IND;
  	  size_t nCarte;
  	  int retirer;
      table.afficherPlateau();
      table.tabJoueurs[IND].afficherJoueur();

      if(CPTour == table.nbJoueurs || CPTour == 0){
        cout<<sep<<"Vous pouvez jouer n'importe quelle carte."<<endl;
        table.initDefausse();
      }

	  do{//tant qu'il veut pas passer
      table.afficheDefausse();
      cout<<sep<<"Quelles cartes souhaitez vous jouer ? (0 pour passer)"<<endl;
	    table.tabJoueurs[IND].main.afficheMain();
	    do{//verification qu'il ai bien la carte
	      if(!table.tabJoueurs[IND].estHumain())
		    {
          nCarte=table.tabJoueurs[IND].launchBot(table.valDefausse());
		    }
	      else{
          while(!(cin>>nCarte)||(table.longMain(IND) < nCarte)){
            if(cin.fail()){
		          cout<<"Saisie incorrecte, recommencez : ";
		          cin.clear();
		          cin.ignore(SHRT_MAX, '\n');
            }
		        else{
              if(table.longMain(IND) < nCarte){
			         cout<<"Le numéro de la carte saisie est incorrect, recommencez: ";
              }
            }
          }
        }
	    }while(table.longMain(IND) < nCarte);
	    if(nCarte != 0){
        if(table.valDefausse()==13 || CPTour == table.nbJoueurs)
        {//sur un roi il pose ce qu'il veut
          table.setDefausse(table.tabJoueurs[IND].main.valeur(table.tabJoueurs[IND].main.chercheVal(nCarte)));
  		    table.tabJoueurs[IND].main.jouerCarte(nCarte);
          if(table.tabJoueurs[IND].estHumain()){
            do{
        			retirer=0;
        			cout<<"Retirer une mise ? 0 pour passer 1 pour retirer :";
        			cin>>retirer;
  		      }while((retirer < 0)||(retirer > 1));
  		    if(retirer==1){
            table.retirerMise(IND);}
          }
          else{
  		      if(table.tabJoueurs[IND].jaiJouerCarteSpec(table.getDefausse())){
              table.retirerMise(IND);}
          }
          CPTour=0;
        }
		    else{
          if(table.valDefausse()+1==table.tabJoueurs[IND].main.valeur(table.tabJoueurs[IND].main.chercheVal(nCarte)).getNumero())
          {//+1=
            table.setDefausse(table.tabJoueurs[IND].main.valeur(table.tabJoueurs[IND].main.chercheVal(nCarte)));
            table.tabJoueurs[IND].main.jouerCarte(nCarte);
            if(table.tabJoueurs[IND].estHumain()){
              do{
                retirer=0;
                cout<<"Retirer une mise ? 0 pour passer, 1 pour retirer :";
                cin>>retirer;
              }while((retirer < 0)||(retirer > 1));
              if(retirer==1)
              {
                table.retirerMise(IND);
              }
            }
            else{
              if(table.tabJoueurs[IND].jaiJouerCarteSpec(table.getDefausse())){
                table.retirerMise(IND);}
              }
              CPTour=0;//si le joueur joue le tour revient à 0
            }
            else{cout<<"Manoeuvre impossible."<<endl;}
          }
        }
        else{
          if(CPTour == table.nbJoueurs){CPTour=0;}
          CPTour+=1;
          }
    }while(nCarte != 0);
	  if(IND == table.nbJoueurs){//on passe au joueur suivant
	    IND=1;
	  }
	  else{
	    IND++;
	  }
    if(DEBUG == 0){
      system("clear");
    }
	}while(table.longMain(ind) != 0);//si et seulement si le joueur courant a encore des cartes

	table.scoreGagnant(table.tabJoueurs[ind]);
	table.payerGagnant(table.tabJoueurs[ind]);
	table.initDefausse();
	table.viderMains();
	if(table.autorisationJouer(table.nbJoueurs))
	{
		cout<<"Des joueurs souhaitent-ils s'en aller ? (nbJoueurs) sinon 0 pour passer et -1 pour quitter."<<endl;
		cin>>tempNb;
		if(tempNb>0)
		{
			string tempPseudo;
			size_t ind;
			bool check;
			do
		{
			ind=1;
			check=false;
			cout<<"Le pseudo du joueur ? (-1 pour passer)"<<endl;
			cin>>tempPseudo;
			if(tempPseudo != "-1")
			{
				while((!check) && (ind <= table.nbJoueurs))
				{
					ind++;
					if(tempPseudo == table.tabJoueurs[ind].getPseudo())
					{
						check=true;
					}
				}
				if(check==true)
				{
					table.tabJoueurs=table.enleverJoueur(tempPseudo);
					tempNb--;
				}
				else{cout<<tempPseudo<<" n'existe pas."<<endl;}
			}
		}while(tempNb!=0 && tempPseudo != "-1");
	}
	if(tempNb != -1)
	{
		table.miseInit();
		table.changerPlaceJoueurs();
	}
}
}
clog.rdbuf(backup);
logFile.close();
cout<<"Merci d'avoir jouer !"<<endl;
table.enterScores();
return 0;
  }
}
