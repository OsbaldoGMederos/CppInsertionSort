#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// Prototypes
int getArraySize();
void insertionSort(int a[], int);
void printArray(int[], int);
void fillArray(int[], int);


int main(){

	int size = getArraySize();
	int a[size];

	clock_t start;
	clock_t end;
	double timeElapsed;

	fillArray(a, size);

	cout << "Unsorted elements: " << endl;
	printArray(a,size);

	start = clock();

	insertionSort(a, size);

	end = clock();

	cout << "Sorted elements: " << endl;
	printArray(a, size);

	timeElapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	cout << "Sorting took " << timeElapsed << " seconds" << endl;
	
	return 0;
}


// function definitions

int getArraySize() {
	int size;

	cout << "We are going to fill the array with random numbers from 1 to 1000" << endl;
	cout << "How many elements should we insert? ";
	cin >> size;
	cin.ignore();

	return size;
}

void fillArray(int a[], int size){

	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist(1, 1000);

	for(int i = 0; i < size; i++) {
		a[i] = dist(rng);
	}

}

void insertionSort(int a[], int size) {

	for(int i = 1; i < size; i++) {

		int key = a[i];
		int j = i - 1;

		while(j > -1 and a[j] > key) {
			a[j+1] = a[j];
			j--;
		}

		a[j+1] = key;

	}
}

void printArray(int a[], int size) {

	for(int i = 0; i < size; i++) {
		cout << a[i] << ((i+1) == size ? "\n" : ", ");
	}
}

