#include<iostream>
using namespace std;

//void FillRand(int** arr)
#define tab "\t"
void Allocate(int** arr, const int m, const int n);

void FillRand(int** arr, const int m, const int n);
void Print(int** arr, const int m, const int n);

void push_row_back(int**& arr, int& m, const int n);
void push_row_front(int**& arr, int& m, const int n);
void insert_row(int**& arr, int& m, const int n, int value);

void pop_row_back(int**& arr, int& m, int n);
void pop_row_front(int**& arr, int& m, int n);
void erase_row(int**& arr, int& m, int n, int value);

void push_col_back(int**& arr, int m, int& n);
void push_col_front(int**& arr, int m, int& n);
void insert_col(int**& arr, int m, int& n, int value);

void pop_col_back(int**& arr, int m, int& n);
void pop_col_front(int**& arr, int m, int& n);
void erase_col(int**& arr, int m, int& n, int value);

void Delete(int** arr, const int m, const int n);
#define ROWS
#define COLS

void rows(int** arr, int m, int n, int value)
{	
#ifdef ROWS
	int key1 = 0;
	do
	{
	cout << "\n Вставить  последнюю строку: - 1 \n";
	cout << " Вставить   первую   строку: - 2 \n";
	cout << " Вставить строку по индексу: - 3 \n";
	cout << " Удалить  последнюю  строку: - 4 \n";
	cout << " Удалить    первую   строку: - 5 \n";
	cout << " Удалить  строку по индексу: - 6 \n";
	cout << " Выход  предидущее  в  меню: - 0 \n";
	cin >> key1;
	system("cls");
	switch (key1)
	{
	case 1:
		push_row_back(arr, m, n);
		cout << "\n   *push_row_back* \n"; Print(arr, m, n);
		break;
	case 2:
		push_row_front(arr, m, n);
		cout << "\n   *push_row_front* \n"; Print(arr, m, n);
		break;
	case 3:
		cout << "\n Выберите номер строки для вставки от 0 до " << m << " - ";
		cin >> value;
		insert_row(arr, m, n, value);
		cout << "\n  *    insert    * \n"; Print(arr, m, n);
		break;
	case 4:
		pop_row_back(arr, m, n);
		cout << "\n  * pop_row_back * \n"; Print(arr, m, n);
		break;
	case 5:
		pop_row_front(arr, m, n);
		cout << "\n  * pop_row_front * \n"; Print(arr, m, n);
		break;
	case 6:
		cout << "\n Выберите номер строки для удаления от 0 до " << m - 1 << " - ";
		cin >> value;
		erase_row(arr, m, n, value);
		cout << "\n  *   erase_row   * \n"; Print(arr, m, n);
		break;
	}
	} while (key1 > 0 && key1 < 7);
	Delete(arr, m, n);
#endif 
}
void cols(int** arr, int m, int n, int value)
{
#ifdef COLS
	int key2 = 0;
	do
	{
		cout << "\n Вставить  последнюю колонну: - 1 \n";
		cout << " Вставить   первую   колонну: - 2 \n";
		cout << " Вставить колонну по индексу: - 3 \n";
		cout << " Удалить  последнюю  колонну: - 4 \n";
		cout << " Удалить    первую   колонну: - 5 \n";
		cout << " Удалить  колонну по индексу: - 6 \n";
		cout << " Выход   предидущее  в  меню: - 0 \n";
		cin >> key2;
		system("cls");
		switch (key2)
		{
		case 1:
			push_col_back(arr, m, n);
			cout << "*\n  push_col_back * \n"; Print(arr, m, n);
			break;
		case 2:
			push_col_front(arr, m, n);
			cout << "*\n push_col_front * \n"; Print(arr, m, n);
			break;
		case 3:
			cout << "\n Выберите номер колонны для вставки от 0 до " << n << " - ";
			cin >> value;
			insert_col(arr, m, n, value);
			cout << "*\n   insert_col   * \n"; Print(arr, m, n);
			break;
		case 4:
			pop_col_back(arr, m, n);
			cout << "*\n   pop_col_back   * \n"; Print(arr, m, n);
			break;
		case 5:
			pop_col_front(arr, m, n);
			cout << "*\n   pop_col_front   * \n"; Print(arr, m, n);
			break;
		case 6:
			cout << "\n Выберите номер колонны для удаления от 0 до " << n << " - ";
			cin >> value;
			erase_col(arr, m, n, value);
			cout << "*\n   erase_col   * \n"; Print(arr, m, n);
			break;
		}
	} while (key2 > 0 && key2 < 7);
Delete(arr, m, n);
#endif  COLS
}


void main()
{
	setlocale(LC_ALL, "Rus");
	int value = 0; 
	int key = 0;
	int m = 5; //Количество строк
	int n = 5; //Количество столбцов
	cout << " Задаём размер массива для работы. \n"; 
	/*cout << " Введите количество строк: - "; cin >> m;
	cout << "\n Введите количество элементов строки: "; cin >> n;*/



	do
	{
	int** arr = new int* [m] {};    //1) Создаём массив указателей:
	Allocate(arr, m, n);
	FillRand(arr, m, n);
	cout << " Начальный массив \n"; Print(arr, m, n);
	cout << " Работаем со строками: - 1\n Работаем с колонками: - 2 \n Выход : - 0 "; cin >> key;
		switch (key)
		{
		case 1:
			rows(arr, m, n, value);
			break;
		case 2:
			cols(arr, m, n, value);
			break;
		}
	} while (key > 0 && key < 3);


	
	cout << "\n\n Hello WORLD!(:-) \n\n";
}

void Allocate(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)     //2) Выделяем память под строки двумерного массива:
		arr[i] = new int[n] {};
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int** arr, const int m, const int n)
{
	cout << "+++++++++++++++++++++++++++++++++++\n\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
	cout << "+++++++++++++++++++++++++++++++++++\n";
}

void push_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m + 1] {};    //1) Создаём буферный массив указателей:	
	for (int i = 0; i < m; i++)
	{		
			buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[m] = new int[n] {};
	m++;
}
void push_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [m + 1]{};    //1) Создаём буферный массив указателей:	
	for (int i = 0; i < m; i++)
	{	
			buffer[i + 1] = arr[i];		
	}	
	delete[] arr;
	arr = buffer;
	arr[0] = new int[n] {};
	m++;
}
void insert_row(int**& arr, int& m, const int n, int value)
{
	int** buffer = new int* [++m]{};    //1) Создаём буферный массив указателей:
	for (int i = 0; i < m - 1; i++)
	{	
			if (i >= value)
			buffer[i + 1] = arr[i];
			else
			buffer[i] = arr[i];		
	}
	delete[] arr;
	arr = buffer;
	arr[value] = new int [n] {};
}

void pop_row_back(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m] {};	
	for (int i = 0; i < m; i++)
	{		
			buffer[i] = arr[i];	
	}	
	arr = buffer;		
}
void pop_row_front(int**& arr, int& m, const int n)
{
	int** buffer = new int* [--m]{};	
	for (int i = 0; i < m; i++)
	{
			buffer[i] = arr[i + 1];
	}	
	delete[] arr;
	arr = buffer;	
}
void erase_row(int**& arr, int& m, const int n, int value)
{
	int** buffer = new int* [--m]{};
	for (int i = 0; i < m; i++)
	{		
			if (i >= value)		
			buffer[i] = arr[i +1];			
			else
			buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
}

void push_col_back(int**& arr, int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1] {};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}	
	n++;
}
void push_col_front(int**& arr, int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1] {};
		for (int j = 0; j < n; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
void insert_col(int**& arr, int m, int& n, int value)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n + 1] {};
		for (int j = 0; j < n + 1; j++)
		{
			if (j >= value)
			buffer[j +1] = arr[i][j];
			else
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}

void pop_col_back(int**& arr, const int m, int& n)
{	
	
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n - 1] {};
		for (int j = 0; j < n - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
	arr[i] = buffer;
	}
	n--;
}
void pop_col_front(int**& arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n - 1] {};
		for (int j = 0; j < n - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}
void erase_col(int**& arr, const int m, int& n, int value)
{
	for (int i = 0; i < m; i++)
	{
		int* buffer = new int[n - 1] {};
		for (int j = 0; j < n - 1; j++)
		{
			if(j >= value)
			buffer[j] = arr[i][j + 1];
			else
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}

void Delete(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	//2)Удаляем массив указателей:
	delete[] arr;
}