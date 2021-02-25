# Programare-orientata-pe-obiecte

## 1. _Stiva de caractere_
### [Link proiect](https://github.com/iuga-paula/Programare-orientata-pe-obiecte/tree/master/Tema1)
_Principii de baza oop: incapsulare, obiecte, clase, constructori de copiere, parametrizati, fara parametrii, destructori, supraincarcare operatori, functii care intorc obiecte, polimorfism, functii friend_ \
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

<hr>

## _Restaurant - gestiunea comenzilor si a clientilor_
### [Link proiect](https://github.com/iuga-paula/Programare-orientata-pe-obiecte/tree/master/Tema2)
_Principii oop : functii inline, mostenire, clase abstracte, functii virtuale pure, override, mostenire virtuala, functii virtuale, static, mostenire diamant_ \
\
Proiect care raspunde urmatoarelor cerinte:\
La restaurant se afla mai multe mese, fiecare masa are o capaciatate maxima de persoane. Clientii sosesc in grupuri si se aseaza la
o masa suficient de incapatoare pentru ei. Un chelner ii intreaba pe rand daca vor un anumit fel de mancare/bautura/desert (intrebari cu raspuns scurt, de exemplu : 
```
Doriti ciorba? 
Da
De care? 
De legume
Cu sau fara smantana? 
Cu
Cu sau fara Ardei?
Fara
Fel principal doriti? 
Nu
Desert doriti? 
Nu
```
). Dupa ce mananca elibereaza masa si pot cere nota de plata individual sau pe masa.


<hr>

## _Catalog individual si gestiunea studentilor in sesiune_
### [Link proiect](https://github.com/iuga-paula/Programare-orientata-pe-obiecte/tree/master/Tema3)
_Principii oop : abstractizare, design patterns, templates, specializari, destructori virtuali, exceptii, STL_ \
\
Scenariu:\
Studentii unei facultati sustin mai multe examene in sesiune. Fiecare examen are un numar incrementat automat, denumirea materiei si data. In functie de tipul examenului exista mai multe note auxiliare:
- Partialul - nota la oral
- Examen final - puncte in plus pentru proiect
- Quizz - pentru studentii care vor sa isi mareasca nota finala - contine un numar de itemi tip grila

Cerinte:\
- Sa se retina elevii care nu au trecut examenului intr-o structura de tip unordered_map <id_examen, vector<elev>>
- Sa se construiasca clasa template CatalogIndividual care contine informatii despre tipurile de examene date de un student, numar matricol (unic per student) si nr_examene
- Pentru adaugarea unei noi pagini in Catalog se supraincarca operatorul +=
- Sa se realizeze o specializare pt Quizz care adapteaza operatorul si afiseaza cate pers. au dat cel putin 2 quizz - uri


