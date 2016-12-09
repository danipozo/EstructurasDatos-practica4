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
                it1++;
            }
            else
            {
                eventos.insert(*it2);
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


std::ostream& operator<<(std::ostream& os, const Cronologia& c)
{
    for(auto i = c.inicio(); i != c.final(); i++)
    {
        os << i->first << '#';

        int t = 0;
        for(auto &j : i->second.obtenerEventos())
        {
            os << j;
            t++;

            if(t == i->second.numeroElementos())
                break;

            os << '#';
        }

        os << std::endl;
    }

    return os;
}


Cronologia Cronologia::filtrarEventos(const std::string& palabraClave)
{
    Cronologia c;

    for(auto i = inicio(); i != final(); i++)
    {
        EventoHistorico ev(i->second.filtrarEventos(palabraClave));

        if(ev.inicio() != ev.final())
            c.agregarEvento(ev);
    }

    return c;
}

Cronologia Cronologia::filtrarEventos(int fechaInicio, int fechaFinal)
{
    Cronologia c;

    IteradorConst it1 = eventos.lower_bound(fechaInicio);
    IteradorConst it2 = eventos.lower_bound(fechaFinal);

    for(; it1 != it2; it1++)
    {
        c.agregarEvento(it1->second);
    }

    return c;
}

void Cronologia::estadisticas(int &numEventos, int &totalAcont, int &maximoAcont, double &promedioAcont)
{
    numEventos = eventos.size();
    totalAcont = 0;
    maximoAcont = 0;

    for(auto i = inicio(); i != final(); i++)
    {
        totalAcont += i->second.numeroElementos();

        if(i->second.numeroElementos() > maximoAcont)
            maximoAcont = i->second.numeroElementos();
    }

    promedioAcont = (double) totalAcont/eventos.size();
}
