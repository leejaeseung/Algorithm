/*
소용돌이 예쁘게 출력하기 성공
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	4672	1252	971	31.022%
문제
크기가 무한인 정사각형 모눈종이가 있다. 모눈종이의 각 정사각형은 행과 열의 쌍으로 표현할 수 있다.

이 모눈종이 전체를 양의 정수의 소용돌이 모양으로 채울 것이다. 일단 숫자 1을 0행 0열에 쓴다. 그리고 나서 0행 1열에 숫자 2를 쓴다. 거기서 부터 소용돌이는 반시계 방향으로 시작된다. 다음 숫자는 다음과 같이 채우면 된다.

    -3 -2 -1  0  1  2  3
    --------------------
-3 |37 36 35 34 33 32 31
-2 |38 17 16 15 14 13 30
-1 |39 18  5  4  3 12 29
 0 |40 19  6  1  2 11 28
 1 |41 20  7  8  9 10 27
 2 |42 21 22 23 24 25 26
 3 |43 44 45 46 47 48 49
이 문제는 위와 같이 채운 것을 예쁘게 출력하면 된다. r1, c1, r2, c2가 입력으로 주어진다. r1, c1은 가장 왼쪽 위 칸이고, r2, c2는 가장 오른쪽 아래 칸이다.

예쁘게 출력한다는 것은 다음과 같이 출력하는 것이다.

출력은 r1행부터 r2행까지 차례대로 출력한다.
각 원소는 공백으로 구분한다.
모든 행은 같은 길이를 가져야 한다.
공백의 길이는 최소로 해야 한다.
모든 숫자의 길이(앞에 붙는 공백을 포함)는 같아야 한다.
만약 수의 길이가 가장 길이가 긴 수보다 작다면, 왼쪽에서부터 공백을 삽입해 길이를 맞춘다.
입력
첫째 줄에 r1, c1, r2, c2가 주어진다. 모두 절댓값이 5000보다 작거나 같은 정수이고, r2-r1은 0보다 크거나 같고, 49보다 작거나 같으며, c2-c1은 0보다 크거나 같고, 4보다 작거나 같다.

출력
r2-r1+1개의 줄에 소용돌이를 예쁘게 출력한다.
    풀이 :
    처음엔 소용돌이의 최대 범위가 절대값 5000이므로 int[10000][10000]을 선언해 해보려 했으나 메모리가 500MB가까이 잡아먹어 실패.
    하지만 소용돌이의 x,y좌표만 바꿔주고 x,y좌표가 r1,r2,c1,c2의 범위에 들어올 때만 값을 넣어주면 된다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int[][] newmap;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);

        int r1 = Integer.parseInt(st.nextToken());
        int c1 = Integer.parseInt(st.nextToken());
        int r2 = Integer.parseInt(st.nextToken());
        int c2 = Integer.parseInt(st.nextToken());

        newmap=new int[r2-r1+1][c2-c1+1];

        tonado(5000+r1,5000+c1,5000+r2,5000+c2);

        int max=0;

        for (int i = 0; i <r2-r1+1 ; i++) {
            for (int j = 0; j <c2-c1+1 ; j++) {
                if(max<newmap[i][j])
                    max=newmap[i][j];
            }
        }

        for (int i = 0; i <r2-r1+1 ; i++) {
            for (int j = 0; j <c2-c1+1 ; j++) {
                for (int l = 0; l <Integer.toString(max).length()-Integer.toString(newmap[i][j]).length() ; l++) {
                    bw.write(" ");
                }
                bw.write(newmap[i][j]+" ");
            }
            bw.write("\n");
        }

        bw.flush();
        bw.close();
    }
    public static void tonado(int r1,int c1,int r2,int c2){
        int x=5000;
        int y=5000;
        int size=1;
        int value=1;

        while(newmap[0][0]==0||newmap[r2-r1][c2-c1]==0){
            if(value==size*size) {
                if((r1<=y&&r2>=y)&&(c1<=x&&c2>=x)){
                    newmap[Math.abs(r1-y)][Math.abs(c1-x)]=value;
                }
                value++;
                x++;
                size += 2;
            }
            for (int i = 0; i <size-1 ; i++) {
                if((r1<=y&&r2>=y)&&(c1<=x&&c2>=x)){
                    newmap[Math.abs(r1-y)][Math.abs(c1-x)]=value;
                }
                value++;
                y--;
            }
            y++;
            x--;
            for (int i = 0; i <size-1 ; i++) {
                if((r1<=y&&r2>=y)&&(c1<=x&&c2>=x)){
                    newmap[Math.abs(r1-y)][Math.abs(c1-x)]=value;
                }
                value++;
                x--;
            }
            x++;
            y++;
            for (int i = 0; i <size-1 ; i++) {
                if((r1<=y&&r2>=y)&&(c1<=x&&c2>=x)){
                    newmap[Math.abs(r1-y)][Math.abs(c1-x)]=value;
                }
                value++;
                y++;
            }
            y--;
            x++;
            for (int i = 0; i <size-2 ; i++) {
                if((r1<=y&&r2>=y)&&(c1<=x&&c2>=x)){
                    newmap[Math.abs(r1-y)][Math.abs(c1-x)]=value;
                }
                value++;
                x++;
            }
        }
    }
}