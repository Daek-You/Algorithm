package Java.BOJ.Implementation;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class BOJ1091 {
    private static int N;
    private static int[] P;
    private static int[] S;

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        P = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) P[i] = Integer.parseInt(st.nextToken());

        S = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) S[i] = Integer.parseInt(st.nextToken());

        int answer = solution();
        System.out.println(answer);
    }

    private static int solution() {
        // 초기 카드 배열 세팅
        int[] cards = new int[N];
        for (int i = 0; i < N; i++) cards[i] = i;
        HashSet<String> visited = new HashSet<>();
        int count = 0;
        
        if (!isTargetState(cards)) {
            while (true) {
                cards = shuffle(cards);
                count++;
                
                // 목표 상태에 도달했는지 확인
                if (isTargetState(cards))   break;
                
                // 현재 카드 상태를 문자열로 변환하여 방문 여부 확인
                String state = Arrays.toString(cards);
    
                // 이미 방문한 상태라면 무한 루프
                if (visited.contains(state))    return -1;
                visited.add(state);
            }
        }

        return count;
    }
    
    private static boolean isTargetState(int[] cards) {
        for (int i = 0; i < N; i++) {
            // i번 카드가 있는 위치 찾기
            int position = -1;
            for (int j = 0; j < N; j++) {
                if (cards[j] == i) {
                    position = j;
                    break;
                }
            }

            // position % 3 == P[i]를 확인 (i번 카드가 P[i] 플레이어에게 가야 함)
            if (position % 3 != P[i])   return false;
        }
        return true;
    }


    private static int[] shuffle(int[] cards) {
        int[] newCards = new int[N];
        for (int i = 0; i < N; i++) newCards[S[i]] = cards[i];
        return newCards;
    }
}