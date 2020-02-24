#pragma once

#include "binnode_travpre_r.h"
#include "binnode_travpre_i1.h"
#include "binnode_travpre_i2.h"

template < typename T > template < typename VST >
void BinNode<T>::travPre ( VST& visit ) {
    switch ( rand() % 3 ) {
        case 0: travPre_I1 ( visit, this ); break;
        case 1: travPre_I2 ( visit, this ); break;
        default: travPre_R ( visit, this ); break;
    }
}