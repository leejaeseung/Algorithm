/*

제
하나의 은하 안에는 여러 행성들이 존재한다. 문명의 기술 발전으로 은하 내의 모든 행성들은 서로 여행할 수 있게 되었다.

드디어 오늘, 80,000 광년 떨어진 다른 은하와 우리 은하를 연결하는 은하 철도가 개통된다.

은하 철도가 개통되면 더 많은 행성을 여행할 수 있다는 사실에 은하 내 모든 행성의 주민들은 들떠있는 분위기이다.

우주철도공사 G-Express는 앞으로의 은하 철도 계획을 발표하였다.

우주는 너무 넓기 때문에, G-Express사는 은하가 연결될 때마다 몇 개의 행성들이 서로 여행할 수 있게 되었는 지를 알려주고자 한다.

G-Express사 기술개발팀의 직원인 당신에게 이 프로그램의 업무 요청이 들어왔다. 각 은하들의 행성 수와 철도 계획이 주어지면 해당 철도를 이용할 수 있는 행성들의 수를 실시간으로 안내하는 프로그램을 만들자.

입력
첫 번째 줄에 은하의 수 N과 철도의 개수 M이 주어진다.

두 번째 줄부터 N개의 줄에 N개의 각 은하 내에 존재하는 행성들의 수가 1번 은하부터 차례대로 주어진다. (행성을 세는 단위는 조(1012) 단위이다.)

그리고 N+2 번째 줄부터 M개의 줄에 걸쳐 은하와 은하 사이를 잇는 철도가 주어진다. 같은 은하 사이에 여러 개의 철도가 건설될 수 있다.

입력되는 N은 2 ≤ N ≤ 100,000, M은 1 ≤ M ≤ 100,000이고, 각 은하의 행성 수는 100(조)개를 넘지 않으며 아무 행성도 없는 경우는 없다.

출력
철도가 연결될 때마다 해당 철도를 이용할 수 있는 행성들의 수를 한 줄씩 출력한다.

풀이:
유니온 파인드 응용 문제이다.
철도 번호가 중복이 있을 수 있으므로 부모 노드를 합칠 때 작은 부모 번호 혹은 큰 부모 번호 쪽에만 행성 수를 카운트 해줘야 한다.
그리고 이미 계산된 은하면(부모가 같으면) 더하지 않고 그대로 출력한다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N,M;
    public static long[] planet;
    public static int[] parents;

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        planet = new long[N + 1];
        parents = new int[N + 1];

        for (int i = 1; i <= N ; i++) {
            planet[i] = Integer.parseInt(br.readLine());
            parents[i] = i;
        }
        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());

            bw.write(union(s, e) + "\n");
        }
        bw.flush();
        bw.close();
    }
    public static int find(int x){
        if(parents[x] == x) {
            return x;
        }
        else{
            return parents[x] = find(parents[x]);
        }
    }
    public static long union(int parent, int now){
        now = find(now);
        parent = find(parent);
        if(now > parent){
            parents[now] = parent;
            planet[parent] += planet[now];
            return planet[parent];
        }
        else if(now < parent){
            parents[parent] = now;
            planet[now] += planet[parent];
            return planet[now];
        }
        else {
            return planet[now];
        }
    }
}