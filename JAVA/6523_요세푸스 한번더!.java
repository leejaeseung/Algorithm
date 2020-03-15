import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static HashMap<Integer, Integer> hm = new HashMap<>();
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while(true){
            st = new StringTokenizer(br.readLine());
            long N = Long.parseLong(st.nextToken());
            if(N == 0)
                break;
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            int turn = 0;
            int count = 0;

            while(true){
                if(hm.containsKey(turn)){
                    break;
                }
                else{
                    hm.put(turn, count++);
                }
                turn = (int)(((((a % N) * (turn % N)) % N * (turn % N)) % N + b % N) % N);
            }
            bw.write(N - count + hm.get(turn) + "\n");
            bw.flush();
            hm.clear();
        }
        bw.close();
    }
}