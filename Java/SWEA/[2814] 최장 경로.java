import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Solution  {
    private static int N, M;
    private static ArrayList<ArrayList<Integer>> Graph;
    private static boolean[] Visited;
    private static int Answer;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int testCase = 1; testCase <= T; testCase++) {
            Initialize(br);

            for (int node = 1; node <= N; node++)
                DFS(node, 1);
            System.out.printf("#%d %d\n", testCase, Answer);
        }
    }

    private static void DFS(int node, int numOfNodes) {
        Visited[node] = true;
        boolean isEndPoint = true;

        for (int nextNode : Graph.get(node)) {
            if (Visited[nextNode])
                continue;

            isEndPoint = false;
            DFS(nextNode, numOfNodes + 1);
        }

        if (isEndPoint)
            Answer = Math.max(Answer, numOfNodes);
        Visited[node] = false;
    }

    private static void Initialize(BufferedReader br) throws Exception {
        String[] args = br.readLine().split(" ");
        N = Integer.parseInt(args[0]);
        M = Integer.parseInt(args[1]);
        Answer = 0;

        Visited = new boolean[N + 1];
        Graph = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i <= N; i++)
            Graph.add(new ArrayList<Integer>());

        for (int i = 0; i < M; i++) {
            args = br.readLine().split(" ");
            int x = Integer.parseInt(args[0]), y = Integer.parseInt(args[1]);

            Graph.get(x).add(y);
            Graph.get(y).add(x);
        }
    }
}