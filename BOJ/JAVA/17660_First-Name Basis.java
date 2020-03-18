/*
문제
In order to schedule who walks across the podium when, one typically uses alphabetical order by last name, breaking ties by first name. In order to do so, you first have to figure out which is a student’s first and last name. This gets more difficult because (1) in a number of countries/cultures, the order of family and given name is reversed, and (2) even when that’s not the case, students who can effortlessly write 10,000-LoC operating systems seem to have serious difficulty determining which of their first and last name to put into which of the two fields labeled “First Name” and “Last Name”. In this problem, you will write a program that helps USC’s administrators fix the ordering of first and last names.

Specifically, for each of the students, you will be given what he/she entered as their first and last name. Furthermore, you get to assume1 that each string can serve either as a first name or a last name, but not both. That is, you cannot have one person named “Aretha Franklin” and another named “Franklin Roosevelt”, because this would use “Franklin” as both a first and last name. If two students claimed to have these names, then one of them would have to have reversed his/her names. Given the list of names, you should output the smallest number of students whose claimed names need to be reversed to make all names consistent (i.e., each string is only used as a first name, or only used as a second name), or otherwise output “Impossible”.

1not completely realistically

입력
The first line is the number 1 ≤ K ≤ 100 of input data sets, followed by K data sets, each of the following form:

The first line is the number 0 ≤ n ≤ 1, 000 of students whose names were included. This is followed by n lines, each containing two strings si,1, si,2, separated by some kind of spaces. Each string consists of 1–30 lowercase letters.

출력
For each data set, output “Data Set x:” on a line by itself, where x is its number. Then, output the smallest number of students whose reported first and last names need to be reversed to make the input consistent, or output “Impossible” if there is no way to accomplish this.

Each data set should be followed by a blank line.

풀이:
이분 그래프 문제였습니다.
각 입력들을 양방향 간선으로 연결하고, 생기는 각 집합마다 이분 그래프로 나타내 줍니다.
그 뒤, 입력에서 첫 번째 문자들을 색깔에 따라 분류해 카운트해줍니다.
불가능한 경우는 이미 이분 그래프를 그릴 때 걸러졌기 때문에 모든 집합은 몇 개만 reverse 해주면 완성됩니다.
즉, 첫 번째 문자에 따라 분류된 색깔의 개수가 적은 만큼만 reverse해주면 됩니다.

코드는 http://contest.usc.edu/index.php/Main/Spring2019USCProgrammingContest?action=download&upname=sp19.first.hemant.java.txt 를 참고했습니다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static ArrayList<Node> tree;
    public static HashMap<String, Integer> hm;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(br.readLine());

        for (int i = 0; i < K ; i++) {
            bw.write("Data Set " + (i + 1) + ":\n");

            N = Integer.parseInt(br.readLine());
            tree = new ArrayList<>();
            hm = new HashMap<>();

            StringTokenizer st;
            int idx = 0;
            int[][] query = new int[N][2];

            for (int j = 0; j < N ; j++) {
                st = new StringTokenizer(br.readLine());
                String first = st.nextToken();
                String second = st.nextToken();

                if(!hm.containsKey(first)){
                    tree.add(new Node(idx));
                    hm.put(first, idx++);
                }
                if(!hm.containsKey(second)){
                    tree.add(new Node(idx));
                    hm.put(second, idx++);
                }
                int from = hm.get(first);
                int to = hm.get(second);
                query[j][0] = from;
                query[j][1] = to;

                tree.get(from).next.add(tree.get(to));
                tree.get(to).next.add(tree.get(from));
            }
            int setNum = binary();
            if(setNum == -1)
                bw.write("Impossible\n\n");
            else{
                int[][] answer = new int[setNum][2];
                //각 집합마다의 정답이 저장됩니다.

                for (int[] temp : query) {
                    //각 입력에서 첫 번째 문자의 색깔에 따라 분류해서 카운트합니다.
                    int first = temp[0];
                    if(tree.get(first).color == 0)
                        answer[tree.get(first).setNum][0]++;
                    else
                        answer[tree.get(first).setNum][1]++;
                }
                int res = 0;
                for (int[] cost : answer) {
                    res += Math.min(cost[0], cost[1]);
                }
                bw.write(res + "\n\n");
            }
        }
        bw.flush();
        bw.close();
    }
    public static int binary(){
        int set = 0;
        for (int i = 0; i < tree.size() ; i++) {
            if(tree.get(i).color != -1) continue;
            //이미 색칠된 집합이면 continue
            tree.get(i).setNum = set;
            set++;
            tree.get(i).color = 0;
            Queue<Node> q = new LinkedList<>();
            q.offer(tree.get(i));

            while(!q.isEmpty()){
                Node now = q.poll();

                for (int j = 0; j < tree.get(now.num).next.size() ; j++) {
                    Node next = tree.get(now.num).next.get(j);

                    if(now.color == next.color) return -1;
                    if(next.color != -1)    continue;
                    next.setNum = now.setNum;
                    next.color = 1 - now.color;
                    q.offer(next);
                }
            }
        }
        return set;
    }
}

class Node{
    int num;
    int setNum;
    int color = -1;
    ArrayList<Node> next;
    public Node(int num){
        this.num = num;
        next = new ArrayList<>();
    }
}