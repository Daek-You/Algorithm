package Java.BOJ.CumulativeSum;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ21758 {
    private static int N;
    private static int[] honey;
    private static int[] prefixSum;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        honey = new int[N + 1];
        prefixSum = new int[N + 1];
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            honey[i] = Integer.parseInt(st.nextToken());
            prefixSum[i] = prefixSum[i - 1] + honey[i];
        }

        int answer = 0;
        
        // 벌통이 제일 오른쪽에 있는 경우
        for (int i = 2; i < N; i++) {
            // 벌1(왼쪽 끝)이 모은 꿀 + 벌2(i 위치)가 모은 꿀
            int total = (prefixSum[N] - honey[1] - honey[i]) + (prefixSum[N] - prefixSum[i]);
            answer = Math.max(answer, total);
        }
        
        // 벌통이 제일 왼쪽에 있는 경우
        for (int i = 2; i < N; i++) {
            // 벌1(오른쪽 끝)이 모은 꿀 + 벌2(i 위치)가 모은 꿀
            int total = (prefixSum[N] - honey[N] - honey[i]) + (prefixSum[i] - honey[i]);
            answer = Math.max(answer, total);
        }

        // 벌통이 중간에 있는 경우
        for (int i = 2; i < N; i++) {
            // 벌1(왼쪽 끝)이 모은 꿀 + 벌2(오른쪽 끝)이 모은 꿀
            int total = (prefixSum[i] - honey[1]) + (prefixSum[N] - prefixSum[i-1] - honey[N]);
            answer = Math.max(answer, total);
        }

        System.out.println(answer);
    }
}