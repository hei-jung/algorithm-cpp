#include <iostream>
#include <vector>
using namespace std;
#define max(a, b) a > b ? a : b

int N = 0;
vector<vector<int>> board;
int answer = 0;

vector<vector<int>> up(vector<vector<int>> board)
{
    for (int c = 0; c < N; c++)
    {
        int r = 0;
        for (int i = 0; i < N; i++)
        {
            if (board[i][c] != 0)
            {
                int tmp = board[i][c];
                board[i][c] = 0;

                if (board[r][c] == 0)
                {
                    board[r][c] = tmp;
                }
                else if (board[r][c] == tmp)
                {
                    board[r][c] += tmp;
                    r++;
                }
                else
                {
                    r++;
                    board[r][c] = tmp;
                }
            }
        }
    }
    return board;
}

vector<vector<int>> down(vector<vector<int>> board)
{
    for (int c = 0; c < N; c++)
    {
        int r = N - 1;
        for (int i = N - 1; i >= 0; i--)
        {
            if (board[i][c] != 0)
            {
                int tmp = board[i][c];
                board[i][c] = 0;

                if (board[r][c] == 0)
                {
                    board[r][c] = tmp;
                }
                else if (board[r][c] == tmp)
                {
                    board[r][c] += tmp;
                    r--;
                }
                else
                {
                    r--;
                    board[r][c] = tmp;
                }
            }
        }
    }
    return board;
}

vector<vector<int>> left(vector<vector<int>> board)
{
    for (int r = 0; r < N; r++)
    {
        int c = 0;
        for (int i = 0; i < N; i++)
        {
            if (board[r][i] != 0)
            {
                int tmp = board[r][i];
                board[r][i] = 0;

                if (board[r][c] == 0)
                {
                    board[r][c] = tmp;
                }
                else if (board[r][c] == tmp)
                {
                    board[r][c] += tmp;
                    c++;
                }
                else
                {
                    c++;
                    board[r][c] = tmp;
                }
            }
        }
    }
    return board;
}

vector<vector<int>> right(vector<vector<int>> board)
{
    for (int r = 0; r < N; r++)
    {
        int c = N - 1;
        for (int i = N - 1; i >= 0; i--)
        {
            if (board[r][i] != 0)
            {
                int tmp = board[r][i];
                board[r][i] = 0;

                if (board[r][c] == 0)
                {
                    board[r][c] = tmp;
                }
                else if (board[r][c] == tmp)
                {
                    board[r][c] += tmp;
                    c--;
                }
                else
                {
                    c--;
                    board[r][c] = tmp;
                }
            }
        }
    }
    return board;
}

void bt(vector<vector<int>> board, int depth)
{
    if (depth == 5)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                answer = max(answer, board[i][j]);
            }
        }
        return;
    }
    bt(up(board), depth + 1);
    bt(down(board), depth + 1);
    bt(left(board), depth + 1);
    bt(right(board), depth + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    board = vector(N, vector<int>(N));
    // vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    bt(board, 0);
    cout << answer << "\n";
    return 0;
}