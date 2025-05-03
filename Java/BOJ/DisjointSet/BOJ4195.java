package DisjointSet;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class BOJ4195 {
    private static int[] Parents;
    private static int[] Sizes;
    
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        
        while (T-- > 0) {
            int F = Integer.parseInt(br.readLine());
            Parents = new int[F * 2];  // 사람 수의 2배로 설정 (넉넉히)
            Sizes = new int[F * 2];    // 같은 크기로 설정
            
            for(int i = 0; i < F * 2; i++) {
                Parents[i] = i;
                Sizes[i] = 1;
            }
            
            HashMap<String, Integer> nameToIndex = new HashMap<>();
            StringBuilder answer = new StringBuilder();
            int index = 0;
            
            for(int i = 0; i < F; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String person1 = st.nextToken(), person2 = st.nextToken();
                
                // 각 사람에게 고유한 인덱스를 할당
                if(!nameToIndex.containsKey(person1))   nameToIndex.put(person1, index++);
                if(!nameToIndex.containsKey(person2))   nameToIndex.put(person2, index++);
                
                int idx1 = nameToIndex.get(person1), idx2 = nameToIndex.get(person2);
                answer.append(union(idx1, idx2));
                if (i < F - 1)  answer.append("\n");
            }

            System.out.println(answer);
        }
    }
    
    static int find(int x) {
        if(Parents[x] == x) return x;
        return Parents[x] = find(Parents[x]);
    }
    
    static int union(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if(rootX == rootY)  return Sizes[rootX];
        
        Parents[rootY] = rootX;
        Sizes[rootX] += Sizes[rootY];
        return Sizes[rootX];
    }
}
