#ifndef CIROBA_H_INCLUDED
#define CIROBA_H_INCLUDED
#include "Meniu.h"

#include <bits/stdc++.h>

using namespace std;

class Ciorba:public Meniu
{

private:
    string tip_ciorba;
    bool smantana;
    bool ardei;

public:
    Ciorba(double pret = 5, string tip_ciorba = "ciuperci", bool smantana = false, bool ardei = false);
    Ciorba(const Ciorba&);
    ~Ciorba();
    void afiseara_pret() override /// nu mai e clasa abstracta
    {
        cout<<pret;
    }

    void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(tip_ciorba == "legume")
            cost = cost + 5;
        else if(tip_ciorba == "burta")
            cost = cost +10;
        if(smantana == true)
            cost += 2;
        if(ardei == true)
            cost += 2;

        Meniu::set_pret(cost);
    }

    double get_pret();
    string get_tip();
    void set_tip_ciorba(string, bool, bool);
    Ciorba operator=(const Ciorba &);
    friend ostream& operator<< (ostream &out, Ciorba &ciorba);
    friend istream& operator>> (istream &in, Ciorba &ciorba);


};
#endif // CIROBA_H_INCLUDED
