#include <iostream>
#include "bintree.h"
using namespace std;

template <typename T>
class VST {
    public:
        void operator() ( T data ) {
            cout << data << " ";
        }
};

template < typename VST >
void test ( BinTree<int>& t, VST& visit ) {
    cout << "���������";
    t.travLevel(visit);
    cout << endl;
    
    cout << "���������";
    t.travPre(visit);
    cout << endl;

    cout << "���������";
    t.travIn(visit);
    cout << endl;

    cout << "���������";
    t.travPost(visit);
    cout << endl;

    cout << "ȫ����ģ��" << t.size() << endl;

    cout << "�Ƿ�Ϊ������" << t.empty() << endl;

    cout << "���ڵ�Ԫ�أ�" << t.root()->data << endl;
}

int main() {
    VST<int> visit;

    cout << "--------------------������--------------------" << endl;
    BinTree<int> t;
    BinNodePosi(int) root = t.insertAsRoot ( 1 );
    BinNodePosi(int) l0 = t.insertAsLC(root, 2);
    BinNodePosi(int) r0 = t.insertAsRC(root, 3);
    BinNodePosi(int) l0l0 = t.insertAsLC(l0,4);
    BinNodePosi(int) r0l0 = t.insertAsLC(r0,5);
    BinNodePosi(int) r0r0 = t.insertAsRC(r0,6);
    test ( t, visit );
    
    cout << endl << endl << "------------------��������---------------" << endl;
    BinTree<int>* t1 = new BinTree<int>();
    BinNodePosi(int) root_t1 = t1->insertAsRoot( 10 );
    t1->insertAsLC ( root_t1, 11 );
    t1->insertAsRC ( root_t1, 12 );
    test ( *t1, visit );

    cout << endl << endl << "------------------��������-----------------" << endl;
    t.attachAsRC ( r0l0, t1 );
    test ( t, visit );

    cout << endl << endl << "------------------ɾ������-----------------" << endl;
    BinTree<int>* t2 = t.secede ( r0 );
    test ( *t2, visit );

    cout << endl << endl << "------------------ɾ���ڵ�-----------------" << endl;
    t2->remove ( r0l0 );
    test ( *t2, visit );

    
    system("pause");
    return 0;
}