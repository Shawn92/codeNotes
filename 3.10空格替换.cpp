class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        // write code here
        int spaceNums = 0;
        for (int i = 0; i < length; ++i)
            if (iniString[i] == ' ')
                ++spaceNums;
        string str = string(spaceNums * 2, ' ');
        iniString += str;
        for (int i = length - 1, j = length + 2 * spaceNums - 1; i >= 0; --i) {
            if (iniString[i] != ' ')
                iniString[j--] = iniString[i];
            else {
                iniString[j--] = '0';
                iniString[j--] = '2';
                iniString[j--] = '%';
            }
        }
        return iniString;
    }
};