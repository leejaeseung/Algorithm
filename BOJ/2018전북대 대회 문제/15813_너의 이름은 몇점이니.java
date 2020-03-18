import java.io.*;

public class Main {

    public static int N;

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        String str = br.readLine();

        int sum = 0;
        for (int i = 0; i < str.length() ; i++) {
            sum += str.charAt(i) - 'A' + 1;
        }
        System.out.println(sum);
    }
}