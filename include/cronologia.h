/**
 * @file   cronologia.h
 * @author Daniel Pozo Escalona
 * 
 * @brief  Archivo de cabecera del TDA Cronologia.
 * 
 * 
 */

#ifndef CRONOLOGIA_H
#define CRONOLOGIA_H

#include "eventohistorico.h"
#include <map>

/**
 * @brief TDA Cronologia.
 * 
 */

class Cronologia
{
  private:
    std::map<int, EventoHistorico> eventos; /**< Contenedor asociativo para los eventos. */

  public:
    // --- Iteradores.
    typedef std::map<int, EventoHistorico>::iterator Iterador; /**< Tipo iterador. */
    typedef std::map<int, EventoHistorico>::const_iterator IteradorConst; /**< Tipo iterador constante. */

    Cronologia() = default;	/**< Constructor por defecto. */
    Cronologia(const Cronologia& c1, const Cronologia& c2); /**< Constructor de mezcla. */

    // --- Métodos que modifican el estado.
  /** 
   * Agrega *e* a la cronología.
   * 
   * @param e 
   */
    void agregarEvento(const EventoHistorico& e) { eventos.insert(std::make_pair(e.obtenerFecha(), e)); }

    // --- Métodos que no modifican el estado.
  /** 
   * Filtra los eventos que contengan la palabra clave.
   * 
   * @param palabraClave 
   * 
   * @return Cronología con dichos eventos.
   */
    Cronologia filtrarEventos(const std::string& palabraClave);
  /** 
   * Filtra los eventos cuya fecha esté en [fechaInicio, fechaFinal].
   * 
   * @param fechaInicio 
   * @param fechaFinal 
   * 
   * @return Cronología con dichos eventos.
   */
    Cronologia filtrarEventos(int fechaInicio, int fechaFinal);
  /** 
   * Devuelve en los parámetros los siguientes datos:
   *
   * - Número de eventos.
   * - Total de acontecimientos.
   * - Máximo de acontecimientos en un evento.
   * - Promedio de acontecimientos en un evento.
   * 
   * @param numEventos 
   * @param totalAcont 
   * @param maximoAcont 
   * @param promedioAcont 
   */
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
