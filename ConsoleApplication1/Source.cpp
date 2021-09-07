/* Source.cpp

   �������� ������ ����������.
   
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

	srand(time(NULL)); //���������� ��� ������ ������� ��������� ����� �����

	int choice = 0;
	show_menu();

	// ������ ������������ �������� � ������������������ ������� ��� ������� �� ���������� ����������
	int * ARR_SORT_SHELL = NULL,
		* ARR_SORT_HOARE = NULL,
		* ARR_SORT_SHAKER = NULL,
		* ARR_SORT_PYRAMIDAL = NULL,
		* ARR_SORT_SELECTION = NULL,
		* ARR_SORT_MERGE = NULL,
		* ARR_SORT_COUNT = NULL ;

	int ARRSZ = 0 ; // ����������� ����������������� �������

	while (choice != 3)
	{
		cout << "\n��� �����: ";
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
			cout << "���������� ����������������� ������ ...";

			cout << "\n\n������� ����������� ����������������� ������� : ";
			cin >> ARRSZ ;
			fflush(stdin); //������� ��� ���������� � ������ ����� �������, ������� ������� ������

			if (ARRSZ <= 0) {
			cout << "������������ �������� ���������" ;
			break ;
			}

			// ��������� ������������� ����������
			free_exp_arrays(ARR_SORT_SHELL, ARR_SORT_HOARE, ARR_SORT_SHAKER, ARR_SORT_PYRAMIDAL, ARR_SORT_SELECTION, ARR_SORT_MERGE, ARR_SORT_COUNT) ; // ������������� ������������ ������

			if (!prepare_exp_arrays(ARRSZ, &ARR_SORT_SHELL, &ARR_SORT_HOARE, &ARR_SORT_SHAKER, &ARR_SORT_PYRAMIDAL, &ARR_SORT_SELECTION, &ARR_SORT_MERGE, &ARR_SORT_COUNT)) cout << endl << "������������ �������!" << endl << endl;
			else {
			cout << endl << "������ ����������." << endl;
			return 1;
			}

			break;
		}
		case 2:
		{
			if (ARR_SORT_SHELL == NULL	|| ARR_SORT_HOARE == NULL || ARR_SORT_SHAKER == NULL || ARR_SORT_PYRAMIDAL == NULL || ARR_SORT_SELECTION == NULL || ARR_SORT_MERGE == NULL || ARR_SORT_COUNT == NULL) {

			cout << endl << "��������� ��������������� ���������� ����������������� ������." ;

			break ;

			}

			clock_t start, finish; // ������� ������� ������ � ���������� ������� �����

			double et1 = 0, et2 = 0, et3 = 0, et4 = 0, et5 = 0, et6= 0, et7 = 0; //����� ���������� ������� ����� � ��������

			cout << endl << "*** ���� ��������� : " << endl << "*** ��������������� ������ ������������ : ���������� �����";

			//out_exp_array(ARRSZ, ARR_SORT_SHELL);
			
			start=clock();
			SORT_SHELL(ARRSZ, ARR_SORT_SHELL);
			finish=clock();
			et1 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_SHELL);


			cout << endl << "*** ���� ��������� : " << endl << "*** ��������������� ������ ������������ : ���������� �����";

			//out_exp_array(ARRSZ, ARR_SORT_HOARE);

			start=clock();
			SORT_HOARE(ARR_SORT_HOARE, 0, ARRSZ-1);
			finish=clock();
			et2 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_HOARE);
			
			cout << endl << "*** ���� ��������� : " << endl << "*** ��������������� ������ ������������ : ��������� ����������";

			//out_exp_array(ARRSZ, ARR_SORT_SHAKER);

			start=clock();
			SORT_SHAKER(ARR_SORT_SHAKER, 1, ARRSZ);
			finish=clock();
			et3 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_SHAKER);

			
			cout << endl << "*** ���� ��������� : " << endl << "*** ��������������� ������ ������������ : ������������� ����������";

			//out_exp_array(ARRSZ, ARR_SORT_PYRAMIDAL);

			start=clock();
			SORT_PYRAMIDAL(ARRSZ, ARR_SORT_PYRAMIDAL);
			finish=clock();
			et4 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_PYRAMIDAL);


			cout << endl << "*** ���� ��������� : " << endl << "*** ��������������� ������ ������������ : ���������� �������";

			//out_exp_array(ARRSZ, ARR_SORT_SELECTION);

			start=clock();
			SORT_SELECTION(ARRSZ, ARR_SORT_SELECTION);
			finish=clock();
			et5 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_SELECTION);

			
			cout << endl << "*** ���� ��������� : " << endl << "*** ��������������� ������ ������������ : ���������� ��������";

			//out_exp_array(ARRSZ, ARR_SORT_MERGE);

			start=clock();
			SORT_MERGE(ARRSZ, ARR_SORT_MERGE);
			finish=clock();
			et6 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_MERGE);

			
			cout << endl << "*** ���� ��������� : " << endl << "*** ��������������� ������ ������������ : ���������� ���������";

			//out_exp_array(ARRSZ, ARR_SORT_COUNT);

			start=clock();
			SORT_COUNT(ARR_SORT_COUNT, ARRSZ, 0, 15999);
			finish=clock();
			et7 = (double) (finish - start) / CLOCKS_PER_SEC;

			//out_exp_array(ARRSZ, ARR_SORT_COUNT);
			
			// ����� ����������� ������������

			printf("\n\n�������������� ������ ������� ����������:\n");
			printf("\n���������� ������� �� %u ��������� ������ %.10f milliseconds.", ARRSZ, et1);
			printf("\n���������� ������� �� %u ��������� ������ %.10f milliseconds.", ARRSZ, et2);
			printf("\n���������� ������� �� %u ��������� ������ %.10f milliseconds.", ARRSZ, et3);
			printf("\n���������� ������� �� %u ��������� ������ %.10f milliseconds.", ARRSZ, et4);
			printf("\n���������� ������� �� %u ��������� ������ %.10f milliseconds.", ARRSZ, et5);
			printf("\n���������� ������� �� %u ��������� ������ %.10f milliseconds.", ARRSZ, et6);
			printf("\n���������� ������� �� %u ��������� ������ %.10f milliseconds.", ARRSZ, et7);

			break;

		}
		case 3:
		{
			cout << "�� ������� ����� ���������� ���������.";
			break;
		}
		default:
		{
			cout << "���������������� ����.";
			break;
		}

		} //switch

	} //while

	free_exp_arrays(ARR_SORT_SHELL, ARR_SORT_HOARE, ARR_SORT_SHAKER, ARR_SORT_PYRAMIDAL, ARR_SORT_SELECTION, ARR_SORT_MERGE, ARR_SORT_COUNT) ; // ������������� ������������ ������

	return 0;
}

void show_menu()
{
	//������� ������� ���� �������� �� �������

	cout << "�������� ��������: " << endl;
	cout << " 1 - ���������� ���� ����������������� ������ ������ ������� ���������� (Win32 System Error Codes)" << endl;
	cout << " 2 - ���������� �������� ������� ��� ������� ������ ���������� ����������" << endl;
	cout << " 3 - �����" << endl;

}

int prepare_exp_arrays(int SZarr, int **arr1, int **arr2, int **arr3, int **arr4, int **arr5, int **arr6, int **arr7)
{
	/* ������� �������������� (��������� ������ � ���������) �������� ������� ����������������� ������ :
	   ���������� �������� ������������ ���������� ��������� �������� �� ��������� 0-15999 (Win32 System Error Codes),
	   ��� ������� ����������� ����� ��������������� �������,
       � �������� ���������� ��������� ����������� ��������� ����������������� ������� (������ ��������) � ������ ���������� ��������,
       ����������: 0 - ����� ����������, 1 - ������
*/

int result = 0 ; // �����

if (SZarr <= 0) {

	cout << endl << "�������� ��������� ������� prepare_exp_buffets() ��� ����������� ���������." ;

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

	cout << endl << "������ ��������� ������������ ������ �� ����." ;

	return 1 ;
}

int arr_val = 0 ;

for (int i = 0; i < SZarr; i++) {

	arr_val = rand () % 16000; // �������� �� [0; 15999]

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
	/* ������� ���������� �������� �������� ����������������� ������ - ������������� ������ */

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
	/* ������� ������������ ����� ����������� ������� �� �������,
	   � �������� ���������� ��������� ����������� � ������ �������

	*/

	cout << endl;
	for (int i=0; i<SZarr; i++) cout << arr[i] << " ";
	cout << endl;

}
