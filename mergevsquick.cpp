#include <iostream>
// Para el tiempo
#include <chrono>
// Impresion
#include <iomanip>
#include <string.h>
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */
using namespace std;
void imprimir(int *arreglo, int n)
{
    cout << "{";
    for (int i = 0; i < n; i++)
        cout << " " << arreglo[i];
    cout << " }" << endl;
}

void merge(int *array, int start, int middle, int end)
{
    int fh = middle - start + 1;
    int sh = end - middle;
    int t1[fh], t2[sh];
    for (int m = 0; m < fh; m++)
        t1[m] = array[start + m];
    for (int n = 0; n < sh; n++)
        t2[n] = array[middle + 1 + n];
    int a = 0;
    int b = 0;
    int c = start;
    while (a < fh && b < sh)
    {
        if (t1[a] <= t2[b])
        {
            array[c] = t1[a];
            a++;
        }
        else
        {
            array[c] = t2[b];
            b++;
        }
        c++;
    }
    while (a < fh)
    {
        array[c] = t1[a];
        a++;
        c++;
    }
    while (b < sh)
    {
        array[c] = t2[b];
        b++;
        c++;
    }
}

void mergeSort(int *array, int start, int end)
{
    if (start < end)
    {
        int middle = start + (end - start) / 2;
        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, end);
        merge(array, start, middle, end);
    }
}

int partition(int *array, int start, int end)
{
    int pivot = start;
    int i = start + 1;
    int j = end;

    while (i <= j)
    {
        if (array[i] > array[pivot] && array[j] < array[pivot])
        {
            int aux = array[i];
            array[i] = array[j];
            array[j] = aux;
        }
        else if (array[i] <= array[pivot])
            i++;
        else if (array[j] >= array[pivot])
            j--;
    }

    int aux = array[pivot];
    array[pivot] = array[j];
    array[j] = aux;
    return j;
}

void quickSort(int *array, int start, int end)
{
    if (start < end)
    {
        int pivot = partition(array, start, end);
        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
}

void copiar(int *array, int *array2, int n)
{
    for (int i = 0; i < n; i++)
        array2[i] = array[i];
}

int main()
{
    const int n = 51;
    int **arrays = new int *[n];
    string *tiempos_merge = new string[n];
    string *tiempos_quick = new string[n];
    for (int i = 0; i < n; i++)
    {
        int w = (i == 0) ? 10 : 100 * i;
        arrays[i] = new int[w];
        for (int j = 0; j < w; j++)
            arrays[i][j] = rand() % 2001;
    }
    for (int i = 0; i < n; i++)
    {
        int w = (i == 0) ? 10 : 100 * i;
        int *array = new int[w];
        copiar(arrays[i], array, w);
        auto start = chrono::high_resolution_clock::now();
        mergeSort(array, 0, w);
        auto end = chrono::high_resolution_clock::now();
        tiempos_merge[i] = to_string(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) + " ns";
        copiar(arrays[i], array, w);
        start = chrono::high_resolution_clock::now();
        quickSort(array, 0, w - 1);
        end = chrono::high_resolution_clock::now();
        tiempos_quick[i] = to_string(chrono::duration_cast<chrono::nanoseconds>(end - start).count()) + " ns";
        delete array;
    }
    const int width = 15;
    cout << BOLDRED << setw(width) << " " << setw(width) << "Merge" << BOLDGREEN << setw((int)width / 2) << "|" << BOLDRED << setw(width) << "Quick" << endl;
    cout << BOLDGREEN << setw(width * 3.5) << "-----------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << BOLDBLUE << setw(width) << ((i == 0) ? 10 : 100 * i);
        cout << RESET << setw(width) << tiempos_merge[i] << setw((int)width / 2) << " " << setw(width) << tiempos_quick[i] << endl;
        cout << BOLDCYAN << setw(width * 3.5) << "-----------------------------------" << endl;
    }
    return 0;
}