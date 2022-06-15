#pragma once
#include <iostream>
#include <conio.h>
#define _MSG " Now your _array is -> "
#define OPER_LIST "\n Choose an operation:\n 1. Push_back\n 2. Push_front\n 3. Insert\n 4. Pop_back\n 5. Pop_front\n 6. Erase\n ESC to quit ";

using namespace std;

/*----------------one-dimensional array----------------------*/
template<typename T> void _print_array(const T*, const int&, const char*);
template<typename T> T* push_back(T*, T&, int&);
template<typename T> T* push_front(T*, T&, int&);
template<typename T> T* insert(T*, T&, int, int&);
template<typename T> T* erase(T*, int, int&);
template<typename T> T* pop_back(T*, int&);
template<typename T> T* pop_front(T*, int&);
template<typename T> int _call_menu(T*, const int&);
template<typename T> T* _operation(T*, int& size, int&);
/*----------------two-dimensional array----------------------*/
template<typename T> void _print_array(T**, const int&, const int&, const char*);
template<typename T> T** push_back(T**, int&, int&, bool);
template<typename T> T** push_front(T**, int&, int&, bool);
template<typename T> T** insert(T**, int&, int&, bool, int&);
template<typename T> T** erase(T**, int& rows, int& cols, bool, int);
template<typename T> T** pop_back(T**, int&, int&, bool);
template<typename T> T** pop_front(T**, int&, int&, bool);
template<typename T> int _call_menu(T**, const int&, const int&);
template<typename T> T** _operation(T**, int&, int&, int&);
template<typename T> void _delete(T**, int& rows);