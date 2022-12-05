package Programmers.Level2;

/**
 * 풀이 : https://terrys-tech-log.tistory.com/33
 */
public class Tornerment {
    class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = 0;

        while(true){
            a = (a/2) + (a%2);
            b = (b/2) + (b%2);
            answer++;
            
            if(a == b) break;
            
            System.out.println( a + " " + b);
            // 테스트 케이스 7, 9, 27, 33이 틀리네.
        }

        return answer;
    }
}
    public static void main(String[] args) {
        
    }
}
