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
        char *tmp_c = ( char * ) new char[ strlen( f_value ) + 1 ] ;
        strcpy( tmp_c , f_value ) ;
        if ( insert_in_bpt( f_num , tmp_c ) )
        {
            printf( "Insert %d %s OK!\n" , f_num , tmp_c ) ;
            insert_count ++ ;
        } else
            printf( "Ignore %d %s\n" , f_num , tmp_c ) ;
    }
    fclose( fp ) ;

    cout << "node_count is :" << node_count << endl;
    cout << "insert_count is :" << insert_count << endl;
    return 0;
}
