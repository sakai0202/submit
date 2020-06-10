#include <iostream>
#include <string.h>
#include <list>
#include <vector>

using namespace::std;

/* �I�u�U�[�o�[�p�^�[��
��Ԃ̕ω��̊ώ@�A�ʒm

��Ԃ��ω����鑤����̒ʒm
�q���Ђ���Ƀ��[�v���񂵂ď�ԕω����ώ@����͖̂��v
�ω����������Ƃ��ɋq���ʒm����ׂ�
�{��ł́A���l�T�C�g��͂��ċ��l�T�C�g���X�V���ꂽ�Ƃ��ɁA
���l�T�C�g(��ϑ��ґ�)����o�^�ґS�̂�notify

��ԂƏ����̕���
�e���i�̌����\�������߂�

�{��̂悤�ɁA�e�ՂɊϑ��҂�ǉ����邱�Ƃ��o����B

����ʓI�ɂ́AJobPosting, JobSeeker�����ꂼ���{�N���X��Observer, Observable�̂悤��
�������L�ڂ��A�g���������߂�B


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

//�ϑ����鑤
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
        cout << myname << "����A�V�����d����񂪓��e����܂����B�@�E��:" << job->getTitle() << endl;
    }
};

//�ϑ�����鑤
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
    //�ϑ��ґ��̍쐬
    JobSeeker* stu1 = new JobSeeker("�c�����Y");
    JobSeeker* stu2 = new JobSeeker("�R�c�Ԏq");

    //��ϑ��ґ�
    JobPosting* information = new JobPosting();
    information->attach(stu1);
    information->attach(stu2);

    information->addJob(new JobPost("�\�t�g�E�F�A�G���W�j�A"));

    JobSeeker* stu3 = new JobSeeker("Jhon Doe");
    information->attach(stu3);

    information->addJob(new JobPost("���΂��|�l"));
}


