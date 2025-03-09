#include <iostream>
#include <string>
#include <list>

using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

int main()
{
    FAST_IO
    string input;
    cin >> input;

    list<char> memo(input.begin(), input.end());
    list<char>::iterator cursor = memo.end();

    int numOfInstructions;
    cin >> numOfInstructions;

    while (numOfInstructions--)
    {
        char instruction;
        cin >> instruction;

        switch(instruction)
        {
            case 'L':
                if (cursor != memo.begin()) cursor--;
                break;

            case 'D':
                if (cursor != memo.end()) cursor++;
                break;

            case 'B':
                if (cursor != memo.begin())
                {
                    cursor--;
                    cursor = memo.erase(cursor);
                }
                break;

            case 'P':
                char character;
                cin >> character;

                memo.insert(cursor, character);
                break;
        }
    }

    for (auto it = memo.begin(); it != memo.end(); ++it)
        cout << *it;

    return 0;
}