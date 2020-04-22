#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#pragma once
#include <bits/stdc++.h>

using namespace std;

class Client
{
private:
    int nr_client;
    string comanda;//ce a comandat un client
    double total;//totalul de achitat pt un client

public:
    Client(int nr_client = 0, double total = 0, string comanda = "");
    Client(Client &);
    ~Client();
    friend ostream& operator<< (ostream &out,  const Client &client);
    friend istream& operator>> (istream &in, Client &client);
    Client operator=(const Client &);
    int get_nr_client();
    double  get_total();
    string get_comanda();
    void set_nr_client(int);
    void set_comanda(string);
    void adauga_la_comanda(string);
    void adauga_la_total(double);


};


#endif // CLIENT_H_INCLUDED
