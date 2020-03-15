/*
    문제
지금 민식이가 계획한 여행은 달이 맨 처음 뜨기 시작할 때 부터, 준비했던 여행길이다. 하지만, 매번 달이 차오를 때마다 민식이는 어쩔 수 없는 현실의 벽 앞에서 다짐을 포기하고 말았다.

민식이는 매번 자신의 다짐을 말하려고 노력했지만, 말을 하면 아무도 못 알아들을 것만 같아서, 지레 겁먹고 벙어리가 되어버렸다. 결국 민식이는 모두 잠든 새벽 네시 반 홀로 일어나, 창 밖에 떠있는 달을 보았다.

하루밖에 남지 않았다. 달은 내일이면 다 차오른다. 이번이 마지막기회다. 이걸 놓치면 영영 못간다.

영식이는 민식이가 오늘도 여태것처럼 그냥 잠 들어버려서 못 갈지도 모른다고 생각했다. 하지만 그러기엔 민식이의 눈에는 저기 뜬 달이 너무나 떨렸다.

민식이는 지금 미로 속에 있다. 미로는 직사각형 모양이고, 여행길을 떠나기 위해 미로를 탈출하려고 한다. 미로는 다음과 같이 구성되어져있다.

빈 곳 : 언제나 이동할 수 있다. ('.‘로 표시됨)
벽 : 절대 이동할 수 없다. (‘#’)
열쇠 : 언제나 이동할 수 있다. 이 곳에 처음 들어가면 열쇠를 집는다. (a - f)
문 : 대응하는 열쇠가 있을 때만 이동할 수 있다. (A - F)
민식이의 현재 위치 : 빈 곳이고, 민식이가 현재 서 있는 곳이다. (숫자 0)
출구 : 달이 차오르기 때문에, 민식이가 가야하는 곳이다. 이 곳에 오면 미로를 탈출한다. (숫자 1)
달이 차오르는 기회를 놓치지 않기 위해서, 미로를 탈출하려고 한다. 한 번의 움직임은 현재 위치에서 수평이나 수직으로 한 칸 이동하는 것이다.

민식이가 미로를 탈출하는데 걸리는 이동 횟수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 미로의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 50) 둘째 줄부터 N개의 줄에 미로의 모양이 주어진다. 같은 타입의 열쇠가 여러 개 있을 수 있고, 문도 마찬가지이다. 그리고, 영식이가 열쇠를 숨겨놓는 다면 문에 대응하는 열쇠가 없을 수도 있다. 0은 한 개, 1은 적어도 한 개 있다. 그리고, 열쇠는 여러 번 사용할 수 있다.

출력
첫째 줄에 민식이가 미로를 탈출하는데 드는 이동 횟수의 최솟값을 출력한다. 만약 민식이가 미로를 탈출 할 수 없으면, -1을 출력한다.
    풀이 :
    넘모 어려움 ㄷㄷ;
    3차원 배열을 이용해 해당 위치에서 key를 몇개씩 가지고 있을 때의 visit 여부를 판단함 -> 해당 키를 가지고 지나간 경우 다시 지나갈 필요가 없음
    그래서 이미 지나온 곳은 counting만 하고 건너뛸 수 있음
 */
import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {

    public static char[][] map;
    public static boolean[][][] visit;
    public static int[] di={-1,0,1,0};
    public static int[] dj={0,1,0,-1};
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s;
        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());

        Queue<Node> q=new LinkedList<>();
        map=new char[N+2][M+2];
        visit=new boolean[N+2][M+2][64];

        for (int i = 0; i <N+2 ; i++) {
            for (int j = 0; j <M+2 ; j++) {
                map[i][j]='#';
            }
        }
        for (int i = 1; i <=N ; i++) {
            s=br.readLine();
            for (int j = 1; j <=M ; j++) {
                map[i][j]=s.charAt(j-1);
                if(s.charAt(j-1)=='0'){
                   visit[i][j][0]=true;
                   q.offer(new Node(i,j,0));
                }
            }
        }
        int cnt=0;
        boolean find=false;
        while(!q.isEmpty()){
            int size=q.size();

            while(size!=0) {
                size--;
                Node temp = q.poll();
                if (map[temp.pt.x][temp.pt.y] == '1') {
                    find = true;
                    break;
                }

                for (int i = 0; i < 4; i++) {
                    int mi = temp.pt.x + di[i];
                    int mj = temp.pt.y + dj[i];
                    int curkey = temp.key;

                    if (map[mi][mj] != '#') {
                        if (map[mi][mj] >= 'a' && map[mi][mj] <= 'f') {
                            curkey |= (1 << (map[mi][mj] - 'a'));
                        }
                        if (map[mi][mj] >= 'A' && map[mi][mj] <= 'F') {
                            int flag=curkey & (1 << (map[mi][mj] - 'A'));
                            if (flag==0)
                                continue;
                        }
                        if (visit[mi][mj][curkey])
                            continue;
                        q.offer(new Node(mi, mj, curkey));
                        visit[mi][mj][curkey] = true;
                    } else
                        continue;
                }
            }
            if(find)
                break;
            else
                cnt++;
        }
        if(!find)
            System.out.println("-1");
        else
            System.out.println(cnt);
    }
}

class Node{

    public Point pt;
    public int key;
    public Node(int i,int j,int key){
        pt=new Point(i,j);
        this.key=key;
    }
}