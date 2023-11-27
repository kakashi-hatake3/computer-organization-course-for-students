# include <iostream>


using namespace std;


void celoe(unsigned long n, int (&arr)[sizeof(n) * 8]) {
	if (n < 0) {
		n += 1;
	}
	for (int i = sizeof(n) * 8 - 1; i >=0; i--) {
		arr[i] = n & 1;
		n >>= 1;
	}
}

void invert_c(unsigned long n, int (&arr)[sizeof(n) * 8], int index) {
	if (arr[index]) {
		arr[index] = 0;
	}
	else {
		arr[index] = 1;
	}
}

void doubleToBits(double value, int(&arr)[sizeof(double) * 8]) {
	unsigned char* bytes = reinterpret_cast<unsigned char*>(&value);

	for (int i = sizeof(double) - 1; i >= 0; --i) {
		unsigned char byte = bytes[i];

		for (int j = 7; j >= 0; --j) {
			arr[(sizeof(double) - i - 1) * 8 + (7 - j)] = (byte >> j) & 1;
		}
	}
}

void invert_dr(double n, int(&arr)[sizeof(double) * 8], int index) {
	if (arr[index]) {
		arr[index] = 0;
	}
	else {
		arr[index] = 1;
	}
	
}

unsigned long binaryToUnsignedLong(int arr[], int size) {
	unsigned long result = 0;

	for (int i = 0; i < size; i++) {
		result = (result << 1) | arr[i];
	}

	return result;
}

double backToDecimalDouble(int bits[64]) {
	unsigned long long result = 0;

	for (int i = 0; i < 64; i++) {
		result = (result << 1) | bits[i];
	}

	double* decimal = reinterpret_cast<double*>(&result);
	return *decimal;
}

void main(){
	unsigned long n;	
	double d;
	int ch, count;
	cout << "Input unsigned long number:" << endl;
	cin >> n;
	cout << "Input double number:" << endl;
	cin >> d;
	int arr_n[sizeof(n) * 8];
	int arr_d[sizeof(double) * 8];
	cout << "Unsigned long in bits: " << endl;
	celoe(n, arr_n);
	for (int i = 0; i < sizeof(n) * 8; i++) {
		cout << arr_n[i];
	}
	cout << endl;

	cout << "Double in bits: " << endl;
	doubleToBits(d, arr_d);
	for (int i = 0; i < sizeof(double) * 8; i++) {
		if (i == 1 || i == 12) {
			cout << " ";
		}
		cout << arr_d[i];
	}
	cout << endl;

	cout << "In what number do you want to invert the bits? (1 - UL, 2 - D)" << endl;
	cin >> ch;
	cout << "Enter count of bits: " << endl;
	cin >> count;
	if (ch == 1) {
		int index;
		for (int i = 0; i < count; i++) {
			cin >> index;
			invert_c(n, arr_n, index);
		}
		cout << "Unsigned long in bits after invert: " << endl;
		for (int i = 0; i < sizeof(n) * 8; i++) {
			cout << arr_n[i];
		}
		cout << endl;
	}
	else {
		int index;
		for (int i = 0; i < count; i++) {
			cin >> index;
			invert_dr(d, arr_d, index);
		}
		cout << "Double in bits after invert: " << endl;
		for (int i = 0; i < sizeof(double) * 8; i++) {
			if (i == 1 || i == 12) {
				cout << " ";
			}
			cout << arr_d[i];
		}
	}

	cout << endl;
	cout << "Unsigned long after algo: " << endl;
	cout << binaryToUnsignedLong(arr_n, 32) << endl;
	cout << "Double after algo: " << endl;
	cout << backToDecimalDouble(arr_d) << endl;
}
