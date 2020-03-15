/*
문제
투튜브의 유명 BJ인 민서는 팬들로부터 많은 사랑을 받고 있다. 팬들은 자신들의 팬심을 표현하기 위해 민서에게 많은 선물을 보내준다. 그 중 민서가 가장 좋아하는 선물은 사과이다. 이 사실을 알게 된 민서의 열혈 팬 성주는 민서에게 특별 포장 되어있는 사과세트를 보내주었다.

며칠이 지나 사과세트를 받은 민서는 포장 방식을 보고 적잖이 당황하였다. 총 2N개의 사과가 들어있었는데, 2개의 기다란 튜브에 N개씩 들어있었다. 각 튜브는 맨 앞과 끝이 뚫려 있어 총 4개의 구멍으로만 사과를 꺼낼 수 있다. 2N개의 사과는 각기 다른 크기를 가지고 있는데, 그 크기는 1부터 2N까지로 중복 없는 크기를 가지고 있다. 민서는 사과를 꺼낼 때, 구멍 쪽에 위치한 4개 이하의 사과 중 크기가 가장 작은 사과를 꺼낸다. 이 과정을 2N번 반복하여 모든 사과를 튜브에서 꺼내게 된다.

하지만 성주가 선물해준 사과는 너무 신선하여 민서가 포장을 뜯는 즉시 조금씩 부패하기 시작한다. 양의 정수 T초의 시간이 지나게 되면, 튜브 안에 들어있는 사과들은 “크기 x T”만큼의 부패도를 가지게 되고, 부패도는 누적된다.

성주도 사과가 부패한다는 사실을 당연히 알기 때문에, 민서에게 보내기 전 최대한 사과들이 부패하지 않도록 배치하려고 한다. 즉, 총 부패도가 최소가 되게 하려고 한다. 여러분이 성주의 팬심이 민서에게 전해지도록 도와주자.

입력
첫째 줄에 양의 정수 N이 주어진다. (1 ≤ N ≤ 10,000)

출력
첫째 줄에 최소의 부패도를 출력한다.

둘째 줄과 셋째 줄에 최소의 부패도를 가지는 사과의 배치를 출력한다. 만약 최소의 부패도를 가지는 사과의 배치가 여러가지 존재할 경우, 그 중 아무거나 출력한다.

풀이:
N = 5
7 6 5 4 8
9 3 2 1 10

부패값이 최소가 되려면 최대한 큰 크기를 뽑아내야 합니다.
다음 규칙들을 고려하여 풀이합니다.
1. 위에서(큰 쪽) 4번째까지의 수는 가장 바깥에 존재합니다.(4번째로 큰 수를 뽑아내게 하기 위해)
2. 4번째로 큰 수의 옆에는 N - 2개의 수들이 1씩 감소하며 존재합니다.(3번째로 큰 수까진 뽑을 수가 없기 때문에 차선책으로 바로 아래 크기를 뽑습니다.
3. 2번을 수행해 모두 뽑았다면, 그 줄 마지막엔 세 번째로 큰 수가 존재합니다.(한 줄이 모두 없어집니다.)
4. 나머지 줄은 두 번째로 큰 수와 가장 큰 수가 둘러싸고 있습니다.(다른 줄을 모두 없애기 전까지 뽑지 못합니다.)
5. 두 번째로 큰 수 옆에는 남은 수들 중 가장 큰 수부터 1씩 감소하며 존재합니다.

위 규칙에 따라 배열을 만들어놓고, 시간마다 계산해가며 풀이했습니다.
 */
import java.io.*;

public class Main7 {

    public static int N;
    public static int[][] tube;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        tube = new int[2][N];
        tube[0][0] = 2 * N - 3;
        tube[0][N - 1] = 2 * N - 2;
        tube[1][0] = 2 * N - 1;
        tube[1][N - 1] = 2 * N;
        for (int i = 1; i < N - 1 ; i++) {
            tube[0][i] = 2 * N - 3 - i;
        }
        int init = 1;
        for (int i = N - 2; i > 0 ; i--) {
            tube[1][i] = init++;
        }

        long res = 0;
        long time = 0;
        long sub = 0;
        if(N > 1) {
            for (int i = 0; i < N - 1; i++) {
                res += (6 * N - 3) * time;
                res += (((2 * N - 3) * (N - 1)) - sub) * time;
                sub += tube[0][i];
                time++;
            }
            res += (6 * N - 3) * time;
            res += (((N - 2) * (N - 1)) / 2) * time;
            time++;
            res += (4 * N - 1) * time;
            res += (((N - 2) * (N - 1)) / 2) * time;
            time++;
            sub = 0;
            for (int i = 0; i < N - 2; i++) {
                res += ((((N - 2) * (N - 1)) / 2) - sub) * time;
                res += (2 * N) * time;
                sub += tube[1][i + 1];
                time++;
            }
            res += 2 * N * time;

            bw.write(res + "\n");
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < N; j++) {
                    bw.write(tube[i][j] + " ");
                }
                bw.write("\n");
            }
        }
        else{
            bw.write(2 + "\n");
            bw.write(1 + "\n");
            bw.write(2 + "\n");
        }
        bw.flush();
        bw.close();
    }
}