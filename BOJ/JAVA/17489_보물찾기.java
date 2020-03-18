/*
    문제
건구스는 세로 길이 N, 가로 길이 M인 보물지도를 하나 발견했다. 지도 뒷면에는 길이 L의 알파벳 문자열과 함께 “쓰여진 문자열을 K번 따라가면, 쓰여진 문자열의 끝 문자가 적힌 타일에 보물이 묻혀 있다” 라는 메모가 적혀 있었다.

“노력은 배신하지 않는다”라는 말을 새기고 있던 건구스는 K의 값이 최대가 되는 곳에 보물이 묻혀 있다고 믿고 있다. 주어진 문자열대로 이동하며, 건구스가 생각하는 보물이 묻힌 장소를 알아보자. 건구스는 (1, 1)에 서 있고, 이동은 인접한 상하좌우 타일로만 가능하다.

입력
첫 줄에 지도의 크기 N, M, 문자열 S의 길이 L이 공백으로 구분돼 주어진다. 가장 왼쪽 위의 좌표는 (1, 1)이고, 가장 오른쪽 아래는 (N, M)이다.

두 번째 줄에 메모에 쓰여진 문자열 S가 주어진다. S는 알파벳 대문자로 이루어져 있으며, S에 중복되는 문자는 없다.

셋째 줄부터 N줄에 걸쳐 지도가 주어진다. 지도는 알파벳 대문자로 이루어져 있으며, 건구스가 서 있는 곳에 쓰여진 글자와 S의 첫 글자는 같다.

출력
건구스가 보물의 좌표가 존재한다고 생각한다면 해당 문자열을 따라간 횟수 K와 보물의 좌표를 출력한다.

만약 건구스가 보물이 없다고 판단하거나, 영원히 보물을 찾을 수 없을 경우 -1만을 출력한다.

K가 최대인 값과 그에 해당하는 보물의 위치를 출력하는 것에 주의한다. K가 최대인 곳이 두 곳 이상인 경우는 없다.

제한
1 ≤ N, M ≤ 100
1 ≤ L ≤ 26
서브태스크 1 (60점)
N = 1
서브태스크 2 (40점)
추가 제한 조건은 없다.
    풀이 :
    처음엔 BFS로 풀려 했으나 loop 를 처리할 방법이 없는 것 같음.
    DFS로 간단히 해결 ㅂㄷㅂㄷ
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static String s;
    public static char[][] map;
    public static int N,M,S;
    public static int[] mv1={0,0,-1,1};
    public static int[] mv2={1,-1,0,0};
    public static boolean[][] visit;
    public static int K=0;
    public static int out_x=0,out_y=0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        map = new char[N + 1][M + 1];
        visit = new boolean[N + 1][M + 1];
        s = br.readLine();
        for (int i = 1; i <= N; i++) {
            String temp = br.readLine();
            for (int j = 1; j <= M; j++) {
                map[i][j] = temp.charAt(j - 1);
            }
        }
        if (dfs(1, 1, 0, 0) == -1) {
            System.out.println(-1);
        } else {
            System.out.println(K);
            System.out.print(out_x + " " + out_y);
        }
    }
    public static int dfs(int x,int y,int now_K,int now_mv){
        visit[x][y]=true;

        if(now_mv==S-1){
            now_K++;
            if(now_K>K){
                out_x=x;
                out_y=y;
                K=now_K;
            }
        }
        for (int i = 0; i <4 ; i++) {
            int new_x=x+mv1[i];
            int new_y=y+mv2[i];

            if(new_x<=0||new_x>N||new_y<=0||new_y>M)    continue;
            if(map[new_x][new_y]==s.charAt((now_mv+1)%S)) {
                if(!visit[new_x][new_y]) {
                    if(dfs(new_x,new_y,now_K,(now_mv+1)%S)==-1){
                        return -1;
                    }
                }
                else
                    return -1;
            }
        }
        visit[x][y]=false;
        return 1;
    }
}