#include "catalog_inividual.h"
#include <bits/stdc++.h>
using namespace std;




int Catalog_Individual<Quizz>::contor_maticol = 0;
unordered_set<string> Catalog_Individual<Quizz>::elevi = {""};

Catalog_Individual<Quizz>::Catalog_Individual()
{
    contor_maticol++;
    nr_examen_curent = 0;
    nr_matricol = contor_maticol;

}


Catalog_Individual<Quizz>::Catalog_Individual(const Catalog_Individual<Quizz>& ob)
{
    nr_matricol = ob.nr_matricol;
    structura_date = ob.structura_date;

}


Catalog_Individual<Quizz>::~Catalog_Individual()
{
    nr_matricol = 0;
    nr_examen_curent = 0;
    structura_date.clear();
   /// elevi.clear();
}


Catalog_Individual<Quizz> Catalog_Individual<Quizz>::operator=(const Catalog_Individual<Quizz>& ob)
{
    if(this != &ob)
    {
        nr_matricol = ob.nr_matricol;
        structura_date = ob.structura_date;
        nr_quizzuri = ob.nr_quizzuri;

    }
    return *this;
}


int Catalog_Individual<Quizz>::get_nr_matricol()
{
    return nr_matricol;
}


int Catalog_Individual<Quizz>::get_nr_examene()
{
    return nr_examen_curent;
}


void Catalog_Individual<Quizz>::afisare()
{
    cout<<" nr matricol  "<<nr_matricol<<"\n";
    if(structura_date.empty() == true)
        cout<<"studentul nu a sustinut acest tip de examene\n";
    else
    {
        cout<<"acesta a dat examenele:\n";
        for(auto &it: structura_date)
        {

            it.afisare();
            ///cout<<"\n";

        }
    }

}


Catalog_Individual<Quizz> Catalog_Individual<Quizz>::operator+=(const Quizz&ob)
{



    nr_examen_curent++;
    structura_date.push_back(ob);
    return *this;

}

template <>
istream&operator>> (istream &in, Catalog_Individual<Quizz>&ob)
{
    cout<<"dati nr maricol:\n";
    in>>ob.nr_matricol;
    cout<<"dati nr de examene sustinute:\n";
    in>>ob.nr_examen_curent;

    for(int i = 0; i <ob.nr_examen_curent; i++)
    {
        Quizz x;
        cout<<"dati examenul\n";
        in>>x;
    }

    return in;
}


void Catalog_Individual<Quizz>::set_studentii_care_au_2quizzuri(string nume, int nr_quizzuri)
{


    if (nr_quizzuri >=2)
    {
        if(elevi.find(nume) == elevi.end())  ///daca numele nu e in set;
            elevi.insert(nume);


    }


}


void Catalog_Individual<Quizz>::afiseaza_sudentii_care_au_dat_2quizzuri()
{
    for (auto const& i: elevi)
    {
        cout << i << " ";
    }
}
