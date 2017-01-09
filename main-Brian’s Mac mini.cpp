//
//  main.cpp
//  Labs 4 & 5
//
//  Created by Brian Lykes on 10/22/16.
//  Copyright © 2016 Brian Lykes. All rights reserved.
//
//
// Project 4 & 5 - This program compares insertion Sort, merge Sort, & Heap Sort

#include <iostream>
#include<cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void insertion (int A[], int n);
void mergesort (int A[],int low, int high, int B[]);
void merge (int A[], int low, int mid, int high, int B[]);
void heapsort (int A[], int n);
void fixheap (int A[], int root, int key, int bound);

int main()
{
    cout<<"Input size"<<"\t"<<"Insertion Sort";
    cout<<"\t\t"<<"Merge Sort";
    cout<<"\t\t"<<"Heap Sort"<<endl;
    
    srand((unsigned)time(0));			//initialize random seed:
    int bound = 1000000000;
    int n=10;
    int *Sequence = new int [n];		//temporaray array for insertion sort
    int *Sequence_1 = new int [n];		//temporaray array for merge sort
    int *Sequence_2 = new int [n];
    clock_t time1, end;
    double diffIns, diffMer, diffHeap;
    
    for (int i=0; i<=5; i++)
    {
        switch (i)
        {
            case 0:
                n=100;
                break;
            case 1:
                n=1000;
                break;
            case 2:
                n=10000;
                break;
            case 3:
                n=50000;
                break;
            case 4:
                n=100000;
                break;
            case 5:
                n=200000;
                break;
            default:
                break;
        }
        int *Sequence = new int [n];
        int *Sequence_1 = new int [n];
        int *Sequence_2 = new int [n];
        for (int k=0; k<n; k++)
        {
            Sequence [k] = ( rand() % (bound + 1) ) ;		//generates random number
            Sequence_1 [k] = Sequence [k];
            Sequence_2 [k] = Sequence [k];
        }
        
        time1=clock();
        insertion (Sequence,n);
        diffIns = (clock()-time1)/ (double) CLOCKS_PER_SEC;
        end=clock();
        
        time1=clock();
        int *B=new int [n];
        mergesort (Sequence_1, 0, n-1, B);
        delete [] B;
        B= NULL;
        diffMer = (clock()-time1)/ (double) CLOCKS_PER_SEC;
        end=clock();
        
        time1=clock();
        heapsort (Sequence_2,n);
        diffHeap = (clock()-time1)/ (double) CLOCKS_PER_SEC;
        end=clock();
        
        cout << left << setw (12) << n << setw (20) << diffIns << setw (16) << diffMer << setw(15) << diffHeap << endl;
        //cout<<n<<"\t\t"<<diffIns<<"\t\t\t";
        //cout<<diffMer<<"\t\t\t"<<diffHeap<<endl;
    }
    delete [] Sequence;
    Sequence = NULL;
    delete [] Sequence_1;
    Sequence_1 = NULL;
    delete [] Sequence_2;
    Sequence_2 = NULL;
    return 0;
}

void insertion (int A[], int n)
{
    int i,j, temp;
    for (i=1; i<n; i++)
    {
        j=i;
        while ( A[j] < A[j-1])
        {
            temp=A[j];
            A[j]=A[j-1];
            A[j-1]=temp;
            j--;
        }
    }
}

void merge (int A[], int low, int mid, int high, int B[])
{
    int l=low, i=low, h=mid+1, k;
    
    while ((l <=mid) && (h <=high))
    {
        if (A[l] <=A[h])
        {
            B[i]=A[l];
            l++;
        }
        
        else
        {
            B[i]=A[h];
            h++;
        }
        i++;
    }
    
    if (l > mid)
        for (k=h; k <=high; k++)
        {
            B[i]=A[k];
            i++;
        }
    
    else
        for (k=l; k <= mid; k++)
        {
            B[i]=A[k];
            i++;
        }
    
    
    for (k=low; k <=high; k++)
    {
        A[k]=B[k];
    }
}

void mergesort (int A[ ], int low, int high, int B[])
{
    if (low < high)
    {
        int mid=(low + high)/2;
        mergesort (A,low, mid, B);
        mergesort (A, mid+1, high, B);
        merge (A,low, mid, high, B);
    }
}

void fixheap (int A[ ], int root, int key, int bound) 

{ 
    int vacant, Lgrchild; 
    bool inserted = false;  
    vacant = root; 
    while ( (2*vacant <= bound) && (!inserted) )
    { 
        Lgrchild = 2 * vacant; 
        if ( (Lgrchild < bound) && A[Lgrchild +1] > A[Lgrchild]) 																					 
            Lgrchild++;
        if ( key < A[Lgrchild] )
        { A[vacant] = A[Lgrchild];
            vacant = Lgrchild;
        }
        else 
            inserted=true;
    } 
    A[vacant] = key;
}

void heapsort (int A[ ], int n)
{
    int i, heapsize, max;
    
    for (i=n/2; i>=1; i--) 
        fixheap(A, i, A[i], n);
    for (heapsize = n; heapsize >= 2; heapsize --)
    {  
        max = A[1];						
        fixheap (A, 1, A[heapsize], heapsize-1);
        A[heapsize]=max;
    }
}
