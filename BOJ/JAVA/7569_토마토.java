/*
    문제
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자모양 상자의 칸에 하나씩 넣은 다음, 상자들을 수직으로 쌓아 올려서 창고에 보관한다.



창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H가 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다. 둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다. 각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 이러한 N개의 줄이 H번 반복하여 주어진다.

출력
여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
    풀이 :
    BFS 문제.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N,M,H;
    public static int[] mv_1={0,0,0,0,1,-1};
    public static int[] mv_2={1,-1,0,0,0,0};
    public static int[] mv_3={0,0,1,-1,0,0};
    public static Queue<XYZ> q;
    public static int zero_count=0;
    public static boolean[][][] visit;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st=new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());
        H=Integer.parseInt(st.nextToken());
        q=new LinkedList<>();

        boolean[][][] map=new boolean[H][M][N];
        visit=new boolean[H][M][N];

        for (int i = 0; i <H ; i++) {
            for (int j = 0; j <M ; j++) {
                st=new StringTokenizer(br.readLine());
                for (int k = 0; k <N ; k++) {
                    int info=Integer.parseInt(st.nextToken());
                    //map[i][j][k]=info;
                    if(info==1) {
                        q.offer(new XYZ(k, j, i));
                        map[i][j][k]=true;
                    }
                    if(info==0) {
                        zero_count++;
                    }
                    else{
                        map[i][j][k]=true;
                    }
                }
            }
        }
        if(zero_count==0)
            System.out.println(0);
        else
            System.out.println(BFS(map));

    }
    public static int BFS(boolean[][][] map){
        int day=0;

        while(!q.isEmpty()){
            int qs=q.size();

            for (int l = 0; l <qs ; l++) {
                int pos1 = q.peek().x;
                int pos2 = q.peek().y;
                int pos3 = q.peek().z;
                q.poll();
                if(visit[pos3][pos2][pos1])
                    continue;
                visit[pos3][pos2][pos1]=true;
                if (!map[pos3][pos2][pos1]) {
                    zero_count--;
                    if(zero_count==0)
                        return day;
                    map[pos3][pos2][pos1] = true;
                }

                for (int i = 0; i < 6; i++) {
                    int next_pos1 = pos1 + mv_1[i];
                    int next_pos2 = pos2 + mv_2[i];
                    int next_pos3 = pos3 + mv_3[i];
                    if (next_pos1 < 0 || next_pos1 >= N || next_pos2 < 0 || next_pos2 >= M || next_pos3 < 0 || next_pos3 >= H)
                        continue;
                    if (map[next_pos3][next_pos2][next_pos1])
                        continue;
                    q.offer(new XYZ(next_pos1, next_pos2, next_pos3));
                }
            }
                day++;
        }
        return -1;
    }
}

class XYZ{
    public int x;
    public int y;
    public int z;
    public XYZ(int x,int y,int z){
        this.x=x;
        this.y=y;
        this.z=z;
    }
}