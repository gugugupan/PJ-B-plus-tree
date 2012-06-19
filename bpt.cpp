#include <iostream>
#include <string>
#include "bpt.h"
using namespace std;

bpt_node *root ;
//data_node *data ;
int node_count ;
int splite_count ;

void initial_bpt()
{
    root = new_bpt_node() ;
    root -> is_root = true ;
    root -> is_leaf = true ;
    node_count = 0 ;
    splite_count = 0 ;
    //data = NULL ;
}

bpt_node *new_bpt_node()
{
    node_count ++ ;

    bpt_node *p = new bpt_node ;
    p -> is_leaf = false ;
    p -> is_root = false ;
    p -> key_num = 0 ;
    p -> pointer[ 0 ] = NULL ;
    p -> father = NULL ;
    return p ;
}
/*
data_node *new_data_node( int key , char *value )
{
    data_node *p = new data_node ;
    p -> key = key ;
    p -> value = value ;
    p -> next = NULL ;
    return p ;
}

void insert_data( data_node *father , data_node *data )
{
    data -> next = father -> next ;
    father -> next = ( void *) data ;
}
*/

bpt_node *find_leaf( int key )
{
    bpt_node *now = root ;
    while ( !now -> is_leaf )
    {
        for ( int i = 0 ; i <= now -> key_num ; i ++ )
            if ( i == now -> key_num || key < now -> key[ i ] )
            {
                now = ( bpt_node *) now -> pointer[ i ] ;
                break ;
            }
    }
    return now ;
}

void insert_in_node( bpt_node *node , int key , void *value ) ;

void split( bpt_node *node )
{
    splite_count ++ ;
    //cout << endl << "split!:" << node -> key_num << ' ' << node -> key[ 0 ] << ' ' << node -> key[ 1 ] << ' ' << node -> key[ 2 ] << endl;
    bpt_node *nodd = new_bpt_node() ;
    int mid_key = node -> key[ M / 2 ] ;

    nodd -> key_num = M - M / 2 - 1 ;
    for ( int i = 0 ; i < nodd -> key_num ; i ++ )
    {
        nodd -> key[ i ] = node -> key[ i + ( M / 2 + 1 ) ] ;
        nodd -> pointer[ i ] = node -> pointer[ i + ( M / 2 + 1 ) ] ;
    }
    nodd -> pointer[ nodd -> key_num ] = node -> pointer[ M ] ;
    node -> key_num = M / 2 ;

    if ( node -> is_leaf )
    {
        node -> key_num ++ ;
        nodd -> pointer[ 0 ] = node -> pointer[ 0 ] ;
        node -> pointer[ 0 ] = nodd ;
        nodd -> is_leaf = true ;
        mid_key = node -> key[ M / 2 + 1 ] ;
    }

    if ( node -> is_root )
    {
        node -> is_root = false ;
        root = new_bpt_node() ;
        root -> is_root = true ;
        root -> key[ 0 ] = mid_key ;
        root -> pointer[ 0 ] = node ;
        root -> pointer[ 1 ] = nodd ;
        root -> key_num = 1 ;

        node -> father = nodd -> father = root ;
    } else
    {
        nodd -> father = node -> father ;
        insert_in_node( ( bpt_node * ) node -> father , mid_key , ( void *) nodd ) ;
    }
    /*
    cout << "midnum: " << mid_key << endl;
    cout << "father: " << (( bpt_node * )node -> father )-> key_num << ' '<< ((bpt_node*)node -> father )-> key[ 0 ] << endl;
    cout << "node: " << node -> key_num << ' ' << node -> key[ 0 ] << ' ' << node -> key[ 1 ] << endl;
    cout << "nodd: " << nodd -> key_num << ' ' << nodd -> key[ 0 ] << ' ' << nodd -> key[ 1 ] << endl << endl ;
    */
}

void insert_in_node( bpt_node *node , int key , void *value )
{
    int x = 0 ;
    while ( x < node -> key_num && node -> key[ x ] < key ) x ++ ;
    for ( int i = node -> key_num ; i > x ; i -- )
        node -> key[ i ] = node -> key[ i - 1 ] ;
    for ( int i = node -> key_num + 1 ; i > x + 1 ; i -- )
        node -> pointer[ i ] = node -> pointer[ i - 1 ] ;
    node -> key[ x ] = key ;
    node -> pointer[ x + 1 ] = value ;
    node -> key_num ++ ;

    if ( node -> key_num == M ) // need to split
        split( node ) ;
}

void delete_in_node( bpt_node *node , int key )
{
    int x = 0 ;
    while ( key != node -> key[ x ] ) x ++ ;
    for ( int i = x ; i < node -> key_num - 1 ; i ++ )
        node -> key[ i ] = node -> key[ i + 1 ] ;
    for ( int i = x + 1 ; i < node -> key_num ; i ++ )
        node -> pointer[ i ] = node -> pointer[ i + 1 ] ;
    node -> key_num -- ;
}

bool insert_in_bpt( int key , void *value )
{
    bpt_node *leaf = find_leaf( key ) ;
    for ( int i = 0 ; i < leaf -> key_num ; i ++ )
        if ( key == leaf -> key[ i ] )
            return false ;
    insert_in_node( leaf , key , value ) ;
    return true ;
}

bool delete_in_bpt( int key )
{
    bpt_node *leaf = find_leaf( key ) ;
    for ( int i = 0 ; i < leaf -> key_num ; i ++ )
        if ( key == leaf -> key[ i ] )
        {
            delete_in_node( leaf , key ) ;
            return true ;
        }
    return false ;
}

char *query_in_bpt( int key )
{
    bpt_node *leaf = find_leaf( key ) ;
    for ( int i = 0 ; i < leaf -> key_num ; i ++ )
        if ( key == leaf -> key[ i ] )
            return ( char * ) leaf -> pointer[ i + 1 ] ;
    return NULL ;
}
