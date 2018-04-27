#include <iostream>
#include "tree.h"

using namespace std;
int main()
{
    jucator j1(1), j2(2),j3(3),j4(4);
   // cout<<j1.get_info();
    base_object * ex=&j1;
    event::Instance()->add("pass",&jucator::call,&j1);
   event::Instance()->add("pass",&jucator::call,&j2);
   event::Instance()->add("pass",&jucator::call,&j3);
    event::Instance()->add("play",jucator::call,&j4);
    event::Instance()->occur("pass");
    event::Instance()->del("pass",&j1);
    event::Instance()->show_all();
    return 0;
}
