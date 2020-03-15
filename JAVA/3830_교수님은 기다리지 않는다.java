/*
문제
상근이는 매일 아침 실험실로 출근해서 샘플의 무게를 재는 일을 하고 있다. 상근이는 두 샘플을 고른 뒤, 저울을 이용해서 무게의 차이를 잰다.

교수님의 마음에 들기 위해서 매일 아침부터 무게를 재고 있지만, 가끔 교수님이 실험실에 들어와서 상근이에게 어떤 두 샘플의 무게의 차이를 물어보기도 한다. 이때, 상근이는 지금까지 잰 결과를 바탕으로 대답을 할 수도 있고, 못 할 수도 있다.

상근이는 결과를 출근한 첫 날부터 공책에 적어 두었다. 하지만, 엄청난 양의 무게가 적혀있기 때문에, 교수님의 질문에 재빨리 대답할 수가 없었다. 이런 상근이를 위해서 프로그램을 만들려고 한다.

상근이가 실험실에서 한 일이 순서대로 주어진다. 어떤 두 샘플의 무게의 차이를 구할 수 있는지 없는지를 알아내는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다.

각 테스트 케이스의 첫째 줄에는 샘플의 종류의 개수 N (2 ≤ N ≤ 100,000)과 상근이가 실험실에서 한 일의 수 M (1 ≤ M ≤ 100,000)이 주어진다. 샘플은 1번부터 N번까지 번호가 매겨져 있다. 다음 M개 줄에는 상근이가 실험실에서 한 일이 주어진다.

상근이가 무게를 쟀다면, ! a b w와 같은 형식으로 주어진다. 이 뜻은 b가 a보다 w그램 무겁다는 뜻이다. (a ≠ b) w는 1,000,000을 넘지 않는 음이 아닌 정수이다. 모든 측정은 정확하고, 일관성을 유지한다.

교수님의 질문은 ? a b와 같은 형식으로 주어진다. 이 뜻은 b가 a보다 얼마나 무거운지를 출력하라는 뜻이다.

마지막 줄에는 0이 두 개 주어진다.

출력
교수님의 질문 (? a b)이 입력으로 들어올 때 마다, 지금까지 측정한 결과를 바탕으로 a와 b의 무게 차이를 계산할 수 있다면, b가 a보다 얼마나 무거운지를 출력한다. 무게의 차이의 절댓값이 1,000,000을 넘지 않는다. 만약, 측정한 결과를 바탕으로 무게의 차이를 계산할 수 없다면, "UNKNOWN"을 출력한다.

풀이:
dist 배열의 의미는 dist[x] = x에서 x의 루트까지의 상대적 거리로 정의한다.
따라서 a,b 의 상대적 무게 차이는 dist[b] - dist[a] 이다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int[] dist;
    public static int[] parent;
    public static int w;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while(true){
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            parent = new int[N + 1];
            dist = new int[N + 1];

            for (int j = 0; j <= N ; j++) {
                parent[j] = j;
            }

            if(N == 0 && M == 0)
                break;

            for (int i = 0; i < M ; i++) {
                st = new StringTokenizer(br.readLine());
                String q = st.nextToken();
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());


                if(q.charAt(0) == '!'){
                    w = Integer.parseInt(st.nextToken());

                    union(a, b, w);
                }
                else{

                    if(find(a) != find(b)){
                        bw.write("UNKNOWN\n");
                    }
                    else{
                        bw.write(dist[b] - dist[a] + "\n");
                    }
                }
            }
        }
        bw.flush();
        bw.close();
    }
    public static void union(int son, int pa, int w){
        int pson = find(son);
        int ppa = find(pa);

        if(pson != ppa) {
            parent[ppa] = pson;
            dist[ppa] = dist[son] - dist[pa] + w;
        }
    }
    public static int find(int now){
        if(now == parent[now])
            return now;
        int p = find(parent[now]);
        //find를 할 때마다 dist가 갱신되지 않게 먼저 루트를 찾아준다.
        dist[now] += dist[parent[now]];
        return parent[now] = p;
    }
}