package Programmers.Level2;
import java.util.*;

/**
 * 풀이 : https://terrys-tech-log.tistory.com/32
 */
public class LargestNumber {
    class Solution {

        public String solution(int[] numbers) {
            String answer = "";
            String[] str = new String[numbers.length];
    
            for(int i = 0; i < numbers.length; i++){
                str[i] = String.valueOf(numbers[i]);
            }     
            
            Arrays.sort(str, new Comparator<String>() {
                @Override
                public int compare(String a, String b) {
                    return (b+a).compareTo(a+b);
                }
            });
            
            for(int i = 0; i < str.length; i++){
                System.out.println(str[i]);
            }
            
            if (str[0].equals("0")) return "0";
            
            for(String s: str) answer += s;
            
            return answer;
        }
    }
    

    public static void main(String[] args) {
        
    }
}
