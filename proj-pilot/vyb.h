#ifndef VYB_H
#define VYB_H
#include <QTextStream>
#include <QFile>
#include <QString>
#include <QChar>

#define A  35

using namespace std;

struct treeNode
{
    struct treeNode* children[A];
    QChar a = a.toLatin1();
    bool isEnd;
};

static QString* x=new QString[3];
treeNode* getNode(void)
{
    treeNode* p = new treeNode;

    p->isEnd = false;

    for (int i = 0; i < A; i++)
        p->children[i] = NULL;

    return p;
}
void ochyst()
{
    for(int i = 0; i<3; i++)
    {
        x[i].clear();
    }
}
void insert(treeNode* root, QString key)
{
    key = key.toLatin1();
    treeNode* p = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index;
        if (key[i] == L'і') //і
        {
            index = L'ъ' - L'а';
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
            p->a = L'і';
        }
        else if (key[i] == L'ї')//ї
        {
            index = L'ы' - L'а';
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
            p->a = L'ї';
        }
        else if (key[i] == L'є')//є
        {
            index = L'э' - L'а';
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
            p->a = L'є';
        }
        else if (key[i] == L'ґ')//ґ
        {
            index = 32;
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
            p->a = L'ґ';
        }
        else if (key[i] == L'’')//’
        {
            index = 33;
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
            p->a = L'’';
        }
        else if (key[i] == L'-')//-
        {
            index = 34;
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
            p->a = L'-';
        }
        else {
            index = key[i].toLatin1() - L'а';
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
            p->a = key[i];
        }

    }
    p->isEnd = true;
}

void searchByPrefix(treeNode* trieNode, QString k, QString prefix, int index, int rah) {
    if (index < prefix.length()) {
        QChar ch = prefix[index].toLatin1();
        int position;
        if (prefix[index] == L'і')
        {
            position = 26;
        }
        else if (prefix[index] == L'ї')
        {
            position = 27;
        }
        else if (prefix[index] == L'є')
        {
            position = 29;
        }
        else if (prefix[index] == L'ї')
        {
            position = 32;
        }
        else if (prefix[index] == L'’')
        {
            position = 33;
        }
        else if (prefix[index] == L'-')
        {
            position = 34;
        }
        else position = ch.toLatin1() - L'а';
        if (trieNode->children[position] != nullptr) {
            k += trieNode->children[position]->a;
            if (index == prefix.length() - 1 && trieNode->children[position]->isEnd) {
                x[rah]=k;
            }
            searchByPrefix(trieNode->children[position], k, prefix, index + 1,rah++);
            string c = "";
            k[k.length() - 1] = NULL;
        }
    }
    else {
        for (int i = 0; i < A; i++) {
            if (trieNode->children[i] != NULL) {
                k += trieNode->children[i]->a;
                if (trieNode->children[i]->isEnd) {
                    x[rah]=k;
                }
                searchByPrefix(trieNode->children[i], k, prefix, index + 1, rah++);
                k[k.length() - 1] = NULL;
            }
        }
    }
    if(rah == 2){
        return;
    }
}

QString* kin(QString text)
{

    QFile input("voc.txt");
    treeNode* root = getNode();
    ochyst();
    QString line;
    if(input.isOpen()){
        while (!input.atEnd()) {
            line = input.readLine();
            insert(root, line.toLatin1());
        }
    QString u;
    u = u.toLatin1();
    QString* a = new QString [3];
    searchByPrefix(root, u, text, 0,0);

    line.clear();
    return x;
  }
  return NULL;
}

#endif // VYB_H
