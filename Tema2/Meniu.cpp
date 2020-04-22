#include "Meniu.h"

Meniu::Meniu()
{
    pret = 0;
}

Meniu::Meniu(double pret):pret(pret)
{

}

Meniu::Meniu(const Meniu &ob)
{
    pret = ob.pret;
}

Meniu::~Meniu()
{
    pret = 0;
}


void Meniu::set_pret(double cost)
{
    pret = cost;
}
