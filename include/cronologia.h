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

    // --- Métodos que modifican el estado.
    void agregarEvento(const EventoHistorico& e) { eventos.insert(std::make_pair(e.obtenerFecha(), e)); }

    // --- Métodos que no modifican el estado.
    Cronologia filtrarEventos(const std::string& palabraClave);
    Cronologia filtrarEventos(int fechaInicio, int fechaFinal);
    void estadisticas(int& numEventos, int& totalAcont, int& maximoAcont, double& promedioAcont);

    // --- Métodos que devuelven iteradores.
    Iterador inicio() { return eventos.begin(); }
    Iterador final() { return eventos.end(); }

    IteradorConst inicio() const { return eventos.cbegin(); }
    IteradorConst final() const { return eventos.cend(); }

    // --- Entrada/salida.
    friend std::istream& operator>>(std::istream& is, Cronologia& c);
    friend std::ostream& operator<<(std::ostream& os, const Cronologia& c);
};

#endif // CRONOLOGIA_H
