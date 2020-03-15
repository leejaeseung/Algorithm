/*
     풀이 :
     지도의 변 쪽 부분에서 null 에러를 방지하기 위해 가로와 세로를 +2만큼 확장해 map[][]배열을 선언한다.
     map을 한칸 한칸 탐색하며 1이면 근처에 섬이 있는지 nearLand()로 재귀하여 끝까지(섬의 끝자락까지) 탐색하고 탐색이 된 섬은 2로 갱신한다.
     map을 탐색할 때 2이면 이미 탐색된 섬이므로 탐색하지 않는다. 0일때는 바다이므로 탐색하지 않는다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int[][] map;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int w,h;
        while(true){
            String s=br.readLine();
            StringTokenizer st=new StringTokenizer(s);
            w=Integer.parseInt(st.nextToken());
            h=Integer.parseInt(st.nextToken());
            if(w==0&&h==0)
                break;
            map=new int[h+2][w+2];
            for (int i = 1; i <=h ; i++) {
                s=br.readLine();
                st=new StringTokenizer(s);
                for (int j = 1; j <=w ; j++) {
                    map[i][j]=Integer.parseInt(st.nextToken());
                }
            }
            bw.write(find(h,w)+"\n");
        }
        bw.flush();
        bw.close();
    }
    public static int find(int h,int w){
        int count=0;

        for (int i = 1; i <=h ; i++) {
            for (int j = 1; j <=w ; j++) {
                count+=nearLand(i,j);
            }
        }
        return count;
    }
    public static int nearLand(int i,int j){
        if(map[i][j]==1){
            map[i][j]=2;
        }
        else{
            return 0;
        }
        for(int k=-1;k<2;k++) {
            for (int m = -1; m < 2; m++) {
                nearLand(i+k,j+m);
            }
        }
        return 1;
    }
}