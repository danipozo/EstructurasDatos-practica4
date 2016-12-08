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
  
  return 0;
}
