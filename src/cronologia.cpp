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
	  eventos.insert(std::make_pair(it1->first, EventoHistorico(it1->second, it2->second)));
            it1++;
            it2++;
        }
        else
        {
            if(it1->first < it2->first)
            {
                eventos.insert(*it1);
                //eventos.insert(*it2);
		it1++;
            }
            else
            {
                eventos.insert(*it2);
                //eventos.insert(*it1);
		it2++;
            }
        }
    }
}

std::istream& operator>>(std::istream& is, Cronologia& c)
{
  std::string line;

    while(std::getline(is, line))
    {
        c.agregarEvento(EventoHistorico(line));
    }

  
  return is;
}
