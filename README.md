# Programare-orientata-pe-obiecte

## 1. _Stiva de caractere_
_Principii de baza oop: incapsulare, obiecte, clase, constructori de copiere, parametrizati, fara parametrii, destructori, supraincarcare operatori, functii care intorc obiecte, polimorfism_ \
Proiect care raspunde urmatoarelor cerinte:\
se considera _clasa Nod_ :
```
class Nod{char info;
Nod* next;}

```
se considera _clasa Stiva_de_caractere_ care are:
- membru privat _Nod*_ varful stivei;
- un constructor care initializeaza varful stivei cu NULL;
- un destructor care dezaloca toate elem. stivei;
- metode publice _push_ , _top_ , _isempty_ ;
- supraincarcarea operatorului << care afiseaza stiva concomintent cu golirea ei;
- supraincarcarea operatorului >> prin pushuri succesive;
- metoda pentru inversare sir utilizand stiva;
- supraincarcarea operatorului - (diferenta dintre stive, elementul cu codul ASCII mai mare e introdus intr-o stiva noua);

