import java.io.BufferedReader;
import java.io.InputStreamReader;
 
class Solution {
     
    private static boolean[] OriginalMemory;
    private static boolean[] CurrentMemory;
    private static int Length;
     
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
 
        for (int test_case = 1; test_case <= T; test_case++) {
            Initialize(br);
             
            int answer = FindMinUpdateCount();
            System.out.printf("#%d %d\n", test_case, answer);
        }
    }
     
    private static int FindMinUpdateCount() {
        int count = 0;
         
        for (int i = 0; i < Length; i++) {
            if (OriginalMemory[i] != CurrentMemory[i]) {
                CurrentMemory[i] = OriginalMemory[i];
                Fill(CurrentMemory, i + 1, CurrentMemory[i]);
                count++;
            }
        }
         
        return count;
    }
     
    private static void Fill(boolean[] memory, int index, boolean value) {
        for (int i = index; i < Length; i++) {
            memory[i] = value;
        }
    }
     
    private static void Initialize(BufferedReader br) throws Exception {
        String inputMemory = br.readLine();
        Length = inputMemory.length();
 
        OriginalMemory = new boolean[Length];
         
        for (int i = 0; i < Length; i++) {
            OriginalMemory[i] = (inputMemory.charAt(i) == '1') ? true : false;
        }
         
        CurrentMemory = new boolean[Length];
    }
}