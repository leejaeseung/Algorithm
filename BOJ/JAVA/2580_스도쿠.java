/*
문제
스도쿠는 18세기 스위스 수학자가 만든 '라틴 사각형'이랑 퍼즐에서 유래한 것으로 현재 많은 인기를 누리고 있다. 이 게임은 아래 그림과 같이 가로, 세로 각각 9개씩 총 81개의 작은 칸으로 이루어진 정사각형 판 위에서 이뤄지는데, 게임 시작 전 몇 몇 칸에는 1부터 9까지의 숫자 중 하나가 쓰여 있다.



나머지 빈 칸을 채우는 방식은 다음과 같다.

각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
위의 예의 경우, 첫째 줄에는 1을 제외한 나머지 2부터 9까지의 숫자들이 이미 나타나 있으므로 첫째 줄 빈칸에는 1이 들어가야 한다.



또한 위쪽 가운데 위치한 3x3 정사각형의 경우에는 3을 제외한 나머지 숫자들이 이미 쓰여있으므로 가운데 빈 칸에는 3이 들어가야 한다.



이와 같이 빈 칸을 차례로 채워 가면 다음과 같은 최종 결과를 얻을 수 있다.



게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.

입력
아홉 줄에 걸쳐 한 줄에 9개씩 게임 시작 전 스도쿠판 각 줄에 쓰여 있는 숫자가 한 칸씩 띄워서 차례로 주어진다. 스도쿠 판의 빈 칸의 경우에는 0이 주어진다. 스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.

출력
모든 빈 칸이 채워진 스도쿠 판의 최종 모습을 아홉줄에 걸쳐 한 줄에 9개씩 한 칸씩 띄워서 출력한다.

스도쿠 판을 채우는 방법이 여럿인 경우는 그 중 하나만을 출력한다.

풀이:
가로, 세로, 3x3 사각형 내에 숫자가 존재하는지 배열 3개로 판별한다.
row[x][1~9] - 가로에 1~9 가 존재하는지
col[y][1~9] - 세로에 1~9 가 존재하는지
squ[사각형 index][1~9] - 3x3 사각형 내에 1~9 가 존재하는지
3x3 사각형은 왼쪽위부터 순서대로 0~8의 번호를 매기고, x,y 좌표가 어떤 사각형인지 판별하려면
(x / 3) * 3 + (y / 3) 식으로 3x3 사각형의 index를 알아낸다.
9x9 = 81 개의 좌표에 대해 재귀 탐색을 하며 map[x][y]가 0일 경우에만 1~9를 대입해보고, 아니라면 재귀 호출만 한다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int[][] map = new int[9][9];
    public static boolean[][] row;
    public static boolean[][] col;
    public static boolean[][] squ;
    public static BufferedWriter bw;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        row = new boolean[9][10];
        col = new boolean[9][10];
        squ = new boolean[9][10];

        for (int i = 0; i < 9 ; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9 ; j++) {

                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] != 0) {
                    row[i][map[i][j]] = true;
                    col[j][map[i][j]] = true;
                    squ[(i / 3) * 3 + (j / 3)][map[i][j]] = true;
                }
            }
        }
        BT(0);
    }
    public static void BT(int pos) throws IOException{

        if(pos == 81){
            for (int i = 0; i < 9 ; i++) {
                for (int j = 0; j < 9 ; j++) {
                    bw.write(map[i][j] + " ");
                }
                bw.write("\n");
            }
            bw.flush();
            bw.close();
            System.exit(0);
        }
        int x = pos / 9;
        int y = pos % 9;

        if(map[x][y] == 0) {
            for (int i = 1; i <= 9; i++) {
                if (!check(x, y, i)) continue;
                map[x][y] = i;
                BT(pos + 1);
                map[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                squ[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
        else
            BT(pos + 1);
    }
    public static boolean check(int x, int y, int value){
        if(row[x][value])
            return false;
        if(col[y][value])
            return false;
        if(squ[(x / 3) * 3 + (y / 3)][value])
            return false;
        row[x][value] = true;
        col[y][value] = true;
        squ[(x / 3) * 3 + (y / 3)][value] = true;
        return true;
    }
}

class XY{
    int x;
    int y;
    public XY(int x, int y){
        this.x = x;
        this.y = y;
    }
}