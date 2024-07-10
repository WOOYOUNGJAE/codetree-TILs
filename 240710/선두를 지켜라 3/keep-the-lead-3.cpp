#include <iostream>
using namespace std;

#define FLAG_NONE 0
#define FLAG_A 1
#define FLAG_B 2
#define FLAG_AB 3

int main() {
    // 여기에 코드를 작성해주세요.
    int N = 0, M = 0;
    cin >> N >> M;

    int distancePerTimeA[1000]{};
    int distancePerTimeB[1000]{};

    int timeIndex = 0;
    for (int i = 0; i < N; ++i)
    {
        int v = 0, t = 0;
        cin >> v >> t;

        for (int j = 0; j < t; ++j, ++timeIndex)
        {
            if (timeIndex == 0)
            {
                distancePerTimeA[0] = v;
            }
            distancePerTimeA[timeIndex] = distancePerTimeA[timeIndex - 1] + v;
        }
    }
    int totalTime = --timeIndex;

    timeIndex = 0;
    for (int i = 0; i < M; ++i)
    {
        int v = 0, t = 0;
        cin >> v >> t;

        for (int j = 0; j < t; ++j, ++timeIndex)
        {
            if (timeIndex == 0)
            {
                distancePerTimeB[0] = v;
            }
            distancePerTimeB[timeIndex] = distancePerTimeB[timeIndex - 1] + v;
        }
    }

    int ePrevFlag = FLAG_NONE;
    timeIndex = 0;
    int result = 0;
    for (int i = 0; i < totalTime; ++i, ++timeIndex)
    {
        int eCurFlag = FLAG_NONE;

        if (distancePerTimeA[timeIndex] > distancePerTimeB[timeIndex])
        {
            eCurFlag = FLAG_A;
        }
        else if (distancePerTimeA[timeIndex] < distancePerTimeB[timeIndex])
        {
            eCurFlag = FLAG_B;
        }
        else
        {
            eCurFlag = FLAG_AB;
        }

        if (eCurFlag != ePrevFlag)
        {
            ++result;
            ePrevFlag = eCurFlag;
        }
    }
    cout << result;
    return 0;
}