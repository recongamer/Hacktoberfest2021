import java.io.*;
import java.util.*;

public class implementing_a_trie {

	public static class Trie {

		public class Node {
			Node[] child;
			boolean isEnd;

			Node() {
				child = new Node[26];
			}
		}

		final private Node root;

		/** Initialize your data structure here. */
		public Trie() {
			root = new Node();
		}

		/** Inserts a word into the trie. */
		public void insert(String word) {

			Node curr = root;
			for(int i = 0; i < word.length(); i++) {
				char ch = word.charAt(i);
				if(curr.child[ch-'a'] == null) {
					curr.child[ch-'a'] = new Node();
				}
				curr = curr.child[ch - 'a'];
			}
			curr.isEnd = true;

		}

		/** Returns if the word is in the trie. */
		public boolean search(String word) {

			Node curr = root;
			for(int  i = 0; i < word.length(); i++) {
				char ch = word.charAt(i);
				if(curr.child[ch -'a'] == null) {
					return false;
				}
				curr = curr.child[ch - 'a'];
			}
			return curr.isEnd;
		}

		/**
		 * Returns if there is any word in the trie that starts with the given prefix.
		 */
		public boolean startsWith(String prefix) {
			Node curr = root;
			for(int  i = 0; i < prefix.length(); i++) {
				char ch = prefix.charAt(i);
				if(curr.child[ch -'a'] == null) {
					return false;
				}
				curr = curr.child[ch - 'a'];
			}
			return true;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

		Trie obj = new Trie();

		while (read.ready()) {
			String inp[] = read.readLine().split(" ");

			if (inp[0].equals("insert")) {
				obj.insert(inp[1]);
			} else if (inp[0].equals("search")) {
				System.out.println(obj.search(inp[1]));
			} else if (inp[0].equals("startsWith")) {
				System.out.println(obj.startsWith(inp[1]));
			}
		}

	}
}
