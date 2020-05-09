#include "examen_final.h"
#include <bits/stdc++.h>
using namespace std;

Examen_final::Examen_final(string materie, float nota_scris, float nota_oral, float puncte_bonus):Partial(materie, nota_scris, nota_oral), puncte_bonus(puncte_bonus)
{


}

Examen_final::Examen_final(const Examen_final& ob)
{

    set_nota_oral(ob.get_nota_oral());
    set_nota_scris(ob.get_nota_scris());
    set_materie(ob.get_materie());
    set_id_examen(ob.get_id_examen());
    puncte_bonus = ob.puncte_bonus;

}

Examen_final::~Examen_final()
{
    puncte_bonus = 0.00;
}

Examen_final Examen_final::operator=(const Examen_final& ob)
{
    if(this!=&ob)
    {
        set_nota_oral(ob.get_nota_oral());
        set_nota_scris(ob.get_nota_scris());
        set_materie(ob.get_materie());
        set_id_examen(ob.get_id_examen());
        puncte_bonus = ob.puncte_bonus;

    }
    return *this;
}

float Examen_final::calculeaza_media()
{
    return (get_nota_oral()+get_nota_scris())/2 + puncte_bonus;
}

float Examen_final::get_puncte_bonus() const
{

    return puncte_bonus;

}

void Examen_final::set_puncte_bonus(float  puncte_bonus)
{
    this->puncte_bonus = puncte_bonus;
}

void Examen_final::verfica_puncte_bonus()
{
    if(((get_nota_oral()+get_nota_scris())/2 + puncte_bonus) >10)
    {
        puncte_bonus = 10 - ((get_nota_oral()+get_nota_scris())/2 + puncte_bonus);
        throw 0;
    }
}

istream&operator>> (istream &in, Examen_final &examen)
{
    in>>dynamic_cast<Partial&>(examen);
    cout<<"dati punctele bonus:\n";
    in>>examen.puncte_bonus;
    try
    {
        examen.verfica_puncte_bonus();

    }
    catch(int)
    {
        cout<<" prea multe puncte bonus\n";
        in>>examen.puncte_bonus;
    }
    catch(...)
    {
        cout<<" prea multe puncte bonus\n";
        in>>examen.puncte_bonus;
    }
    return in;
}
