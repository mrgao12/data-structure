#pragma once

#include "binnode.h"

template < typename T >
class BinTree {
    protected:
        BinNodePosi(T) _root; int _size;
        virtual int updateHeight ( BinNodePosi(T) x );
        void updateHeightAbove ( BinNodePosi(T) x );
    public:
        BinTree() : _size ( 0 ), _root ( NULL ) {}
        ~BinTree() { if ( 0 < _size ) remove ( _root ); }

        int size() const { return _size; }
        bool empty() const { return ! _root; }
        BinNodePosi(T) root() const { return _root; }

        BinNodePosi(T) insertAsRoot ( T const& e );
        BinNodePosi(T) insertAsLC ( BinNodePosi(T) x, T const& e );
        BinNodePosi(T) insertAsRC ( BinNodePosi(T) x, T const& e );
        BinNodePosi(T) attachAsLC ( BinNodePosi(T) x, BinTree<T>* &t );
        BinNodePosi(T) attachAsRC ( BinNodePosi(T) x, BinTree<T>* &t );

        int remove ( BinNodePosi(T) x );
        BinTree<T>* secede ( BinNodePosi(T) x );

        template < typename VST > void travLevel ( VST& visit ) { if ( _root ) _root->travLevel ( visit ); }
        template < typename VST >
        void travPre ( VST& visit ) { if ( _root ) _root->travPre ( visit ); }
        template < typename VST >
        void travIn ( VST& visit ) { if ( _root ) _root->travIn ( visit ); }
        template < typename VST >
        void travPost ( VST& visit ) { if ( _root ) _root->travPost ( visit ); }
};

#include "bintree_implementation.h"