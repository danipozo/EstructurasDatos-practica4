#include "eventohistorico.h"

EventoHistorico::EventoHistorico(const std::string& linea)
{
    int indice = linea.find ('#', 0), anterior;
    bool parada;

    evento.first = std::stoi (linea.substr (0, indice));

    do
    {
        anterior = indice + 1;
        parada = (indice = linea.find ('#', anterior)) == std::string::npos;
        insertarEvento(linea.substr (anterior, parada ? std::string::npos : indice - anterior));
    }
    while (!parada);
}

EventoHistorico::EventoHistorico(const EventoHistorico& ev1, const EventoHistorico& ev2)
{
    evento.first = ev1.obtenerFecha();

    for(auto i = ev1.inicio(); i != ev1.final(); i++)
        insertarEvento(*i);

    for(auto i = ev2.inicio(); i != ev2.final(); i++)
        insertarEvento(*i);
}

std::ostream& operator<<(std::ostream& os, const EventoHistorico& ev)
{
    os << ev.evento.first << ':' << std::endl;

    for(auto &i : ev.evento.second)
    {
        os << "    - " << i << std::endl;
    }

    return os;
}

EventoHistorico EventoHistorico::filtrarEventos(const std::string& palabraClave)
{
    EventoHistorico ev(evento.first);

    for(auto i = inicio(); i != final(); i++)
    {
        if(i->find(palabraClave) != std::string::npos)
            ev.insertarEvento(*i);
    }

    return ev;
}
