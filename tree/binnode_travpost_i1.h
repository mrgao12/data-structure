#pragma once

template < typename T >
void goHLVFL ( stack<BinNodePosi(T)>& S ) {
    while ( BinNodePosi(T) x = S.top() ) {
        if ( HasLChild( *(x) ) ) {
            if ( HasRChild( *(x) ) ) S.push ( x->rc );
            S.push ( x->lc );
        } else S.push ( x->rc );
    }
    S.pop();
}

template < typename VST, typename T >
void travPost_I1 ( VST& visit, BinNodePosi(T) x ) {
    stack<BinNodePosi(T)> S;
    if ( x ) S.push ( x );

    while ( ! S.empty() ) {
        if ( S.top() != x->parent ) goHLVFL ( S );
        x = S.top(); S.pop(); visit ( x->data );
    }
}