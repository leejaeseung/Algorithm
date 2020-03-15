import java.io.*;
public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String w = br.readLine();
        StringBuilder S = new StringBuilder();
        S.append(br.readLine());

        int N = Integer.parseInt(br.readLine());
        int idx = 0;
        int cnt = 0;
        for (int i = 0; i < N ; i++) {
            if(br.readLine().charAt(0) == 'L'){
                idx = S.indexOf(w);
                if(idx != -1){
                    S.delete(idx, idx + w.length());
                    cnt++;
                }
            }
            else{
                idx = S.lastIndexOf(w);
                if(idx != -1){
                    S.delete(idx, idx + w.length());
                    cnt++;
                }
            }
        }

        bw.write(cnt + "\n");
        bw.write(S.toString() + "\n");
        if(!S.toString().contains(w))
            bw.write("Perfect!");
        else
            bw.write("You Lose!");
        bw.flush();
        bw.close();
    }
}