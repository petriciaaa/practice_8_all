#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



inline void output(int* value1, int* value2, string article,string functionName) {
	cout << functionName << " function " << article << " swap: " << "\t"<<"&x= " << &value1 << "\t" << "&y= " << &value2 << endl;
	cout <<"\t\t\t\t"<< "x= "<<*value1<< "\t\t\t"<<"y= "<<*value2 << endl;
};


void swap(int* value1, int* value2) {
	const int temp = *value2;
	*value2 = *value1;
	*value1 = temp;
}


int main()
{
	int val1 = 5;
	int val2 = 10;

	
	output(&val1, &val2, "before","Main");
	output(&val1, &val2, "before","Swap");

	swap(&val1, &val2);

	output(&val1, &val2, "after", "Swap");
	output(&val1,&val2, "after","Main");


}
