/*
제
트리 T는 아래 그림 1과 같은 구조를 가지고 있으며 원은 ‘정점’이라 하고, 정점과 정점을 연결하는 선을 ‘에지’라 한다. 특히 가장 위에 위치한 정점을 ‘루트’라 하는데 오직 하나만 있다. N개의 정점들은 숫자 1부터 N으로 표현하고 루트는 항상 1이다.

두 정점 v와 w를 연결하는 경로는 정점들의 순서리스트 (v0, v1, ..., vm)로, 정점 vi와 vi+1은 에지로 연결되고 v0 = v, vm = w이다. 트리에서는 임의의 두 정점 v와 w 사이에 항상 두 정점을 연결하는 경로가 오직 하나만 존재한다. 예를 들어, 그림 1에서 정점 3과 11 사이의 유일한 경로는 (3, 4, 1, 7, 11)이다.



그림 1

각 정점 v에서 루트 r과 연결하는 유일한 경로 P에 대해서 정점 v와 에지로 연결된 정점 중에서 P상에 있는 정점을 v의 ‘부모 정점’이라고 한다. 예를 들어, 그림 1에서 4, 7, 9의 부모 정점은 1이고, 2와 11의 부모 정점은 7이다.

트리 T에서 어떤 두 정점을 연결하는 에지를 제거하면 그 두 정점 외에도 경로가 존재하지 않는 정점 쌍이 있을 수 있다. 여러분은 “정점 v와 w를 연결하는 경로가 존재하는가?”와 같은 질의에 답해야 한다. 예를 들어, 그림 1에서 7과 11 사이의 에지를 제거하면 8과 5를 연결하는 경로는 존재하지 않는다.

트리 정보가 주어지고, 에지의 제거 정보와 질의가 임의의 순서로 주어질 때, 작업을 순서대로 수행하며 질의에 대한 답을 출력하는 프로그램을 작성하시오.

입력
표준 입력으로 다음 정보가 주어진다. 첫 번째 줄에는 트리의 정점의 개수와 질의의 개수를 나타내는 두 정수 N과 Q (1 ≤ N, Q ≤ 200,000)가 주어진다. 다음 N-1개의 줄의 i번째 줄에는 정점 i+1의 부모 정점을 나타내는 정수 a가 주어진다 (1 ≤ a ≤ N). 다음 (N-1)+Q개의 줄 중에서 N-1개는 (1)의 형태로, Q개는 (2)의 형태로 주어진다. (1) 두 정수 x와 b가 주어진다(x = 0, 2 ≤ b ≤ N). 이것은 b의 부모 정점과 b를 연결하는 에지를 제거함을 의미한다. 각 줄의 b는 모두 다르다. (2) 세 정수 x, c, d가 주어진다 (x = 1, 1 ≤ c, d ≤ N). 이것은 c와 d를 연결하는 경로가 존재하는 지 묻는 질의를 의미한다.

출력
표준 출력으로 질의에 대한 답을 순서대로 Q개의 줄에 출력한다. 각 줄마다 경로가 존재하면 YES를 아니면 NO를 출력한다.

풀이:
유니온 파인드와 오프라인 쿼리 문제이다.
질문의 순서를 역순으로 바꾸어 풀이한다.
즉, 간선을 끊어라 -> 간선을 이어라 로 바꾸어 풀이한다.
답도 마찬가지로 역순으로 출력한다.
 */
import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static int N, Q;
    public static int[] parent;
    public static int[] n_parent;
    public static Stack<String> query = new Stack<>();
    public static Stack<String> answer = new Stack<>();
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        parent = new int[N + 1];
        n_parent = new int[N + 1];

        for (int i = 1; i <= N ; i++) {
            parent[i] = i;
            n_parent[i] = i;
        }

        for (int i = 2; i <= N ; i++) {
            parent[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 0; i < Q + N - 1 ; i++) {
            query.push(br.readLine());
        }
        while(!query.isEmpty()){
            st = new StringTokenizer(query.pop());
            int x = Integer.parseInt(st.nextToken());

            if(x == 0){
                int b = Integer.parseInt(st.nextToken());

                n_parent[b] = parent[b];
            }
            else{
                int c = Integer.parseInt(st.nextToken());
                int d = Integer.parseInt(st.nextToken());

                if(find(c) == find(d))
                    answer.push("YES");
                else
                    answer.push("NO");
            }
        }
        while (!answer.isEmpty()){
            bw.write(answer.pop() + "\n");
        }
        bw.flush();
        bw.close();
    }
    public static int find(int now){
        if(now == n_parent[now])
            return now;
        return n_parent[now] = find(n_parent[now]);
    }
}