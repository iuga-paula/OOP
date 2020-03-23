#include "Stiva_de_caractere.h"
#include "Nod.h"




Stiva_de_caractere:: Stiva_de_caractere()
    {
        varf = NULL;
        //nr_elem = 0;
    };

Nod * Stiva_de_caractere::get_varf()
    {
        return varf;
    }

void Stiva_de_caractere::parcugere()
    {
        cout<<"parc ";
        for(Nod *q = varf; q; q = q ->get_link())
            cout<<q->get_info()<<" ";
        cout<<"\n";

    }

Stiva_de_caractere::~Stiva_de_caractere()
{
///Nod *current = varf;


    while(varf!=NULL)
    {

        Nod *q = varf;
        varf = varf -> get_link();
        delete q;

    }
    delete varf;
}

void Stiva_de_caractere::top()
{

    cout<<varf -> get_info()<<"\n";
}


void Stiva_de_caractere::push(char data)
{
    if(isempty())
    {
        Nod *nodNou = new Nod();
        nodNou ->set_info(data);
        varf = nodNou;
    }
    else
    {
        Nod *nodNou = new Nod();
        nodNou ->set_link(varf);
        nodNou ->set_info(data);
        varf = nodNou;
    }
    //nr_elem += 1;
}

int Stiva_de_caractere::isempty()
{
    if(varf == NULL)
        return 1;

    return 0;
}


void Stiva_de_caractere::pop()
{

    if (isempty())
    {
        cout<<"Stiva e goala!!";

    }

    else
    {
        Nod *NodNou = varf;
        varf =  varf -> get_link();
        //nr_elem -= 1;




    }
}

ostream& operator<< (ostream &out,  Stiva_de_caractere &stiva)
{

    while(!stiva.isempty())
    {

        out<<stiva.get_varf() -> get_info();

        stiva.pop();

    }
    out<<"\n";

    return out;
}

istream& operator>> (istream &in, Stiva_de_caractere &stiva)
{

    char data;
    cout<<"Dati nr de elem: "<<"\n";

    int nr;
    in>>nr;

    while(nr)
    {
        in>>data;
        stiva.push(data);
        nr--;
    }

    return in;
}

string Stiva_de_caractere::inversare_sir(string &sir)
{

    for(auto i=0; i<sir.length(); i++)
    {
        push(sir[i]);

    }

    sir.clear();
    while(!isempty())
    {
        sir.push_back(get_varf() -> get_info());
        pop();

    }
    return sir;

}

Stiva_de_caractere* Stiva_de_caractere ::memorare()
{

    int n,nr;
    cout<<"dati numarul de stive"<<"\n";
    cin>>n;
    Stiva_de_caractere a[n];

    for (int i=0; i<n; i++)
    {
      cin>>a[i];



    }
    cout<<"\n";
    for (int i=0; i<n; i++)
        cout<<a[i];

    return a;

}

