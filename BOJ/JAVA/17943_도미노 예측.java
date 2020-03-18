/*
문제
보드게임 카페에서 아르바이트를 하는 정기는 사장님 몰래 도미노 놀이를 하는 취미가 있다. 도미노 놀이는 줄지어 세운 도미노의 한쪽 끝을 밀어 다른 도미노들을 연속적으로 넘어트리는 놀이를 말하는데, 정기는 사장님이 가장 아끼는 숫자 도미노로 도미노 놀이를 하기 때문에 사장님에게 들키지 않으려 노력한다.

그러나, 어느 때와 마찬가지로 사장님 몰래 도미노 놀이를 즐기고 있던 정기는 도미노가 쓰러지는 모습을 넋 놓고 지켜보던 중 사장님에게 도미노 놀이를 하는 장면을 들키고 말았다.

자신의 숫자 도미노를 가지고 있는 정기를 보며 화를 내려던 사장님은 줄을 완벽하게 맞추며 쓰러진 숫자 도미노를 보고 정기에게 자신이 낸 질문을 모두 맞춘다면 이번 일은 눈감아 주겠다고 하였고, 숫자 도미노의 진정한 사용 방법을 알려주었다.

정기가 도미노 놀이에 사용한 숫자 도미노는 앞면과 뒷면에 같은 정수가 적혀있는데, 숫자 도미노를 통한 도미노 놀이는 이 숫자들을 이용하여 도미노의 숫자를 추측하는 방식으로 이루어진다.

첫 번째 도미노는 쓰러지며 두 번째 도미노를 덮고, 두 번째 도미노는 세 번째 도미노를 덮는다. 이런 식으로 i번째 도미노는 i+1번째 도미노를 덮는데, 질문자는 첫 번째 도미노부터 마지막의 바로 전 도미노까지 각각의 도미노와 도미노가 덮은 도미노의 수를 XOR한 값을 기록한다. 즉, 첫 번째 도미노 수와 두 번째 도미노 수의 XOR, 두 번째 도미노 수와 세 번째 도미노 수의 XOR, 이런 식으로 도미노의 개수 – 1 개의 숫자를 기록한다.

이후 쓰러진 도미노를 치운 뒤 질문자는 플레이어에게 기록한 숫자를 보여주고, 두 가지 종류의 질문을 한다.

x번째 도미노의 수와 y번째 도미노의 수를 XOR한 값을 답하라.
x번째 도미노의 수가 d일 때, y번째 도미노의 수를 답하라.
숫자 도미노 놀이의 초보자인 정기를 위해 사장님의 질문에 대신 답해줄 프로그램을 작성해보자.

입력
첫 번째 줄에 숫자 도미노의 개수 N과 질문의 수 Q가 정수로 주어진다. (3 ≤ N ≤ 2 × 105, 1 ≤ Q ≤ 105)

두 번째 줄에 사장님이 기록한 N-1개의 정수가 주어진다. (각각의 정수는 0 이상 231-1 이하이다.)

세 번째 줄부터 Q개의 줄에 걸쳐 각각의 줄에 사장님의 질문이 주어진다. 질문의 형식은 “0 x y” 또는 “1 x y d”이고, 순서대로 1번 질문과 2번 질문을 의미한다. ( 1 ≤ x ≤ y ≤ N, 0 ≤ d ≤ 231-1)

출력
주어진 질문의 답을 Q개의 줄에 걸쳐 출력한다.

풀이:
비트 연산과 세그먼트 트리(XOR) 문제입니다.
1번 질문 : x번째 도미노에서 y번째 도미노까지 XOR한 비트의 1의 개수가 짝수 개라면 그 비트는 같습니다.
예를 들어,
1
0001
2
0010
3
0011
4
0100
5
1~4까지 모든 XOR 계산값(0001,0010,0011)을 XOR하면 1이 모두 지워지게 되어 같은 수라는 것을 알 수 있습니다.
따라서 x ~ y-1 까지의 모든 XOR 계산값들을 XOR 하면 1번 질문의 답이 됩니다. 단, x 와 y가 같다면 0을 출력합니다.

2번 질문 : 1번 질문에서 구한 값의 비트(Mask) 1은 d와 다른 비트의 위치입니다.
따라서 해당 위치의 비트를 반전시킨 값이 y가 됩니다.
Mask 비트의 위치만 반전시키는 식은 다음과 같습니다.
res = ~(xor ^ (~d))
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main17 {

    public static int[] tree;
    public static int[] num;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        int H = (int)Math.ceil((Math.log(N - 1) / Math.log(2)));

        num = new int[N];
        tree = new int[(int)Math.pow(2, H + 1) + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N - 1 ; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }

        init(1, 1, N - 1);

        for (int i = 0; i < Q ; i++) {
            st = new StringTokenizer(br.readLine());
            int question = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            int xor = getXor(1, 1, N - 1, x, y - 1);

            if(question == 0){

                if(x != y)
                    bw.write(xor + "\n");
                else
                    bw.write(0 + "\n");
            }
            else{
                int d = Integer.parseInt(st.nextToken());
                int res = ~(xor ^ (~d));

                if(x != y)
                    bw.write(res + "\n");
                else
                    bw.write(d + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
    public static int init(int now, int left, int right){
        if(left == right){
            return tree[now] = num[left];
        }
        return tree[now] = init(now * 2, left, (left + right) / 2) ^ init(now * 2 + 1, (left + right) / 2 + 1, right);
    }
    public static int getXor(int now, int left, int right, int start, int end){
        if(start > right || end < left) return 0;
        if(left >= start && right <= end)   return tree[now];

        return getXor(now * 2, left, (left + right) / 2, start, end) ^ getXor(now * 2 + 1, (left + right) / 2 + 1, right, start, end);
    }
}