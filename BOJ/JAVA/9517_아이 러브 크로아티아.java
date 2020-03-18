/*
    풀이 : 230초를 넘기면 break
 */
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int start = Integer.parseInt(br.readLine());
        int N = Integer.parseInt(br.readLine());
        Queue<question> q_list = new LinkedList<>();
        for (int i = 0; i < N ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            q_list.offer(new question(Integer.parseInt(st.nextToken()), st.nextToken().charAt(0)));
        }

        int cur_time = 0;
        while (true) {
            question temp = q_list.poll();
            cur_time += temp.time;

            if( cur_time >= 230 )
                break;
            if( temp.answer == 'T'){
                start = (start % 8) + 1;
            }
        }
        bw.write(Integer.toString(start));
        bw.flush();
        bw.close();
    }
}

class question{

    public int time;
    public char answer;
    public question(int time, char answer){
        this.answer = answer;
        this.time = time;
    }
}