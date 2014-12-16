#include "cstring.h"
#include <cstdlib>
#include <cstdio>

int main(int argc, char* argv[])
{


  



  cstring str1=cstring("toto1");
  cstring str3=str1;
 	

  	
  str1.showstring();
  (str3+'o').showstring();
  str3.showstring();
  printf("la taille vaut %d et la capacité vaut %d\n", str3.getLength(),str3.getCapacity());

  return 0;
}

