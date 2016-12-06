#include "eventohistorico.h"

int main()
{
  EventoHistorico ev("1934#kjdnkfjnd#lsnvlsnv#sjnvksjvn");

  for(auto i = ev.inicio(); i != ev.final(); i++)
    std::cout << *i << std::endl;
  
  return 0;
}
