/*
문제
놀이공원에서 여러 개의 놀이기구를 맡아 일하는 세혁이와 근영이는 서로 좋아하는 사이이다. 그들은 쉬는 시간을 이용하여 둘만의 시간을 가지기를 원한다. 그래서 매일 일과 시작 전에 놀이기구의 운영 일정을 보고, 그날 둘이 함께할 수 있는 가장 긴 휴식시간이 언제인지를 찾으려고 한다.

놀이공원에서 일하는 모든 사람들은 어떤 놀이기구가 작동을 시작하기 10분 전부터, 모든 놀이기구가 작동을 멈춘 후 10분 후까지는 쉴 수 없고, 그 나머지 일과 시간에만 쉴 수 있다.

하루 일과를 시작하는 시각은 오전 10시이고, 일과를 마치는 시각은 오후 10시이다. 예를 들어 세 개의 놀이기구가 작동하는 시간이 다음과 같다고 하면,

놀이기구 1: 오전 10시 30분 ~ 오후 1시

놀이기구 2: 오후 7시 00분 ~ 오후 9시 10분

놀이기구 3: 오후 12시 30분 ~ 오후 4시 50분

세혁이와 근영이는 놀이기구 1이 운행되기 전에 20분, 놀이기구 3의 운행이 끝나고 놀이기구 2의 운행시작 전 사이에 1시간 50분, 놀이 2의 운행이 끝난 후에 40분 동안 쉴 수 있다. 따라서 둘이 함께할 수 있는 가장 긴 시간은 1시간 50분이다.

놀이기구 운영 일정이 주어질 때, 그 날 세혁이와 근영이가 함께할 수 있는 가장 긴 시간을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 놀이기구의 개수 N이 주어진다. 이어 N줄에 걸쳐 각 놀이기구의 운행시작 시각과 종료 시각이 빈 칸을 사이에 두고 주어진다. 시각은 시간단위 두 자리, 분 단위 두 자리로 구성되며 오후 1시는 13시, 오후 2시는 14시, ... , 오후 10시는 22시로 표현된다. N은 50 이하의 자연수이다.

출력
첫째 줄에 세혁이와 근영이가 함께할 수 있는 가장 긴 시간을 분 단위로 출력한다. 만약 함께할 수 있는 시간이 없다면 첫째 줄에 0을 출력한다.

풀이:
오전 10시~오후10시는 600분 ~ 1320분이므로 놀이기구가 가동되는 시간을 배열에서 제거해 풀이.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        boolean[] time = new boolean[1440];

        for (int i = 0; i < N ; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int start_M = (start / 100) * 60 + (start % 100) - 10;
            int end_M = (end / 100) * 60 + (end % 100) + 10;

            for (int j = start_M; j < end_M ; j++) {
                time[j] = true;
            }
        }
        int res = 0;
        int max = 0;
        for (int i = 600; i < 1320 ; i++) {
            if(!time[i]) {
                res++;
            }
            if(time[i] || i == 1319){
                max = Math.max(res, max);
                res = 0;
            }
        }
        bw.write(Integer.toString(max));
        bw.flush();
        bw.close();
    }
}