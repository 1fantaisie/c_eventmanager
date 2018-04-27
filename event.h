#include<map>
#include <vector>
#include <iostream>
using namespace std;
typedef struct my_pair
{
     typedef void (*MFP)(void *);
        MFP pointer; // pointer to function to be called
        void * x ; // object adress
};


class event
{
     map<char*,vector <my_pair> > ev_list;

public:
 static event* Instance(); // Unique point of access

    vector <my_pair> get_vector (char * name ); // returns the objects vector with the specified event name
     void add(char *name, void (*f) (void *),void * temp); // connect an object to manager
     void del (char *name,void *temp); // delete an object from manager
    void occur ( char * name); // triggers an action
    void show_all (); // shows all objects connected to manager


private:
 event() {}; // Prevent clients from creating a new event
 event(const event&);
 static event* pInstance_;
 };


