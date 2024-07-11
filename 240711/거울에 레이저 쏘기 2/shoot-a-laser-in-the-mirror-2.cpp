#include <iostream>
#include <vector>

using namespace std;

bool IsValid(short x, short y, short size)
{
    return x >= 0 && y >= 0 && x < size && y < size;
}

int main() {
    // 여기에 코드를 작성해주세요.

    short N = 0;
    cin >> N;

    vector<vector<char>> mirrorGrid(N, vector<char>(N)); // N * N

    for (short i = 0; i < N; ++i)
    {
        for (short j = 0; j < N; ++j)
        {
            cin >> mirrorGrid[i][j];
        }
    }
    short K = 0;
    cin >> K;

    // 상 우 하 좌
    char dirXArr[4] {0, 1, 0, -1}; 
    char dirYArr[4] {-1, 0, 1, 0};

    // init Dir
    short curXPos = 0, curYPos = 0, curDir = -1/*방향배열 인겟스*/;
    if (K <= N) // 최상단
    {
        curXPos = K - 1;
        curYPos = 0;
        curDir = 2;
    }
    else if (K <= 2 * N)
    {
        curXPos = N - 1;
        curYPos = (K % N) - 1;
        curDir = 3;
    }
    else if (K <= 3 * N)
    {
        curXPos = N - (K % N);
        curYPos = N - 1;
        curDir = 0;
    }
    else
    {
        curXPos = 0;
        curYPos = N - (K % N);
        curDir = 1;
    }

    short result = 0;
    while (true)
    {
        if (IsValid(curXPos, curYPos, N) == false)
        {
            break;
        }
        ++result;
        if (mirrorGrid[curXPos][curYPos] == '/')
        {
            switch(curDir)
            {
            case 0: // 상 -> 오른쪽으로
                curXPos += 1;
                curDir = 1; // 우
                break;
            case 1: // 우 -> 아래로
                curYPos += 1;
                curDir = 2; // 하
                break;
            case 2: // 하 -> 왼쪽으로
                curXPos -= 1; 
                curDir = 3; // 좌
                break;
            case 3: // 좌 -> 상
                curXPos -= 1;
                curDir = 0; // 상
                break;
            }
        }
        else // 
        {
            switch(curDir)
            {
            case 0: // 상 -> 좌로
                curXPos -= 1;
                curDir = 3; // 좌
                break;
            case 1: // 우 -> 상
                curYPos -= 1;
                curDir = 0; // 상
                break;
            case 2: // 하 -> 우
                curXPos += 1; 
                curDir = 1; // 우
                break;
            case 3: // 좌 -> 하
                curYPos += 1;
                curDir = 2; // 하
                break;
            }
        }
    }
    cout << result;
    return 0;
}