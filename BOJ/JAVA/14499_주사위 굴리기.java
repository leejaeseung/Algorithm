/*
    동,서,남,북 별로 움직일 때마다 주사위의 전개도 값이 일정하게 변하는 것을 이용하여 풀이
 */

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int x,y;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[][] die={{0,0,0}
                ,{0,0,0}
                ,{0,0,0}
                ,{0,0,0}};

        String s=br.readLine();
        StringTokenizer st=new StringTokenizer(s);
        int ver=Integer.parseInt(st.nextToken());
        int hor=Integer.parseInt(st.nextToken());
        int[][] map=new int[ver][hor];
        y=Integer.parseInt(st.nextToken());
        x=Integer.parseInt(st.nextToken());
        int N=Integer.parseInt(st.nextToken());

        for (int i = 0; i <ver ; i++) {
            s=br.readLine();
            st=new StringTokenizer(s);
            for (int j = 0; j <hor ; j++) {
                map[i][j]=Integer.parseInt(st.nextToken());
            }
        }
        Dicegame dg=new Dicegame(map,die,x,y,ver,hor);
        st=new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            dg.command(Integer.parseInt(st.nextToken()));
        }
    }
}

class Dicegame{

    private int map[][];
    private int die[][];
    private int x,y;
    private int ver,hor;
    public Dicegame(int[][] map,int[][] die,int x,int y,int ver,int hor){
        this.map=map;
        this.die=die;
        this.x=x;
        this.y=y;
        this.ver=ver;
        this.hor=hor;
    }
    public int command(int dir){
        int ret=1;
        switch(dir){
            case 1 :
                ret=right();
                break;
            case 2:
                ret=left();
                break;
            case 3:
                ret=up();
                break;
            case 4:
                ret=down();
                break;
            default:
        }
        if(ret==-1)
            return -1;
        else {
            System.out.println(this.die[1][1]);
            return 1;
        }
    }
    public int right(){
        if(x+1!=hor) {
            x++;
            change_die(die[0][1],die[3][1],die[1][0],die[1][1],die[2][1],die[1][2]);
            if(map[y][x]==0){                               //바닥 칸이 0이면 -> 주사위 바닥이 복사 바닥: die[3][1]
                map[y][x]=die[3][1];
            }
            else{                                           //아니면 바닥 값이 주사위로 복사,바닥은 0
                die[3][1]=map[y][x];
                map[y][x]=0;
            }
            return 1;
        }
        else
            return -1;
    }
    public int left(){
        if(x!=0) {
            x--;
            change_die(die[0][1],die[1][1],die[1][2],die[3][1],die[2][1],die[1][0]);
            if(map[y][x]==0){                               //바닥 칸이 0이면 -> 주사위 바닥이 복사 바닥: die[3][1]
                map[y][x]=die[3][1];
            }
            else{                                           //아니면 바닥 값이 주사위로 복사,바닥은 0
                die[3][1]=map[y][x];
                map[y][x]=0;
            }
            return 1;
        }
        else
            return -1;
    }
    public int up(){
        if(y!=0) {
            y--;
            change_die(die[1][1],die[1][0],die[2][1],die[1][2],die[3][1],die[0][1]);
            if(map[y][x]==0){                               //바닥 칸이 0이면 -> 주사위 바닥이 복사 바닥: die[3][1]
                map[y][x]=die[3][1];
            }
            else{                                           //아니면 바닥 값이 주사위로 복사,바닥은 0
                die[3][1]=map[y][x];
                map[y][x]=0;
            }
            return 1;
        }
        else
            return -1;
    }
    public int down(){
        if(y+1!=ver) {
            y++;
            change_die(die[3][1],die[1][0],die[0][1],die[1][2],die[1][1],die[2][1]);
            if(map[y][x]==0){                               //바닥 칸이 0이면 -> 주사위 바닥이 복사 바닥: die[3][1]
                map[y][x]=die[3][1];
            }
            else{                                           //아니면 바닥 값이 주사위로 복사,바닥은 0
                die[3][1]=map[y][x];
                map[y][x]=0;
            }
            return 1;
        }
        else
            return -1;
    }
    public void change_die(int a,int b,int c,int d,int e,int f){
        this.die[0][1]=a;
        this.die[1][0]=b;
        this.die[1][1]=c;
        this.die[1][2]=d;
        this.die[2][1]=e;
        this.die[3][1]=f;
    }
}
/*
        die={{0,a,0}
            ,{b,c,d}
            ,{0,e,0}
            ,{0,f,0}}
 */