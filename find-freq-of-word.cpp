//write a code to find the frequency of a word in a book.  

#include <iostream>

using namespace std;

int findFreq(string &word ,string &sentence)
{
	int skip =0;
	int curr =0;
	int count =0;
	string collected;
	const char * book = sentence.c_str();
	while(book[curr] != '\0') //running time proprotion to O(length of sentence)
	{
		if(book[curr] == ' ')
		{
			if(skip != 1)
				if(word.compare(collected) == 0)
					count++;
			skip=0;
			collected="";
		}
		else
		{
			if(collected.size() >= word.size()) //This helps to avoid string size to be limited to word size to avoid too much concatenation.
				skip =1;
			else
				collected.append(1,book[curr]);
		}
		curr++;
	}
	if(collected.size() == word.size() && word.compare(collected) == 0) //We could have exited before hitting the white space condition
		count++;
	return count;
}

int main(int argc ,char **argv)
{
	string word = "the";
	string sentence = "in the ally was there the greatest";
	//string sentence = "the            then            the";
	int count = findFreq(word,sentence);
	cout<<"count = "<<count<<endl;
	return 0;
}