#ifndef __GP__BPT__
#define __GP__BPT__

#include <iostream>
#include <string>
#include <vector>

const int M = 3 ;

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
extern void initial_bpt() ;
extern bool insert_in_bpt( int key , void *value ) ;


#endif
