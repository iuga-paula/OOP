#include "Vin_la_sticla.h"
#include <bits/stdc++.h>
using namespace std;

Vin_la_sticla::Vin_la_sticla(double pret, string denumire, int an):Meniu(pret),denumire(denumire),an(an)
{

}

Vin_la_sticla::Vin_la_sticla(const Vin_la_sticla &ob)
{
    pret = ob.pret;

    denumire = ob.denumire;
    an = ob.an;
}

Vin_la_sticla::~Vin_la_sticla()
{
    denumire = "";
    an = 0;

}

void Vin_la_sticla::set_tip_vin_la_sticla(string denumire, int an)
{
    this->denumire = denumire;
    this->an = an;

}

double Vin_la_sticla::get_pret()
{
    return pret;
}

string Vin_la_sticla::get_tip_vin_la_sticla()
{
    return denumire;
}

Vin_la_sticla Vin_la_sticla::operator=(const Vin_la_sticla &vin)
{
    if(this!=&vin)
    {

        denumire = vin.denumire;
        an = vin.an;
    }
    return *this;
}

ostream& operator<< (ostream &out, Vin_la_sticla &vin)
{
    out<<"pt vinul la sticla "<<vin.denumire <<" din anul "<<vin.an;
    out<<" pretul este ";
    out<<vin.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Vin_la_sticla &vin)
{
    cout<<"dati ce marca de vin la sticla doriti:\n ";
    in>>vin.denumire;
    cout<<"dati anul de productie:\n";
    in>>vin.an;

    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    vin.set_pret(pr);
    return  in;
}
