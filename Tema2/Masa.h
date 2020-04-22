#ifndef MASA_H_INCLUDED
#define MASA_H_INCLUDED

#include "Client.h"
#include <bits/stdc++.h>

using namespace std;

class Masa
{

private:
    Client *masa_clienti;//Compozitie: vector de clienti pe poz i vom avea clientul cu nr i care are comanada invididuala +total
    int capacitate_masa;
    int nr_clienti;

public:
    Masa(int nr_clienti1 = 0, int capacitate_masa1 = 15);
    Masa(const Masa &);
    ~Masa();
    friend ostream& operator<< (ostream &out,  const Masa &masa);
    friend istream& operator>> (istream &in, Masa &masa);
    Masa operator=(const Masa &);
    void adauga_client_la_masa();
    double  calculeaza_total_per_masa();
    double calculeaza_total_per_client(int);
    void adauga_comanda_la_client(string, int);
    void adauga_pret_la_total_client(double, int);
    Client operator[](int i);
    void afiseaza_nota_per_masa();
    void afiseaza_nota_per_client(int);

    Masa *memorare_afisare_n_obiecte();


};


#endif // MASA_H_INCLUDED
