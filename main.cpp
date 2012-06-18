#include <iostream>
#include <cstdio>
#include <cstring>
#include "bpt.h"

using namespace std;

int insert_count ;

int main()
{
    FILE *fp = fopen( "test" , "r" ) ;
    if ( fp == NULL )
    {
        cout << "." << endl;
        return 0 ;
    }

    initial_bpt() ;
    int f_num ;
    char f_value[ 10 ] ;
    insert_count = 0 ;

    while ( fscanf( fp , "%d%s" ,&f_num , f_value ) != EOF )
    {
        cout << f_num << ' ' << f_value << "OK!" << endl;
        char *tmp_c = ( char * ) new char[ strlen( f_value ) + 1 ] ;
        strcpy( tmp_c , f_value ) ;
        insert_in_bpt( f_num , tmp_c ) ;

        insert_count ++ ;
    }
    fclose( fp ) ;

    cout << "node_count is :" << node_count << endl;
    cout << "insert_count is :" << insert_count << endl;
    return 0;
}
