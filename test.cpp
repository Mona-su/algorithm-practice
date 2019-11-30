#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <iomanip>

using namespace std;

struct P
{
	int x, y;
};

struct comp
{
	bool operator() (const P& lhs, const P& rhs) const {
		return lhs.x < rhs.x;
	}
};

int main() {
	/* 
	 * test the datatype of int double operation 
	 * result: double
	*/
	// double ans, temp = 5.0;
	// ans = 1 / temp;
	// cout << ans << endl; // 0.2

	// int i;
	// if ((i = 3) != 5)
	// 	cout << "**" << i << endl; // **3

	/* 
	 * test the fill function for reset array value 
	*/
	// int a[5] = {0};
	// a[4]++;
	// fill(a, a+5, 0);
	// for (int i = 0; i < 5; ++i)
	// {
	// 	/* code */
	// 	cout << a[i] << " ";
	// }
	// cout << endl; // 0 0 0 0 0

	/* 
	 * test string comparison 
	 * result: "==" could do string comparison
	*/
	// string a_str = "abc";
	// string b_str = "abd";
	// if (a_str == b_str)
	// 	cout << "true" << endl;
	// else
	// 	cout << "false" << endl; // false

	/* 
	 * test stringstream 
	 * result: is >> temp1 >> temp1 >> temp3 >> temp4; works for tempx different data types
	*/
	// string line;
	// getline(cin, line);
	// istringstream is(line);
	// string temp1 = "&", temp2 = "*", temp3;
	// double temp4;
	// is >> temp1 >> temp1 >> temp3 >> temp4; // works properly, temp1 will be rewrite
	// cout << temp1 << " - " << temp2 << " - " << temp3 << " : " << temp4 << endl;

	/* 
	 * test set with user defined class or struct (see which will be deleted when duplicate occurs 
	 * also test the set print
	 * result: for duplicates, the first occurance will be left and others will be dropped
	*/
	// set<P, comp> ps;
	// for (int i = 0; i < 10; ++i)
	// {
	// 	int x, y;
	// 	cin >> x >> y;
	// 	P tempp;
	// 	tempp.x = x;
	// 	tempp.y = y;
	// 	ps.insert(tempp);
	// }
	// for (auto itr = ps.begin(); itr != ps.end(); itr++)
	// {
	// 	cout << (*itr).x << "," << (*itr).y << endl;
	// }

	/* 
	 * test double precision
	 * result: double only goes to five (or four) digits after decimal point
	 *         need to use setprecision
	*/
	// double d = 1.54345346546;
	// cout << setprecision(15) << d << endl;
	// string ds;
	// getline(cin, ds); // input ds as 1.54345346546
	// istringstream is(ds);
	// is >> d; 
	// cout << d << endl;

	/* 
	 * test to_string
	 * result: only print 6 digits after decimal point
	*/
	// string s = to_string(1.54345346546);
	// cout << s << endl; // only print 6 digits after decimal point

	/* 
	 * test minus sign
	 * result: minus sign works on variable
	*/
	// int x = 3, y = -x;
	// cout << y << endl;

	/* 
	 * test istringstream with getline
	 * result: istringstream and stod only gives 6 digits
	*/
	string line = "3346546_345.5678546_-23.657500968";
	double x, y;
	int id;
	size_t pos = line.find('_');
	string temp = line.substr(0, pos);
	cout << "id string: " << temp << endl;
	istringstream is(line);
	is >> setprecision(15) >> id;
	cout << "id int: " << id << endl;
	id = stod(line.substr(0, pos));
	cout << "id int with stod: " << id << endl;
	int start = pos + 1;
	pos = line.find('_', start);
	temp = line.substr(start, pos - start);
	cout << "x string: " << temp << endl;
	istringstream is2(temp);
	is2 >> setprecision(15) >> x;
	cout << "x double: " << x << endl;
	x = stod(line.substr(start, pos - start));
	cout << "x double with stod: " << x << endl;
	start = pos + 1;
	temp = line.substr(start, line.length() - start);
	cout << "y string: " << temp << endl;
	istringstream is3(temp);
	is3 >> setprecision(15) >> y;
	cout << "y double: " << y << endl;
	y = stod(line.substr(start, line.length() - start));
	cout << "y double with stod: " << y << endl;

	return 0;
}