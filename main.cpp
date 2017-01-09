//
//  main.cpp
//  Lab 3
//
//  Created by Brian Lykes on 9/21/16.
//  Copyright © 2016 Brian Lykes. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

int long long InsertionMod (int A[ ], int n);	//calculates # of steps calculated
void calculateResult (int n);		//finds calculated real and calculated average

using namespace std;

int main()
{
    cout<<"Input size" <<"\t\t" <<"Calculated Average" "\t\t" "Real Average" <<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    calculateResult(100);
    calculateResult(500);
    calculateResult(1000);
    calculateResult(2500);
    calculateResult(3000);
    calculateResult(3500);
    
    return 0;
}

void calculateResult (int n)
{
    srand((unsigned)time(0));
    
    long int calculatedAverage, realAverage;
    calculatedAverage = ( (pow((long double)n,2)/4) + (3*(long double)n/4) );
    
    int bound = 500;
    int long long total_steps = 0;
    int *Sequence;
    Sequence = new int [n];
    for (int k=0; k<100000; k++)
    {
        for (int i=0; i<n; i++)
            Sequence [i] = ( rand() % (bound + 1) ) ;
        
        int find = InsertionMod (Sequence,n);
        total_steps+=find;
    }
    realAverage = total_steps/100000;
    cout << left << setw (18) << n << setw (24) << calculatedAverage << realAverage << endl;
    Sequence = NULL;
    delete [] Sequence;
};

int long long InsertionMod (int A[ ], int n)

{
    int i,j, temp;
    int count=0;
    A[0]=-32768;
    for (i=1; i<=n; i++)
    {
        j=i;
        while ( A[j] < A[j-1])
        {							 
            temp=A[j];
            A[j]=A[j-1];
            A[j-1]=temp;
            j--;
            count++;
        }
        count++;
    }
    return count;
};
