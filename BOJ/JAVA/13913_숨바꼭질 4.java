/*
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.
    풀이 : BFS로 각 지점에서의 이동횟수를 구하고, 도착 지점에서부터 역으로 BFS를 해서 현재 지점의 이동횟수-1 인 지점을 탐색한다.
 */
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static int[] cnt=new int[100001];
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        Stack<Integer> res = new Stack<>();

        int start=Integer.parseInt(st.nextToken());
        int end=Integer.parseInt(st.nextToken());

        BFS(start,end);
        res=BFS_rev(end,start);

        bw.write(cnt[end]+"\n");
        while(!res.isEmpty()){
            bw.write(res.pop()+" ");
        }
        bw.flush();
        bw.close();
    }
    public static void BFS(int start,int end){
        Queue<Integer> q=new LinkedList<>();
        boolean[] visit=new boolean[100001];
        q.offer(start);
        visit[start]=true;

        while(!q.isEmpty()){
            int temp=q.poll();

            if(temp == end)
                break;

            if( temp-1 >= 0 ){
                if(!visit[temp-1]) {
                    q.offer(temp - 1);
                    visit[temp - 1] = true;
                    cnt[temp - 1]=cnt[temp]+1;
                }
            }
            if( temp+1 <= 100000 ){
                if(!visit[temp+1]) {
                    q.offer(temp + 1);
                    visit[temp + 1] = true;
                    cnt[temp + 1]=cnt[temp]+1;
                }
            }
            if( temp*2 <= 100000 ){
                if(!visit[temp*2]) {
                    q.offer(temp * 2);
                    visit[temp * 2] = true;
                    cnt[temp * 2]=cnt[temp]+1;
                }
            }
        }
    }
    public static Stack<Integer> BFS_rev(int start, int end){
        Queue<Integer> q=new LinkedList<>();
        Stack<Integer> res=new Stack<>();
        q.offer(start);
        res.push(start);

        while(!q.isEmpty()){
            int temp=q.poll();

            if(temp == end)
                break;

            if( temp-1 >= 0 ){
                if(cnt[temp-1] == cnt[temp]-1) {
                    q.offer(temp - 1);
                    res.push(temp-1 );
                    continue;
                }
            }
            if( temp+1 <= 100000 ){
                if(cnt[temp+1] == cnt[temp]-1) {
                    q.offer(temp + 1);
                    res.push(temp+1);
                    continue;
                }
            }
            if(temp % 2 == 0) {
                if (temp / 2 > 0) {
                    if (cnt[temp / 2] == cnt[temp] - 1) {
                        q.offer(temp / 2);
                        res.push(temp / 2);
                        continue;
                    }
                }
            }
        }
        return res;
    }
}