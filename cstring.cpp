#include "cstring.h"
#include<cstdlib>
#include<cstdio>
#include<cstring>
const int cstring::MAX_SIZE=255;

//constructors
cstring::cstring(void)
{
  nb_char=0;
  capacity=0;
  
  data=NULL;
}

cstring::cstring(char* databis)
{
  nb_char=strlen(databis);
  capacity=nb_char;
  data=new char[nb_char];
  int i;
  for(i=0;i<nb_char;i++){
    data[i]=databis[i];
  }

}



//getters
int cstring::getLength()
{
  return nb_char;
}

int cstring::getCapacity()
{ 
  return capacity;
}

