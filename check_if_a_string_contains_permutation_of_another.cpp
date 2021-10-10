/* Checks if a string s2 contains permutation of another string s1
 * 
 * So basically we take the length of s1 say k and compare substrings of length k
 * starting from the first index of string s2. like 1...k and 2..k+1 and so on untill n-k...n
 * 
 * Now if we need to comapare two strings and chcek if they are permutations of each other 
 * we can either 
 * 	1. sort them and just do a char by char sequential comparison
 *  2. count the characters and their frequencies and compare these
 * 
 * Both are O(N) operations,but in case of 2 if we do a preprocessing of the counting
 * in the subsequent steps we could simply do O(1) updates and O(1) comparisons of the substrings
 * 
 * say we shift from 1..k to 2..k+1 then we shall remove char[1] from hashtable and 
 * add char[k+1] to it, after this we shall go over the hash tables for the substring 
 * and s1, and comapre them. If they match, then the permutation exists.
 * 
 * */



#include <iostream>
using namespace std;

bool checkInclusion(string s1, string s2) {
	
	int freq_s1[26]={0}; // HashTable for s1
	int freq_s2[26]={0}; // HashTable for substrings of s2
	
	int n =s2.length();
	int k =s1.length();
	if(n<k) return 0;
	// Gerneration of HashTable for s1
	for(int i=0;i<k;i++)
	{
		freq_s1[s1[i]-97]++;    
	}
	
	// Gerneration of HashTable for s2[1..k]
	for(int i=0;i<k;i++)
	{
		freq_s2[s2[i]-97]++;    
	}
	
	bool flag = true;
	for(int i=0;i<26;i++)
	{
		if(freq_s1[i]!=freq_s2[i])
		{
			flag=false;
			break;
		}
	}
	if(flag) return 1;
	flag=true;
	
	
	for(int i=1;i<=n-k;i++)
	{
		// Updatation
		freq_s2[s2[i-1]-97]--;
		freq_s2[s2[i+k-1]-97]++;
		
		for(int j=0;j<26;j++)
		{
			if(freq_s1[j]!=freq_s2[j])
			{
				flag=false;
				break;
			}
		}
		if(flag) return 1;
		flag=true;
	}
	
	return 0;
}
    
    
int main()
{
	// s2 target string, s1 smaller string
	string s1,s2;
	cin>>s1>>s2;
	cout<<checkInclusion(s1,s2)<<endl;
	return 0;
}
