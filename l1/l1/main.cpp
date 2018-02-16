#include <iostream>
#include <vector>
#include <iomanip>

const size_t row = 3;
const size_t col = 4;

using namespace std;

void show_matrix(vector<vector<double> > &a, size_t row, size_t col)
{
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++)
			cout << setw(5) << a[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	vector<vector<double>> v = { { 7, 2, 3, 4 },
	{ 6, 7, 8, 9 },
	{ 5, 11, 12, 13 }, };
	//поднимаем строку с самым маленьким первым элементом
	for (size_t i = 1; i < row; i++)
		if (v[0][0] > v[i][0])
			for (size_t j = 0; j < col; j++)
				swap(v[i][j], v[0][j]);
	//приводим первый элемент матрицы к единице(делим всю строку на первый элемент)
	for (int k = col - 1; k >= 0; k--) {
		v[0][k] = v[0][k] / v[0][0];
	}


	show_matrix(v, row, col);
	return 0;
}