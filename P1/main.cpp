#include "SortArray.h"
int main() {
	//float a[] = { 1.4F, -5.2F, 3.3F, 0 };
	//char a[] = {'A', 'B', 'C', 'D'};

	STUDENT a[] = { {"abc", 8.5}, {"def", 9.5}, {"asd", 9.5} , {"trang", 9.0}, {"dat", 0.9}, {"quyen", 8.5}};

	int n = sizeof(a) / sizeof(a[0]);

	//SortAlgorithm<float>* alg = SortAlgorithm<float>::getObject(SortAlgorithm<float>::InterchangeSort);
	//SortAlgorithm<char>* alg = SortAlgorithm<char>::getObject(SortAlgorithm<char>::InterchangeSort);
	SortAlgorithm<STUDENT>* alg = SortAlgorithm<STUDENT>::getObject(SortAlgorithm<STUDENT>::InterchangeSort);
	alg->Sort(a, n);
	cout << "Array increasingly sorte: " << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
	}
	return 0;
}