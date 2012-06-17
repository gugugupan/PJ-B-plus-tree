#ifndef __GP__BPT__
#define __GP__BPT__

#include <iostream>
#include <string>
#include <vector>

const int M = 4 ;

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

extern void Initial() ;
extern void insert_in_bpt( int key , void *value ) ;


#endif
