#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

class String
{
friend class CharProxy;
public:
class CharProxy{

    public:
        CharProxy(String * pstr, size_t idx) :_ps(pstr), _idx(idx){}

        CharProxy& operator=(const CharProxy&rhs)
        {
            //cout<<"CharProxy& operator=(const CharProxy&rhs)//"<<endl;
            (_ps->_pstr)[_idx]=((rhs._ps)->_pstr)[rhs._idx];
            return *this;
        }
        CharProxy& operator=(char ch)
        {
            cout<<"CharProxy& operator=(char ch)"<<endl;
            
            if (_idx < (*_ps).size())
            {
                if ((*_ps).getRefcount() > 1)
                {
                char *ptmp = new char[(*_ps).size() + 5]() + 4;
                strcpy(ptmp, (*_ps)._pstr);
                (*_ps).decreaseRefcount();
                (*_ps)._pstr = ptmp;
                (*_ps).initRefcount();
                }
                (_ps->_pstr)[_idx]=ch;
            }

            return *this;
        }
        operator char()const
        {
            cout<<"operator char()const//Read"<<endl;
            return (_ps->_pstr)[_idx];
        }
    private:
        String *_ps;
        size_t _idx;
    };
public:
    String()
    :_pstr(new char[5]() + 4)
    {
        cout <<"String()" << endl;
        initRefcount();
    }
    String(const char *pstr)
    :_pstr(new char[strlen(pstr) + 5]() + 4)
    {
        cout <<"String(const char *)" << endl;
        strcpy(_pstr, pstr);
        initRefcount();
    }

    String(const String &rhs)
    :_pstr(rhs._pstr)
    {
        cout <<"String(const String &)" << endl;
        increaseRefcount();
    }
    String &operator=(const String &rhs)
    {
        cout << "String &operator=(const String &)" <<endl;
        if (this != &rhs)
        {
            release();
            _pstr = rhs._pstr;
            increaseRefcount();
        }

        return *this;
    }
    ~String()
    {
        cout << "~String()" << endl;
        release();
    }
#if 0
    char &operator[](size_t idx)
    {
        cout<<"char &operator[](size_t idx)"<<endl;
        if (idx < size())
        {
            if (getRefcount() > 1)
            {
                char *ptmp = new char[size() + 5]() + 4;
                strcpy(ptmp, _pstr);
                decreaseRefcount();
                _pstr = ptmp;
                initRefcount();

            }
            return _pstr[idx];
        }
        else
        {
            static char nullchar = '\0';
            return nullchar;
        }
        
    }
#endif
public:
    const char &operator[](size_t idx) const
    {
        cout<<"const char &operator[](size_t idx) const"<<endl;
        if (idx < size())
        {
            return _pstr[idx];
        }
        else
        {
            static char nullchar = '\0';
            return nullchar;
        }
    }
    CharProxy operator[](size_t idx)
    {
        //cout<<"CharProxy operator[](size_t idx)"<<endl;
        return CharProxy(this,idx);
    }



public:
    int getRefcount() const
    {
        return *(int *)(_pstr - 4);
    }

    const char *c_str() const
    {
        return _pstr;
    }

    size_t size() const
    {
        return strlen(_pstr);
    }
private:
    void initRefcount()
    {
        *(int *)(_pstr - 4) = 1;
    }

    void increaseRefcount()
    {
        ++*(int *)(_pstr - 4);
    }

    void decreaseRefcount()
    {
        --*(int *)(_pstr - 4);
    }

    void release()
    {
        decreaseRefcount();
        if (getRefcount() == 0)
        {
            delete [] (_pstr - 4);
            cout << ">>>delete heap data" << endl;
        }

    }

    friend std::ostream &operator<<(std::ostream &os, const String &rhs);
private:
    char *_pstr;
};

std::ostream &operator<<(std::ostream &os, const String &rhs)
{
    os << rhs._pstr;
    return os;
}
void test()
{
    String s1("hello");
    String s2 = s1;

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    cout << "s1's refcount = " << s1.getRefcount() << endl;
    cout << "s2's refcount = " << s2.getRefcount() << endl;
    
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());

    cout << endl;
    String s3 = "world";
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    cout << "s1's refcount = " << s1.getRefcount() << endl;
    cout << "s2's refcount = " << s2.getRefcount() << endl;
    cout << "s3's refcount = " << s3.getRefcount() << endl;
    
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

    cout << endl;
    s3 = s1;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    cout << "s1's refcount = " << s1.getRefcount() << endl;
    cout << "s2's refcount = " << s2.getRefcount() << endl;
    cout << "s3's refcount = " << s3.getRefcount() << endl;
    
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

    cout << endl;
    cout << "修改s3[0] = 'H'之后 :" << endl;
    s3[0] = 'H';
    cout << "s3[0] = " << s3[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    cout << "s1's refcount = " << s1.getRefcount() << endl;
    cout << "s2's refcount = " << s2.getRefcount() << endl;
    cout << "s3's refcount = " << s3.getRefcount() << endl;
    
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

    cout << endl;
    cout << "对s1[0] 执行读操作之后 :" << endl;
    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    cout << "s1's refcount = " << s1.getRefcount() << endl;
    cout << "s2's refcount = " << s2.getRefcount() << endl;
    cout << "s3's refcount = " << s3.getRefcount() << endl;
    
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

}
int main(void)
{
    test();
    return 0;
}

