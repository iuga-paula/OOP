#include "Bere_la_sticla.h"
#include <bits/stdc++.h>

using namespace std;

Bere_la_sticla::Bere_la_sticla(double pret, string denumire, bool alcool):Meniu(pret),denumire(denumire),alcool(alcool)
{

}

Bere_la_sticla::Bere_la_sticla(const Bere_la_sticla &ob)
{
    pret = ob.pret;

    denumire = ob.denumire;
    alcool = ob.alcool;
}

Bere_la_sticla::~Bere_la_sticla()
{
    denumire = "";
    alcool = false;

}

void Bere_la_sticla::set_tip_bere_la_sticla(string denumire, bool alcool)
{
    this->denumire = denumire;
    this->alcool = alcool;

}

double Bere_la_sticla::get_pret()
{
    return pret;
}

string Bere_la_sticla::get_tip_bere_la_sticla()
{
    return denumire;
}

Bere_la_sticla Bere_la_sticla::operator=(const Bere_la_sticla &bere)
{
    if(this!=&bere)
    {

        denumire = bere.denumire;
        alcool = bere.alcool;
    }
    return *this;
}

ostream& operator<< (ostream &out, Bere_la_sticla &bere)
{
    out<<"pt berea la sticla "<<bere.denumire;
    if(bere.alcool == true)
        out<<" cu alcool";
    else
        cout<<" fara alcool";
    out<<" pretul este ";
    out<<bere.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Bere_la_sticla &bere)
{
    cout<<"dati ce marca de bere la sticla doriti:\n ";
    in>>bere.denumire;

    string s;
    cout<<"doriti cu alcool?:\n";
    in>>s;
    if(s=="da")
        bere.alcool = true;
    else
        bere.alcool = false;
    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    bere.set_pret(pr);
    return  in;
}
