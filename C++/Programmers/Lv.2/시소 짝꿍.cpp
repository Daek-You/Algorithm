#include <map>
#include <string>
#include <vector>
using namespace std;

const int MAX_WEIGHT = 1000;
vector<pair<int, int>> ratios { {1, 2}, {2, 3}, {3, 4} };


map<int, int> CountWeights(const vector<int>& weights)
{
    map<int, int> counts;
    for (const auto weight : weights)
        counts[weight]++;
    return counts;
}


long long FindSeesawPair(const vector<int>& weights)
{
    long long answer = 0;
    map<int, int> counts = CountWeights(weights);

    for(const auto element : counts)
    {
        long long count = element.second;
        answer += (count * (count - 1)) / 2;       // nC2 조합 공식 -> 같은 몸무게끼리인 사람들끼리 시소 짝꿍이 되는 경우의 수
        
        for (int i = 0; i < ratios.size(); i++)
        {
            long long weight = element.first;

            // weight : x = n1 : n2에서 weight를 n1으로 나눠 1의 비율로 표준화
            if (weight % ratios[i].first != 0)
                continue;

            // 구하고자 하는 x 값 계산 - > weight/n1 : x = 1 : n2
            // -> x = (weight / n1) * n2
            long long target = (weight / ratios[i].first) * ratios[i].second;
            
            // weight의 개수와 target의 개수가 주어졌을 때, 서로 이어지는 개수
            // ex) 200, 200, 400, 400, 400 -> 2 x 3 = 6
            answer += counts[target] * count;
        }
    }

    return answer;
}

long long solution(vector<int> weights) {
    long long answer = FindSeesawPair(weights);
    return answer;
}