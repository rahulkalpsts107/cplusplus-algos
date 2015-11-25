 //"How do you find the number of unique values in an array? 
 //I.e. not how often each of the values occur, just how many different values there are."
 #include<iostream>
 #include<algorithm>
 #include<vector>
 
 using namespace std;
 
 class set
 {
 	vector<int> v;
 	int binSearch(int start , int end, int elem)
		{
			int ret = 0;
			if (start == end)
			{
				if (v[start] == elem)
					ret = 1;
			}
			else
			{
				int mid = (start + end)/2;
				if (elem<v[mid])
					ret = binSearch(start,mid,elem);
				else if (elem > v[mid])
					ret = binSearch(mid+1,end,elem);
				else
					ret = 1;
			}
			return ret;
		}
	public:	
		void insert(int elem)//no insert case o(logn) and insert case o(nlogn)
		{
			if(v.size()!=0)
			{
				if(!binSearch(0,v.size()-1,elem))//o(logn)
				{
					v.push_back(elem);
					sort(v.begin(),v.end());//o(nlogn)
				}
			}
			else if (v.size() ==0)
			{
				v.push_back(elem);
			}
			
		}
		
		int uniqueCount()
	 	{
	 		return v.size()	;
	 	}
 };
 
 
 int main(int argc,char **argv)
 {
 	set s;
 	s.insert(5);
 	s.insert(2);
 	s.insert(3);
 	s.insert(5);
 	s.insert(4);
 	s.insert(2);
 	s.insert(9);
 	s.insert(11);
 	s.insert(3);
 	s.insert(0);
 	s.insert(0);
 	s.insert(0);
 	s.insert(0);
 	cout<<s.uniqueCount()<<endl;
 }
