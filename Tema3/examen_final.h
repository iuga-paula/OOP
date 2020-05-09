#ifndef EXAMEN_FINAL_H_INCLUDED
#define EXAMEN_FINAL_H_INCLUDED
#include "partial.h"
#include <bits/stdc++.h>
using namespace std;

class Examen_final:public Partial
{

private:
    float puncte_bonus;

public:
    Examen_final(string materie = "", float nota_scris = 0.00, float nota_oral = 0.00, float puncte_bonus = 0.00);
    Examen_final(const Examen_final &);
    virtual~Examen_final();
    float calculeaza_media();
    virtual void afisare()override
    {
        cout<<"Pt examenul "<<get_id_examen()<<" la materia "<<get_materie()<<" nota la scris este "<<get_nota_scris()<<", nota la oral este "<<get_nota_oral()<<", punctele bonus sunt"<<puncte_bonus<<", ";
        cout<<"media scris + oral este "<<calculeaza_media()<<"\n";
    }
    float get_puncte_bonus() const;
    void set_puncte_bonus(float);
    void verfica_puncte_bonus();
    Examen_final operator=(const Examen_final &);
    friend istream&operator>> (istream &in, Examen_final &examen);
    virtual float get_media()override
    {
        return calculeaza_media();
    }


};

#endif // EXAMEN_FINAL_H_INCLUDED
