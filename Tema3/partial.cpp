#include "partial.h"
#include <bits/stdc++.h>
using namespace std;

Partial::Partial(string materie, float nota_scris, float nota_oral):Examen(materie,nota_scris), nota_oral(nota_oral)
{

}

Partial::Partial(const Partial &ob)
{
    set_id_examen(ob.get_id_examen());
    set_materie(ob.get_materie());
    set_nota_scris(ob.get_nota_scris());
    nota_oral = ob.nota_oral;

}

Partial::~Partial()
{
    nota_oral = 0.00;
}

float Partial::get_nota_oral() const
{

    return nota_oral;
}

void Partial::set_nota_oral(float nota)
{
    if(nota>=0 && nota<=10)
        nota_oral = nota;
}

Partial Partial::operator=(const Partial& partial)
{
    if(this!=&partial)
    {
        nota_oral=partial.nota_oral;
        set_nota_scris(partial.get_nota_scris());
        set_materie(partial.get_materie());
        set_id_examen(partial.get_id_examen());
    }
    return *this;
}

void Partial::verifica_nota_oral()
{
    if(nota_oral <0 || nota_oral>10)
        throw 0;
}

istream& operator>> (istream &in, Partial &partial)
{

    in>>dynamic_cast<Examen&>(partial);

    cout<<"dati nota la oral\n";
    in>>partial.nota_oral;
    try
    {
        partial.verifica_nota_oral();
    }
    catch(int)
    {
        cout<<"nota oral introdusa gresit\n";
        in>>partial.nota_oral;
    }
    catch(...)
    {
        cout<<"nota oral  gresita\n";
        in>>partial.nota_oral;
    }

    return in;


}
