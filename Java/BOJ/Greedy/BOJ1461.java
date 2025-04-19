package BOJ.Greedy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ1461 {
    
    public static void main(String[] args) throws Exception {

        // 1. 입력 받기
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());

        ArrayList<Integer> positivePositions = new ArrayList<>();
        ArrayList<Integer> negativePositions = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        
        for (int i = 0; i < N; i++) {
            int position = Integer.parseInt(st.nextToken());
            if (position > 0)   positivePositions.add(position);
            else                negativePositions.add(-position);
        }

        // 2. 오름차순 정렬
        Collections.sort(positivePositions);
        Collections.sort(negativePositions);
        int answer = 0;

        // 비어 있는 컬렉션 예외 처리를 편하게 하기 위해, 0 삽입
        if (positivePositions.isEmpty())    positivePositions.add(0);
        if (negativePositions.isEmpty())    negativePositions.add(0);

        // 3. 둘 중에 더 적은 거리 쪽을 먼저 다녀오기
        int pSize = positivePositions.size(), nSize = negativePositions.size();
        ArrayList<Integer> closablePositions = (positivePositions.get(pSize - 1) < negativePositions.get(nSize - 1)) ? positivePositions : negativePositions;

        // 끝에서부터 가져다놓기
        for (int i = closablePositions.size() - 1; i >= 0; i -= M) {
            answer += closablePositions.get(i) * 2;     // 왕복으로 다녀와야 하니
        }
        
        // 4. 이제 남은 쪽에 책 가져다 놓기
        // 제일 멀리 있는 건 왕복으로 가져다 놓을 필요 X
        ArrayList<Integer> farPositions = (closablePositions == positivePositions) ? negativePositions : positivePositions;
        answer += farPositions.get(farPositions.size() - 1);

        // 나머지는 왕복으로 가져다두기
        for (int i = farPositions.size() - 1 - M; i >= 0; i -= M) {
            answer += farPositions.get(i) * 2;
        }

        // 정답 출력
        System.out.println(answer);
    }
}
