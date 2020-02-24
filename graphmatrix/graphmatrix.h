#pragma once

#include <vector>
#include <cstdlib>
#include "../graph/graph.h"
using namespace std;

template < typename Tv > struct Vertex {
    Tv data; int dTime, fTime; int inDegree, outDegree;
    int parent; int priority; VStatus status;

    Vertex ( Tv const& d = ( Tv ) 0 ) : data ( d ), status ( UNDISCOVERED ), dTime ( -1 ), fTime ( -1 ), inDegree ( 0 ), outDegree ( 0 ), parent ( -1 ), priority ( INT_MAX ) {}
};

template < typename Te > struct Edge {
    Te data; EType type; int weight;
    Edge ( Te const& d, int w ) : data ( d ), weight ( w ), type ( UNDETERMINED ) {}
};

template < typename Tv, typename Te >
class GraphMatrix : public Graph< Tv, Te > {
    private:
        vector< Vertex< Tv > > V;
        vector< vector< Edge< Te >* > > E;
    public:
        GraphMatrix() { n = e = 0; }
        ~GraphMatrix() {
            for ( int i = 0; i < n; i++ ) {
                for ( int j = 0; j < n; j++ ) {
                    delete E[i][j];
                }
            }
        }

        virtual Tv& Vertex ( int i ) { return V[i].data; }
        virtual int inDegree ( int i ) { return V[i].inDegree; }
        virtual int outDegree ( int i ) { return V[i].outDegree; }
        virtual VStatus& status ( int i ) { return V[i].status; }
        virtual int& fTime ( int i ) { return V[i].fTime; }
        virtual int& dTime ( int i ) { return V[i].dTime; }
        virtual int& priority ( int i ) { return V[i].priority; }
        virtual int& parent ( int i ) { return V[i].parent; }
        virtual int firstNbr ( int i ) { return nextNbr ( i, n ); }
        virtual int nextNbr ( int i, int j ) { 
            while ( ( -1 < j ) && ( ! exists ( i, --j ) ) ); return j;
        }
        virtual int insert ( Tv const& d ) {
            for ( int i = 0; i < n; i++ ) E[i].push_back ( ( Edge< Te >* ) NULL ); n++;
            E.push_back ( vector< Edge< Te >* > ( n, ( Edge< Te >* ) NULL ) );
            V.push_back ( Vertex< Tv > ( d ) );
            return n;
        }
        virtual Tv remove ( int i ) {
            for ( int j = 0; j < n; i++ ) {
                if ( exists ( i, j ) ) { delete E[i][j]; V[j].inDegree--; }
            }
            E.erase ( i ); n--;
            
            Tv d = V[i].data; V.erase ( i );

            for ( int j = 0; j < n; j++ ) {
                if ( exists ( j, i ) ) delete E[j][i];
                E[j].erase ( i );
            }
            return d;
        }

        virtual Te& edge ( int i, int j ) { return E[i][j]->edge; }
        virtual EType& type ( int i, int j ) { return E[i][j]->type; }
        virtual int& weight ( int i, int j ) { return E[i][j]->weight; }
        virtual bool exists ( int i, int j ) {
            if ( i > 0 && i < n && j > 0 && j < n && E[i][j] ) return true;
        }

        virtual void insert ( Te const& d, int w, int i, int j ) {
            if ( exists ( i, j ) ) return;
            E[i][j] = new Edge< Te > ( d, w );
            V[i].outDegree++; V[j].inDegree++; e++;
        }

        virtual Te remove ( int i, int j ) {
            Te d = E[i][j].data; delete E[i][j]; E[i][j] = NULL;
            e--; V[i].outDegree--; V[j].inDegree--;
            return d;
        }
};