#include <iostream>

using namespace std;


class Client
{
private:
    int nr_client;
    string comanda;//ce a comandat un client
    double total;//totalul de achitat pt un client

public:
    //inline Client():total(total), comanda(comanda){nr_client++;};
    inline Client(int nr_client = 0, double total = 0, string comanda = ""):nr_client(nr_client),total(total), comanda(comanda)
    {

    }
    Client(Client &);
    ~Client();
    friend ostream& operator<< (ostream &out,  Client &client);
    friend istream& operator>> (istream &in, Client &client);
    Client operator=(const Client &);
    int get_nr_client();
    double  get_total();
    string get_comanda();
    void set_nr_client(int);
    void set_comanda(string);
    void adauga_la_comanda(string);
    void adauga_la_total(double);


};

class Masa
{

private:
    Client *masa_clienti;//Compozitie: vector de clienti pe poz i vom avea clientul cu nr i care are comanada invididuala +total
    int capacitate_masa;
    int nr_clienti;

public:
    Masa(int nr_clienti1 = 0, int capacitate_masa1 = 15): nr_clienti(nr_clienti1), capacitate_masa(capacitate_masa1)
    {
        masa_clienti = new Client[capacitate_masa];
    }

    Masa(const Masa &);
    ~Masa();
    friend ostream& operator<< (ostream &out,  Masa &masa);
    friend istream& operator>> (istream &in, Masa &masa);
    Masa operator=(const Masa &);
    void adauga_client_la_masa();
    double  calculeaza_total_per_masa();
    double calculeaza_total_per_client(int);
    void adauga_comanda_la_client(string, int);
    void adauga_pret_la_total_client(double, int);
    Client operator[](int i);
    void afiseaza_nota_per_masa();
    void afiseaza_nota_per_client(int i);


};


class Meniu  ///clasa abstracta;
{

private:
    double pret;

public:
    virtual void afiseara_pret() = 0;///functie virtuala pura;
    Meniu();
    Meniu(double);
    virtual ~Meniu();
    virtual double get_pret();
    virtual void set_pret(double);

};

class Desert:public Meniu
{

private:
    string tip_desert;
    int nr_cupe;

public:
    Desert(double pret = 5, string tip_desert = "inghetata", int nr_cupe = 0):Meniu(pret),tip_desert(tip_desert),nr_cupe(nr_cupe)
    {

    }

    ~Desert();

    void set_pret(double pret) override  ///doar in clasa se poate defini
    {

        if(tip_desert == "inghetata" && nr_cupe==3)
            set_pret(pret + 5);
        else if(tip_desert == "inghetata" && nr_cupe==4)
            set_pret(pret + 10);
        else if(tip_desert == "inghetata" && nr_cupe==5)
            set_pret(pret + 15);
        else
            set_pret(pret);

    }

    void set_tip_desert(string, int);

    double get_pret() override
    {
        Meniu::get_pret();
    }

};




Client::Client(Client &ob)
{
    nr_client = ob.nr_client;
    total = ob.total;
    comanda = ob.comanda;

}


Client::~Client()
{
    total = 0;
    comanda.clear();

}

ostream& operator<< (ostream &out,  Client &client)
{
    out<<"Clientul cu nr "<<client.nr_client;
    out<<" pt comanda "<<client.comanda<<" aveti de platit "<<client.total;
    return out;

}

istream& operator>> (istream &in, Client &client)
{
    cout<<"dati nr client\n ";
    in>>client.nr_client;
    cout<<" dati comanda:\n";
    in>>client.comanda;

    return in;

}

Client Client ::operator=(const Client &ob)
{
    if(this!=&ob)
    {
        nr_client = ob.nr_client;
        comanda = ob.comanda;
        total = ob.total;
    }
    return *this;
}

int Client::get_nr_client()
{
    return nr_client;

}

double  Client::get_total()
{
    return total;
}

string Client::get_comanda()
{
    return comanda;
}

void Client::set_comanda(string s)
{
    comanda = s;

}

void Client::set_nr_client(int nr)
{
    nr_client = nr;
}

void Client::adauga_la_total(double  pret)
{
    total = get_total() + pret;

}

void Client::adauga_la_comanda(string element)
{
    comanda = get_comanda() + element;
}

Masa::Masa(const Masa &ob):masa_clienti(ob.masa_clienti)
{
    capacitate_masa = ob.capacitate_masa;
    nr_clienti = ob.nr_clienti;
    for(int i=0; i<capacitate_masa; i++)
    {
        masa_clienti[i] = ob.masa_clienti[i];
    }


}

Masa::~Masa()
{
    capacitate_masa = nr_clienti = 0;
    delete []masa_clienti;
}

Masa Masa::operator=(const Masa &ob)
{
    if(this!=&ob)
    {
        nr_clienti = ob.nr_clienti;
        capacitate_masa = ob.capacitate_masa;
        masa_clienti = ob.masa_clienti;

    }
    return *this;
}

ostream& operator<< (ostream &out,  Masa &masa)
{

    out<<"la masa sunt ocupate  "<<masa.nr_clienti<<" locuri din "<<masa.capacitate_masa<<"\n";
    out<<"clientii de la masa + ce au comandat fiecare sunt:\n";
    for(int i=0; i<masa.nr_clienti; i++)
    {

        out<<"clientul cu nr "<<masa.masa_clienti[i].get_nr_client()<<" a comandat "<<masa.masa_clienti[i].get_comanda()<<" si are de platit "<<masa.masa_clienti[i].get_total()<<"\n";
    }
    return out;
}

istream& operator>>(istream &in, Masa &masa)
{

    string s;
    s = new char[250];
    cout<<"dati capacitatea mesei:\n";
    in>>masa.capacitate_masa;
    cout<<"dati nr de clienti care sosesc la masa:\n";
    in>>masa.nr_clienti;
    cout<<"dati ce comanda fiecare client pe rand CU VIRGULE FARA SPATIU:\n";
    for(int i=0; i<masa.nr_clienti; i++)
    {
        masa.masa_clienti[i].set_nr_client(i);
        cout<<"pt clientul cu numarul "<<masa.masa_clienti[i].get_nr_client()<<"\n";
        in>>s;
        masa.masa_clienti[i].set_comanda(s);///de pus si preturile!!

    }

}

void Masa::adauga_client_la_masa()
{
    if(nr_clienti+1 <= capacitate_masa)
    {
        nr_clienti++;
        masa_clienti[nr_clienti].set_nr_client(nr_clienti);
    }
    else
    {
        cout<<"nu mai e loc la aceasta masa!";///de inloc cu o eroare
    }

}

void Masa::adauga_comanda_la_client(string element, int nr_client)
{
    if(nr_client < capacitate_masa)
        masa_clienti[nr_client].adauga_la_comanda(element);

}


void Masa::adauga_pret_la_total_client(double pret, int nr_client)
{
    if(nr_client < capacitate_masa)
        masa_clienti[nr_client].adauga_la_total(pret);

}

double Masa::calculeaza_total_per_client(int nr_client)
{
    if(nr_client < capacitate_masa)
        return masa_clienti[nr_client].get_total();
}

double Masa::calculeaza_total_per_masa()
{
    double total_per_masa = 0;
    for(int i=0; i<nr_clienti; i++)
    {
        total_per_masa += masa_clienti[i].get_total();
    }
    return total_per_masa;
}

void Masa::afiseaza_nota_per_client(int nr_client)
{
    //masa_clienti[nr_client]->Client::operator<<;
    cout<<masa_clienti[nr_client];
}

void Masa::afiseaza_nota_per_masa()
{
    cout<<*this;
    cout<<calculeaza_total_per_masa();
}


Meniu::Meniu()
{
    pret = 0;
}

Meniu::Meniu(double pret):pret(pret)
{

}

Meniu::~Meniu()
{
    pret = 0;
}

double Meniu::get_pret()
{
    return pret;

}

void Meniu::set_pret(double cost)
{
    pret = cost;
}

Desert::~Desert()
{
    tip_desert = "";
    nr_cupe = 0;

}

void Desert::set_tip_desert(string tip, int nr_cupe)
{
    tip_desert  = tip;
    nr_cupe = nr_cupe;
}





int main()
{
//    Client client;
//    cin>>client;
//    Client client1;
//
//    cin>>client1;
//    cout<<client;
//    cout<<"\n";
//    cout<<client1;
//    cout<<"\n";
//    Client client2(2,2,"mere");
//    cout<<client2<<"\n";
//    client2.adauga_la_comanda(" apa plata");
//    cout<<client2<<"\n";
//    client2.adauga_la_total(10);
//    cout<<client2<<"\n";
//    Client c(client2);
//    cout<<c;
//    Masa m1;
//    cin>>m1;
//    cout<<m1;
    /* Masa m3(m2);*/
    Masa m2(0,5);//masa cu 0 clienti dar care are 5 locuri
    cout<<m2;
    m2.adauga_client_la_masa();
    m2.adauga_client_la_masa();
    m2.adauga_comanda_la_client("tiramisuu",0);
    m2.adauga_pret_la_total_client(5,0);
    m2.adauga_comanda_la_client("mere pere",1);
    m2.adauga_pret_la_total_client(10,1);
    cout<<m2;
    cout<<"\n";
    m2.afiseaza_nota_per_client(1);
    cout<<"\n";
    m2.afiseaza_nota_per_masa();



    return 0;
}
