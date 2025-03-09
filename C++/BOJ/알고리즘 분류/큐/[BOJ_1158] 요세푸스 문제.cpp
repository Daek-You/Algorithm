#include <iostream>
#include <queue>
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
using namespace std;

int main()
{
    FAST_IO

    int N, K;
    cin >> N >> K;

    int count = 1;
    queue<int> people;
    for (int i = 1; i <= N; i++)
        people.emplace(i);


    cout << "<";
    while (!people.empty())
    {
        if (count != K)
        {
            int front = people.front();
            people.push(front);
            people.pop();

            count++;
            continue;
        }

        cout << people.front();
        people.pop();

        if (!people.empty())
            cout << ", ";
        count = 1;
    }

    cout << ">";
    return 0;
}
