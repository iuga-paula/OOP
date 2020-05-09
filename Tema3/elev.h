#ifndef ELEV_H_INCLUDED
#define ELEV_H_INCLUDED

#include "catalog_inividual.h"
#include <bits/stdc++.h>
using namespace std;

class Elev
{
private:
    string nume;
    int nr_examene;
    int grupa;
    int nr_quizzuri_date;
    Catalog_Individual<Examen>examene;
    Catalog_Individual<Partial>partiale;
    Catalog_Individual<Examen_final>examene_finale;
    Catalog_Individual<Quizz>quizzuri;


public:
    Elev(string nume = "",  int grupa = 0, int nr_examene = 0);
    Elev(const Elev&);
    ~Elev();
    string get_nume()const;
    void set_nume(const string);
    int get_nr_examene()const;
    void set_nr_examene(int);
    void set_nr_examene();
    int get_grupa()const;
    void set_grupa(int);
    Elev operator=(const Elev&);
    friend istream& operator>> (istream &in,Elev &);
    friend ostream& operator<< (ostream &out, Elev &);
    void adauga_examen(Examen);
    void adauga_partial(Partial);
    void adauga_examen_final(Examen_final);
    void adauga_quizz(Quizz);
    void set_partiale_picate();
    void afiseaza_partialele_picate();
    void set_examene();
    void afiseaza_examenele_picate();
    void set_examene_finale();
    void afiseaza_examenele_finale();
    void set_quizzuri();
    void afiseaza_quizzurile();
    int get_nr_quizzuri()const;
    Elev* memorare_afisare_n_obiecte();

};

#endif // ELEV_H_INCLUDED
