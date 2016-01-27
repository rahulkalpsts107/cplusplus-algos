#include<iostream>
#include<algorithm>
using namespace std;

class Job
{
	int start;
	int end;
	int weight;
public:
	Job(int start ,int end ,int weight)
	{
		this->start = start;
		this->end = end;
		this->weight = weight;
	}
};

bool sortFunction(Job &s1, Job &s2)
{
    return (s1.end < s2.end);
}

int main(int argc, char **argv)
{
	Job j1(1,2,50);
	Job j2(3,5,20);
	Job j3(6,19,100);
	Job j4(2,100,200);
	Job jobs[] = {j1,j2,j3,j4};
	sort();
	int size = 0;
	int events = sizeof(jobs)/sizeof(jobs[0]);
	int output[events];
	
	cout<<"returned activities "<<size<<endl;
	int i;
	for(i=0;i<size;i++)
	{
		cout<<"event "<<start[output[i]]<<" - "<<finish[output[i]]<<endl;
	}
	return 0;
}