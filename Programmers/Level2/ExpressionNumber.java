package Programmers.Level2;

/**
 * ExpressionNumber
 * 풀이 : https://terrys-tech-log.tistory.com/28
 */
public class ExpressionNumber {

    // 아래코드만 프로그래머스 붙여 넣기
    class Solution {
        public int solution(int n) {
            int answer = 0;
            
            for(int i = 1; i <= n; i++) {
                int temp = i;
                
                if( i == n ) answer++;
                
                for(int j = i+1; j <= n; j++){
                    temp += j;
                    if( temp == n ) answer ++;
                    else if(temp > n) break;
                }
            }
            return answer;
        }
    }

    public static void main(String[] args) {
        
    }
}