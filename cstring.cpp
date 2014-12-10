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
cstring::cstring(const char* databis)
{
  nb_char=strlen(databis);
  capacity=nb_char;
  data=new char[nb_char];
  memcpy (data, databis, nb_char+1);

}


cstring::cstring(const cstring &strbis)// constructor with param
{
  nb_char=strbis.nb_char;
  capacity=strbis.capacity;
  data=new char[capacity+1];
  memcpy (data,strbis.data, nb_char+ 1);
}  

//operators
cstring & cstring::operator= ( const cstring &str )
{
  char* temp_data=new char [str.nb_char+1];
  strcpy(temp_data,str.data);
  data=temp_data;
  return *this;
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
//public methode/ show everything from string
void cstring::showstring (void)
{
  printf("%p\n");
  printf("%d\n",nb_char);
  printf("%d\n",capacity);
  int i;
  for(i=0;i<nb_char;i++)
  {
    printf("%c",data[i]);
  }
  printf("\n");

}


//changes the size of the string by i

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



//operator
cstring & cstring::operator=(char c)
{
  char* str=new char[1];
  str[0]=c;
  cstring  * cstr = new cstring(str);
return *(cstr);
}


//verify if a string is empty
bool cstring::empty(void){
return nb_char==0;
}

