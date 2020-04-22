#include "Fel_principal.h"
#include <bits/stdc++.h>

using namespace std;

Fel_principal::Fel_principal(double pret, string carne, string tip_fel):Meniu(pret),carne(carne),tip_fel(tip_fel)
{

}

Fel_principal::Fel_principal(const Fel_principal &ob)
{
    pret = ob.pret;

    carne = ob.carne;
    tip_fel = ob.tip_fel;
}


void Fel_principal::set_tip_fel(string carne, string fel)
{
    this->carne = carne;
    tip_fel = fel;

}
double Fel_principal::get_pret()
{
    return pret;
}

string Fel_principal::get_tip_fel()
{
    return carne + " " + tip_fel;
}

Fel_principal Fel_principal::operator=(const Fel_principal &ob)
{
    if(this!=&ob)
    {

        pret = ob.pret;
        carne = ob.carne;
        tip_fel = ob.tip_fel;
    }
    return *this;
}

ostream& operator<< (ostream &out, Fel_principal &fel)
{
    out<<"pt felul principal din care de "<<fel.carne<<" cu denumirea "<<fel.tip_fel;
    out<<" pretul este ";
    out<<fel.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Fel_principal &fel)
{
    cout<<"dati tipul de carne:\n ";
    in>>fel.carne;
    cout<<"dati denumirea felului:\n";
    in>>fel.tip_fel;

    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    fel.set_pret(pr);
    return  in;
}
