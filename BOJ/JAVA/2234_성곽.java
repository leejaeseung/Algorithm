/*
    문제


대략 위의 그림과 같이 생긴 성곽이 있다. 굵은 선은 벽을 나타내고, 점선은 벽이 없어서 지나다닐 수 있는 통로를 나타낸다. 이러한 형태의 성의 지도를 입력받아서 다음을 계산하는 프로그램을 작성하시오.

이 성에 있는 방의 개수
가장 넓은 방의 넓이
하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
위의 예에서는 방은 5개고, 가장 큰 방은 9개의 칸으로 이루어져 있으며, 위의 그림에서 화살표가 가리키는 벽을 제거하면 16인 크기의 방을 얻을 수 있다.

성은 m×n(1 ≤ m, n ≤ 50)개의 정사각형 칸으로 이루어진다. 성에는 최소 두 개의 방이 있어서, 항상 하나의 벽을 제거하여 두 방을 합치는 경우가 있다.

입력
첫째 줄에 두 정수 n, m이 주어진다. 다음 m개의 줄에는 n개의 정수로 벽에 대한 정보가 주어진다. 벽에 대한 정보는 한 정수로 주어지는데, 서쪽에 벽이 있을 때는 1을, 북쪽에 벽이 있을 때는 2를, 동쪽에 벽이 있을 때는 4를, 남쪽에 벽이 있을 때는 8을 더한 값이 주어진다. 참고로 이진수의 각 비트를 생각하면 쉽다. 따라서 이 값은 0부터 15까지의 범위 안에 있다.

출력
첫째 줄에 1의 답을, 둘째 줄에 2의 답을, 셋째 줄에 3의 답을 출력한다.
    풀이 :
    셋째 조건 - visit을 boolean 대신 int로 선언해 이미 들린 방은 그 방의 번호를 visit으로 정해준다.
    각 방의 노드를 만들어 그 노드들은 자신의 방 번호, 방 크기, 인접한 방 번호를 갖게 한다.
    BFS로 탐색할 때, 벽 너머를 보고 그 방의 번호(visit)을 체크해 인접한 방임을 노드에 등록한다.
    노드들을 탐색해 인접한 방과 방 크기를 합한 것의 최대가 벽 하나를 허물었을 때의 최대 방 개수이다.
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static int[][] map;
    public static int[] mv1={0,-1,0,1};
    public static int[] mv2={-1,0,1,0};
    public static int[][] visit;
    public static int N,M;
    public static int room_cnt=0;
    public static int room_max=0;
    public static int can_max=0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st=new StringTokenizer(br.readLine());
        N=Integer.parseInt(st.nextToken());
        M=Integer.parseInt(st.nextToken());
        map=new int[M][N];
        visit=new int[M][N];
        Vector<Room> vt=new Vector<>();

        for (int i = 0; i <M ; i++) {
            st=new StringTokenizer(br.readLine());
            for (int j = 0; j <N ; j++) {
                map[i][j]=Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i <M ; i++) {
            for (int j = 0; j <N ; j++) {
                if(visit[i][j]==0){
                    room_cnt++;
                    vt.add(new Room(room_cnt));
                    vt.get(room_cnt-1).roomsize=BFS(new XY(i,j),room_cnt,vt);
                    room_max=Math.max(vt.get(room_cnt-1).roomsize,room_max);
                }
            }
        }
        for (int i = 0; i <vt.size() ; i++) {
            for (int j = 0; j <vt.get(i).around.size() ; j++) {
                can_max=Math.max(can_max,vt.get(i).roomsize+vt.get(vt.get(i).around.get(j)-1).roomsize);
            }
        }
        System.out.println(room_cnt);
        System.out.println(room_max);
        System.out.println(can_max);
    }
    public static int BFS(XY start,int room_num,Vector<Room> vt){
        Queue<XY> q=new LinkedList<>();
        int cnt=0;
        q.offer(start);

        while(!q.isEmpty()){
            XY temp=q.poll();
            if(visit[temp.x][temp.y]!=0)    continue;
            visit[temp.x][temp.y]=room_num;
            cnt++;

            int mv_count=0;
            for (int i = 1; i <=8 ; i*=2) {
                int next_x=temp.x+mv1[mv_count];
                int next_y=temp.y+mv2[mv_count];
                mv_count++;
                if(next_x<0||next_x>=M||next_y<0||next_y>=N)    continue;
                if(check_dir(map[temp.x][temp.y],i)){
                    if(visit[next_x][next_y]==0) {
                        q.offer(new XY(next_x, next_y));
                    }
                }
                else{
                    if(visit[next_x][next_y]!=0&&visit[next_x][next_y]!=room_num) {
                        if(!vt.get(room_num-1).around.contains(visit[next_x][next_y])){
                            vt.get(room_num-1).around.add(visit[next_x][next_y]);
                        }
                        if(!vt.get(visit[next_x][next_y]-1).around.contains(room_num)){
                            vt.get(visit[next_x][next_y]-1).around.add(room_num);
                        }
                    }
                }
            }
        }
        return cnt;
    }
    public static boolean check_dir(int pos,int dir){
        if((pos&dir)==0)
            return true;
        else
            return false;
    }
}

class XY{
    public int x;
    public int y;
    public XY(int x,int y){
        this.x=x;
        this.y=y;
    }
}

class Room{

    public int room_num;
    public ArrayList<Integer> around;
    public int roomsize=0;
    public Room(int room_num){
        this.room_num=room_num;
        around=new ArrayList<>();
    }
}