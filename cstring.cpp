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

//constructor from c-string
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

int cstring::getSizeMax()
{
  return MAX_SIZE;
}
//destructor
cstring::~cstring(){
	delete &nb_char;
	delete &capacity;
	delete data;
}

//changes the size of the string by i
void cstring::reserve(int i){
if(i<0){
  if(capacity+i<=nb_char){
	capacity=nb_char;/*establishes a limit:reserve won't delete characters*/ 
	}
  else capacity=capacity+i;
  delete &(*(data+capacity));
}
  else{
	int r;
	char* s=new char [i];
	for(r=capacity;r<capacity+i;r++){
		*(data+capacity+r)=*(s+r);
	}
	capacity=capacity+i;
}}
//methods resize
//modification de nb_char en lg
void cstring::resize(int lg)
{
  int i;
  char * copy; //le tableau non permanent dans lequel on recopie les valeurs de datas
  if(lg>capacity){
    capacity=lg; //augmentation de la capacity si lg plus grand que capacity
    copy=new char[lg];
    for(i=0;i<nb_char;i++){
      copy[i]=data[i]; //recopie les char dans un tableau 
    }
    data=copy;
  }
  else{
    copy=new char[lg];
    for(i=0;i<lg;i++){
      copy[i]=data[i];
    }
    data=copy;
  }
  delete[] copy;
 nb_char=lg;
}

//modifie la taille nb_char en lg, et éventuellemnt comble le vide par des char 'c'
void cstring::resize(int lg, char c){
  int i;
  int sizetamp=nb_char;
  resize(lg); //modifie la taille
  if(lg>sizetamp){
    for(i=sizetamp; i<lg;i++){
      data[i]=c; //mets les caractères c dans l'espace vide créer par le changement de taille
    }
  }
}

//return the char's adress at the position pos
char & cstring::at(int pos)
{
  /* if(pos>nb_char){
    return NULL;
    }*/
  return *(data+pos);
}
//verify if a string is empty
bool cstring::empty(void){
return nb_char==0;
}
