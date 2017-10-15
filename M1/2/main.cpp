/* Задание 2.4
“Считалочка”. В круг выстроено N человек, 
пронумерованных числами от 1 до N. 
Будем исключать каждого k-ого до тех пор, 
пока не уцелеет только один человек. 
(Например, если N=10, k=3, то сначала умрет 3-й, 
	потом 6-й, затем 9-й, затем 2-й, затем 7-й, потом 1-й, 
		потом 8-й, за ним - 5-й, и потом 10-й. Таким образом, уцелеет 4-й.) 
Необходимо определить номер уцелевшего.
N, k ≤ 10000.
*/

#include <iostream>
 
int getPlayer(int count, int split) {
     int res = 0;
     for (int i = 1; i <= count; ++i)
         res = (res + split) % i;
     return ++res;
 }
 
int main() {
    int count, split;
    std::cin >> count >> split;
    if (!count && !split) return 0;
    if (count == 1) std::cout << 1;
    else std::cout << getPlayer(n,k);
    
    return 0;
}