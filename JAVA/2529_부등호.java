/*
    문제
두 종류의 부등호 기호 ‘<’와 ‘>’가 k개 나열된 순서열  A가 있다. 우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다. 예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자.

A =>  < < < > < < > < >

부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 아래는 부등호 순서열 A를 만족시키는 한 예이다.

3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

이 상황에서 부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 이 수를 주어진 부등호 관계를 만족시키는 정수라고 한다. 그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다.

5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

여러분은 제시된 k개의 부등호 순서를 만족하는 (k+1)자리의 정수 중에서 최댓값과 최솟값을 찾아야 한다. 앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }중에서 선택해야 하며 선택된 숫자는 모두 달라야 한다.

입력
첫 줄에 부등호 문자의 개수를 나타내는 정수 k가 주어진다. 그 다음 줄에는 k개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. k의 범위는 2 ≤ k ≤ 9 이다.

출력
여러분은 제시된 부등호 관계를 만족하는 k+1 자리의 최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력해야 한다. 단 아래 예(1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다.
    풀이 :
    부등호 기호를 그래프에서 유방향 간선으로 생각하여 최대값을 찾을 땐 >를 ->, <를 <-의 방향으로 보고, 최소값을 찾을 땐 반대로 생각하여 그래프를 만든다.
    최대, 최소는 그리디 알고리즘을 기반으로하여 우선순위 큐를 이용한 위상정렬을 한다.(최대의 경우 높은 수부터 들어갈 때 큐 중 가장 앞쪽의 순서에 들어가야 하므로)
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        String s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);

        Node[] nd_max = new Node[N + 1];
        Node[] nd_min = new Node[N+1];
        for (int i = 0; i < N + 1; i++) {
            nd_max[i] = new Node(i);
            nd_min[i]=new Node(i);
        }
        for (int i = 0; i < N; i++) {
            if (st.nextToken().charAt(0) == '>') {
                nd_max[i].next.add(nd_max[i+1]);
                nd_max[i+1].indegree++;
                nd_min[i+1].next.add(nd_min[i]);
                nd_min[i].indegree++;
            } else {
                nd_max[i+1].next.add(nd_max[i]);
                nd_max[i].indegree++;
                nd_min[i].next.add(nd_min[i+1]);
                nd_min[i+1].indegree++;
            }
        }
        TPS(nd_max,9,false);
        System.out.println();
        TPS(nd_min,0,true);
    }
    public static void TPS(Node[] nd,int index,boolean isMin){
        PriorityQueue<Node> pq=new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.num<=o2.num?-1:1;
            }
        });
        int[] printNum=new int[10];
        for (int i = 0; i <nd.length ; i++) {
            if(nd[i].indegree==0){
                pq.offer(nd[i]);
            }
        }
        while(!pq.isEmpty()){
            Node temp=pq.poll();
            printNum[temp.num]=index;
            if(isMin==false)
                index--;
            else
                index++;
            for (int i = 0; i <temp.next.size() ; i++) {
                temp.next.get(i).indegree--;
                if(temp.next.get(i).indegree==0)
                    pq.offer(temp.next.get(i));
            }
        }
        for (int i = 0; i <N+1 ; i++) {
            System.out.print(printNum[i]);
        }
    }
}

class Node{
    public int num;
    public ArrayList<Node> next;
    public int indegree;
    public Node(int num){
        next=new ArrayList<>();
        this.num=num;
    }
}