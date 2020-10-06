#pragma once
#include <limits>
#include <map>
#include <string>
#include <vector>

class city;

//data
static std::map<std::string, int> city_to_id;
static std::vector<city> cities;
static std::vector<std::vector<std::pair<int, double> > > graph;
//

class city
{
public:
	std::string name;
	int next;
	double min_path;

	explicit city(const std::string city_name): name(city_name)
	{
		next = -1;
		min_path = std::numeric_limits<double>::max();
	}
};
