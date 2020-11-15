#include "QS.h"
using namespace std;

void QS::quickSort(int left, int right) {
/*
	bool sorted;
	for (int i=0; i<itemCount-1; i++) {
		if(qs_array[i] <= qs_array[i+1]){
			cout << i;
			sorted = true;
		} else {
			sorted = false;
			break;
		}
	}
	*/
	//cout<<getArray()<< " " << endl;
    if (left < right) {
			//cout<< left << " || " << right << endl;
        int pivot = medianOfThree(left, right);
				cout << pivot;
        pivot = partition(left, right, pivot);
				cout << pivot;
				quickSort(left, pivot-1);
				quickSort(pivot+1, right);
				
    }
}

void QS::sortAll() {
	quickSort(0, itemCount-1);
}

	/*
	* medianOfThree()
	*
	* The median of three pivot selection has two parts:
	*
	* 1) Calculates the middle index by averaging the given left and right indices:
	*
	* middle = (left + right)/2
	*
	* 2) Then bubble-sorts the values at the left, middle, and right indices.
	*
	* After this method is called, data[left] <= data[middle] <= data[right].
	* The middle index will be returned.
	*
	* Returns -1 if the array is empty, if either of the given integers
	* is out of bounds, or if the left index is not less than the right
	* index.
	*
	* @param left
	* 		the left boundary for the subarray from which to find a pivot
	* @param right
	* 		the right boundary for the subarray from which to find a pivot
	* @return
	*		the index of the pivot (middle index); -1 if provided with invalid input
	*/
int QS::medianOfThree(int left, int right) {

//	cout << getArray() << " || " << left << " " << right << " && " << itemCount<< endl;

	if(itemCount == 0 || qs_array == NULL) {
		return(-1);
	}
	if(left < 0 || right >= itemCount || left >= right ) {
		return(-1);
	}

	if(left==right){
		return(-1);
	}

	if(right == itemCount){
		return(-1);
	}

	int middle = -999;
	middle = (left + right) / 2;

/*
	if(middle==right || middle ==left ){
		return(-99);
	}
*/
	if(qs_array[left] > qs_array[middle]) {
		int temp = qs_array[left];
		qs_array[left] = qs_array[middle];
		qs_array[middle] = temp;
	}

	if(qs_array[left] > qs_array[right]) {
	int temp = qs_array[left];
	qs_array[left] = qs_array[right];
	qs_array[right] = temp;
	}
	

	if(qs_array[middle] > qs_array[right]) {
		int temp = qs_array[middle];
		qs_array[middle] = qs_array[right];
		qs_array[right] = temp;
	}

	return(middle);

}

	/*
	* Partitions a subarray around a pivot value selected according to
	* median-of-three pivot selection.  Because there are multiple ways to partition a list,
	* we will follow the algorithm on page 611 of the course text when testing this function.
	*
	* The values which are smaller than the pivot should be placed to the left
	* of the pivot; the values which are larger than the pivot should be placed
	* to the right of the pivot.
	*
	* Returns -1 if the array is null, if either of the given integers is out of
	* bounds, or if the first integer is not less than the second integer, or if the
	* pivot is not within the sub-array designated by left and right.
	*
	* @param left
	* 		the left boundary for the subarray to partition
	* @param right
	* 		the right boundary for the subarray to partition
	* @param pivotIndex
	* 		the index of the pivot in the subarray
	* @return
	*		the pivot's ending index after the partition completes; -1 if
	* 		provided with bad input
	*/
int QS::partition(int left, int right, int pivotIndex) {

	if(itemCount == 0 || qs_array==NULL) {
		return(-1);
	}
	if(left < 0 || right >= itemCount || left >= right) {
		return(-1);
	}
	if(pivotIndex > right || pivotIndex < left){
		return(-1);
	}

//Step 1
	//pivotIndex = medianOfThree(left, right);

//Step 2

	int tempValue;

	tempValue = qs_array[pivotIndex];
	qs_array[pivotIndex] = qs_array[left];
	qs_array[left] = tempValue;
	
//Step 3

	int up = left;
	int down = right;

	do
	{

		while ((qs_array[up] <= qs_array[left]) && (up < right)) {
			++up;
			//cout << up << " && " << down << endl;
		}

		while ((qs_array[down] >= qs_array[left]) && (down >= up)) {
			--down;
			//cout << down << " || " << qs_array[down] << endl;
		}
		//cout << getArray() << "  && ";
		//cout << qs_array[up] << " || " << qs_array[down] << endl;
		if(up < down) {
			//cout << "Swap";
			//cout<< getArray() << endl;
			tempValue = qs_array[up];
			qs_array[up] = qs_array[down];
			qs_array[down] = tempValue;
		}
	}
	while(up < down);

	tempValue = qs_array[left];
	qs_array[left] = qs_array[down];
	qs_array[down] = tempValue;
/*
	if(qs_array[down] == qs_array[right]){
		return(right);
	}*/
	return(down);

}

	/*
	* Produces a comma delimited string representation of the array. For example: if my array
	* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
	* with no trailing comma.  The number of cells included equals the number of values added.
	* Do not include the entire array if the array has yet to be filled.
	*
	* Returns an empty string, if the array is NULL or empty.
	*
	* @return
	*		the string representation of the current array
	*/
string QS::getArray() const {

	if(itemCount!=0){
		string tempString;
			for(int i =0; i<itemCount;i++){
					tempString += to_string(qs_array[i]);
					tempString += ',';
			}

		tempString.pop_back();

	return(tempString);
		} else {
			return("");
	}
}

	/*
	* Returns the number of elements which have been added to the array.
	*/
int QS::getSize() const {
	return(itemCount);
}

	/*
	* Adds the given value to the end of the array starting at index 0.
	* For example, the first time addToArray is called,
	* the give value should be found at index 0.
	* 2nd time, value should be found at index 1.
	* 3rd, index 2, etc up to its max capacity.
	*
	* If the array is filled, do nothing.
	* returns true if a value was added, false otherwise.
	*/
bool QS::addToArray(int value) {

	if(itemCount < maxCapacity){
		qs_array[itemCount] = value;
		itemCount++;
		return(true);
	} else {
		return(false);
	}
}

	/*
	* Dynamically allocates an array with the given capacity.
	* If a previous array had been allocated, delete the previous array.
	* Returns false if the given capacity is non-positive, true otherwise.
	*
	* @param
	*		size of array
	* @return
	*		true if the array was created, false otherwise
	*/
bool QS::createArray(int capacity) {

maxCapacity = capacity;

	if (capacity <= 0) {
		return(false);
	}

	if(qs_array!=NULL){
		clear();
		createArray(capacity);
	}

	qs_array = new int [capacity];
	return(true);
}

	/*
	* Resets the array to an empty or NULL state.
*/

	
void QS::clear() {

	int *temp = qs_array;
	delete [] temp;
	qs_array = NULL;
	itemCount = 0;
	maxCapacity = 0;
	
}