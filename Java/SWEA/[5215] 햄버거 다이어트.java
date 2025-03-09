import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution {
	private static int NumOfIngredients;
	private static int LimitCalorie;
	private static int Answer;
	private static int[] Points, Calories;
	private static boolean[] Visited;
	
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for (int test_case = 1; test_case <= T; test_case++)
		{
			Initialize(br);
			Combination(0, 0, 0);
			System.out.printf("#%d %d\n", test_case, Answer);
		}
	}
	
	private static void Combination(int index, int points, int calories) {
		if (index >= NumOfIngredients) {
			Answer = Math.max(Answer, points);
			return;
		}
		
		for (int i = index; i < NumOfIngredients; i++) {
			if (!Visited[i] && calories + Calories[i] <= LimitCalorie) {
				Visited[i] = true;
				Answer = Math.max(Answer, points + Points[i]);
				Combination(i + 1, points + Points[i], calories + Calories[i]);
				Visited[i] = false;
			}
		}
	}
	
	private static void Initialize(BufferedReader br) throws Exception {
		String[] arguments = br.readLine().split(" ");
		NumOfIngredients = Integer.parseInt(arguments[0]);
		LimitCalorie = Integer.parseInt(arguments[1]);
		Answer = 0;
		
		Points = new int[NumOfIngredients];
		Calories = new int[NumOfIngredients];
		Visited = new boolean[NumOfIngredients];
		
		for (int i = 0; i < NumOfIngredients; i++) {
			String[] args = br.readLine().split(" ");
			Points[i] = Integer.parseInt(args[0]);
			Calories[i] = Integer.parseInt(args[1]);
		}
	}
}