#include <iostream>
#include <vector>
#include <iomanip>

const size_t row = 3;
const size_t col = 4;

using namespace std;

void show_matrix(vector<vector<float> > &a)
{
	cout.precision(2);
	cout << endl << endl;
	for (size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < col; j++)
			cout << setw(7) << a[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;
}
void Gauss_method(vector<vector<float> > &a) 
{
	float mpl = 0;//множитель
	//прямой ход
	cout << endl << "PR HOD:" << endl;
	for (int n = 0; n < row; n++) {
		for (int k = row; k >= n; k--)
			a[n][k] /= a[n][n];
		for (int i = 1 + n; i < row; i++) {
			mpl = a[i][n] / a[n][n];
			for (int j = 0 + n; j < col; j++)
				a[i][j] = a[i][j] - (a[n][j] * mpl);
		}
	}
	show_matrix(a);
	//обратный ход
	cout << endl << "OBR HOD: " << endl;
	for (int n = row - 1; n >= 0; n--) {
		for (int i = 0; i < n; i++) {
			mpl = a[i][n] / a[n][n];
			a[i][n] -= a[n][n] * mpl;
			a[i][col - 1] -= a[n][col - 1] * mpl;
		}
	}
	show_matrix(a);
}

void up_main_el(vector<vector<float> > &a)
{
	for (size_t i = 1; i < row; i++)
		if (a[0][0] < a[i][0])
			for (size_t j = 0; j < col; j++)
				swap(a[i][j], a[0][j]);
}

void find_answer(float * x, vector<vector<float> > &a)
{
	for (int i = 0; i < row; i++)
		x[i] = a[i][col - 1];
}

int main()
{
	float x[row - 1];
	vector<vector<float>> v = { { -1, -1, 1, -1 },{ 2, -1 , 2 ,3 },{ 3, -1, 1, 3 } };
	
	cout << "Matrix:" << endl;
	show_matrix(v);
	
	up_main_el(v);
	cout << endl << "After SWAP ROWS: " << endl;
	show_matrix(v);
	
	Gauss_method(v);
	cout << endl << "After Gauss method: " << endl;
	show_matrix(v);

	find_answer(x, v);
	cout << "Answer: ";
	for (int i = 0; i < row; i++)
		cout << x[i] << " ";
	cout << endl;

	return 0;
}