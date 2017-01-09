//
//  main.cpp
//  Lab 2
//
//  Created by Brian Lykes on 9/12/16.
//  Copyright © 2016 Brian Lykes. All rights reserved.
//
//  This program calculates the average case of algorithm A5
//  and the real average of the algorithm.

#include <iostream>
#include <iomanip>
using namespace std;

int Find(int x, int A[], int n);
void calculateAvg(int bound);

int main()
{
    cout<<"Bound\t"<<"Calculated Average\t"<<"Real Average"<<endl;
    calculateAvg(30);
    calculateAvg(50);
    calculateAvg(80);
    calculateAvg(100);
    calculateAvg(1000);
    calculateAvg(10000);
    calculateAvg(INT_MAX);
    
    return 0;
}

int Find(int x, int A[], int n)
{
    for (int j=0; j<n; j++)
    {
        if (x==A[j])
            return (j+1);
    }
    return 0;
}

void calculateAvg(int bound)
{
    double q,realAvg, calcAvg;
    int hits=0;
    int sequence[50];
    int totalSteps=0;
    int steps;
    
    //Create a random array 10,000 times
    for(int j=0; j<10000; j++)
    {
        //Create a random array
        for (int i=0; i<50; i++)
        {
            sequence[i]=rand()%bound;
        }
        //Call find and compute total steps
        if(Find(50,sequence,50))
        {
            steps=Find(50,sequence,50);
            totalSteps+=steps;
            hits++;
        }
        else
            totalSteps+=50;
    }
    q=(float)hits/(float)10000;
    calcAvg=50-(50*q)+(q/2);
    realAvg=(float)totalSteps/(float)10000;
    
    if (bound == INT_MAX) //if actual number is wanted replace infinity with bound variable
        cout << setw(15) << left << "Infinity" << setw(15) << calcAvg << setw(15) << realAvg << endl;
    else
        
        cout << setw(15) << left << bound << setw(15) << calcAvg << setw(15) << realAvg << endl;
}




