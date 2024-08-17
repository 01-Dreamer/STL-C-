#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cassert>

namespace my_std
{
    class my_string
    {

    public:
        //Member constants
        const static size_t npos;
        typedef char* iterator;
        typedef const char* const_iterator;


        //constructor,destructor and =
        my_string();
        my_string(const char* s);
        my_string(const my_string& s);
        my_string(size_t n,char c);
        my_string& operator=(const char* s);
        my_string& operator=(const my_string& s);
        ~my_string();


        //Iterators
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;


        //Capacity
        size_t size() const;
        size_t capacity() const;
        bool empty() const;
        void reserve(size_t n);
        void resize(size_t n);
        void resize(size_t n,char c);
        void clear();


        //Element access
        char& operator[](size_t pos);
        const char& operator[](size_t pos) const;


        //Modifiers
        my_string& operator+=(char c);
        my_string& operator+=(const char* s);
        my_string& operator+=(const my_string& s);
        my_string& insert(size_t pos,const char* s);
        my_string& insert(size_t pos,const my_string& s);
        my_string& insert(size_t pos,size_t n,char c);
        my_string& replace(size_t pos,size_t len,const char* s);
        my_string& replace(size_t pos,size_t len,const my_string& s);
        my_string& replace(size_t pos,size_t len,size_t n,char c);
        my_string& erase(size_t pos=0,size_t len=npos);


        //String operations
        const char* c_str() const;
        size_t find(const char* s,size_t pos=0) const;
        size_t find(const my_string& s,size_t pos=0) const;
        size_t find(char c,size_t pos=0) const;
        my_string substr(size_t pos=0,size_t len=npos) const;
        bool operator==(const char* s) const;
        bool operator!=(const char* s) const;
        bool operator>(const char* s) const;
        bool operator<(const char* s) const;
        bool operator>=(const char* s) const;
        bool operator<=(const char* s) const;
        bool operator==(const my_string& s) const;
        bool operator!=(const my_string& s) const;
        bool operator>(const my_string& s) const;
        bool operator<(const my_string& s) const;
        bool operator>=(const my_string& s) const;
        bool operator<=(const my_string& s) const;


        //Non-member function overloads
        friend my_string operator+(const my_string& s1,const my_string& s2);
        friend my_string operator+(const my_string& s1,const char* s2);
        friend my_string operator+(const char* s1,const my_string& s2);
        friend my_string operator+(const my_string& s,char c);
        friend my_string operator+(char c,const my_string& s);
        friend std::ostream& operator<<(std::ostream& out,const my_string& s);
        friend std::istream& operator>>(std::istream& in,my_string& s);
        friend void swap(my_string& s1,my_string& s2);


    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    };


}
