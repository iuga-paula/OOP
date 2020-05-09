#include "examen.h"
#include <bits/stdc++.h>
using namespace std;

int Examen::contor_id_examen = 0;

void Examen::schimba_contor()
{
    if(contor_id_examen>20)
    {
        contor_id_examen = 0;
    }

}

Examen::Examen(string materie, float nota):materie(materie), nota_scris(nota)
{
    contor_id_examen++;
    id_examen = contor_id_examen;
}

Examen::Examen(const Examen &ob)
{
    set_id_examen(ob.id_examen);
    set_materie( ob.materie);
    nota_scris = ob.nota_scris;
}

Examen::~Examen()
{
    id_examen = 0;
    materie.clear();
    nota_scris = 0.00;
}

string Examen::get_materie() const
{
    return materie;

}

int Examen::get_id_examen()const
{
    return id_examen;

}

float Examen::get_nota_scris()const
{
    return nota_scris;
}

void Examen::set_id_examen(const int id)
{
    id_examen = id;
}

void Examen::set_nota_scris(const float nota)
{
    if(nota>=0 && nota<=10)
        nota_scris = nota;
}

void Examen::set_materie(const string materie)
{

    this->materie = materie;
}

Examen Examen::operator=(const Examen& examen)
{
    if(this!=&examen)
    {
        id_examen = examen.id_examen;
        nota_scris = examen.nota_scris;
        materie =  examen.materie;
    }
    return *this;
}

void Examen::afisare()
{
    cout<<"pt examenul "<<id_examen<<" la materia "<<materie<<" nota la scris este "<<nota_scris<<"\n";

}
void Examen::verifica_nota_scris()
{
    if(nota_scris>10 || nota_scris<0)
        throw 0;
}

istream& operator>> (istream &in, Examen &examen)
{

    cout<<"dati materia\n ";
    in>>examen.materie;
    cout<<"dati nota la scris\n ";
    in>>examen.nota_scris;
    try
    {
        examen.verifica_nota_scris();
    }
    catch(int)
    {
        cout<<"nota gresit introdusa\n";
        in>>examen.nota_scris;
    }
    catch(...)
    {
        cout<<"nota gresita\n";
        in>>examen.nota_scris;
    }

    return in;

}

float Examen::get_media()
{
    return nota_scris;
}
