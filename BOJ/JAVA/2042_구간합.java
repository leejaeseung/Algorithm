/*
    문제
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 회수이고, K는 구간의 합을 구하는 회수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어지는데, a가 1인 경우 b번째 수를 c로 바꾸고 a가 2인 경우에는 b번째 수부터 c번째 수까지의 합을 구하여 출력하면 된다.

a가 1인 경우 c는 long long 범위를 넘지 않는다.

출력
첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다. 단, 정답은 long long 범위를 넘지 않는다.
    풀이 :
    세그먼트 트리 연습
    펜윅 트리 연습 - 더 좋은듯
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        long[] num = new long[N+1];
        long[] tree=new long[N+1];

        for (int i = 1; i <=N ; i++) {
            num[i]=Long.parseLong(br.readLine());

            pw_update(tree,i,num[i]);
        }
        long diff=0;
        int index=0;
        for (int i = 0; i <M+K ; i++) {
            st=new StringTokenizer(br.readLine());
            if(Integer.parseInt(st.nextToken())==1){
                index=Integer.parseInt(st.nextToken());
                diff=Integer.parseInt(st.nextToken())-num[index];
                num[index]+=diff;
                pw_update(tree,index,diff);
            }
            else{
                int left=Integer.parseInt(st.nextToken());
                int right=Integer.parseInt(st.nextToken());
                bw.write(sum(tree,right)-sum(tree,left-1)+"\n");
            }
        }
        bw.flush();
        bw.close();
    }
    /*public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());
        int K=Integer.parseInt(st.nextToken());

        long[] num=new long[N];
        int H= (int)Math.ceil((Math.log(N)/Math.log(2)));
        long[] tree=new long[(int)(Math.pow(2,H+1))];

        tree_size=N+1;


        for (int i = 0; i <N ; i++) {
            num[i]=Long.parseLong(br.readLine());
        }
        init(num,tree,1,0,N-1);
        long diff=0;
        int index=0;
        for (int i = 0; i <M+K ; i++) {
            st=new StringTokenizer(br.readLine());
            if(Integer.parseInt(st.nextToken())==1){
                index=Integer.parseInt(st.nextToken());
                diff=Integer.parseInt(st.nextToken())-num[index-1];
                num[index-1]+=diff;
                change(tree,1,diff,0,N-1,index-1);
            }
            else{
                bw.write(getsum(tree,1,0,N-1,Integer.parseInt(st.nextToken())-1,Integer.parseInt(st.nextToken())-1)+"\n");
            }
        }
        bw.flush();
        bw.close();
    }
    public static long init(long[] num,long[] tree,int now,int start,int end){
        if(start==end){
            return tree[now]=num[start];
        }
        else{
            return tree[now]=init(num,tree,now*2,start,(start+end)/2)+init(num,tree,now*2+1,(start+end)/2+1,end);
        }
    }
    public static long getsum(long[] tree,int now,int start,int end,int left,int right){
        if(end<left||start>right){
            return 0;
        }
        if(left<=start&&right>=end){
            return tree[now];
        }
            return getsum(tree,now*2,start,(start+end)/2,left,right)+getsum(tree,now*2+1,(start+end)/2+1,end,left,right);
    }
    public static void change(long[] tree,int now,long diff,int start,int end,int index){
        if(index>end||index<start)  return;
        tree[now]+=diff;
        if(start!=end){
            change(tree,now*2,diff,start,(start+end)/2,index);
            change(tree,now*2+1,diff,(start+end)/2+1,end,index);
        }
    }*/
    public static void pw_update(long[] tree,int i,long diff){
        while(i<tree.length){
            tree[i]+=diff;
            i+=(i&-i);
        }
    }
    public static long sum(long[] tree,int i){
        long sum=0;
        while(i>0){
            sum+=tree[i];
            i-=(i&-i);
        }
        return sum;
    }
}