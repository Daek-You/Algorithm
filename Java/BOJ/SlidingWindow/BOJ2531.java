package Java.BOJ;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class BOJ2531 {
    
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());           // 벨트 위에 놓인 접시 수
        int d = Integer.parseInt(st.nextToken());           // 초밥 종류 수
        int k = Integer.parseInt(st.nextToken());           // 연속해서 먹는 접시 수
        int c = Integer.parseInt(st.nextToken());           // 쿠폰 번호

        int[] sushies = new int[n];
        for (int i = 0; i < n; i++) {
            sushies[i] = Integer.parseInt(br.readLine());
        }
        
        HashMap<Integer, Integer> eatingCounter = new HashMap<>();     // <먹은 초밥 번호, 먹은 개수>

        // 일단 0번부터 k - 1번까지 k개 초밥 먹기
        for (int i = 0; i < k; i++) {
            eatingCounter.merge(sushies[i], 1, Integer::sum);      // 먹은 초밥 목록에 없으면 1로 설정, 있으면 +1
        }

        int couponEffect = eatingCounter.containsKey(c) ? 0 : 1;    // 쿠폰 적용 여부
        int answer = eatingCounter.size() + couponEffect;

        for (int removeIdx = 0; removeIdx < n; removeIdx++) {
            int removeSushi = sushies[removeIdx];

            // 초밥 제거
            eatingCounter.computeIfPresent(removeSushi, (key, value) -> value - 1);
            if (eatingCounter.get(removeSushi) != null && eatingCounter.get(removeSushi) == 0) {
                eatingCounter.remove(removeSushi);
            }

            // 초밥 추가
            int addSushi = sushies[(removeIdx + k) % n];
            eatingCounter.merge(addSushi, 1, Integer::sum);
            
            // 쿠폰 효과 계산 (쿠폰 초밥이 이미 있는지 확인)
            couponEffect = eatingCounter.containsKey(c) ? 0 : 1;
            answer = Math.max(answer, eatingCounter.size() + couponEffect);
        }

        System.out.println(answer);
    }
}
