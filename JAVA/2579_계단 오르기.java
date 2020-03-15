/*
    마지막 계단을 밟을 경우의 수를 나누어 풀이한다.
    1. 마지막 전칸을 밟고 마지막 칸을 밟을 경우 -> 이 경우는 마지막 전전전칸을 밟았어야 하므로 예외처리 해준다
    2. 마지막 전전칸을 밟고 마지막 칸을 밟을 경우

    틀린 이유 : 시간 초과
    재귀 함수로 탐색하며 찾도록 구현했지만 너무 오래걸림.
    해결 : dp배열(dp[i]엔 i까지의 최대값이 저장)을 만들어 O(N)만에 해결

*/
import java.io.*;

public class Main {

    public static int[] score;
    public static int[] dp;
    public static int N;
    public static int max=0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        N=Integer.parseInt(br.readLine());
        int index=N;
        score=new int[N+1];
        dp=new int[N+1];
        for (int i = 1; i <=N ; i++) {
            score[i]=Integer.parseInt(br.readLine());
        }
        if(N>=1)
        dp[1]=score[1];
        if(N>=2)
        dp[2]=score[1]+score[2];

        for(int i=3;i<=N;i++){
            dp[i]=Math.max(dp[i-2]+score[i],dp[i-3]+score[i-1]+score[i]);
        }
        bw.write(Integer.toString(dp[N]));
        bw.flush();
        bw.close();
    }
    public static int floor(int check,int floor_count,int sum){                 //재귀함수 1

        sum+=score[floor_count];
        if(floor_count==N) {
            if (max < sum) {
                max = sum;
                return 1;
            }
            else
                return -1;
        }

        if(check==0||check==1) {
            floor(check + 1, floor_count + 1, sum);
        }
        if(floor_count!=N-1) {
            floor(1, floor_count + 2, sum);
        }
        return 1;
    }
    public static int find(int floor_count){                                //재귀 함수 2
        int i_2,i_1;

        if(floor_count==1)
            return score[floor_count];
        else if(floor_count==0)
            return 0;
        else if(floor_count==2)
            return score[1]+score[2];

        i_1=find(floor_count-1);
        i_2=find(floor_count-2);

        if(i_1!=i_2+score[floor_count-1]){
            return Math.max(i_1,i_2)+score[floor_count];
        }
        else
        {
            return i_2+score[floor_count];
        }
    }
}
