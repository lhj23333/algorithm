#include <iostream>
#include <vector>

using namespace std;

struct point {
    int x;
    int y;
    point(int x, int y) : x(x), y(y) {}
};

bool traversal(vector<point*> &vec, point *p) {
    if(vec.size() == 0) return false;

    vector<int> xIndex;
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i]->x == p->x) {
            xIndex.push_back(i);
        }
    }

    for(size_t i = 0; i < xIndex.size(); i++) {
        if(vec[xIndex[i]]->y == p->y) return true;
    }
    return false;
}

int main() 
{
    int number;
    cin >> number;
    int result = 0;

    vector<point*> vec;
    for(size_t i = 0; i < number; i ++) {
        int x, y;
        cin >> x >> y;
        point *temp = new point(x, y);
        
        if(!traversal(vec, temp)) vec.push_back(temp);
    }

    cout << vec.size() << endl;
    
    return 0;
}