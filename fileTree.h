//
// Created by NSUS on 2021/4/18.
//

#ifndef FILEMENU_FILETREE_H
#define FILEMENU_FILETREE_H
using namespace std;

const string dirFlag = "/";
const string fileFlag = "*";
enum TYPE {DIR, FILE};

struct Node{
    string name;
    Node* parent;
    Node* child;
    Node* brother;
    TYPE type;

    Node(): parent(nullptr), child(nullptr), borther(nullptr) {
        type = DIR;
        name = "";
    };
    Node(string Name, Node* Parent, TYPE t): name(Name), parent(Parent), type(t) {
        child = nullptr;
        brother = nullptr;
    };
};

class fileTree {
public:
    fileTree();
    ~fileTree();

    void run();       /*目录系统开始运行*/
    void dir();       /*根据节点输出文件以及文件名*/
    void mkdir()      /*在当前节点下创建文件夹并按照字典序插入*/
    void cd();
    void mkfile();
    void save();
    void reConstruct();
    void quit();
private:
    Node *root;
    Node *now;
    string opt;             /*记录操作类型*/
    string postfix;         /*记录操作后缀*/
    string nowDir;          /*记录当前目录*/
    Node* getChildNode(string name); /*根据文件夹名返回该节点*/
    void getCommend();
    void (*selectFunctionToRun())();
};


#endif //FILEMENU_FILETREE_H
