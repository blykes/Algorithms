//
//  main.cpp
//  382 Lab 0
//
//  Created by Brian Lykes on 8/31/16.
//  Copyright © 2016 Brian Lykes. All rights reserved.
//
// This will show the difference in timing between reciursive and non recursive Fibinoci sequence


#include <iostream>
#include <ctime>
using namespace std;


int long long FibRec (int n);
int long long FibNonRec (int n);
int long long FibNum = 50;


int main()
{
    time_t startTimeRec, endTimeRec;
    time_t startTimeNonRec, endTimeNonRec;
    double timeDiffRec;
    double timeDiffNonRec;
   // int fibVal;
    
    cout << "\t n" << "\t" << "| Recursive" << "| Non Recursive" << "\t | Fib Value" <<endl;
    
    cout << "\t*********************************************** " << endl;
    
    for (int x = 0; x <= FibNum; x = x+5)
    {
        time (&startTimeRec);
        FibRec (x);
        time (&endTimeRec);
        timeDiffRec = difftime (endTimeRec, startTimeRec);
        
        time (&startTimeNonRec);
        FibNonRec(x);
        time (&endTimeNonRec);
        timeDiffNonRec = difftime (endTimeNonRec, startTimeNonRec);
        cout << "\t " << x << "\t| " << timeDiffRec << "\t| " << timeDiffNonRec << "\t| " << FibRec(x) << endl;
    }
    
    return 0;
    
}

long long int FibRec (int (n)) //array of size n
{
    
    if (n == 0 || n == 1)
    {
        return (n);
    }
    else
    {
        return (FibRec (n-1) + FibRec(n-2));
    }
}
            
long long int FibNonRec (int n) //array of size n
{
    int F[60];
    
    F[0]=0; F[1]=1;
    
    for (int i = 2; i <= n; i++)
    {
        F[n] = F[n-1] + F[n-2];
    }
    
    return (F[n]);
}
