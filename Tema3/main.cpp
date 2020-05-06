#include <iostream>
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
    Examen(string, float);
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


};

class Partial:public Examen
{

private:
    float nota_oral;

public:
    Partial(string,float,float);
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


};

class Examen_final:public Partial
{

private:
    float puncte_bonus;

public:
    Examen_final(string,float,float,float);
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


};


class Quizz:public Examen_final
{

private:
    int  nr_itemi;
    float nota_quizz;

public:
    Quizz(string,float,float,float,int,float);
    Quizz(const Quizz &);
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



};

template <class T>
class Catalog_Individual;

template<class T>
istream&operator>>(istream &in, Catalog_Individual<T>&ob);

template <class T>
class Catalog_Individual
{
private:
    int nr_matricol;
    static int contor_maticol;
    int nr_examen_curent;
    vector<T> structura_date;

public:
    Catalog_Individual();
    Catalog_Individual(const Catalog_Individual&);
    ~Catalog_Individual();
    Catalog_Individual operator=(const Catalog_Individual&);
    friend istream&operator>> <>(istream &in, Catalog_Individual&ob);
    void afisare();
    int get_nr_matricol();
    int get_nr_examene();
    Catalog_Individual operator+=(const T &examen);


};

class Elev
{
private:
    string nume;
    int nr_examene;
    int grupa;
    Catalog_Individual<Examen>examene;
    Catalog_Individual<Partial>partiale;
    Catalog_Individual<Examen_final>examene_finale;
    Catalog_Individual<Quizz>quizzuri;


public:
    Elev(string, int, int);
    Elev(const Elev&);
    ~Elev();
    string get_nume()const;
    void set_nume(const string);
    int get_nr_examene()const;
    void set_nr_examene(int);
    void set_nr_examene();
    int get_grupa()const;
    void set_grupa(int);
    Elev operator=(const Elev&);
    friend istream& operator>> (istream &in,Elev &);
    friend ostream& operator<< (ostream &out, Elev &);
    void adauga_examen(Examen);
    void adauga_partial(Partial);
    void adauga_examen_final(Examen_final);
    void adauga_quizz(Quizz);





};









Elev::Elev(string nume = "",  int grupa = 0, int nr_examene = 0):nume(nume), nr_examene(nr_examene), grupa(grupa)
{

}

Elev::Elev(const Elev & ob)
{
    grupa = ob.grupa;
    nr_examene = ob.nr_examene;
    nume = ob.nume;

}

Elev::~Elev()
{
    grupa = 0;
    nr_examene = 0;
    nume.clear();

}

Elev Elev::operator=(const Elev &ob)
{
    if(this != &ob)
    {
        grupa = ob.grupa;
        nr_examene = ob.nr_examene;
        nume = ob.nume;

    }
    return *this;
}

int Elev::get_grupa()const
{
    return grupa;
}

int Elev::get_nr_examene()const
{
    return nr_examene;
}

string Elev::get_nume() const
{
    return nume;
}

void Elev::set_grupa(const int nr)
{
    grupa = nr;
}

void Elev::set_nr_examene(const int nr)
{
    nr_examene = nr;
}

void Elev::set_nr_examene()
{
    nr_examene = examene.get_nr_examene() + partiale.get_nr_examene() + examene_finale.get_nr_examene() + quizzuri.get_nr_examene();
}

void Elev::set_nume(const string nume)
{
    this->nume = nume;
}

void Elev::adauga_examen(Examen examen)
{
    examene += examen;
}

void Elev::adauga_partial(Partial partial)
{
    partiale += partial;
}

void Elev::adauga_examen_final(Examen_final examen_final)
{
    examene_finale += examen_final;
}

void Elev::adauga_quizz(Quizz quizz)
{
    quizzuri += quizz;
}

istream&operator>> (istream &in, Elev &ob)
{
    cout<<"dati numele\n";
    in>>ob.nume;
    if(ob.nume == "")
    {
        throw "nume gresit";
        in>>ob.nume;
    }
    cout<<"dati grupa\n";
    in>>ob.grupa;
    in>>ob.nr_examene;

    return in;

}
ostream& operator<< (ostream &out, Elev &ob)
{
    out<<"Pt studentul cu numele "<< ob.nume<<", grupa "<<ob.grupa<<", nr de examene "<<ob.nr_examene<< "\n";
    out<<"\n";
    out<<"fisa a) cu examene scrise " ;
    ob.examene.afisare();
    out<<"\n";
    out<<"fisa b) cu partiale ";
    ob.partiale.afisare();
    out<<"\n";
    out<<"fisa c) cu examene finale ";
    ob.examene_finale.afisare();
    out<<"\n";
    out<<"fisa d) cu quizzuri este ";
    ob.quizzuri.afisare();

    out<<"------------------------------";


    return out;

}

int Examen::contor_id_examen = 0;

void Examen::schimba_contor()
{
    if(contor_id_examen>20)
    {
        contor_id_examen = 0;
    }

}

Examen::Examen(string materie = "", float nota = 0.00):materie(materie), nota_scris(nota)
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




Partial::Partial(string materie = "", float nota_scris = 0.00, float nota_oral = 0.00):Examen(materie,nota_scris), nota_oral(nota_oral)
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

Examen_final::Examen_final(string materie = "", float nota_scris = 0.00, float nota_oral = 0.00, float puncte_bonus = 0.00):Partial(materie, nota_scris, nota_oral), puncte_bonus(puncte_bonus)
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


Quizz::Quizz(string materie = "", float nota_scris = 0.00, float nota_oral = 0.00, float puncte_bonus = 0.00, int nr = 15, float nota = 0.00):Examen_final(materie,nota_scris,nota_oral,puncte_bonus), nr_itemi(nr), nota_quizz(nota)
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

template <class  T>
int Catalog_Individual<T>::contor_maticol = 0;

template <class T>
Catalog_Individual<T>::Catalog_Individual()
{
    contor_maticol++;
    nr_examen_curent = 0;
    nr_matricol = contor_maticol;

}

template <class T>
Catalog_Individual<T>::Catalog_Individual(const Catalog_Individual& ob)
{
    nr_matricol = ob.nr_matricol;
    structura_date = ob.structura_date;
}

template <class T>
Catalog_Individual<T>::~Catalog_Individual()
{
    nr_matricol = 0;
    nr_examen_curent = 0;
    structura_date.clear();
}

template<class T>
Catalog_Individual<T> Catalog_Individual<T>::operator=(const Catalog_Individual& ob)
{
    if(this != &ob)
    {
        nr_matricol = ob.nr_matricol;
        structura_date = ob.structura_date;
    }
    return *this;
}

template<class T>
int Catalog_Individual<T>::get_nr_matricol()
{
    return nr_matricol;
}

template<class T>
int Catalog_Individual<T>::get_nr_examene()
{
    return nr_examen_curent;
}

template<class T>
void Catalog_Individual<T>::afisare()
{
    cout<<" nr matricol  "<<nr_matricol<<"\n";
    if(structura_date.empty() == true)
        cout<<"studentul nu a sustinut acest tip de examene\n";
    else
    {
        cout<<"acesta a dat examenele:\n";
        for(auto &it: structura_date)
        {

            it.afisare();
            ///cout<<"\n";

        }
    }

}

template<class T>
Catalog_Individual<T> Catalog_Individual<T>::operator+=(const T &ob)
{



    nr_examen_curent++;
    structura_date.push_back(ob);
    return *this;

}

template <class T>
istream&operator>> (istream &in, Catalog_Individual<T>&ob)
{
    cout<<"dati nr maricol:\n";
    in>>ob.nr_matricol;
    in>>ob.student;
    for(int i = 0; i <ob.nr_examen_curent; i++)
    {
        T x;
        cout<<"dati examenul\n";
        in>>x;
    }

    return in;
}


int main()
{
//    Examen ob0;
//    cin>>ob0;
//    cout<<ob0.get_nota_scris();
//    Partial ob;
//    cin>>ob;
//    cout<<ob.get_nota_scris();
//
//Examen_final ob1;
//cin>>ob1;
////cout<<ob1.get_puncte_bonus();
//    Examen_final examen;
//    cin>>examen;
//    Catalog_Individual<Examen_final>elev1;
//
//    elev1.adauga_nume_grupa_student("Iosif", 133,30);
////cout<<elev1.get_nr_matricol();
//   // elev1.afisare();
////Quizz q("analiza", 6.40, 7, 3.00, 8.00);
//    elev1+=examen;
//elev1.afisare();

    Elev student1("Iosif", 133);
    Examen  examen("matem", 8.76);
    Partial partial1("info", 5.70, 9.00);
    Partial partial2("algebra", 10, 7.50);
    student1.adauga_examen(examen);
    student1.adauga_partial(partial1);
    student1.adauga_partial(partial2);
    student1.set_nr_examene();
    cout<<student1;


    return 0;
}
