/*
문제
민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 친구이다. 우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 친구를 모으는 것이 취미이다.

어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스의 첫째 줄에는 친구 관계의 수 F가 주어지며, 이 값은 100,000을 넘지 않는다. 다음 F개의 줄에는 친구 관계가 생긴 순서대로 주어진다. 친구 관계는 두 사용자의 아이디로 이루어져 있으며, 알파벳 대문자 또는 소문자로만 이루어진 길이 20 이하의 문자열이다.

출력
친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

풀이:
총 생길수 있는 사람의 수는 N * 2 이고, 새로운 친구가 나올 때마다 해쉬맵에 번호와 함께 저장한다.
그리고 유니온-파인드로 집합을 합쳐주는데, 합쳐지는 집합의 루트 노드의 count를 최고 루트 노드의 count와 더한다.
 */
import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static HashMap<String, Integer> hm;
    public static int[] parent;
    public static int[] p_cnt;
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T ; i++) {
            hm = new HashMap<>();
            N = Integer.parseInt(br.readLine());

            parent = new int[N * 2];
            p_cnt = new int[N * 2];

            for (int j = 0; j < N * 2 ; j++) {
                parent[j] = j;
                p_cnt[j] = 1;
            }

            int cnt = 0;
            for (int j = 0; j < N ; j++) {
                st = new StringTokenizer(br.readLine());

                String usr1 = st.nextToken();
                String usr2 = st.nextToken();

                if(!hm.containsKey(usr1)){
                    hm.put(usr1, cnt);
                    cnt++;
                }
                if(!hm.containsKey(usr2)){
                    hm.put(usr2, cnt);
                    cnt++;
                }
                union(hm.get(usr1), hm.get(usr2));
            }
        }
        bw.flush();
        bw.close();
    }
    public static int find(int now){
        if(now == parent[now])
            return now;

        return parent[now] = find(parent[now]);
    }
    public static void union(int x, int y) throws IOException{
        x = find(x);
        y = find(y);

        if(x != y){
            parent[x] = y;
            p_cnt[y] += p_cnt[x];
        }
        bw.write(p_cnt[y] + "\n");
    }
}
