#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Exponent
 {
 public:
 	Exponent(int val,int pow):coeff(val),power(pow){}
 	/* data */
 	int coeff;
 	int power;
 }; 


void polyDerivative(vector<Exponent *> * input,vector<Exponent *> * output)
{
	unordered_map<int,int> values;
	for(vector<Exponent *>::iterator iter = input->begin(); iter != input->end();iter++)
	{
		if((*iter)->power == 0)
		{
			if(values.find((*iter)->power) == values.end())
				values[(*iter)->power] = (*iter)->coeff;
			else
				values[(*iter)->power] += (*iter)->coeff;
		}
		else
		{
			int power = (*iter)->power-1;
 			if(values.find(power) == values.end())
				values[power] = (*iter)->coeff * (*iter)->power;
			else
				values[power] += (*iter)->coeff * (*iter)->power;
		}
	}
	for(unordered_map<int,int>::iterator iter = values.begin(); iter != values.end(); iter++ )
	{
		output->push_back(new Exponent((*iter).second,(*iter).first));
	}
}

int main(int argc ,char **argv)
{
	vector<Exponent *> input;
	Exponent a (5,0);
	Exponent b (2,1);
	Exponent c (3,2);
	Exponent d (6,4);
	input.push_back(&a);
	input.push_back(&b);
	input.push_back(&c);
	input.push_back(&d); 
	vector<Exponent *> output;
	polyDerivative(&input,&output);
	for(vector<Exponent *>::iterator iter = output.begin(); iter != output.end(); iter++ )
	{
		cout<<"power "<<(*iter)->power<<" val "<<(*iter)->coeff<<endl;
	}
	return 0;
}