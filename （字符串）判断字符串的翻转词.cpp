class Rotation {
public:
    bool chkRotation(string A, int lena, string B, int lenb) {
        // write code here
        return (A+A).find(B) != string::npos;
    }
};