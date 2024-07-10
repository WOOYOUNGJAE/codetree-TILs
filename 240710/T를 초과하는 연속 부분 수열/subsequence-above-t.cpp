#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n = 0, t = 0;
    cin >> n >> t;

    int curLength = 0;  
    int lengthMax = 0;
    for (int i = 0; i < n; ++i)
    {
        int num = 0;
        cin >> num;

        if (num > t)
        {
            ++curLength;
            if (curLength > lengthMax)
            {
                lengthMax = curLength;
            }
        }
        else
        {
            curLength = 0;
        }
    }

    cout << lengthMax;
    
    return 0;
}