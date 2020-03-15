/*
    RGB거리 : bottom up 문제
    처음에 재귀 함수를 이용하여 풀이했으나 시간 복잡도가 O(2^N)이 되어 시간 초과됨
    이차원 배열을 이용해 최소값을 갱신해가며 풀이함
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int MAX=0x7FFFFFFF;
    public static int min=MAX;
    public static int[][] home;
    public static int sum=0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N=Integer.parseInt(br.readLine());
        home=new int[N][3];

        for (int i = 0; i <N ; i++) {
            String s = br.readLine();
            StringTokenizer st = new StringTokenizer(s);
            for (int j = 0; j <3 ; j++) {
                home[i][j]=Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 1; i <N ; i++) {
            for (int j = 0; j <3 ; j++) {
                home[i][j]+=Math.min(home[i-1][(j+1)%3],home[i-1][(j+2)%3]);
            }
        }
        int temp=Math.min(home[N-1][0],home[N-1][1]);
        temp=Math.min(temp,home[N-1][2]);
        //find(0,-1,0);
        bw.write(Integer.toString(temp));
        bw.flush();
        bw.close();
    }
    public static int find(int home_index,int Prevcolor,int sum){
        if(home_index==home.length){
            if(min>sum){
                min=sum;
            }
            return 1;
        }
        if(min<=sum){
            return 1;
        }
        if(Prevcolor==0){
            find(home_index+1,1,sum+home[home_index][1]);
            find(home_index+1,2,sum+home[home_index][2]);
        }else if(Prevcolor==1){
            find(home_index+1,0,sum+home[home_index][0]);
            find(home_index+1,2,sum+home[home_index][2]);
        }else if(Prevcolor==2){
            find(home_index+1,0,sum+home[home_index][0]);
            find(home_index+1,1,sum+home[home_index][1]);
        }
        else{
            find(home_index+1,0,sum+home[home_index][0]);
            find(home_index+1,1,sum+home[home_index][1]);
            find(home_index+1,2,sum+home[home_index][2]);
        }
        return 1;
    }
    public static int min(int R,int G,int B){
        int temp=Math.min(R,G);
        temp=Math.min(temp,B);
        sum+=temp;
        if(temp==R)
            return 0;
        else if(temp==G)
            return 1;
        else
            return 2;
    }
}