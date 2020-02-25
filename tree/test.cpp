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
    cout << "层序遍历：";
    t.travLevel(visit);
    cout << endl;
    
    cout << "先序遍历：";
    t.travPre(visit);
    cout << endl;

    cout << "中序遍历：";
    t.travIn(visit);
    cout << endl;

    cout << "后序遍历：";
    t.travPost(visit);
    cout << endl;

    cout << "全树规模：" << t.size() << endl;

    cout << "是否为空树：" << t.empty() << endl;

    cout << "根节点元素：" << t.root()->data << endl;
}

int main() {
    VST<int> visit;

    cout << "--------------------建立树--------------------" << endl;
    BinTree<int> t;
    BinNodePosi(int) root = t.insertAsRoot ( 1 );
    BinNodePosi(int) l0 = t.insertAsLC(root, 2);
    BinNodePosi(int) r0 = t.insertAsRC(root, 3);
    BinNodePosi(int) l0l0 = t.insertAsLC(l0,4);
    BinNodePosi(int) r0l0 = t.insertAsLC(r0,5);
    BinNodePosi(int) r0r0 = t.insertAsRC(r0,6);
    test ( t, visit );
    
    cout << endl << endl << "------------------建立新树---------------" << endl;
    BinTree<int>* t1 = new BinTree<int>();
    BinNodePosi(int) root_t1 = t1->insertAsRoot( 10 );
    t1->insertAsLC ( root_t1, 11 );
    t1->insertAsRC ( root_t1, 12 );
    test ( *t1, visit );

    cout << endl << endl << "------------------接入子树-----------------" << endl;
    t.attachAsRC ( r0l0, t1 );
    test ( t, visit );

    cout << endl << endl << "------------------删除子树-----------------" << endl;
    BinTree<int>* t2 = t.secede ( r0 );
    test ( *t2, visit );

    cout << endl << endl << "------------------删除节点-----------------" << endl;
    t2->remove ( r0l0 );
    test ( *t2, visit );

    
    system("pause");
    return 0;
}