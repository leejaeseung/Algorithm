/*
    카카오프렌즈 스토어에서는 N종류의 인형을 팔고 있다. N개의 인형들 중에서는 잘 팔리는 인형과 그렇지 않은 인형들이 섞여 있어서 잘 팔리는 인형은 상대적으로 사람들이 많이 볼 수 있는 곳에 배치하고, 잘 팔리지 않는 인형은 상대적으로 사람들이 적게 볼 수 있는 곳에 배치한다. 그러므로 배치된 곳이 가까운 두 인형은 상대적으로 판매량이 비슷하다고 할 수 있다.

좋은 배치를 정하기 위해서 어느 날, 여러 명의 사람들을 대상으로 인형의 선호도를 조사하였다. 조사 결과 각 인형에 대해서 선호하는 사람의 수를 모두 구하였고, 그에 따라 인형의 배치를 정하려고 한다.

카카오프렌즈 스토어를 관리하는 브라이언은 어떠한 특정한 곳에 인형들을 배치하고자 하는데, 그곳에 인형들을 선택하는 방법은 다음과 같다:

먼저 비슷한 인형이 가깝게 위치하도록 서로 다른 N개의 인형을 종류당 한 개씩 일렬로 배치한다.
그 후, 선호하는 사람의 수의 표준편차가 최소가 되는, K개 이상의 연속된 위치에 있는 인형들을 선택하여 그들을 같은 곳에 배치한다.
위의 방법으로 인형들을 선택했을 때, 선택된 인형들의 선호하는 사람의 수의 표준편차를 구하여라.

N개의 수 a1, a2, …, aN이 주어져 있을 때, 통계학에서 (산술) 평균은 (a1 + a2 + … + aN) / N 으로 정의한다. 이를 m으로 정의하자. 또한, 분산은 ((a1 - m)2 + (a2 - m)2 + … + (aN - m)2) / N으로 정의하고, 표준 편차는 분산의 음이 아닌 제곱근으로 정의한다.

입력
첫 번째 줄에 N과 K가 주어진다. N은 1 이상 500 이하의 정수이고, K는 1 이상 N 이하의 정수이다.

두 번째 줄에는 N개의 정수가 입력되며, 이는 인형이 일렬로 나열된 순서대로 인형을 선호하는 사람의 수이다. 각 수는 모두 106 이하의 음이 아닌 정수이다.

출력
선택된 인형들을 선호하는 사람의 수의 표준 편차를 출력한다. 출력한 결과와 실제 답을 비교하였을 때의 상대/절대 오차가 10-6 이하인 경우에만 정답으로 인정한다.
    풀이 : 하라는 대로만 하자. ( K개 이상 주의 )
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int K=Integer.parseInt(st.nextToken());
        double[] dolls=new double[N];
        double min=Double.MAX_VALUE;

        st=new StringTokenizer(br.readLine());
        for (int i = 0; i <N ; i++) {
            dolls[i]=Double.parseDouble(st.nextToken());
        }
        while (N>=K) {
            for (int i = 0; i < N - K + 1; i++) {
                double aver = 0;
                for (int j = i; j < K + i; j++) {
                    aver += dolls[j];
                }
                aver /= (double) K;
                double sd = 0;
                for (int j = i; j < K + i; j++) {
                    sd += Math.pow(dolls[j] - aver, 2);
                }
                sd /= (double) K;
                min = Math.min(min, Math.sqrt(sd));
            }
            K++;
        }
        bw.write(String.format("%.11f",min));
        bw.flush();
        bw.close();
    }
}
