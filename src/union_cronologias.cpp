#include "cronologia.h"
#include <fstream>

int main(int argc, char** argv)
{
  if(argc < 3)
    {
      std::cout << "Especifica al menos dos rutas a cronologías." << std::endl;
      return 1;
    }

  std::ifstream f1(argv[1]);
  std::ifstream f2(argv[2]);

  Cronologia c1, c2;

  f1 >> c1;
  f2 >> c2;

  Cronologia c3(c1, c2);

  if(argc < 4)
    {
      std::cout << c3;

      return 0;
    }

  std::ofstream f3(argv[3]);

  f3 << c3;
  
  return 0;
}
