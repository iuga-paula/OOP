#include "Desert.h"
#include <bits/stdc++.h>

using namespace std;

Desert::Desert(double pret, string tip_desert, int nr_cupe):Meniu(pret),tip_desert(tip_desert),nr_cupe(nr_cupe)
{

}

Desert::Desert(const Desert &ob)
{
    pret = ob.pret;

    tip_desert = ob.tip_desert;
    nr_cupe = ob.nr_cupe;
}
Desert::~Desert()
{
    tip_desert = "";
    nr_cupe = 0;

}

void Desert::set_tip_desert(string tip, int nr_cupe)
{
    tip_desert  = tip;
    this->nr_cupe = nr_cupe;
    if(tip_desert == "inghetata" && (nr_cupe < 3 || nr_cupe >5))
        throw 0;


    if(tip != "inghetata" && nr_cupe > 0)
        throw 0;



}
double Desert::get_pret()
{
    return pret;
}

string Desert::get_tip()
{
    return tip_desert;
}

Desert Desert::operator=(const Desert &ob)
{
    if(this!=&ob)
    {

        pret = ob.pret;
        tip_desert = ob.tip_desert;
        nr_cupe = ob.nr_cupe;
    }
    return *this;
}

ostream& operator<< (ostream &out, Desert &desert)
{
    out<<"pt desertul "<<desert.tip_desert<<" pretul este ";
    out<<desert.pret;
    if(desert.tip_desert == "inghetata")
        out<<" si nr de cupe este "<<desert.nr_cupe;
    return out;
}

istream& operator>> (istream &in, Desert &desert)
{
    cout<<"dati tipul de desert:\n ";
    in>>desert.tip_desert;
    if(desert.tip_desert == "inghetata")
    {
        cout<<"dati nr cupe: ";
        in>>desert.nr_cupe;
    }
    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    desert.set_pret(pr);
    return  in;
}
