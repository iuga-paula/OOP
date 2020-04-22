#ifndef VIN_VARSAT_H_INCLUDED
#define VIN_VARSAT_H_INCLUDED

#include "Meniu.h"
#include <bits/stdc++.h>
using namespace std;

class Vin_varsat:virtual public Meniu
{
private:
    string culoare;
    double cantitate;///in ml;

public:
    Vin_varsat(double pret = 25, string culoare = "rosu", double cantitate = 100);
    Vin_varsat(const Vin_varsat&);
    ~Vin_varsat();
    void afiseara_pret() override ///nu mai e clasa abstracta
    {
        cout<<pret;
    }

    virtual void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(culoare == "rosu")
            cost = cost + (cantitate/10);
        else
            cost = cost + (cantitate)/15;

        Meniu::set_pret(cost);
    }

    double get_pret();
    string get_tip_vin_varsat();
    void set_tip_vin_varsat(string, double);
    Vin_varsat operator=(const Vin_varsat &);
    friend ostream& operator<< (ostream &out, Vin_varsat &vin);
    friend istream& operator>> (istream &in, Vin_varsat &vin);




};

#endif // VIN_VARSAT_H_INCLUDED
