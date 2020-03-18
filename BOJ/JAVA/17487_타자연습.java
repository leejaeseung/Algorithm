import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static int bothcnt=0;
    public static int left=0;
    public static int right=0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        String s=br.readLine();

        for (int i = 0; i <s.length() ; i++) {
            leftORright(s.charAt(i));
        }
        balance();
        System.out.println(left+" "+ right);
    }
    public static void leftORright(char c){
        if(c>='A'&&c<='Z'){
            bothcnt++;
            leftORright((char)(c-'A'+'a'));
        }
        else if(c==32){
            bothcnt++;
        }
        else if(c=='q'||c=='w'||c=='e'||c=='r'||c=='t'||c=='y'||c=='a'||c=='s'||c=='d'||c=='f'||c=='g'||c=='z'||c=='x'||c=='c'||c=='v'||c=='b'){
            left++;
        }
        else{
            right++;
        }
    }
    public static void balance(){
        while(bothcnt-- >0){
            if(Math.abs(left-right)==0){
                left++;
            }
            else if(left<right){
                left++;
            }
            else{
                right++;
            }
        }
    }
}
