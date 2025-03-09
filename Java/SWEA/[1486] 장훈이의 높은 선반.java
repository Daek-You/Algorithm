import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution
{
    private static int N;
    private static int B;
    private static int Answer;
    private static int[] Heights;
    private static boolean[] Visited;

	public static void main(String args[]) throws Exception
	{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

		for (int test_case = 1; test_case <= T; test_case++)
		{
            Initialize(br);
            Combination(0, 0);
            System.out.printf("#%d %d\n", test_case, Answer);
        }
	}

    private static void Initialize(BufferedReader br) throws Exception
    {
        StringTokenizer tokenizer = new StringTokenizer(br.readLine());
        N = Integer.parseInt(tokenizer.nextToken());
        B = Integer.parseInt(tokenizer.nextToken());
        Answer = Integer.MAX_VALUE;
        Heights = new int[N];
        Visited = new boolean[N];
        tokenizer = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++)
            Heights[i] = Integer.parseInt(tokenizer.nextToken());
    }

    private static void Combination(int index, int sum)
    {
        if (sum >= B)
        {
            Answer = Math.min(Answer, sum - B);
            return;
        }

        for (int i = index; i < N; i++)
        {
            if (Visited[i])
                continue;
            
            Visited[i] = true;
            Combination(i + 1, sum + Heights[i]);
            Visited[i] = false;
        }
    }
}