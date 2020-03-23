#include "Nod.h"

Nod::Nod(char v)
    {
        info = v;
        link = nullptr;
    }

Nod::Nod():nr_elem(0),info('\0'),link(nullptr) {}

void Nod::set_info(char v)
    {
        info = v;
    }

void Nod::set_link(Nod *elem)
    {
        link = elem;
    }

 Nod *Nod::get_link() const
    {
        return link;
    }

char Nod::get_info() const
    {
        return info;
    }

Nod::~Nod()
{
    if(link!=nullptr)
         delete link;


//delete info;
}
