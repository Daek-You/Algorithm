#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int instructionNums, top = -1;
	cin >> instructionNums;
	cin.ignore();

	vector<int> stack;
	for (int i = 0; i < instructionNums; i++)
	{
		string instruction;
		getline(cin, instruction);

		if (instruction.length() >= 6)    // push 명령어만 6글자 이상이다.
		{
			stringstream targetInstruction(instruction);
			string _instruction_, data;
			targetInstruction >> _instruction_ >> data;
			
			stack.push_back(stoi(data));
			top++;
			continue;
		}

		if (instruction.compare("pop") == 0)
		{
			if (top == -1)
			{
				cout << -1 << '\n';
				continue;
			}
			cout << stack[top--] << '\n';
			stack.pop_back();
		}

		else if (instruction.compare("size") == 0)
		{
			cout << stack.size() << '\n';
		}

		else if (instruction.compare("empty") == 0)
		{
			cout << stack.empty() << '\n';
		}

		else if (instruction.compare("top") == 0)
		{
			if (top == -1)
			{
				cout << -1 << '\n';
				continue;
			}
			cout << stack[top] << '\n';
		}
	}

	return 0;
}