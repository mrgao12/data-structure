#pragma once

template < typename T, typename VST >
void visitAlongLeftBranch ( stack<BinNodePosi(T)>& S, VST& visit, BinNodePosi(T) x ) {
    while ( x ) {
        visit ( x->data );
        S.push ( x->rc );
        x = x->lc;
    }
}

template < typename VST, typename T >
void travPre_I2 ( VST& visit, BinNodePosi(T) x ) {
    stack<BinNodePosi(T)> S;

    while ( true ) {
        visitAlongLeftBranch ( S, visit, x );
        if ( S.empty() ) break;
        x = S.top(); S.pop();
    }
}