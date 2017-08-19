class LeftMostAppearance {
public:
    int findPos(vector<int> arr, int n, int num) {
        // write code here
        if (arr.size() == 0) return -1;
        if (arr.size() == 1 && arr[0] != num) return -1;
        if (arr.size() == 1 && arr[0] == num) return 0;
        int l = 0, mid = -1, r = arr.size() - 1;
        while (l <= r) {
            mid = (r - l) / 2 + l;
            if ((arr[mid] == num && arr[mid - 1] < num) || (arr[mid] == num && mid == 0)) 
                break;
            else if ((arr[mid] == num && arr[mid - 1] == num) || arr[mid] > num)
                r = mid - 1;
            else if (arr[mid] < num)
                l = mid + 1;
        }
        if (l > r)
            return -1;
        return mid;
    }
};