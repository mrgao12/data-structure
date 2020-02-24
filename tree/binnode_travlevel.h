#pragma once

template < typename T > template < typename VST >
void BinNode<T>::travLevel ( VST& visit ) {
    BinNodePosi(T) x = this;
    queue<BinNodePosi(T)> Q;
    Q.push ( x );
    while ( ! Q.empty() ) {
        x = Q.front(); Q.pop();
        visit ( x->data );
        if ( HasLChild ( *(x) ) ) Q.push ( x->lc );
        if ( HasRChild ( *(x) ) ) Q.push ( x->rc );
    }
}