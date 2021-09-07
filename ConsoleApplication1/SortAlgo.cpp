
/* SortAlgo.cpp

   Интерфейс набора алгоритмов сортировки массивов целочисленных данных.
   
*/

#include <memory.h>
#include "SortAlgo.h"

void SORT_SHELL (int SZarr, int * arr)
{
	/* Функция реализует сортировку массива целочисленных значений методом Шелла,
	   первым параметром принимает размерность массива, вторым - адрес массива.
	   */
    for(int s=SZarr/2; s>0; s/=2) 
	{

			for(int i=0; i<SZarr; i++) 
			{

					for(int j=i+s; j<SZarr; j+=s) 
					{
						if(arr[i] > arr[j])
						{
							int temp = arr[j];
							arr[j] = arr[i];
							arr[i] = temp;
						}
					}

			}

    }
}

void SORT_HOARE (int* arr, int first, int last)
{
	/* Функция реализует сортировку массива целочисленных значений методом Хоара,
	   первым параметром принимает адрес массива, вторым и третьим - индекс первого 
	   и последнего элементов.
	   */

    int i = first, j = last, x = arr[(first + last) / 2];
  
    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
  
        if(i <= j) {
            if (arr[i] > arr[j]) 
				{
					int tmp = 0;
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j]=tmp; 
			    }
            i++;
            j--;
        }
    } while (i <= j);
  
    if (i < last) SORT_HOARE(arr, i, last);
    if (first < j) SORT_HOARE(arr, first, j);

}


void SORT_SHAKER (int * arr, int Start, int N)
{

	/* Функция реализует сортировку массива целочисленных значений методом шейкерной сортировки,
	   первым параметром принимает адрес массива, вторым и третьим - номер первого 
	   и последнего элементов.
	   */

int Left, Right, i, tmp;

Left=Start;

Right=N-1;

while (Left<=Right)
{
for (i=Right; i>=Left; i--)
if (arr[i-1]>arr[i]) {
	tmp = arr[i] ;
	arr[i] = arr[i - 1];
    arr[i - 1] = tmp ;
}

Left++;

for (i=Left; i<=Right; i++)
if (arr[i-1]>arr[i]) {
	tmp = arr[i] ;
	arr[i] = arr[i - 1];
    arr[i - 1] = tmp ;
}

Right--;

}

}

void SORT_PYRAMIDAL (int SZarr, int * arr)
{

	/* Функция реализует сортировку массива целочисленных значений методом пирамидальной сортировки,
	   первым параметром принимает размерность массива, вторым - адрес массива.
	   */

int i, sh = 0, b = 0;

  while (1)
  {
    b = 0;
    for (i = 0; i < SZarr; ++i)
    {
      if (i*2 + 2 + sh < SZarr)
      {
        if (arr[i+sh] > arr[i*2 + 1 + sh] || arr[i + sh] > arr[i*2 + 2 + sh])
    {
      if (arr[i*2+1+sh] < arr[i*2+2+sh])
      {
        swap (&arr[i+sh], &arr[i*2+1+sh]);
        b = 1;
      }
      else if (arr[i*2+2+sh] < arr[i*2+1+sh])
      {
        swap (&arr[i+sh],&arr[i*2+2+sh]);
        b = 1;
      }
    }
      }
      else if (i * 2 + 1 + sh < SZarr)
      {
        if (arr[i+sh] > arr[i*2+1+sh])
    {
      swap (&arr[i+sh], &arr[i*2+1+sh]);
      b=1;
    }
      }
    }
    if (!b) sh++;
    if (sh+2==SZarr)
      break;
  }

}

void SORT_SELECTION (int SZarr, int * arr)
{

	/* Функция реализует сортировку массива целочисленных значений методом сортировки выбором,
	   первым параметром принимает размерность массива, вторым - адрес массива.
	   */

for (int i = 0; i < SZarr - 1; i++) 
{
/* устанавливаем начальное значение минимального индекса */
    int min_i = i;
	/* находим индекс минимального элемента */
	for (int j = i + 1; j < SZarr; j++) 
    {
		if (arr[j] < arr[min_i]) 
        {
			min_i = j;
		}
	}
	/* меняем значения местами */
	int temp = arr[i];
	arr[i] = arr[min_i];
	arr[min_i] = temp;
}

}

void SORT_MERGE (int SZarr, int * arr)
{
	/* Функция реализует сортировку массива целочисленных значений методом сортировки слиянием,
	   первым параметром принимает размерность массива, вторым - адрес массива.
	   */

    int rght, rend;
    int i, j, m;

	int * b = new int[SZarr];
 
    for (int k = 1; k < SZarr; k *= 2)
    {
        for (int LEFT = 0; LEFT + k < SZarr; LEFT += k * 2)
        {
            rght = LEFT + k;
            rend = rght + k;
            if (rend > SZarr) rend = SZarr;
            m = LEFT; i = LEFT; j = rght;
            while (i < rght && j < rend)
            {
                if (arr[i] <= arr[j])
                {
                    b[m] = arr[i]; i++;
                }
                else
                {
                    b[m] = arr[j]; j++;
                }
                m++;
            }
            while (i < rght)
            {
                b[m] = arr[i];
                i++; m++;
            }
            while (j < rend)
            {
                b[m] = arr[j];
                j++; m++;
            }
            for (m = LEFT; m < rend; m++)
            {
                arr[m] = b[m];
            }
        }
    }

	delete [] b;
}

void SORT_COUNT (int* array, int len, int min, int max)
{

	/* Функция реализует сортировку массива целочисленных значений методом сортировки подсчетом,
	   первым параметром принимает адрес массива, вторым - его размерность,
	   третьим и четвертым - минимальное и максимальное значение в массиве соответственно.
	   */

  int *cnt = new int[max-min+1];
 
  for(int i = min; i <= max; ++i) cnt[i - min] = 0;
  for(int i = 0; i < len; ++i) ++cnt[array[i] - min];
 
  for(int i = min; i <= max; ++i)
    for(int j = cnt[i - min]; j--;)
      *array++ = i;

  delete [] cnt;
}

void swap (int *a, int *b) { 
	
int t = *a; 

*a = *b; 

*b = t; 

}
