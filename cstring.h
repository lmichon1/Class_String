class cstring
{

 public:
  //constructors
  cstring(void);
  cstring(char* str);
  cstring(const cstring &strbis);

  //setters
  void setLength(int length);
  void setData(char* databis);
  void setChar(int place, char letter);
  
  //operator
  cstring & operator= ( const cstring &str );

  //getters
  int getLength();
  int getSizeMax();
  int getCapacity();
  int getChar(int place);
 //methode
  void showstring (void);
  void reserve(int i);
  char& at(int pos);
  //modification de la taille
  void resize(int lg); //modifie la taille 
  void resize(int lg, char c);
  bool empty(void);

  //Destructor
  ~cstring(void);

 private:
  int nb_char, capacity;
  char* data;
  static const int MAX_SIZE;

};

