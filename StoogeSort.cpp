#include <iostream>
using namespace std;

void stoogeSort(int arr[], int l, int r)
{
    //Если массив пустой или содержит только 1 элемент
    if (l >= r)
        return;

   //Если первый элемент больше последнего, то меняем их местами
    if (arr[l] > arr[r])
        swap(arr[l], arr[r]);

    //Если в массиве больше 2 элементов
    if (r - l + 1 > 2) {
        int t = (r - l + 1) / 3;
         
        //Рекурсивно сортируем первые 2/3 элементов
        stoogeSort(arr, l, r - t);

        //Рекурсивно сортируем последние 2/3 элементов
        stoogeSort(arr, l + t, r);

        //Снова рекурсивно сортируем первые 2/3 элементов
        stoogeSort(arr, l, r - t);
    }
}

int main()
{
    int arr[] = {10, 3, 5, 9, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    stoogeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}