/*
문제
초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다. 여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.

집합을 표현하는 프로그램을 작성하시오.

입력
첫째 줄에 n(1≤n≤1,000,000), m(1≤m≤100,000)이 주어진다. m은 입력으로 주어지는 연산의 개수이다. 다음 m개의 줄에는 각각의 연산이 주어진다. 합집합은 0 a b의 형태로 입력이 주어진다. 이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다. 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다. 이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다. a와 b는 n 이하의 자연수또는 0이며 같을 수도 있다.

출력
1로 시작하는 입력에 대해서 한 줄에 하나씩 YES/NO로 결과를 출력한다. (yes/no 를 출력해도 된다)

풀이:
유니온 파인드 기본 문제
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N,M;
    public static int[] parent;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        parent = new int[N + 1];

        for (int i = 0; i <= N ; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            int o = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            if(o == 0){
                union(x, y);
            }
            else{
                if(find(x) == find(y))
                    bw.write("YES\n");
                else
                    bw.write("NO\n");
            }
        }
        bw.flush();
        bw.close();
    }
    public static int find(int now){
        if(parent[now] == now)
            return now;
        else{
            return find(parent[now]);
        }
    }
    public static void union(int node1, int node2){
        node1 = find(node1);
        node2 = find(node2);

        if(node1 != node2){
            if(node1 > node2)
                parent[node1] = node2;
            else
                parent[node2] = node1;
        }
    }
}
