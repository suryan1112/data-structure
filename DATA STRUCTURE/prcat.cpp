#include<bits/stdc++.h>
using namespace std;

string findPairWithBitwiseAnd(const vector<int>& arr, int x) {
    unordered_set<int> seen;
    int complement = ~x;

    for (int num : arr) {
        if (seen.count(complement))
            return "yes";

        int res = num;
        for (int seenNum : seen) {
            res |= seenNum;

            if (res == x)
                return "yes";
        }

        seen.insert(num);
    }

    return "no";
}

int main() {
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Enter the target integer: ";
    cin >> x;

    string result = findPairWithBitwiseAnd(arr, x);
    cout << "Pair exists? " << result << endl;

    return 0;
}
// 1 7 3 4 2 13