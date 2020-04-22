#ifndef FEL_PRINCIPAL_H_INCLUDED
#define FEL_PRINCIPAL_H_INCLUDED

#include "Meniu.h"
#include <bits/stdc++.h>

using namespace std;

class Fel_principal:public Meniu
{

private:
    string carne;
    string tip_fel;

public:
    Fel_principal(double pret = 25, string carne = "pui", string tip_fel = "frigarui");
    Fel_principal(const Fel_principal&);
    virtual ~Fel_principal()
    {
        carne = "";
        tip_fel= "";

    };
    void afiseara_pret() override ///nu mai e clasa abstracta
    {
        cout<<pret;
    }

    virtual void set_pret(double cost) override  ///doar in clasa se poate defini
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

    virtual double get_pret();
    string get_tip_fel();
    void set_tip_fel(string, string);
    Fel_principal operator=(const Fel_principal &);
    friend ostream& operator<< (ostream &out, Fel_principal &fel);
    friend istream& operator>> (istream &in, Fel_principal &fel);

};

#endif // FEL_PRINCIPAL_H_INCLUDED
