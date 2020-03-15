/*
    문제
강호는 N개의 도시로 이루어진 나라에 살고 있다. 각 도시는 M개의 도로로 연결되어 있으며, 각 도로를 지날 때 필요한 시간이 존재한다. 도로는 잘 연결되어 있기 때문에, 도시 A에서 B로 이동할 수 없는 경우는 존재하지 않는다.

도시 A에서 도시 B로 바로 갈 수 있는 도로가 있거나, 다른 도시를 거쳐서 갈 수 있을 때, 도시 A에서 B를 갈 수 있다고 한다.

강호는 모든 쌍의 도시에 대해서 최소 이동 시간을 구해놓았다. 민호는 이 표를 보고 원래 도로가 몇 개 있는지를 구해보려고 한다.

예를 들어, 예제의 경우에 모든 도시 사이에 강호가 구한 값을 가지는 도로가 존재한다고 해도 된다. 하지만, 이 도로의 개수는 최솟값이 아니다. 예를 들어, 도시 1-2, 2-3, 1-4, 3-4, 4-5, 3-5를 연결하는 도로만 있다고 가정해도, 강호가 구한 모든 쌍의 최솟값을 구할 수 있다. 이 경우 도로의 개수는 6개이고, 모든 도로의 시간의 합은 55이다.

모든 쌍의 도시 사이의 최소 이동 시간이 주어졌을 때, 이 나라에 존재할 수 있는 도로의 개수의 최솟값과 그 때, 모든 도로의 시간의 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 도시의 개수 N(1 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에 각각의 도시 사이에 이동하는데 필요한 시간 (≤ 10,000)이 주어진다. A에서 B로 가는 시간과 B에서 A로 가는 시간은 같다. 또, A와 B가 같은 경우에는 필요한 시간은 0이다.

출력
첫째 줄에 도로 개수가 최소일 때, 모든 도로의 시간의 합을 출력한다. 불가능한 경우에는 -1을 출력한다.
    풀이 :
    플로이드 와샬 알고리즘을 응용한 문제다.
    i->j의 거리와 i에서 k를 거쳐 j까지의 거리 값이 같다면 i->j는 쓸모없는 간선이 되기 때문에 제거한다.
    만약 같지 않고 i->j가 더 크다면 모순이므로 -1를 출력한다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int[][] map;
    public static int city;
    public static boolean[][] map_need;
    public static boolean IMP;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st=new StringTokenizer(br.readLine());
        city=Integer.parseInt(st.nextToken());
        map=new int[city+1][city+1];
        map_need=new boolean[city+1][city+1];
        for (int i = 1; i <=city ; i++) {
            for (int j = 1; j <=city ; j++) {
                map_need[i][j]=true;
            }
        }

        for (int i = 1; i <=city ; i++) {
            st=new StringTokenizer(br.readLine());
            for (int j = 1; j <=city ; j++) {
                map[i][j]=Integer.parseInt(st.nextToken());
            }
        }
        boolean[] temp=new boolean[city+1];
        end :for (int i = 1; i <=city ; i++) {
            for (int j = i+1; j <=city ; j++) {
                temp[i]=true;
                temp[j]=true;
                Minho(i,j,temp);
                if(IMP==true)
                    break end;
                temp[i]=false;
                temp[j]=false;
            }
        }
        int count=0;
        if(IMP==false) {
            for (int i = 1; i <= city; i++) {
                for (int j = i + 1; j <= city; j++) {
                    if (map_need[i][j] == true)
                        count += map[i][j];
                }
            }
            bw.write(Integer.toString(count));
        }
        else
            bw.write("-1");
        bw.flush();
        bw.close();
    }
    public static void Minho(int i,int j,boolean[] temp){
        for (int k = 1; k <=city ; k++) {
            if(temp[k]==false){
                if(map[i][j]==map[i][k]+map[k][j]){
                    map_need[i][j]=false;
                }
                else if(map[i][j]>map[i][k]+map[k][j]){
                    IMP=true;
                    break;
                }
            }
        }
    }
}