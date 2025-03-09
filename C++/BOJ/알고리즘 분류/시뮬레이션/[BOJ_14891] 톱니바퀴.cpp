#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define S '1'
#define LEFT_INTERLOCKING_TOOTH 6
#define RIGHT_INTERLOCKING_TOOTH 2
#define GEARWHELL_COUNT 4
#define DIRECTION_COUNT 8

int CalculatedPoint(const vector<string>& gearWheels)
{
    int totalPoint = 0;
    for (int i = 1; i <= 4; i++)
        if (gearWheels[i][0] == S)
            totalPoint += 1 << (i - 1);

    return totalPoint;
}

void RotateGearWheels(vector<string>& gearWheels, vector<bool>& visited, const int gearId, const int direction)
{
    visited[gearId] = true;
    int leftGearWheelId = gearId - 1, rightGearWheelId = gearId + 1;

    if (1 <= leftGearWheelId and !visited[leftGearWheelId])
    {
        if (gearWheels[leftGearWheelId][RIGHT_INTERLOCKING_TOOTH] != gearWheels[gearId][LEFT_INTERLOCKING_TOOTH])
            RotateGearWheels(gearWheels, visited, leftGearWheelId, -direction);
    }

    if (rightGearWheelId <= 4 and !visited[rightGearWheelId])
    {
        if (gearWheels[rightGearWheelId][LEFT_INTERLOCKING_TOOTH] != gearWheels[gearId][RIGHT_INTERLOCKING_TOOTH])
            RotateGearWheels(gearWheels, visited, rightGearWheelId, -direction);
    }

    int rotationCount = 0, toothId = 0;
    char previousMagneticPole = gearWheels[gearId][toothId];
    char temp;

    while (rotationCount < DIRECTION_COUNT)
    {
        int nextToothId = (toothId + DIRECTION_COUNT + direction) % DIRECTION_COUNT;
        temp = gearWheels[gearId][nextToothId];

        gearWheels[gearId][nextToothId] = previousMagneticPole;
        previousMagneticPole = temp;
        toothId = nextToothId;
        rotationCount++;
    }
}

int main()
{
    FAST_IO

    vector<string> gearWheels(GEARWHELL_COUNT + 1);
    for (int i = 1; i <= GEARWHELL_COUNT; i++)
        cin >> gearWheels[i];

    int K;
    cin >> K;

    while (K--)
    {
        int gearWheelNumber, rotationDirection;
        cin >> gearWheelNumber >> rotationDirection;

        vector<bool> visited(GEARWHELL_COUNT + 1, false);
        RotateGearWheels(gearWheels, visited, gearWheelNumber, rotationDirection);
    }

    cout << CalculatedPoint(gearWheels);
    return 0;
}