/*
문제
세준이는 등산광이다. 세준이는 높은 곳에서 도시를 내려다 보는 것을 좋아한다. 하지만, 겁이 많은 세준이는 어두워지기 전에 호텔로 내려오려고 한다.

세준이가 가려고하는 산의 지도가 입력으로 주어진다. 산의 지도를 M이라고 했을 때, M[i][j]는 (i,j)의 높이가 M[i][j]라는 것을 의미한다. 그 값이 'A'-'Z'일 때는 0-25를 뜻하는 것이고, 'a'-'z'일 때는, 26-51을 뜻한다.

세준이의 호텔은 (0,0)에 위치해 있다. 그리고, 세준이는 지금위치에서 바로 인접한 정수 좌표 중 높이의 차이가 T보다 크지 않은 곳으로만 다닐 수 있다.

만약 세준이가 현재 위치에서 높이가 낮은 곳이나 같은 곳으로 이동한다면 시간은 1초가 걸린다. 하지만 높은 곳으로 이동한다면 두 위치의 높이의 차이의 제곱만큼 시간이 걸린다. 예를 들어 높이가 5에서 높이가 9인 곳으로 간다면, 시간은 (5-9)^2=16이 걸린다. 하지만, 높이가 9인 곳에서 5인 곳으로 간다면 시간은 1이 걸린다.

산의 지도와, T, 그리고 어두워지는 시간 D가 주어졌을 때, 세준이가 D보다 크지 않은 시간동안 올라갈 수 있는 최대 높이를 구하는 프로그램을 작성하시오.(세준이는 호텔에서 출발해서 호텔로 돌아와야 한다.)

입력
첫째 줄에 산의 세로크기 N과 가로크기 M 그리고, T와 D가 주어진다. N과 M은 25보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 지도가 주어진다. T는 52보다 작거나 같은 자연수이고, D는 1,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 세준이가 갈 수 있는 가장 높은 곳의 위치를 출력한다.

풀이:
총 N * M 개의 노드가 생기므로 플로이드 와샬 알고리즘을 위해 dist[N * M][N * M] 의 배열을 만듭니다.
map의 모든 점에 대하여 상하좌우에 대한 간선에 가중치를 부여합니다.(차의 절대값이 T보다 크면 연결하지 않습니다.)
플로이드 와샬 알고리즘으로 모든 점에 대한 최단 거리를 구하고
(0,0)으로 돌아올 수 있는 값 == dist[0][x] + dist[x][0] <= D 중 최대값을 구합니다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N, M, T, D;
    public static int[][] map;
    public static int[][] dist;
    public static int[] dir1 = {0,0,1,-1};
    public static int[] dir2 = {1,-1,0,0};
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        dist = new int[N * M][N * M];
        for (int i = 0; i < N * M; i++) {
            for (int j = 0; j < N * M ; j++) {
                dist[i][j] = 1000000000;
                if(i == j)
                    dist[i][j] = 0;
            }
        }

        for (int i = 0; i < N ; i++) {
            String str = br.readLine();
            for (int j = 0; j < M ; j++) {
                char c = str.charAt(j);
                if(c >= 'A' && c <= 'Z')
                    map[i][j] = c - 'A';
                else
                    map[i][j] = c - 'a' + 26;
            }
        }
        for (int i = 0; i < N ; i++) {
            for (int j = 0; j < M ; j++) {
                for (int k = 0; k < 4 ; k++) {
                    XY next = new XY(i + dir1[k], j + dir2[k]);
                    if(next.x < 0 || next.x >= N || next.y < 0 || next.y >= M)  continue;
                    int now_Node = i * M + j;
                    int next_Node = next.x * M + next.y;
                    if(Math.abs(map[i][j] - map[next.x][next.y]) > T)  continue;
                    if(map[i][j] < map[next.x][next.y]){
                        dist[now_Node][next_Node] = (int)Math.pow(Math.abs(map[i][j] - map[next.x][next.y]), 2);
                    }
                    else{
                        dist[now_Node][next_Node] = 1;
                    }
                }
            }
        }
        Floid();

        int max = 0;

        for (int i = 0; i < N * M ; i++) {
                if(dist[0][i] + dist[i][0] <= D)
                    max = Math.max(max, map[i / M][i % M]);
        }
        bw.write(Integer.toString(max));
        bw.flush();
        bw.close();
    }
    public static void Floid(){
        for (int i = 0; i < N * M ; i++) {
            for (int j = 0; j < N * M ; j++) {
                for (int k = 0; k < N * M ; k++) {
                    dist[j][k] = Math.min(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
        }
    }
}

class XY {
    int x;
    int y;
    public XY(int x, int y){
        this.x = x;
        this.y = y;
    }
}