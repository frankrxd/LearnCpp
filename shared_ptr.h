#ifndef __SHARED_PTR_
#define __SHARED_PTR_

template<class T>
class shared_ptr {
    shared_ptr(T *p):_refcount(new int(1))
                    ,_ptr(p){}
    shared_ptr(shared_ptr<T>& other)
            :_refcount(other._refcount)
            ,_ptr(other._ptr){}
    T* operator->() {
        return _ptr;
    }
    T& operator*() {
        return *_ptr;
    }
    shared_ptr<T>& operator=(shared_ptr<T> &other){
        ++other._refcount;
        if(_ptr&&0==--_refcount) {
            delete _refcount;
            delete _ptr;
        }
        _refcount = other._refcount;
        _ptr = other._ptr;
    }
    ~shared_ptr() {
        if(--_refcount == 0){
            delete _refcount;
            delete _ptr;
        }
    }
    int getRef() {
        return _refcount;
    }


private:
    int* _refcount;
    T* _ptr;
};



#endif