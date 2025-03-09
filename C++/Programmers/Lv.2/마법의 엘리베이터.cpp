#include <string>
using namespace std;
const int HALF_NUM = 5;
const int divider = 10;

bool IsWillGoUp(int quotient, int remainder) {
    if (remainder == HALF_NUM) {
        int nextRemainder = quotient % divider;
        return nextRemainder >= HALF_NUM;
    }
    return remainder > HALF_NUM;
}


int solution(int storey) {
    int magicStoneCount = 0;

    while (true) {
        int quotient = storey / divider;
        int remainder = storey % divider;
        bool isWillGoUp = IsWillGoUp(quotient, remainder);

        int direction = isWillGoUp ? 1 : -1;
        int moveDistance = min(10 - remainder, remainder);

        storey += (moveDistance * direction);
        magicStoneCount += moveDistance;

        int nextFloorQuotient = storey / divider;
        if (nextFloorQuotient == 0)
            break;

        storey = nextFloorQuotient;
    }

    return magicStoneCount;
}