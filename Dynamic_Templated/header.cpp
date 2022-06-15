#pragma once
#include "Header.h"

/*----------------one-dimensional array----------------------*/

template<typename T>
void _print_array(const T* _array, const int& size, const char* _string = "")
{
	cout << "\n " << _string;
	if (size == 0) cout << "empty";
	else
		for (int i = 0; i < size; ++i)
			cout << _array[i] << "  ";
}

template<typename T>
T* push_back(T* _array, T& value, int& size)
{
	return insert(_array, value, size, size);
}

template<typename T>
T* push_front(T* _array, T& value, int& size)
{
	return	insert(_array, value, 0, size);
}

template<typename T>
T* insert(T* _array, T& value, int position, int& size)
{
	if (position <= size)
	{
		T* temp = new T[++size];
		for (int i = 0; i < position; ++i)
		{
			temp[i] = _array[i];
		}
		temp[position] = value;
		for (int i = position + 1; i < size; ++i)
		{
			temp[i] = _array[i - 1];
		}
		delete[]_array;
		return temp;
	}
	else return _array;
}

template<typename T>
T* erase(T* _array, int position, int& size)
{
	if ((size != 0) && (position < size))
	{
		T* temp = new T[--size];
		for (int i = 0; i < position; i++)
		{
			temp[i] = _array[i];
		}
		for (int i = position; i < size; i++)
		{
			temp[i] = _array[i + 1];
		}
		delete[]_array;
		_array = temp;
	}
	return _array;
}

template<typename T>
T* pop_back(T* _array, int& size)
{
	return erase(_array, size - 1, size);
}

template<typename T>
T* pop_front(T* _array, int& size)
{
	return erase(_array, 0, size);
}

template<typename T>
int _call_menu(T* _array, const int& size)
{
	system("cls");
	_print_array(_array, size, _MSG);
	cout << OPER_LIST;
	return _getch();
}

template<typename T>
T* _operation(T* _array, int& size, int& key)
{
	T value = 0;
	int position = 0;
	switch (key)
	{
	case '1':
	{
		cout << "\n Enter a value to push back -> "; cin >> value;
		_array = push_back(_array, value, size);
		break;
	}
	case '2':
	{
		cout << "\n Enter a value to push front -> "; cin >> value;
		_array = push_front(_array, value, size);
		break;
	}
	case '3':
	{
		cout << "\n Enter a value to insert -> "; cin >> value;
		cout << "\n Enter a position -> "; cin >> position;
		_array = insert(_array, value, position, size);
		break;
	}
	case '4':
	{
		_array = pop_back(_array, size);
		break;
	}
	case '5':
	{
		_array = pop_front(_array, size);
		break;
	}
	case '6':
	{
		cout << "\n Enter a position -> "; cin >> position;
		_array = erase(_array, position, size);
		break;
	}
	case 27:
		break;
	default:
	{
		cout << "\n Unknows operation. Re-choose..." << endl;
		break;
	}
	}
	return _array;
}

/*----------------two-dimensional array----------------------*/

template<typename T>
void _print_array(T** _array, const int& rows, const int& cols, const char*)
{
	cout << _MSG;
	if (rows == 0) cout << " empty ";
	else
		for (int i = 0; i < rows; i++)
			_print_array(_array[i], cols);
}

template<typename T>
T** push_back(T** _array, int& rows, int& cols, bool _add_rows)
{
	return insert(_array, rows, cols, _add_rows, _add_rows ? rows : cols);
}

template<typename T>
T** push_front(T** _array, int& rows, int& cols, bool _add_rows)
{
	return insert(_array, rows, cols, _add_rows, 0);
}

template<typename T>
T** insert(T** _array, int& rows, int& cols, bool _add_rows, int& _where_to_add)
{
	if (_add_rows) {
		T** _temp = new T * [++rows];
		for (int i = 0; i < cols; i++) {
			if (i == _where_to_add) continue;
			_temp[i] = array[i];
		}
		for (int i = 0; i < cols; i++) {
			_temp[_where_to_add][i] = srand(time(NULL));
		}
		_delete(_array, rows - 1);
		_array = _temp;
	}
	else {
		for (int i = 0; i < rows; i++) {
			_array[i] = insert(_array[i], srand(time(NULL)), _where_to_add, cols);
			--cols;
		}
		++cols;
	}
	return _array;
}

template<typename T>
T** erase(T** _array, int& rows, int& cols, bool _delete_rows, int _from_where_to_delete)
{
	if (_delete_rows) {
		T** _temp = new T * [--rows];
		for (int i = 0; i < cols; i++) {
			if (i == _from_where_to_delete) continue;
			_temp[i] = array[i];
		}
		_delete(_array, rows + 1);
		_array = _temp;
	}
	else
	{
		for (int i = 0; i < rows; i++) {
			_array[i] = erase(_array[i], _from_where_to_delete, cols);
			++cols;
		}
		--cols;
	}
	return _array;
}

template<typename T>
T** pop_back(T** _array, int& rows, int& cols, bool _delete_rows)
{
	return erase(_array, rows, cols, _delete_rows, _delete_rows ? rows : cols);
}

template<typename T>
T** pop_front(T** _array, int& rows, int& cols, bool _delete_rows)
{
	return erase(_array, rows, cols, _delete_rows, 0);
}

template<typename T>
int _call_menu(T** _array, const int& rows, const int& cols)
{
	system("cls");
	_print_array(_array, rows, cols, _MSG);
	cout << OPER_LIST;
	return _getch();
}

template<typename T>
T** _operation(T** _array, int& rows, int& cols, int& key)
{
	int position = 0;
	bool _work_with_rows = true;
	switch (key)
	{
	case '1':
	{
		cout << "\n Push back: Rows - 1  Cols - 0  "; cin >> _work_with_rows;
		_array = push_back(_array, rows, cols, _work_with_rows);
		break;
	}
	case '2':
	{
		cout << "\n Push front: Rows - 1  Cols - 0  "; cin >> _work_with_rows;
		_array = push_front(_array, rows, cols, _work_with_rows);
		break;
	}
	case '3':
	{
		cout << "\n Insert: Rows - 1  Cols - 0  "; cin >> _work_with_rows;
		cout << "\n Enter a position -> "; cin >> position;
		_array = insert(_array, rows, cols, _work_with_rows, position);
		break;
	}
	case '4':
	{
		cout << "\n Pop back: Rows - 1  Cols - 0"; cin >> _work_with_rows;
		_array = pop_back(_array, rows, cols, _work_with_rows);
		break;
	}
	case '5':
	{
		cout << "\n Pop front: Rows - 1  Cols - 0"; cin >> _work_with_rows;
		_array = pop_front(_array, rows, cols, _work_with_rows);
		break;
	}
	case '6':
	{
		cout << "\n Erase: Rows - 1  Cols - 0"; cin >> _work_with_rows;
		cout << "\n Choose " << (_work_with_rows == true ? "rows" : "columns") << " -> "; cin >> position;
		_array = erase(_array, rows, cols, _work_with_rows, position);
		break;
	}
	case 27:
		break;
	default:
	{
		cout << "\n Unknows operation. Re-choose..." << endl;
		break;
	}
	}
	return _array;
}

template<typename T>
void _delete(T** _array, int& rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]_array[i];
	}
}