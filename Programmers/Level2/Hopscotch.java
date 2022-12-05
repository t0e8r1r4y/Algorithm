package Programmers.Level2;

/**
 * 풀이 : https://terrys-tech-log.tistory.com/30
 */
public class Hopscotch {
    
    class Solution {
    
        private int findMax(int val, int idx, int[] land){
            int res = 0;
            for(int i = 0; i < land.length; i++){
                if(idx == i) continue;
                res = Math.max( res, val + land[i] );
            }
            
            return res;
        }
        
        int solution(int[][] land) {
            
            int answer = 0;
            int[][] arr = new int[land.length][land[0].length];
            
            for(int i = 0 ; i < land.length; i ++) {
                for(int j = 0 ; j < land[0].length; j++){
                    if(i == 0) arr[i][j] = land[i][j];
                    else {
                        arr[i][j] = findMax(land[i][j], j, arr[i-1]);
                        answer = Math.max(answer, arr[i][j]);
                    }
                }
            }
    
            return answer;
        }
    }
    

    public static void main(String[] args) {
        
    }
}
