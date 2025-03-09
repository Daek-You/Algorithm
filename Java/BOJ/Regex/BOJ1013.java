import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class BOJ1013 {
    
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        String regex = "(100+1+|01)+";
        StringBuilder answer = new StringBuilder();

        while (T-- > 0) {
            String input = br.readLine();               // 우리가 검사할 문자열
            Pattern pattern = Pattern.compile(regex);   // 우리가 찾으려는 정규식 패턴 컴파일
            Matcher matcher = pattern.matcher(input);   // 입력 문자열에서 우리가 찾는 정규식 패턴이 있는지 검사
            String result = (matcher.matches()) ? "YES" : "NO";
            answer.append(result).append("\n");
        }

        // 정답 출력
        System.out.println(answer);
    }
}
