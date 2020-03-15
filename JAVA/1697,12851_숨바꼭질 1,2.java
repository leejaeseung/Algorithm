/*
    숨바꼭질 문제 : 크게 세 가지 경우로 나눔
    M>N : 짝수라면 /2, 홀수라면 +1한 뒤 /2 or -1한 뒤 /2를 재귀함수로 반복하여 N=M이 될 때까지 반복 -> 하지만 /2보다 +나-해서 가는게 빠른 경우가 있으므로 예외처리 필요
    그리고 12851문제에서 minCnt를 구할 때 M이 2이면 /2 와 -1 의 경우를 값은 같지만 다른 경우이므로 예외처리 해주어야함
    M==N : 답을 구했으므로 min을 갱신하고, minCnt로 몇개인지 셈 -> min이 갱신될 때 mnCnt도 1로 초기화
    M<N : -1하는 경우밖에 없으므로 M과N의 차이가 걸린 시간임-> 바로 min과 minCnt 갱신
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int min=0x7FFFFFFF;
    public static int minCnt=1;
    public static void main(String[] argc) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        String s=br.readLine();
        StringTokenizer st=new StringTokenizer(s);

        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());

        find(N,M,0);

        bw.write(min+"\n"+minCnt);
        bw.flush();
        bw.close();
    }
    public static int find(int N,int M,int sec){
        if(N==M){
            if(sec<min){
                minCnt=1;
                min=sec;
            }
            else if(sec==min){
                minCnt++;
            }
            return 1;
        }
        else if(N<M){
            if(N==0&&M==1){
                find(N,M-1,sec+1);
            }
            else {
                if(Math.abs(N-M/2)<=M-N) {
                    if (M % 2 == 0) {
                        find(N, M / 2, sec + 1);
                        if(M==2){
                            find(N, M-1, sec + 1);
                        }
                    } else {
                        find(N, (M + 1) / 2, sec + 2);
                        find(N, (M - 1) / 2, sec + 2);
                        if(M-1==2)
                            find(N, M-1, sec + 1);
                    }
                }
                else{
                    find(N,M-1,sec+1);
                }
            }
        }
        else{
            if(sec+(N-M)<min){
                minCnt=1;
                min=sec+N-M;
            }
            else if(sec+(N-M)==min){
                minCnt++;
            }
            return 1;
        }
        return 1;
    }
}
