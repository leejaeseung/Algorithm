/*
    풀이 :
    DFS연습 문제
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int[] m_ver = {0, 0, 1, -1};
    public static int[] m_hor = {1, -1, 0, 0};
    public static int ver,hor;
    public static int max=0;
    public static char[][] map;
    public static boolean[] alpha=new boolean[26];
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st=new StringTokenizer(br.readLine());
        ver=Integer.parseInt(st.nextToken());
        hor=Integer.parseInt(st.nextToken());
        map=new char[ver][hor];

        for (int i = 0; i <ver ; i++) {
            String s=br.readLine();
            for (int j = 0; j <hor ; j++) {
                map[i][j]=s.charAt(j);
            }
        }
        DFS(0,0,1);
        bw.write(Integer.toString(max));
        bw.flush();
        bw.close();
    }
    public static void DFS(int i,int j,int sum){
        alpha[map[i][j]-'A']=true;

        boolean flag=false;
        for (int k = 0; k <4 ; k++) {
            int pos_i=i+m_ver[k];
            int pos_j=j+m_hor[k];

            if(pos_i<0||pos_j<0||pos_i>ver-1||pos_j>hor-1)
                continue;
            if(alpha[map[pos_i][pos_j]-'A']==false){
                flag=true;
                DFS(pos_i,pos_j,sum+1);
            }
        }
        if(!flag){
            max=Math.max(sum,max);
        }
        alpha[map[i][j]-'A']=false;
    }
}