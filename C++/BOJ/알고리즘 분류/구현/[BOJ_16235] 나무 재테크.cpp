#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Point = pair<int, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int N, M, K;
vector<vector<int>> AddingEnergies;
vector<vector<int>> Energies;
vector<vector<vector<int>>> Ages;
vector<Point> Directions { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

void Initialize()
{
    cin >> N >> M >> K;
    AddingEnergies.resize(N + 1, vector<int>(N + 1));
    Energies.resize(N + 1, vector<int>(N + 1, 5));    // 초기 영양분 값은 5
    Ages.resize(N + 1, vector<vector<int>>(N + 1, vector<int>()));

    for (int row = 1; row <= N; row++)
        for (int column = 1; column <= N; column++)
            cin >> AddingEnergies[row][column];

    for (int i = 0; i < M; i++)
    {
        int row, column, age;
        cin >> row >> column >> age;
        Ages[row][column].push_back(age);
    }
}

void SpringAndSummer()
{
    for (int row = 1; row <= N; row++)
    {
        for (int column = 1; column <= N; column++)
        {
            if (Ages[row][column].empty())
                continue;
            
            int deadTreeEnergy = 0;
            vector<int> temp;
            sort(Ages[row][column].begin(), Ages[row][column].end());

            for (const int age : Ages[row][column])
            {
                if (age <= Energies[row][column])
                {
                    Energies[row][column] -= age;
                    temp.push_back(age + 1);
                    continue;
                }

                deadTreeEnergy += (age / 2);
            }

            Ages[row][column].clear();
            for (const int age : temp)
                Ages[row][column].push_back(age);
            
            Energies[row][column] += deadTreeEnergy;
        }
    }
}

void Autumn()
{
    for (int row = 1; row <= N; row++)
    {
        for (int column = 1; column <= N; column++)
        {
            if (Ages[row][column].empty())
                continue;
            
            for (const int age : Ages[row][column])
            {
                if (age % 5 == 0)
                {
                    for (const Point& direction : Directions)
                    {
                        int nextRow = row + direction.first;
                        int nextColumn = column + direction.second;

                        if (nextRow < 1 or nextRow > N or nextColumn < 1 or nextColumn > N)
                            continue;
            
                        Ages[nextRow][nextColumn].push_back(1);
                    }
                }
            }
        }
    }
}

void Winter()
{
    for (int row = 1; row <= N; row++)
        for (int column = 1; column <= N; column++)
            Energies[row][column] += AddingEnergies[row][column];
}

int main()
{
    FAST_IO
    Initialize();

    for (int i = 0; i < K; i++)
    {
        SpringAndSummer();
        Autumn();
        Winter();
    }

    int answer = 0;
    for (int row = 1; row <= N; row++)
        for (int column = 1; column <= N; column++)
            answer += Ages[row][column].size();

    cout << answer;
    return 0;
}