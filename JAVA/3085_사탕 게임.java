/*
    문제
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

출력
첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.
    풀이 :
    기본적인 브루트 포스 문제다.
    꼭 인접한 사탕을 바꿔야 최대가 되는게 아니다. -> 오히려 연속 줄을 가만히 두고 쓸모없는 사탕을 바꿔주면 더 많이 먹는다.(바꾼 뒤 전체 사탕 중에 고르기 때문)
 */
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {

    public static int N;
    public static char[][] map;
    public static boolean[][] visit;
    public static int max=0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N=Integer.parseInt(br.readLine());
        map=new char[N][N];
        visit=new boolean[N][N];

        for (int i = 0; i <N ; i++) {
            String s=br.readLine();
            for (int j = 0; j <N ; j++) {
                map[i][j]=s.charAt(j);
            }
        }
        for (int i = 0; i <N ; i++) {
            for (int j = 0; j <N ; j++) {
                if(j<N-1) {
                    if (map[i][j] != map[i][j + 1]) {
                        swap(i,j,i,j+1);
                        for (int k = 0; k <N ; k++) {
                            for (int l = 0; l <N ; l++) {
                                max = Math.max(max,Math.max(search_ver(k, l, map[k][l]),search_hor(k, l, map[k][l])));
                            }
                        }
                        swap(i,j,i,j+1);
                    }
                }
                if(i<N-1){
                    if(map[i][j]!=map[i+1][j]){
                        swap(i,j,i+1,j);
                        for (int k = 0; k <N ; k++) {
                            for (int l = 0; l <N ; l++) {
                                max = Math.max(max,Math.max(search_ver(k, l, map[k][l]),search_hor(k, l, map[k][l])));
                            }
                        }
                        swap(i,j,i+1,j);
                    }
                }
            }
        }
        bw.write(Integer.toString(max));
        bw.flush();
        bw.close();
    }
    public static int search_ver(int i,int j,char candy){
        int sum=0;
        visit[i][j]=true;

        if(i!=0&&map[i-1][j]==candy&&visit[i-1][j]==false)
            sum+=search_ver(i-1,j,candy);
        if(i!=N-1&&map[i+1][j]==candy&&visit[i+1][j]==false)
            sum+=search_ver(i+1,j,candy);

        visit[i][j]=false;
        sum++;

        return sum;
    }
    public static int search_hor(int i,int j,char candy){
        int sum=0;
        visit[i][j]=true;

        if(j!=0&&map[i][j-1]==candy&&visit[i][j-1]==false)
            sum+=search_hor(i,j-1,candy);
        if(j!=N-1&&map[i][j+1]==candy&&visit[i][j+1]==false)
            sum+=search_hor(i,j+1,candy);

        visit[i][j]=false;
        sum++;

        return sum;
    }
    public static void swap(int i1,int j1,int i2,int j2){
        char temp=map[i1][j1];
        map[i1][j1]=map[i2][j2];
        map[i2][j2]=temp;
    }
}