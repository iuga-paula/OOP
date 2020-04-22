#include "Apa.h"
#include <bits/stdc++.h>

using namespace std;

Apa::Apa(double pret, string denumire):Meniu(pret),denumire(denumire)
{

}

Apa::Apa(const Apa &ob)
{
    pret = ob.pret;

    denumire = ob.denumire;
}

Apa::~Apa()
{
    denumire = "";
}

void Apa::set_tip_apa(string denumire)
{
    this->denumire = denumire;
}

double Apa::get_pret()
{
    return pret;
}

string Apa::get_tip_apa()
{
    return denumire;
}

Apa Apa::operator=(const Apa &ob)
{
    if(this!=&ob)
    {

        denumire = ob.denumire;

    }
    return *this;
}

ostream& operator<< (ostream &out, Apa &apa)
{
    out<<"pt sticla de apa"<<apa.denumire;
    out<<" pretul este ";
    out<<apa.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Apa &apa)
{
    cout<<"dati ce marca de apa la sticla doriti:\n ";
    in>>apa.denumire;
    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    apa.set_pret(pr);
    return  in;
}
