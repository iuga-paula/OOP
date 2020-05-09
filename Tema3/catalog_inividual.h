#ifndef CATALOG_INIVIDUAL_H_INCLUDED
#define CATALOG_INIVIDUAL_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;

#include "quizz.h"
template <class T>
class Catalog_Individual;

template<class T>
istream&operator>>(istream &in, Catalog_Individual<T>&ob);

template <class T>
class Catalog_Individual
{
private:
    int nr_matricol;
    static int contor_maticol;
    int nr_examen_curent;
    vector<T> structura_date;
    //static vector<string> studenti_care_nu_au_trecut_examene;
    static unordered_map<int, vector<string>> umap;

public:
    Catalog_Individual();
    Catalog_Individual(const Catalog_Individual&);
    ~Catalog_Individual();
    Catalog_Individual operator=(const Catalog_Individual&);
    friend istream&operator>> <>(istream &in, Catalog_Individual&ob);
    void afisare();
    int get_nr_matricol();
    int get_nr_examene();
    Catalog_Individual operator+=(const T &examen);
    //void set_lista_cu_examene_picate(string nume_student);
    void set_umapul_cu_studentii_picati(string);
    void afiseaza_umapul_cu_sudentii_picati();



};


template <>
class Catalog_Individual<Quizz>;

template<>
istream&operator>>(istream &in, Catalog_Individual<Quizz>&ob);

template<>
class Catalog_Individual <Quizz>
{
private:
    int nr_quizzuri;
    int nr_matricol;
    static int contor_maticol;
    int nr_examen_curent;
    vector<Quizz> structura_date;
    static unordered_set <string> elevi;//studentii care au dat cel putin 2 quizzuri


public:
    Catalog_Individual();
    Catalog_Individual(const Catalog_Individual&);
    ~Catalog_Individual();
    Catalog_Individual operator=(const Catalog_Individual&);
    friend istream&operator>> <>(istream &in, Catalog_Individual&ob);
    void afisare();
    int get_nr_matricol();
    int get_nr_examene();
    Catalog_Individual operator+=(const Quizz &examen);
    void creste_nr_quizzuri();
    void set_studentii_care_au_2quizzuri(string, int);
    void afiseaza_sudentii_care_au_dat_2quizzuri();


};

template <class  T>
int Catalog_Individual<T>::contor_maticol = 0;

template <class T>
Catalog_Individual<T>::Catalog_Individual()
{
    contor_maticol++;
    nr_examen_curent = 0;
    nr_matricol = contor_maticol;

}

template <class T>
Catalog_Individual<T>::Catalog_Individual(const Catalog_Individual& ob)
{
    nr_matricol = ob.nr_matricol;
    structura_date = ob.structura_date;
    umap = ob.umap;
}

template <class T>
Catalog_Individual<T>::~Catalog_Individual()
{
    nr_matricol = 0;
    nr_examen_curent = 0;
    structura_date.clear();
}

template<class T>
Catalog_Individual<T> Catalog_Individual<T>::operator=(const Catalog_Individual& ob)
{
    if(this != &ob)
    {
        nr_matricol = ob.nr_matricol;
        structura_date = ob.structura_date;
        umap = ob.umap;
    }
    return *this;
}

template<class T>
int Catalog_Individual<T>::get_nr_matricol()
{
    return nr_matricol;
}

template<class T>
int Catalog_Individual<T>::get_nr_examene()
{
    return nr_examen_curent;
}

template<class T>
void Catalog_Individual<T>::afisare()
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

template<class T>
Catalog_Individual<T> Catalog_Individual<T>::operator+=(const T &ob)
{



    nr_examen_curent++;
    structura_date.push_back(ob);
    return *this;

}

template <class T>
istream&operator>> (istream &in, Catalog_Individual<T>&ob)
{
    cout<<"dati nr maricol:\n";
    in>>ob.nr_matricol;
    cout<<"dati nr de examene sustinute:\n";
    in>>ob.nr_examen_curent;
    for(int i = 0; i <ob.nr_examen_curent; i++)
    {
        T x;
        cout<<"dati examenul\n";
        in>>x;
    }

    return in;
}
//template<class T>
//vector<string> Catalog_Individual<T>::studenti_care_nu_au_trecut_examene = {""};

template<class T>
unordered_map<int, vector<string>> Catalog_Individual<T>::umap = {{ 0, {""} }};

template<class T>
void Catalog_Individual<T>::set_umapul_cu_studentii_picati(string nume)
{
    for (unsigned i=0; i<structura_date.size(); i++)
    {
        if (umap.find(structura_date[i].get_id_examen()) == umap.end())
        {
            ///cheia nu a fost introdusa in umap pana acum;
            umap.insert({ structura_date[i].get_id_examen(), {""} });
        }

        if(structura_date[i].get_media() <5 || structura_date[i].get_nota_scris()<5)
        {
            umap[structura_date[i].get_id_examen()].push_back(nume);
        }




    }


}

template<class T>
void Catalog_Individual<T>::afiseaza_umapul_cu_sudentii_picati()
{
    for(const auto& p : umap)
    {
        if(p.first != 0)
        {
            cout << p.first << ":";
            for(const auto& i : p.second)
            {
                cout << i;
            }
            cout<<"\n";
        }
    }
}




#endif // CATALOG_INIVIDUAL_H_INCLUDED
