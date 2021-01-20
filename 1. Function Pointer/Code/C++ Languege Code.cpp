#include <iostream>

using namespace std;

class Caculator {
private:
	int A, B;
public:
	Caculator(const int& A, const int& B) : A(A), B(B) {}

	int add() const { return A + B; }
	int substract() const { return A - B; }
	int multiple() const { return A * B; }
	int divide() const { return A / B; }
};

int main() {
	int A, B;
	cin >> A >> B;
	Caculator caculator(A, B);

	cout << "Add : " << caculator.add() << endl;
	cout << "Substract : " << caculator.substract() << endl;
	cout << "Multiple : " << caculator.multiple() << endl;
	cout << "Divide : " << caculator.divide() << endl;
}