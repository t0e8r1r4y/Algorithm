package Programmers.Level2;

/**
 * 풀이 : https://terrys-tech-log.tistory.com/31
 */
public class VowelDictionary {
    
    class Solution {
    
        public int solution(String word) {
            int answer = 0;
            String s = "AEIOU";
            int[] m = {781, 156,31,6,1};
    
            for(int i = 0 ; i  < word.length(); i++){
                answer += ( m[i] * s.indexOf(word.charAt(i)) ) + 1;
            }
            
            return answer;
        }
    }

    public static void main(String[] args) {
        
    }
}
