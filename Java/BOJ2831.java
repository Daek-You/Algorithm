import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ2831 {
    
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 1 << 16);
        int N = Integer.parseInt(br.readLine());

        // 남자가 원하는 키 선호도 조사
        PriorityQueue<Integer> higherMen = new PriorityQueue<>();
        PriorityQueue<Integer> lowerMen = new PriorityQueue<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int height = Integer.parseInt(st.nextToken());
            if (height >= 0)    higherMen.add(height);
            else                lowerMen.add(-height);
        }

        // 여자가 원하는 키 선호도 조사
        PriorityQueue<Integer> higherWomen = new PriorityQueue<>();
        PriorityQueue<Integer> lowerWomen = new PriorityQueue<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int height = Integer.parseInt(st.nextToken());
            if (height >= 0)    higherWomen.add(height);
            else                lowerWomen.add(-height);
        }

        int answer = 0;

        // 키가 작은 여자를 원하는 남자 - 키가 큰 남자를 원하는 여자
        while (!lowerMen.isEmpty() && !higherWomen.isEmpty()) {
            int manHeight = lowerMen.peek(), womanHeight = higherWomen.peek();

            if (manHeight > womanHeight) {
                answer++;
                lowerMen.poll();
                higherWomen.poll();
            } else {
                // 남자 키가 더 작다는 거고, 이보다 작은 여자들은 없으므로 남자를 제외
                lowerMen.poll();
            }
        }

        // 키가 큰 여자를 원하는 남자 - 키가 작은 남자를 원하는 여자
        while (!higherMen.isEmpty() && !lowerWomen.isEmpty()) {
            int manHeight = higherMen.peek(), womanHeight = lowerWomen.peek();
            if (manHeight < womanHeight) {
                answer++;
                higherMen.poll();
                lowerWomen.poll();
            } else {
                // 남자 키가 더 크다는 거고, 이보다 큰 여자는 없으므로 여자를 제외
                lowerWomen.poll();
            }
        }

        System.out.println(answer);
    }
}
