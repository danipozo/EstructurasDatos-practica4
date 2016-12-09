#include "cronologia.h"
#include <fstream>

int main(int argc, char** argv)
{
  if(argc < 4)
    {
      std::cout << "Especifica al menos una ruta a una cronología y un intervalo." << std::endl;
      return 1;
    }

  std::ifstream f1(argv[1]);

  Cronologia c1;

  f1 >> c1;

  Cronologia c2(c1.filtrarEventos(std::stoi(argv[2]), std::stoi(argv[3])));

  if(argc < 5)
    {
      std::cout << c2;

      return 0;
    }

  std::ofstream f2(argv[3]);

  f2 << c2;
  
  return 0;
}
