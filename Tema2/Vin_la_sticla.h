#ifndef VIN_LA_STICLA_H_INCLUDED
#define VIN_LA_STICLA_H_INCLUDED

#include "Meniu.h"
#include <bits/stdc++.h>
using namespace std;

class Vin_la_sticla:virtual public Meniu
{

private:
    string denumire;
    int an;

public:
    Vin_la_sticla(double pret = 25, string denumire = "Castel Bolovanu", int an = 2004);
    Vin_la_sticla(const Vin_la_sticla&);
    ~Vin_la_sticla();
    void afiseara_pret() override ///nu mai e clasa abstracta
    {
        cout<<pret;
    }

    virtual void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(denumire == "Bordeux")
            cost = cost + 20;
        else
            cost = cost + 10;

        Meniu::set_pret(cost);
    }

    double get_pret();
    string get_tip_vin_la_sticla();
    void set_tip_vin_la_sticla(string, int);
    Vin_la_sticla operator=(const Vin_la_sticla &);
    friend ostream& operator<< (ostream &out, Vin_la_sticla &vin);
    friend istream& operator>> (istream &in, Vin_la_sticla &vin);




};

#endif // VIN_LA_STICLA_H_INCLUDED
