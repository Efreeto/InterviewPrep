#include<iostream>
using namespace std;
class ShellSort{
private:
	int no_of_elements;
	int elements[10];
public:
	void getarray();
	void sortit(int[], int);
	int return_noelements();
	void display();
};
void ShellSort::getarray(){
	cout << "How many elements? ";
	cin >> no_of_elements;
	cout << "Insert array of element to sort: ";
	for (int i = 0; i<no_of_elements; i++){
		cin >> elements[i];
	}
}
int ShellSort::return_noelements(){
	return no_of_elements;
}
void ShellSort::sortit(int incrmnts[], int numinc){
	int incr, j, k, span, y;
	for (incr = 0; incr < numinc; incr++){
		span = incrmnts[incr];
		for (j = span; j < no_of_elements; j++){
			y = elements[j];
			for (k = j - span; k >= 0 && y < elements[k]; k -= span){
				elements[k + span] = elements[k];
			}
			elements[k + span] = y;
		}
		cout << "Iteration = " << incr + 1 << " Span = " << span << " : ";
		display();
		if (span == 1)
			break;
	}
}
void ShellSort::display(){
	for (int i = 0; i < no_of_elements; i++){
		cout << elements[i] << " ";
	}
	cout << endl;
}
int massin(){
	ShellSort SHS;
	int n, i, j;
	SHS.getarray();
	n = SHS.return_noelements();
	int* incrmnts = new int[n];
	for (i = n, j = 0; i > 0; i = i / 2, j++){
		incrmnts[j] = i;
	}
	SHS.sortit(incrmnts, j + 1);
	return 0;
}