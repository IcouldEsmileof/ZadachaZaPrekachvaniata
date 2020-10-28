#pragma once
#include <istream>
#include <ostream>
#include <string>

#include "City.h"

int add_city(std::string);

inline std::pair<int, int> parse_input(std::istream& in)
{
	std::string n;
	in>>n;
	for(auto i = 0; i<stoi(n); i++)
	{
		std::string c1, c2, ctime;
		double time;
		in>>c1>>c2>>ctime;
		const auto id1 = add_city(c1), id2 = add_city(c2);
		if(id1==-1||id2==-1) { throw std::exception("Cities could be added."); }
		if((time = stod(ctime))<0) { throw std::exception("Invalid input."); }
		graph[id2].push_back(std::make_pair(id1, time));
	}
	std::string start, end;
	in>>start>>end;
	return std::make_pair(city_to_id.at(start), city_to_id.at(end));
}

inline int add_city(std::string city_name)
{
	int id;
	try { id = city_to_id.at(city_name); }
	catch(std::out_of_range)
	{
		id = static_cast<int>(cities.size());
		city_to_id.insert(std::make_pair(city_name, id));
		cities.push_back(city(city_name));
		graph.push_back(std::vector<std::pair<int, double> >());
	}
	return id;
}

/*
27
1 2 2
1 3 4
1 4 1
2 5 3
2 6 2
2 7 4
3 5 2
3 6 8
3 7 1
4 5 7
4 6 4
4 7 6
5 8 2
5 9 4
6 8 3
6 9 7
7 8 7
7 9 5
8 10 6
8 11 5
8 12 9
9 10 5
9 11 1
9 12 7
10 13 2
11 13 4
12 13 2
1 13
*/
