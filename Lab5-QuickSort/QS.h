#include <iostream>
#include <string>
#include "QSInterface.h"
using namespace std;

class QS: public QSInterface {
private:
	int* qs_array = NULL;
	int itemCount = 0;
	int maxCapacity = 0;

public:
	QS() {
		qs_array = NULL;
		itemCount = 0;
		maxCapacity = 0;
	}
	virtual ~QS() {clear();}

	void sortAll();

	void quickSort(int left, int right);
	int medianOfThree(int left, int right);
	int partition(int left, int right, int pivotIndex);
	string getArray() const;//
	int getSize() const;//
	bool addToArray(int value);//
	bool createArray(int capacity);//
	void clear();//
};

	
