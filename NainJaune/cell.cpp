#include "cell.h"


Cell::Cell()
{
  suiv=NULL; prec=NULL;
}


Cell::Cell(TypeVal v) : val(v)
{
  suiv=NULL; prec=NULL;
}


void Cell::operator=(const Cell& c)
{
  this->prec=prec;
  this->suiv=suiv;
  this->val=val;
}


TypeVal Cell::getVal() const
{
  return val;
}


void Cell::setVal(TypeVal v)
{
  val=v;
}

 
Cell* Cell::getPrec() const
{
  return prec;
}


void Cell::setPrec(Cell* c)
{
  prec=c;
}


Cell* Cell::getSuiv() const
{
  return suiv;
}


void Cell::setSuiv(Cell* c)
{
  suiv=c;
}
