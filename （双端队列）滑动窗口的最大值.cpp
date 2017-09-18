class SlideWindow {
public:
    vector<int> slide(vector<int> arr, int n, int w) {
        // write code here
        deque<int> window;
        vector<int> vec;
        for (int i = 0; i < w - 1; ++i) {
            while (!window.empty() && arr[i] > arr[window.back()])
                window.pop_back();
            window.push_back(i);
        }

        for (int i = w - 1; i < n; ++i) {
            while (!window.empty() && arr[i] > arr[window.back()])
                window.pop_back();
            window.push_back(i);
            while (i - window.front() >= w)
                window.pop_front();
            vec.push_back(arr[window.front()]);
        }
        return vec;
    }
};