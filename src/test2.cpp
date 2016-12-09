#include "cronologia.h"
#include <fstream>

int main()
{
    Cronologia c1, c2;

    std::ifstream i1("../datos/timeline_worldhistory.txt");
    std::ifstream i2("../datos/timeline_science.txt");

    i1 >> c1;
    i2 >> c2;

    Cronologia c3(c1, c2);

    for(auto i = c3.inicio(); i != c3.final(); i++)
    {
        std::cout << i->second << std::endl;
    }

    Cronologia c4(c3.filtrarEventos(1924, 1988));

    int numEventos, totalAcont, maximoAcont; double promedioAcont;
    c4.estadisticas(numEventos, totalAcont, maximoAcont, promedioAcont);

    //std::cout << c4 << std::endl << std::endl;

    std::cout << "N. eventos: " << numEventos << std::endl;
    std::cout << "T. acont: " << totalAcont << std::endl;
    std::cout << "M. acont.: " << maximoAcont << std::endl;
    std::cout << "P. acont.: " << promedioAcont << std::endl;

    return 0;
}
