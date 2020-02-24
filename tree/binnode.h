#pragma once

#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

#define BinNodePosi(T) BinNode<T>*
#define stature(p) ( (p) ? (p)->height : -1 )

template < typename T > struct BinNode {
    T data; int height;
    BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc;

    BinNode() : parent ( NULL ), lc ( NULL ), rc ( NULL ), height ( 0 ) {}
    BinNode ( T e, BinNodePosi(T) p = NULL, BinNodePosi(T) l = NULL, BinNodePosi(T) r = NULL, int h = 0 ) :
        data ( e ), parent ( p ), lc ( l ), rc ( r ), height ( h ) {}
    
    int size();

    BinNodePosi(T) insertAsLC ( T const& );
    BinNodePosi(T) insertAsRC ( T const& );

    BinNodePosi(T) succ();

    template < typename VST > void travPre ( VST& );
    template < typename VST > void travIn ( VST& );
    template < typename VST > void travPost ( VST& );
    template < typename VST > void travLevel ( VST& );
};

#include "binnode_implementation.h"
