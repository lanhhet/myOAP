
/* SortAlgo.h

   Интерфейс набора алгоритмов сортировки массивов целочисленных данных.
   
*/

void SORT_SHELL (int, int *) ;
void SORT_HOARE (int *, int, int) ;
void SORT_SHAKER (int *, int, int) ;
void SORT_PYRAMIDAL (int, int *) ;
void SORT_SELECTION (int, int *) ;
void SORT_MERGE (int, int *) ;
void SORT_COUNT (int *, int, int, int) ;

void swap (int *, int *);  // вспомогательная функция - меняет местами значения двух переменных