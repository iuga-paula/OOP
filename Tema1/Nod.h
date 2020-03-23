#ifndef NOD_H_INCLUDED
#define NOD_H_INCLUDED



class Nod
{

private:
    int nr_elem;
    char info;
    Nod *link;

public:
    Nod(char);
    Nod();
    void set_info(char);
    void set_link(Nod *);
    Nod *get_link() const;
    char get_info() const;
    ~Nod();

};
#endif // NOD_H_INCLUDED
