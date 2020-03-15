/*
    풀이 : 해쉬맵과 배열을 이용하자
 */
import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());

        String[] p_name=new String[N+1];
        HashMap<String,Integer> hm=new HashMap<>();
        String s;
        for (int i = 1; i <=N ; i++) {
            s=br.readLine();
            p_name[i]=s;
            hm.put(s,i);
        }
        for (int i = 0; i <M ; i++) {
            s=br.readLine();
            if(s.charAt(0)>='A'&&s.charAt(0)<='Z'){
                bw.write(hm.get(s)+"\n");
            }
            else{
                bw.write(p_name[Integer.parseInt(s)]+"\n");
            }
        }
        bw.flush();
        bw.close();
    }
}