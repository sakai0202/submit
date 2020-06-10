#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/* オブザーバーパターン
状態の変化の観察、通知

状態が変化する側からの通知
航空会社が常にループを回して状態変化を観察するのは無益
変化があったときに客が通知するべき
本例では、求人サイトを模して求人サイトが更新されたときに、
求人サイト(被観測者側)から登録者全体にnotify

状態と処理の分離
各部品の交換可能性を高める

本例のように、容易に観測者を追加することが出来る。

より一般的には、JobPosting, JobSeekerもそれぞれ基本クラスにObserver, Observableのように
処理を記載し、拡張性を高める。


cf.
https://techracho.bpsinc.jp/hachi8833/2017_10_17/46071#observer
https://www.techscore.com/tech/DesignPattern/Observer.html/
https://qiita.com/junkin_au/items/3fc358798bbaa31c4921
*/

class JobPost {
protected:
    string title;
public:
    JobPost(string name) {
        title = name;
    }

    string getTitle() {
        return title;
    }
};

//観測する側
class JobSeeker {
protected:
    string myname;
public:

    JobSeeker(string nam) {
        myname = nam;
    }
    ~JobSeeker() {};

    void onJobPosted(JobPost* job)
    {
        cout << myname << "さん、新しい仕事情報が投稿されました。　職種:" << job->getTitle() << endl;
    }
};

//観測される側
class JobPosting {
protected:
    std::vector<JobSeeker*> vecObserver;
public:
    void notify(JobPost* job) {
        for (unsigned int i = 0; i < (vecObserver.size()); i++) {
            vecObserver.at(i)->onJobPosted(job);
        }
    }

    void attach(JobSeeker* addobs) {
        vecObserver.push_back(addobs);
    }

    void addJob(JobPost* jobposting) {
        notify(jobposting);
    }

};

int main() {
    //観測者側の作成
    JobSeeker* stu1 = new JobSeeker("田中太郎");
    JobSeeker* stu2 = new JobSeeker("山田花子");

    //被観測者側
    JobPosting* information = new JobPosting();
    information->attach(stu1);
    information->attach(stu2);

    information->addJob(new JobPost("ソフトウェアエンジニア"));

    JobSeeker* stu3 = new JobSeeker("Jhon Doe");
    information->attach(stu3);

    information->addJob(new JobPost("お笑い芸人"));
}


