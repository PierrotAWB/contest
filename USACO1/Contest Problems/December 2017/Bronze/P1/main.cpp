#include <iostream>
#include <fstream>

using namespace std; 

int findOverlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) { 
	if (x3 >= x1) { 
		if (x3 < x2) { 
			if (x4 >= x2){
				if (y4 > y2)
					return min(x2 - x1, abs(x2 - x3)) * min(y2 - y1, abs(y3 - y2)); // OK
				else {
					if (y3 <= y1)
						return min(x2 - x1, abs(x2 - x3)) * min(y2 - y1, abs(y4 - y1)); // OK
					else // completely contained
						return min(x2 - x1, abs(x2 - x3)) * min(y2 - y1, abs(y4 - y3)); // OK
				}
			} else { // completely contained, horizontally
				if (y4 > y2) 
					return min(x2 - x1, abs(x3 - x4)) * min(y2 - y1, abs(y3 - y2));
				else // checked 100% contained
					if (y3 <= y1)
						return min(x2 - x1, abs(x3 - x4)) * min(y2 - y1, abs(y4 - y1));
					else
						return min(x2 - x1, abs(x3 - x4)) * min(y2 - y1, abs(y4 - y3));

			}
		} else { 
			return 0;
		}
	}

	if (x3 < x1) { 
		if (x4 > x1) { 
			if (y4 > y2)
				return min(x2 - x1, abs(x4 - x1)) * min(y2 - y1, abs(y2 - y3)); // OK
			else {
				if (y3 <= y1)
					return min(x2 - x1, abs(x4 - x1)) * min(y2 - y1, abs(y4 - y1));
				else // contained within
					return min(x2 - x1, abs(x4 - x1)) * min(y2 - y1, abs(y4 - y3));
			}
		} else { 
			return 0;
		}
	}

	return 0;
}

int main() {
	ifstream fin("billboard.in");
	// combine the two areas first
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6; 
	fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6; 
	fin.close();

	int A1 = abs(x2 - x1) * abs(y2 - y1);
	int A2 = abs(x4 - x3) * abs(y4 - y3);

	int totalArea = A1 + A2 - findOverlap(x1, y1, x2, y2, x5, y5, x6, y6) - findOverlap(x3, y3, x4, y4, x5, y5, x6, y6);
	// cout << findOverlap(x1, y1, x2, y2, x5, y5, x6, y6) << " ";
	// cout << findOverlap(x3, y3, x4, y4, x5, y5, x6, y6) << " ";

	ofstream fout("billboard.out");
	fout << totalArea << endl;
	fout.close();

	return 0;
}
