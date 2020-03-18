/*
문제
초등학생 준석이는 영어를 배우고 있는 중이다.

개구쟁이인 준석이는 단어에서 본인이 마음에 드는 부분을 뽑아 섞어 읽고, 뽑은 부분의 알파벳 종류와 개수만 이야기한다.

준석이와 소통하고 싶어하는 진우 선생님은 준석이가 일정한 규칙을 가지고 읽는다는 것을 깨달았다.

진우 선생님이 발견한 규칙은 다음과 같다.

먼저, 준석이는 주어진 단어에서 본인이 읽고 싶은 연속된 문자열을 뽑아 다음의 규칙에 따라 새 문자열을 만든다.

문자열을 반으로 나눈다.
1번 과정에서 나눠진 두 개의 문자열 중 한 쪽 문자열만 역순으로 바꾼다.
2번 과정에서 역순으로 바꾸지 않은 다른 한 쪽의 문자열을 다시 반으로 나눈다.
3번 과정에서 반으로 나눈 두 개의 문자열 중 한 쪽 문자열만 역순으로 바꾼다.
1 ~ 4번 과정을 반복한다.  단, 반복하는 과정에서 역순으로 바꿀 문자열은 무작위로 선택하고 선택한 문자열의 길이가 1이라면 역순으로 바꾸지 않고 끝낸다.
위의 규칙에 따라 여러 문자열들을 만들 수 있는데 만약 만들어진 문자열이 중복되면, 오직 1개만 가능한 문자열로 생각한다.

또한 반으로 나눌 문자열 S의 길이가 N이라 하면, N이 홀수일 경우 반으로 나누는 방법은 두 가지가 생긴다.

이 경우, 두 가지를 모두 가능한 방법으로 생각하며 두 가지 방법에서 발생하는 모든 경우의 수도 포함해야 한다.

이런 규칙에 따라 새 문자열을 만들고 나면 준석이는 그 문자열에 포함된 알파벳과 알파벳의 개수를 말한다. (단, 준석이가 잘못 말할 가능성은 없다.)

예를 들어, inconvenience라는 단어가 주어졌다고 하자.

준석이는 e가 2개, n이 2개, i가 1개, c가 1개라고 말한다.

준석이가 말한 조건에 따르면, 준석이가 단어 속에서 뽑은 연속된 문자열은 두 개가 될 수 있다.(enienc, nience)

예시를 위해 enienc를 봤다고 가정하자.

enienc를 반으로 나누면 eni와 enc가 된다.
eni 또는 enc를 역순으로 바꾼다. 예시에서는 enc의 순서를 역순으로 한다. (cne)
eni를 역순으로 바꾸지 않았으므로 eni를 반으로 나눈다. 다만, 정확히 반으로 나눌 수 없기 때문에 e ni와 en i로 두 가지 경우가 생길 수 있다. 예시에서는 e ni일 경우를 설명하겠다.
만약 e를 선택한다면 eni가 되고, ni를 선택한다면 ein이 된다. 따라서, enicne 혹은 eincne가 된다.
이처럼 inconvenience라는 단어가 주어지고, 준석이가 단어 속에서 뽑은 연속된 문자열 enienc과 nience에 대하여

준석이의 규칙에 의해 만들어진 문자열들은 eincne, einnce, einnec, enicne, ineecn, ineenc, inenec, neicne, neiecn, nieecn으로 총 10개다.

진우 선생님은 준석이와 소통을 하기 위해 준석이의 규칙에 의해 만들어질 문자열들을 모두 알아내고자 한다.

진우 선생님을 도와 주어진 단어, 준석이가 말한 알파벳과 알파벳들의 개수를 토대로 규칙에 따라 만들 수 있는 문자열들의 개수를 출력하는 프로그램을 만들자.

입력
첫째 줄에 준석이가 말한 알파벳 종류의 개수가 주어진다. 단, 알파벳 종류의 개수는 N개(0 < N < 15)다.

둘째 줄에는 준석이가 말한 알파벳들과 각각의 개수가 주어진다. 단, 각각의 개수는 M개(0 < M < 15)다.

세번째 줄에는 알파벳 소문자로 이루어진 영어 단어가 주어진다. 단, 영어 단어의 길이는 알파벳 각각의 갯수들의 합 이상이며 15자 미만이다.

출력
규칙에 따라 만들 수 있는 문자열의 개수를 출력한다. 단, 중복되는 문자열일 경우 그 문자열은 1개로 취급해야 한다.

풀이:
범위가 모두 15이하이기 때문에 재귀호출을 이용한 완전 탐색으로 풀이하였습니다.
먼저 준식이가 말한 알파벳에 맞게 전체 단어에서 sub 단어를 분리해줍니다. -> isCorrect()
시작 인덱스(s) 와 종료 인덱스(e) 가 주어지면 해당 위치만 역순으로 바꾸는 swap() 함수를 구현합니다.
그리고 재귀 함수를 돌면서 앞쪽을 바꾼 경우(front), 뒤쪽은 바꾼 경우(back)에 따라 인덱스를 조절해가며 재귀 호출해줍니다.
역순으로 바꿀 단어가 홀수인 경우엔 시작 인덱스(s)를 1 증가시켜 한번 더 재귀 호출합니다.

중복 확인은 해쉬맵을 이용합니다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N, sum;
    public static String str;
    public static HashMap<String, Boolean> hm = new HashMap<>();
    public static int[] alpha = new int[26];
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        sum = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N ; i++) {
            sum += alpha[st.nextToken().charAt(0) - 'a'] = Integer.parseInt(st.nextToken());
        }

        str = br.readLine();

        for (int i = 0; i <= str.length() - sum ; i++) {
            StringBuilder sub = new StringBuilder().append(str.substring(i, i + sum));
            if(isCorrect(sub.toString())){
                half(sub, 0, sub.length());
            }
        }
        System.out.println(hm.size());
    }
    public static boolean isCorrect(String s){
        int[] check = new int[26];
        for (int i = 0; i < 26 ; i++) {
            check[i] = alpha[i];
        }
        for (int i = 0; i < s.length() ; i++) {
            if(--check[s.charAt(i) - 'a'] < 0)
                return false;
        }
        return true;
    }
    public static void half(StringBuilder str, int s, int e){
        if(e == s + 1 || e == s + 2) {
            if(!hm.containsKey(str.toString()))
                //이미 들어가있는 문자열이 아니라면
                hm.put(str.toString(), true);
            return;
        }

        StringBuilder front = swap(str, s, (s + e) / 2);
        StringBuilder back = swap(str, (s + e) / 2, e);
        //front = 앞쪽이 반전된 문자열
        //back = 뒤쪽이 반전된 문자열

        half(front, (s + e) / 2, e);
        half(back, s, (s + e) / 2);

        if((s + e) % 2 != 0) {
            //홀수인 경우 시작 길이를 1 늘려 경우를 추가해줌.
            front = swap(str, s, (s + e) / 2 + 1);
            back = swap(str, (s + e) / 2 + 1, e);

            half(front, (s + e) / 2 + 1, e);
            half(back, s, (s + e) / 2 + 1);
        }
    }
    public static StringBuilder swap(StringBuilder str, int s, int e){
        //s 와 e 사이의 문자열을 반전시키는 함수
        StringBuilder ret = new StringBuilder();

        ret.append(str.substring(0, s)).append(new StringBuilder().append(str.substring(s, e)).reverse());
        if(e < str.length())
            ret.append(str.substring(e, str.length()));
        return ret;
    }
}