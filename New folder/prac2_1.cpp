#include <bits/stdc++.h>
using namespace std;

struct Metrics {
    unsigned long long comparison = 0;
    unsigned long long ops = 0;
    unsigned long long call = 0;
};
int iterativeLinearSearch(int arr[], int n, int target, Metrics &m) {
    m.comparison = 0;
    m.ops = 0;
    m.call = 0;

    for (int i = 0; i < n; i++) {
        m.comparison++;
        if (arr[i] == target)
            return i;

        m.ops++;
    }

    return -1;
}

int recursiveLinearSearch(int arr[], int n, int target, int index, Metrics &m1) {
    m1.call++;
    m1.comparison++;

    if (index >= n)
        return -1;

    m1.comparison++;
    if (arr[index] == target)
        return index;

    m1.ops++;

    return recursiveLinearSearch(arr, n, target, index + 1, m1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int target = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    Metrics m;

    int a = iterativeLinearSearch(arr, n, target, m);

    cout << "Iterative Index : " << a << endl;
    cout << "Comparison : " << m.comparison << endl;
    cout << "Operations : " << m.ops << endl;

    cout << "------------------------" ;

    Metrics m1;

    int b = recursiveLinearSearch(arr, n, target, 0, m1);

    cout << "Recursive Index : " << b << endl;
    cout << "Comparison : " << m1.comparison << endl;
    cout << "Operations : " << m1.ops << endl;
    cout << "Function Calls : " << m1.call << endl;

    return 0;
}
