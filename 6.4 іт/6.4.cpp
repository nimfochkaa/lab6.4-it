#include <iostream>
#include <time.h>
using namespace std;

void Create(float* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);  
    }
}

float FindMin(const float* a, const int size) {
    float minElement = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] < minElement) {
            minElement = a[i];  
        }
    }
    return minElement;
}

int FindFirstPositive(const float* a, const int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] > 0) {
            return i;  
        }
    }
    return -1; 
}

int FindLastPositive(const float* a, const int size) {
    int lastPos = -1;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0) {
            lastPos = i;  
        }
    }
    return lastPos;
}

float SumBetweenPositives(const float* a, int firstPos, int lastPos) {
    float sum = 0;
    if (firstPos == -1 || lastPos == -1 || firstPos >= lastPos) {
        return 0;  
    }
    for (int i = firstPos + 1; i < lastPos; i++) {
        sum += a[i]; 
    }
    return sum;
}

void RearrangeArray(float* a, const int size) {
    int zeroCount = 0;

    float* temp = new float[size];

    for (int i = 0; i < size; i++) {
        if (a[i] == 0) {
            temp[zeroCount++] = 0;
        }
    }

    for (int i = 0; i < size; i++) {
        if (a[i] != 0) {
            temp[zeroCount++] = a[i];
        }
    }

    for (int i = 0; i < size; i++) {
        a[i] = temp[i];
    }

    delete[] temp;
}

int main() {
    srand((unsigned)time(NULL));  
    int n;

    cout << "Enter the number of array elements: ";
    cin >> n;

    float* a = new float[n];  
    int Low = -10;
    int High = 10;

    Create(a, n, Low, High);

    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    float minElement = FindMin(a, n);
    cout << "Minimal element: " << minElement << endl;

    int firstPos = FindFirstPositive(a, n);
    int lastPos = FindLastPositive(a, n);

    if (firstPos == -1 || lastPos == -1) {
        cout << "There are not enough positive elements to calculate the sum" << endl;
    }
    else {
    
        float sum = SumBetweenPositives(a, firstPos, lastPos);
        cout << "The sum of the elements between the first and last positive ones: " << sum << endl;
    }

    RearrangeArray(a, n);

    cout << "RearrangeArray: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    delete[] a;

    return 0;
}



