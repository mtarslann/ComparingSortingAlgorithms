#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>

using namespace std;
template<class T>
void insertionSort(T arr[], int length) {
  int i;
     for(i=1;i<length;i++)
     {
             T t=arr[i];
             int j;
             for(j=i-1;j>=0&&t<arr[j];j--)
             {
                arr[j+1]=arr[j];
             }
             arr[j+1]=t;
     }
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
	int array_size = 1000;
    int array[array_size];
    
    srand(time(NULL));
    for(int m=0;m<array_size;m++){
            array[m]=rand()%1000+1;
                       }
                
    
	insertionSort(array, array_size);
	writeToFile(array,array_size);
	                  
    return EXIT_SUCCESS;
}
