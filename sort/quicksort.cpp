#include <iostream>
#include <vector>
using namespace std;

int partition ( int lo, int hi, vector<int>& a ) {
    int pivot = a[lo];
    while ( lo < hi ) {
        while ( ( lo < hi ) && ( pivot <= a[hi] ) ) hi--;
        a[lo] = a[hi];
        while ( ( lo < hi ) && ( pivot >= a[lo] ) ) lo++;
        a[hi] = a[lo];
    }
    a[lo] = pivot;
    return lo;
}

void quickSort ( int lo, int hi, vector<int>& a ) {
    if ( hi - lo < 2 ) return;
    int mi = partition ( lo, hi-1, a );
    quickSort ( lo, mi, a );
    quickSort ( mi+1, hi, a );
}

int main() {
    int A[] = { 6, 5, 4, 3, 2, 1 };
    vector<int> a ( A, A+6 );
    cout << "------------------ÅÅÐòÇ°----------------" << endl;
    for ( int i = 0; i < a.size(); i++ ) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    quickSort ( 0, a.size(), a );
    cout << "------------------ÅÅÐòºó----------------" << endl;
    for ( int i = 0; i < a.size(); i++ ) {
        cout << a[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}