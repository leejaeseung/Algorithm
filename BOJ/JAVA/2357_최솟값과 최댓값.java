/*
    문제
N(1 ≤ N ≤ 100,000)개의 정수들이 있을 때, a번째 정수부터 b번째 정수까지 중에서 제일 작은 정수를 찾는 것은 어려운 일이 아니다. 하지만 이와 같은 a, b의 쌍이 M(1 ≤ M ≤ 100,000)개 주어졌을 때는 어려운 문제가 된다. 이 문제를 해결해 보자.

여기서 a번째라는 것은 입력되는 순서로 a번째라는 이야기이다. 예를 들어 a=1, b=3이라면 입력된 순서대로 1번, 2번, 3번 정수 중에서 최솟값을 찾아야 한다. 각각의 정수들은 1이상 1,000,000,000이하의 값을 갖는다.

입력
첫째 줄에 N, M이 주어진다. 다음 N개의 줄에는 N개의 정수가 주어진다. 다음 M개의 줄에는 a, b의 쌍이 주어진다.

출력
M개의 줄에 입력받은 순서대로 각 a, b에 대한 답을 출력한다.
    풀이 :
    펜윅으로는 펜윅 트리를 2개 쓰는 방법이 있지만 공부해봐야겠고,
    세그먼트 트리로 구간 합 문제와 똑같이 구현함(update)는 필요없음.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());

        int H=(int)Math.ceil((Math.log(N))/Math.log(2));

        long[] num=new long[N+1];
        long[] tree_min=new long[(int)Math.pow(2,H+1)];
        long[] tree_max=new long[(int)Math.pow(2,H+1)];
        for (int i = 1; i <=N ; i++) {
            num[i]=Integer.parseInt(br.readLine());
        }
        init_min(tree_min,num,1,1,N);
        init_max(tree_max,num,1,1,N);
        for (int i = 0; i <M ; i++) {
            st=new StringTokenizer(br.readLine());
            int left=Integer.parseInt(st.nextToken());
            int right=Integer.parseInt(st.nextToken());
            bw.write(getMin(tree_min,1,1,N,left,right)+" "+getMax(tree_max,1,1,N,left,right)+"\n");
        }
        bw.flush();
        bw.close();
    }
    public static long init_min(long[] tree,long[] num,int now,int start,int end){
        if(start==end){
            return tree[now]=num[start];
        }
        return tree[now]=Math.min(init_min(tree,num,now*2,start,(start+end)/2),init_min(tree,num,now*2+1,(start+end)/2+1,end));
    }
    public static long getMin(long[] tree,int now,int start,int end,int left,int right){
        if(left>end||right<start)   return Long.MAX_VALUE;
        if(start>=left&&end<=right){
            return tree[now];
        }
        return Math.min(getMin(tree,now*2,start,(start+end)/2,left,right),getMin(tree,now*2+1,(start+end)/2+1,end,left,right));
    }
    public static long init_max(long[] tree,long[] num,int now,int start,int end){
        if(start==end){
            return tree[now]=num[start];
        }
        return tree[now]=Math.max(init_max(tree,num,now*2,start,(start+end)/2),init_max(tree,num,now*2+1,(start+end)/2+1,end));
    }
    public static long getMax(long[] tree,int now,int start,int end,int left,int right){
        if(left>end||right<start)   return Long.MIN_VALUE;
        if(start>=left&&end<=right){
            return tree[now];
        }
        return Math.max(getMax(tree,now*2,start,(start+end)/2,left,right),getMax(tree,now*2+1,(start+end)/2+1,end,left,right));
    }
}