#include "avl.h"
#include <iostream>
using namespace std;

template <typename T>
class VST {
    public:
        void operator() ( T data ) {
            cout << data << " ";
        }
};

int main() {
    AVL<int> avl;
    avl.insertAsRoot(5);
    VST<int> visit;

    for ( int i = 10; i >= 1; i-- ) {
        avl.insert ( i );
    }
    cout << "-----------------�������������---------------" << endl;
    avl.travIn ( visit );
    cout << endl << endl;

    cout << "-----------------ɾ���ڵ��������---------------" << endl;
    avl.remove ( 5 );
    avl.travIn ( visit );
    cout << endl << endl;
    
    system("pause");
    return 0;
}