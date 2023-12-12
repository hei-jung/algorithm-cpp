#include <iostream>
#include <queue>
#include <cstring> //memset

using namespace std;

int N, M;
int graph[300][300] = {0};
bool visited[300][300];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int melt(int x, int y) // 빙산 녹는 과정
{
    int ocean_cnt = 0; // 접해있는 바다
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && graph[nx][ny] == 0 && !visited[nx][ny])
        {
            ocean_cnt++;
        }
    }
    return max(0, graph[x][y] - ocean_cnt);
}

void bfs(int x, int y) // 덩어리 개수
{
    queue<pair<int, int>> q;

    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && graph[nx][ny] != 0 && !visited[nx][ny])
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main()
{
    init();

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }

    int year = 0; // 시간
    while (1)
    {
        // 빙산 덩어리 개수
        int cnt = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (graph[i][j] != 0 && !visited[i][j])
                {
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        if (cnt > 1)
        {
            cout << year;
            break;
        }
        // 빙산 녹기
        bool flag = true;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (graph[i][j] != 0)
                {
                    flag = false;
                    visited[i][j] = true;
                    graph[i][j] = melt(i, j);
                }
            }
        }
        year++;
        if (flag) // 빙산이 다 녹음
        {
            cout << 0;
            break;
        }
    }

    return 0;
}
