#ifndef BAUTURI_H_INCLUDED
#define BAUTURI_H_INCLUDED

#include "Vin_varsat.h"
#include "Vin_la_sticla.h"
#include "Bere_la_sticla.h"
#include "Apa.h"

class Bauturi: public Vin_varsat, public Vin_la_sticla, public Bere_la_sticla, public Apa
{
private:
    double pret_mediu;

public:
    Bauturi(double pret = 5);
    void set_pret(double cost)
    {
        pret_mediu = cost;
    }

    Bauturi(const Bauturi&);
    ~Bauturi();
    void afiseara_pret() override ///nu mai e clasa abstracta
    {
        cout<<pret;
    }

    void calculeaza_pret_mediu();
    Bauturi operator=(const Bauturi&);
    friend ostream& operator<< (ostream &out, Bauturi &);
    friend istream& operator>> (istream &in, Bauturi &);


};

#endif // BAUTURI_H_INCLUDED
