package Java.BOJ.CumulativeSum;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ5549 {
    private static int N, M, K;
    private static int[][][] Maps;
    private static final char[] LABELS = {'J', 'O', 'I'};

    public static void main(String[] args) throws Exception {

        // 1. 입력 받기
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(br.readLine());
        Maps = new int[3][M + 1][N + 1];

        for (int r = 1; r <= M; r++) {
            String line = br.readLine();
            for (int c = 1; c <= N; c++) {
                for (int i = 0; i < 3; i++) {
                    int addValue = (line.charAt(c - 1) == LABELS[i]) ? 1 : 0;
                    Maps[i][r][c] = Maps[i][r - 1][c] + Maps[i][r][c - 1] - Maps[i][r - 1][c - 1] + addValue; 
                }
            }
        }

        // 2. 값 구하기
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());

            for (int j = 0; j < 3; j++) {
                int result = Maps[j][c][d] - Maps[j][a - 1][d] - Maps[j][c][b - 1] + Maps[j][a - 1][b - 1];
                answer.append(result).append(" ");
            }
            answer.append("\n");
        }

        System.out.println(answer);
    }
}
