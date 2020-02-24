#pragma once

template < typename VST, typename T >
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
void travPost ( VST& visit, BinNodePosi(T) x ) {
    stack<BinNodePosi(T)> S;
    if ( x ) S.push ( x );

    while ( ! S.empty() ) {
        if ( S.top() != x ) goHLVFL ( S );
        x = S.pop(); visit ( x->data );
    }
}