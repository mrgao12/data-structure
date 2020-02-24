#pragma once

#include "binnode_travin_i1.h"
#include "binnode_travin_i2.h"
#include "binnode_travin_i3.h"
#include "binnode_travin_r.h"

template < typename T > template < typename VST >
void BinNode<T>::travIn ( VST& visit ) {
    switch ( rand() % 3 ) {
        case 0: travIn_I1 ( visit, this ); break;
        case 1: travIn_I2 ( visit, this ); break;
        case 2: travIn_I3 ( visit, this ); break;
        default: travIn_R ( visit, this ); break;
    }
}