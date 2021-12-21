#ifndef __VECTOR_H_INCLUDED__
#define __VECTOR_H_INCLUDED__
#define __TRACE__

#include <vector>
#include <iostream>

#include "Trace.h"

using std::cout;
using std::endl;

template <class T>
class vector
{
public:
    std::vector<T> vec;

    vector(int size)
        : vec(size)
    {
        TRACE(dummy, "vector<T>::vector(int)");
        cout << "   count = 1" << endl;
    }

    ~vector()
    {
        TRACE(dummy, "vector<T>::~vector");
        cout << "   count = 1" << endl;
    }

    T &operator[](int i)
    {
        return vec[i];
    }
};

template <>
class vector<void *>
{
public:
    std::vector<void *> vec;
    static int count;

    vector(int size)
        : vec(size)
    {
        TRACE(dummy, "vector<void*>::vector(int)");
        cout << "   count = " << ++count << endl;
    }

    ~vector()
    {
        TRACE(dummy, "vector<void*>::~vector");
        cout << "   count = " << count-- << endl;
    }
};

template <typename T>
class vector<T *> : private vector<void *>
{
public:
    std::vector<T *> vec;
    typedef vector<void *> base;

    vector(int size)
        : base(size), vec(size)
    {
        TRACE(dummy, "vector<T*>::vector(int)");
    }

    ~vector()
    {
        TRACE(dummy, "vector<T*>::~vector");
    }

    T *&operator[](int i)
    {
        return vec[i];
    }

    T *&elem(int i)
    {
        return vec[i];
    }
};

#endif
