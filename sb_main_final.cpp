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
//search CAN remain an array, does not need to be sorted in order to search through the venctor elementally
void binarySearch (int NE, int left, int right, vector<int> all, int search_value)
{
    //this catches and stops the sequence
    if (left > right)
    {
        cout<<"No"<<endl;
        return;
    }
    //eg 9/2 = 4 (due to 4.5 being casted as int to 4)
    //left side will be from 0 to 4 and right side from 5 to 9
    int middle = (left + right) / 2;
    if (search_value == all.at(middle))
    {
        cout<<"Yes"<<endl;
        return;
    }
    //Equivalent to not finding it
    if (left == right)
    {
        cout<<"No"<<endl;
        return;
    }
    if (search_value < all.at(middle))
    {
        return binarySearch(0, left, middle - 1, all, search_value);
    }
    else
    {
        return binarySearch(0, middle + 1, right, all, search_value);
    }
    
}

void linearSearch (int NE, int NS, int all[], int search[])
{
    int search_value = 0;
    int all_value = 0;
    bool flag = false;
    
    for (int i = 0; i < NS; i++)
    {
        flag = false;
        search_value = search[i];
        //cout<<"search value:"<<search_value<<endl;
        
        for(int j = 0; j<NE; j++)
        {
            all_value = all[j];
            if(search_value == all_value)
            {
                //cout<<"Match found for: "<<search_value<<endl;
                cout<<"Yes"<<endl;
                flag = true;
                break;
            }
        }
        //crappy implementation where we have to always check this variable (time costing and stupid)
        //how could i have gotten rid of this flag?
        if (flag == false)
        {
            cout<<"No"<<endl;
            
        }
    }
}


int main(int argc, char **argv)
{
    
    
    int NE;  // number of elements
    int NS;  // number of element to search
    int exe_type;
    
    //changed for testing
    //TWO types of inputs. Input for testing: ./search 10 5 1
    //Input for taking in values: ./search 10 5 0
    if (argc != 4)
    {
        printf("<usage>: parameters.\n");
        return 1;
    }
    else
    {
        NE = atoi(argv[1]);
        NS = atoi(argv[2]);
        //printf("Number of elements = %d\nNumber of elements to search = %d\n", NE, NS);
        exe_type = atoi(argv[3]);
    }
    
    //Created holders for the elements
    int all_holder[NE];
    int search_holder[NS];
    
    if(exe_type == 0)
    {
        cin>>NE;
        cin>>NS;
        cout<<NE<<endl;
        cout<<NS<<endl;
        for (int a = 0;a < NE; a++)
        {
            cin>>all_holder[a];
            cout<<"all holder:"<<all_holder[a]<<endl;
        }
        for (int b = 0; b < NS; b++)
        {
            cin>>search_holder[b];
            cout<<"search holder:"<<search_holder[b]<<endl;
        }
        
        clock_t start = 0;
        clock_t finish = 0;
        double elapsed_time = 0;
        
        // Here goes the code you want to time
        // ...
        
        start = clock();
        //LINEAR SEARCH TIMING
        cout<<"Linear Search: "<<endl;
        linearSearch(NE,NS,all_holder,search_holder);
        
        //Put all array values into a vector for easy sorting
        vector<int> all_vector (all_holder, all_holder+NE);
        sort(all_vector.begin(), all_vector.begin()+NE);
        
        //        //Print out to confirm that everything was sorted
        //        //Sortingis done OUTSIDE of the timing function for BOTH BINARY AND LINEAR SEARCH
        //        for(int a=0; a<NE; a++)
        //        {
        //            cout<<"Vector value at "<<a<<": "<<all_vector.at(a)<<endl;
        //
        //        }
        finish = clock();
        elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
        cout<<"Time for LinearSearch: "<<elapsed_time<<endl;
        
        
        start = clock();
        //BINARY SEARCH TIMING
        cout<<"Binary Search: "<<endl;
        for (int a=0; a<NS; a++)
        {
            //Pasing all these variables is pretty poor programming. BinarySearch COULD just reference global variables, etc. Well maybe this isnt too bad and could be reused a little easier.
            binarySearch(NE, 0, NE-1, all_vector, search_holder[a]);
        }
        
        finish = clock();
        elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
        cout<<"Value of N: "<<NE<<endl;
        cout<<"Value of S: "<<NS<<endl;
        cout<<"Time for BinarySearch: "<<elapsed_time<<endl;
        
        return 0;
        
    }
    
    if(exe_type == 1)
    {
        
        
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
        
        start = clock();
        //LINEAR SEARCH TIMING
        cout<<"Linear Search: "<<endl;
        linearSearch(NE,NS,all_holder,search_holder);
        
        //Put all array values into a vector for easy sorting
        vector<int> all_vector (all_holder, all_holder+NE);
        sort(all_vector.begin(), all_vector.begin()+NE);
        
        //Print out to confirm that everything was sorted
        //Sortingis done OUTSIDE of the timing function for BOTH BINARY AND LINEAR SEARCH
        for(int a=0; a<NE; a++)
        {
            cout<<"Vector value at "<<a<<": "<<all_vector.at(a)<<endl;
            
        }
        finish = clock();
        elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
        cout<<"Time for LinearSearch: "<<elapsed_time<<endl;
        
        
        start = clock();
        //BINARY SEARCH TIMING
        cout<<"Binary Search: "<<endl;
        for (int a=0; a<NS; a++)
        {
            cout<<"val of binary search pass:"<<a<<endl;
            //Pasing all these variables is pretty poor programming. BinarySearch COULD just reference global variables, etc. Well maybe this isnt too bad and could be reused a little easier.
            binarySearch(NE, 0, NE-1, all_vector, search_holder[a]);
        }
        
        finish = clock();
        elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
        cout<<"Value of N: "<<NE<<endl;
        cout<<"Value of S: "<<NS<<endl;
        cout<<"Time for BinarySearch: "<<elapsed_time<<endl;
        
        return 0;
    }
    
    return 0;
    
}

