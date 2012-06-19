#ifndef __GP__BPT__
#define __GP__BPT__

#include <iostream>
#include <string>
#include <vector>

const int M = 21 ;

/*
struct data_node
{
    int key ;
    char *value ;
    void *next ;
} ;
*/

struct bpt_node
{
    bool is_leaf ;
    bool is_root ;
    int key_num ;
    int key[ M ] ;
    void *pointer[ M + 1 ] ;
    void *father ;
} ;

extern int node_count ;
extern int splite_count ;
extern void initial_bpt() ;
extern bool insert_in_bpt( int key , void *value ) ;
extern bool delete_in_bpt( int key ) ;
extern char *query_in_bpt( int key ) ;


#endif
