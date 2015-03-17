//
//  sb_main.cpp
//  Exercise2
//
//  Created by Gonsalves on 3/17/15.
//
//

#include <stdio.h>
#include <algorithm>
#include <binary.h>
#include <linear.h>
#include <ctime>

int main
{
    clock_t start, finish;
    double elapsed_time;
    
    start = clock();
    // Here goes the code you want to time
    // ...
    finish = clock();
    elapsed_time = (double)(finish - start)/CLOCKS_PER_SEC;

}
