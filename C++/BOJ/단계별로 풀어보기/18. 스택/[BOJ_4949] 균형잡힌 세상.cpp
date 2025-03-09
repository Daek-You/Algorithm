#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

int main() {
	cout.tie(NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	map<char, char> oppositeParenthesis{ {')', '('}, {']', '['} };

	while (true)
	{
		stack<char> parenthesises;
		string sentence;
		getline(cin, sentence, '.');

		if (sentence.empty())
			break;

		bool isValidCase = true;

		for (const auto character : sentence)
		{
			if ((character == '(') or (character == '['))
				parenthesises.push(character);

			else if (!parenthesises.empty() and (character == ')' or character == ']'))
			{
				if (parenthesises.top() != oppositeParenthesis[character])
				{
					isValidCase = false;
					break;
				}
				parenthesises.pop();
			}
			
			else if ((character == ')' or character == ']'))
			{
				isValidCase = false;
				break;
			}
		}

		if (!parenthesises.empty() or !isValidCase)
			cout << "no" << '\n';
		else
			cout << "yes" << '\n';
		
		cin.ignore(2, '\n');   // '\n' 두 글자를 버퍼에서 제거해줘야 다음 입력 맨 앞에 '\n'이 안 들어간다.
	}


	return 0;
}