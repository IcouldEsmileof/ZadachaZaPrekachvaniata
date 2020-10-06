#pragma once
#include <limits>
#include <ostream>
#include <vector>
#include "City.h"

inline int min_dist(std::vector<bool> used)
{
	// Initialize min value
	double min = std::numeric_limits<double>::max();
	int min_index = -1;

	for(int i = 0; i<used.size(); i++)
	{
		if(!used[i]&&cities[i].min_path<=min)
		{
			min = cities[i].min_path;
			min_index = i;
		}
	}

	return min_index;
}

inline void dijkstra(const int start, const int end)
{
	std::vector<bool> used;

	for(auto i = 0; i<cities.size(); i++) { used.push_back(false); }

	cities[end].min_path = 0;

	for(auto count = cities.begin(); count!=cities.end(); ++count)
	{
		const auto u = min_dist(used);

		used[u] = true;

		for(auto v = graph[u].begin(); v!=graph[u].end(); ++v)
		{
			if(!used[v->first]&&(
				   cities[u].min_path!=std::numeric_limits<double>::max())
			   &&cities[u].min_path+v->second<cities[v->first].min_path)
			{
				cities[v->first].min_path = cities[u].min_path+v->second;
				cities[v->first].next = u;
			}
		}
	}
}
