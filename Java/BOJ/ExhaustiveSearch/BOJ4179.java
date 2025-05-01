package BOJ.ExhaustiveSearch;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Dictionary;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class BOJ4179 {
    private static class Point {
        int row, col;

        Point(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }

    private static int R, C;
    private static char[][] Field;
    private static Point[][] JihoonPositions;
    private static LinkedList<int[]> JihoonQueue, FireQueue;
    private static boolean[][] Visited;

    private static final int DIRECTION_COUNT = 4;
    private static int[] ROW_DIRS = {-1, 1, 0, 0};
    private static int[] COL_DIRS = {0, 0, -1, 1};

    private static boolean IsEscaped = false;
    private static int ElapseTime = 0;

    public static void main(String[] args) throws Exception {

        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        Visited = new boolean[R][C];
        Field = new char[R][C];
        JihoonPositions = new Point[R][C];
        JihoonQueue = new LinkedList<>();
        FireQueue = new LinkedList<>();

        for (int r = 0; r < R; r++) {
            String row = br.readLine();
            for (int c = 0; c < C; c++) {
                Field[r][c] = row.charAt(c);

                if (Field[r][c] == 'J') {
                    JihoonQueue.add(new int[] {r, c, 0});
                    Visited[r][c] = true;
                } else if (Field[r][c] == 'F') {
                    FireQueue.add(new int[] {r, c});
                }    
            }
        }

        // BFS
        do {
            moveJihoons();
            moveFires();
        } while (!IsEscaped && !JihoonQueue.isEmpty());

        // 정답 출력
        String answer = IsEscaped ? String.valueOf(ElapseTime) : "IMPOSSIBLE";
        System.out.println(answer);
    }

    private static void moveJihoons() {
        if (!JihoonQueue.isEmpty()) {
            int size = JihoonQueue.size();

            for (int i = 0; i < size; i++) {
                int[] data = JihoonQueue.poll();
                int row = data[0], col = data[1], time = data[2];
                
                // 죽은 케이스
                if (Field[row][col] == 'F') continue;
                
                JihoonPositions[row][col] = null;
                for (int d = 0; d < DIRECTION_COUNT; d++) {
                    int nextRow = row + ROW_DIRS[d];
                    int nextCol = col + COL_DIRS[d];

                    if (!isInMap(nextRow, nextCol)) {
                        IsEscaped = true;
                        ElapseTime = time + 1;
                        return;
                    }

                    if (Field[nextRow][nextCol] == '#' || Field[nextRow][nextCol] == 'F' || Visited[nextRow][nextCol])     continue;

                    JihoonQueue.add(new int[] {nextRow, nextCol, time + 1});
                    JihoonPositions[nextRow][nextCol] = new Point(nextRow, nextCol);
                    Visited[nextRow][nextCol] = true;
                }
            }
        }

    }

    private static void moveFires() {
        if (!FireQueue.isEmpty()) {
            int size = FireQueue.size();

            for (int i = 0; i < size; i++) {
                int[] data = FireQueue.poll();
                int row = data[0], col = data[1];

                for (int d = 0; d < DIRECTION_COUNT; d++) {
                    int nextRow = row + ROW_DIRS[d];
                    int nextCol = col + COL_DIRS[d];

                    if (!isInMap(nextRow, nextCol))                                         continue;
                    if (Field[nextRow][nextCol] == '#' || Field[nextRow][nextCol] == 'F')   continue;

                    Field[nextRow][nextCol] = 'F';
                    FireQueue.add(new int[] {nextRow, nextCol});
                }
            }
        }
    }

    private static boolean isInMap(int row, int col) {
        return 0 <= row && row < R && 0 <= col && col < C;
    }
}
