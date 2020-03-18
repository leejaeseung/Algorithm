/*
    문제
앞에서 뒤로 보나, 뒤에서 앞으로 보나 같은 수열을 팰린드롬 이라고 한다. 예를 들어 {1}, {1, 2, 1}, {1, 2, 2, 1}과 같은 수열은 팰린드롬 이지만, {1, 2, 3}, {1, 2, 3, 2} 등은 팰린드롬이 아니다.

한 수열이 주어졌을 때, 이 수열에 최소 개수의 수를 끼워 넣어 팰린드롬을 만들려고 한다. 최소 몇 개의 수를 끼워 넣으면 되는지를 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 길이 N(1≤N≤5,000)이 주어진다. 다음 줄에는 N개의 수열을 이루는 수들이 주어진다. 각 수들은 int 범위이다.

출력
첫째 줄에 끼워 넣을 수들의 최소 개수를 출력한다.
    풀이 :
    왼쪽과 오른쪽 부터 비교해가면서 같으면 거리를 좁혀주고
    다르면 왼쪽을 ++한 것과 오른쪽을 -- 한 것 중 작은 수를 취한다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int[] arr;
    public static int[][] cache;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N=Integer.parseInt(br.readLine());

        arr=new int[N];
        cache=new int[N][N];
        for (int i = 0; i <N ; i++) {
            for (int j = 0; j <N ; j++) {
                cache[i][j]=-1;
            }
        }

        StringTokenizer st=new StringTokenizer(br.readLine());
        for (int i = 0; i <N ; i++) {
            arr[i]=Integer.parseInt(st.nextToken());
        }

        System.out.println(pd(0,N-1));
    }
    public static int pd(int left,int right){
        if(right<left)
            return 0;
        if(cache[left][right]!=-1)
            return cache[left][right];
        if(arr[left]==arr[right])
            return cache[left][right]=pd(left+1,right-1);
        else
            return cache[left][right]=Math.min(1+pd(left+1,right),1+pd(left,right-1));
    }
}