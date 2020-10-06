#pragma once
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>


#include "City.h"
#include "dijkstra.h"
#include "input_parser.h"

void print_result(const int start, const int end)
{
	if(start==end)
	{
		std::cout<<"Start city and end city are the same.";
		return;
	}
	int cur_id=start;
	std::stringstream output;
	for(; true;)
	{
		if(cities[cur_id].next==-1)
		{
			if(cur_id==end)
			{
				output<<"->"<<cities[cur_id].name<<std::endl;
				output<<"It took "<<cities[start].min_path<<"h"<<std::endl;
			}
			else
			{
				output.clear();
				output<<"No path between "
					<<cities[start].name<<" and "
					<<cities[end].name<<std::endl;
			}
			break;
		}
		output<<"->"<<cities[cur_id].name<<std::endl;
		cur_id = cities[cur_id].next;
	}
	std::cout<<output.str();
}


int main()
{
	std::ifstream in("input.txt",std::ifstream::in);
	const auto start_end = parse_input(in);
	dijkstra(start_end.first, start_end.second);
	print_result(start_end.first, start_end.second);
	return 0;
}
