#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int TAM = 13;
template <typename T>
void printArray(T *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl
         << endl;
}
template <typename T>
void printSingleStack(stack<T> stCK)
{
    while (!stCK.empty())
    {
        cout << stCK.top();
        stCK.pop();
        cout << ((stCK.size() > 0) ? " | " : "\n");
    }
}
template <typename T>
void printStackVector(vector<stack<T>> newVector)
{
    for (int w = 0; w < newVector.size(); ++w)
        printSingleStack<T>(newVector[w]);
    cout << endl;
}
/*template <typename T>
T getLowest(vector<stack<T>> &elements)
{
    T lowest = 999999999;
    int index = -1;
    for (int i = 0; i < elements.size(); ++i)
    {
        if (!elements[i].empty() && elements[i].top() < lowest)
        {
            lowest = elements[i].top();
            index = i;
        }
    }
    if (index != -1)
    {
        elements[index].pop();
        if (elements[index].empty())
            elements.erase(elements.begin() + index);
    }
    else
    {
        cout << "|--('>')--|";
    }
    return lowest;
}*/
template <typename T>
void patienceSort(T *&elementsList, int size)
{
    vector<stack<T>> newVector;
    newVector.push_back(stack<T>());
    newVector[0].push(elementsList[0]);
    bool inserted = false;
    for (int i = 1; i < size; ++i)
    {
        inserted = false;
        for (int j = 0; j < newVector.size() && !inserted; ++j)
        {
            if (elementsList[i] <= newVector[j].top())
            {
                newVector[j].push(elementsList[i]);
                inserted = true;
            }
        }
        if (!inserted)
        {
            newVector.push_back(stack<T>());
            newVector[newVector.size() - 1].push(elementsList[i]);
        }
    }
    delete[] elementsList;
    cout << "At start" << endl;
    printStackVector<T>(newVector);
    elementsList = new T[size];
    auto getLowest = [](vector<stack<T>> &elements) {
        T lowest = 100000000;
        int index = -1;
        for (int i = 0; i < elements.size(); ++i)
        {
            if (!elements[i].empty() && elements[i].top() < lowest)
            {
                lowest = elements[i].top();
                index = i;
            }
        }
        if (index != -1)
        {
            elements[index].pop();
            if (elements[index].empty())
                elements.erase(elements.begin() + index);
        }
        else
        {
            cout << "|--('>')--|";
        }
        return lowest;
    };
    for (int i = 0; i < size; ++i)
    {
        elementsList[i] = getLowest(newVector);
        /*if (i != size - 1)
        {
            cout << "At " << i + 1 << "° repetition" << endl;
            printStackVector<T>(newVector);
        }*/
    }
}
int main()
{
    int *toOrder = new int[TAM];
    int elements[TAM] = {89, 144, 55, 1, 13, 21, 2, 34, 0, 1, 8, 5, 3};
    for (int i = 0; i < TAM; i++)
    {
        toOrder[i] = elements[i];
    }
    cout << "\nInitial\n";
    printArray<typeof(*toOrder)>(toOrder, TAM);
    patienceSort<typeof(*toOrder)>(toOrder, TAM);
    cout << "\nFinal\n";
    printArray<typeof(*toOrder)>(toOrder, TAM);
}