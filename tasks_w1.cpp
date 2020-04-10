/*
 * TASK 1
 *
#include <iostream>

int main(){

	int x, y;
	std::cin >> x >> y;
	std::cout << x + y;
	return 0;
}
*/

/*
 * TASK 2
#include <iostream>
#include <string>

int main(){
	std::string a, b, c;
	std::cin >> a >> b >> c;
	if (a <= b and a <= c){
		std::cout << a;
	} else if (b <= c) {
		std::cout << b;
	} else {
		std::cout << c;
	}
	return 0;
}
*/

/*
 * TASK 3

#include <iostream>
#include <cmath>

int main() {
	double a, b, c;
	std::cin >> a >> b >> c;
	double add_part = b * b - 4*a*c;
	if (a == 0) {
		if (b == 0) {
			return 0;
		}
		std::cout << -1 * c / b;
	} else if (add_part == 0){
		std::cout << -1 * b / (2*a);
	} else if (add_part > 0) {
		std::cout << (-1 * b + sqrt(add_part))/ (2*a) << " " << (-1 * b - sqrt(add_part))/ (2*a);
	}
	return 0;
}
*/

/*
 * TASK 4
 *
 * 10 2
 * 3 5
 * 11 0
 * 0 10

#include <iostream>

int main(){

	int a, b;
	std::cin >> a >> b;

	if (b == 0) {
		std::cout << "Impossible";
	} else {
		std::cout << a / b;
	}

	return 0;
}
 */


/*
 * TASK 5
 *
 *
 * 100 110 120 5 10
 * 115 110 120 5 10
 * 150 110 120 5 12.5


#include <iostream>

int main(){
	double n, a, b, x, y;

	std::cin >> n >> a >> b >> x >> y;
	if (n > a) {
		if (n > b) {
			std::cout << n * (100 - y) / 100 << std::endl;
		} else {
			std::cout << n * (100 - x) / 100 << std::endl;
		}
	} else {
		std::cout << n << std::endl;
	}

	return 0;
}
 */

/*
 * TASK 6
 *
 * 1 10
 * 2 3
 * 9 11


#include <iostream>

int main() {
	int a, b;

	std::cin >> a >> b;

	if (a % 2 == 1) {
		a += 1;
	}

	for (int i = a; i <=b; i+=2) {
		std::cout << i;
		if (i < b) {
			std::cout << " ";
		}
	}

	return 0;
}
 */


/*
 * TASK 7
 *
 * comfort
 * coffee
 * car


#include <iostream>
#include <string>

int main() {
	std::string s;
	int count = 0;
	int index = -2;

	std::cin >> s;

	for (int i = 0; i < s.size(); ++i){
		if (s[i] == 'f') {
			count +=1;
			if (count == 2){
				index = i;
				break;
			}
		}
	}

	if (count < 2) {
			index += count;
	}
	std::cout << index;

	return 0;
}
 */


/*
 * TASK 8
 *
 * Euclide algorithm
 *
 * 25 27
 * 12 16
 * 13 13

#include <iostream>

int main(){
	int a, b;

	std::cin >> a >> b;
	while (a > 0 && b > 0){
		if (a > b) {
			a %= b;
		} else {
			b %= a;
		}
	}

	std::cout << a + b << std::endl;
	return 0;
}
*/


/*
 * TASK 9
 *
 * 5 -> 101
 * 32 -> 100000
 * 1 -> 1


#include <iostream>
#include <vector>

int main() {

	int n;
	std::vector<int> val;
	std::cin >> n;

	while (n > 0){
		val.push_back(n % 2);
		n /= 2;
	}

	for (int i=val.size() -1; i >= 0; --i){
		std::cout << val[i];
	}

	return 0;
}
 */

















