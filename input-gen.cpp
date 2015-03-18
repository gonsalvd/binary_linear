/**
    Input generator for the Search Problem

    Commands:
        $g++ input-gen.cpp -o generator
        $./generator 1000000 100 > input-1m.in


**/

#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

void setGen(int NE, int NS)
{
    // Initializing seed for pseudo-random sequence
    srand(time(NULL));

    printf("%d %d\n", NE, NS);
    for (int i=1; i<=NE; i++)
    {
        int number;

        number = rand();
        // coin toss
        double r = ((double) rand() / (RAND_MAX));

        if (r < 0.05)           // Introducing neg. numbers with 5% probability
            number = - number;
        printf("%d ", number);
        
        cout<<"here1"<<endl;

        if (!(i % 100)) printf("\n");
    }
    printf("\n");
    for (int i=1; i<=NS; i++)
    {
        int number;

        number = rand();
        // coin toss
        double r = ((double) rand() / (RAND_MAX));

        if (r < 0.05)           // Introducing neg. numbers with 5% probability
            number = - number;
        printf("%d ", number);
        cout<<"here2"<<endl;

        if (!(i % 100)) printf("\n");
    }

    return 0;
}
