#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */
   
template<class T>   
void partition(T a[], int l, int r, int &i, int &j)
{
    i = l-1, j = r;
    int p = l-1, q = r;
    T v = a[r];
 
    while (true)
    {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely terminate
        // as v is last element
        while (a[++i] < v);
 
        // From right, find the first element smaller than or
        // equal to v
        while (v < a[--j])
            if (j == l)
                break;
 
        // If i and j cross, then we are done
        if (i >= j) break;
 
        // Swap, so that smaller goes on left greater goes on right
        swap(a[i], a[j]);
 
        // Move all same left occurrence of pivot to beginning of
        // array and keep count using p
        if (a[i] == v)
        {
            p++;
            swap(a[p], a[i]);
        }
 
        // Move all same right occurrence of pivot to end of array
        // and keep count using q
        if (a[j] == v)
        {
            q--;
            swap(a[j], a[q]);
        }
    }
 
    // Move pivot element to its correct index
    swap(a[i], a[r]);
 
    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i-1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);
 
    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i+1;
    for (int k = r-1; k > q; k--, i++)
        swap(a[i], a[k]);
}
 
// 3-way partition based quick sort

template<class T>
void quickSort(T a[], int l, int r)
{
    if (r <= l) return;
 
    int i, j;
 
    // Note that i and j are passed as reference
    partition(a, l, r, i, j);
 
    // Recur
    quickSort(a, l, j);
    quickSort(a, i, r);
}	

template<class T>
void writeToFile(T arr[], int length){
	ofstream myfile;
  	myfile.open ("result.txt");
  	myfile << "Sorted Array Size = " << length <<endl;
  	
	for(int m=0;m<length;m++){
		myfile << arr[m] << endl; 
                       }
	myfile.close(); 
}

int main(int argc, char *argv[])
{
	int array_size = 10000;
    int array[array_size];
    
    srand(time(NULL));
    for(int m=0;m<array_size;m++){
            array[m]=rand()%1000+1;
                       }
    quickSort(array, 0, array_size);    
	writeToFile(array,array_size);
	                  
    return EXIT_SUCCESS;
}
