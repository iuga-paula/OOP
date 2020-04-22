#include "Garnitura.h"
#include <bits/stdc++.h>

using namespace std;

Garnitura::Garnitura(double pret, string carne, string tip_fel, string leguma_principala, string tip):
    Fel_principal(pret,carne,tip_fel), leguma_principala(leguma_principala), tip_garnitura(tip)
{

}

Garnitura::Garnitura(const Garnitura &ob)
{
    pret = ob.pret;

    leguma_principala = ob.leguma_principala;
    tip_garnitura = ob.tip_garnitura;
}

Garnitura::~Garnitura()
{
    leguma_principala = "";
    tip_garnitura = "";

}

void Garnitura::set_tip_garnitura(string leguma, string nume)
{
    leguma_principala = leguma;
    tip_garnitura = nume;

}

double Garnitura::get_pret()
{
    return pret;
}

string Garnitura::get_tip_garnitura()
{
    return leguma_principala + " " + tip_garnitura;
}

Garnitura Garnitura::operator=(const Garnitura &ob)
{
    if(this!=&ob)
    {

        this->Fel_principal::operator=(ob);
        leguma_principala = ob.leguma_principala;
        tip_garnitura = ob.tip_garnitura;
    }
    return *this;
}

ostream& operator<< (ostream &out, Garnitura &garnitura)
{
    out<<"pt garnitura "<<garnitura.leguma_principala<<" cu denumirea "<<garnitura.tip_garnitura;
    out<<" pretul este ";
    out<<garnitura.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Garnitura &garnitura)
{
    cout<<"dati din ce vreti garnitura:\n ";
    in>>garnitura.leguma_principala;
    cout<<"dati modul de perparare:\n";
    in>>garnitura.tip_garnitura;

    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    garnitura.set_pret(pr);
    return  in;
}
