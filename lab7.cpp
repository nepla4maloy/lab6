
#include <iostream>
using namespace std;

const int MAXN = 100000;

void insertSort(int arr[], int n) {
    
    for (int i = 1; i < n; ++i) {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = x;
    }
}

int main() {
    int n;
    int arr[MAXN];

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    
    insertSort(arr, n);

    int totalCost = 0;
    int size = n;

    while (size > 1) {
        
        int a = arr[0];
        int b = arr[1];
        int sum = a + b;
        totalCost += sum;

        
        for (int i = 2; i < size; ++i)
            arr[i - 2] = arr[i];

        size -= 2;

        
        int i = size - 1;
        while (i >= 0 && arr[i] > sum) {
            arr[i + 1] = arr[i];
            --i;
        }
        arr[i + 1] = sum;
        ++size;
    }

    cout << totalCost << endl;
    return 0;
}
