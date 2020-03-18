/*
문제
캐슬 디펜스는 성을 향해 몰려오는 적을 잡는 턴 방식의 게임이다. 게임이 진행되는 곳은 크기가 N×M인 격자판으로 나타낼 수 있다. 격자판은 1×1 크기의 칸으로 나누어져 있고, 각 칸에 포함된 적의 수는 최대 하나이다. 격자판의 N번행의 바로 아래(N+1번 행)의 모든 칸에는 성이 있다.

성을 적에게서 지키기 위해 궁수 3명을 배치하려고 한다. 궁수는 성이 있는 칸에 배치할 수 있고, 하나의 칸에는 최대 1명의 궁수만 있을 수 있다. 각각의 턴마다 궁수는 적 하나를 공격할 수 있고, 모든 궁수는 동시에 공격한다. 궁수가 공격하는 적은 거리가 D이하인 적 중에서 가장 가까운 적이고, 그러한 적이 여럿일 경우에는 가장 왼쪽에 있는 적을 공격한다. 같은 적이 여러 궁수에게 공격당할 수 있다. 공격받은 적은 게임에서 제외된다. 궁수의 공격이 끝나면, 적이 이동한다. 적은 아래로 한 칸 이동하며, 성이 있는 칸으로 이동한 경우에는 게임에서 제외된다. 모든 적이 격자판에서 제외되면 게임이 끝난다.

게임 설명에서 보다시피 궁수를 배치한 이후의 게임 진행은 정해져있다. 따라서, 이 게임은 궁수의 위치가 중요하다. 격자판의 상태가 주어졌을 때, 궁수의 공격으로 제거할 수 있는 적의 최대 수를 계산해보자.

격자판의 두 위치 (r1, c1), (r2, c2)의 거리는 |r1-r2| + |c1-c2|이다.

입력
첫째 줄에 격자판 행의 수 N, 열의 수 M, 궁수의 공격 거리 제한 D가 주어진다. 둘째 줄부터 N개의 줄에는 격자판의 상태가 주어진다. 0은 빈 칸, 1은 적이 있는 칸이다.

출력
첫째 줄에 궁수의 공격으로 제거할 수 있는 적의 최대 수를 출력한다.

풀이 :
궁수들의 모든 가능한 위치를 브루트 포스로 탐색합니다.
적을 탐색할 때 BFS로 탐색하는데, 이때 왼쪽 -> 위 -> 오른쪽 순으로 탐색합니다.
중복된 적을 공격하는 것에 주의하고, 적이 내려올 때마다 벽에 박는 적을 세주고,
처음 카운트한 적의 수 == 궁수가 잡은 적 + 벽에 박은 적 을 만족하면 중단합니다.
 */

import java.io.*;
import java.util.*;

public class Main {

    public static int N,M,D;
    public static boolean[][] map;
    public static int enemy_count = 0;
    public static int max = 0;
    public static ArrayList<XY> arch;
    public static int[] mv1 = {0,-1,0};
    public static int[] mv2 = {-1,0,1};
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        map = new boolean[N][M];
        arch = new ArrayList<>();
        for (int i = 0; i < N ; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M ; j++) {
                if(Integer.parseInt(st.nextToken()) == 0){
                    map[i][j] = false;
                }
                else{
                    map[i][j] = true;
                    enemy_count++;
                }
            }
        }
            for (int j = 0; j < M ; j++) {
                arch.add(new XY(N,j));
            }
        Brute_Force();

        bw.write(Integer.toString(max));
        bw.flush();
        bw.close();
    }
    public static void Brute_Force(){
        for (int i = 0; i < arch.size() - 2; i++) {
            for (int j = i + 1; j < arch.size() - 1; j++) {
                for (int k = j + 1; k < arch.size(); k++) {
                    max = Math.max(max, attack(i, j, k));
                }
            }
        }
    }
    public static int attack(int a1, int a2, int a3){
        int enemy_death = 0;
        int enemy_kill = 0;
        boolean[][] attack_map = new boolean[N][M];
        for (int i = 0; i < N ; i++) {
            for (int j = 0; j < M ; j++) {
                attack_map[i][j] = map[i][j];
            }
        }

        while(enemy_death < enemy_count){

            Queue<XY> enemy = new LinkedList<>();

            XY temp = BFS(arch.get(a1), D, attack_map);
            if(temp != null){
                enemy.offer(temp);
            }
            temp = BFS(arch.get(a2), D, attack_map);
            if(temp != null){
                enemy.offer(temp);
            }
            temp = BFS(arch.get(a3), D, attack_map);
            if(temp != null){
                enemy.offer(temp);
            }

            while (!enemy.isEmpty()) {
                XY del = enemy.poll();
                if(attack_map[del.x][del.y]){
                    attack_map[del.x][del.y] = false;
                    enemy_kill++;
                    enemy_death++;
                }
            }
            for (int i = 0; i < M; i++) {
                if (attack_map[N - 1][i]) {
                    enemy_death++;
                    attack_map[N - 1][i] = false;
                }
            }
            attack_map = down(attack_map);
        }
        return enemy_kill;
    }
    public static boolean[][] down(boolean[][] mymap){
        boolean[][] ret = new boolean[N][M];

        for (int i = 1; i < N ; i++) {
            for (int j = 0; j < M ; j++) {
                ret[i][j] = mymap[i - 1][j];
            }
        }
        return ret;
    }
    public static XY BFS(XY start, int distance, boolean[][] mymap){
        Queue<XY> q = new LinkedList<>();
        boolean[][] visit = new boolean[N][M];
        q.offer(start);
        int mydis = 0;



        while(!q.isEmpty()){
            int size = q.size();
            for (int j = 0; j < size ; j++) {

                XY now = q.poll();

                for (int i = 0; i < 3; i++) {
                    int next_x = now.x + mv1[i];
                    int next_y = now.y + mv2[i];

                    if (next_x < 0 || next_y < 0 || next_y >= M || next_x >= N) continue;

                    if (!visit[next_x][next_y]) {
                        if (mymap[next_x][next_y] && mydis + 1 <= distance) {
                            return new XY(next_x, next_y);
                        }
                        visit[next_x][next_y] = true;
                        q.offer(new XY(next_x, next_y));
                    }
                }
            }
            mydis++;
            if(mydis > distance)
                return null;
        }
        return null;
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