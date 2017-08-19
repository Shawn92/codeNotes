class MinValue {
public:
    int getMin(vector<int> arr, int n) {
        // write code here
        if (arr.size() == 0) return -1;
        if (arr.size() == 1) return arr[0];
        int l = 0, r = n - 1, mid = 0;
        while (l < r - 1) {
            if (arr[l] < arr[r]) {
                return arr[l];
            }
            mid = (l + r) / 2;
            if (arr[l] == arr[mid] && arr[mid] == arr[r]) {
                return *min_element(arr.begin() + l, arr.begin() + r + 1);
            }
            if (arr[mid] >= arr[l]) l = mid;
            else if (arr[mid] <= arr[r]) r = mid;
        }
        return arr[r];
    }
};