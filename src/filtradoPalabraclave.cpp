#include "cronologia.h"
#include <fstream>

int main(int argc, char** argv)
{
  if(argc < 3)
    {
      std::cout << "Especifica al menos una ruta a una cronología y una palabra clave." << std::endl;
      return 1;
    }

  std::ifstream f1(argv[1]);

  Cronologia c1;

  f1 >> c1;

  Cronologia c2(c1.filtrarEventos(argv[2]));

  if(argc < 4)
    {
      std::cout << c2;

      return 0;
    }

  std::ofstream f2(argv[3]);

  f2 << c2;
  
  return 0;
}
