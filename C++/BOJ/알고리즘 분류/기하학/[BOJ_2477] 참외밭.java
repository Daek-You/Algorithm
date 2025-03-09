import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ2477 {
    private static int K;
    private static int[] Lengths;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int K = Integer.parseInt(br.readLine());
        Lengths = new int[6];

        // 1:동쪽, 2:서쪽, 3:남쪽, 4:북쪽
        int maxHorizontalLength = 0, maxVerticalLength = 0;
        int maxHorizontalIndex = -1, maxVerticalIndex = -1;

        for (int i = 0; i < 6; i++) {
            String[] input = br.readLine().split(" ");
            int direction = Integer.parseInt(input[0]);
            Lengths[i] = Integer.parseInt(input[1]);

            // 가로 방향 최고 길이와 인덱스 찾기
            if (direction <= 2 && maxHorizontalLength < Lengths[i]) {
                maxHorizontalLength = Lengths[i];
                maxHorizontalIndex = i;
            } else if (direction > 2 && maxVerticalLength < Lengths[i]){
                maxVerticalLength = Lengths[i];
                maxVerticalIndex = i;
            }
        }

        // 빼야 할 사각형 가로 세로 길이 찾기 (가장 긴 변의 양 쪽 변 차이가 작은 사각형의 변의 길이)
        int minHorizontalLength = -1, minVerticalLength = -1;

        for (int i = 0; i < 6; i++) {
            int previous = (i - 1) < 0 ? 5 : i - 1;
            int next = (i + 1) >= 6 ? 0 : i + 1;

            if (i == maxHorizontalIndex) {
                minHorizontalLength = Math.abs(Lengths[previous] - Lengths[next]);
            } else if (i == maxVerticalIndex) {
                minVerticalLength = Math.abs(Lengths[previous] - Lengths[next]);
            }
        }

        int groundArea = (maxHorizontalLength * maxVerticalLength) - (minHorizontalLength * minVerticalLength);
        int answer = K * groundArea;
        System.out.println(answer);
        br.close();
    }
}