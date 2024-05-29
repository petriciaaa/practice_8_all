#include <iostream>


int factorial(int num) {
	if (num==1 || num==2)
	{
		return num;
	}
	return factorial(num - 1) * num;
}

int sumOfSeries(int num) {
	if (!num)
	{
		return num;}
	return sumOfSeries(num - 1) +num;
}
int countOfNums(int num) {
	int counter = 0;

	for (int i = 1; i <= num; i++)
	{
		!(i % 3 )? counter ++: NULL;
	}
	return counter;
}

int main()
{
	int val;
	int(*func)(int);

	std::cout << "Enter a number ";
	std::cin >> val;

	func = factorial;
	std::cout <<"Factorial " << func(val) << std::endl;

	func = sumOfSeries;	
	std::cout << "Sum of numbers between 1 and " <<val<<" = " << func(val) << std::endl;

	func = countOfNums;
	std::cout << "Count of numbers between 1 and  " << val << " that divisible by 3 = " << func(val)<<std::endl;

	return 0;
}