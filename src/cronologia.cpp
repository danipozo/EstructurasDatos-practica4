#include "cronologia.h"

Cronologia::Cronologia(const Cronologia& c1, const Cronologia& c2)
{
    Cronologia::IteradorConst it1 = c1.inicio();
    Cronologia::IteradorConst it2 = c2.inicio();

    while(true)
    {
        if(it1 == c1.final())
        {
            for(; it2 != c2.final(); it2++)
            {
                eventos.insert(*it2);
            }

	    break;
        }

        if(it2 == c2.final())
        {
            for(; it1 != c1.final(); it1++)
            {
                eventos.insert(*it1);
            }

	    break;
        }

        if(it1->first == it2->first)
        {
            eventos.insert(EventoHistorico(*it1, *it2));
            it1++;
            it2++;
        }
        else
        {
            if(it1->first < it2->first)
            {
                eventos.insert(*it1);
                eventos.insert(*it2);
            }
            else
            {
                eventos.insert(*it1);
                eventos.insert(*it2);
            }
        }
    }
}
