#ifndef __CELL_H__
#define __CELL_H__

#include "carte.h"
using namespace std;
#define TypeVal Carte


class Cell{
  
  private:
    Cell* prec;
    Cell* suiv;
    TypeVal val;

  public:
    Cell();
    Cell(TypeVal);

    TypeVal getVal() const;
    Cell* getPrec() const;
    Cell* getSuiv() const;
    void operator=(const Cell&);
    void setVal(TypeVal);
    void setPrec(Cell*);
    void setSuiv(Cell*);  

};
#endif
