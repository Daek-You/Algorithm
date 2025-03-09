import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ2792 {
    private static int N, M;
    private static int[] NumOfColors;

    public static void main(String[] args) throws Exception {

        // 1. 입력 받기
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        NumOfColors = new int[M];

        int maxJemCount = 0;
        for (int i = 0; i < M; i++) {
            NumOfColors[i] = Integer.parseInt(br.readLine());;
            maxJemCount = Math.max(maxJemCount, NumOfColors[i]);
        }

        // 2. 최소 질투심 찾기
        int left = 1, right = maxJemCount;
        int answer = maxJemCount;           // 최악의 경우: 가장 많은 한 종류의 보석 개수를 한 사람이 다 차지하는 것
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (canDistribute(mid)) {
                // 해당 질투심으로 나눠줄 수 있다면, 더 낮은 질투심 탐색
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;     // 해당 질투심으로는 나눠줄 수 없다면, 더 높은 질투심 탐색
            }
        }

        // 3. 정답 출력
        System.out.println(answer);
    }

    private static boolean canDistribute(int maxJemCountPerStudent) {
        int student = 0;
        for (int count : NumOfColors) {
            // 각 색상마다 필요한 학생 수 계산
            student += Math.ceil((double)count / maxJemCountPerStudent);
        }

        // 필요한 학생 수가 N명 이하면 가능
        return student <= N;
    }
}
