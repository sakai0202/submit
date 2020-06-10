#include <iostream>
#include <algorithm>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/*Compositeパターン
容器と中身の同一視により再帰的な構造の取り扱いを容易にする
cf↓　の概念図通りに実装
https://maku.blog/p/7gmjvza/#8-composite-パターン
*/

class Entry {
public:
    virtual int GetSize() = 0;
    virtual ~Entry() {};
};

class File : public Entry {
protected:
    int size;
public:
    File(int inisiz) {
        size = inisiz;
    }
    virtual ~File() {};

    virtual int GetSize() { return size; }
};

class Directory : public Entry {
protected:
    vector<Entry*> allfile;

public:

    virtual ~Directory() {};

    void AddEntry(Entry* entry) {
        allfile.push_back(entry);
    }

    virtual int GetSize() {
        int sum = 0;
        for (unsigned int i = 0; i < allfile.size(); i++) {
            sum += allfile.at(i)->GetSize();
        }

        //    cout << "dir size =" << sum << endl;
        return sum;
    }

};

int main() {
    Directory* dir = new Directory();
    dir->AddEntry(new File(10));
    dir->AddEntry(new File(20));

    Directory* dir2 = new Directory();
    dir2->AddEntry(dir);
    dir2->AddEntry(new File(30));

    Directory* dir3 = new Directory();
    dir3->AddEntry(dir2);
    dir3->AddEntry(new File(50));
    dir3->AddEntry(new File(100));

    Directory* dir4 = new Directory();
    dir4->AddEntry(dir2);
    dir4->AddEntry(new File(500));
    dir4->AddEntry(new File(100));


    cout << dir->GetSize() << endl;
    cout << dir2->GetSize() << endl;
    cout << dir3->GetSize() << endl;
    cout << dir4->GetSize() << endl;

}
