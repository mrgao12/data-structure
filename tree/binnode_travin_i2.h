#pragma once

template < typename VST, typename T >
void travIn_I2 ( VST& visit, BinNodePosi(T) x ) {
    stack<BinNodePosi(T)> S;

    while ( true ) {
        if ( x ) {
            S.push ( x );
            x = x->lc;
        } else if ( ! S.empty() ) {
            x = S.top(); S.pop();
            visit ( x->data );
        } else break;
    }
}