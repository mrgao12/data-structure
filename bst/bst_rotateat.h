#pragma once

template < typename T >
BinNodePosi(T) BST<T>::rotateAt ( BinNodePosi(T) v ) {
    if ( ! v ) { cout << " NULL node can not be rotated! " << endl; exit ( -1 ); }
    BinNodePosi(T) p = v->parent; BinNodePosi(T) g = p->parent;

    if ( IsLChild( *(p) ) ) {
        if ( IsLChild( *(v) ) ) {
            p->parent = g->parent;
            return connect34 ( v, p, g, v->lc, v->rc, p->rc, g->rc );
        } else {
            v->parent = g->parent;
            return connect34 ( p, v, g, p->lc, v->lc, v->rc, g->rc );
        }
    } else {
        if ( IsLChild( *(v) ) ) {
            v->parent = g->parent;
            return connect34 ( g, v, p, g->lc, v->lc, v->rc, p->rc );
        } else {
            p->parent = g->parent;
            return connect34 ( g, p, v, g->lc, p->lc, v->lc, v->rc );
        }
    }
}