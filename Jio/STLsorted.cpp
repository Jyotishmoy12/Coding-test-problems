You are given an array of N integers - A and another integer K. 
You need to sort the first K elements of A in ascending order and the remaining 
(N−K) elements in descending order.

#include <iostream>
#include <algorithm>
using namespace std;

void customSort(int arr[], int n, int k) {
    sort(arr, arr + k);
    sort(arr + k, arr + n, greater<int>());
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        int A[N];
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        customSort(A, N, K);
        for (int i = 0; i < N; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
