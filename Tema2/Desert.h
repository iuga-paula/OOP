#ifndef DESERT_H_INCLUDED
#define DESERT_H_INCLUDED

#include "Meniu.h"
#include <bits/stdc++.h>

using namespace std;

class Desert:public Meniu
{

private:
    string tip_desert;
    int nr_cupe;

public:
    Desert(double pret = 5, string tip_desert = "inghetata", int nr_cupe = 0);
    Desert(const Desert&);
    ~Desert();
    void afiseara_pret() override ///Desert nu mai e clasa abstracta
    {
        cout<<pret;
    }

    void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(tip_desert == "inghetata" && nr_cupe==3)
            Meniu::set_pret(cost + 5);
        else if(tip_desert == "inghetata" && nr_cupe==4)
            Meniu::set_pret(cost + 10);
        else if(tip_desert == "inghetata" && nr_cupe==5)
            Meniu::set_pret(cost + 15);
        else
            Meniu::set_pret(cost);
    }

    virtual double get_pret();
    string get_tip();
    void set_tip_desert(string, int);
    Desert operator=(const Desert &);
    friend ostream& operator<< (ostream &out, Desert &desert);
    friend istream& operator>> (istream &in, Desert &desert);


};


#endif // DESERT_H_INCLUDED
