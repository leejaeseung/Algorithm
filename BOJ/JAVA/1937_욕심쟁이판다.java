/*
문제
n*n의 크기의 대나무 숲이 있다. 욕심쟁이 판다는 어떤 지역에서 대나무를 먹기 시작한다. 그리고 그 곳의 대나무를 다 먹어 치우면 상, 하, 좌, 우 중 한 곳으로 이동을 한다. 그리고 또 그곳에서 대나무를 먹는다. 그런데 단 조건이 있다. 이 판다는 매우 욕심이 많아서 대나무를 먹고 자리를 옮기면 그 옮긴 지역에 그 전 지역보다 대나무가 많이 있어야 한다. 만약에 그런 지점이 없으면 이 판다는 불만을 가지고 단식 투쟁을 하다가 죽게 된다(-_-)

이 판다의 사육사는 이런 판다를 대나무 숲에 풀어 놓아야 하는데, 어떤 지점에 처음에 풀어 놓아야 하고, 어떤 곳으로 이동을 시켜야 둘 다 소중한 생명이지만 판다가 최대한 오래 살 수 있는지 고민에 빠져 있다. 우리의 임무는 이 사육사를 도와주는 것이다. n*n 크기의 대나무 숲이 주어져 있을 때, 이 판다가 최대한 오래 살려면 어떤 경로를 통하여 움직여야 하는지 구하여라.

입력
첫째 줄에 대나무 숲의 크기 n(1 ≤ n ≤ 500)이 주어진다. 그리고 둘째 줄부터 n+1번째 줄까지 대나무 숲의 정보가 주어진다. 대나무 숲의 정보는 공백을 사이로 두고 각 지역의 대나무의 양이 정수 값으로 주어진다. 대나무의 양은 1,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에는 판다가 최대한 살 수 있는 일수(K)를 출력한다.

풀이:
dp[i][j] = (i,j) 에서 최대한 살 수 있는 일 수.
dfs로 푸는게 나은 것 같다.
경로가 이미 구해졌다면 그 값을 리턴한다.
dfs로 재귀적으로 탐색하면서 현재의 최대 일 수는 다음 노드들의 최대 일 수 + 1 중에 가장 큰 값이다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N, res = 0;
    public static int[][] map;
    public static int[] mv1 = {0,0,1,-1};
    public static int[] mv2 = {1,-1,0,0};
    public static int[][] dp;
    public static PriorityQueue<XY> q = new PriorityQueue<>(new Comparator<XY>() {
        @Override
        public int compare(XY xy, XY t1) {
            return xy.v >= t1.v ? 1 : -1;
        }
    });
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        dp = new int[N][N];


        for (int i = 0; i < N ; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                q.offer(new XY(i, j, map[i][j]));
            }
        }
        BFS();
        System.out.println(res);

    }
    public static void BFS() {
        while (!q.isEmpty()) {
            XY now = q.poll();

            int max = 0;

            for (int i = 0; i < 4; i++) {
                int next_x = now.x + mv1[i];
                int next_y = now.y + mv2[i];

                if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) continue;
                if ((map[next_x][next_y] < map[now.x][now.y])) {
                    if (dp[next_x][next_y] > max)
                        max = dp[next_x][next_y];
                }
            }
            dp[now.x][now.y] = max + 1;
            res = Math.max(dp[now.x][now.y], res);
        }
    }
}

class XY{
    int x;
    int y;
    int v;
    public XY(int x, int y, int v){
        this.x = x;
        this.y = y;
        this.v = v;
    }
}