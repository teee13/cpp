#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    std::vector<double> v;
    double median;
    v.insert(v.begin(), nums1.begin(), nums1.end());
    v.insert(v.end(), nums2.begin(), nums2.end());
    std::sort(v.begin(), v.end());

    if (v.size() % 2 != 0)
    {
        int m = ((v.size() + 1) / 2) - 1;
        median = v[m];
    }
    else
    {
        int m = (v.size() / 2) - 1;
        int m2 = (v.size() / 2);
        median = (v[m] + v[m2]) / 2;
    }
    return median;
}

int main()
{
    vector<int> v1 = {1, 2, 5};
    vector<int> v2 = {0, 3, 4};
    double median = findMedianSortedArrays(v1, v2);
    cout << median;

    return 0;
}
