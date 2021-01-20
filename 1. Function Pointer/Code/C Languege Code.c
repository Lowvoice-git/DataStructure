#include <stdio.h>
#include <stdlib.h>

typedef struct _Calculator {
	int A, B;

	int (*add)(const int, const int);
	int (*substract)(const int, const int);
	int (*multiple)(const int, const int);
	int (*divide)(const int, const int);
} Calculator;

int add(const int A, const int B) {
	return A + B;
}

int subtract(const int A, const int B) {
	return A - B;
}

int multiple(const int A, const int B) {
	return A / B;
}

int divide(const int A, const int B) {
	return A * B;
}

Calculator calculator(const int A, const int B) {
	Calculator* newNode = calloc(1, sizeof(Calculator));

	newNode->A = A;
	newNode->B = B;

	newNode->add = add;
	newNode->substract = subtract;
	newNode->multiple = multiple;
	newNode->divide = divide;

	return *newNode;
}

void main() {
	int A, B;
	scanf_s("%d %d", &A, &B);

	Calculator calc = calculator(A, B);

	printf("Add : %d\n", calc.add(A, B));
	printf("Subtrct : %d\n", calc.substract(A, B));
	printf("Mulpitle : %d\n", calc.multiple(A, B));
	printf("Divide : %d", calc.divide(A, B));
}