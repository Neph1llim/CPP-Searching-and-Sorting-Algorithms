#include <iostream>

using namespace std;

// Sorting Algorithms
void BubbleSort(int array[], int size);
void InsertionSort(int array[], int size); // temp
void SelectionSort(int array[], int size); // temp and min
void MergeSort(int array[], int size); // sub arrays, recursion
void Merge(int leftSide[], int rightSide[], int array[], int size);

//Searching Algorithms


// ui and outputs
void ShowResult(int array[], int size);

int main(){
	int array[10] = {1,9,2,8,3,7,4,6,10,5};
	int size = 	sizeof(array) / sizeof(array[0]); // calculates the size of the array
	int choice;
	bool done = false;
	
	
	cout << "Random Numbers:\n";
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	
	
	while(!done){
		
	cout << "\n\nChoose your Sorting Algorithm:\n";
	cout << "1. Bubble Sort\n";
	cout << "2. Insertion Sort\n";
	cout << "3. Selection Sort\n";
	cout << "4. Merge Sort\n";
	cout << "Your Answer: "; 
	cin >> choice;
	cout << endl;
		switch(choice){
			case 1: BubbleSort(array, size); done = true; break;
			case 2: InsertionSort(array, size); done = true; break;
			case 3: SelectionSort(array, size); done = true; break;
			case 4: MergeSort(array, size); done = true; break;
			default: cout << "Invalid Choice!"; cin.clear();fflush(stdin);
		}
	}
	
	ShowResult(array,size);
	
	return 0;
}

void BubbleSort(int array[], int size){
	for(int i = 0; i < size - 1; i++){ // outer loop
		for(int j = 0; j < size - i - 1; j++){ // inner loop
			if (array[j] >= array[j+1]){
				// swap
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;	
			}
		}
	}
}

void InsertionSort(int array[], int size){
	for(int i = 0; i < size - 1; i++){ // outer loop
		for(int j = i; j > 0 ; j--){// inner loop decrement
			if(array[j] <= array[j-1]){
				int temp = array[j-1];
				array[j-1] = array[j];
				array[j] = temp;
			}
		}
	}
}

void SelectionSort(int array[], int size){
	for(int i = 0; i < size - 1; i++){
		int min = i;
		for(int j = i + 1; j < size; j++){
			if(array[j] <= array[min]){
				min = j; // tracks the min index
			}
		}
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

void MergeSort(int array[], int size){
	
	if(size <= 1){ // base case
		return;
	}
	
	int middle = size/2;
	cout << middle << endl;
	//sub arrays based on the size 
		int *leftSide = new int[middle];
		int *rightSide = new int[size - middle];
	
	//condition
    for (int i = 0; i < middle; i++) {
        leftSide[i] = array[i];
    }
    for (int i = middle; i < size; i++) {
        rightSide[i - middle] = array[i];
    }
	
	//recursion
    MergeSort(leftSide, middle);
    MergeSort(rightSide, size - middle);
    //merging
	Merge(leftSide, rightSide, array, size);
}

void Merge(int leftSide[], int rightSide[], int array[], int size){
	int leftSize = size / 2;
	int rightSize = size - leftSize;
	
	int i = 0, l = 0, r = 0; // index for array, left, and right
	
	//merging conditions
	while(l < leftSize && r < rightSize){
		if(leftSide[l] < rightSide[r]){
			array[i] = leftSide[l];
			i++;
			l++;
		}else{
			array[i] = rightSide[r];
			i++;
			r++;
		}
	}
	while(l < leftSize){
		array[i] = leftSide[l];
		i++;
		l++;
	}
	while(r < rightSize){
		array[i] = rightSide[r];
		i++;
		r++;
	}
	
}

void ShowResult(int array[], int size){
	cout << "-------------Final Solution---------------\n\n";
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

