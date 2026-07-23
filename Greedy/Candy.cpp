class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> arr(n, 1);

        for (int i = 0; i < n - 1; i++) {
            if (ratings[i] == ratings[i + 1]) {
                continue;
            }
            if (ratings[i + 1] > ratings[i]) {
                arr[i + 1] = arr[i] + 1;
            } else if (arr[i] == arr[i + 1]) {
                arr[i + 1] = arr[i];
                arr[i]++;
                for (int j = i - 1; j >= 0; j--) {
                    if (ratings[j] > ratings[j + 1]) {
                        if (arr[j + 1] < arr[j]) {
                            break;
                        }
                        arr[j]++;
                    }
                }
            }
        }

        return accumulate(arr.begin(), arr.end(), 0);
    }
};
