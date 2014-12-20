


//****************************************************************************
//
//                         CSTRING
//
//****************************************************************************



#ifndef __CSTRING_H__
#define __CSTRING_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>




// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================






class cstring
{
  public:
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    cstring(void);
    cstring(const char* databis);
    cstring(const cstring &strbis);
    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~cstring(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    inline int length();
    inline int getSizeMax(); //here's the max_size method
    inline int getCapacity();
    inline char getChar(int place);
    inline char* getData();
    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    inline void setLength(int length);
    inline void setData(char* databis);
    inline void setChar(int place, char letter);
    // =======================================================================
    //                                Operators
    // =======================================================================
    cstring & operator= ( const cstring &str );
    cstring & operator=(char c);
    cstring & operator=(char* c);
    cstring operator+(char ch);
    cstring& operator+(const cstring & str);
    char& operator[](unsigned int pos);
    // =======================================================================
    //                              Public Methods
    // =======================================================================
    const char* c_str(void) const;
    void showstring (void);
    void reserve(int i);
    void clear(void);
    char& at(int pos);
    //modification de la taille
    void resize(int lg); //modifie la taille 
    void resize(int lg, char c);
    bool empty(void);
    void limit(void);
    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    private:
    int nb_char, capacity;
    char* data;
    static const int MAX_SIZE;
};

#endif // __CSTRING_H__

