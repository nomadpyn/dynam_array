#include<iostream>

using namespace std;

int main() {
// создаем динамический массив и заполняем его
	int size = 0;
	cout << "How many elements in array:\n";
	cin >> size;
	int* arr = new int[size] {};
	cout << "Enter elements in arr from 1 to " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << "Index " << i << ". Value ";
		cin >> arr[i];
	}
// создаем меню для работы	
	bool not_end = true;
	while (not_end) {
		cout << "What you want to do?\nYour array\n";
		for (int i = 0; i < size; i++)
				cout << arr[i] << " ";
		cout << endl;
		cout << "1 - Find sum of negative array elements\n";
		cout << "2 - Find product of array elements with odd numbers\n";
		cout << "3 - Find the sum of array elements between the first two zeros. If there are no zeros, then choose where to insert zeros\n";
		cout << "0 - End program\n";
		int choise;
		cin >> choise;
		switch (choise) {
// находим сумму отрицательных элементов массива			
		case 1: {
			int sum = 0;
			for (int i = 0; i < size; i++) {
				if (arr[i] < 0)
					sum += arr[i];
			}
			cout << "The sum of negative elements is " << sum << endl;
			break;
		}
// находим произведение элементов массива с нечетными индексами
		case 2: {
			int mult = 1;
			for (int i = 0; i < size;) {
				mult = mult * arr[i];
				i = i + 2;
			}
			cout << "The product of array elements with odd numbers is " << mult << endl;
			break;
// находим сумму элементов между двумя нулями, если их нет то создаем условие для работы		
		case 3: {
			int nul = 0, start = 0, end = 0, sum = 0;;
			for (int i = 0; i < size; i++) {
				if (arr[i] == 0)
					nul++;
			}
			switch (nul) {
			case 0: {
				cout << "There are no zeros in your array. Which elements of the array (from 1 to " << size
					<< ") insert zeros ? \n";
				cin >> start;
				start--;
				arr[start] = 0;
				cout << "Index " << start << ". Value " << arr[start] << endl;
				cin >> end;
				end--;
				arr[end] = 0;
				cout << "Index " << end << ". Value " << arr[end] << endl;;
				for (int i = start; i <= end; i++)
					sum += arr[i];
				cout << "The sum of the elements between zeros is " << sum << endl;
				break;
			}
			case 1: {
				for (int i = 0; i < size; i++) {
					if (arr[i] == 0) {
						start = i;
						break;
					}
				}
				cout << "You have one zero in the array, it is in the index " << start <<
					".Where to put the second?\n";
				cin >> end;
				end--;
				arr[end] = 0;
				cout << "Index " << end << ". Value " << arr[end] << endl;;
				for (int i = start; i < end; i++)
					sum += arr[i];
				cout << "The sum of the elements between zeros is " << sum << endl;
				break;
			}
			default: {
				for (int i = 0; i < size; i++) {
					if (arr[i] == 0) {
						start = i;
						break;
					}
				}
				for (int i = start+1; i < size; i++) {
					if (arr[i] == 0) {
						end = i;
						break;
					}
				}
				for (int i = start; i < end; i++)
					sum += arr[i];
				
				cout << "Sum of elements between zeros, in indices " << start << " and " << end << 
					" is " << sum << endl;
				break;
			}
			}
			break;
			}
// выход из программы при нажатии 0			
		case 0:
			cout << "Goodbye!\n";
			not_end = false;
			break;
// вариант на случай, если пользователь неправильно выбрал действие в меню			
		default:
			cout << "You have not chosen an action\n";
			break;
		}
		}
	delete[]arr;
	return 0;
}