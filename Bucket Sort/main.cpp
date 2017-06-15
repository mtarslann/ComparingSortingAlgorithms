#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <vector>
using namespace std;

template<class T>
static void bucketSort(T data[], int count) {
	T minValue = data[0];
	T maxValue = data[0];

	for (int i = 1; i < count; i++)
	{
		if (data[i] > maxValue)
			maxValue = data[i];
		if (data[i] < minValue)
			minValue = data[i];
	}

	int bucketLength = maxValue - minValue + 1;
	vector<T>* bucket = new vector<T>[bucketLength];

	for (int i = 0; i < bucketLength; i++)
	{
		bucket[i] = vector<int>();
	}

	for (int i = 0; i < count; i++)
	{
		bucket[data[i] - minValue].push_back(data[i]);
	}

	int k = 0;
	for (int i = 0; i < bucketLength; i++)
	{
		int bucketSize = bucket[i].size();

		if (bucketSize > 0)
		{
			for (int j = 0; j < bucketSize; j++)
			{
				data[k] = bucket[i][j];
				k++;
			}
		}
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
	int array_size = 50000;
    int array[array_size];
    
    srand(time(NULL));
    for(int m=0;m<array_size;m++){
            array[m]=rand()%1000+1;
                       }
                       
    bucketSort(array, array_size);    
	writeToFile(array,array_size);
	                  
    return EXIT_SUCCESS;
}
