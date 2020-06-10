#include <iostream>
#include <algorithm>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/*ストラテジーパターン
変動しやすい一連の処理を持つ部分を分離し、それを簡単に切り替えて実行できるような仕組み
別クラスに分離することでメンテナンス性が向上
StatePatternとは内部状態が変化することに重点を置かれている点で違うということになる
cf.
https://techracho.bpsinc.jp/hachi8833/2017_10_17/46071#strategy
*/

class SortStrategy {
public:
    virtual ~SortStrategy() {};

    virtual void Sort(vector<int>& arrays) = 0;
};

class NormalSortStrategy : public SortStrategy {
    void Sort(vector<int>& arrays) override {
        std::sort(arrays.begin(), arrays.end());
        cout << "std sort" << endl;
    }
};

class StableSortStrategy : public SortStrategy {
    void Sort(vector<int>& arrays) override {
        std::stable_sort(arrays.begin(), arrays.end());
        cout << "std stable sort" << endl;
    }
};

class Sorter {
protected:
    SortStrategy* sortStrategy;
public:
    Sorter(SortStrategy* inisort) {
        sortStrategy = inisort;
    }

    void Sort(vector<int>& dataset) {
        sortStrategy->Sort(dataset);
    }
};

int main() {
    vector<int> dataset;
    dataset.push_back(4);
    dataset.push_back(2);
    dataset.push_back(7);
    dataset.push_back(6);
    dataset.push_back(8);

    Sorter* sorter = new Sorter(new NormalSortStrategy());
    sorter->Sort(dataset);

    for (unsigned int i = 0; i < dataset.size(); i++) {
        cout << dataset[i] << endl;
    }

    dataset.push_back(4);
    dataset.push_back(2);
    dataset.push_back(7);
    dataset.push_back(6);
    dataset.push_back(8);

    Sorter* sorter2 = new Sorter(new StableSortStrategy());
    sorter2->Sort(dataset);

    for (unsigned int i = 0; i < dataset.size(); i++) {
        cout << dataset[i] << endl;
    }
}
