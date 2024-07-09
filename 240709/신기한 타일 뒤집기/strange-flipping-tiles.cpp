#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n = 0;
    cin >> n;

    int colorArr[200001] {}; // -1 0 1 , white gray black
    int curPoint = 100000;
    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        char c = '\0';
        cin >> x >> c;

        int iPlusOrMinus = +1;
        if (c == 'L')
        {
            iPlusOrMinus = -1;
        }
        for (int j = 0; j < x; ++j)
        {
            colorArr[curPoint] = iPlusOrMinus;
            curPoint += iPlusOrMinus;
        }
        curPoint -= iPlusOrMinus;
    }

    int whiteCount = 0, blackCount = 0;
    for (int i = 0; i < 200001; ++i)
    {
        if (colorArr[i] == -1)
        {
            ++whiteCount;
            continue;
        }
        if (colorArr[i] == 1)
        {
            ++blackCount;
        }
    }

    cout << whiteCount << " " << blackCount;
    return 0;
}