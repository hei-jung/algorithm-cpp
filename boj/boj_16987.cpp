#include <iostream>

using std::cin;
using std::cout;
using std::ios;

int N;          // 계란의 수
int S[8] = {0}; // 계란의 내구도
int W[8] = {0}; // 계란의 무게
int answer = 0;

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int max(int a, int b)
{
    return a >= b ? a : b;
}

void bt(int i, int cnt)
{
    if (i == N) // 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료
    {
        answer = max(answer, cnt);
        return;
    }
    if (S[i] <= 0 || cnt == N - 1) // 손에 든 계란 깨졌을 경우, 안 깨진 계란 없을 경우
    {
        bt(i + 1, cnt); // 다음 계란(한 칸 오른쪽) 선택
        return;
    }
    for (int j = 0; j < N; j++)
    {
        if (j == i)
        {
            continue;
        }
        if (S[j] <= 0) // 깨진 계란이면 안 치고 패스
        {
            continue;
        }
        S[i] -= W[j];
        S[j] -= W[i];
        bt(i + 1, cnt + (S[i] <= 0) + (S[j] <= 0)); // 깨진 계란 개수 갱신
        S[i] += W[j];
        S[j] += W[i];
    }
}

int main()
{
    init();

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i] >> W[i];
    }

    bt(0, 0);
    cout << answer << "\n";

    return 0;
}
