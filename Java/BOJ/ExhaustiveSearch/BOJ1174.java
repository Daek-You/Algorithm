package BOJ.ExhaustiveSearch;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BOJ1174 {
    private static List<Long> decreasingNumbers = new ArrayList<>();
    private static int N;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        
        // 줄어드는 수 생성
        for (int i = 0; i <= 9; i++) {
            generateDecreasingNumbers(i, i);
        }
        
        Collections.sort(decreasingNumbers);
        
        if (N <= decreasingNumbers.size())  System.out.println(decreasingNumbers.get(N - 1));
        else                                System.out.println(-1);
    }

    private static void generateDecreasingNumbers(long number, int lastDigit) {
        // 현재 수를 리스트에 추가
        decreasingNumbers.add(number);
        
        // 마지막 자릿수보다 작은 수를 뒤에 붙여 새로운 줄어드는 수 생성
        for (int i = 0; i < lastDigit; i++) {
            generateDecreasingNumbers(number * 10 + i, i);
        }
    }
}