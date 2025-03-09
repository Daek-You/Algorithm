import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ10836 {
    private static int M, N;
    private static int[] EdgeMap;

    public static void main(String[] args) throws Exception {

        // 1. 입력 받기
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        
        EdgeMap = new int[2 * M - 1];   // 가장자리 애벌레들의 개수는 2M - 1
        Arrays.fill(EdgeMap, 1);    // 모든 애벌레들의 초기 크기는 1

        // 2. N일 동안 가장 자리 애벌레들의 성장 기록하기
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int idx = 0, growUpValue = 0; growUpValue < 3; growUpValue++) {
                int count = Integer.parseInt(st.nextToken());
                // 가장자리 애벌레 키우기
                while (count-- > 0) EdgeMap[idx++] += growUpValue;
            }
        }

        // 3. 정답 출력
        printAnswer();
    }

    private static void printAnswer() {
        // 가장 왼쪽 열을 제외한 나머지 열은 맨 위 행의 열 값과 같다 (수진이 풀이의 힌트)
        // why? 애벌레 성장 방향이 맨 왼쪽 아래 -> 위 -> 오른쪽으로 가는데, "감소하지 않는다"라고 했기 때문
        StringBuilder answer = new StringBuilder();
        
        // 첫 번째 행 출력
        for (int c = 0; c < M; c++) {
            int value = (c == 0) ? EdgeMap[M - 1] : EdgeMap[M - 1 + c];
            answer.append(value).append(" ");
        }
        answer.append("\n");

        // 나머지 2번째 행부터 출력
        for (int r = 1; r < M; r++) {
            // 각 행의 첫 번째 열 (가장자리)
            answer.append(EdgeMap[M - 1 - r]).append(" ");

            //각 행의 나머지 열들
            for (int c = 1; c < M; c++) {
                answer.append(EdgeMap[M - 1 + c]).append(" ");
            }

            answer.append("\n");
        }

        System.out.println(answer);
    }
}