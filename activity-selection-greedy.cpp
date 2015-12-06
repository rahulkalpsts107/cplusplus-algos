#include<iostream>

using namespace std;

//n^2
void returnActivities(int *start ,int *finish ,int events, int *output, int *num)
{
	int i;
	int earliestEnding = 0;
	int iter = 1;
	output[iter-1] = 0;
	int numTimes = 1;
	while(iter < events)
	{
		int lowestBest = start[iter];
		for(i=iter;i<events;i++)//Instead of running n times here , we can sort the input based on finish times and search which results in O(nlogn) time
		{
			if((start[i] > start[earliestEnding] && start[i] >=finish[earliestEnding]) && start[i] <= lowestBest)
			{
				lowestBest = start[i];
				earliestEnding = i;
				output[numTimes] = earliestEnding;
				numTimes++;
			}
		}
		iter++;
	}
	*num = numTimes;
}

int main(int argc, char **argv)
{
	int start[]  = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
	int finish[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
	int size = 0;
	int events = sizeof(start)/sizeof(start[0]);
	int output[events];
	returnActivities(start,finish,events,output,&size);
	cout<<"returned activities "<<size<<endl;
	int i;
	for(i=0;i<size;i++)
	{
		cout<<"event "<<start[output[i]]<<" - "<<finish[output[i]]<<endl;
	}
	return 0;
}