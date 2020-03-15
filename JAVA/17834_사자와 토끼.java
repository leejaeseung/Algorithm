/*
문제
사자와 토끼는 전국적으로 인기를 끌고 있는 재밌는 보드게임이다. 사자와 토끼를 즐기기 위해서는 2명의 플레이어와 1명의 심판이 필요하다. 보드판은 N개의 수풀과 M개의 오솔길로 이루어져 있다. 오솔길은 서로 다른 두 수풀을 양방향으로 연결하며, 어떤 수풀에서 다른 수풀까지 1개 이상의 오솔길을 통하면 반드시 도달 할 수 있다.

게임은 다음과 같은 순서로 이루어진다.



심판이 사자와 토끼의 초기 위치를 각각 어느 수풀로 할지 정한다. 사자와 토끼의 초기 위치는 같을 수 없으며, 사자의 위치는 사자 플레이어에게만, 토끼의 위치는 토끼 플레이어에게만 알려준다.

매 턴마다, 사자와 토끼는 현재 위치한 수풀에서 오솔길 1개를 따라 이동해야 한다. 두 플레이어는 자신의 말을 이동할 위치를 심판에게만 말한다. 이동하지 않을 수는 없다.

이동한 후, 사자와 토끼가 같은 수풀에 있다면 사자가 토끼를 잡아먹어 게임이 끝난다. 그렇지 않다면, 다시 2로 돌아가 턴을 계속하여 진행한다. 물론 게임이 끝나지 않는 이상, 이동 후에도 두 플레이어는 상대 말의 위치를 알 수 없다. 또한, 사자는 오솔길 위에서는 토끼를 볼 수 없기 때문에, 같은 오솔길을 통해 이동하여도 서로 다른 수풀에 도착했다면 게임이 끝나지 않는다.

이렇게 서로 심리전을 통해 토끼는 사자에게서 도망가고, 사자는 토끼를 찾아내는 게임이다. 그런데 보드의 모양과 사자와 토끼의 초기 위치에 따라서, 어떻게 움직여도 영원히 게임이 끝나지 않는 경우가 있다는 것을 발견했다. 예를 들어, 위의 그림과 같은 보드판에서는 게임이 끝나지 않는 (사자의 초기 위치, 토끼의 초기 위치)의 조합은 다음과 같이 8가지가 존재한다 : (1,2) (1,4) (2,1) (2,3) (3,2) (3,4) (4,1) (4,3). 이런 경우에는, 심지어 두 플레이어가 서로의 위치를 알고 일부러 게임을 끝내려고 해도 끝낼 수 없다!

보드판의 모양이 주어질 때, 어떻게 움직여도 영원히 게임이 끝나지 않는 초기 위치의 경우의 수가 몇 가지가 있을지 구해보자.

입력
첫 번째 줄에 수풀의 수 N(2 ≤ N ≤ 50,000)과 오솔길의 수 M(1 ≤ M ≤ 500,000)이 공백으로 구분되어 주어진다.

두 번째 줄부터 M개의 줄에 걸쳐, u, v(1 ≤ u,v ≤ N, u ≠ v)가 공백으로 구분되어 주어진다. 이는 u번 수풀과 v번 수풀이 오솔길로 연결되어 있음을 의미한다.

출력
첫 번째 줄에 어떻게 움직여도 영원히 게임이 끝나지 않는 초기 위치의 경우의 수를 출력한다.

답이 32-bit형 정수(int)의 최대값보다 클 수 있음에 주의하자.
풀이 : 이분 그래프로 생각하여 정점을 탐색하면서 번갈아가며 true,false를 지정합니다.(두가지 색을 칠한다고 생각)
만약 이미 방문한 점인데 같은 색이라면 0을 리턴합니다.
(true개수)P1 (false개수)P1 2 개가 답입니다.
 */

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int N,M;
    public static ArrayList<Node> nd;
    public static boolean[] visit;
    public static void main(String[] argc) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        visit = new boolean[N + 1];
        nd = new ArrayList<>();
        for (int i = 0; i <= N ; i++) {
            nd.add(new Node(i));
        }
        for (int i = 0; i < M ; i++) {
            int from,to;
            st = new StringTokenizer(br.readLine());
            from = Integer.parseInt(st.nextToken());
            to = Integer.parseInt(st.nextToken());
            nd.get(from).next.add(nd.get(to));
            nd.get(to).next.add(nd.get(from));
        }
        long t_v = Search();
        long f_v = N - t_v;
        long res = Perm(t_v, 1) * Perm(f_v, 1) * 2;
        bw.write(Long.toString(res));
        bw.flush();
        bw.close();
    }
    public static long Perm(long n,long r){
        long res = 1;
        for (long i = 0; i < r; i++) {
            res *= (n - i);
        }
        return res;
    }

    public static long Search(){
        Queue<Node> q = new LinkedList<>();
        long cnt = 0;
        q.offer(nd.get(1));
        visit[1] = true;
        nd.get(1).v = true;

        while(!q.isEmpty()){
            Node now = q.poll();

            if(now.v)
                cnt++;

            for (int i = 0; i < now.next.size() ; i++) {
                Node nxt = now.next.get(i);

                if(!visit[nxt.num]){
                    visit[nxt.num] = true;
                    nxt.v = !now.v;
                    q.offer(nxt);
                }
                else{
                    if(nxt.v == now.v)
                        return 0;
                }
            }
        }
        return cnt;
    }
}

class Node{

    public int num;
    public boolean v = false;
    public ArrayList<Node> next;
    public Node(int num){
        this.num = num;
        next = new ArrayList<>();
    }
}