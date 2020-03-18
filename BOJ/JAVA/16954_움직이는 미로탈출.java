/*
문제
욱제는 학교 숙제로 크기가 8×8인 체스판에서 탈출하는 게임을 만들었다. 체스판의 모든 칸은 빈 칸 또는 벽 중 하나이다. 욱제의 캐릭터는 가장 왼쪽 아랫 칸에 있고, 이 캐릭터는 가장 오른쪽 윗 칸으로 이동해야 한다.

이 게임의 특징은 벽이 움직인다는 점이다. 1초마다 모든 벽이 아래에 있는 행으로 한 칸씩 내려가고, 가장 아래에 있어서 아래에 행이 없다면 벽이 사라지게 된다. 욱제의 캐릭터는 1초에 인접한 한 칸 또는 대각선 방향으로 인접한 한 칸으로 이동하거나, 현재 위치에 서 있을 수 있다. 이동할 때는 빈 칸으로만 이동할 수 있다.

1초 동안 욱제의 캐릭터가 먼저 이동하고, 그 다음 벽이 이동한다. 벽이 캐릭터가 있는 칸으로 이동하면 더 이상 캐릭터는 이동할 수 없다.

욱제의 캐릭터가 가장 오른쪽 윗 칸으로 이동할 수 있는지 없는지 구해보자.

입력
8개 줄에 걸쳐서 체스판의 상태가 주어진다. '.'은 빈 칸, '#'는 벽이다. 가장 왼쪽 아랫칸은 항상 벽이 아니다.

출력
욱제의 캐릭터가 가장 오른쪽 윗 칸에 도착할 수 있으면 1, 없으면 0을 출력한다.
    풀이 :
    똥 피하기 게임으로 생각하면 된다.
    총 8초를 버티면 더 이상 내려오는 똥이 없으므로 8초간의 맵을 3차원 배열로 만들어 큐에 넣어가며 큐가 비면 똥을 못 피한 것이고,
    버티면 도달 할 수 있다.
 */
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static boolean[][][] map=new boolean[9][10][10];
    public static Queue<XY> q;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        q=new LinkedList<>();
        for (int i = 0; i <8 ; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    map[i][j][k]=true;
                }
            }
        }
        for (int i = 1; i <= 8; i++) {
            String s = br.readLine();
            for (int j = 1; j <= 8; j++) {
                if (s.charAt(j-1) == '.')
                    map[0][i][j]=false;
            }
        }
        for (int i = 1; i <9 ; i++) {
            for (int j = 1; j <=i ; j++) {
                for (int k = 1; k <=8 ; k++) {
                    map[i][j][k]=false;
                }
            }
            for (int j = i+1; j <=8 ; j++) {
                for (int k = 1; k <=8 ; k++) {
                    map[i][j][k]=map[i-1][j-1][k];
                }
            }
        }
        q.offer(new XY(8,1));
        int map_sec=0;
        boolean flag=false;
        find :while(!q.isEmpty()){
            int size=q.size();
            if(map_sec==8){
                flag=true;
                break;
            }
            for (int i = 0; i <size ; i++) {
                can_go(map_sec,q.poll());
            }
            map_sec++;
        }
        if(flag){
            System.out.println(1);
        }
        else
            System.out.println(0);

    }
    public static void can_go(int map_sec,XY pos){
        if(map[map_sec][pos.X][pos.Y]==true)
            return;
        for (int i = 0; i <3 ; i++) {
            if(map[map_sec][pos.X-1][pos.Y+i-1]==false)
                q.offer(new XY(pos.X-1,pos.Y+i-1));
        }
        if(map[map_sec][pos.X][pos.Y-1]==false){
            q.offer(new XY(pos.X,pos.Y-1));
        }
        if(map[map_sec][pos.X][pos.Y]==false){
            q.offer(new XY(pos.X,pos.Y));
        }
        if(map[map_sec][pos.X][pos.Y+1]==false){
            q.offer(new XY(pos.X,pos.Y+1));
        }
        for (int i = 0; i <3 ; i++) {
            if(map[map_sec][pos.X+1][pos.Y+i-1]==false)
                q.offer(new XY(pos.X+1,pos.Y+i-1));
        }
    }
}

class XY{

    public int X;
    public int Y;
    public XY(int X,int Y){
        this.X=X;
        this.Y=Y;
    }
}