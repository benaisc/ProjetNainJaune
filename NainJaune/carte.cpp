#include "carte.h"

Carte::Carte():numero(0),signe('z'){}

Carte::Carte(int numero, char signe){
  if((signe!='c' || signe!='h' || signe!='d' || signe!='s') && (numero>13 || numero<0))
    cerr<<"ATTENTION ! La carte "<<numero<<" "<<signe<<" n'est pas valide !"<<endl;
  else{
    this->numero=numero;
    this->signe=signe;
  }
}
Carte::~Carte(){}

void Carte::afficherCarte() const
{
  switch (signe){
 		case 's':
			switch (numero)
			{
				case 1:
				cout<<"\U0001F0A1";
				break;

				case 2:
				cout<<"\U0001F0A2";
				break;

				case 3:
				cout<<"\U0001F0A3";
				break;

				case 4:
				cout<<"\U0001F0A4";
				break;

				case 5:
				cout<<"\U0001F0A5";
				break;

				case 6:
				cout<<"\U0001F0A6";
				break;

				case 7:
				cout<<"\U0001F0A7";
				break;

				case 8:
				cout<<"\U0001F0A8";
				break;

				case 9:
				cout<<"\U0001F0A9";
				break;

				case 10:
				cout<<"\U0001F0AA";
				break;

				case 11:
				cout<<"\U0001F0AB";
				break;

				case 12:
				cout<<"\U0001F0AD";
				break;

				case 13:
				cout<<"\U0001F0AE";
				break;
			}
		break;

		case 'h':
			switch (numero)
			{
				case 1:
				cout<<"\033[31;1m\U0001F0B1\033[0m";
				break;

				case 2:
				cout<<"\033[31;1m\U0001F0B2\033[0m";
				break;

				case 3:
				cout<<"\033[31;1m\U0001F0B3\033[0m";
				break;

				case 4:
				cout<<"\033[31;1m\U0001F0B4\033[0m";
				break;

				case 5:
				cout<<"\033[31;1m\U0001F0B5\033[0m";
				break;

				case 6:
				cout<<"\033[31;1m\U0001F0B6\033[0m";
				break;

				case 7:
				cout<<"\033[31;1m\U0001F0B7\033[0m";
				break;

				case 8:
				cout<<"\033[31;1m\U0001F0B8\033[0m";
				break;

				case 9:
				cout<<"\033[31;1m\U0001F0B9\033[0m";
				break;

				case 10:
				cout<<"\033[31;1m\U0001F0BA\033[0m";
				break;

				case 11:
				cout<<"\033[31;1m\U0001F0BB\033[0m";
				break;

				case 12:
				cout<<"\033[31;1m\U0001F0BD\033[0m";
				break;

				case 13:
				cout<<"\033[31;1m\U0001F0BE\033[0m";
				break;
			}
		break;

		case 'd':
			switch (numero)
			{
				case 1:
				cout<<"\033[31;1m\U0001F0C1\033[0m";
				break;

				case 2:
				cout<<"\033[31;1m\U0001F0C2\033[0m";
				break;

				case 3:
				cout<<"\033[31;1m\U0001F0C3\033[0m";
				break;

				case 4:
				cout<<"\033[31;1m\U0001F0C4\033[0m";
				break;

				case 5:
				cout<<"\033[31;1m\U0001F0C5\033[0m";
				break;

				case 6:
				cout<<"\033[31;1m\U0001F0C6\033[0m";
				break;

				case 7:
				cout<<"\033[31;1m\U0001F0C7\033[0m";
				break;

				case 8:
				cout<<"\033[31;1m\U0001F0C8\033[0m";
				break;

				case 9:
				cout<<"\033[31;1m\U0001F0C9\033[0m";
				break;

				case 10:
				cout<<"\033[31;1m\U0001F0CA\033[0m";
				break;

				case 11:
				cout<<"\033[31;1m\U0001F0CB\033[0m";
				break;

				case 12:
				cout<<"\033[31;1m\U0001F0CD\033[0m";
				break;

				case 13:
				cout<<"\033[31;1m\U0001F0CE\033[0m";
				break;
			}
		break;

		case 'c':
			switch (numero)
			{
				case 1:
				cout<<"\U0001F0D1";
				break;

				case 2:
				cout<<"\U0001F0D2";
				break;

				case 3:
				cout<<"\U0001F0D3";
				break;

				case 4:
				cout<<"\U0001F0D4";
				break;

				case 5:
				cout<<"\U0001F0D5";
				break;

				case 6:
				cout<<"\U0001F0D6";
				break;

				case 7:
				cout<<"\U0001F0D7";
				break;

				case 8:
				cout<<"\U0001F0D8";
				break;

				case 9:
				cout<<"\U0001F0D9";
				break;

				case 10:
				cout<<"\U0001F0DA";
				break;

				case 11:
				cout<<"\U0001F0DB";
				break;

				case 12:
				cout<<"\U0001F0DD";
				break;

				case 13:
				cout<<"\U0001F0DE";
				break;
			}
		break;

		default :
		cerr<<"erreur de signe des cartes\n";
  }
}

int Carte::getNumero() const{
  return numero;
}

char Carte::getSigne() const{
  return signe;
}

void echangerCarte(Carte &a,Carte &b){
  Carte c;
  if(DEBUG == 3){
    cout<< endl << "cartes avant échange : " <<endl;
    a.afficherCarte();
    cout << "  ";
    b.afficherCarte();
  }
  c=a;a=b;b=c;
  if(DEBUG == 3){
    cout << endl << "cartes après échange : "<<endl;
    a.afficherCarte();
    cout << "  ";
    b.afficherCarte();
    cout << endl <<"------------------------------------";
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    
  }
}
