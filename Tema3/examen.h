#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;
class Examen
{


private:
    static int contor_id_examen;
    int id_examen;
    string materie;
    float nota_scris;

public:
    Examen(string materie = "", float nota = 0.00);
    Examen(const Examen&);
    virtual ~Examen();
    virtual void afisare();
    string get_materie()const;
    int get_id_examen()const;
    float get_nota_scris()const;
    void set_id_examen(const int);
    void set_materie(const string);
    void set_nota_scris(const float);
    Examen operator=(const Examen&);
    friend istream& operator>> (istream &in, Examen &examen);
    void verifica_nota_scris();
    static void schimba_contor();
    virtual float get_media();


};


#endif // EXAMEN_H_INCLUDED
