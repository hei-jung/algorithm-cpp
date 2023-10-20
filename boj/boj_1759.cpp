#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::ios;
using std::sort;
using std::string;

int L, C;
char arr[15];
int dp[15] = {0};

void init()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int check(string pw)
{
    int vowel_cnt = 0;
    int cons_cnt = 0;
    for (int i = 0; i < L; i++)
    {
        if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u')
        {
            vowel_cnt++;
        }
        else
        {
            cons_cnt++;
        }
        if (vowel_cnt >= 1 && cons_cnt >= 2) // 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성되어 있다
        {
            return 1;
        }
    }
    return 0;
}

void bt(int idx, int cnt, string pw)
{
    if (cnt == L)
    {
        if (check(pw) == 0)
        {
            return;
        }
        cout << pw << "\n";
        return;
    }
    for (int i = idx; i < C; i++) // 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열 (=> idx)
    {
        if (dp[i] == 0)
        {
            dp[i] = 1;
            bt(i, cnt + 1, pw + arr[i]);
            dp[i] = 0;
        }
    }
}

int main()
{
    init();
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + C);
    bt(0, 0, "");
    return 0;
}
