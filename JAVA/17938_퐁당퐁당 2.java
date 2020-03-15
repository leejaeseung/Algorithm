/*
문제
퐁당퐁당은 술게임 중 팀워크가 가장 중요한 MT 단골 게임이다. 매 차례마다 지정된 수의 팔을 동시에 들어야 하는데, 이를 실패하면 팔을 들어야했던 사람과 실수로 팔을 든 사람 모두 연좌제로 마셔야 하기 때문이다. 퐁당퐁당 게임의 규칙은 아래와 같다.

1번 사람부터 N번 사람까지 순서대로 총 N명의 사람들이 원 모양을 이루어 반시계방향으로 둘러앉는다. 이 때 모든 사람들은 원의 중앙을 바라보고 앉는다.
게임은 1번 사람의 왼팔부터 시작하여 원의 바깥에서 보았을 때 왼쪽에서 오른쪽으로 진행한다.
첫번째 차례 이후 매 차례마다 가장 오른쪽 사람이 들었던 팔의 다음 팔부터 진행하고, 순서대로 지정된 수만큼의 팔을 들어올린다.
게임을 시작할 때 들어야 하는 팔의 갯수는 1개이다. 시작하여 차례가 지날 때마다 들어야 하는팔의 개수는 1씩 증가한다.
들어야 하는 팔의 갯수가 2 × N 개가 되었다면 다음 차례부터 1씩 감소시킨다.
들어야 하는 팔의 갯수가 1개가 되었다면 다음 차례부터 다시 1씩 증가시킨다.
즉, 매 차례에 들어야 할 팔의 갯수는 1 이상 2 × N 이하로 유지된다.
엠티에서 퐁당퐁당 게임을 하던 휘수는 친구들이 너무 잘하는 것을 보고 재미가 없어져, 최대한 많은 사람을 먹이기 위해 자기가 해당하는 차례에 일부러 팔을 들지 않으려고 한다. 휘수는 매 차례마다 자기가 트롤을 해서 사람들과 다 같이 술을 먹을 수 있을지 알고 싶어 한다. 여러분이 휘수를 도와주자!

입력
첫 번째 줄에 게임에 참여하는 사람수 N이 정수로 주어진다. (2 ≤ N ≤ 1,000)

두 번째 줄에는 휘수의 위치 P와 차례 T가 정수로 주어진다. (1 ≤ P ≤ N, 1 ≤ T ≤ 10,000,000)

출력
만약 T번째 차례에 휘수가 팔을 들어야 해서, 휘수가 트롤을 성공할 수 있다면 “Dehet YeonJwaJe ^~^”을 출력하고, 휘수가 트롤을 할 수 없는 위치라면 “Hing…NoJam”을 출력한다.

풀이:
풍당퐁당1 의 코드를 재사용하여 풀이.
가장 마지막 이전의 팔 번호와 가장 마지막 팔 번호 사이에 휘수의 위치가 있는지 판단한다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main12 {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int P = Integer.parseInt(st.nextToken());
        int T = Integer.parseInt(st.nextToken());

        int arm = 1;
        int cnt = 1;
        int p = -1;
        int sum = 0;
        int left = 0;
        int right = 0;

        while(cnt != T){
            if(arm == 2 * N || arm == 1)
                p *= -1;
            arm += p;
            if(cnt == T -1) {
                left = sum;
            }
            sum = (sum + arm) % (N * 2);
            if(cnt == T -1) {
                right = sum;
            }
            cnt++;
        }
        boolean flag = true;
        if(left > right){
            if(left < 2 * P || right >= 2 * P - 1)
                flag = true;
            else
                flag = false;
        }
        else{
            if(left < 2 * P && right >= 2 * P - 1)
                flag = true;
            else
                flag = false;
        }

        if(flag)
            System.out.println("Dehet YeonJwaJe ^~^");
        else
            System.out.println("Hing...NoJam");
    }
}