/*	In the case of using an one-dimensional array you enter data by hand
	In the case of using a two-dimensional array you enter only the place for adding rows or columns being filled with random values */

#include "header.h"
#include "header.cpp"

int main()
{
	setlocale(0, "");
	int* int_array = nullptr;
	double* double_array = nullptr;
	char* char_array = nullptr;
	int** int_array_2 = nullptr;
	double** double_array_2 = nullptr;
	char** char_array_2 = nullptr;
	int size{ 0 }, rows{ 0 }, cols{ 0 };
	int key{ 0 };

	cout << "\n Choose datatype: 1 - int  2 - double  3 - char  "; key = (int)_getch() - 48;
	cout << "\n 1 - One-dimensional array   2 - Two-dimensional array"; ((int)_getch() - 48 == 1) ? key : key += 3;
	switch (key)
	{
	case 1: while ((key = _call_menu(int_array, size)) != 27) { int_array = _operation(int_array, size, key); }				delete[]int_array;				break;
	case 2: while ((key = _call_menu(double_array, size)) != 27) { double_array = _operation(double_array, size, key); }			delete[]double_array;			break;
	case 3: while ((key = _call_menu(char_array, size)) != 27) { char_array = _operation(char_array, size, key); }				delete[]char_array;				break;
	case 4: while ((key = _call_menu(int_array_2, rows, cols)) != 27) { int_array_2 = _operation(int_array_2, size, key); }			_delete(int_array_2, rows);	break;
	case 5: while ((key = _call_menu(double_array_2, rows, cols)) != 27) { double_array_2 = _operation(double_array_2, size, key); }		_delete(double_array_2, rows);	break;
	case 6: while ((key = _call_menu(char_array_2, rows, cols)) != 27) { char_array_2 = _operation(char_array_2, size, key); }			_delete(char_array_2, rows);	break;
	default: break;
	}
	return 0;
}