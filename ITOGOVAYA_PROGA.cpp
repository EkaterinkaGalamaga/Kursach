#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int number; 
	cout << "Enter digit 1 to enter matrix elements; digit 2 to create a matrix with random elements.\n";
step1:
	cin >> number;
	if (number != 1 && number != 2)
	{
		cout << "Enter 1 or 2!\n";
		goto step1;
	}
	if (number == 2) {
		int N = rand() % 10 + 2;
		int mas[N][N];
		int i, j;
		srand(time(0));
		cout << "The matrix is generated: \n";
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				mas[i][j] = rand() % 21 - 2;
				cout << mas[i][j] << "\t";
			}
			cout << "\n";
		}
		cout << "\n";
		//-------------------------------------------------------------------------------
	
		int sum = 0, count = 0, sum_2 = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (mas[i][j] < 0) count += 1;
			}
			if (count == 0) {
				for (j = 0; j < N; j++) {
					sum = sum + mas[i][j];
				}
				count = 0;
				cout << "Line amount ¹ " << i + 1 << " = " << sum << "\n";
				sum_2 += sum;
				sum = 0;
			}
			if (count > 0) {
				for (j = 0; j < N; j++)
					count = 0;
				cout << "Line amount " << i + 1 << " has a negative number, skip it...\n";
			}
		}
		cout << "\nThe total sum of row elements that do not contain negative numbers: " << sum_2 << "\n";
		cout << "\n";
		//--------------------------------------------------------------------------------------
		int summa[N]; 
		memset(summa, 0, sizeof(summa));
		int k;
		for (k = 0; k < N - 1; k++) {
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (i + j == k) summa[k] += mas[i][j];
				}
			}
			cout << summa[k] << "\n";
		}
		//-------------------------------------------------------------------------------------
		if (k = N - 1) cout << "Side diagonal, skip...\n";
		//-------------------------------------------------------------------------------------
		for (k = N - 1; k < N * 2 - 2; k++) { 
			summa[k] = 0;
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (i + j == k + 1) summa[k] += mas[i][j];
				}
			}
			cout << summa[k] << "\n";
		}
		//-------------------------------------------------------------------------------------
		int min1 = summa[0];
		for (k = 0; k < N; k++) {
			if ((k != N / 2 - 1) && min1 > summa[k]) min1 = summa[k];
		}
		int min2 = summa[0];
		for (k = N - 1; k < N * 2 - 2; k++) {
			if ((k != N * 2 - 1) && min2 > summa[k]) min2 = summa[k];
		}
		if (min1 < min2)
			cout << "Minimum amount on the diagonals = " << min1 << "\n";
		else
			cout << "Minimum amount on the diagonals = " << min2 << "\n";
	}

	if (number == 1) {
		int n;
		cout << "Enter the number of rows (columns) of the square matrix:";
		cin >> n;
		int i, j;
		int N = (int) n;
		int mas[N][N];
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("Element[%d][%d] = ", i + 1, j + 1);
				scanf("%d", &mas[i][j]);
			}
		}
		printf("\n-----------------------\n");
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++)
				printf((j < (N - 1)) ? "%d\t" : "%d\n", mas[i][j]);
		}
		//Sums of elements of each row of the matrix
		int sum = 0, count = 0, sum_2 = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (mas[i][j] < 0) count += 1;
			}
			if (count == 0) {
				for (j = 0; j < N; j++) {
					sum = sum + mas[i][j];
				}
				count = 0;
				cout << "Line amount " << i + 1 << " = " << sum << "\n";
				sum_2 += sum;
				sum = 0;
			}
			if (count > 0) {
				for (j = 0; j < N; j++)
					count = 0;
				cout << "Line amount " << i + 1 << " has a negative number, skip it...\n";
			}
		}
		cout << "\nThe total sum of row elements that do not contain negative numbers:" << sum_2 << "\n";
		cout << "\n";
		//--------------------------------------------------------------------------------------
		int summa[N]; 
		memset(summa, 0, sizeof(summa));
		int k;
		for (k = 0; k < N - 1; k++) {
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (i + j == k) summa[k] += mas[i][j];
				}
			}
			cout << summa[k] << "\n";
		}
		//--------------------------------------------------------------------------------------
		if (k = N - 1) cout << "Side diagonal, skip...\n";
		//--------------------------------------------------------------------------------------
		for (k = N - 1; k < N * 2 - 2; k++) { 
			summa[k] = 0;
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					if (i + j == k + 1) summa[k] += mas[i][j];
				}
			}
			cout << summa[k] << "\n";
		}
		//-----------------------------------------------------------------------------------------
		int min1 = summa[0]; 
		for (k = 0; k < N; k++) {
			if ((k != N / 2 - 1) && min1 > summa[k]) min1 = summa[k];
		}
		int min2 = summa[0]; 
		for (k = N - 1; k < N * 2 - 2; k++) {
			if ((k != N * 2 - 1) && min2 > summa[k]) min2 = summa[k];
		}
		if (min1 < min2)
			cout << "Minimum amount on the diagonals = " << min1 << "\n";
		else
			cout << "Minimum amount on the diagonals = " << min2 << "\n";
	}
}
