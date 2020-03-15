/*
문제
바이너리 왕국의 불쌍한 하인들은 매일 바이너리 길을 청소한다. 바이너리 길은 N개의 0 또는 1로 이루어진 수열이다.

0은 깨끗한 칸, 1은 더러운 칸을 의미한다.

그들은 "flip"이라는 기술만을 사용해서 청소를 한다. 이것은 연속된 더러운 칸을 깨끗하게 만드는 기술이다. 즉, 연속된 1을 모두 0으로 만든다.

바이너리 왕국의 악덕한 왕은 매일 하인들에게 M개의 시련을 내리는 것이 취미이다. 시련에는 2가지 종류가 있는데 다음과 같다.

"0": 현재 길의 모든 칸을 깨끗하게 만들기 위한 "flip"의 최소 횟수를 하인들에게 크게 외치게 한다.
"1 i": 바이너리 길의 i번째 칸을 더럽힌다. 단, 이미 더럽혀져 있다면 아무 일도 일어나지 않는다.
바이너리 왕국의 불쌍한 하인들의 슬픈 외침들을 출력하라.

입력
첫째 줄에 바이너리 길의 칸의 개수 N, 시련의 개수 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

둘째 줄에 N개의 현재 바이너리 길의 상태가 주어진다.

그다음 M개의 줄에 걸쳐서 시련이 주어진다. 이때 0번 시련은 "0", 1번 시련은 "1 i"와 같이 주어진다. (1 ≤ i ≤ N)

출력
0번 시련이 주어졌을 때, 하인들의 외침을 개행으로 구분하여 출력하라.

풀이 : 입력 수가 크므로 O(N) 만에 풀어야 합니다.
입력을 받을 때 연속된 1의 개수를 구합니다.
1 명령을 받을 때마다 다음 네가지 경우에 따라 flip의 개수를 조정합니다.
(원래 더러운 길이면 패스합니다.)
1. 왼쪽에 1 있고 오른쪽에 0 -> 그대로
2. 왼쪽에 0 있고 오른쪽에 1 -> 그대로
3. 왼쪽에 1 있고 오른쪽에 1 -> flip--
4. 왼쪽에 0 있고 오른쪽에 0 -> flip++
 */

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] binary = new int[N + 2];
        int flip = 0;
        boolean flag = false;

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N ; i++) {
            binary[i] = Integer.parseInt(st.nextToken());
            if(binary[i] == 1){
                if(!flag){
                    flip++;
                    flag = true;
                }
            }
            else{
                if(flag){
                    flag = false;
                }
            }
        }
        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            int order = Integer.parseInt(st.nextToken());
            if(order == 0){
                bw.write(flip + "\n");
            }
            else{
                int dirty = Integer.parseInt(st.nextToken());
                if(binary[dirty] == 0) {
                    if (binary[dirty - 1] == 1 && binary[dirty + 1] == 1) {
                        flip--;
                    }
                    else if (binary[dirty - 1] == 0 && binary[dirty + 1] == 0) {
                        flip++;
                    }
                }
                binary[dirty] = 1;
            }
        }
        bw.flush();
        bw.close();
    }
}