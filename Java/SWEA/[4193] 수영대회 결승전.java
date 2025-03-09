import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;

class Solution
{
    private static final int OBSTACLE = 1;
    private static final int MAELSTROM = 2;
    private static final int DIRECTION_COUNT = 4;
    private static int N;
    private static int[][] Field;
    private static int[] DirectionRow       = {-1, 1, 0, 0};
    private static int[] DirectionColumn    = {0, 0, -1, 1};

	public static void main(String args[]) throws Exception
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for (int test_case = 1; test_case <= T; test_case++)
		{
            Initialize(br);

            String[] start = br.readLine().split(" ");
            String[] destination = br.readLine().split(" ");
    
            int startRow = Integer.parseInt(start[0]), startColumn = Integer.parseInt(start[1]);
            int destRow = Integer.parseInt(destination[0]), destColumn = Integer.parseInt(destination[1]);
            int answer = BFS(startRow, startColumn, destRow, destColumn);

            System.out.printf("#%d %d\n", test_case, answer);
		}
	}

    private static int BFS(int startRow, int startColumn, int destRow, int destColumn)
    {
        Queue<Point> queue = new LinkedList<>();
        boolean[][] visited = new boolean[N][N];

        queue.add(new Point(startRow, startColumn));
        visited[startRow][startColumn] = true;
        int time = -1;

        while (!queue.isEmpty())
        {
            int size = queue.size();
            time++;
            
            while (size-- > 0)
            {
                Point current = queue.poll();

                for (int i = 0; i < DIRECTION_COUNT; i++)
                {
                    int nextRow = current.row + DirectionRow[i];
                    int nextColumn = current.column + DirectionColumn[i];
    
                    if (nextRow < 0 || nextRow >= N || nextColumn < 0 || nextColumn >= N || visited[nextRow][nextColumn] || Field[nextRow][nextColumn] == OBSTACLE)
                        continue;
                    
                    if (Field[nextRow][nextColumn] == MAELSTROM)
                    {
                        if (time % 3 == 2)  // 소용돌이가 멈추는 경우
                        {
                            queue.add(new Point(nextRow, nextColumn));
                            visited[nextRow][nextColumn] = true;
                            continue;
                        }

                        queue.add(new Point(current.row, current.column));
                        continue;
                    }

                    if (nextRow == destRow && nextColumn == destColumn)
                        return time + 1;
                    
                    else
                    {
                        queue.add(new Point(nextRow, nextColumn));
                        visited[nextRow][nextColumn] = true;
                    }
                }
            }
        }

        return -1;
    }

    private static void Initialize(BufferedReader br) throws Exception
    {
        N = Integer.parseInt(br.readLine());
        Field = new int[N][N];

        for (int i = 0; i < N; i++)
        {
            String row = br.readLine();
            String[] tokens = row.split(" ");

            for (int j = 0; j < N; j++)
                Field[i][j] = Integer.parseInt(tokens[j]);
        }
    }
}

class Point
{
    Point(int row, int column)
    {
        this.row = row;
        this.column = column;
    }

    int row, column;
}