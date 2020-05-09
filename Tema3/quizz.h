#ifndef QUIZZ_H_INCLUDED
#define QUIZZ_H_INCLUDED
#include "examen_final.h"
#include <bits/stdc++.h>
using namespace std;
class Quizz:public Examen_final
{

private:
    int  nr_itemi;
    float nota_quizz;

public:
    Quizz(string materie = "", float nota_scris = 0.00, float nota_oral = 0.00, float puncte_bonus = 0.00, int nr = 15, float nota = 0.00);
    Quizz(const Quizz&);
    ~Quizz();
    void afisare()override
    {
        cout<<"Pt examenul "<<get_id_examen()<<" la materia "<<get_materie()<<" nota la scris este "<<get_nota_scris()<<", nota la oral este "<<get_nota_oral()<<", punctele bonus sunt"<<get_puncte_bonus()<<", ";
        cout<<"media oral + scris este "<<calculeaza_media();
        cout<<"nota la quizz pt marire este "<<nota_quizz<<", ";
        cout<<"media dupa marire este "<<calculeaza_media_cu_marire()<<"\n";
    }
    void set_nota_quizz(float);
    float get_nota_quizz() const;
    float calculeaza_media_cu_marire();
    Quizz operator=(const Quizz&);
    friend istream&operator>> (istream &in, Quizz &);
    virtual float get_media()override
    {
        return calculeaza_media_cu_marire();
    }




};


#endif // QUIZZ_H_INCLUDED
