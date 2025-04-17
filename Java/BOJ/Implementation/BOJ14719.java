import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ14719 {
    private static int H, W;
    private static int[] blocks;

    public static void main(String[] args) throws Exception {
        // 1. 입력 받기
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        blocks = new int[W];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < W; i++) {
            blocks[i] = Integer.parseInt(st.nextToken());
        }

        // 2. 빗물의 양 계산
        int answer = 0;
        
        for (int i = 1; i < W - 1; i++) {
            // 현재 위치에서 왼쪽으로 가장 높은 블록을 찾음
            int leftMax = 0;
            for (int j = 0; j < i; j++) {
                leftMax = Math.max(leftMax, blocks[j]);
            }
            
            // 현재 위치에서 오른쪽으로 가장 높은 블록을 찾음
            int rightMax = 0;
            for (int j = i + 1; j < W; j++) {
                rightMax = Math.max(rightMax, blocks[j]);
            }
            
            // 두 블록 중 낮은 높이가 현재 위치보다 높으면 물이 고임
            int minHeight = Math.min(leftMax, rightMax);
            if (minHeight > blocks[i]) {
                answer += minHeight - blocks[i];
            }
        }

        // 3. 정답 출력
        System.out.println(answer);
    }
}
