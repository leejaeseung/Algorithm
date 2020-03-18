/*
문제
틱택토(Tic-tac-toe) 게임은 두 플레이어가 번갈아가며 O와 X를 3x3판에 써서 같은 글자를 가로, 세로, 혹은 대각선 상에 놓이도록 하는 게임이다.

먼저 3개의 연속 된 O 또는 X를 완성시킨 플레이어가 승리하게 된다. 이 게임은 무승부가 가능하다.



Figure: 게임의 진행과정 예시

틱택토 초보 승현이와 기영이는 틱택토 게임을 플레이하고 있었다. 그런데 뒤에서 지켜보고 있던 틱택토 초고수 윤영이와 진욱이가 너무나 답답한 나머지 본인들이 대신 플레이를 해주겠다고 나섰다.

지금까지 진행 된 틱택토 게임 보드가 주어졌을 때, 이번에 착수하는 플레이어가 얻을 수 있는 최선의 게임 결과는 무엇일까? 단, 두 플레이어는 항상 모든 경우를 고려하여 최선의 수를 둔다고 가정한다.

입력
현재까지 진행된 틱택토 게임 보드가 띄어쓰기로 구분되어 3줄에 걸쳐 주어진다. 0은 빈칸, 1은 X, 2는 O를 의미한다. 단, 항상 X가 선공이다. 그리고 이미 게임이 종료된 상태는 입력으로 주어지지 않는다.

출력
첫째 줄에 주어진 게임 보드에서 이번에 착수하는 플레이어가 얻을 수 있는 최선의 게임 결과를 출력한다.

이기는 경우 "W", 무승부인 경우 "D", 지는 경우 "L"을 출력한다.

풀이 : 매우 어려움. 모든 경우의 수가 3^9 = 19683 개, 각 맵에 대한 캐시를 만들어 해당 맵에 대해 최선의 결과가 나왔다면 그대로 반영
하고, 다음 턴의 상대가 이겼다면 -> 난 짐 -> 반대의 결과를 리턴, 비겼다면 0을 리턴.
 */

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int[][] map = new int[3][3];
    public static int[] cache = new int[19683];
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int count = 0;
        for (int i = 0; i < 19683 ; i++) {
            cache[i] = -2;
        }
        for (int i = 0; i < 3 ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 3 ; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] != 0)
                    count++;
            }
        }
        int res = 0;
        if(count % 2 == 0) {
            res = BruteForce(map,  1);
        }
        else {
            res = BruteForce(map,   2);
        }

        if(res == 0)
            bw.write("D");
        else if(res == 1)
            bw.write("W");
        else
            bw.write("L");
        bw.flush();
        bw.close();
    }
    public static int toInt(int[][] map){

        int result = 0;
        for (int i = 0; i < 3 ; i++) {
            for (int j = 0; j < 3 ; j++) {

                result *= 3;
                if(map[i][j] == 1){
                    result++;
                }
                else if(map[i][j] == 2){
                    result += 2;
                }
            }
        }
        return result;
    }
    public static int BruteForce(int[][] nowmap,  int turn){

        if(whoWin(nowmap, (turn % 2) + 1))
            return -1;

        int cacheNum = toInt(nowmap);
        int result = cache[cacheNum];

        if( result != -2)
            return result;

        int minValue = 2;

        for (int i = 0; i < 3 ; i++) {
            for (int j = 0; j < 3 ; j++) {
                if(map[i][j] == 0){
                    map[i][j] = turn;
                    minValue = Math.min(minValue, BruteForce(nowmap,   (turn % 2) + 1));
                    map[i][j] = 0;
                }
            }
        }
        if(minValue == 2)
            return cache[cacheNum] = 0;

        return cache[cacheNum] = minValue * -1;
    }

    public static boolean whoWin(int[][] nowmap, int turn){

        for (int i = 0; i < 3 ; i++) {
            for (int j = 0; j < 3 ; j++) {
                if(nowmap[i][j] != turn)
                    break;
                if(j == 2)
                    return true;
            }
        }
        for (int i = 0; i < 3 ; i++) {
            for (int j = 0; j < 3 ; j++) {
                if(nowmap[j][i] != turn)
                    break;
                if(j == 2)
                    return true;
            }
        }
        for (int i = 0; i < 3 ; i++) {
                if(nowmap[i][i] != turn)
                    break;
                if(i == 2)
                    return true;
        }
        for (int i = 0; i < 3 ; i++) {
                if(nowmap[i][2 - i] != turn)
                    break;
                if(i == 2)
                    return true;
        }
        return false;
    }
}

class XY{

    public int x;
    public int y;
    public XY(int x, int y){
        this.x = x;
        this.y = y;
    }
}