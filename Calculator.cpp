/*
	Calculator App by Quoc Khanh
	- Các bạn có thể update thêm vài chức năng tính toán nhé
*/
#pragma warning( disable : 6387; once : 4385; error : 164 ; disable : 4267 ; warning : 69)
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<conio.h>
#include<iomanip>
#include<algorithm>

using namespace std;

int A, B;
const int sizeN = 100;
bool act = false;
vector<int>bin;
vector<int>dec;
vector<int>oct;
vector<int>hex;

void input() {
	cout << "\40\40INPUT\n";
	cout << "Number A : ";
	cin >> A;
	cout << "Number B :";
	cin >> B;
}
void RESULT() {
	cout << "Result = ";
}
void SUM() {
	cout << A + B << endl;
}
void SUB() {
	cout << A - B << endl;
}
void MUL() {
	cout << A * B << endl;
}
void DIV() {
	if (B == 0)
		cout << "ERROR DIVISION BY ZERO!!!" << endl;
	else
		cout << fixed << setprecision(3) << (double)A / B << endl;
}
void MOD() {
	cout << A % B << endl;
}
void BIN() {
	int inp;
	cout << "Enter a decimal number :";
	cin >> inp;


	while (inp > 0) {
		bin.push_back(inp % 2);
		inp /= 2;
	}

	sort(bin.begin(), bin.end(), greater<int>());
	RESULT();
	for (auto& i : bin) {
		cout << i;
	}
}
void DEC() {
	char bin[sizeN];
	cout << "Enter a binary number :";
	cin >> bin;
	int dec_value = 0;
	int base = 1;
	auto len = strlen(bin);
	for(int i = len - 1; i >= 0; i--) {
		if (bin[i] == '1')
			dec_value += base;
		base = base * 2;
	}
	RESULT();
	cout << dec_value << endl;
}
void OCT() {
	int deciNum;
	cout << "Enter a decimal number :";
	cin >> deciNum;
	int octalNum = 0, countval = 1;

	while (deciNum != 0) {
		int remainder = deciNum % 8;
		octalNum += remainder * countval;
		countval = countval * 10;
		deciNum /= 8;
	}
	RESULT();
	cout << octalNum << endl;
}
void HEX() {
	int n;
	cout << "Enter a decimal number :";
	cin >> n;
	string ans = "";

	while (n != 0) {
		int rem = 0;
		char ch;
		rem = n % 16;
		if (rem < 10) {
			ch = rem + 48;
		}
		else {
			ch = rem + 55;
		}
		ans += ch;
		n = n / 16;
	}
	size_t i = 0, j = ans.size() - 1;
	while (i <= j)
	{
		swap(ans[i], ans[j]);
		i++;
		j--;
	}
	RESULT();
	cout << ans << endl;
}
void ACSII() {
	int inp;
	cout << "Enter a integer number :";
	cin >> inp;

	char convert = '0' + inp;
	RESULT();
	cout << convert << endl;
}
void menu() {
	int c;
	cout << "\40\40Calculator App\n"
		<< "==================\n"
		<< "1.Summation\n"
		<< "2.Subtraction\n"
		<< "3.Multiplication\n"
		<< "4.Division\n"
		<< "5.Modulo\n"
		<< "6.Convert Binary\n"
		<< "7.Convert Decimal\n"
		<< "8.Convert Octal\n"
		<< "9.Convert Heximal\n"
		<< "10.Convert ACSII\n"
		<< "==================\n"
		<< "Choose:";
	cin >> c;
	switch (c) {
	case 1:
		input();
		RESULT();
		SUM();
		break;
	case 2:
		input();
		RESULT();
		SUB();
		break;
	case 3:
		input();
		RESULT();
		MUL();
		break;
	case 4:
		input();
		RESULT();
		DIV();
		break;
	case 5:
		input();
		RESULT();
		MOD();
		break;
	case 6:
		BIN();
		break;
	case 7:
		DEC();
		break;
	case 8:
		OCT();
		break;
	case 9:
		HEX();
		break;
	case 10:
		ACSII();
		break;
	default:
		break;
	}
}
int main() {
	char c;
	do {
		system("cls");
		menu();
		c = _getch();
	} while (c != '\n');
}