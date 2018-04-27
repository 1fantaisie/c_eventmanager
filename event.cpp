
#include "tree.h"
event* event::pInstance_ = 0;
  event* event::Instance()
{
    if (!pInstance_)
    pInstance_ = new event;
    return pInstance_;
 }

    vector <my_pair> event::get_vector (char * name )
 {
        map<char*,vector <my_pair>>::iterator it;
        it=ev_list.find(name);
        if(it!= ev_list.end())
            return it->second;
        vector <my_pair> empty_v;
        return empty_v;
    }
void event::add(char *name, void (*f) (void *),void * temp)
    {
        vector <my_pair> y;
         y=get_vector(name);
        my_pair element;
        element.pointer=f;
        element.x=temp;
        y.push_back(element);
        ev_list[name]=y;
    }
void event::occur ( char * name)
{
        map <char *,vector < my_pair>> ::iterator it;
         it = ev_list.find(name);
         vector <my_pair> v=it->second;
         for(int i=0;i<v.size();i++)
            v[i].pointer(v[i].x);

}
  void event::show_all ()
    {
        cout<<endl<<"Toate obiectele conectate";
        for (map<char*,vector <my_pair>>::iterator it=ev_list.begin(); it!=ev_list.end(); ++it)
        {
            cout<<endl;
            cout << it->first << " : " ;//<< it->second << '\n';
            vector <my_pair> v=it->second;
            for(int i=0;i<v.size();i++)
            v[i].pointer(v[i].x);
        }
    }
     void event::del(char * name, void *temp)
    {
        map <char *,vector < my_pair>> ::iterator it;
         it = ev_list.find(name);
         vector <my_pair>::iterator vec_it;
        for(vec_it = (*it).second.begin(); vec_it != (*it).second.end(); ++vec_it )
            if(temp==vec_it->x)
                vec_it = it->second.erase(vec_it);
    }
