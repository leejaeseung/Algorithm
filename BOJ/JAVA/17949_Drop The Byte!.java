import java.io.*;
import java.util.StringTokenizer;

public class Main3 {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int point = 0;

        for (int i = 0; i < N ; i++) {
            String form = st.nextToken();
            if(form.equals("char")){
                bw.write(Long.parseLong(s.substring(point, point = point + 2), 16) + " ");
            }
            else if(form.equals("int")){
                bw.write(Long.parseLong(s.substring(point, point = point + 8), 16) + " ");
            }
            else if(form.equals("long_long")){
                bw.write(Long.parseLong(s.substring(point, point = point + 16), 16) + " ");
            }
        }
        bw.flush();
        bw.close();
    }
}