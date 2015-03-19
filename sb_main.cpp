//
//  sb_main.cpp
//  Exercise2
//
//  Created by Gonsalves on 3/17/15.
//
//


#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "binary.cpp"
#include "linear.cpp"
#include <ctime>
#include <vector>
using namespace std;

//this is going to be RECURSIVE
//
void binarySearch (int NE, int NS, vector<int> all, int search[])
{
    

}

void linearSearch (int NE, int NS, int all[], int search[])
{
    int search_value = 0;
    int all_value = 0;
    
    for (int i = 0; i < NS; i++)
    {
        search_value = search[i];
        //cout<<"search value:"<<search_value<<endl;
        
        for(int j =0; j<NE; j++)
        {
            all_value = all[j];
            if(search_value == all_value)
            {
                cout<<"Match found for: "<<search_value<<endl;
                break;
            }
        }
    }
}


int main(int argc, char **argv)
{
    
    int NE;  // number of elements
    int NS;  // number of element to search
    
    if (argc != 3)
    {
        printf("<usage>: parameters.\n");
        return 1;
    }
    else
    {
        NE = atoi(argv[1]);
        NS = atoi(argv[2]);
        //printf("Number of elements = %d\nNumber of elements to search = %d\n", NE, NS);
    }
    
    //Created holders for the elements
    int all_holder[NE];
    int search_holder[NS];
    
    // Initializing seed for pseudo-random sequence
    srand(time(NULL));
    
    printf("%d %d\n", NE, NS);
    for (int i=0; i<NE; i++)
    {
        int number;
        
        number = rand();
        // coin toss
        double r = ((double) rand() / (RAND_MAX));
        
        if (r < 0.05)           // Introducing neg. numbers with 5% probability
            number = - number;
        //printf("%d ", number);
        
        //added number to set
        all_holder[i] = number;
        
        cout<<all_holder[i]<<endl;
        
        //if (!(i % 100)) printf("\n");
    }
    printf("\n");
    for (int i=0; i<NS; i++)
    {
        int number;
        
        number = rand();
        // coin toss
        double r = ((double) rand() / (RAND_MAX));
        
        if (r < 0.05)           // Introducing neg. numbers with 5% probability
            number = - number;
        //printf("%d ", number);
        
        //added
        search_holder[i] = number;
        cout<<search_holder[i]<<endl;

        
        //cout<<"here2"<<endl;
        
        //if (!(i % 100)) printf("\n");
    }
    
    
    int* holder[argc];
    clock_t start = 0;
    clock_t finish = 0;
    double elapsed_time = 0;
    
    //Put all array values into a vector for easy sorting
    vector<int> all_vector (all_holder, all_holder+NE);
    sort(all_vector.begin(), all_vector.begin()+NE);
    //cout<<"Array value at 0:"<<all_holder[0]<<endl;
    
    //Print out to confirm that everything was sorted
    //Sortingis done OUTSIDE of the timing function for BOTH BINARY AND LINEAR SEARCH
    for(int a=0; a<NE; a++)
    {
        cout<<"Vector value at "<<a<<": "<<all_vector.at(a)<<endl;

    }
    
    start = clock();
    // Here goes the code you want to time
    // ...
    linearSearch(NE,NS,all_holder,search_holder);
    finish = clock();
    elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
    cout<<"Value of N: "<<NE<<endl;
    cout<<"Value of S: "<<NS<<endl;
    cout<<"Time for LinearSearch: "<<elapsed_time<<endl;
    
    return 0;

}

