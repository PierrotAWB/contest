//
//  main.cpp
//  CCC14S3
//
//  Created by Andrew Wang on 2017-07-19.
//  Copyright © 2017 Andrew Wang. All rights reserved.
//

#include <iostream>
#include <stack> 
using namespace std;

int main(int argc, const char * argv[])
{
	cin.sync_with_stdio();
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		
		stack<int> mountainTop, branch, lake;
		
		for (int j = 0; j < N; j++) // read input
		{
			int k ;
			cin >> k;
			mountainTop.push(k);
		}
		
		lake.push(0);
		branch.push(0);
		
		while (!mountainTop.empty() || branch.top() == lake.top() + 1)
		{
			// if direct route from mount to lake allowed, take it.
			if(!mountainTop.empty())
			{
				if (mountainTop.top() == lake.top() + 1)
				{
					lake.push(mountainTop.top());
					mountainTop.pop();
					continue;
				}
			}
			
			// if branch to lake allowed, take it.
			if (branch.top() == lake.top() + 1)
			{
				lake.push(branch.top());
				branch.pop();
			}
			// else push from mountain to branch
			else
			{
				if (!mountainTop.empty())
				{
					branch.push(mountainTop.top());
					mountainTop.pop();
				}
				else
				{
					break;
				}
			}
		}
		
		// output status
		if (lake.size() == N + 1) // everything transferred into lake INCLUDING THE INITIAL 0
		{
			cout << "Y\n";
		}
		else
		{
			cout << "N\n";
		}
	}
	
	return 0;
}
