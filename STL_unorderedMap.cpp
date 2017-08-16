// unordered_map::insert
#include <iostream>
#include <string>
#include <unordered_map>

typedef std::pair<std::string, double> recipe_pair;

int mainnn()
{
	std::unordered_map<std::string, double>
		myrecipe,
		mypantry = { { "milk", 2.0 }, { "flour", 1.5 } };

	recipe_pair myshopping("baking powder", 0.3);

	myrecipe.insert(myshopping);                        // copy insertion
	myrecipe.insert(recipe_pair("eggs", 6.0)); // move insertion
	myrecipe.insert(mypantry.begin(), mypantry.end());  // range insertion
	myrecipe.insert({ { "sugar", 0.8 }, { "salt", 0.1 } });    // initializer list insertion
	myrecipe.insert({ "sugar", 0.6 });
	myrecipe["pepper"] = 3.0;
	myrecipe["cheese"]++;
	if (myrecipe["coco"])
		std::cout << "exists"; 
	else
	{
		myrecipe["coco"];
	}
		


	std::cout << "myrecipe contains:" << std::endl;
	for (auto& x : myrecipe)
		std::cout << x.first << ": " << x.second << std::endl;

	std::cout << std::endl;

	auto egg_pair = myrecipe.find("eggs");
	double egg_amount = egg_pair->second;
	return 0;
}