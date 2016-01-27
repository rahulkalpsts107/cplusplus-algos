//Sort the activities by ending times and assume the ending times are 1, . . . , n. Now find the best solution ending at the time i, for i = 1, . . . , n. 
//Use this information to find the best solution overall.
//Using dynamic problem

#include<iostream>
#include<algorithm>
using namespace std;

class Job
{
public:
	int start;
	int end;
	int weight;
	Job(int start ,int end ,int weight)
	{
		this->start = start;
		this->end = end;
		this->weight = weight;
	}
};

int getLatestNonConflictingJob(Job *jobs, int curr)
{
	int idx =-1;
	for(int i=curr; i>0 ; i--)
	{
		if(jobs[i-1].end > jobs[i-1].start)
		{
			idx = i-1;
			break;
		}
	}
	return idx;
}

int returnBestJobs(Job *jobs , Job *output , int numJobs , int* maxJobs)
{
	if(numJobs == 1)
	{
		output[(*maxJobs)++] = jobs[0];
		return jobs[0].weight;
	}
	else
	{
		int nonConflictingJob = getLatestNonConflictingJob(jobs,numJobs-1);
		int includingProfit = jobs[numJobs].weight;
		if(nonConflictingJob != -1)
			includingProfit +=returnBestJobs(jobs,output,nonConflictingJob+1,maxJobs);

		int excludingProfit = returnBestJobs(jobs,output,numJobs-1,maxJobs);
		return max(includingProfit,excludingProfit);
	}
}

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
	int events = sizeof(jobs)/sizeof(jobs[0]);
	sort(jobs,jobs+events,sortFunction);
	int size = 0;
	returnBestJobs(jobs,output,events,&size);
	cout<<"returned activities "<<size<<endl;
	int i;
	for(i=0;i<size;i++)
	{
		//cout<<"event "<<start[output[i]]<<" - "<<finish[output[i]]<<endl;
	}
	return 0;
}