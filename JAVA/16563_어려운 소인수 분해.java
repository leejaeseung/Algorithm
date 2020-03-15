/*
문제
지원이는 대회에 출제할 문제에 대해서 고민하다가 소인수분해 문제를 출제해야겠다고 마음을 먹었다. 그러나 그 이야기를 들은 동생의 반응은 지원이의 기분을 상하게 했다.

"소인수분해? 그거 너무 쉬운 거 아니야?"

지원이는 소인수분해의 어려움을 알려주고자 엄청난 자신감을 가진 동생에게 2와 500만 사이의 자연수 N개를 주고 소인수분해를 시켰다. 그러자 지원이의 동생은 기겁하며 쓰러졌다. 힘들어하는 지원이의 동생을 대신해서 여러분이 이것도 쉽다는 것을 보여주자!

입력
첫째 줄에는 자연수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 자연수 ki (2 ≤ ki ≤ 5,000,000, 1 ≤ i ≤ N)가 N개 주어진다.

출력
N줄에 걸쳐서 자연수 ki의 소인수들을 오름차순으로 출력하라.

두 번째 풀이 : 시간을 단축하려고 소수를 나누어 갈 때
(현재 수의 제곱근 < 나누는 수 ) 이면 뒤의 소수는 더 이상 볼 필요가 없으므로
현재 수를 출력하고 멈춥니다.
이 때, 4999999의 제곱근은 2236.xxx 이므로 소수의 최대 범위를 2239까지 늘려줘야 합니다.

첫 번째 풀이 : 5백만 까지의 입력이므로 필요한 소수는 2236 까지입니다.
숫자를 맨 처음 소수부터 나누어 나가면서 동시에 소수를 출력합니다.
마지막 남은 수가 2236 보다 큰 수면 그 수는 소수이므로 그대로 출력합니다.
 */

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static int[] num;
    public static ArrayList<Integer> prime = new ArrayList<>();
    public static boolean[] isprime = new boolean[2240];
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        num = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N ; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }
        isprime[0] = true;
        isprime[1] = true;
        getPrime();

        for (int i = 0; i < N ; i++) {
            int now = num[i];

            for (int j = 0; j < prime.size(); j++) {

                if(now % prime.get(j) == 0){
                    now /= prime.get(j);
                    bw.write(prime.get(j) + " ");
                    if(now == 1) {
                        bw.write("\n");
                        break;
                    }
                    j--;
                }
                else {
                    if ((int)Math.sqrt(now) < prime.get(j)) {
                        bw.write(now + "\n");
                        break;
                    }
                }
            }

        }
        bw.flush();
        bw.close();
    }
    public static void getPrime(){
        for (int i = 2; i < 2240; i++) {
            if(isprime[i])
                continue;
            for (int j = 2; 2240 > i * j; j++) {
                if(!isprime[i * j]){
                    isprime[i * j] = true;
                }
            }
        }
        for (int i = 0; i < 2240 ; i++) {
            if(!isprime[i])
                prime.add(i);
        }
    }
}