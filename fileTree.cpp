//
// Created by NSUS on 2021/4/18.
//

#include "fileTree.h"
#include <iostream>
#include <string>
#include <sstream>

fileTree::fileTree() {
    opt = "";
    postfix = "";
    nowDir = "/";
    root = new Node("/", nullptr, DIR);
    now  = root;
    reConstruct();
}

void fileTree::getCommend() {
    string commend;
    string get[2];
    for(int i = 0; i < 2; i++) get[i] = "";
    getline(cin, commend);
    stringstream ss;
    ss << commend;
    int i = 0;
    while(getline(ss, get[i++], ' '));
    opt = get[0];
    postfix = get[1];
}

Node* fileTree::getChildNode(string name) {
    Node* firstChild = now->child;
    while(firstChild != NULL && firstChild->name != name) firstChild = firstChild->brother;
    return firstChild;
}

void fileTree::run() {
    while(1) {
        getCommend();
        selectFunctionToRun(void)();
        if(opt == "quit") break;
    }
}

void (*)() fileTree::selectFunctionToRun() {
    switch(opt) {
        case "cd": return cd;
        case "mkdir": return mkdir;
        case "mkfile": return mkfile;
        case "dir": return dir;
        case "save": return save;
        case "reConstruct": return reConstruct;
        case "load": return load;
        case "quit": return quit;
    }
}

void fileTree::dir() {
    Node* current = now->child;
    if(current == NULL) return ;
    while(current->type == DIR) {
        cout << dirFlag + current.name << endl;
        current = current->brother;
    }
    if(curret == NULL) return;
    while(current != NULL) {
        cout << current.name + fileFlag << endl;
        current = current->brother;
    }
    return ;
}

void fileTree::mkdir() {
    Node* current = now->child;
    while(current != NULL && current->type == DIR) {
        if ()
    }
}