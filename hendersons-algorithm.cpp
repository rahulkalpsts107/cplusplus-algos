bool flag[2] = {false};
int turn = 0;


void P0()
{
	while(true)
	{
		flag[0] = true;
		turn = 1;
		while(flag[1] && turn == 1);
		/*Critical section*/
		flag[0] = false;
	}
}

void P1()
{
	while(true)
	{
		flag[1] = true;
		turn = 0;
		while(flag[0] && turn == 0);
		/*Critical section*/
		flag[1] = false;
	}
}