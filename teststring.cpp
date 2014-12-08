#include "cstring.h"
#include<cstdlib>
#include<cstdio>

int main(int argc, char* argv[])
{
  cstring  phrase/*=new cstring()*/;
  printf("la taille vaut %d et la capacité vaut %d\n", phrase.getLength(),phrase.getCapacity());
  
}
