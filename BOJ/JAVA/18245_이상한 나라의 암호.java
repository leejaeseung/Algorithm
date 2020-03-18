import java.io.*;
public class Main2 {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int cnt = 2;
        while(true){
            String s = br.readLine();
            if(s.equals("Was it a cat I saw?"))
                break;
            for (int i = 0; i < s.length() ; i = i + cnt) {
                bw.write(s.charAt(i));
            }
            bw.write("\n");
            bw.flush();
            cnt++;
        }

        bw.close();
    }
}