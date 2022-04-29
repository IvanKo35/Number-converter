#include <iostream>
using namespace std;

int result, k, i, j;
int n = 0;
int flag = 0;
int h1 = 0, h5 = 0, h10 = 0, h50 = 0, h100 = 0, h500 = 0, h1000 = 0;
string s;

int roman[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
int nums[7] = { 1, 5, 10, 50, 100, 500, 1000 };

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите число в римских цифрах: " << endl;
	cin >> s;
	result = 0;
	i = 0;
	k = 0;
	for (j = 0; j < s.length(); j++) {
		i = 0;
		k = 0;
		while (i < 7) {

			if (s[j] == roman[i]) {
				break;
			}
			else { i++; }
		}
		while (k < 7) {

			if (s[j + 1] == roman[k]) {
				break;
			}
			else { k++; }
		}

		if (j + 1 < s.length() and nums[i] < nums[k]) {
			if (s[j] == 'I' and (s[j + 1] == 'V' or s[j + 1] == 'X')) {
				if (h1 >= 1 or result == 4 or result == 9) {
					flag = 1;
				}
				else {
					result -= nums[i];
				}
			}
			else if (s[j] == 'X' and (s[j + 1] == 'L' or s[j + 1] == 'C')) {
				if (h10 >= 1 or result == 40 or result == 90 or abs(result) % 10 > 0) {
					flag = 1;
				}
				else {
					result -= nums[i];
				}
			}
			else if (s[j] == 'C' and (s[j + 1] == 'D' or s[j + 1] == 'M')) {
				if (h100 >= 1 or result == 400 or result == 900 or abs(result) % 10 > 0) {
					flag = 1;
				}
				else {
					result -= nums[i];
				}

			}
			else {
				flag = 1;
				break;
			}
		}
		else {
			if (s[j] == s[j + 1]) {
				if (s[j] == 'I') {
					h1 += 1;
					if (h1 < 3) {
						result += nums[i];
					}
					else {
						flag = 1;
						break;
					}
				}
				else if (s[j] == 'V') {
					flag = 1;
					break;
				}
				else if (s[j] == 'X') {
					h10 += 1;
					if (h10 < 3) {
						result += nums[i];
					}
					else {
						flag = 1;
						break;
					}
				}
				else if (s[j] == 'L') {
					flag = 1;
					break;
				}
				else if (s[j] == 'C') {
					h100 += 1;
					if (h100 < 3) {
						result += nums[i];
					}
					else {
						flag = 1;
						break;
					}
				}
				else if (s[j] == 'D') {
					flag = 1;
					break;
				}
				else if (s[j] == 'M') {
					h1000 += 1;
					if (h1000 < 3) {
						result += nums[i];
					}
					else {
						flag = 1;
						break;
					}
				}
			}
			else {
				if (s[j] == 'I') {
					if (result == 4 or result == 9) {
						flag = 1;
					}
				}
				else if (s[j] == 'X') {
					if (result == 40 or result == 90 or (abs(result) % 10 > 0 and result + 11 == 100)) {
						flag = 1;
					}
				}
				else if (s[j] == 'C') {
					if (abs(result) % 10 > 0 or result == 400 or result == 900) {
						flag = 1;
					}
				}
				else if (s[j] == 'D') {
					if (abs(result) % 100 > 0) {
						flag = 1;
					}
				}
				else if (s[j] == 'M') {
					if (abs(result) % 100 > 0) {
						flag = 1;
					}
				}
				result += nums[i];
			}
		}
	}
	if (flag == 0) {
		cout << "Ваше число в арабских цифрах: " << result << endl;
	}
	else {
		cout << "Ошибка: введено неправильное число" << endl;
	}

	return 0;
}