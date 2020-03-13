#pragma once

#define IsRoot(x) ( ! (x).parent )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
#define HasParent(x) ( ! IsRoot(x) )
#define HasLChild(x) ( (x).lc )
#define HasRChild(x) ( (x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) )
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) )
#define IsLeaf(x) ( ! HasChild(x) )

#define sibling(p) ( IsLChild( *(p) ) ? p->parent->rc : p->parent->lc )
#define uncle(p) ( IsLChild( *(p->parent) ) ? p->parent->parent->rc : p->parent->parent->lc )
#define FromParentTo(p) ( IsRoot( *(p) ) ? BinTree<T>::_root : ( IsLChild( *(p) ) ? p->parent->lc : p->parent->rc ) )