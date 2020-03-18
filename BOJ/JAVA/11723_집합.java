/*
문제
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다.
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다.
입력
첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.

둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

출력
check 연산이 주어질때마다, 결과를 출력한다.

풀이:
x의 범위가 20이하이므로 16bit짜리 char 배열 2개로 해결 가능하다.
x번째 bit를 적절하게 비트 연산으로 바꿔가며 풀이한다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static char[] c;
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());
        c = new char[2];

        for (int i = 0; i < T ; i++) {
            st = new StringTokenizer(br.readLine());
            String order = st.nextToken();

            switch (order){
                case "add":
                    add(Integer.parseInt(st.nextToken()));
                    break;
                case "remove":
                    remove(Integer.parseInt(st.nextToken()));
                    break;
                case "check":
                    check(Integer.parseInt(st.nextToken()));
                    break;
                case "toggle":
                    toggle(Integer.parseInt(st.nextToken()));
                    break;
                case "all":
                    all();
                    break;
                case "empty":
                    empty();
                    break;
                default:
                    break;
            }
        }
        bw.flush();
        bw.close();
    }
    public static void add(int x){
        c[x >> 4] = (char)(c[x >> 4] | (1 << ((x & 0x000F) - 1)));
    }
    public static void remove(int x){
        c[x >> 4] = (char)~(c[x >> 4] ^ ~(1 << ((x & 0x000F) - 1)));
    }
    public static void check(int x) throws IOException{
        bw.write(((c[x >> 4] >> (x & 0x000F) - 1) & 1) + "\n");
    }
    public static void toggle(int x){
        c[x >> 4] = (char)(c[x >> 4] ^ (1 << (x & 0x000F) - 1));
    }
    public static void all(){
        c[0] = 0xFFFF;
        c[1] = 0x000F;
    }
    public static void empty(){
        c[0] = 0;
        c[1] = 0;
    }
}