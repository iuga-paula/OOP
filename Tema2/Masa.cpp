#include "Masa.h"
#include <bits/stdc++.h>

using namespace std;

Masa::Masa(int nr_clienti1, int capacitate_masa1): nr_clienti(nr_clienti1), capacitate_masa(capacitate_masa1)
    {
        masa_clienti = new Client[capacitate_masa1];
    }

Masa::Masa(const Masa &ob):masa_clienti(ob.masa_clienti)
{
    capacitate_masa = ob.capacitate_masa;
    nr_clienti = ob.nr_clienti;
    for(int i=0; i<capacitate_masa; i++)
    {
        masa_clienti[i] = ob.masa_clienti[i];
    }


}

Masa::~Masa()
{
    capacitate_masa = nr_clienti = 0;
    delete []masa_clienti;
}

Masa Masa::operator=(const Masa &ob)
{
    if(this!=&ob)
    {
        nr_clienti = ob.nr_clienti;
        capacitate_masa = ob.capacitate_masa;
        masa_clienti = ob.masa_clienti;

    }
    return *this;
}

ostream& operator<< (ostream &out, const Masa &masa)
{

    out<<"la masa sunt ocupate  "<<masa.nr_clienti<<" locuri din "<<masa.capacitate_masa<<"\n";
    out<<"clientii de la masa + ce au comandat fiecare sunt:\n";
    for(int i=0; i<masa.nr_clienti; i++)
    {

        out<<"clientul cu nr "<<masa.masa_clienti[i].get_nr_client()<<" a comandat "<<masa.masa_clienti[i].get_comanda()<<" si are de platit "<<masa.masa_clienti[i].get_total()<<" lei\n";
    }
    return out;
}

istream& operator>>(istream &in, Masa &masa)
{

    string s;
    s = new char[250];
    cout<<"dati capacitatea mesei:\n";
    in>>masa.capacitate_masa;
    cout<<"dati nr de clienti care sosesc la masa:\n";
    in>>masa.nr_clienti;
    cout<<"dati ce comanda fiecare client pe rand CU VIRGULE FARA SPATIU:\n";
    for(int i=0; i<masa.nr_clienti; i++)
    {
        masa.masa_clienti[i].set_nr_client(i);
        cout<<"pt clientul cu numarul "<<masa.masa_clienti[i].get_nr_client()<<"\n";
        in>>s;
        masa.masa_clienti[i].set_comanda(s);

    }
    cout<<"\n";

}

void Masa::adauga_client_la_masa()
{
    if(nr_clienti+1 <= capacitate_masa)
    {
        nr_clienti++;
        masa_clienti[nr_clienti].set_nr_client(nr_clienti);
    }
    else
    {
        throw "nu mai e loc la masa";
        //cout<<"nu mai e loc la aceasta masa!";
    }

}

void Masa::adauga_comanda_la_client(string element, int nr_client)
{
    if(nr_client < capacitate_masa)
        masa_clienti[nr_client].adauga_la_comanda(element);

}


void Masa::adauga_pret_la_total_client(double pret, int nr_client)
{
    if(nr_client < capacitate_masa)
        masa_clienti[nr_client].adauga_la_total(pret);

}

double Masa::calculeaza_total_per_client(int nr_client)
{
    if(nr_client < capacitate_masa)
        return masa_clienti[nr_client].get_total();
}

double Masa::calculeaza_total_per_masa()
{
    double total_per_masa = 0;
    for(int i=0; i<nr_clienti; i++)
    {
        total_per_masa += masa_clienti[i].get_total();
    }
    return total_per_masa;
}

void Masa::afiseaza_nota_per_client(int nr_client)
{
    //masa_clienti[nr_client]->Client::operator<<;
    cout<<masa_clienti[nr_client];
    cout<<" lei\n";
}

void Masa::afiseaza_nota_per_masa()
{
    cout<<*this;
    cout<<"Totalul de achitat este: ";
    cout<<calculeaza_total_per_masa();
    cout<<" lei\n";
}

Masa* Masa::memorare_afisare_n_obiecte()
{
    int n;
    cout<<"dati numarul de mese:\n";
    cin>>n;
    Masa a[n];
    for (int i=0; i<n; i++)
        cin>>a[i];

    cout<<"\n";
    for (int i=0; i<n; i++)
        cout<<a[i];

    return a;

}
