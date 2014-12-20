

// =================================================================
//                              Libraries
// =================================================================

#include <cstdlib>
#include <cstdio>
#include <cstring>



// =================================================================
//                            Project Files
// =================================================================
#include "cstring.h"
// #########################################################################
//                                                                         #
//                               Class STRING                              #
//                                                                         #
// #########################################################################

// =================================================================
//                    Definition of static attributes
// =================================================================
const int cstring::MAX_SIZE=255;
// =================================================================
//                             Constructors
// =================================================================

cstring::cstring(void)
{
  nb_char=0;
  capacity=0;
  data=NULL;
}

//constructor from c-string/////////////////////////////////////////
cstring::cstring(const char* databis)
{
  nb_char=strlen(databis);
  capacity=nb_char;
  data=new char[nb_char];
  memcpy (data, databis, nb_char+1);

}

//constructor with param////////////////////////////////////////////
cstring::cstring(const cstring &strbis)
{
  nb_char=strbis.nb_char;
  capacity=strbis.capacity;
  data=new char[capacity+1];
  memcpy (data,strbis.data, nb_char+ 1);
}  

// =================================================================
//                             Destructor
// =================================================================
cstring::~cstring(void)
{
  delete[] data;
  nb_char=0;
  capacity=0;
}

// =================================================================
//                             Operator
// =================================================================
//=string//////////////////////////////
cstring & cstring::operator= ( const cstring &str )
{
  char* temp_data=new char [str.nb_char+1];
  //memcpy(temp_data,str.data,str.nb_char+1);
  strcpy(temp_data,str.data);
  data=temp_data;
  return *this;
}
//=char////////////////////////////////
cstring & cstring::operator=(char c)
{
  char* str=new char[1];
  str[0]=c;
  
  data=str;
  capacity=1;
  nb_char=1;
  return *this;
}
//=*char///////////////////////////////
cstring & cstring::operator=(char* c){
  capacity=nb_char=strlen(c);
  data=c;
  return *this;
   }
//+char///////////////////////////////
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
//+string///////////////////////////
//since + is an unary operator, it concatenates 2 strings into the first
cstring& cstring::operator+(const cstring &str){
char *tot;
capacity=capacity+str.capacity;
int i;
for(i=0;i<nb_char;i++){
    tot[i]=data[i];
}
data=new char[capacity];
for(i=0;i<nb_char;i++){
    data[i]=tot[i];
}
for(i=0;i<str.nb_char;i++){
data[i+nb_char]=str.data[i];
}
nb_char=nb_char+str.nb_char;
return *this;
}
//return character in given position
char& cstring::operator[](unsigned int pos){
if(pos<capacity){
return *(data+pos);}
printf("Position [%d] inexistant\n",pos);
return *(data+pos);
}


// =================================================================
//                            Public Methods
// =================================================================
//gettor////////////////////////
int cstring::length()
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

char cstring::getChar(int place){
return *(data+place);
}

char* cstring::getData(){
return data;
};

//Method C_str///////////////////////////////////////////////////////:
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
//Method showstring-all the contenants of string will be shown////////
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
//Method clear string /////////////////////////////////////////////////
void cstring::clear(void)
{
  nb_char=0;
  data=new char[capacity+1];
  data[0]='\0';
}


//changes the size of the string by i
void cstring::reserve(int i){
  if(capacity+i<=nb_char){
	capacity=nb_char;//establishes a limit:reserve won't delete characters
}
  else capacity=capacity+i;
	int r;
	char* s=new char [capacity];
	for(r=0;r<nb_char;r++){
		s[r]=data[r];
	}
	for(r=nb_char;r<capacity;r++){
		s[r]='\0';}
	data=s;
}

//methods resize
//change nb_char in lg
//Method resize///////////////////////////////////////////////////////
void cstring::resize(int lg)
{
  int i;
  char * copy; //the non permanent table in which we copy value's data
  if(lg>capacity){
    capacity=lg; //increase capacity if lg longer than capacity
    copy=new char[lg];
    for(i=0;i<nb_char;i++){
      copy[i]=data[i]; //copy char into a table 
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

//method resize(int, char)
//modify size nb_char in lg, and eventually replace empty by  chars 'c'
void cstring::resize(int lg, char c){
  int i;
  int sizetamp=nb_char;
  resize(lg); //change size
  if(lg>sizetamp){
    for(i=sizetamp; i<lg;i++){
      data[i]=c; //put chars c into empty spaces create by changing the size
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

