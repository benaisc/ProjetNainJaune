#include "carte.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char ** argv){
  Carte c1(13,'s');
  Carte c2(10,'c');
  Carte c3(10,'d');
  Carte c4(10,'h');
  Carte c5(10,'s');
  Carte c6(11,'c');
  Carte c7(9,'c');
  Carte c8(14,'c');
  c1.afficherCarte();
cout<<endl;
  c2.afficherCarte();
cout<<endl;
  c3.afficherCarte();
cout<<endl;
  c4.afficherCarte();
cout<<endl;
  c5.afficherCarte();
cout<<endl;
  c6.afficherCarte();
cout<<endl;
  c7.afficherCarte();
cout<<endl;
  c8.afficherCarte();
cout<<endl;
  cout << "C2 getNumero : " << c2.getNumero() << " getSigne : " << c2.getSigne() << endl;
  cout << "C1 getNumero : " << c1.getNumero() << " getSigne : " << c1.getSigne() << endl;

  if(c2.estSuperieure(c3))
    cout << "La carte c2 est supérieure à c3." << endl;
  else
    cout << "La carte c2 est inférieure à c3." << endl;


  if(c2.estSuperieure(c4))
    cout << "La carte c2 est supérieure à c4." << endl;
  else
    cout << "La carte c2 est inférieure à c4." << endl;


  if(c2.estSuperieure(c5))
    cout << "La carte c2 est supérieure à c5." << endl;
  else
    cout << "La carte c2 est inférieure à c5." << endl;


  if(c2.estSuperieure(c6))
    cout << "La carte c2 est supérieure à c6." << endl;
  else
    cout << "La carte c2 est inférieure à c6." << endl;


  if(c2.estSuperieure(c7))
    cout << "La carte c2 est supérieure à c7." << endl;
  else
    cout << "La carte c2 est inférieure à c7." << endl;

  if(c2.estSuperieure(c8))
    cout << "La carte c2 est supérieure à c8." << endl;
  else
    cout << "La carte c2 est inférieure à c8." << endl;
  
  return 0;
}



