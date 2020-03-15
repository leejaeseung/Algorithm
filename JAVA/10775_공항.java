/*
문제
오늘은 신승원의 생일이다.

박승원은 생일을 맞아 신승원에게 인천국제공항을 선물로 줬다.

공항에는 G개의 게이트가 있으며 각각은 1에서 G까지의 번호를 가지고 있다.

공항에는 P개의 비행기가 순서대로 도착할 예정이며, 당신은 i번째 비행기를 1번부터 gi (1 ≤ gi ≤ G) 번째 게이트중 하나에 영구적으로 도킹하려 한다. 비행기가 도킹된 게이트에는 다른 비행기가 도착할 수 없다.

이렇게 공항을 운영할 경우 간혹 비행기가 어떤 곳에도 도킹하지 못하는 사고가 발생한다. 이러한 사고가 일어나면 공항의 평판이 급속히 나빠져, 이후 어떤 비행기도 도착하지 않으려 할 것이다.

신승원은 가장 많은 비행기를 공항에 도킹시켜서 박승원을 행복하게 하고 싶어한다. 승원이는 비행기를 최대 몇 대 도킹시킬 수 있는가?

입력
첫 번째 줄에는 게이트의 수 G (1 ≤ G ≤ 105)가 주어진다.

두 번째 줄에는 비행기의 수 P (1 ≤ P ≤ 105)가 주어진다.

이후 P개의 줄에 gi (1 ≤ gi ≤ G) 가 주어진다.

출력
승원이가 도킹시킬 수 있는 최대의 비행기 수를 출력한다.

풀이:
게이트마다 노드가 하나씩 있고, 최우선으로 자기 자신을 선택하거나, 자기자신 - 1 을 선택하는게 최선이다.
부모 노드를 Root - 1 로 설정해가며 Root가 0이라면 게이트가 꽉 찬 것이다.
 */
import java.io.*;

public class Main {

    public static int G, P;
    public static int[] parent;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        G = Integer.parseInt(br.readLine());
        P = Integer.parseInt(br.readLine());

        parent = new int[G + 1];

        for (int i = 0; i <= G ; i++) {
            parent[i] = i;
        }

        int cnt = 0;
        for (int i = 0; i < P ; i++) {
            int now = Integer.parseInt(br.readLine());

            int p = find(now);
            if(p != 0){
                union(p, p - 1);
                cnt++;
            }
            else
                break;
        }
        System.out.println(cnt);
    }
    public static int find(int now){
        if(now == parent[now])
            return now;
        return parent[now] = find(parent[now]);
    }
    public static void union(int x, int y){
        x = find(x);
        y = find(y);

        if(x == y)  return;
        parent[x] = y;
    }
}