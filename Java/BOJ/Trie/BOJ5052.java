package Java.BOJ.Trie;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ5052 {
    private static class Trie {
        boolean isFinished;
        Trie[] numbers = new Trie[10];        // 0 ~ 9
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int numOfTestcases = Integer.parseInt(br.readLine());
        StringBuilder answer = new StringBuilder();

        while (numOfTestcases-- > 0) {
            int n = Integer.parseInt(br.readLine());
            Trie root = new Trie();
            
            // 모든 전화번호를 저장
            String[] phoneNumbers = new String[n];
            for (int i = 0; i < n; i++) {
                phoneNumbers[i] = br.readLine();
            }
            
            // 모든 전화번호를 Trie에 삽입
            for (int i = 0; i < n; i++) {
                insert(root, phoneNumbers[i]);
            }
            
            // 일관성 확인
            boolean isConsistent = true;
            for (int i = 0; i < n; i++) {
                if (!isConsistent(root, phoneNumbers[i])) {
                    isConsistent = false;
                    break;
                }
            }

            answer.append(isConsistent ? "YES" : "NO").append("\n");
        }

        System.out.println(answer);
    }

    // Trie에 전화번호 삽입
    private static void insert(Trie node, String phoneNumber) {
        Trie current = node;
        
        for (int i = 0; i < phoneNumber.length(); i++) {
            int index = phoneNumber.charAt(i) - '0';
            if (current.numbers[index] == null) {
                current.numbers[index] = new Trie();
            }
            current = current.numbers[index];
        }
        
        current.isFinished = true;
    }
    
    private static boolean isConsistent(Trie root, String phoneNumber) {
        Trie current = root;
        
        for (int i = 0; i < phoneNumber.length(); i++) {
            // 현재 위치가 다른 번호의 끝인데, 아직 현재 번호가 끝나지 않았다면 현재 번호가 다른 번호의 접두어
            if (current.isFinished && i < phoneNumber.length()) {
                return false;
            }
            
            int index = phoneNumber.charAt(i) - '0';
            current = current.numbers[index];
        }
        
        // 현재 번호의 끝에 도달했을 때, 이 위치에서 계속되는 다른 번호가 있는지 확인 -> 있다면 현재 번호는 다른 번호의 접두어가 됨
        for (int i = 0; i < 10; i++) {
            if (current.numbers[i] != null) {
                return false;
            }
        }
        
        return true;
    }
}