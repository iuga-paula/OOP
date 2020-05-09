#ifndef PARTIAL_H_INCLUDED
#define PARTIAL_H_INCLUDED
#include "examen.h"
#include <bits/stdc++.h>
using namespace std;

class Partial:public Examen
{

private:
    float nota_oral;

public:
    Partial(string materie = "", float nota_scris = 0.00, float nota_oral = 0.00);
    Partial(const Partial &);
    virtual~Partial();
    virtual void afisare()override
    {

        cout<<"pt examenul "<<get_id_examen()<<" la materia "<<get_materie()<<" nota la scris este "<<get_nota_scris()<<", nota la oral este "<<nota_oral<<"\n";
    }
    float get_nota_oral() const;
    void set_nota_oral(float);
    void verifica_nota_oral();
    Partial operator=(const Partial&);
    friend istream& operator>> (istream &in, Partial &partial);
    virtual float get_media()override
    {
        return nota_oral;
    }


};


#endif // PARTIAL_H_INCLUDED
