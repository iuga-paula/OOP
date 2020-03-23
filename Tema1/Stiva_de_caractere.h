#ifndef STIVA_DE_CARACTERE_H_INCLUDED
#define STIVA_DE_CARACTERE_H_INCLUDED

#pragma once
#include <bits/stdc++.h>
#include "Nod.h"


using namespace std;


class Stiva_de_caractere
{
private:
    Nod *varf; //varful stivei
    //int nr_elem;

public:
    Stiva_de_caractere();
    ~Stiva_de_caractere();
    Nod *get_varf();

    void parcugere();
    void top();
    void push(char);
    void pop();
    int isempty();
    friend ostream& operator<< (ostream &out,  Stiva_de_caractere &stiva);
    friend istream& operator>> (istream &in, Stiva_de_caractere &stiva);
    string inversare_sir(string &);
    Stiva_de_caractere operator-(Stiva_de_caractere &stiva){ Stiva_de_caractere S2;


    while(!isempty() && !stiva.isempty())
    {

        if(stiva.get_varf() != NULL && get_varf() != NULL)
        {
            if( stiva.get_varf()->get_info() > get_varf()->get_info())
            {

                S2.push(stiva.get_varf()->get_info());
                stiva.pop();
                pop();

            }
            else
            {
                S2.push(get_varf()->get_info());
                pop();
                stiva.pop();
            }
        }

    }

    return S2;
};


     Stiva_de_caractere *memorare();



};



#endif // STIVA_DE_CARACTERE_H_INCLUDED
