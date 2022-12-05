package Programmers.Level2;

/**
 * 풀이 : https://terrys-tech-log.tistory.com/29
 */
public class LargestSquare {
    
    class Solution
    {
        public int solution(int [][]board)
        {
            int answer = 0;
            int [][]arr = new int[board.length+1][board[0].length+1];
            
            for(int i = 1; i <= board.length; i++) {
                for(int j = 1; j <= board[0].length; j++){
                    if(board[i-1][j-1] != 0) {
                        int min = Math.min( Math.min(arr[i-1][j], arr[i][j-1]), arr[i-1][j-1]  );
                        arr[i][j] = min+1;
                        answer = Math.max(answer, min + 1);
                    }
                }
            }
            answer *= answer;
    
            return answer;
        }
    }
    

    public static void main(String[] args) {
        
    }
}
