#include <iostream>
#include "Stiva_de_caractere.h"

using namespace std;

int main()
{
   //Nod A('1');
//    cout<<A.get_info()<<"\n";
//   Nod *a = new Nod();

    Stiva_de_caractere S1,S3,S2;
    cout<<"Stiva 1 e goala?: "<<S1.isempty()<<"\n";
     S1.push('a');
     cout<<"Stiva 1 e goala?: "<<S1.isempty()<<"\n";
     cout<<"Varful stivei 1 este:";
      S1.top();
      S1.push('b');
      cout<<"Parcurgerea stivei 1 este: ";
      S1.parcugere();
      S1.pop();
      cout<<"Noul varf al stivei 1 dupa pop este: ";
      S1.top();
      cout<<"Supraincarcarea operatorului << concomitent cu golirea stivei: "<<S1;

      string s;
      cout<<"Dati elemtele sirului de inversat: ";
      cin>>s;

      cout<<"sirul inversat este: "<<S2.inversare_sir(s)<<"\n";


      cin>>S3;
      cout<<S3<<"\n";


    Stiva_de_caractere S5,S4;
    S3.push('E');
    S3.push('X');
    S3.push('A');
    S3.push('M');
    S3.push('E');
    S3.push('N');

    S4.push('P');
    S4.push('O');
    S4.push('O');
    S4.push('L');
    S4.push('A');
    S4.push('B');
    S4.push('O');
    S4.push('R');
    S4.push('A');
    S4.push('T');
    S4.push('O');
    S4.push('R');

     S5 = S3- S4;
     cout<<"Supraincarcare operator -: ";
     cout<<S5;

     Stiva_de_caractere X;
     X.memorare();








    return 0;
}
