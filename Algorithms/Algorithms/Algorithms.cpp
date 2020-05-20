#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cctype>
#include <string>
#include <numeric>

using namespace std;

bool test(int i)
{
	return true;
}
int main()
{
	vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> x1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	//----------min/max Element
	int maxElementIndex = std::max_element(v.begin(), v.end()) - v.begin();
	int maxElement = *std::max_element(v.begin(), v.end());

	int minElementIndex = std::min_element(v.begin(), v.end()) - v.begin();
	int minElement = *std::min_element(v.begin(), v.end());
	vector<int> x2;
	//---------------transform
	transform(x1.begin(), x1.end(), x1.begin(),
			  [](int a) { return a * a; }

	);
	//Uppercase String
	std::string s("hello");
	std::transform(s.begin(), s.end(), s.begin(), std::toupper);

	//--------------copy
	copy(x1.begin(), x1.end(), back_inserter(x2));
	//Shout out whole array
	//copy(x1.begin(),x1.end(),
	//	ostream_iterator<int>(std::cout, " "));

	//-------------copy_if
	//filter passing lambda expression
	vector<int> x4;
	copy_if(x1.begin(), x1.end(), back_inserter(x4),
			[](const int &a) { return (a == 4 || a == 9); });
	copy(x4.begin(), x4.end(),
		 ostream_iterator<int>(std::cout, " "));
	//filter passing function
	vector<int> x5;
	copy_if(x1.begin(), x1.end(), back_inserter(x5), test);
	copy(x5.begin(), x5.end(),
		 ostream_iterator<int>(std::cout, " "));

	//-------------accumulate
	vector<int> x0{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int x = accumulate(x0.begin(), x0.end(), 0); //type of the last element , in this case 0 -> int
	int y = accumulate(x0.begin(), x0.end(), 1, multiplies<>());
	cout << "Accumuliert: " << x << endl;
	cout << "Multipliziert: " << y << endl;

	//----------------intersecting
	std::vector<int> v3;

	std::sort(x1.begin(), x1.end());
	std::sort(x2.begin(), x2.end());

	std::set_intersection(x1.begin(), x1.end(),
						  x2.begin(), x2.end(),
						  back_inserter(v3));

	//----------------count
	vector<int> x6{1, 1, 2, 3, 4, 4, 4, 1, 2, 3, 1, 1, 2, 3, 1, 1};
	cout << "Amount of ones :" << count(x6.begin(), x6.end(), 1) << endl;
	//----------------count_if
	cout << "Amount of numbers greater then 2: :" << count_if(x6.begin(), x6.end(), [](int a) { return a > 2; }) << endl;

	//---------------any_of  -> 0: false , 1:true
	cout << "Do we have numbers greater than 6? " << any_of(x6.begin(), x6.end(), [](auto a) { return a > 6; }) << endl;
	//--------------none_of
	cout << "DON'T we have numbers greater than 6? " << none_of(x6.begin(), x6.end(), [](auto a) { return a > 6; }) << endl;
	//--------------all
	cout << "Are all numbers higher then 0? " << all_of(x6.begin(), x6.end(), [](auto a) { return a > 0; }) << endl;

	//-----------------find
	auto it = find(x6.begin(), x6.end(), 77);
	if (it == x6.end())
	{
		cout << "Nicht gefunden!" << endl;
	}
	else
	{
		cout << "Stelle wo die erste 4 ist: " << it - x6.begin() << endl;
	}

	//----------------search
	string haystack = "askfasdfoasidfaajeo";
	string needle = "idf";
	auto it2 = search(haystack.begin(), haystack.end(), needle.begin(), needle.end());
	cout << (it2 - haystack.begin()) << endl;
}
