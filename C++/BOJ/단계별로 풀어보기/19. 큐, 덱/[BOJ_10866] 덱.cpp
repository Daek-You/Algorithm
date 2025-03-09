#include <iostream>
#include <string>
#include <map>
#include <deque>
using namespace std;

enum class Instruction
{
	PUSH_FRONT,
	PUSH_BACK,
	POP_FRONT,
	POP_BACK,
	SIZE,
	EMPTY,
	FRONT,
	BACK
};

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	map<string, Instruction> instructions
	{ {"push_front", Instruction::PUSH_FRONT},
	  {"push_back", Instruction::PUSH_BACK},
	  {"pop_front", Instruction::POP_FRONT},
	  {"pop_back", Instruction::POP_BACK},
	  {"size", Instruction::SIZE},
	  {"empty", Instruction::EMPTY},
	  {"front", Instruction::FRONT},
	  {"back", Instruction::BACK}
	};
	int n;
	cin >> n;
	
	deque<int> answer;
	for (int i = 0; i < n; i++)
	{
		string instruction;
		cin >> instruction;

		switch (instructions[instruction])
		{
			int data;
		case Instruction::PUSH_FRONT:
			cin >> data;
			answer.push_front(data);
			break;

		case Instruction::PUSH_BACK:
			cin >> data;
			answer.push_back(data);
			break;

		case Instruction::POP_FRONT:
			if (answer.empty())
				cout << -1 << '\n';
			else
			{
				cout << answer.front() << '\n';
				answer.pop_front();
			}
			break;

		case Instruction::POP_BACK:
			if (answer.empty())
				cout << -1 << '\n';
			else
			{
				cout << answer.back() << '\n';
				answer.pop_back();
			}
			break;

		case Instruction::SIZE:
			cout << answer.size() << '\n';
			break;

		case Instruction::EMPTY:
			cout << answer.empty() << '\n';
			break;

		case Instruction::FRONT:
			if (answer.empty())
				cout << -1 << '\n';
			else
			{
				cout << answer.front() << '\n';
			}			
			break;

		case Instruction::BACK:
			if (answer.empty())
				cout << -1 << '\n';
			else
			{
				cout << answer.back() << '\n';
			}
			break;
		}
	}
	
	return 0;
}