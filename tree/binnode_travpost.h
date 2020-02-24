#pragma once

#include "binnode_travpost_i1.h"
#include "binnode_travpost_r.h"

template < typename T > template < typename VST >
void BinNode<T>::travPost ( VST& visit ) {
    switch ( rand() % 2 ) {
        case 0: travPost_I1 ( visit, this );
        default: travPost_R ( visit, this );
    }
}