/* Source.cpp

   основной модуль приложения.
   
*/

#include <windows.h>
#include <iostream>
#include <ctime>

#include "Source.h"
#include "SortAlgo.h"

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Ru");

	srand(time(NULL)); //генерируем при каждом запуске программы новые числа

	int choice = 0;
	show_menu();

	// адреса динамических массивов с экспериментальными данными для каждого из алгоритмов сортировки
	int * ARR_SORT_SHELL = NULL,
		* ARR_SORT_HOARE = NULL,
		* ARR_SORT_SHAKER = NULL,
		* ARR_SORT_PYRAMIDAL = NULL,
		* ARR_SORT_SELECTION = NULL,
		* ARR_SORT_MERGE = NULL,
		* ARR_SORT_COUNT = NULL ;

	int ARRSZ = 0 ; // размерность экспериментальной выборки

	while (choice != 3)
	{
		cout << "\nВаш выбор: ";
		do
		{
			char buf[10];
			scanf_s("%c", buf, 10);
			choice = atoi(buf);
		} while (!choice);

		switch (choice)
		{
		case 1:
		{
			cout << "Подготовка экспериментальных данных ...";

			cout << "\n\nзадайте размерность экспериментальной выборки : ";
			cin >> ARRSZ ;
			fflush(stdin); //очищаем все оставшиеся в буфере ввода символы, включая перевод строки

			if (ARRSZ <= 0) {
			cout << "недопустимое значение параметра" ;
			break ;
			}

			// поддержка множественной подготовки
			free_exp_arrays(ARR_SORT_SHELL, ARR_SORT_HOARE, ARR_SORT_SHAKER, ARR_SORT_PYRAMIDAL, ARR_SORT_SELECTION, ARR_SORT_MERGE, ARR_SORT_COUNT) ; // высвобождение динамической памяти

			if (!prepare_exp_arrays(ARRSZ, &ARR_SORT_SHELL, &ARR_SORT_HOARE, &ARR_SORT_SHAKER, &ARR_SORT_PYRAMIDAL, &ARR_SORT_SELECTION, &ARR_SORT_MERGE, &ARR_SORT_COUNT)) cout << endl << "подготовлены успешно!" << endl << endl;
			else {
			cout << endl << "ошибка подготовки." << endl;
			return 1;
			}

			break;
		}
		case 2:
		{
			if (ARR_SORT_SHELL == NULL	|| ARR_SORT_HOARE == NULL || ARR_SORT_SHAKER == NULL || ARR_SORT_PYRAMIDAL == NULL || ARR_SORT_SELECTION == NULL || ARR_SORT_MERGE == NULL || ARR_SORT_COUNT == NULL) {

			cout << endl << "требуется предварительная подготовка экспериментальных данных." ;

			break ;

			}

			clock_t start, finish; // отметки времени старта и завершения каждого теста

			double et1 = 0, et2 = 0, et3 = 0, et4 = 0, et5 = 0, et6= 0, et7 = 0; //время выполнения каждого теста в секундах

			cout << endl << "*** ТЕСТ СТАРТОВАЛ : " << endl << "*** АЛГОРИТМИЧЕСКИЙ ОБЪЕКТ ТЕСТИРОВАНИЯ : СОРТИРОВКА ШЕЛЛА";

			//out_exp_array(ARRSZ, ARR_SORT_SHELL);
			
			start=clock();
			SORT_SHELL(ARRSZ, ARR_SORT_SHELL);
			finish=clock();
			et1 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_SHELL);


			cout << endl << "*** ТЕСТ СТАРТОВАЛ : " << endl << "*** АЛГОРИТМИЧЕСКИЙ ОБЪЕКТ ТЕСТИРОВАНИЯ : СОРТИРОВКА ХОАРА";

			//out_exp_array(ARRSZ, ARR_SORT_HOARE);

			start=clock();
			SORT_HOARE(ARR_SORT_HOARE, 0, ARRSZ-1);
			finish=clock();
			et2 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_HOARE);
			
			cout << endl << "*** ТЕСТ СТАРТОВАЛ : " << endl << "*** АЛГОРИТМИЧЕСКИЙ ОБЪЕКТ ТЕСТИРОВАНИЯ : ШЕЙКЕРНАЯ СОРТИРОВКА";

			//out_exp_array(ARRSZ, ARR_SORT_SHAKER);

			start=clock();
			SORT_SHAKER(ARR_SORT_SHAKER, 1, ARRSZ);
			finish=clock();
			et3 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_SHAKER);

			
			cout << endl << "*** ТЕСТ СТАРТОВАЛ : " << endl << "*** АЛГОРИТМИЧЕСКИЙ ОБЪЕКТ ТЕСТИРОВАНИЯ : ПИРАМИДАЛЬНАЯ СОРТИРОВКА";

			//out_exp_array(ARRSZ, ARR_SORT_PYRAMIDAL);

			start=clock();
			SORT_PYRAMIDAL(ARRSZ, ARR_SORT_PYRAMIDAL);
			finish=clock();
			et4 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_PYRAMIDAL);


			cout << endl << "*** ТЕСТ СТАРТОВАЛ : " << endl << "*** АЛГОРИТМИЧЕСКИЙ ОБЪЕКТ ТЕСТИРОВАНИЯ : СОРТИРОВКА ВЫБОРОМ";

			//out_exp_array(ARRSZ, ARR_SORT_SELECTION);

			start=clock();
			SORT_SELECTION(ARRSZ, ARR_SORT_SELECTION);
			finish=clock();
			et5 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_SELECTION);

			
			cout << endl << "*** ТЕСТ СТАРТОВАЛ : " << endl << "*** АЛГОРИТМИЧЕСКИЙ ОБЪЕКТ ТЕСТИРОВАНИЯ : СОРТИРОВКА СЛИЯНИЕМ";

			//out_exp_array(ARRSZ, ARR_SORT_MERGE);

			start=clock();
			SORT_MERGE(ARRSZ, ARR_SORT_MERGE);
			finish=clock();
			et6 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_MERGE);

			
			cout << endl << "*** ТЕСТ СТАРТОВАЛ : " << endl << "*** АЛГОРИТМИЧЕСКИЙ ОБЪЕКТ ТЕСТИРОВАНИЯ : СОРТИРОВКА ПОДСЧЕТОМ";

			//out_exp_array(ARRSZ, ARR_SORT_COUNT);

			start=clock();
			SORT_COUNT(ARR_SORT_COUNT, ARRSZ, 0, 15999);
			finish=clock();
			et7 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_COUNT);
			
			// вывод результатов тестирования

			printf("\n\nРЕЗУЛЬТИРУЮЩИЙ СНИМОК ВРЕМЕНИ ВЫПОЛНЕНИЯ:\n");
			printf("\nСортировка массива из %u элементов заняла %.10f milliseconds.", ARRSZ, et1);
			printf("\nСортировка массива из %u элементов заняла %.10f milliseconds.", ARRSZ, et2);
			printf("\nСортировка массива из %u элементов заняла %.10f milliseconds.", ARRSZ, et3);
			printf("\nСортировка массива из %u элементов заняла %.10f milliseconds.", ARRSZ, et4);
			printf("\nСортировка массива из %u элементов заняла %.10f milliseconds.", ARRSZ, et5);
			printf("\nСортировка массива из %u элементов заняла %.10f milliseconds.", ARRSZ, et6);
			printf("\nСортировка массива из %u элементов заняла %.10f milliseconds.", ARRSZ, et7);

			break;

		}
		case 3:
		{
			cout << "Вы выбрали опцию завершение программы.";
			break;
		}
		default:
		{
			cout << "Недействительный ввод.";
			break;
		}

		} //switch

	} //while

	free_exp_arrays(ARR_SORT_SHELL, ARR_SORT_HOARE, ARR_SORT_SHAKER, ARR_SORT_PYRAMIDAL, ARR_SORT_SELECTION, ARR_SORT_MERGE, ARR_SORT_COUNT) ; // высвобождение динамической памяти

	return 0;
}

void show_menu()
{
	//функция выводит меню операций на консоль

	cout << "Выберите операцию: " << endl;
	cout << " 1 - Наполнение пула экспериментальных данных кодами отказов приложения (Win32 System Error Codes)" << endl;
	cout << " 2 - Стартовать тестовые прогоны для полного набора алгоритмов сортировки" << endl;
	cout << " 3 - выход" << endl;

}

int prepare_exp_arrays(int SZarr, int **arr1, int **arr2, int **arr3, int **arr4, int **arr5, int **arr6, int **arr7)
{
	/* функция подготавливает (размещает память и заполняет) тестовые массивы экспериментальных данных :
	   наполнение массивов производится множеством случайных значений из диапазона 0-15999 (Win32 System Error Codes),
	   все массивы наполняются одним сгенерированным набором,
       в качестве параметров принимает размерность требуемой экспериментальной выборки (первый параметр) и адреса указателей массивов,
       возвращает: 0 - успех выполнения, 1 - ошибка
*/

int result = 0 ; // успех

if (SZarr <= 0) {

	cout << endl << "значение параметра функции prepare_exp_buffets() вне допустимого диапазона." ;

	return 1 ;
}

*arr1 = new int [SZarr];
*arr2 = new int [SZarr];
*arr3 = new int [SZarr];
*arr4 = new int [SZarr];
*arr5 = new int [SZarr];
*arr6 = new int [SZarr];
*arr7 = new int [SZarr];

if (*arr1 == NULL ||
	*arr2 == NULL ||
	*arr3 == NULL ||
	*arr4 == NULL ||
	*arr5 == NULL ||
	*arr6 == NULL ||
	*arr7 == NULL)   {

	cout << endl << "ошибка выделения динамической памяти из кучи." ;

	return 1 ;
}

int arr_val = 0 ;

for (int i = 0; i < SZarr; i++) {

	arr_val = rand () % 16000; // диапазон от [0; 15999]

	(*arr1)[i] = arr_val ;
	(*arr2)[i] = arr_val ;
	(*arr3)[i] = arr_val ;
	(*arr4)[i] = arr_val ;
	(*arr5)[i] = arr_val ;
	(*arr6)[i] = arr_val ;
	(*arr7)[i] = arr_val ;

}

return result ;

}

void free_exp_arrays(int *arr1, int *arr2, int *arr3, int *arr4, int *arr5, int *arr6, int *arr7)
{
	/* функция производит удаление массивов экспериментальных данных - высвобождение памяти */

	delete [] arr1;
	delete [] arr2;
	delete [] arr3;
	delete [] arr4;
	delete [] arr5;
	delete [] arr6;
	delete [] arr7;

}

void out_exp_array (int SZarr, int * arr)
{
	/* функция осуществляет вывод содержимого массива на консоль,
	   в качестве параметров принимает размерность и адреса массива

	*/

	cout << endl;
	for (int i=0; i<SZarr; i++) cout << arr[i] << " ";
	cout << endl;

}
