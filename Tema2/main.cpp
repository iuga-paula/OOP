#include <iostream>
#include "Masa.h"
#include "Desert.h"
#include "Ciroba.h"
#include "Garnitura.h"
#include "Bauturi.h"

using namespace std;

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

    int nr_mese,nr_clienti;
    cout<<"dati nr de mese din restaurant:\n";
    cin>>nr_mese;

    for(int i = 0; i<nr_mese; i++)
    {
        {
            Masa m;
            string s, comanda;
            double pret;

            cout<<"pt masa cu nr "<<i<<" dati nr de clienti care sosesc"<<":\n";
            cin>>nr_clienti;
            for(int j = 0; j<nr_clienti; j++)
            {

                cout<<"comanda pt clientul "<<j<<" (scrieti cu LITERE MICI, doar denumirile de marca cu litera mare):\n";
                cout<<"De baut va aduc ceva?\n ";
                cin>>s;
                if(s == "da")
                {
                    cout<<" Vin, bere sau apa?\n";
                    cin>>s;
                    string s1,s2;
                    double nr;
                    int n;
                    if(s == "vin")
                    {
                        cout<<"pahar sau sticla?\n";
                        cin>>s1;
                        if(s1 == "pahar")
                        {
                            Vin_varsat ob;
                            cout<<"cati ml?\n";
                            cin>>nr;

                            try
                            {
                                ob.set_tip_vin_varsat(s2, nr);
                            }
                            catch(double x)
                            {
                                cout<<"ati introdus 0 mililitri!\n";
                                cin>>nr;
                                ob.set_tip_vin_varsat(s2, nr);
                            }
                            catch(...)
                            {
                                cout<<"nr de mililitri introdus gresit!\n";
                            }
                            cout<<"ce culoare?\n";
                            cin>>s2;
                            ob.set_pret(10);
                            comanda = s + " la " + s1 + " " + s2;
                            m.adauga_comanda_la_client(comanda, j);
                            pret = ob.get_pret();
                            m.adauga_pret_la_total_client(pret, j);

                        }

                        else if (s1 == "sticla")
                        {
                            Vin_la_sticla ob;
                            cout<<"ce marca?\n";
                            cin>>s2;
                            cout<<"din ce an?\n";
                            cin>>n;
                            ob.set_tip_vin_la_sticla(s2, n);
                            ob.set_pret(25);
                            pret = ob.get_pret();
                            comanda = s + " la " + s1 + " " + s2;
                            m.adauga_comanda_la_client(comanda, j);
                            m.adauga_pret_la_total_client(pret, j);

                        }

                        else
                            cout<<"nu exista in meniu!";



                    }

                    else if ( s == "bere")
                    {
                        Bere_la_sticla ob;
                        cout<<"ce firma?\n";
                        cin>>s1;
                        cout<<"cu alcool sau fara\n";
                        cin>>s2;
                        bool alcool;
                        if(s2 == "cu")
                        {
                            alcool = true;
                            comanda = s + " " + s1 + " " + "cu alcool";
                        }

                        else
                        {
                            alcool = false;
                            comanda = s + " " + s1 + " " + "fara alcool";
                            ob.set_tip_bere_la_sticla(s1, alcool);
                            ob.set_pret(15);
                            m.adauga_comanda_la_client(comanda, j);
                            pret = ob.get_pret();
                            m.adauga_pret_la_total_client(pret, j);

                        }
                    }

                    else if(s == "apa")
                    {
                        Apa ob;
                        cout<<"ce firma?\n";
                        cin>>s1;
                        ob.set_tip_apa(s1);
                        ob.set_pret(5);
                        comanda = s + " " + s1;
                        pret = ob.get_pret();
                        m.adauga_comanda_la_client(comanda, j);
                        m.adauga_pret_la_total_client(pret, j);
                    }


                }

                cout<<"Doriti ciorba?\n";
                cin>>s;
                if(s == "da")
                {
                    string s1,s2,s3;
                    bool smantana, ardei;
                    cout<<"De care?\n";
                    cin>>s1;
                    Ciorba ob;
                    if(s1 == "legume" || s1 == "ciuperci" || s1 == "burta")
                    {
                        comanda = "ciorba " +  s1;
                        cout<<"Cu sau fara smantana?\n";
                        cin>>s2;
                        if(s2 == "cu")
                        {
                            smantana = true;
                            comanda += " cu smantana";
                        }
                        else
                            smantana = false;
                        cout<<"Cu sau fara ardei?\n";
                        cin>>s3;
                        if(s3 == "cu")
                        {
                            ardei = true;
                            comanda += " cu ardei";
                        }
                        else
                            ardei = false;
                        ob.set_tip_ciorba(s1, smantana, ardei);
                        ob.set_pret(10);
                        pret = ob.get_pret();
                        m.adauga_comanda_la_client(comanda, j);
                        m.adauga_pret_la_total_client(pret, j);


                    }
                    else
                        cout<<"Nu exista in meniu acest tip de ciorba!\n";


                }

                cout<<"Fel principal doriti?\n";
                cin>>s;
                if(s == "da")
                {
                    Fel_principal ob;
                    string s1,s2,s3;
                    cout<<"pui sau vita?\n";
                    cin>>s1;
                    if( s1 == "pui")
                    {
                        cout<<"Frigarui sau tocana?\n";
                        cin>>s2;
                        comanda = s2 + " de pui";
                        ob.set_tip_fel(s1, s2);
                        ob.set_pret(25);
                        pret = ob.get_pret();
                        m.adauga_comanda_la_client(comanda, j);
                        m.adauga_pret_la_total_client(pret, j);

                    }
                    else if( s1 == "vita")
                    {
                        cout<<"Chateaubriand, stroganoff sau file?\n";
                        cin>>s2;
                        comanda = s2 + " de vita";
                        ob.set_tip_fel(s1, s2);
                        ob.set_pret(25);
                        pret = ob.get_pret();
                        m.adauga_comanda_la_client(comanda, j);
                        m.adauga_pret_la_total_client(pret, j);


                    }
                    else
                        cout<<"nu avem!\n";

                    cout<<"Garnitura la felul principal doriti?\n";
                    cin>>s1;
                    if(s1 == "da")
                    {
                        Garnitura ob2;
                        cout<<"orez sau  cartofi?\n";
                        cin>>s2;
                        if(s2 == "cartofi")
                        {
                            cout<<"pajiti sau piure?\n";
                            cin>>s3;

                        }
                        else if(s2 == "orez")
                        {
                            s3 = "sarbesc";
                        }
                        ob2.set_tip_garnitura(s2, s3);
                        comanda = s2 + " " + s3;

                        Fel_principal *p = &ob2; //upcasting cu virtual;
                        p->set_pret(30);
                        pret = p->get_pret();

                        m.adauga_comanda_la_client(comanda, j);
                        m.adauga_pret_la_total_client(pret, j);

                    }

                }

                cout<<"Desert doriti?\n";
                cin>>s;
                if(s == "da")
                {
                    string s1;
                    int nr_cupe = 0;
                    Desert ob;
                    cout<<"inghetata sau krant?\n";
                    cin>>s1;
                    if(s1 == "inghetata")
                    {
                        cout<<"Cate cupe?\n";
                        cin>>nr_cupe;
                        comanda = "inghetata " + to_string(nr_cupe) + " cupe";
                        try
                        {
                            ob.set_tip_desert("inghetata", nr_cupe);
                        }
                        catch(int x)
                        {
                            cout<<"trebuie sa alegeti intre 3 si 5 cupe!\n";
                            cin>>nr_cupe;
                            comanda = "inghetata " + to_string(nr_cupe) + " cupe";
                        }
                        catch(...)
                        {
                            cout<<"nr de cupe incorect!\n";
                        }
                        ob.set_pret(5);
                        pret = ob.get_pret();
                        m.adauga_comanda_la_client(comanda, j);
                        m.adauga_pret_la_total_client(pret, j);


                    }
                    else if(s1 == "krant" || s1 == "tort")
                    {
                        comanda = s1;
                        try
                        {
                            ob.set_tip_desert(s1, 0);
                        }
                        catch(int)
                        {
                            cout<<"nr cupe exista!\n";
                        }
                        catch(...)
                        {
                            cout<<"nr cupe neacceptat!\n";
                        }
                        ob.set_pret(5);
                        pret = ob.get_pret();
                        m.adauga_comanda_la_client(comanda, j);
                        m.adauga_pret_la_total_client(pret, j);
                    }
                    else
                        cout<<"nu exista in meniu acest desert!\n";


                }


                try
                {

                    m.adauga_client_la_masa();
                }
                catch(const char* x)
                {
                    cout<<x;
                }
                catch(...)
                {
                    cout<<"nu mai incapt clienti la aceasta masa!!!!\n";
                }
            }

            //cout<<m;
            int nr;
            cout<<"doriti nota pe masa sau pe client?(dati 1 pt masa, 2 pt client)\n";
            cin>>nr;
            switch(nr)
            {
            case 1:
                m.afiseaza_nota_per_masa();
                cout<<"\n";
                break;

            case 2:
                for(int k = 0; k<nr_clienti; k++)
                {
                    m.afiseaza_nota_per_client(k);


                }
                cout<<"\n";
                break;
            default:
                cout<<"optiune invalida!!!\n";
                break;

            }

        }

        /// m se distruge aici;
    }
    return 0;
}
