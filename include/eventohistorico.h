/**
 * @file   eventohistorico.h
 * @author Daniel Pozo Escalona
 * @brief  Fichero de cabecera del TDA EventoHistorico.
 *
 *
 */


#ifndef EVENTOHISTORICO_H
#define EVENTOHISTORICO_H

#include <set>
#include <utility>
#include <string>
#include <iostream>

/**
 * @brief TDA EventoHistorico.
 *
 * Una instancia de @e EventoHistorico representa una fecha
 * y una serie de eventos históricos ocurridos en esa fecha.
 *
 */

class EventoHistorico
{
  private:
    std::pair<int, std::set<std::string>> evento; /**< Par que contiene la fecha y un *set*
						     con eventos históricos.*/

  public:
    // --- Definición de iteradores.
    typedef std::set<std::string>::iterator Iterador; /**< Iterador sobre los eventos. */
    typedef std::set<std::string>::const_iterator IteradorConst; /**< Iterador constante
								    sobre los eventos.*/

    // --- Contructores.
    EventoHistorico() = default; /**< Constructor por defecto. */
    EventoHistorico(const EventoHistorico& ev1, const EventoHistorico& ev2); /**< Constructor de mezcla. */
    EventoHistorico(int fecha) : evento(fecha, std::set<std::string>()) {} /**< Constructor con fecha. */
    /**
     * Construye una instancia de *EventoHistorico* a partir de una línea de un fichero de datos.
     *
     * @param linea
     */
    EventoHistorico(const std::string& linea);
    ~EventoHistorico() = default; /**< Destructor por defecto. */

    // --- Métodos que no modifican el estado.
    int obtenerFecha() const { return evento.first; } /**< Devuelve la fecha asociada a la
							 instancia.*/
    /**
     * @return Número de eventos en el objeto.
     */
    int numeroElementos() const { return evento.second.size(); }
    /**
     * @param palabraClave
     *
     * @return EventoHistorico con los eventos que contengan la palabra clave.
     */
    EventoHistorico filtrarEventos(const std::string& palabraClave);
    /**
     * @return El conjunto de eventos asociado a la instancia.
     */
    const std::set<std::string>& obtenerEventos() const { return evento.second; }

    /**
     * @return Iterador constante al inicio del conjunto de eventos asociado.
     */
    IteradorConst inicio() const { return evento.second.cbegin(); }
    /**
     * @return Iterador constante al final del conjunto de eventos asociado.
     */
    IteradorConst final() const { return evento.second.cend(); }


    // --- Métodos que modifican el estado.
    /**
     * Inserta un evento en el conjunto de eventos asociado.
     *
     * @param ev
     */
    void insertarEvento(const std::string& ev) { evento.second.insert(ev); }

    /**
     * @return Iterador al inicio del conjunto de eventos asociado.
     */
    Iterador inicio() { return evento.second.begin(); }
    /**
     * @return Iterador al final del conjunto de eventos asociado.
     */
    Iterador final() { return evento.second.end(); }
    /**
     * Operador de salida mediante flujo.
     *
     * @param os
     * @param ev
     *
     * @return os
     */
    friend std::ostream& operator<<(std::ostream& os, const EventoHistorico& ev);
};


#endif // EVENTOHISTORICO_H
