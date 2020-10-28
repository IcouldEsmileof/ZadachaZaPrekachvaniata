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
	int cur_id = start;
	std::stringstream output;
	if(cities[cur_id].next!=-1)
	{
		output<<"Start at: "<<cities[cur_id].name<<std::endl;
		cur_id = cities[cur_id].next;
	}
	for(; true;)
	{
		if(cities[cur_id].next==-1)
		{
			if(cur_id==end)
			{
				output<<"End at:   "<<cities[cur_id].name<<std::endl;
				output<<"It took "<<cities[start].min_path<<"h."<<std::endl;
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
		output<<"       -> "<<cities[cur_id].name<<std::endl;
		cur_id = cities[cur_id].next;
	}
	std::cout<<output.str();
}


int main()
{
	const auto n = 4;
	std::string files[n] = {
		"input_1.txt",
		"input_2.txt",
		"input_3.txt",
		"input_4_no_path.txt"
		};
	auto cur = files[0];
	try
	{
		std::cout<<"Choose one of the files:"<<std::endl;
		for(auto i = 0; i<n; i++)
		{
			std::cout<<i+1<<":\t"<<files[i]<<std::endl;
		}
		std::cout<<std::endl;
		std::string a;
		std::cin>>a;
		if(stoi(a)>0&&stoi(a)<n+1) { cur = files[stoi(a)-1]; }
		else { throw std::exception(); }
	}
	catch(std::exception)
	{
		std::cout<<"Invalid input\nUsing default - input_1.txt."<<std::endl;
	}
	std::ifstream in(cur, std::ifstream::in);
	const auto start_end = parse_input(in);
	dijkstra(start_end.first, start_end.second);
	print_result(start_end.first, start_end.second);
	return 0;
}
