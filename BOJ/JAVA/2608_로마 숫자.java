import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String A =  br.readLine();
        String B =  br.readLine();

        int C = loToar(A) + loToar(B);

        System.out.println(C);
        System.out.println(arTolo(C));
    }
    public static int loToar(String lo){
        int ret = 0;
        for (int i = 0; i < lo.length() ; i++) {
            char now = lo.charAt(i);
            if(now == 'I'){
                if(i != lo.length() - 1 && (lo.charAt(i + 1) == 'V' || lo.charAt(i + 1) == 'X'))
                    ret -= 1;
                else
                    ret += 1;
            }
            else if(now == 'V'){
                ret += 5;
            }
            else if(now == 'X'){
                if(i != lo.length() - 1 && (lo.charAt(i + 1) == 'L' || lo.charAt(i + 1) == 'C'))
                    ret -= 10;
                else
                    ret += 10;
            }
            else if(now == 'L'){
                ret += 50;
            }
            else if(now == 'C'){
                if(i != lo.length() - 1 && (lo.charAt(i + 1) == 'D' || lo.charAt(i + 1) == 'M'))
                    ret -= 100;
                else
                    ret += 100;
            }
            else if(now == 'D'){
                ret += 500;
            }
            else if(now == 'M'){
                ret += 1000;
            }
        }
        return ret;
    }
    public static String arTolo(int ar){
        String ret = "";
        int i;

        for (i = 0; i < ar / 1000 ; i++) {
            ret += "M";
        }
        ar -= 1000 * i;
        if(ar >= 900){
            ret += "CM";
            ar -= 900;
        }
        else if(ar >= 500){
            ret += "D";
            ar -= 500;
        }
        else if(ar >= 400){
            ret += "CD";
            ar -= 400;
        }
            for (i = 0; i < ar / 100 ; i++) {
                ret += "C";
            }
            ar -= 100 * i;
        if(ar >= 90){
            ret += "XC";
            ar -= 90;
        }
        else if(ar >= 50){
            ret += "L";
            ar -= 50;
        }
        else if(ar >= 40){
            ret += "XL";
            ar -= 40;
        }
            for (i = 0; i < ar / 10 ; i++) {
                ret += "X";
            }
            ar -= 10 * i;
        if(ar >= 9){
            ret += "IX";
            ar -= 9;
        }
        else if(ar >= 5){
            ret += "V";
            ar -= 5;
        }
        else if(ar >= 4){
            ret += "IV";
            ar -= 4;
        }
            for (i = 0; i < ar ; i++) {
                ret += "I";
            }
        return ret;
    }
}