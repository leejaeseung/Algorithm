/*
문제
태보(TaeBo)란, 태권도와 복싱을 조합한 운동이다. 복싱의 공격 기술로는 민첩하게 앞주먹을 뻗으면서 가볍게 치는 잽, 옆으로 치는 펀치인 훅이 있다.

선풍적인 인기에 태보 강의를 들으며 태보를 마스터한 혜정이는 이제 펀치 속도가 워낙 빨라서 잽과 훅을 반복하다보면 잔상이 남는다.

얼굴의 왼편에 왼손의 잔상이, 오른편에는 오른손이 잔상이 남을 때 혜정이는 주먹을 몇 번 뻗었을까?

주먹의 잔상은 =로 시작하여 @로 끝나고, 잔상이 남지 않는 경우는 없다. 얼굴 형태가 (^0^) 꼴이고, 주먹의 잔상이 같은 곳에 위치하지 않는다.

입력
문자열의 길이는 1,000을 넘지 않는다.

출력
첫째 줄에 왼손의 잔상의 수와 오른손의 잔상의 수를 출력한다.

풀이:
얼굴 모양을 정규표현식으로 나누어 왼쪽, 오른쪽 @ 의 개수를 세어 풀이함.
 */

import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        int left = 0;
        int right = 0;

        String[] sp = s.split("\\(\\^0\\^\\)");
        for (int i = 0; i < sp[0].length() ; i++) {
            if(sp[0].charAt(i) == '@')
                left++;
        }
        if(sp.length == 2) {
            for (int i = 0; i < sp[1].length(); i++) {
                if (sp[1].charAt(i) == '@')
                    right++;
            }
        }
        System.out.print(left + " " + right);
    }
}