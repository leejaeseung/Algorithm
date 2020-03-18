/*
    시뮬레이션 입문 문제 :
    so EZ...;;
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int people=0;
    public static int max=0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        String s;
        for (int i = 1; i <5 ; i++) {
            s=br.readLine();
            StringTokenizer st=new StringTokenizer(s);

            Maxpeople(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
        }
        bw.write(Integer.toString(max));
        bw.flush();
        bw.close();
    }
    public static void Maxpeople(int out,int in){
        people=people+in-out;
        if(people>max)
            max=people;
    }
}
