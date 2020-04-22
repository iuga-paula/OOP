#include "Ciroba.h"
#include <bits/stdc++.h>

using namespace std;

Ciorba::Ciorba(double pret, string tip_ciorba, bool smantana, bool ardei):Meniu(pret),tip_ciorba(tip_ciorba),smantana(smantana), ardei(ardei)
{

}

Ciorba::Ciorba(const Ciorba &ob)
{
    pret = ob.pret;

    tip_ciorba = ob.tip_ciorba;
    smantana = ob.smantana;
    ardei = ob.ardei;
}

Ciorba::~Ciorba()
{
    tip_ciorba = "";
    smantana = false;
    ardei = false;

}

void Ciorba::set_tip_ciorba(string tip, bool smantana, bool ardei)
{
    tip_ciorba = tip;
    this->smantana = smantana;
    this->ardei = ardei;

}
double Ciorba::get_pret()
{
    return pret;
}

string Ciorba::get_tip()
{
    return tip_ciorba;
}

Ciorba Ciorba::operator=(const Ciorba &ob)
{
    if(this!=&ob)
    {

        pret = ob.pret;
        tip_ciorba = ob.tip_ciorba;
        smantana = smantana;
        ardei = ardei;
    }
    return *this;
}

ostream& operator<< (ostream &out, Ciorba &ciorba)
{
    out<<"pt ciorba "<<ciorba.tip_ciorba;
    if(ciorba.smantana == true)
        out<<" cu smantana";
    if(ciorba.ardei == true)
        out<<" cu ardei";
    out<<"pretul este ";
    out<<ciorba.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Ciorba &ciorba)
{
    cout<<"dati tipul de ciorba:\n ";
    in>>ciorba.tip_ciorba;
    string s;
    cout<<"doriti cu smantana?:\n";
    in>>s;
    if(s=="da")
        ciorba.smantana = true;
    else
        ciorba.smantana = false;

    cout<<"doriti cu adei?:\n";
    in>>s;
    if(s=="da")
        ciorba.ardei = true;
    else
        ciorba.ardei = false;

    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    ciorba.set_pret(pr);
    return  in;
}

