/*
문제
독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.

로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 중 k(k>6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.

예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는 경우의 수는 총 28가지이다. ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])

집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있다. 첫 번째 수는 k (6 < k < 13)이고, 다음 k개 수는 집합 S에 포함되는 수이다. S의 원소는 오름차순으로 주어진다.

입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스마다 수를 고르는 모든 방법을 출력한다. 이때, 사전 순으로 출력한다.

각 테스트 케이스 사이에는 빈 줄을 하나 출력한다.

풀이:
백트래킹 연습!
6개를 뽑아야 하므로 6개까지 cnt로 카운트를 세주고,
k - 5 번만큼만 반복으로 재귀호출해준다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static BufferedWriter bw;
    public static int[] numbers;
    public static int k;
    public static ArrayList<Integer> out;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        while(true){
            st = new StringTokenizer(br.readLine());
            k = Integer.parseInt(st.nextToken());
            out = new ArrayList<>();
            numbers = new int[k];
            if(k == 0)
                break;
            for (int i = 0; i < k ; i++) {
                int temp = Integer.parseInt(st.nextToken());
                numbers[i] = temp;
            }
            BT(0, 0);
            bw.write("\n");
            bw.flush();
        }
        bw.close();
    }
    public static void BT(int cnt, int idx) throws  IOException{
        if(cnt == 6){
            for (int i = 0; i < out.size() ; i++) {
                bw.write( out.get(i) + " ");
            }
            bw.write("\n");
            return;
        }
        for (int i = 0; i <= k - 6; i++) {
            if(idx + i >= k)  continue;
            out.add(numbers[idx + i]);
            BT(cnt + 1, idx + i + 1);
            out.remove(out.size() - 1);
        }
    }
}