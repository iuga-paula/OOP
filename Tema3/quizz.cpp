#include "quizz.h"
#include <bits/stdc++.h>
using namespace std;

Quizz::Quizz(string materie, float nota_scris, float nota_oral, float puncte_bonus, int nr, float nota):Examen_final(materie,nota_scris,nota_oral,puncte_bonus), nr_itemi(nr), nota_quizz(nota)
{

}

Quizz::Quizz(const Quizz &ob)
{
    set_nota_oral(ob.get_nota_oral());
    set_nota_scris(ob.get_nota_scris());
    set_materie(ob.get_materie());
    set_id_examen(ob.get_id_examen());
    set_puncte_bonus(ob.get_puncte_bonus());
    nr_itemi = ob.nr_itemi;
    nota_quizz = ob.nota_quizz;



}

Quizz::~Quizz()
{
    nr_itemi = 0;
    nota_quizz = 0.00;
}

Quizz Quizz::operator=(const Quizz &ob)
{
    if(this!=&ob)
    {
        set_nota_oral(ob.get_nota_oral());
        set_nota_scris(ob.get_nota_scris());
        set_materie(ob.get_materie());
        set_id_examen(ob.get_id_examen());
        set_puncte_bonus(ob.get_puncte_bonus());
        nr_itemi = ob.nr_itemi;
        nota_quizz = ob.nota_quizz;


    }
    return *this;
}

void Quizz::set_nota_quizz(float nota)
{
    nota_quizz = nota;
}

float Quizz::get_nota_quizz()const
{
    return nota_quizz;
}

float Quizz::calculeaza_media_cu_marire()
{
    return (calculeaza_media() + nota_quizz)/2;
}


istream&operator>> (istream &in, Quizz &ob)
{
    in>>dynamic_cast<Examen_final&>(ob);
    cout<<"dati nr itemi \n";
    in>>ob.nr_itemi;
    cout<<"dati nota quizz \n";
    in>>ob.nota_quizz;

    return in;
}
