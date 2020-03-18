/*
    풀이:
    원주율과 택시 기하학만 알면 된.
    새롭게 알게 된 것: String.format으로 출력 형식 지정가능(c언어처럼)
 */
import java.io.*;

public class Main {

    public static double R;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        R = Double.parseDouble(br.readLine());
        double pie=3.14159265359;
        double ucl=R*R*pie;
        double taxi=R*R*2;

        System.out.println(String.format("%.6f",ucl));
        System.out.println(String.format("%.6f",taxi));
    }
}