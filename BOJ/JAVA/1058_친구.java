/*
    문제
지민이는 세계에서 가장 유명한 사람이 누구인지 궁금해졌다. 가장 유명한 사람을 구하는 방법은 각 사람의 2-친구를 구하면 된다. 어떤 사람 A가 또다른 사람 B의 2-친구가 되기 위해선, 두 사람이 친구이거나, A와 친구이고, B와 친구인 C가 존재해야 된다. 여기서 가장 유명한 사람은 2-친구의 수가 가장 많은 사람이다. 가장 유명한 사람의 2-친구의 수를 출력하는 프로그램을 작성하시오.

A와 B가 친구면, B와 A도 친구이고, A와 A는 친구가 아니다.

입력
첫째 줄에 사람의 수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 각 사람이 친구이면 Y, 아니면 N이 주어진다. (예제를 참고)

출력
첫째 줄에 가장 유명한 사람의 2-친구의 수를 출력한다.
    풀이 :
    플로이드 알고리즘
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int[][] fd;
    public static int N;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        PriorityQueue<Integer> pq=new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1>=o2?-1:1;
            }
        });

        N=Integer.parseInt(br.readLine());
        fd=new int[N][N];

        for (int i = 0; i <N ; i++) {
            String s=br.readLine();
            for (int j = 0; j <N ; j++) {
                if(s.charAt(j)=='N'){
                    fd[i][j]=100;
                }
                else{
                    fd[i][j]=1;
                }
            }
        }
        for (int i = 0; i <N ; i++) {
            Floid(i);
        }

        for (int i = 0; i <N ; i++) {
            int cnt=0;
            for (int j = 0; j <N ; j++) {
                if(fd[i][j]>0&&fd[i][j]<3){
                    cnt++;
                }
            }
            pq.offer(cnt);
        }
        System.out.println(pq.peek());
    }
    public static void Floid(int temp){
        for (int i = 0; i<N ; i++) { if(i==temp) continue;
            for (int j = 0; j <N ; j++) { if(j==temp||j==i) continue;
                    fd[i][j]=Math.min(fd[i][j],fd[i][temp]+fd[temp][j]);
            }
        }
    }
}
