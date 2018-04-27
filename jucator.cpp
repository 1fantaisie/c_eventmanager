#include <iostream>
#include "tree.h"
using namespace std;
 void jucator::occ()
  {
        cout<<endl<<"Current obj:";
        cout<<this->info;

  }
 void jucator :: call (void * y)
 {
     {
         jucator * obj =(jucator *) y;
        obj->occ();
}
 }
   jucator::jucator()
  {
      info=0;
  }
  jucator ::jucator(int x)
  {
      info =x;
  }
    int jucator::get_info()
    {
        return info;
    }
