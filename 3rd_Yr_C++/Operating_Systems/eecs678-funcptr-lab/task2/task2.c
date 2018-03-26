#include <stdio.h>
#include <stdlib.h>

int add (int a, int b);
int subtract (int a, int b);
int multiply (int a, int b);
int divide (int a, int b);

int (*arr_func_ptrs[4]) (int a, int b);

int main (void)
{
	int a;
	int b;
	int function;
	int answer;

	printf("Operand 'a' : ");
	scanf("%d", &a);
	printf(" | Operand 'b' : ");
	scanf("%d", &b);
	puts("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide): ");
	scanf("%d", &function);

	arr_func_ptrs[0] = add;
	arr_func_ptrs[1] = subtract;
	arr_func_ptrs[2] = multiply;
	arr_func_ptrs[3] = divide;

	answer = (arr_func_ptrs[function](a, b));

	printf("x = %d\n", answer);

	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding 'a' and 'b'\n"); return a + b; }
int subtract (int a, int b) { printf ("Subtracting 'a' and 'b'\n"); return a - b; }
int divide (int a, int b) { printf ("Dividing 'a' and 'b'\n"); return a / b; }
int multiply (int a, int b) { printf ("Multiplying 'a' and 'b'\n"); return a * b; }
