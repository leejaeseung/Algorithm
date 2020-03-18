/*
    문제
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 곱을 구하려 한다. 만약에 1, 2, 3, 4, 5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 곱을 구하라고 한다면 240을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 곱을 구하라고 한다면 48이 될 것이다.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 회수이고, K는 구간의 곱을 구하는 회수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+2번째 줄까지 세 개의 정수 a,b,c가 주어지는데, a가 1인 경우 b번째 수를 c (0 ≤ c ≤ 1,000,000)로 바꾸고 a가 2인 경우에는 b부터 c까지의 곱을 구하여 출력하면 된다.

출력
첫째 줄부터 K줄에 걸쳐 구한 구간의 곱을 1,000,000,007로 나눈 나머지를 출력한다.
    풀이 :
    구간합처럼 차를 구하지 않고 리프 노드만 갱신하고 값을 return 하면서 새로 갱신해준다,
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static long MOD=1000000007;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K=Integer.parseInt(st.nextToken());

        int H=(int)Math.ceil(Math.log(N)/Math.log(2));
        long[] tree=new long[(int)Math.pow(2,H+1)];
        long[] num=new long[N+1];
        for (int i = 1; i <tree.length ; i++) {
            tree[i]=1;
        }
        for (int i = 1; i <=N ; i++) {
            num[i]=Long.parseLong(br.readLine());
        }
        init(tree,num,1,1,N);
        int f;
        int index;
        long value;
        for (int i = 0; i <M+K ; i++) {
            st=new StringTokenizer(br.readLine());
            f=Integer.parseInt(st.nextToken());
            if(f==1){
                index=Integer.parseInt(st.nextToken());
                value=Long.parseLong(st.nextToken());
                update(tree,1,value,1,N,index);
            }
            else{
                int left=Integer.parseInt(st.nextToken());
                int right=Integer.parseInt(st.nextToken());
                bw.write(getMul(tree,1,1,N,left,right)+"\n");
            }
        }
        bw.flush();
        bw.close();
    }
    public static long init(long[] tree,long[] num,int now,int start,int end){
        if(start==end){
            return tree[now]=num[start];
        }
        return tree[now]=((init(tree,num,now*2,start,(start+end)/2)%MOD)*(init(tree,num,now*2+1,(start+end)/2+1,end)%MOD))%MOD;
    }
    public static long update(long[] tree,int now,long value,int start,int end,int index){
        if(start>index||end<index) return tree[now];
        if(start==end){
            return tree[now]=value;
        }
        return tree[now]=(update(tree,now*2,value,start,(start+end)/2,index)%MOD)*(update(tree,now*2+1,value,(start+end)/2+1,end,index)%MOD)%MOD;
    }
    public static long getMul(long[] tree,int now,int start,int end,int left,int right){
        if(start>right||end<left)   return 1;
        if(left<=start&&right>=end){
            return tree[now];
        }
        return (getMul(tree,now*2,start,(start+end)/2,left,right)%MOD)*(getMul(tree,now*2+1,(start+end)/2+1,end,left,right)%MOD)%MOD;
    }
}