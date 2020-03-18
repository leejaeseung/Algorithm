/*
문제
성규는 학점이 높고 알고리즘도 잘 다루는 편이라 매년 알고리즘 대회에 나가 수상을 해오곤 한다. 성규의 꿈은 대학교 4학년 칼졸업을 하고 나서 좋은 대기업에 취직하여 빨리 돈을 버는 것이다.

어느 날, 성규는 전공 수업을 들으러 강의실에 가서 책을 펴고 앉았다. 이 때 교수님이 수업을 시작하시기 전에 한 말씀 하셨다.

교수님: "음... 여기서 내가 눈 여겨 봐온 학생이 있는데... 그래, 성규야. 너 내 랩실에 들어올 생각 없니? 나와 함께 알고리즘에 대한 논문이나 써보자꾸나."

성규는 큰일이다 싶었다. 성규는 졸업하고 싶었다. 대답을 할 생각이 떠오르기 전에 먼저 도망가야겠다는 생각이 들어버렸다!

강의실에는 가로로 N 행, 세로로 N 열, 총 N × N 개의 책상이 있으며, 위쪽에서부터 R 번째 행, 왼쪽에서부터 C 번째 열에 있는 책상의 위치를 (R, C)로 표현한다. 각 책상 자리는 비어있거나, 성규가 아닌 학생 혹은 성규가 앉아있거나, 교수님이 위치해 있다.

도망가는 데 성공하려면, 성규와 교수님의 거리가 5 이상이면서, 교수님과 성규를 꼭짓점으로 하는 축에 평행한 직사각형 안에, 교수님을 제지해줄 성규가 아닌 학생이 세 명 이상 있어야 한다.
단, 교수님과 성규가 같은 행 혹은 같은 열의 책상에 앉아있다면 교수님과 성규를 잇는 선분 상에 성규가 아닌 학생이 세 명 이상 있어야 한다.

이때, 책상 (a, b)와 책상 (c, d) 간의 거리는 로 정의한다.

성규는 도망가다가 잡히는 것이 최악이라 판단되어, 도망갈 수가 없는 환경이면 순순히 대학원생의 길로 들어서려고 한다. 이런 성규를 위해 확실히 도망갈 수 있는지 알려주는 프로그램을 작성하자.

입력
입력의 첫 번째 줄에 자연수 N(7 ≤ N ≤ 1,000) 이 주어진다.

두 번째 줄부터 N개의 각 줄에 0, 1, 2, 5 중 하나의 숫자가 공백으로 구분되어 N개씩 주어진다.

N개의 줄 중 R번째 줄의 C번째 숫자가 d라는 것은 다음과 같은 의미를 가진다:

d = 0: 책상 (R, C)는 빈 자리이다.
d = 1: 책상 (R, C)는 성규가 아닌 학생이 앉아있다.
d = 2: 책상 (R, C)는 성규가 앉아있다.
d = 5: 책상 (R, C)는 교수님이 앉아있다.
성규와 교수님은 겹치지 않으며, 각각 정확히 한 자리에만 앉아있다.

출력
첫 번째 줄에 성규가 교수님에게서 도망칠 수 있으면 1, 그렇지 못하면 0을 출력한다.

풀이 :
성규와 교수의 좌표를 따로 저장하고, 다른 학생들 좌표를 큐에 넣고 성규와 교수 사이의 값인 지 판단한다.
 */
/*
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main1 {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[][] cl = new int[N][N];
        XY pro = new XY(0,0);
        XY SG = new XY(0,0);
        Queue<XY> q = new LinkedList<>();
        for (int i = 0; i < N ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N ; j++) {
                cl[i][j] = Integer.parseInt(st.nextToken());
                if(cl[i][j] == 5){
                    pro = new XY(i ,j);
                }
                if(cl[i][j] == 2){
                    SG = new XY(i ,j);
                }
                if(cl[i][j] == 1){
                    q.offer(new XY(i, j));
                }
            }
        }
        if(Math.pow(Math.pow(pro.x - SG.x, 2) + Math.pow(pro.y - SG.y, 2), 0.5) < 5 ){
            System.out.println(0);
        }
        else{
            int cnt = 0;
            while(!q.isEmpty() && cnt < 3){
                XY other = q.poll();
                if(other.x >= Math.min(pro.x, SG.x) && other.x <= Math.max(pro.x, SG.x) && other.y >= Math.min(pro.y, SG.y) && other.y <= Math.max(pro.y, SG.y)){
                    cnt++;
                }
            }
            if(cnt >= 3){
                System.out.println(1);
            }
            else{
                System.out.println(0);
            }
        }
    }
}

class XY{
    int x;
    int y;
    public XY(int x, int y){
        this.x = x;
        this.y = y;
    }
}*/