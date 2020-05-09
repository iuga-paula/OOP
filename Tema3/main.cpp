#include <iostream>
#include <bits/stdc++.h>
#include "elev.h"
#include "quizz.h"

using namespace std;

int main()
{
    //    Elev e;
//    e.memorare_afisare_n_obiecte();

    Elev student0;
    try
    {

        cin>>student0;
    }
    catch(const char* x)
    {
        cout<<x<<" repetati operatiunea!\n";
        cin>>student0;
    }
    catch(...)
    {
        cout<<"eroare citire!!\n";
    }
    cout<<"\n";
    Examen e1("alegbra",6.70);
    Partial p0("asc", 8.90, 9.75);
    Partial p1("gc", 7.80, 8.00);
    Quizz q1("asc", 8.90, 9.75, 0.00, 5, 10.00);
    Quizz q2("gc", 7.80, 8.00, 0.00, 10, 10.00);
    Examen_final fin("asd", 4.00, 5.00, 0.25);
    student0.adauga_examen(e1);
    student0.adauga_examen_final(fin);
    student0.adauga_quizz(q1);
    student0.adauga_quizz(q2);
    student0.adauga_partial(p0);
    student0.adauga_partial(p1);
    student0.set_nr_examene();
    student0.set_partiale_picate();
    student0.set_examene();
    student0.set_examene_finale();
    student0.set_quizzuri();
    //cout<<student0.get_nr_quizzuri();


    Elev student1("Iosif", 133);
    Examen  examen("matem", 8.76);
    Partial partial1("info", 5.70, 9.00);
    Partial partial2("algebra", 10, 7.50);
    Partial partial3("logica", 4.30, 6.00);
    Examen_final f1("asd", 5.00, 8.00, 3.00);
    Quizz q0("asd",5.00,8.00, 3.00, 10, 9.10);
    Quizz q00("algebra",10, 7.50, 0.00, 15, 9.00);
    student1.adauga_examen(examen);
    student1.adauga_partial(partial1);
    student1.adauga_partial(partial2);
    student1.adauga_partial(partial3);
    student1.adauga_examen_final(f1);
    student1.adauga_quizz(q0);
    student1.adauga_quizz(q00);
    student1.set_nr_examene();
    student1.set_partiale_picate();
    student1.set_examene();
    student1.set_examene_finale();
    student1.set_quizzuri();


    Elev student2("Popa", 133);
    Examen examen1("poo", 4.70);
    Examen examen2("asc", 3.30);
    Partial partial4("info", 4.30, 10);
    Partial partial5("geometrie", 4.30, 10);
    Examen_final f2("bd",7.00, 8.00, 1.50);
    //cout<<examen.get_id_examen()<<"\n";
    student2.adauga_examen(examen1);
    student2.adauga_partial(partial4);
    student2.adauga_partial(partial5);
    student2.adauga_examen_final(f2);
    student2.set_nr_examene();
    student2.set_partiale_picate();
    student2.set_examene();
    student2.set_examene_finale();
    //cout<<student2;
    //cout<<partial4.get_id_examen();

    student2.afiseaza_partialele_picate();
    cout<<"\n";
    student2.afiseaza_examenele_picate();
    cout<<"\n";
    student2.afiseaza_examenele_finale();
    cout<<"\n";
    student2.afiseaza_quizzurile();

    return 0;
}
