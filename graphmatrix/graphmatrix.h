#pragma once

#include "../graph/graph.h"
#include <vector>
#include <cstdlib>
using namespace std;

template < typename Tv > struct Vertex {
    Tv data; VStatus status; int inDegree, outDegree;
    int dTime, fTime; int parent; int priority;

    Vertex ( Tv const& d = ( Tv ) 0 ) : data ( d ), status ( UNDISCOVERED ), priority ( INT_MAX ),
        dTime ( -1 ), fTime ( -1 ), inDegree ( -1 ), outDegree ( -1 ) {}
};

template < typename Te > struct Edge {
    Te data; int weight; EType type;
    Edge ( Te const& d, int w ) : data ( d ), weight ( w ), type ( UNDETERMINED ) {}
};

template <typename Tv, typename Te>
class GraphMatrix : public Graph< Tv, Te > {
    private:
        vector< Vertex< Tv > > V;
        vector< vector< Edge< Te >* > > E;
    public:
        GraphMatrix() { Graph<Tv, Te>::n = 0; Graph<Tv, Te>::e = 0; }
        ~GraphMatrix() {
            for ( int i = 0; i < Graph<Tv, Te>::n; i++ ) {
                for ( int j = 0; j < Graph<Tv, Te>::n; j++ ) {
                    delete E[i][j];
                }
            }
        }

        virtual Tv& vertex ( int i ) { return V[i].data; }
        virtual int& dTime ( int i ) { return V[i].dTime; }
        virtual int& fTime ( int i ) { return V[i].fTime; }
        virtual VStatus& status ( int i ) { return V[i].status; }
        virtual int& parent ( int i ) { return V[i].parent; }
        virtual int& priority ( int i ) { return V[i].priority; }
        virtual int inDegree ( int i ) { return V[i].inDegree; }
        virtual int outDegree ( int i ) { return V[i].outDegree; }
        virtual int firstNbr ( int i ) { return nextNbr ( i, Graph<Tv, Te>::n ); }
        virtual int nextNbr ( int i, int j ) {
            while ( ( -1 < j ) && ( ! exists ( i, --j ) ) ); return j;
        }
        virtual int insert ( Tv const& d ) {
            for ( int i = 0; i < Graph<Tv, Te>::n; i++ ) E[i].push_back ( ( Edge< Te >* ) NULL );
            V.push_back ( Vertex< Tv > ( d ) ); Graph<Tv, Te>::n++;
            E.push_back ( vector< Edge< Te >* > ( Graph<Tv, Te>::n, ( Edge< Te >* ) NULL ) );
            return Graph<Tv, Te>::n;
        }
        virtual Tv remove ( int i ) {
            for ( int j = 0; j < Graph<Tv, Te>::n; j++ ) {
                if ( exists ( i, j ) ) {
                    delete E[i][j];
                    V[j].inDegree--;
                }
            }
            E.erase ( E.begin() + i );

            Tv d = V[i].data; V.erase ( V.begin() + i ); Graph<Tv, Te>::n--;

            for ( int j = 0; j < Graph<Tv, Te>::n; j++ ) {
                if ( exists ( j, i ) ) {
                    delete E[j][i];
                    V[j].outDegree--;
                }
                E[j].erase ( E[j].begin() + i );
            }

            return d;
        }

        virtual Te& edge ( int i, int j ) { return E[i][j]->data; }
        virtual int& weight ( int i, int j ) { return E[i][j]->weight; }
        virtual EType& type ( int i, int j ) { return E[i][j]->type; }
        virtual bool exists ( int i, int j ) {
            return ( i >= 0 && j >= 0 && i < Graph<Tv, Te>::n && j < Graph<Tv, Te>::n && E[i][j] != NULL );
        }
        virtual void insert ( Te const& d, int w, int i, int j ) {
            if ( exists ( i, j ) ) return;
            E[i][j] = new Edge<Te> ( d, w );
            Graph<Tv, Te>::e++; V[i].outDegree++; V[j].inDegree++;
        }

        virtual Te remove ( int i, int j ) {
            Te d = E[i][j]->data; delete E[i][j]; E[i][j] = NULL;
            Graph<Tv, Te>::e--; V[i].outDegree--; V[j].inDegree--;
            return d;
        }
};