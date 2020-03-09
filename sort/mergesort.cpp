#include <iostream>
#include <vector>
using namespace std;

void merge ( int a[], int lo, int mi, int hi ) {
    int *A = a + lo;
    int lb = mi - lo; int lc = hi - mi;
    int *B = new int[lb]; int *C = a + mi;
    for ( int i = 0; i < lb; B[i] = A[i++] );

    for ( int i = 0, j = 0, k = 0; ( j < lb ) || ( k < lc ); ) {
        if ( ( j < lb ) && ( ! ( k < lc ) || ( B[j] <= C[k] ) ) ) A[i++] = B[j++];
        if ( ( k < lc ) && ( ! ( j < lb ) || ( C[k] < B[j] ) ) ) A[i++] = C[k++];
    }
}

void mergeSort ( int a[], int lo, int hi ) {
    if ( hi - lo < 2 ) return;
    int mi = ( lo + hi ) / 2;
    mergeSort ( a, lo, mi ); mergeSort ( a, mi, hi );
    merge ( a, lo, mi, hi );
}

int main() {
    int a[] = { 6, 5, 4, 3, 2, 1 };
    cout << "------------------ÅÅÐòÇ°----------------" << endl;
    for ( int i = 0; i < 6; i++ ) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    mergeSort ( a, 0, 6 );
    cout << "------------------ÅÅÐòºó----------------" << endl;
    for ( int i = 0; i < 6; i++ ) {
        cout << a[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}