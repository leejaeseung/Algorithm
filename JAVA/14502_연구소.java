/*
    문제
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.

연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 

일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.

2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

2 1 0 0 1 1 0
1 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 1 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

2 1 0 0 1 1 2
1 0 1 0 1 2 2
0 1 1 0 1 2 2
0 1 0 0 0 1 2
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.

연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)

둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.

빈 칸의 개수는 3개 이상이다.

출력
첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.
    풀이 : BFS로 감염된 수를 세고, 브루트 포스로 감염된 수의 최솟값을 구한다.
    맨 처음에 구한 0의 개수 - 감염된 수
 */
import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static int[][] map;
    public static int N,M;
    public static int[] mv1 = {0,0,1,-1};
    public static int[] mv2 = {1,-1,0,0};
    public static int min = Integer.MAX_VALUE;
    public static ArrayList<XY> zero = new ArrayList<>();
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int count = 0;

        map = new int[N][M];

        for (int i = 0; i < N ; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 0) {
                    zero.add(new XY(i, j));
                    count++;
                }
            }
        }

        BF(0, 0);

        System.out.println(count - min - 3);
    }
    public static void BF(int count, int index){
        if(count == 3){
            min = Math.min( min , BFS_count() );
            return;
        }

        if(count == 0){
            for (int i = index; i < zero.size() - 2 ; i++) {
                map[zero.get(i).x][zero.get(i).y] = 1;
                BF(count + 1, i + 1);
                map[zero.get(i).x][zero.get(i).y] = 0;
            }
        }
        if(count == 1){
            for (int i = index; i < zero.size() - 1 ; i++) {
                map[zero.get(i).x][zero.get(i).y] = 1;
                BF(count + 1, i + 1);
                map[zero.get(i).x][zero.get(i).y] = 0;
            }
        }
        if(count == 2){
            for (int i = index; i < zero.size(); i++) {
                map[zero.get(i).x][zero.get(i).y] = 1;
                BF(count + 1, i);
                map[zero.get(i).x][zero.get(i).y] = 0;
            }
        }
    }
    public static int BFS_count(){
        Queue<XY> q=new LinkedList<>();
        boolean[][] visit = new boolean[N][M];
        int cnt = 0;

        for (int i = 0; i < N ; i++) {
            for (int j = 0; j < M ; j++) {
                if(map[i][j] == 2) {
                    q.offer(new XY(i, j));
                    visit[i][j] = true;
                }
            }
        }
        while (!q.isEmpty()){
            XY temp = q.poll();

            for (int i = 0; i < 4 ; i++) {
                int next_x = temp.x + mv1[i];
                int next_y = temp.y + mv2[i];

                if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= M ) continue;
                if(map[next_x][next_y] == 1)    continue;
                if(!visit[next_x][next_y]){
                    q.offer(new XY(next_x , next_y));
                    visit[next_x][next_y] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
}

class XY{

    public int x;
    public int y;
    public XY(int x,int y){
        this.x = x;
        this.y = y;
    }
}