#ifndef BERE_LA_STICLA_H_INCLUDED
#define BERE_LA_STICLA_H_INCLUDED

#include "Meniu.h"

#include <bits/stdc++.h>

using namespace std;

class Bere_la_sticla: virtual public Meniu
{
private:
    string denumire;
    bool alcool;

public:
    Bere_la_sticla(double pret = 15, string denumire = "Ursus", bool alcool = true);
    Bere_la_sticla(const Bere_la_sticla&);
    ~Bere_la_sticla();
    void afiseara_pret() override ///nu mai e clasa abstracta
    {
        cout<<pret;
    }

    virtual void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(denumire == "Bergenbir")
            cost = cost + 3;
        else if(denumire == "Tuborg")
            cost = cost + 5;
        else if(denumire == "Heineken")
            cost += 7;

        Meniu::set_pret(cost);
    }

    double get_pret();
    string get_tip_bere_la_sticla();
    void set_tip_bere_la_sticla(string, bool);
    Bere_la_sticla operator=(const Bere_la_sticla &);
    friend ostream& operator<< (ostream &out, Bere_la_sticla &bere);
    friend istream& operator>> (istream &in, Bere_la_sticla &bere);

};

#endif // BERE_LA_STICLA_H_INCLUDED
