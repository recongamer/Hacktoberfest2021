/*
 * Boyer-Moore Voting Algorithm:
 * 
 * This Algorithm was originally employed to find the candidate with max no of votes.
 * It also assumed that such a candidate existed.
 * Although it can be modified to cases where such a candidate does not exist.
 * For the voting purpose,this algorithm is used to find majority element in an array
 * whose elements represent the vote to a certain candidate.
 * 
 * 
 * Say an array has n elements and M is the majority element.
 * Then count(M) > n/2 , where count() denotes no of occurences.
 * Now if we see the algorithm, we are assuming one element to be the majority element
 * and subtracting the count of other elements from the count of the element untill it turns 0
 * then we are taking the next element as candidate/majority and moving forward.
 * Now, f = count(M) -  count(other elements) > 0
 * hence if we take some occurences out of count(M) to neutralize count(other), there would
 * be always some left, which will eventually make M the remaining candidate. 
 * */

#include <iostream>
using namespace std;

int res;
bool flag;

void BoyerMoore(int votes[],int n)
{
	int candidate=votes[0];
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(count==0)
			candidate=votes[i];
			
		if(votes[i]==candidate)
			count++;
		else
			count--;
	}
	// If there was a guarentee that a majority element existed
	// Then there would be no need for the next lines and we could
	// return the candidate 
	
	int maj_count=0;
	for(int i=0;i<n;i++)
	{
		if(votes[i]==candidate)
			maj_count++;
	}
	
	if(maj_count>n/2)
	{
		flag=0;
		res=candidate;
	}
	else
		flag=1;
	
}

int main()
{
	int n;
	cin>>n;
	int votes[n];
	for(int i=0;i<n;i++)
	{
		cin>>votes[i];
	}
	
	BoyerMoore(votes,n);
	if(flag==1)
		cout<<"No Majority Element"<<endl;
	else
		cout<<"Majority Element: "<<res<<endl;
}
