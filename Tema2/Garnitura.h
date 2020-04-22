#ifndef GARNITURA_H_INCLUDED
#define GARNITURA_H_INCLUDED

#include "Fel_principal.h"
#include <bits/stdc++.h>

using namespace std;

class Garnitura:public Fel_principal
{

private:
    string leguma_principala;
    string tip_garnitura;

public:
    Garnitura(double pret = 25, string carne = "pui", string tip_fel = "frigarui", string leguma_principala = "cartofi", string tip ="prajiti");

    Garnitura(const Garnitura&);
    ~Garnitura();
    void afiseara_pret() override
    {
        cout<<pret;
    }

    void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(leguma_principala == "cartofi"  && tip_garnitura == "piure")
            cost = cost + 3;
        else if (leguma_principala == "orez" && tip_garnitura == "sarbesc")
            cost = cost + 5;

        Meniu::set_pret(cost);
    }

    double get_pret();
    string get_tip_garnitura();
    void set_tip_garnitura(string, string);
    Garnitura operator=(const Garnitura &);
    friend ostream& operator<< (ostream &out, Garnitura &garnitura);
    friend istream& operator>> (istream &in,  Garnitura &garnitura);


};

#endif // GARNITURA_H_INCLUDED
