/*
문제
동혁이는 친구들과 함께 여행을 가려고 한다. 한국에는 도시가 N개 있고 임의의 두 도시 사이에 길이 있을 수도, 없을 수도 있다. 동혁이의 여행 일정이 주어졌을 때, 이 여행 경로가 가능한 것인지 알아보자. 물론 중간에 다른 도시를 경유해서 여행을 할 수도 있다. 예를 들어 도시가 5개 있고, A-B, B-C, A-D, B-D, E-A의 길이 있고, 동혁이의 여행 계획이 E C B C D 라면 E-A-B-C-B-C-B-D라는 여행경로를 통해 목적을 달성할 수 있다.

도시들의 개수와 도시들 간의 연결 여부가 주어져 있고, 동혁이의 여행 계획에 속한 도시들이 순서대로 주어졌을 때(중복 가능) 가능한지 여부를 판별하는 프로그램을 작성하시오.

입력
첫 줄에 도시의 수 N이 주어진다. N은 200이하이다. 둘째 줄에 여행 계획에 속한 도시들의 수 M이 주어진다. M은 1000이하이다. 다음 N * N 행렬을 통해 임의의 두 도시가 연결되었는지에 관한 정보가 주어진다. 1이면 연결된 것이고 0이면 연결이 되지 않은 것이다. A와 B가 연결되었으면 B와 A도 연결되어 있다. 마지막 줄에는 여행 계획이 주어진다.

출력
첫 줄에 가능하면 YES 불가능하면 NO를 출력한다.

풀이:
유니온 파인드 연습 문제
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;
    public static int[] parent;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        parent = new int[N + 1];
        for (int i = 1; i <= N ; i++) {
            parent[i] = i;
        }

        for (int i = 1; i <= N ; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N ; j++) {
                if(Integer.parseInt(st.nextToken()) == 1)
                    union(i, j);
            }
        }
        st = new StringTokenizer(br.readLine());
        int prev = find(Integer.parseInt(st.nextToken()));
        boolean flag = true;
        for (int i = 0; i < M - 1  ; i++) {
            int now = find(Integer.parseInt(st.nextToken()));
            if(prev != now){
                flag = false;
                break;
            }
            prev = now;
        }
        if(flag)
            bw.write("YES");
        else
            bw.write("NO");
        bw.flush();
        bw.close();
    }
    public static int find(int now){
        if(now == parent[now])
            return now;
        else
            return parent[now] = find(parent[now]);
    }
    public static void union(int x, int y){
        x = find(x);
        y = find(y);

        if(x != y)
            parent[y] = x;
    }
}