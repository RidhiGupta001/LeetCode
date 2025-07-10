#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> generateNextPalindrome(int num[], int n) {
        vector<int> digits(num, num + n);

        // Handle the special case where all digits are 9
        bool allNine = true;
        for (int d : digits) {
            if (d != 9) {
                allNine = false;
                break;
            }
        }
        if (allNine) {
            vector<int> res(n + 1, 0);
            res[0] = 1;
            res[n] = 1;
            return res;
        }

        // Step 1: Mirror left to right
        vector<int> result = digits;
        int i = 0, j = n - 1;
        while (i < j) {
            result[j] = result[i];
            i++;
            j--;
        }

        // Step 2: Compare to original
        bool greater = false;
        for (int k = 0; k < n; ++k) {
            if (result[k] > digits[k]) {
                greater = true;
                break;
            } else if (result[k] < digits[k]) {
                break;
            }
        }

        // Step 3: If mirrored number not greater, increment middle and mirror again
        if (!greater) {
            int mid = n / 2;
            int carry = 1;

            if (n % 2 == 1) {
                result[mid] += 1;
                carry = result[mid] / 10;
                result[mid] %= 10;
                i = mid - 1;
                j = mid + 1;
            } else {
                i = mid - 1;
                j = mid;
            }

            while (i >= 0 && carry) {
                result[i] += carry;
                carry = result[i] / 10;
                result[i] %= 10;
                result[j] = result[i];
                i--;
                j++;
            }

            if (carry) {
                result.insert(result.begin(), 1);
                result.push_back(1);
            }
        }

        return result;
    }
};
