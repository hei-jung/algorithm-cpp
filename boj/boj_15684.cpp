#include <iostream>

using std::cin;
using std::cout;

int n, m, h;
int grid[31][11] = {0};
int ans = 4;

int sadari(void)
{
    int idx;
    for (int j = 1; j < n + 1; j++)
    {
        idx = j;
        for (int i = 1; i < h + 1; i++)
        {
            // 가로선이 있니?
            if (grid[i][idx] == 1)
            {
                idx++;
            }
            else if (grid[i][idx - 1] == 1)
            {
                idx--;
            }
        }
        if (idx != j)
        {
            return 0;
        }
    }
    return 1;
}

void dfs(int idx, int cnt)
{
    if (sadari() == 1)
    {
        ans = ans < cnt ? ans : cnt;
    }
    else if (cnt == 3 || ans <= cnt)
    {
        return;
    }
    for (int i = idx; i < h + 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == 0 && grid[i][j - 1] == 0 && grid[i][j + 1] == 0)
            {
                grid[i][j] = 1;
                dfs(i, cnt + 1);
                grid[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    int a, b;
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        // b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다
        cin >> a >> b; // 가로선 정보 (1 ≤ a ≤ H, 1 ≤ b ≤ N-1)
        grid[a][b] = 1;
    }
    dfs(1, 0);
    cout << (ans < 4 ? ans : -1) << "\n";
}