class PriorityQueue
{
	public:
		class Node()
		{
			public:
				int v;
				int index;
				int val;
				Node(int data, int idx, int wt):v(data),index(idx),val(wt)
				{
					curr=-1;
				}
		};
		int curr;
		int size;
		Node * nodes;
		PriorityQueue(int size)
		{
			this->size = size;
			if(size)
				nodes = new Node[size];
			else 
				nodes = NULL;
		}

		int insert(int data ,int wt)
		{
			if(curr<size)
			{
				Node *temp = new Node(data,++curr,wt);
				nodes[curr] =temp;
				bubbleUp(curr);
				return curr;
			}
			else
			{
				cout<<"overflow"<<endl;
				return -1;
			}
		}

		int decreasePriority(int n ,int wt)
		{
			Node *tmp = nodes[n];
			tmp->val = tmp;
			return bubbleUp(n);
		}

		int extractMin()
		{
			if(size)
			{
				int n = nodes[0].data;
				swap(nodes[0] ,nodes[size-1]);
				size--;
				bubbleDown(0);
			}
			else
			{
				if(nodes != NULL)
					delete(nodes);
				return -1;
			}
		}

		int getMin()
		{
			if(size)
				return nodes[0];
			else
				return -1;
		}
	private:
		void inswap(int &a ,int &b)
		{
			a = a+b;
			b = a-b;
			a = a-b;
		}

		void swap(Node *A ,Node *B)
		{
			inswap(A->v ,B->v);
			inswap(A->val ,B->val);
			inswap(A->index ,B->index);
		}
		int bubbleUp(int idx)
		{
			int par = parent(idx);
			while(par >=0)
			{
				if(nodes[par].data > nodess[idx].data)
				{
					swap(nodes[par] ,nodes[idx]);
					idx = par;
				}
				else
				{
					break;
				}
			}
			return idx;
		}

		void bubbleDown(int idx)
		{
			int lt = left(idx);
			int rt = right(idx);
			while(1)
			{
				int swpIdx =-1;
				if(lt<size)
				{
					if(nodes[lt].val <= nodes[idx].val)
					{
						swpIdx =lt;
					}
				}
				if(rt<size)
				{
					if(nodes[rt].val > nodes[idx].val)
					{
						swpIdx =rt;
					}
				}
				if(swpIdx == -1)
					break;
				else
				{
					swap(nodes[swpIdx],nodes[idx]);
					idx = swpIdx;
				}
			}
		}

		int left(int idx)
		{
			return (2*i)+1;
		}

		int right(int idx)
		{
			return (2*i)+2;
		}

		int parent(int idx)
		{
			return ceil((float)idx/2.0)) - 1.0;
		}
};