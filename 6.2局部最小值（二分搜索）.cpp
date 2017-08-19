class Solution {
public:
    int getLessIndex(vector<int> arr) {
        int l = 0, r = arr.size() - 1;
        if (arr.size()==0) return -1;
        if (arr.size() == 1)
            return 0;
        if (arr[l] < arr[l + 1])
            return l;
        if (arr[r] < arr[r - 1])
            return r;
        int mid = -1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
                break;
            else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
                l = mid;
            else
                r = mid;
        }
        return mid;
    }
};