#include "Bauturi.h"
#include <bits/stdc++.h>

using namespace std;

Bauturi::Bauturi(double pret):pret_mediu(pret)
{

}

Bauturi::Bauturi(const Bauturi &ob)
{
    pret_mediu = ob.pret;
}

Bauturi::~Bauturi()
{
    pret_mediu = 0;
}

Bauturi Bauturi::operator=(const Bauturi &ob)
{
    if(this!=&ob)
    {
        this->Vin_la_sticla::operator=(ob);
        this->Vin_varsat::operator=(ob);
        this->Bere_la_sticla::operator=(ob);

        pret_mediu = ob.pret_mediu;

    }
    return *this;
}
ostream& operator<< (ostream &out, Bauturi &b)
{
    out<<"pretul mediu al bauturilor este "<<b.pret_mediu;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Bauturi &b)
{
    cout<<"dati pretul mediu al bauturilor:\n ";
    in>>b.pret_mediu;
    return  in;
}
