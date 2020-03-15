/*
    풀이 :
    중요도와 문서의 이름을 각각 String으로 저장하고, 맨 앞의 중요도와 뒤 문서들의 중요도를 비교하여 더 높은 중요도를 만나면 그때까지의
    문서를 모두 뒤로 보내고 이 작업을 반복한다.
    만약 더 높은 중요도를 만나지 않으면 맨 앞의 문서를 지우고 count값을 갱신한다.
    찾는 문서(m)와 같은 이름의 문서를 만나면 count+1을 리턴한다
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        int N=Integer.parseInt(br.readLine());

        for (int i = 0; i <N ; i++) {
            StringBuilder name=new StringBuilder();
            StringBuilder pre=new StringBuilder();

            String s=br.readLine();
            StringTokenizer st=new StringTokenizer(s);
            int n=Integer.parseInt(st.nextToken());
            int m=Integer.parseInt(st.nextToken());

            s=br.readLine();
            st=new StringTokenizer(s);
            for (int j = 0; j <n ; j++) {
                pre.append(st.nextToken());
                name.append((char)j);
            }
            bw.write(find(name,pre,m)+"\n");
        }
        bw.flush();
        bw.close();
    }
    public static int find(StringBuilder name,StringBuilder pre,int m){
        int count=0;
        while(true) {
            for (int i=1; i < pre.length(); i++) {
                if (pre.toString().charAt(0) < pre.toString().charAt(i)) {
                    String temp = pre.substring(0, i);
                    pre.delete(0, i);
                    pre.append(temp);
                    temp = name.substring(0, i);
                    name.delete(0, i);
                    name.append(temp);
                    i = 0;
                }
            }
            if (name.toString().charAt(0)==(char)m) {
                return count+1;
            } else {
                pre.delete(0,1);
                name.delete(0,1);
                count++;
            }
        }
    }
}
