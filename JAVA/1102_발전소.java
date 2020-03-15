/*
문제
은진이는 발전소에서 근무한다. 은진이가 회사에서 잠깐 잘 때마다, 몇몇 발전소가 고장이난다. 게다가, 지금 은진이의 보스 형택이가 은진이의 사무실로 걸어오고 있다. 만약 은진이가 형택이가 들어오기 전까지 발전소를 고쳐놓지 못한다면, 은진이는 해고당할 것이다.

발전소를 고치는 방법은 간단하다. 고장나지 않은 발전소를 이용해서 고장난 발전소를 재시작하면 된다. 하지만, 이때 비용이 발생한다. 이 비용은 어떤 발전소에서 어떤 발전소를 재시작하느냐에 따라 다르다.

적어도 P개의 발전소가 고장나 있지 않도록, 발전소를 고치는 비용의 최솟값을 구하는 프로그램을 작성하시오.


입력
첫째 줄에 발전소의 개수 N이 주어진다. N은 16보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 발전소 i를 이용해서 발전소 j를 재시작할 때 드는 비용이 주어진다. i줄의 j번째 값이 그 값이다. 그 다음 줄에는 각 발전소가 켜져있으면 Y, 꺼져있으면 N이 순서대로 주어진다. 마지막 줄에는 P가 주어진다. 비용은 50보다 작거나 같은 음이 아닌 정수이고, P는 0보다 크거나 같고, N보다 작거나 같은 정수이다.

출력
첫째 줄에 문제의 정답을 출력한다. 불가능한 경우에는 -1을 출력한다.

풀이:
발전소가 켜진 경우를 1 , 꺼진 경우를 0으로 bit를 표시해줍니다.
먼저, 켜진 발전소에 대해 다음으로 킬 발전소를 정합니다.
그리고 해당 발전소를 킨 뒤 그 발전소가 켜졌다고 생각하고(bit를 1로 키고) 다음 꺼진 발전소에 대해 모두 TSP()함수를 호출합니다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N, P;
    public static int[][] cost;
    public static int[][] visit;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        cost = new int[N][N];
        visit = new int[N][1 << N];

        for (int i = 0; i < N ; i++) {
            for (int j = 0; j < (1 << N) ; j++) {
                visit[i][j] = -1;
            }
        }

        for (int i = 0; i < N ; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N ; j++) {
                cost[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        String str = br.readLine();
        int bit = 0;
        for (int i = 0; i < N ; i++) {
            if(str.charAt(i) == 'Y') {
                bit |= (1 << i);
            }
        }
        P = Integer.parseInt(br.readLine());

        if(P == 0)
            System.out.println(0);
        else {
            int res = 1000000000;
            for (int i = 0; i < N; i++) {
                if (str.charAt(i) == 'Y') {
                    res = Math.min(res, TSP(i, bit));
                }
            }
            if (res == 1000000000)
                System.out.println(-1);
            else
                System.out.println(res);
        }
    }
    public static int TSP(int now, int visited){
        int ret = visit[now][visited];

        if(countBit(visited) >= P)
            //켜진 발전소가 P 이상이면 0을 리턴합니다.
            return 0;

        if(ret != -1)
            return ret;

        ret = 1000000000;
        for (int i = 0; i < N ; i++) {
            if((visited & (1 << i)) != 0) continue;
            //꺼진 발전소를 찾습니다.

            int next = visited | (1 << i);
            //next발전소가 켜졌다고 가정합니다.

            for (int j = 0; j < N ; j++) {
                if((next & (1 << j)) != 0)
                    //next 발전소가 켜졌다고 생각하고 다음 꺼진 발전소에 대해 모두 TSP()를 호출합니다.
                    ret = Math.min(ret, TSP(j, next) + cost[now][i]);
            }
        }

        return visit[now][visited] = ret;
    }
    public static int countBit(int bit){
        int cnt = 0;

        while(bit != 0){
            cnt += (bit & 1);
            bit >>= 1;
        }
        return cnt;
    }
}