import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ13422 {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder answer = new StringBuilder();

        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
            
            // 각 집의 돈 입력 받기
            st = new StringTokenizer(br.readLine());
            int[] moneies = new int[N];
            for (int i = 0; i < N; i++) moneies[i] = Integer.parseInt(st.nextToken());

            // 1 ~ M번째 집까지의 돈의 총 액수 구하기
            int totalMoney = 0;
            for (int i = 0; i < M; i++) totalMoney += moneies[i];
            int numOfCases = (totalMoney < K) ? 1 : 0;

            // Sliding window
            if (N != M) {       // N == M일 땐 1가지 경우만 나오므로
                for (int left = 0; left < N - 1; left++) {
                    totalMoney -= moneies[left];             // 맨 왼쪽 제외
                    totalMoney += moneies[(left + M) % N];   // 맨 오른쪽 추가
    
                    // K원을 넘지 않을 경우에만 가능한 경우의 수 추가
                    if (totalMoney < K) numOfCases++;
                }
            }

            // 정답 저장
            answer.append(numOfCases).append("\n");
        }

        // 정답 출력
        System.out.println(answer);
    }
}
