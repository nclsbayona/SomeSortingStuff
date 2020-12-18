#include <iostream>
#include <chrono>
#include <ctime>
/*#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif*/
using namespace std;
const int N=10; //Se puede cambiar y no debe pasar nada
void llenarArr(int arr[]){
    srand(time(NULL));
    for (int i=0; i<N; ++i)
        arr[i]=rand()%1001;
}
long double fac(int n){
    if (!n || n==1)
        return 1;
    return n*fac(n-1);
}
int main(){
    int array[N];
    long double facto;
    llenarArr(array);
    auto start = chrono::system_clock::now();
    for(int i=0;i<N;++i)
        facto=fac(array[i]);
    auto end=chrono::system_clock::now();
    chrono::duration<double> elapsed=end-start;
    cout<<"Factorial de "<<array[N-1]<<"="<<facto<<"\nTiempo "<<elapsed.count();
}