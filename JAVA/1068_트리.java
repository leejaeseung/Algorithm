/*
    풀이 :
    처음에 문제 입력 값을 트리의 노드가 무조건 위에서부터 0 1 2 3 4 처럼 순서대로 내려오는 것으로 이해해 런타임 오류가 계속 뜸.
    Vector 배열을 이용해 vt[i]엔 i노드의 자식들을 넣고 루트노드부터 ㄹ트 노드의 자식들을 큐에 넣고 빼면서 vt[i]가 비어있을 경우엔
    leaf이므로 leaf_count를 갱신하며 풀이함
 */
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N=Integer.parseInt(br.readLine());
        Vector<Integer>[] vt=new Vector[N];
        for (int i = 0; i <N ; i++) {
            vt[i]=new Vector<>();
        }
        String s=br.readLine();
        StringTokenizer st=new StringTokenizer(s);
        Queue<Integer> q=new LinkedList<>();

        int root_node=-1;
        for (int i = 0; i <N ; i++) {
            int parent = Integer.parseInt(st.nextToken());
            if (parent == -1) {
                root_node = i;
            } else {
                vt[parent].add(i);
            }
        }
        int delete=Integer.parseInt(br.readLine());

        if(delete==root_node){
            bw.write(Integer.toString(0));
        }
        else {
            for (int i = 0; i <N ; i++) {
                vt[i].remove((Object)delete);
            }

            int leaf_count = 0;
            q.offer(root_node);
            while (!q.isEmpty()) {
                if (!vt[q.peek()].isEmpty()) {
                    for (int i = 0; i < vt[q.peek()].size(); i++) {
                        q.offer(vt[q.peek()].get(i));
                    }
                } else {
                    leaf_count++;
                }
                q.poll();
            }

            bw.write(Integer.toString(leaf_count));
        }
        bw.flush();
        bw.close();
    }
}