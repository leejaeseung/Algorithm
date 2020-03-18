/*
문제
상근이는 1층 빌딩에 침입해 매우 중요한 문서를 훔쳐오려고 한다. 상근이가 가지고 있는 평면도에는 문서의 위치가 모두 나타나 있다. 빌딩의 문은 모두 잠겨있기 때문에, 문을 열려면 열쇠가 필요하다. 상근이는 일부 열쇠를 이미 가지고 있고, 일부 열쇠는 빌딩의 바닥에 놓여져 있다.

상근이가 훔칠 수 있는 문서의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 수는 100개를 넘지 않는다.

각 테스트 케이스의 첫째 줄에는 지도의 높이와 너비 h와 w (2 ≤ h, w ≤ 100)가 주어진다. 다음 h개 줄에는 빌딩을 나타내는 w개의 문자가 주어지며, 각 문자는 다음 중 하나이다.

'.'는 빈 공간을 나타낸다.
'*'는 벽을 나타내며, 상근이는 벽을 통과할 수 없다.
'$'는 상근이가 훔쳐야하는 문서이다.
알파벳 대문자는 문을 나타낸다.
알파벳 소문자는 열쇠를 나타내며, 그 문자의 대문자인 모든 문을 열 수 있다.
마지막 줄에는 상근이가 이미 가지고 있는 열쇠가 공백없이 주어진다. 만약, 열쇠를 하나도 가지고 있지 않는 경우에는 "0"이 주어진다.

상근이는 빌딩 밖으로 나갈 수 있다. 각각의 문에 대해서, 그 문을 열 수 있는 열쇠의 개수는 0개, 1개, 또는 그 이상이고, 각각의 열쇠에 대해서, 그 열쇠로 열 수 있는 문의 개수도 0개, 1개, 또는 그 이상이다. 열쇠는 여러 번 사용할 수 있다.

출력
각 테스트 케이스 마다, 상근이가 훔칠 수 있는 문서의 최대 개수를 출력한다.

풀이:
조건이 까다로운 BFS 문제였습니다.
문을 만나면 문 doors 배열에 저장한 뒤, 열쇠를 만났을 때 doors 배열을 탐색하여 해당하는 문의 좌표를 큐에 넣습니다.
이미 구한 열쇠라면 문을 그냥 통과합니다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int T, N, M;
    public static char[][] map;
    public static boolean[][] visit;
    public static int[] mv1 = {0,0,1,-1};
    public static int[] mv2 = {1,-1,0,0};
    public static boolean[] havekey;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            map = new char[N + 2][M + 2];
            visit = new boolean[N + 2][M + 2];
            havekey = new boolean[26];

            for (int j = 0; j <= N + 1 ; j++) {
                if(j == 0 || j == N + 1){
                    for (int k = 0; k <= M + 1 ; k++) {
                        map[j][k] = '.';
                    }
                }
                else {
                    String s = br.readLine();
                    for (int k = 0; k <= M + 1; k++) {
                        if (k == 0 || k == M + 1)
                            map[j][k] = '.';
                        else {
                            map[j][k] = s.charAt(k - 1);
                        }
                    }
                }
            }
            String key = br.readLine();
            if(key.charAt(0) != '0'){
                for (int j = 0; j < key.length() ; j++) {
                    char now = key.charAt(j);
                    havekey[now - 'a'] = true;
                }
            }
            bw.write(BFS() + "\n");
        }
        bw.flush();
        bw.close();
    }
    public static int BFS(){
        Queue<XY> q = new LinkedList<>();
        ArrayList<XY> doors = new ArrayList<>();
        q.offer(new XY(0, 0, -1));

        int cnt = 0;

        while(!q.isEmpty()){
            XY now = q.poll();

            for (int i = 0; i < 4 ; i++) {
                int next_x = now.x + mv1[i];
                int next_y = now.y + mv2[i];

                if(next_x < 0 || next_y < 0 || next_x >= N + 2 || next_y >= M + 2)  continue;
                char nextxy = map[next_x][next_y];
                if(nextxy == '*')  continue;
                if(visit[next_x][next_y])   continue;
                visit[next_x][next_y] = true;

                if(nextxy >= 'A' && nextxy <= 'Z'){
                    if(havekey[nextxy - 'A'])
                        q.offer(new XY(next_x, next_y, -1));
                    else
                        doors.add(new XY(next_x, next_y, nextxy - 'A'));
                }
                else if(nextxy >= 'a' && nextxy <= 'z'){
                    havekey[nextxy - 'a'] = true;
                    for (int j = 0; j < doors.size() ; j++) {
                        XY now_door = doors.get(j);

                        if(now_door.door == nextxy - 'a'){
                            q.offer(new XY(now_door.x, now_door.y, -1));
                            now_door.door = -1;
                        }
                    }
                    q.offer(new XY(next_x, next_y, -1));
                    map[next_x][next_y] = '.';
                }
                else if(nextxy == '$'){
                    map[next_x][next_y] = '.';
                    q.offer(new XY(next_x, next_y, -1));
                    cnt++;
                }
                else{
                    q.offer(new XY(next_x, next_y, -1));
                }
            }
        }
        return cnt;
    }
}

class XY{
    int x;
    int y;
    int door;
    public XY(int x, int y, int door){
        this.x = x;
        this.y = y;
        this.door = door;
    }
}