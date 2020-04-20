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
    friend ostream& operator<< (ostream &out,  const Client &client);
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
    friend ostream& operator<< (ostream &out,  const Masa &masa);
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

    Masa *memorare_afisare_n_obiecte();


};

class Meniu  ///clasa abstracta;
{

protected:
    double pret;

public:
    virtual void afiseara_pret() = 0;///functie virtuala pura;
    Meniu();
    Meniu(double);
    Meniu(const Meniu&);
    virtual ~Meniu();
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

    Desert(const Desert&);
    ~Desert();
    void afiseara_pret() override ///Desert nu mai e clasa abstracta
    {
        cout<<pret;
    }

    void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(tip_desert == "inghetata" && nr_cupe==3)
            Meniu::set_pret(cost + 5);
        else if(tip_desert == "inghetata" && nr_cupe==4)
            Meniu::set_pret(cost + 10);
        else if(tip_desert == "inghetata" && nr_cupe==5)
            Meniu::set_pret(cost + 15);
        else
            Meniu::set_pret(cost);
    }

    virtual double get_pret();
    string get_tip();
    void set_tip_desert(string, int);
    Desert operator=(const Desert &);
    friend ostream& operator<< (ostream &out, Desert &desert);
    friend istream& operator>> (istream &in, Desert &desert);


};


class Ciorba:public Meniu
{

private:
    string tip_ciorba;
    bool smantana;
    bool ardei;

public:
    Ciorba(double pret = 5, string tip_ciorba = "ciuperci", bool smantana = false, bool ardei = false):Meniu(pret),tip_ciorba(tip_ciorba),smantana(smantana), ardei(ardei)
    {

    }

    Ciorba(const Ciorba&);
    ~Ciorba();
    void afiseara_pret() override /// nu mai e clasa abstracta
    {
        cout<<pret;
    }

    void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(tip_ciorba == "legume")
            cost = cost + 5;
        else if(tip_ciorba == "burta")
            cost = cost +10;
        if(smantana == true)
            cost += 2;
        if(ardei == true)
            cost += 2;

        Meniu::set_pret(cost);
    }

    double get_pret();
    string get_tip();
    void set_tip_ciorba(string, bool, bool);
    Ciorba operator=(const Ciorba &);
    friend ostream& operator<< (ostream &out, Ciorba &ciorba);
    friend istream& operator>> (istream &in, Ciorba &ciorba);


};

class Fel_principal:public Meniu
{

private:
    string carne;
    string tip_fel;

public:
    Fel_principal(double pret = 25, string carne = "pui", string tip_fel = "frigarui"):Meniu(pret),carne(carne),tip_fel(tip_fel)
    {

    }

    Fel_principal(const Fel_principal&);
    ~Fel_principal();
    void afiseara_pret() override ///nu mai e clasa abstracta
    {
        cout<<pret;
    }

   void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(carne == "pui"  && tip_fel == "tocana")
            cost = cost + 5;
        else if(carne == "vita" && tip_fel == "chateaubrian")
            cost = cost +10;
        else if(carne == "vita" && tip_fel == "stroganoff")
            cost = cost +15;
        else if(carne == "vita" && tip_fel == "file")
            cost = cost + 20;

        Meniu::set_pret(cost);
    }

    double get_pret();
    string get_tip_fel();
    void set_tip_fel(string, string);
    Fel_principal operator=(const Fel_principal &);
    friend ostream& operator<< (ostream &out, Fel_principal &fel);
    friend istream& operator>> (istream &in, Fel_principal &fel);

};

class Garnitura:public Fel_principal
{

private:
    string leguma_principala;
    string tip_garnitura;

public:
    Garnitura(double pret = 25, string carne = "pui", string tip_fel = "frigarui", string leguma_principala = "cartofi", string tip ="prajiti"):
        Fel_principal(pret,carne,tip_fel), leguma_principala(leguma_principala), tip_garnitura(tip)
    {

    }

    Garnitura(const Garnitura&);
    ~Garnitura();
    void afiseara_pret() override
    {
        cout<<pret;
    }

    void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(leguma_principala == "cartofi"  && tip_garnitura == "piure")
            cost = cost + 3;
        else if (leguma_principala == "orez" && tip_garnitura == "sarbesc")
            cost = cost + 5;

        Meniu::set_pret(cost);
    }

    double get_pret();
    string get_tip_garnitura();
    void set_tip_garnitura(string, string);
    Garnitura operator=(const Garnitura &);
    friend ostream& operator<< (ostream &out, Garnitura &garnitura);
    friend istream& operator>> (istream &in,  Garnitura &garnitura);


};

class Vin_varsat:public Meniu
{
private:
    string culoare;
    double cantitate;///in ml;

public:
     Vin_varsat(double pret = 25, string culoare = "rosu", double cantitate = 100):Meniu(pret),culoare(culoare),cantitate(cantitate)
    {

    }

    Vin_varsat(const Vin_varsat&);
    ~Vin_varsat();
    void afiseara_pret() override ///nu mai e clasa abstracta
    {
        cout<<pret;
    }

   void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(culoare == "rosu")
            cost = cost + (cantitate/10);
        else
            cost = cost + (cantitate)/15;

        Meniu::set_pret(cost);
    }

    double get_pret();
    string get_tip_vin_varsat();
    void set_tip_vin_varsat(string, double);
    Vin_varsat operator=(const Vin_varsat &);
    friend ostream& operator<< (ostream &out, Vin_varsat &vin);
    friend istream& operator>> (istream &in, Vin_varsat &vin);




};

class Vin_la_sticla:public Meniu
{

private:
    string denumire;
    int an;

public:
     Vin_la_sticla(double pret = 25, string denumire = "Castel Bolovanu", int an = 2004):Meniu(pret),denumire(denumire),an(an)
    {

    }

    Vin_la_sticla(const Vin_la_sticla&);
    ~Vin_la_sticla();
    void afiseara_pret() override ///nu mai e clasa abstracta
    {
        cout<<pret;
    }

   void set_pret(double cost) override  ///doar in clasa se poate defini
    {

        if(denumire == "Bordeux")
            cost = cost + 20;
        else
            cost = cost + 10;

        Meniu::set_pret(cost);
    }

    double get_pret();
    string get_tip_vin_la_sticla();
    void set_tip_vin_la_sticla(string, int);
    Vin_la_sticla operator=(const Vin_la_sticla &);
    friend ostream& operator<< (ostream &out, Vin_la_sticla &vin);
    friend istream& operator>> (istream &in, Vin_la_sticla &vin);




};

class Bere_la_sticla:public Meniu
{

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

ostream& operator<< (ostream &out, const Client &client)
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

ostream& operator<< (ostream &out, const Masa &masa)
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
    cout<<"\n";

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
    cout<<"\n";
}

void Masa::afiseaza_nota_per_masa()
{
    cout<<*this;
    cout<<"Totalul de achitat este: ";
    cout<<calculeaza_total_per_masa();
    cout<<"\n";
}

Masa* Masa::memorare_afisare_n_obiecte()
{
    int n;
    cout<<"dati numarul de mese:\n";
    cin>>n;
    Masa a[n];
    for (int i=0; i<n; i++)
        cin>>a[i];

    cout<<"\n";
    for (int i=0; i<n; i++)
        cout<<a[i];

    return a;

}


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

Desert::Desert(const Desert &ob)
{
    pret = ob.pret;

    tip_desert = ob.tip_desert;
    nr_cupe = ob.nr_cupe;
}
Desert::~Desert()
{
    tip_desert = "";
    nr_cupe = 0;

}

void Desert::set_tip_desert(string tip, int nr_cupe)
{
    tip_desert  = tip;
    this->nr_cupe = nr_cupe;
}
double Desert::get_pret()
{
    return pret;
}

string Desert::get_tip()
{
    return tip_desert;
}

Desert Desert::operator=(const Desert &ob)
{
    if(this!=&ob)
    {

        pret = ob.pret;
        tip_desert = ob.tip_desert;
        nr_cupe = ob.nr_cupe;
    }
    return *this;
}

ostream& operator<< (ostream &out, Desert &desert)
{
    out<<"pt desertul "<<desert.tip_desert<<" pretul este ";
    out<<desert.pret;
    if(desert.tip_desert == "inghetata")
        out<<" si nr de cupe este "<<desert.nr_cupe;
    return out;
}

istream& operator>> (istream &in, Desert &desert)
{
    cout<<"dati tipul de desert:\n ";
    in>>desert.tip_desert;
    if(desert.tip_desert == "inghetata")
    {
        cout<<"dati nr cupe: ";
        in>>desert.nr_cupe;
    }
    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    desert.set_pret(pr);
    return  in;
}


Ciorba::Ciorba(const Ciorba &ob)
{
    pret = ob.pret;

    tip_ciorba = ob.tip_ciorba;
    smantana = ob.smantana;
    ardei = ob.ardei;
}

Ciorba::~Ciorba()
{
    tip_ciorba = "";
    smantana = false;
    ardei = false;

}

void Ciorba::set_tip_ciorba(string tip, bool smantana, bool ardei)
{
    tip_ciorba = tip;
    this->smantana = smantana;
    this->ardei = ardei;

}
double Ciorba::get_pret()
{
    return pret;
}

string Ciorba::get_tip()
{
    return tip_ciorba;
}

Ciorba Ciorba::operator=(const Ciorba &ob)
{
    if(this!=&ob)
    {

        pret = ob.pret;
        tip_ciorba = ob.tip_ciorba;
        smantana = smantana;
        ardei = ardei;
    }
    return *this;
}

ostream& operator<< (ostream &out, Ciorba &ciorba)
{
    out<<"pt ciorba "<<ciorba.tip_ciorba;
    if(ciorba.smantana == true)
        out<<" cu smantana";
    if(ciorba.ardei == true)
        out<<" cu ardei";
    out<<"pretul este ";
    out<<ciorba.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Ciorba &ciorba)
{
    cout<<"dati tipul de ciorba:\n ";
    in>>ciorba.tip_ciorba;
    string s;
    cout<<"doriti cu smantana?:\n";
    in>>s;
    if(s=="da")
        ciorba.smantana = true;
    else
        ciorba.smantana = false;

    cout<<"doriti cu adei?:\n";
    in>>s;
    if(s=="da")
        ciorba.ardei = true;
    else
        ciorba.ardei = false;

    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    ciorba.set_pret(pr);
    return  in;
}


Fel_principal::Fel_principal(const Fel_principal &ob)
{
    pret = ob.pret;

    carne = ob.carne;
    tip_fel = ob.tip_fel;
}

Fel_principal::~Fel_principal()
{
    carne = "";
    tip_fel= "";

}

void Fel_principal::set_tip_fel(string carne, string fel)
{
    this->carne = carne;
    tip_fel = fel;

}
double Fel_principal::get_pret()
{
    return pret;
}

string Fel_principal::get_tip_fel()
{
    return carne + " " + tip_fel;
}

Fel_principal Fel_principal::operator=(const Fel_principal &ob)
{
    if(this!=&ob)
    {

        pret = ob.pret;
        carne = ob.carne;
        tip_fel = ob.tip_fel;
    }
    return *this;
}

ostream& operator<< (ostream &out, Fel_principal &fel)
{
    out<<"pt felul principal din care de "<<fel.carne<<" cu denumirea "<<fel.tip_fel;
    out<<" pretul este ";
    out<<fel.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Fel_principal &fel)
{
    cout<<"dati tipul de carne:\n ";
    in>>fel.carne;
    cout<<"dati denumirea felului:\n";
    in>>fel.tip_fel;

    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    fel.set_pret(pr);
    return  in;
}


Garnitura::Garnitura(const Garnitura &ob)
{
    pret = ob.pret;

    leguma_principala = ob.leguma_principala;
    tip_garnitura = ob.tip_garnitura;
}

Garnitura::~Garnitura()
{
    leguma_principala = "";
    tip_garnitura = "";

}

void Garnitura::set_tip_garnitura(string leguma, string nume)
{
   leguma_principala = leguma;
    tip_garnitura = nume;

}

double Garnitura::get_pret()
{
    return pret;
}

string Garnitura::get_tip_garnitura()
{
    return leguma_principala + " " + tip_garnitura;
}

Garnitura Garnitura::operator=(const Garnitura &ob)
{
    if(this!=&ob)
    {

       this->Fel_principal::operator=(ob);
       leguma_principala = ob.leguma_principala;
       tip_garnitura = ob.tip_garnitura;
    }
    return *this;
}

ostream& operator<< (ostream &out, Garnitura &garnitura)
{
    out<<"pt garnitura "<<garnitura.leguma_principala<<" cu denumirea "<<garnitura.tip_garnitura;
    out<<" pretul este ";
    out<<garnitura.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Garnitura &garnitura)
{
    cout<<"dati din ce vreti garnitura:\n ";
    in>>garnitura.leguma_principala;
    cout<<"dati modul de perparare:\n";
    in>>garnitura.tip_garnitura;

    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    garnitura.set_pret(pr);
    return  in;
}


Vin_varsat::Vin_varsat(const Vin_varsat &ob)
{
    pret = ob.pret;

    culoare = ob.culoare;
    cantitate = ob.cantitate;
}

Vin_varsat::~Vin_varsat()
{
    cantitate = 0;
    culoare = "";

}

void Vin_varsat::set_tip_vin_varsat(string culoare, double nr)
{
  this->culoare = culoare;
  cantitate = nr;

}

double Vin_varsat::get_pret()
{
    return pret;
}

string Vin_varsat::get_tip_vin_varsat()
{
    return culoare;
}

Vin_varsat Vin_varsat::operator=(const Vin_varsat &ob)
{
    if(this!=&ob)
    {

       culoare = ob.culoare;
       cantitate = ob.cantitate;
    }
    return *this;
}

ostream& operator<< (ostream &out, Vin_varsat &vin)
{
    out<<"pt vinul varsat "<<vin.culoare<<vin.cantitate<<" mililitri";
    out<<" pretul este ";
    out<<vin.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Vin_varsat &vin)
{
    cout<<"dati ce culoare de vin varsat doriti:\n ";
    in>>vin.culoare;
    cout<<"dati cantitatea:\n";
    in>>vin.cantitate;

    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    vin.set_pret(pr);
    return  in;
}


Vin_la_sticla::Vin_la_sticla(const Vin_la_sticla &ob)
{
    pret = ob.pret;

    denumire = ob.denumire;
    an = ob.an;
}

Vin_la_sticla::~Vin_la_sticla()
{
    denumire = "";
    an = 0;

}

void Vin_la_sticla::set_tip_vin_la_sticla(string denumire, int an)
{
  this->denumire = denumire;
  this->an = an;

}

double Vin_la_sticla::get_pret()
{
    return pret;
}

string Vin_la_sticla::get_tip_vin_la_sticla()
{
    return denumire;
}

Vin_la_sticla Vin_la_sticla::operator=(const Vin_la_sticla &vin)
{
    if(this!=&vin)
    {

       denumire = vin.denumire;
       an = vin.an;
    }
    return *this;
}

ostream& operator<< (ostream &out, Vin_la_sticla &vin)
{
    out<<"pt vinul la sticla "<<vin.denumire <<" din anul "<<vin.an;
    out<<" pretul este ";
    out<<vin.pret;
    out<<"\n";
    return out;
}

istream& operator>> (istream &in, Vin_la_sticla &vin)
{
    cout<<"dati ce marca de vin la sticla doriti:\n ";
    in>>vin.denumire;
    cout<<"dati anul de productie:\n";
    in>>vin.an;

    cout<<"dati pretul: ";
    double pr;
    in>>pr;
    vin.set_pret(pr);
    return  in;
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
//    Masa m2(0,5);//masa cu 0 clienti dar care are 5 locuri
//    cout<<m2;
//    m2.adauga_client_la_masa();
//    m2.adauga_client_la_masa();
//    m2.adauga_comanda_la_client("tiramisuu",0);
//    m2.adauga_pret_la_total_client(5,0);
//    m2.adauga_comanda_la_client("mere pere",1);
//    m2.adauga_pret_la_total_client(10,1);
//    cout<<m2;
//
//    m2.afiseaza_nota_per_client(1);
//
//    m2.afiseaza_nota_per_masa();
//
//    Masa A;
//    A.memorare_afisare_n_obiecte();

//    Desert d,d1;
//    cin>>d1;
//    cout<<d.get_pret()<<"\n";
//    d.set_tip_desert("inghetata",4);
//    d.set_pret(10.5);
//    cout<<d.get_pret();

//      Ciorba ci;
//      Ciorba ci1;
//      ci1.set_tip_ciorba("burta", true,false);
//      cout<<ci1.get_pret();
//      cout<<ci1.get_tip();
//      cin>>ci;
//      cout<<ci;

//    Fel_principal f;
//    cout<<f;
//    f.set_tip_fel("vita","file");
//    f.set_pret(30);
//    cout<<f;

//Garnitura g;
//cin>>g;
//cout<<g;
//cout<<g.get_tip_garnitura();
//g.set_pret(10.43);
//cout<<g;

//Vin_varsat v;
//cout<<v.get_pret();
//v.set_tip_vin_varsat("rosu", 14);
//cout<<v;




    return 0;
}
