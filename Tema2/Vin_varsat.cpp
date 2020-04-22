#include "Vin_varsat.h"
#include <bits/stdc++.h>
using namespace std;

Vin_varsat::Vin_varsat(double pret, string culoare, double cantitate):Meniu(pret),culoare(culoare),cantitate(cantitate)
{

}

Vin_varsat::Vin_varsat(const Vin_varsat &ob)
{
    pret = ob.pret;

    culoare = ob.culoare;
    cantitate = ob.cantitate;
}

Vin_varsat::~Vin_varsat()
{
    cantitate = 0;
    culoare = "";

}

void Vin_varsat::set_tip_vin_varsat(string culoare, double nr)
{
    this->culoare = culoare;
    cantitate = nr;
    if(nr == 0)
        throw nr;

}

double Vin_varsat::get_pret()
{
    return pret;
}

string Vin_varsat::get_tip_vin_varsat()
{
    return culoare;
}

Vin_varsat Vin_varsat::operator=(const Vin_varsat &ob)
{
    if(this!=&ob)
    {

        culoare = ob.culoare;
        cantitate = ob.cantitate;
    }
    return *this;
}

ostream& operator<< (ostream &out, Vin_varsat &vin)
{
    out<<"pt vinul varsat "<<vin.culoare<<vin.cantitate<<" mililitri";
    out<<" pretul este ";
    out<<vin.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Vin_varsat &vin)
{
    cout<<"dati ce culoare de vin varsat doriti:\n ";
    in>>vin.culoare;
    cout<<"dati cantitatea:\n";
    in>>vin.cantitate;

    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    vin.set_pret(pr);
    return  in;
}
