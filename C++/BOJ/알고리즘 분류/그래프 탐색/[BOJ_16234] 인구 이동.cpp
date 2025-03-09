#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Position = pair<int, int>;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

vector<vector<int>> Directions { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int N, L, R;
bool CanContinue;

int SurveyPopulations(const vector<vector<int>>& populations, vector<vector<bool>>& isOpenBorder, vector<Position>& openedContries, int row, int col)
{
    queue<Position> countries;
    int numOfPopulation = populations[row][col];
    
    isOpenBorder[row][col] = true;
    countries.emplace(Position(row, col));
    openedContries.emplace_back(Position(row, col));

    while (!countries.empty())
    {
        row = countries.front().first;
        col = countries.front().second;
        countries.pop();

        for (const vector<int>& direction : Directions)
        {
            int nextRow = row + direction[0];
            int nextCol = col + direction[1];

            if (nextRow < 0 or nextRow >= N or nextCol < 0 or nextCol >= N)
                continue;
            
            if (isOpenBorder[nextRow][nextCol])
                continue;
            
            int currentCountryPopulation = populations[row][col];
            int adjacentCountryPopulation = populations[nextRow][nextCol];
            int difference = abs(currentCountryPopulation - adjacentCountryPopulation);

            if (L <= difference and difference <= R)
            {
                CanContinue = true;
                isOpenBorder[nextRow][nextCol] = true;
                numOfPopulation += adjacentCountryPopulation;

                openedContries.emplace_back(Position(nextRow, nextCol));
                countries.emplace(Position(nextRow, nextCol));
            }
        }
    }

    return numOfPopulation;
}

void MigratePopulation(vector<vector<int>>& populations, const vector<Position>& countries, const int totalPopulation)
{
    int adjustPopulation = totalPopulation / countries.size();

    for (const Position& position : countries)
    {
        int row = position.first, col = position.second;
        populations[row][col] = adjustPopulation;
    }
}

int main()
{
    FAST_IO
    cin >> N >> L >> R;

    // 1. 각 땅의 인구 수 초기화
    vector<vector<int>> populations(N, vector<int>(N));
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            cin >> populations[row][col];

    // 2. 시뮬레이션 시작    
    int day = 0;
    while (true)
    {
        CanContinue = false;
        vector<vector<bool>> isOpenBorder(N, vector<bool>(N, false));

        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                if (!isOpenBorder[row][col])
                {
                    vector<Position> openedContries;
                    int totalPopulation = SurveyPopulations(populations, isOpenBorder, openedContries, row, col);
                    MigratePopulation(populations, openedContries, totalPopulation);
                }
            }
        }

        if (!CanContinue)
            break;
        day++;
    }

    cout << day;
    return 0;
}