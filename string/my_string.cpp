#include"my_string.h"


namespace my_std
{
    //Member constants
    const size_t my_string::npos=-1;


    my_string::my_string():my_string(""){}
    my_string::my_string(const char* s)
    {
        _size=strlen(s);
        _capacity=_size+5;
        _str=new char[_capacity+1]{0};
        strcpy(_str,s);
    }
    my_string::my_string(const my_string& s):my_string(s._str){}
    my_string& my_string::operator=(const char* s)
    {
        _size=strlen(s);
        if(_size>=_capacity)
        {
            _capacity=std::max(_size+5,(_capacity+2)*3/2);
            delete[] _str;
            _str=new char[_capacity+1]{0};
        }
        strcpy(_str,s);
        _str[_size]='\0';
        return *this;
    }
    my_string& my_string::operator=(const my_string& s)
    {
        return *this=s._str;
    }
    my_string::my_string(size_t n,char c)
    {
        _size=n;
        _capacity=_size+5;
        _str=new char[_capacity+1]{0};
        memset(_str,c,_size);
    }
    my_string::~my_string()
    {
        delete[] _str;
        _size=0;
        _capacity=0;
    }


    //Iterators
    my_string::iterator my_string::begin()
    {
        return _str;
    }
    my_string::iterator my_string::end()
    {
        return _str+_size;
    }
    my_string::const_iterator my_string::begin() const
    {
        return _str;
    }
    my_string::const_iterator my_string::end() const
    {
        return _str+_size;
    }


    //Capacity
    size_t my_string::size() const
    {
        return _size;
    }
    size_t my_string::capacity() const
    {
        return _capacity;
    }
    bool my_string::empty() const
    {
        return _size==0;
    }
    void my_string::reserve(size_t n)
    {
        if(n<=_capacity) return;
        _capacity=n;
        char* tmp=new char[_capacity+1]{0};
        strcpy(tmp,_str);
        delete[] _str;
        _str=tmp;
    }
    void my_string::resize(size_t n)
    {
        if(n<=_size)
        {
            _size=n;
            _str[_size]='\0';
        }
        else resize(n,'\0');
    }
    void my_string::resize(size_t n,char c)
    {
        if(n<=_size) resize(n);
        else
        {
            if(n>_capacity) reserve(n+5);;
            memset(_str+_size,c,n-_size);
            _size=n;
            _str[_size]='\0';
        }
    }
    void my_string::clear()
    {
        _str[_size=0]='\0';
    }


    //Element access
    char& my_string::operator[](size_t pos)
    {
        assert(pos<_size);
        return _str[pos];
    }
    const char& my_string::operator[](size_t pos) const
    {
        assert(pos<_size);
        return _str[pos];
    }


    //Modifiers
    my_string& my_string::operator+=(char c)
    {
        if(_size>=_capacity) reserve((_capacity+2)*3/2);
        _str[_size++]=c;
        _str[_size]=0;
        return *this;
    }
    my_string& my_string::operator+=(const char* s)
    {
        size_t sz=strlen(s);
        if(_size+sz>=_capacity)
        {
            size_t new_capacity=std::max(_size+sz+5,(_capacity+2)*3/2);
            reserve(new_capacity);
        }
        strcpy(_str+_size,s);
        _size+=sz;
        _str[_size]='\0';
        return *this;
    }
    my_string& my_string::operator+=(const my_string& s)
    {
        *this+=s.c_str();
        return *this;
    }
    my_string& my_string::insert(size_t pos,const char* s)
    {
        assert(pos<=_size);
        size_t sz=strlen(s);
        if(_size+sz>=_capacity)
        {
            size_t new_capacity=std::max(_size+sz+5,(_capacity+2)*3/2);
            reserve(new_capacity);
        }
        memmove(_str+pos+sz,_str+pos,_size-pos);
        memcpy(_str+pos,s,sz);
        _size+=sz;
        _str[_size]='\0';
        return *this;
    }
    my_string& my_string::insert(size_t pos,const my_string& s)
    {
        assert(pos<=_size);
        this->insert(pos,s._str);
        return *this;
    }
    my_string& my_string::insert(size_t pos,size_t n,char c)
    {
        assert(pos<=_size);
        if(_size+n>=_capacity)
        {
            size_t new_capacity=std::max(_size+n+5,(_capacity+2)*3/2);
            reserve(new_capacity);
        }
        memmove(_str+pos+n,_str+pos,_size-pos);
        memset(_str+pos,c,n);
        _size+=n;
        _str[_size]='\0';
        return *this;
    }
    my_string& my_string::replace(size_t pos,size_t len,const char* s)
    {
        assert(pos+len<=_size);
        size_t sz=strlen(s);
        if(_size+sz>=_capacity)
        {
            size_t new_capacity=std::max(_size+sz+5,(_capacity+2)*3/2);
            reserve(new_capacity);
        }
        if(sz!=len) memmove(_str+pos+sz,_str+len,_size-pos-len);
        memcpy(_str+pos,s,sz);
        _size+=sz-len;
        _str[_size]='\0';
        return *this;
    }
    my_string& my_string::replace(size_t pos,size_t len,const my_string& s)
    {
        replace(pos,len,s._str);
        return *this;
    }
    my_string& my_string::replace(size_t pos,size_t len,size_t n,char c)
    {
        assert(pos+len<=_size);
        if(_size+n>=_capacity)
        {
            size_t new_capacity=std::max(_size+n+5,(_capacity+2)*3/2);
            reserve(new_capacity);
        }
        if(n!=len) memmove(_str+pos+n,_str+len,_size-pos-len);
        memset(_str+pos,c,n);
        _size+=n-len;
        _str[_size]='\0';
        return *this;
    }
    my_string& my_string::erase(size_t pos,size_t len)
    {
        if(len>_size-pos+1) len=_size-pos;
        memcpy(_str+pos,_str+pos+len,_size-pos-len);
        _size-=len;
        _str[_size]='\0';
        return *this;
    }


    //String operations
    const char* my_string::c_str() const
    {
        return _str;
    }
    size_t my_string::find(const char* s,size_t pos) const
    {
        size_t sz=strlen(s);
        for(size_t i=pos;i<=_size-sz;i++)
        {
            size_t j=0;
            for(;j<sz;j++)
                if(_str[i+j]!=s[j])
                    break;
            if(j==sz) return i;
        }
        return npos;
    }
    size_t my_string::find(const my_string& s,size_t pos) const
    {
        return find(s._str,pos);
    }
    size_t my_string::find(char c,size_t pos) const
    {
        for(size_t i=pos;i<_size;i++)
            if(_str[i]==c)
                return i;
        return npos;
    }
    my_string my_string::substr(size_t pos,size_t len) const
    {
        len=std::min(len,_size-pos);
        my_string res;
        for(size_t i=pos;i<=pos+len-1;i++)
            res+=_str[i];
        return res;
    }
    bool my_string::operator==(const char* s) const
    {
        return !strcmp(this->c_str(),s);
    }
    bool my_string::operator!=(const char* s) const
    {
        return !(*this==s);
    }
    bool my_string::operator>(const char* s) const
    {
        return strcmp(this->c_str(),s)>0;
    }
    bool my_string::operator<(const char* s) const
    {
        return strcmp(this->c_str(),s)<0;
    }
    bool my_string::operator>=(const char* s) const
    {
        return strcmp(this->c_str(),s)>=0;
    }
    bool my_string::operator<=(const char* s) const
    {
        return strcmp(this->c_str(),s)<=0;
    }
    bool my_string::operator==(const my_string& s) const
    {
        return *this==s.c_str();
    }
    bool my_string::operator!=(const my_string& s) const
    {
        return *this!=s.c_str();
    }
    bool my_string::operator>(const my_string& s) const
    {
        return *this>s.c_str();
    }
    bool my_string::operator<(const my_string& s) const
    {
        return *this<s.c_str();
    }
    bool my_string::operator>=(const my_string& s) const
    {
        return *this>=s.c_str();
    }
    bool my_string::operator<=(const my_string& s) const
    {
        return *this<=s.c_str();
    }


    //Non-member function overloads
    my_string operator+(const my_string& s1,const my_string& s2)
    {
        my_string res(s1);
        return res+=s2;
    }
    my_string operator+(const my_string& s1,const char* s2)
    {
        my_string res(s1);
        return res+=s2;
    }
    my_string operator+(const char* s1,const my_string& s2)
    {
        return s2+s1;
    }
    my_string operator+(const my_string& s,char c)
    {
        my_string res(s);
        return res+=c;
    }
    my_string operator+(char c,const my_string& s)
    {
        return s+c;
    }
    std::ostream& operator<<(std::ostream& out,const my_string& s)
    {
        out<<s.c_str();
        return out;
    }
    std::istream& operator>>(std::istream& in,my_string& s)
    {
        s.clear();
        char c=in.get();
        while(c==' '||c=='\n') c=in.get();
        while(c!=' '&&c!='\n')
        {
            s+=c;
            c=in.get();
        }
        return in;
    }
    void swap(my_string& s1,my_string& s2)
    {
        std::swap(s1._str,s2._str);
        std::swap(s1._size,s2._size);
        std::swap(s1._capacity,s2._capacity);
    }


}