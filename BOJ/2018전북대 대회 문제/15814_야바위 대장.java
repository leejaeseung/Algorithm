import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int T;

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder s = new StringBuilder();
        s.append(br.readLine());

        T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            char temp = s.charAt(a);
            s.setCharAt(a, s.charAt(b));
            s.setCharAt(b, temp);
        }
        System.out.println(s.toString());
    }
}