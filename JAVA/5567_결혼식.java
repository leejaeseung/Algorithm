/*
    결혼식 성공
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	4163	1706	1451	42.242%
문제
상근이는 자신의 결혼식에 학교 동기 중 자신의 친구와 친구의 친구를 초대하기로 했다. 상근이의 동기는 모두 N명이고, 이 학생들의 학번은 모두 1부터 N까지이다. 상근이의 학번은 1이다.

상근이는 동기들의 친구 관계를 모두 조사한 리스트를 가지고 있다. 이 리스트를 바탕으로 결혼식에 초대할 사람의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이의 동기의 수 n (2 ≤ n ≤ 500)이 주어진다. 둘째 줄에는 리스트의 길이 m (1 ≤ m ≤ 10000)이 주어진다. 다음 줄부터 m개 줄에는 친구 관계 ai bi가 주어진다. (1 ≤ ai < bi ≤ n) ai와 bi가 친구라는 뜻이며, bi와 ai도 친구관계이다.

출력
첫째 줄에 상근이의 결혼식에 초대하는 동기의 수를 출력한다.

    풀이 :
    친구의 친구까지만 초대하므로 친구=1, 친구의 친구=2의 거리로 생각해 그래프의 최단 거리를 구한다.
    상근이의 학번은 항상 1이므로 1번 노드에 대해 다익스트라 알고리즘을 적용해 최단 거리를 구하고 거리가 2이하인 것들만 카운트한다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int[][] list;
    public static boolean[] visit;
    public static int N;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N=Integer.parseInt(br.readLine());
        int L=Integer.parseInt(br.readLine());

        list=new int[N+1][N+1];
        for (int i = 1; i <=N ; i++) {
            for (int j = 1; j <=N ; j++) {
                if(i==j)
                    list[i][j]=99999999;
            }
        }
        visit=new boolean[N+1];

        for (int i = 0; i <L ; i++) {
            StringTokenizer st=new StringTokenizer(br.readLine());
            int start=Integer.parseInt(st.nextToken());
            int end=Integer.parseInt(st.nextToken());
            list[start][end]=1;
            list[end][start]=1;
            if(start==1)
                list[end][end]=1;
        }
        visit[1]=true;
        for (int i = 1; i <=N ; i++) {
            if(visit[i]==false&&list[1][i]!=0)
            find(1,i);
        }
        int count=0;
        for (int i = 2; i <=N ; i++) {
            if(list[i][i]<=2)
                count++;
        }
        bw.write(Integer.toString(count));
        bw.flush();
        bw.close();
    }
    public static void find(int start,int now){
        visit[now]=true;
        for (int i = 1; i <=N ; i++) {
            if(visit[i]==false&&list[now][i]!=0){
                list[start][i]=Math.min(list[i][i],list[start][now]+list[now][i]);
                list[i][i]=list[start][i];
            }
        }
        visit[now]=false;
    }
}