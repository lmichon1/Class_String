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

  //getters
  int getLength();
  int getSizeMax();
  int getCapacity();
  int getChar(int place);



 private:
  int nb_char, capacity;
  char* data;
  static const int MAX_SIZE;

};

