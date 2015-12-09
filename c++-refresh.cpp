#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

class chemical
{
private:
	chemical(const chemical &chem);
public:
	int carbon;
	int hydrogen;
	vector<string> chemicalNames;
	chemical(int carb, int hyd):carbon(carb),hydrogen(hyd)
	{	
	}
	void addChemicalNames(string checmicalName)
	{
		chemicalNames.push_back(checmicalName);
	}
	void print()
	{
		cout<<"carbon "<<carbon<<" hydrogen "<<hydrogen<<" - ";
		for(vector<string>::iterator iter = chemicalNames.begin() ; iter!= chemicalNames.end() ; iter++)
		{
			cout<<(*iter)<<", ";
		}
		cout<<endl;
	}

};

chemical * returnChemical(int carbon, int hydrogen ,vector<chemical *> &chemicals)
{
	for(vector<chemical *>::iterator iter = chemicals.begin() ; iter!= chemicals.end() ; iter++)
	{
		if((*iter)->carbon == carbon && (*iter)->hydrogen == hydrogen )
			return (*iter);
	}
	return NULL;
}

int main(int argc ,char **argv)
{
	ifstream ifs("a.txt");
	if(!ifs.is_open())
		return -1;
	int carbon;
	int hydrogen;
	char dummy;
	char name[255];
	vector<chemical *> chemicals;
	while(ifs>>name>>dummy>>carbon>>dummy>>hydrogen)
	{
		chemical *existing = returnChemical(carbon,hydrogen,chemicals);
		if( existing == NULL)
		{
			chemical *c = new chemical(carbon,hydrogen);
			c->addChemicalNames(string(name));
			chemicals.push_back(c);
			c->print();
		}
		else
			existing->addChemicalNames(name);
	}
	for(vector<chemical *>::iterator iter = chemicals.begin() ; iter!= chemicals.end() ; iter++)
	{
		(*iter)->print();
	}
	ifs.close();
	return 0;	
}