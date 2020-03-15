/*
미로에 갇힌 건우 성공
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	152	22	20	30.769%
문제
평소 탱자탱자 놀던 건우가 마지막 날에 과제를 시작했다. 건우는 피곤이 몰려왔는지, 그만 잠이 들고 말았다! 그러고는 꿈을 꿨다. 그곳은 미로였는데 너무 현실성이 없었던 탓에 건우는 꿈이란 걸 알아챘다. 얼른 꿈에서 깨려고 노력했지만 깰 수 없었다. 왜냐하면 건우가 꿈에서 깨어나려면 반드시 미로를 탈출해야만 했기 때문이다. 미로의 특징은 다음과 같다.

n×n미로이며 가장 왼쪽 위가 출발지, 가장 오른쪽 아래가 도착지이다. 출발지와 도착지에는 벽이 없음이 보장된다.
건우는 상하좌우로만 움직일 수 있으며, 벽을 넘는 것을 제외하면 한 번 이동할 때 벽이 없는 인접한 칸으로 이동한다.
초기 상태는 첫 번째 날 낮으로 시작하고, 건우가 m번 이동할 때 마다 낮에서 밤 또는 밤에서 낮으로 바뀐다.
밤에는 낮과 달리 추가로 벽을 넘을 수 있다. 벽을 넘을 때는 가려는 방향의 인접한 칸에 벽이 있어야 하며, 건우가 서 있을 수 있는 칸이 나올때까지 연속된 벽을 넘는다.
벽을 넘는 도중에 방향을 바꿀 순 없으며, 벽을 넘으면 1번 이동한 것으로 간주한다.
다음은 벽을 넘는 것에 대한 예시다. 주황색은 건우가 있는 곳 파란색은 벽이다.



위 경우는 벽을 넘을 수 있다.



위 경우처럼 벽을 넘었을 때 미로를 벗어날 경우에는 이동할 수 없다.

건우가 가장 빨리 탈출할 수 있는 날이 몇 번째 날의 낮 혹은 밤인지를 구해서 건우가 잠에서 깨도록 만들자!

입력
첫 번째 줄에 n, m이 주어진다. (1 ≤ n ≤ 500, 1 ≤ m ≤ 10)

두 번째 줄부터 n개의 각 줄에 0 또는 1이 공백을 사이에 두고 n개씩 주어진다.
이 때 0 은 벽이 없어 건우가 설 수 있는 곳, 1 은 벽이 있어 건우가 설 수 없는 곳을 의미한다.

출력
건우가 가장 빨리 탈출할 수 있는 날이 몇번째 날인지, 그리고 낮이면 "sun", 밤이면 "moon"을 공백으로 구분하여 함께 출력한다.
예를 들어, 2번째 날 밤일 경우, "2 moon" 을 출력하고, 3번째 날 낮일 경우, "3 sun" 을 출력한다. 만약 탈출할 수 없을 경우 -1을 출력한다.

풀이 :
방문 배열을 [x][y][걸음 수][낮 or 밤]으로 하여 낮,밤마다의 걸음 수를 모두 고려한다.
총 걸음 수로 출력할 날짜와 낮,밤을 계산한다.
 */

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main4 {

    public static int N,M;
    public static int[][] map;
    public static boolean[][][][] visit;
    public static int[] mv1 = {0,0,1,-1};
    public static int[] mv2 = {1,-1,0,0};
    public static int ans_step = -1;
    public static int ans_isSun = 1;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new int[N][N];
        visit = new boolean[N][N][M + 1][2];

        for (int i = 0; i < N ; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        BFS();

        if(ans_step != -1) {
            bw.write((ans_step / (M * 2) + 1 )  + " ");
            if (ans_isSun == 1)
                bw.write("sun");
            else
                bw.write("moon");
        }
        else
            bw.write(Integer.toString(-1));
        bw.flush();
        bw.close();
    }
    public static void BFS(){
        Queue<XY> q = new LinkedList<>();
        q.offer(new XY(0,0, 0, 1));
        visit[0][0][0][1] = true;

        while(!q.isEmpty()){
            XY now = q.poll();

            if(now.x == N - 1 && now.y == N - 1){
                ans_step = now.step;
                ans_isSun = now.isSun;
                return;
            }

            for (int i = 0; i < 4; i++) {
                int next_x = now.x + mv1[i];
                int next_y = now.y + mv2[i];
                int next_step = now.step + 1;
                int next_isSun = now.isSun;

                if(next_step % M == 0)
                    next_isSun = (next_isSun + 1) % 2;

                if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N) continue;
                if(now.isSun == 1 && map[next_x][next_y] == 1)   continue;
                if(now.isSun == 0 && map[next_x][next_y] == 1){
                    while((next_x >= 0 && next_y >= 0 && next_x < N && next_y < N) && map[next_x][next_y] == 1 ){
                        next_x += mv1[i];
                        next_y += mv2[i];
                    }
                    if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N)  continue;
                }
                if(!visit[next_x][next_y][next_step % M][next_isSun]){
                    visit[next_x][next_y][next_step % M][next_isSun] = true;

                    q.offer(new XY(next_x, next_y, next_step, next_isSun));
                }
            }
        }
    }
}

class XY{
    int x;
    int y;
    int step;
    int isSun;
    public XY(int x, int y, int step, int isSun){
        this.x = x;
        this.y = y;
        this.step = step;
        this.isSun = isSun;
    }
}
