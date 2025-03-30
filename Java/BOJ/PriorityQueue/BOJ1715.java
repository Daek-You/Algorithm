package Java.BOJ.PriorityQueue;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class BOJ1715 {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < N; i++) pq.add(Integer.parseInt(br.readLine()));

        int answer = 0;
        while (pq.size() > 1) {
            int card1 = pq.poll(), card2 = pq.poll();
            int sum = card1 + card2;
            answer += sum;
            pq.add(sum);
        }

        System.out.println(answer);
    }
}