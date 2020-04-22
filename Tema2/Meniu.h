#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED
#include <bits/stdc++.h>

using namespace std;

class Meniu  ///clasa abstracta;
{

protected:
    double pret;

public:
    virtual void afiseara_pret() = 0;///functie virtuala pura;
    Meniu();
    Meniu(double);
    Meniu(const Meniu&);
    virtual ~Meniu();
    virtual void set_pret(double);

};

#endif // MENIU_H_INCLUDED
