#include <iostream>

void fillArray(int* arr1, int* arr2, int** result, const int length) {
    for (int i = 0; i < length; i++) {
        result[0][i] = arr1[i] + arr2[i];
        result[1][i] = arr1[i] - arr2[i];
        result[2][i] = arr1[i] * arr2[i];
    }
}


void printArray(int** arr, int rows,int cols) {
    std::cout << std::endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << arr[i][j]<<"\t";
        }
        std::cout <<std::endl;
    }
    std::cout << std::endl;
}   
void printArray(int* arr,const int lenght) {
   
        for (int i= 0; i < lenght; i++)
        {
            std::cout << arr[i]<<"\t";
        }
        std::cout <<std::endl;
    
}   
void printInfo(int** arr, int rows) {
    for (int i = 0; i < rows; i++)
    {
        std::cout << i + 1 << " row: " << "adress: " << &arr[i] << " value: " << *arr[i] << std::endl;
    }
}


int main() {
    
    const int LENGTH = 5;
    int arr1[] = {0,1,2,3,4};
    int arr2[] = {5,6,0,7,1};

    int rows = 3;
    int cols = 5;

    std::cout << "Initial arrays"<<std::endl;
    printArray(arr1, LENGTH);
    printArray(arr2, LENGTH);

    
    //arr of pointers, pRes - pointer
    int** pRes = new int*[rows];
    std::cout << std::endl << "Memory allocated for pointer array: " << "adress: "<<&pRes<<" value: "<<*pRes<< std::endl << std::endl;


    for (int i = 0; i < rows; i++)
    {
        pRes[i] = new int[cols];
        std::cout << "Memory allocated for "<<i+1<<" row"<< std::endl;
    }

    //printInfo
    printInfo(pRes, rows);

   
    fillArray(arr1, arr2, pRes, LENGTH);
    printArray(pRes, rows, cols);


    std::cout << "Memory for pointer array: " << "adress: " << &pRes << " value: " << *pRes<<std::endl  << std::endl;


    //printInfo
    printInfo(pRes, rows);



    for (int i = 0; i < rows; i++)
    {
        std::cout << "Memory for " << i+1 << " row is cleared" << std::endl;
        delete  pRes[i];

    }

    //printInfo
    printInfo(pRes, rows);
    
    //delete poinetrs array
    delete [] pRes;

    std::cout << std::endl << "Memory for pointers array is cleared" << std::endl;
    return 0;
}