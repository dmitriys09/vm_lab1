#include <iostream>
#include <vector>
#include <iomanip>

const size_t row = 3;
const size_t col = 4;

using namespace std;

void show_matrix(vector<vector<float> > &a, size_t row, size_t col)
{
	cout << endl << endl;
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++)
			cout << setw(6) << a[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;
}
void Gauss_method(vector<vector<float> > &a, size_t row, size_t col) {
	float mpl = 0;//множитель
	//пр€мой ход
	for (int n = 0; n < row; n++) {
		for (int k = row; k >= n; k--)
			a[n][k] /= a[n][n];
		for (int i = 1 + n; i < row; i++) {
			mpl = a[i][n] / a[n][n];
			for (int j = 0 + n; j < col; j++)
				a[i][j] = a[i][j] - (a[n][j] * mpl);
		}
	}
	//обратный ход
	for (int n = row - 1; n >= 0; n--) {
		for (int i = 0; i < n; i++) {
			mpl = a[i][n] / a[n][n];
			a[i][n] -= a[n][n] * mpl;
			a[i][col - 1] -= a[n][col - 1] * mpl;
		}
	}
}

int main()
{
	float x[row - 1];
	vector<vector<float>> v = { { -1, 4, 2, 7 },
	{ 2, -6, -3, 10 },
	{ 2, -5, -2, -7}, };
	//поднимаем строку с самым маленьким первым элементом
	for (size_t i = 1; i < row; i++)
		if (v[0][0] > v[i][0])
			for (size_t j = 0; j < col; j++)
				swap(v[i][j], v[0][j]);	

	cout << "Matrix:" << endl;
	show_matrix(v, row, col);
	
	Gauss_method(v, row, col);
	cout << endl << "After Gauss method: " << endl;
	show_matrix(v, row, col);

	//находим корни в матрице
	for (int i = 0; i < row; i++)
		x[i] = v[i][col - 1];
	//¬ывод результата
	cout << "Answer: ";
	for (int i = 0; i < row; i++)
		cout << x[i] << " ";
	cout << endl;
	return 0;
}