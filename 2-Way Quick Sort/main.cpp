#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
using namespace std;
template<class T>
void quickSort(T arr[], int left, int right) {
      int i = left, j = right;
      T tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
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
	int array_size = 50000;
    int array[array_size];
    
    srand(time(NULL));
    for(int m=0;m<array_size;m++){
            array[m]=rand()%1000+1;
                       }
                       
    quickSort(array, 0, array_size);    
	writeToFile(array,array_size);
	                  
    return EXIT_SUCCESS;
}
