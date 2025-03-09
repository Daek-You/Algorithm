import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class BOJ4991 {
    private static final char DIRTY = '*';
    private static final char FURNITURE = 'x';
    private static final char START_POSITION = 'o';

    private static final int[] ROW_DIRS = {-1, 1, 0, 0};
    private static final int[] COL_DIRS = {0, 0, -1, 1};

    public static void main(String[] args) throws Exception {

         BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         StringBuilder answers = new StringBuilder();
         
        while (true) {
            // 1. 입력 받기
            StringTokenizer st = new StringTokenizer(br.readLine());
            int maxCol = Integer.parseInt(st.nextToken()), maxRow = Integer.parseInt(st.nextToken());
            if (maxRow == 0 && maxCol == 0) break;

            char[][] map = new char[maxRow][maxCol];
            int startRow = -1, startCol = -1;
            int numOfDirtyRooms = 0;
            for (int r = 0; r < maxRow; r++) {
                String line = br.readLine();

                for (int c = 0; c < maxCol; c++) {
                    map[r][c] = line.charAt(c);

                    if (map[r][c] == START_POSITION) {
                        startRow = r;
                        startCol = c;
                    } else if (map[r][c] == DIRTY) {
                        numOfDirtyRooms++;
                    }
                }
            }

            // 2. bfs 시뮬레이션
            int answer = bfs(map, numOfDirtyRooms, startRow, startCol);
            answers.append(answer).append("\n");
        }
         
        System.out.println(answers.toString());
    }

    private static int bfs(final char[][] map, final int numOfDirtyRooms, int startRobotRow, int startRobotCol) {
        int maxRow = map.length, maxCol = map[0].length;
        boolean[][][] visit = new boolean[4][maxRow][maxCol];
        int minMoveCount = Integer.MAX_VALUE;
        
        LinkedList<int[]> queue = new LinkedList<>();
        queue.add(new int[] {startRobotRow, startRobotCol, 0, 0});     // [행, 열, 이동 횟수, 청소한 더러운 칸 개수]

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int row = current[0], col = current[1];
            int moveCount = current[2], cleanedDirtyRooms = current[3];

            // 모든 구역을 다 치웠다면
            if (cleanedDirtyRooms == numOfDirtyRooms) {
                minMoveCount = Math.min(minMoveCount, moveCount);
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nextRow = row + ROW_DIRS[i];
                int nextCol = col + COL_DIRS[i];

                if (nextRow < 0 || nextRow >= maxRow || nextCol < 0 || nextCol >= maxCol)   continue;
                if (map[nextRow][nextCol] == FURNITURE || isClear(map, visit, nextRow, nextCol))       continue;

                visit[i][nextRow][nextCol] = true;
                int isDirtyRoom = (map[nextRow][nextCol] == DIRTY) ? 1 : 0;
                queue.add(new int[] {nextRow, nextCol, moveCount + 1, cleanedDirtyRooms + isDirtyRoom});
            }
        }

        // 치울 수 없는 더러운 칸이 있는 경우에는 -1 리턴
        return (minMoveCount == Integer.MAX_VALUE) ? - 1 : minMoveCount;
    }

    private static boolean isClear(final char[][] map, final boolean[][][] visit, int row, int col) {
        for (int i = 0; i < 4; i++) {
            if (map[row][col] == DIRTY && visit[i][row][col]) return true;
        }

        return false;
    }
}