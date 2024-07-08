#include <iostream>
#include <string>
using namespace std;

struct TileData
{
    short curColor = 0;  // -1 0 1 2 흰색 무색 검정 회색
    short whiteCount = 0;
    short blackCount = 0;
};

int main() {
    // 여기에 코드를 작성해주세요.
    int n = 0;
    cin >> n;

    TileData tileArr[199999];
    
    int curPoint = 100000;
    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        char c = '\0';
        cin >> x >> c;

        int iPaintColor = 0;
        int iPlusOrMinus = 1;
        if (c == 'L')
        {
            iPlusOrMinus = -1;
            iPaintColor = -1; // white
        }
        else
        {
            iPaintColor = +1; // black
        }

        
        for (int j = 0; j < x; ++j, curPoint += iPlusOrMinus)
        {
            TileData& refCurTile = tileArr[curPoint];
            if (refCurTile.curColor == 2) // 회색이면
            {
                continue;
            }

            // 회색이 되어야 하는 경우
            if (refCurTile.blackCount >= 2) // 검정 이미 2회 이상
            {
                if (refCurTile.whiteCount == 1 & iPaintColor == -1)
                {
                    refCurTile.curColor = 2; // gray
                    ++refCurTile.whiteCount;
                    continue;
                }
            }
            else if (refCurTile.whiteCount >= 2)
            {
                if (refCurTile.blackCount == 1 & iPaintColor == 1)
                {
                    refCurTile.curColor = 2; // gray
                    ++refCurTile.blackCount;
                    continue;
                }
            }

            // 그냥 덮어 칠하는 경우
            refCurTile.curColor = iPaintColor;
            if (iPaintColor == -1)
            {
                ++refCurTile.whiteCount;
            }
            else
            {
                ++refCurTile.blackCount;
            }
        }
        curPoint -= iPlusOrMinus; // x회수보다 1번 덜 이동연산 되어야 하기 때문에
    }

    int iResultWhiteCount = 0, iResultBlackCount = 0, iResultGrayCount = 0;
    for (int i = 0; i < 199999; ++i)
    {
        TileData& refCurTile = tileArr[i];
        if (refCurTile.curColor == 0) // 무색 (닿지 않은 곳)
        {
            continue;
        }

        if (refCurTile.curColor == -1) // white
        {
            ++iResultWhiteCount;
        }
        else if (refCurTile.curColor == +1) // black
        {
            ++iResultBlackCount;
        }
        else if (refCurTile.curColor == 2)
        {
            ++iResultGrayCount;
        }
    }

    cout << iResultWhiteCount << " " << iResultBlackCount << " " << iResultGrayCount;
    return 0;
}