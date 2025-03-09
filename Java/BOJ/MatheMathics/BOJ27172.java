import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ27172 {
    private static int N;
    private static boolean[] Visited;
    private static int[] Cards, Scores;

    public static void main(String[] args) throws Exception {

        // 1. 입력 받기
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 1 << 16);
        N = Integer.parseInt(br.readLine());
        Cards = new int[N];
        
        // 입력으로 주어지는 수들 중에서 가장 큰 숫자 찾기
        int maxNum = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            Cards[i] = Integer.parseInt(st.nextToken());
            if (maxNum < Cards[i])  maxNum = Cards[i];
        }
        
        // 2. 각 플레이어의 카드 숫자에 대응되는 숫자 방문 체크
        Scores = new int[maxNum + 1];
        Visited = new boolean[maxNum + 1];
        for (int card : Cards)  Visited[card] = true;

        // 3. 각 플레이어의 카드 숫자와 배수 관계인 숫자들 점검
        for (int i = 0; i < N; i++) {
            for (int k = 2; Cards[i] * k <= maxNum; k++) {
                int cardNum = Cards[i] * k;
                
                // 다른 플레이어가 가진 숫자라면 점수 계산
                if (Visited[cardNum]) {
                    Scores[i]++;
                    Scores[cardNum]--;
                }
            }
        }

        // 4. 정답 출력
        StringBuilder answer = new StringBuilder();
        for (int card : Cards) answer.append(Scores[card]).append(" ");
        System.out.println(answer);
    }
}
