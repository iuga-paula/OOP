#include "elev.h"
#include <bits/stdc++.h>
using namespace std;

Elev::Elev(string nume,  int grupa, int nr_examene):nume(nume), nr_examene(nr_examene), grupa(grupa)
{

    nr_quizzuri_date = 0;
}

Elev::Elev(const Elev & ob)
{
    grupa = ob.grupa;
    nr_examene = ob.nr_examene;
    nume = ob.nume;
    nr_quizzuri_date = ob.nr_quizzuri_date;

}

Elev::~Elev()
{
    grupa = 0;
    nr_examene = 0;
    nume.clear();
    nr_quizzuri_date = 0;

}

Elev Elev::operator=(const Elev &ob)
{
    if(this != &ob)
    {
        grupa = ob.grupa;
        nr_examene = ob.nr_examene;
        nume = ob.nume;
        nr_quizzuri_date = ob.nr_quizzuri_date;

    }
    return *this;
}

int Elev::get_grupa()const
{
    return grupa;
}

int Elev::get_nr_examene()const
{
    return nr_examene;
}

int Elev::get_nr_quizzuri()const
{
   return nr_quizzuri_date;
}

string Elev::get_nume() const
{
    return nume;
}

void Elev::set_grupa(const int nr)
{
    grupa = nr;
}

void Elev::set_nr_examene(const int nr)
{
    nr_examene = nr;
}

void Elev::set_nr_examene()
{
    nr_examene = examene.get_nr_examene() + partiale.get_nr_examene() + examene_finale.get_nr_examene() + quizzuri.get_nr_examene();
}

void Elev::set_nume(const string nume)
{
    this->nume = nume;
}

void Elev::adauga_examen(Examen examen)
{
    examene += examen;
}

void Elev::adauga_partial(Partial partial)
{
    partiale += partial;
}

void Elev::adauga_examen_final(Examen_final examen_final)
{
    examene_finale += examen_final;
}

void Elev::adauga_quizz(Quizz quizz)
{
    quizzuri += quizz;

    nr_quizzuri_date++;
}

istream&operator>> (istream &in, Elev &ob)
{
    cout<<"dati numele\n";
    in>>ob.nume;
    bool ok = true;
    for (int i = 0; i < ob.nume.size(); i++)
    {
        int uppercaseChar = toupper(ob.nume[i]);
        if (uppercaseChar < 'A' || uppercaseChar > 'Z' || ob.nume == "")
        {
            ok =  false;
        }
    }
    if(ok == false)
    {
        throw "nume gresit";
        in>>ob.nume;
    }
    cout<<"dati grupa\n";
    in>>ob.grupa;
    cout<<"dati nr examene\n";
    in>>ob.nr_examene;

    return in;

}

ostream& operator<< (ostream &out, Elev &ob)
{
    out<<"Pt studentul cu numele "<< ob.nume<<", grupa "<<ob.grupa<<", nr de examene "<<ob.nr_examene<< "\n";
    out<<"\n";
    out<<"fisa a) cu examene scrise " ;
    ob.examene.afisare();
    out<<"\n";
    out<<"fisa b) cu partiale ";
    ob.partiale.afisare();
    out<<"\n";
    out<<"fisa c) cu examene finale ";
    ob.examene_finale.afisare();
    out<<"\n";
    out<<"fisa d) cu quizzuri este ";
    ob.quizzuri.afisare();

    out<<"------------------------------";


    return out;

}


void Elev::set_partiale_picate()
{
    partiale.set_umapul_cu_studentii_picati(get_nume());

}

void Elev::set_examene()
{
    examene.set_umapul_cu_studentii_picati(get_nume());
}

void Elev::set_examene_finale()
{
    examene_finale.set_umapul_cu_studentii_picati(get_nume());
}

void Elev::set_quizzuri()
{
    quizzuri.set_studentii_care_au_2quizzuri(get_nume(), this->nr_quizzuri_date);
}

void Elev::afiseaza_quizzurile()
{
    cout<<"Studentii care au dat cel putin 2 quizzuri sunt:\n";
    quizzuri.afiseaza_sudentii_care_au_dat_2quizzuri();
}

void Elev::afiseaza_partialele_picate()
{
    cout<<"Id-ul partialului + studentii picati la partiale\n";
    partiale.afiseaza_umapul_cu_sudentii_picati();
}

void Elev::afiseaza_examenele_picate()
{
    cout<<"Id-ul exemenelor scrise + studentii picati la examenele scrise\n";
    examene.afiseaza_umapul_cu_sudentii_picati();
}

void Elev::afiseaza_examenele_finale()
{
    cout<<"Id-ul exemenelor finale + studentii picati la examenele finale\n";
    examene_finale.afiseaza_umapul_cu_sudentii_picati();
}

Elev* Elev::memorare_afisare_n_obiecte()
{
    int n;
    cout<<"dati numarul de elevi:\n";
    cin>>n;
    Elev a[n];
    for (int i=0; i<n; i++)
        cin>>a[i];

    cout<<"\n";
    for (int i=0; i<n; i++)
        cout<<a[i];

    return a;

}
