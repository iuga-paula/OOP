#ifndef APA_H_INCLUDED
#define APA_H_INCLUDED

#include "Meniu.h"
#include <bits/stdc++.h>

using namespace std;


class Apa:virtual public Meniu
{
private:
    string denumire;

public:
    Apa(double pret = 25, string denumire = "Dorna");

    Apa(const Apa&);
    ~Apa();
    void afiseara_pret() override ///nu mai e clasa abstracta
    {
        cout<<pret;
    }

    virtual void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(denumire == "Acua Carpatica")
            cost = cost + 2;
        else
            cost = cost + 1;

        Meniu::set_pret(cost);
    }

    double get_pret();
    string get_tip_apa();
    void set_tip_apa(string);
    Apa operator=(const Apa &);
    friend ostream& operator<< (ostream &out, Apa &apa);
    friend istream& operator>> (istream &in, Apa &apa);

};
#endif // APA_H_INCLUDED
