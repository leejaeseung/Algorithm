/*
<그림 1>과 같이 정사각형 모양을 한 여섯 종류의 색종이가 있다. ①번 색종이는 한 변의 길이가 1cm이고, 차례대로 그 길이가 1cm씩 커져, ⑥번 색종이의 한 변의 길이는 6cm가 된다.



주어진 색종이를 <그림 2>와 같이 가로, 세로의 길이가 각각 6cm인 판 위에 붙이려고 한다. 색종이를 붙일 때는 색종이가 판의 경계 밖으로 삐져 나가서는 안되며, 색종이가 서로 겹쳐서도 안 된다. 또한 하나의 색종이는 하나의 판에만 붙여야 한다.



각 종류별로 색종이의 장수가 주어질 때, 그 색종이를 모두 붙이기 위해서 위와 같은 판이 최소 몇 개가 필요한지 구하는 프로그램을 작성하시오.

풀이 :
6x6은 1개만 가능
5x5는 1개만 가능(1x1짜리 11개를 채워줌)
4x4는 1개만 가능(2x2짜리 5개 채워보고 남으면 1x1짜리 채움)
3x3은 4개까지 가능(남는 곳에 2x2짜리 5,3,1 개 채워보고 남으면 1x1짜리 채움)
2x2는 9개까지 가능(남는 자리에 1x1짜리 채움)
1x1은 36개까지 가능
 */

import java.io.*;
public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] paper = new int[7];
        int cnt = 0;

        for (int i = 1; i <= 6 ; i++) {
            paper[i] = Integer.parseInt(br.readLine());
        }

        cnt += paper[6];
        cnt += paper[5]; paper[1] -= paper[5] * 11;
        cnt += paper[4];
        if(paper[2] >= paper[4] * 5){
            paper[2] -= paper[4] * 5;
        }
        else{
            paper[1] -= ((paper[4] * 5) - paper[2]) * 4;
            paper[2] = 0;
        }
        cnt += (paper[3] / 4) + 1;
        paper[3] %= 4;
        if(paper[3] == 0){
            cnt--;
        }
        else if(paper[3] == 1){
            paper[2] -= 5;

            if(paper[2] <= 0){
                paper[1] -= 27 - ((paper[2] + 5) * 4);
            }
            else{
                paper[1] -= 7;
            }
        }
        else if(paper[3] == 2){
            paper[2] -= 3;
            if(paper[2] <= 0){
                paper[1] -= 18 - ((paper[2] + 3) * 4);
            }
            else{
                paper[1] -= 6;
            }
        }
        else if(paper[3] == 3){
            paper[2] -= 1;
            if(paper[2] <= 0){
                paper[1] -= 9 - ((paper[2] + 1) * 4);
            }
            else{
                paper[1] -= 5;
            }
        }
        if(paper[2] > 0){
            cnt += (paper[2] / 9) + 1;
            if(paper[2] % 9 == 0)
                cnt--;
            else
                paper[1] -= 36 - ((paper[2] % 9) * 4);
        }
        if(paper[1] > 0){
            cnt += (paper[1] / 36) + 1;
            if(paper[1] % 36 == 0)
                cnt--;
        }
        bw.write(Integer.toString(cnt));
        bw.flush();
        bw.close();
    }
}