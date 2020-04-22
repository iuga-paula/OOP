#include "Client.h"
#include <bits/stdc++.h>

using namespace std;

Client::Client(int nr_client, double total, string comanda):nr_client(nr_client),total(total), comanda(comanda)
{

}

Client::Client(Client &ob)
{
    nr_client = ob.nr_client;
    total = ob.total;
    comanda = ob.comanda;

}


Client::~Client()
{
    total = 0;
    comanda.clear();

}

ostream& operator<< (ostream &out, const Client &client)
{
    out<<"Clientul cu nr "<<client.nr_client;
    out<<" pt comanda "<<client.comanda<<" aveti de platit "<<client.total;
    return out;

}

istream& operator>> (istream &in, Client &client)
{
    cout<<"dati nr client\n ";
    in>>client.nr_client;
    cout<<" dati comanda:\n";
    in>>client.comanda;

    return in;

}

Client Client ::operator=(const Client &ob)
{
    if(this!=&ob)
    {
        nr_client = ob.nr_client;
        comanda = ob.comanda;
        total = ob.total;
    }
    return *this;
}

int Client::get_nr_client()
{
    return nr_client;

}

double  Client::get_total()
{
    return total;
}

string Client::get_comanda()
{
    return comanda;
}

void Client::set_comanda(string s)
{
    comanda = s;

}

void Client::set_nr_client(int nr)
{
    nr_client = nr;
}

void Client::adauga_la_total(double  pret)
{
    total = get_total() + pret;

}

void Client::adauga_la_comanda(string element)
{
    if(get_comanda() != "")
    comanda = get_comanda() + ", " + element;
    else
        comanda = get_comanda() + " " + element;
}
