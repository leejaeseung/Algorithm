/*
    문제
0으로 시작하지 않는 정수 N이 주어진다. 이때, M을 정수 N의 자릿수라고 했을 때, 다음과 같은 연산을 K번 수행한다.

1 ≤ i < j ≤ M인 i와 j를 고른다. 그 다음, i번 위치의 숫자와 j번 위치의 숫자를 바꾼다. 이때, 바꾼 수가 0으로 시작하면 안 된다.

위의 연산을 K번 했을 때, 나올 수 있는 수의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N과 K가 주어진다. N은 1,000,000보다 작거나 같은 자연수이고, K는 10보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제에 주어진 정답을 K번 했을 때, 만들 수 있는 가장 큰 숫자를 출력한다. 만약 연산을 K번 할 수 없으면 -1을 출력한다.
    풀이 :
    재귀 함수로 모든 수들을 바꿔주는 경우를 체크해준다.
    예외 상황 : 바꿔준 횟수 때의 그 수는 다시 호출하지 않는다, 맨 처음 수와 0을 바꿔주는 경우는 건너뛴다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int max=-1;
    public static int K;
    public static boolean[][] visit=new boolean[11][1000001];
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st=new StringTokenizer(br.readLine());

        int N=Integer.parseInt(st.nextToken());
        K=Integer.parseInt(st.nextToken());

                if (Integer.toString(N).length() == 2) {
                    if (Integer.toString(N).charAt(1) != '0') {
                        BFS(N, 0);
                    }
                } else if (Integer.toString(N).length() != 1) {
                    BFS(N, 0);
                }
                System.out.print(max);
    }
    public static void BFS(int num,int cnt){
        if(cnt>=K){
            max=Math.max(max,num);
            return;
        }
        for (int k = 1; k <Integer.toString(num).length() ; k++) {
            for (int l = k+1; l <=Integer.toString(num).length() ; l++) {
                if(k==1&&Integer.toString(num).charAt(l-1)=='0')  continue;
                    int change = change_num(k, l, num);
                    if (!visit[cnt][change]) {
                        visit[cnt][change]=true;
                        BFS(change, cnt + 1);
                    }
                }
        }
    }
    public static int change_num(int i,int j,int num){
        i=Integer.toString(num).length()-i+1;
        j=Integer.toString(num).length()-j+1;
        int i_index=(int)((num%Math.pow(10,i))/Math.pow(10,i-1));
        int j_index=(int)((num%Math.pow(10,j))/Math.pow(10,j-1));
        return num-((int)Math.pow(10,i-1)*i_index)-(int)(Math.pow(10,j-1)*j_index)+(int)(Math.pow(10,j-1)*i_index)+(int)(Math.pow(10,i-1)*j_index);
    }
}