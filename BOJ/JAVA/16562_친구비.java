/*
문제
19학번 이준석은 학생이 N명인 학교에 입학을 했다. 준석이는 입학을 맞아 모든 학생과 친구가 되고 싶어한다. 하지만 준석이는 평생 컴퓨터랑만 대화를 하며 살아왔기 때문에 사람과 말을 하는 법을 모른다. 그런 준석이에게도 희망이 있다. 바로 친구비다!

학생 i에게 Ai만큼의 돈을 주면 그 학생은 1달간 친구가 되어준다! 준석이에게는 총 k원의 돈이 있고 그 돈을 이용해서 친구를 사귀기로 했다. 막상 친구를 사귀다 보면 돈이 부족해질 것 같다는 생각을 하게 되었다. 그래서 준석이는 “친구의 친구는 친구다”를 이용하기로 했다.

준석이는 이제 모든 친구에게 돈을 주지 않아도 된다!

위와 같은 논리를 사용했을 때, 가장 적은 비용으로 모든 사람과 친구가 되는 방법을 구하라.

입력
첫 줄에 학생 수 N (1 ≤ N ≤ 10,000)과 친구관계 수 M (0 ≤ M ≤ 10,000), 가지고 있는 돈 k (1 ≤ k ≤ 10,000,000)가 주어진다.

두번째 줄에 N개의 각각의 학생이 원하는 친구비 Ai가 주어진다. (1 ≤ Ai ≤ 10,000, 1 ≤ i ≤ N)

다음 M개의 줄에는 숫자 v, w가 주어진다. 이것은 학생 v와 학생 w가 서로 친구라는 뜻이다.

출력
준석이가 모든 학생을 친구로 만들 수 있다면, 친구로 만드는데 드는 최소비용을 출력한다. 만약 친구를 다 사귈 수 없다면, “Oh no”(따옴표 제거)를 출력한다.

풀이 : 노드들을 재귀적으로 탐색하면서 부모 노드를 지정해줍니다.
부모 노드가 이미 정해진 노드들은 탐색할 필요가 없지만
부모 노드보다 친구비가 적을 수 있으므로 친구비의 최소값을 갱신해줍니다.
구해진 친구비 최소값들의 합을 가지고 있는 돈과 비교하여 출력합니다.
 */

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static ArrayList<Node> friend = new ArrayList<>();
    public static int N,M,K;
    public static int[] parent;
    public static long[] money;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        parent = new int[N + 1];
        money = new long[N + 1];
        for (int i = 0; i <= N ; i++) {
            money[i] = Long.MAX_VALUE;
        }

        st = new StringTokenizer(br.readLine());
        friend.add(new Node(0, 0));
        for (int i = 1; i <= N ; i++) {
            friend.add(new Node(i, Long.parseLong(st.nextToken())));
            parent[i] = i;
        }
        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            friend.get(from).next.add(friend.get(to));
            friend.get(to).next.add(friend.get(from));
        }

        for (int i = 1; i <= N ; i++) {
            if( i == parent[i]) {
                getParent(i, i);
            }
            money[parent[i]] = Math.min(money[parent[i]], friend.get(i).money);
        }
        long sum = 0;
        for (int i = 1; i <money.length ; i++) {
            if(money[i] != Long.MAX_VALUE){
                sum += money[i];
            }
        }
        if(K < sum)
            bw.write("Oh no");
        else
            bw.write(Long.toString(sum));
        bw.flush();
        bw.close();
    }
    public static void getParent(int now, int start){
            parent[now] = start;
            for (int i = 0; i < friend.get(now).next.size() ; i++) {
                int next = friend.get(now).next.get(i).num;
                if(next != start){
                    if(next == parent[next])
                        getParent(next, start);
                }
            }
    }
}

class Node{

    public int num;
    public long money;
    public ArrayList<Node> next;
    public Node(int num, long money){
        this.num = num;
        this.money = money;
        next = new ArrayList<>();
    }
}