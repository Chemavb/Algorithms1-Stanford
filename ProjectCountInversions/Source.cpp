#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

std::pair<vector<int>, unsigned int> mergesort_and_countinv(vector<int> v) {
	if (v.size() == 1) {
		return std::make_pair(v, 0);
	}

	vector<int>::const_iterator first = v.begin();
	vector<int>::const_iterator middle = v.begin() + v.size() / 2;
	vector<int>::const_iterator end = v.end();

	vector<int> vLeft(first, middle);
	vector<int> vRight(middle, end);

	pair<vector<int>, unsigned int> pairLeft = mergesort_and_countinv(vLeft);
	vector<int> vLeftSorted = pairLeft.first;
	int numInvIzq = pairLeft.second;
	pair<vector<int>, unsigned int> pairRight = mergesort_and_countinv(vRight);
	vector<int> vRightSorted = pairRight.first;
	int numInvRight = pairRight.second;
	//Combine phase of Divide & Conquer
	int i = 0;
	int iIzq = 0;
	int iDer = 0;
	int numSplitInv = 0;
	vector<int> vSorted;
	while (i < v.size()) {
		if (iIzq == vLeftSorted.size()) {
			vSorted.push_back(vRightSorted[iDer]);
			iDer++;
		}
		else if (iDer == vRightSorted.size()) { 
			vSorted.push_back(vLeftSorted[iIzq]);
			iIzq++;
		}
		else {
			if (vLeftSorted[iIzq] < vRightSorted[iDer]) {
				vSorted.push_back(vLeftSorted[iIzq]);
				iIzq++;
			}
			else {
				vSorted.push_back(vRightSorted[iDer]);
				iDer++;
				numSplitInv = numSplitInv + vLeftSorted.size() - iIzq;
			}
		}
		i++;
	}
	unsigned int numInvTotal = numInvIzq + numInvRight + numSplitInv;
	cout << numInvTotal << endl;
	return std::make_pair(vSorted, numInvTotal);

}

vector<int> mergesort(vector<int> v) {

	if (v.size() == 1) {
		return v;
	}
	vector<int>::const_iterator first = v.begin();
	vector<int>::const_iterator middle = v.begin() + v.size() / 2;
	vector<int>::const_iterator end = v.end();

	vector<int> vLeft(first, middle);
	vector<int> vRight(middle, end);

	vector<int> vLeftSorted = mergesort(vLeft);
	vector<int> vRightSorted = mergesort(vRight);
	//Combine phase of Divide & Conquer
	int i = 0;
	int iIzq = 0;
	int iDer = 0;
	vector<int> vSorted;
	while (i < v.size()) {
		if (iIzq == vLeftSorted.size()) {
			vSorted.push_back(vRightSorted[iDer]);
			iDer++;
		}
		else if (iDer == vRightSorted.size()) {
			vSorted.push_back(vLeftSorted[iIzq]);
			iIzq++;
		}
		else {
			if (vLeftSorted[iIzq] < vRightSorted[iDer]) {
				vSorted.push_back(vLeftSorted[iIzq]);
				iIzq++;
			}
			else {
				vSorted.push_back(vRightSorted[iDer]);
				iDer++;
			}
		}
		i++;
	}
	return vSorted;
}

int main()
{
	vector<int> v;
	vector<int> v1 = { 1,2,3 };
	std::ifstream infile("C:/Users/Chema/Documents/Algorithms1_Stanford/IntegerArray.txt");
	int a;
	while (infile >> a)
	{
		v.push_back(a);
	}
	/*for (int &a : v) {
		cout << a << endl;
	}*/
	cout << "Number of inversions: " << endl;
	pair<vector<int>, unsigned int> vectorSorted_numInv = mergesort_and_countinv(v);
	cout << vectorSorted_numInv.second << endl;

	cout << "Vecor sorted: " << endl;
	vector<int> vectorSorted = mergesort(v);
	/*for (int &a : vectorSorted) {
		cout << a << endl;
	}*/
	return 0;
}