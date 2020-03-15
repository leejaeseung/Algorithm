/*
문제
어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다. 예를 들어 11=32+12+12(3개 항)이다. 이런 표현방법은 여러 가지가 될 수 있는데, 11의 경우 11=22+22+12+12+12(5개 항)도 가능하다. 이 경우, 수학자 숌크라테스는 “11은 3개 항의 제곱수 합으로 표현할 수 있다.”라고 말한다. 또한 11은 그보다 적은 항의 제곱수 합으로 표현할 수 없으므로, 11을 그 합으로써 표현할 수 있는 제곱수 항의 최소 개수는 3이다.

주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 그 항의 최소개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 100,000)

출력
주어진 자연수를 제곱수의 합으로 나타낼 때에 그 제곱수 항의 최소 개수를 출력한다.

풀이:
BFS로 풀이함.
N부터 시작하여 가장 가까운 제곱수를 빼가며 0이 될때까지 BFS로 탐색
 */
import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        ArrayList<Integer> pow = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i * i <= 100000 ; i++) {
            pow.add(i * i);
        }
        boolean[] visit = new boolean[N + 1];
        int cnt = -1;
        q.offer(N);
        visit[N] = true;

        while (!q.isEmpty()){
            int size = q.size();
            cnt++;

            for (int j = 0; j < size ; j++) {
                int now = q.poll();

                if(now == 0){
                    bw.write(Integer.toString(cnt));
                }

                for (int i = pow.size() - 1; i >= 0; i--) {
                    int next = now - pow.get(i);

                    if (next < 0)
                        continue;
                    if (!visit[next]){
                        visit[next] = true;
                        q.offer(next);
                    }
                }
            }
        }
        bw.flush();
        bw.close();
    }
}