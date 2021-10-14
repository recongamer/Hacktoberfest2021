/*
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
 
Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 
Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
*/


//Solution:
class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        int M = board.length, N = board[0].length;
        
		// Find all possible words that can be found in the matrix
        List<String> possibleWords = new ArrayList<>();
        int dp[] = new int[26];
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                dp[board[i][j] - 'a']++;
            }
        }
        
        for(String word: words) {
            boolean valid = true;
            for(char ch: word.toCharArray()) {
                if(dp[ch - 'a'] == 0) {
                    valid = false;
                    break;
                }
            }
            if(valid) possibleWords.add(word);
        }
        
        if(possibleWords.size() == 0)
            return new ArrayList<>();
        
        List<String> result = new ArrayList<>();
        for(String word: possibleWords) {
            for(int i = 0; i < M; i++) {
                boolean found = false;
                for(int j = 0; j < N; j++) {
                    if(word.charAt(0) == board[i][j]) {
                        if(dfs(board, word, i, j, 0)) { 
                            found = true;
                            result.add(word);
                            break;
                        }
                    }
                }
                if(found) break;
            }
        }
        
        return result;
    }
    
    boolean dfs(char[][] board, String word, int i, int j, int pos) {
        if(pos == word.length())
            return true;
        
        int M = board.length, N = board[0].length;
        if(i < 0 || i >= M || j < 0 || j >= N || board[i][j] == '*' || board[i][j] != word.charAt(pos))
            return false;
        
        char prevValue = board[i][j];
        board[i][j] = '*';
        
        boolean result = dfs(board, word, i + 1, j, pos + 1) ||
                            dfs(board, word, i - 1, j, pos + 1) ||
                                dfs(board, word, i, j + 1, pos + 1) ||
                                    dfs(board, word, i, j - 1, pos + 1);
        
        board[i][j] = prevValue;
        
        return result;
    }
}
