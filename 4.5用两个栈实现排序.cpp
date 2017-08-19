class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        // write code here
        vector<int> stackTemp;
        while(numbers.size() > 0) {
            int temp = numbers[0];
            numbers.erase(numbers.begin());
            while (stackTemp.size() > 0 && stackTemp[0] < temp) {
                int temp2 = stackTemp[0];
                stackTemp.erase(stackTemp.begin());
                numbers.insert(numbers.begin(), temp2);
            }
            stackTemp.insert(stackTemp.begin(), temp);
        }
        while (stackTemp.size() > 0) {
            int temp = stackTemp[0];
            stackTemp.erase(stackTemp.begin());
            numbers.insert(numbers.begin(), temp);
        }
        return numbers;
    }
};