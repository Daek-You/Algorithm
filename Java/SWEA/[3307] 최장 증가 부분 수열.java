import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Solution
{
	private static int N;
	private static int[] Sequence;
	
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for(int test_case = 1; test_case <= T; test_case++)
		{
			Initialize(br);
			
			ArrayList<Integer> LCS = new ArrayList<>();
			
			for (int i = 0; i < N; i++) {
				if (LCS.isEmpty() || LCS.get(LCS.size() - 1) < Sequence[i]) {
					LCS.add(Sequence[i]);
					continue;
				}
				
				int index = Lower_Bound(LCS, 0, LCS.size() - 1, Sequence[i]);
				
				if (index >= LCS.size())
					LCS.add(Sequence[i]);
				else
					LCS.set(index, Sequence[i]);
			}
			
			System.out.printf("#%d %d\n", test_case, LCS.size());
		}
	}
	
	private static int Lower_Bound(ArrayList<Integer> LCS, int left, int right, int value) {
		while (left < right) {
			int mid = (left + right ) / 2;
			
			if (LCS.get(mid) < value)
				left = mid + 1;
			else
				right = mid;
		}
		
		return right;
	}
	
	private static void Initialize(BufferedReader br) throws Exception {
		N = Integer.parseInt(br.readLine());
		Sequence = new int[N];
		
		String[] args = br.readLine().split(" ");
		
		for (int i = 0; i < N; i++) {
			Sequence[i] = Integer.parseInt(args[i]);
		}
	}
}