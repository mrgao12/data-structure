#include "bst.h"
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
    BST<int> bst;
    bst.insertAsRoot(5);
    VST<int> visit;

    for ( int i = 10; i >= 1; i-- ) {
        bst.insert ( i );
    }
    cout << "-----------------对新树中序遍历---------------" << endl;
    bst.travIn ( visit );
    cout << endl << endl;

    cout << "-----------------删除节点中序遍历---------------" << endl;
    bst.remove ( 5 );
    bst.travIn ( visit );
    cout << endl << endl;
    
    system("pause");
    return 0;
}