#ifndef CRONOLOGIA_H
#define CRONOLOGIA_H

#include "eventohistorico.h"
#include <map>

class Cronologia
{
  private:
    std::map<int, EventoHistorico> eventos;

  public:
    // --- Iteradores.
    typedef std::map<int, EventoHistorico>::iterator Iterador;
    typedef std::map<int, EventoHistorico>::const_iterator IteradorConst;

    Cronologia() = default;
  Cronologia(const Cronologia& c1, const Cronologia& c2);

  void agregarEvento(const EventoHistorico& e) { eventos.insert(std::pair<int,EventoHistorico>(e.obtenerFecha(), e)); }

    // --- Métodos que devuelven iteradores.
    Iterador inicio() { return eventos.begin(); }
    Iterador final() { return eventos.end(); }

    IteradorConst inicio() const { return eventos.cbegin(); }
    IteradorConst final() const { return eventos.cend(); }

    // --- Entrada.
  friend std::istream& operator>>(std::istream& is, Cronologia& c);
};

#endif // CRONOLOGIA_H
