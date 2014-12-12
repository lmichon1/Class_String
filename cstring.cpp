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


cstring & cstring::operator=(char c)
{
  char* str=new char[1];
  str[0]=c;
  //cstring  * cstr = new cstring(str);
  //printf("je suis dans operator = et la long vaut %d\n", cstr->getLength());
  data=str;
  capacity=1;
  nb_char=1;
  return *this;
}

cstring cstring::operator+(char ch)
{
  int temp_nb_char=nb_char+2;
  char* temp_data=new char[temp_nb_char];//reserve memory of tempolary string
  memcpy(temp_data,data,nb_char*sizeof(*data));
  temp_data[temp_nb_char-2]=ch;
  temp_data[temp_nb_char-1]='\0';

  cstring* final_data=new cstring(temp_data);
  return *final_data;
}

  /*printf("j'entre dans ma méthode\n");
  int nb_char2=nb_char+strlen(databis);
  int capacity2=capacity+strlen(databis);
  printf("j'ai créé les entiers longueur et capacité\n");
  char* char_tamp=new char[nb_char2];
  int i,j;
  printf("j'ai créé mon char* charbis\n");
  for(i=0;i<nb_char;i++)
  {
     char_tamp[i] =data[i];
  }
  printf("j'ai copié les char de la string\n");
  for(j=0;j<strlen(databis);j++)
  {
     char_tamp[j+nb_char]=databis[j];
  }
  printf("j'ai ajouté les char de char*\n");
  cstring *cstr=new cstring(char_tamp);
  printf("j'ai créé la string que je vais retourner\n");
  return *cstr;
*/



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
}
//public methode/ show everything from string

const char* cstring::c_str(void) const
{
  char * temp_data=new char[nb_char+1];
  int i;
  for(i=0;i<nb_char;i++)
  {
    temp_data[i]=data[i];
  }
  temp_data[nb_char]='\0';
  return temp_data;
}

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
//clear string
void cstring::clear(void)
{
  nb_char=0;
  data=new char[capacity+1];
  data[0]='\0';
}


//changes the size of the string by i
/*
void cstring::reserve(int i){
if(i<0){
  if(capacity+i<=nb_char){
	capacity=nb_char;//establishes a limit:reserve won't delete characters
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
*/

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
  return *(data+pos);
}






//verify if a string is empty
bool cstring::empty(void){
return nb_char==0;
}

