/*
    So EZ...
 */
import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s=br.readLine();
        char[] str=new char[s.length()];

        for (int i = 0; i <s.length() ; i++) {
            str[i]=s.charAt(i);
        }
        for (int i = 0; i <s.length() ; i++) {
            bw.write(((str[i]-42)%26)+65);
        }
        bw.flush();
        bw.close();
    }
}