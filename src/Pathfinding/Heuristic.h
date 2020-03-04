#pragma once

class Heuristic
{
public:
	virtual float getEstimate(int from, int to) = 0;
};

class ClusterH : public Heuristic
{
	int table[3][3] = { {0,7,5}, 
						{3,0,1}, 
						{4,1,0} };
	virtual float getEstimate(int from, int to)
	{
		int fCluster = getCluster(from);
		int tCluster = getCluster(to);

		return table[fCluster][tCluster];
	}

	int getCluster(int c)
	{
		int cluster = 0;
		switch (c)
		{
		case 3:
		case 8:
		case 1:
		case 2:
		case 10:
		case 11:
		case 9:
			cluster = 0;
			break;
		case 6:
		case 7:
		case 18:
		case 5:
		case 0:
		case 19:
			cluster = 1;
			break;
		case 17:
		case 16:
		case 15:
		case 20:
		case 4:
		case 13:
		case 14:
		case 12:
		default:
			cluster = 2;
			break;
		}
		return cluster;
	}
};

class ZeroH : public Heuristic
{
	virtual float getEstimate(int from, int to)
	{
		return 0.0f;
	}
};