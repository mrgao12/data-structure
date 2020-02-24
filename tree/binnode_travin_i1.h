#pragma once

template < typename T >
void goAlongLeftBranch ( BinNodePosi(T) x, stack<BinNodePosi(T)>& S ) {
    while ( x ) {
        S.push ( x );
        x = x->lc;
    }
}

template < typename VST, typename T >
void travIn_I1 ( VST& visit, BinNodePosi(T) x ) {
    stack<BinNodePosi(T)> S;
    while ( true ) {
        goAlongLeftBranch ( x, S );
        if ( S.empty() ) break;
        x = S.top(); S.pop();
        visit ( x->data ); x = x->rc;
    }
}