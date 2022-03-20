#include <iostream>
// Para el tiempo
#include <chrono>
// Para el merge en el mergeSort
#include <vector>
#include <algorithm>
using namespace std;
void imprimir(int *arreglo, int n)
{
    cout << "{";
    for (int i = 0; i < n; i++)
        cout << " " << arreglo[i];
    cout << " }" << endl;
}

void bubbleSort(int *array, int tam)
{
    bool swapped = true;
    for (int i = 0; i < tam - 1 && swapped; i++)
    {
        swapped = false;
        for (int j = 0; j < tam - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
                swapped = true;
            }
        }
    }
}

void selectionSort(int *array, int tam)
{
    int minPosition, aux;

    for (int i = 0; i < tam - 1; i++)
    {
        minPosition = i;

        for (int j = i + 1; j < tam; j++)
        {

            if (array[j] < array[minPosition])
            {
                minPosition = j;
            }
        }
        if (minPosition > i)
        {
            int aux = array[i];
            array[i] = array[minPosition];
            array[minPosition] = aux;
        }
    }
}

void insertionSort(int *array, int tam)
{
    int current, pos, p;
    bool swap = true;
    for (int i = 0; i < tam - 1 && swap; i++)
    {
        swap = false;
        current = array[i];
        pos = array[i + 1];
        p = i + 1;
        for (int j = i + 1; j < tam; j++)
            if (array[j] < pos)
            {
                pos = array[j];
                p = j;
            }
        if (array[i] > pos)
        {
            swap = true;
            array[i] = pos;
            array[p] = current;
        }
    }
}

void merge(int* array, int start, int middle, int end)
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
        quickSort(array, start, pivot);
        quickSort(array, pivot + 1, end);
    }
}

int main()
{
    int n, i;
    cout << "Ingrese el numero de elementos: ";
    cin >> n;
    int *arreglo = new int[n];
    int *copia = new int[n];
    int numero;

    cout << "Ingrese los elementos separados por espacio: ";
    for (i = 0; i < n; i++)
        cin >> arreglo[i];

    cout << "El arreglo original es: ";
    imprimir(arreglo, n);
    while (true)
    {

        cout << "\n\n\n1. Burbuja\n";
        cout << "2. Seleccion\n";
        cout << "3. Inserción\n";
        cout << "4. Merge\n";
        cout << "5. Quick\n";
        cout << "0. Salir\n";
        cin >> numero;
        for (i = 0; i < n; i++)
            copia[i] = arreglo[i];
        switch (numero)
        {
        case 1:
        {
            auto t0 = chrono::high_resolution_clock::now();
            bubbleSort(copia, n);
            auto t1 = chrono::high_resolution_clock::now();
            cout << "Tiempo de ejecucion: " << chrono::duration_cast<chrono::nanoseconds>(t1 - t0).count() << " nanosegundos\n";
            imprimir(copia, n);
            break;
        }
        case 2:
        {
            auto t0 = chrono::high_resolution_clock::now();
            selectionSort(copia, n);
            auto t1 = chrono::high_resolution_clock::now();
            cout << "Tiempo de ejecucion: " << chrono::duration_cast<chrono::nanoseconds>(t1 - t0).count() << " nanosegundos\n";
            imprimir(copia, n);
            break;
        }
        case 3:
        {
            auto t0 = chrono::high_resolution_clock::now();
            insertionSort(copia, n);
            auto t1 = chrono::high_resolution_clock::now();
            cout << "Tiempo de ejecucion: " << chrono::duration_cast<chrono::nanoseconds>(t1 - t0).count() << " nanosegundos\n";
            imprimir(copia, n);
            break;
        }
        case 4:
        {
            auto t0 = chrono::high_resolution_clock::now();
            mergeSort(copia, 0, n);
            auto t1 = chrono::high_resolution_clock::now();
            cout << "Tiempo de ejecucion: " << chrono::duration_cast<chrono::nanoseconds>(t1 - t0).count() << " nanosegundos\n";
            imprimir(copia, n);
            break;
        }
        case 5:
        {
            auto t0 = chrono::high_resolution_clock::now();
            quickSort(copia, 0, n-1);
            auto t1 = chrono::high_resolution_clock::now();
            cout << "Tiempo de ejecucion: " << chrono::duration_cast<chrono::nanoseconds>(t1 - t0).count() << " nanosegundos\n";
            imprimir(copia, n);
            break;
        }
        default:
            return 0;
        }
    }
    return 0;
}