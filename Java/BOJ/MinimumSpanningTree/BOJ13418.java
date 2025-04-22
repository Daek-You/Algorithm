package MinimumSpanningTree;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ13418 {
    private static class Node {
        int next, cost;

        Node(int next, int cost) {
            this.next = next;
            this.cost = cost;
        }
    }

    private static int N, M;
    private static ArrayList<Node>[] Nodes;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        Nodes = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++) Nodes[i] = new ArrayList<>();    

        // 시작 지점과 연결된 첫 지점과의 관계 넣기
        st = new StringTokenizer(br.readLine());
        int enterNode = Integer.parseInt(st.nextToken()), enterNextNode = Integer.parseInt(st.nextToken());
        int isDownhill = Integer.parseInt(st.nextToken()); // 1이면 내리막, 0이면 오르막
        Nodes[enterNode].add(new Node(enterNextNode, isDownhill));
        Nodes[enterNextNode].add(new Node(enterNode, isDownhill));

        // 나머지 관계들 넣기
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken()), to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            Nodes[from].add(new Node(to, cost));
            Nodes[to].add(new Node(from, cost));
        }

        // 최악의 경로: 오르막길(cost=0)을 우선 선택
        int worstPath = prim(enterNode, enterNextNode, isDownhill, (a, b) -> a.cost - b.cost);
        
        // 최선의 경로: 내리막길(cost=1)을 우선 선택
        int bestPath = prim(enterNode, enterNextNode, isDownhill, (a, b) -> b.cost - a.cost);
        
        int answer = worstPath - bestPath;
        System.out.println(answer);
    }

    private static int prim(int startNode, int firstNext, int firstCost, Comparator<Node> comparator) {
        boolean[] visited = new boolean[N + 1];
        PriorityQueue<Node> pq = new PriorityQueue<>(comparator);
        
        // 시작 노드와 첫 번째 노드는 이미 방문한 것으로 처리
        visited[startNode] = true;
        visited[firstNext] = true;
        
        // 첫 번째 노드에 연결된 간선들을 우선순위 큐에 추가
        for (Node nearNode : Nodes[firstNext]) {
            if (!visited[nearNode.next])    pq.add(nearNode);
        }
        
        // 첫 노드에 연결된 간선도 우선순위 큐에 추가
        for (Node nearNode : Nodes[startNode]) {
            if (!visited[nearNode.next])    pq.add(nearNode);
        }

        // 첫 번째 간선은 이미 선택됨 - 오르막길이면(cost=0) 카운트 증가
        int upHillCount = firstCost == 0 ? 1 : 0;
        int edgeCount = 1; // 첫 번째 간선은 이미 선택됨
        
        while (!pq.isEmpty() && edgeCount < N) {
            Node current = pq.poll();
            
            if (visited[current.next]) continue;
            
            // 오르막길(cost=0)이면 카운트 증가
            if (current.cost == 0)  upHillCount++;
            
            visited[current.next] = true;
            edgeCount++;
            
            // 현재 노드에 연결된 간선들 추가
            for (Node nearNode : Nodes[current.next]) {
                if (!visited[nearNode.next])    pq.add(nearNode);
            }
        }
        
        // 총 피로도 = 오르막길 개수의 제곱
        return upHillCount * upHillCount;
    }
}