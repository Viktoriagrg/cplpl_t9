#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QTextEdit>
#include <QButtonGroup>
#include <QPushButton>
#include <QChar>
#include <QTextStream>
#include <QFile>
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>
#include <QDir>
#include <QTextCodec>
#define A  36

using namespace std;

// Function declarations
bool persha_vidm(QString text, bool a, bool b);
bool druga_vidm(QString text, bool a, bool b);
bool tretia_vidm(QString text);
bool chetverta_vidm(QString text);
bool poshuk(QString prefix);
QString defis(QString a);

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->derevtse->setChecked(1);
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}


// Close button click handler
void MainWindow::on_pushButton_4_clicked()
{
    QWidget::close();
}

// Triggered action handler
void MainWindow::on_action_3_triggered()
{
    QWidget::close();
}

static QString text;

// PushButton click handler
void MainWindow::on_pushButton_clicked()
{


    QString j = ui->aaaa->toPlainText();

    if(ui->textBrowser->toPlainText()!="")
    {
        QString w = ui->aaaa->toPlainText();
        if(ui->radioButton_2->isChecked())
        {
            // Check for specific words and add them with a comma
            if((QString::compare(w,"щоб")==0)||(QString::compare(w,"але")==0) ||(QString::compare(w,"а")==0)||(QString::compare(w,"що")==0)||(QString::compare(w,"зате")==0)||(QString::compare(w,"проте")==0)||(QString::compare(w,"однак")==0))
            {
                text = text + U','+' ' + w;
                ui->textBrowser->setText(text);
                ui->aaaa->clear();
                ui->radioButton_2->setChecked(false);
                return;
            }

        }
    }
    // Additional validation based on radio button selections
    if(!(ui->radioButton_16->isChecked()||ui->radioButton_17->isChecked())){
    if(ui->radioButton_2->isChecked())
    {
        QString l = j;
        j = defis(j);
        if(!(QString::compare(l,j)==0)){
        text = text + ' ' + j;
        ui->textBrowser->setText(text);
        ui->aaaa->clear();
        ui->radioButton_2->setChecked(0);
        return;
        }
    }
    if(ui->im->isChecked()&&(ui->os1->isChecked()||ui->os2->isChecked())/*&&((j.at(j.length()-1)==U'а')||(j.at(j.length()-1)==U'я'))*/)
    {
        if(!poshuk(j)){
        if(!persha_vidm(j, ui->os1->isChecked(), ui->os2->isChecked())){
        QMessageBox s;
        s.information(this,"ERROR!!!","Закінчення введено неправильно, змініть його");
        return;
        }
    }
    }
    if(ui->im->isChecked()&&(ui->os1->isChecked()||ui->os2->isChecked())/*&&((j.at(j.length()-1)==U'а')||(j.at(j.length()-1)==U'я'))*/)
    {
        if(!poshuk(j)){
        if(!druga_vidm(j, ui->os2->isChecked(), ui->os3->isChecked())){
        QMessageBox s;
        s.information(this,"ERROR!!!","Закінчення введено неправильно, змініть його");
        return;
        }
    }
    }
    if(ui->im->isChecked()&&(ui->os1->isChecked())/*&&((j.at(j.length()-1)==U'а')||(j.at(j.length()-1)==U'я'))*/)
    {
        if(!poshuk(j)){
        if(!tretia_vidm(j)){
        QMessageBox s;
        s.information(this,"ERROR!!!","Закінчення введено неправильно, змініть його");
        return;
        }
    }
    }
    if(ui->im->isChecked()&&((ui->os3->isChecked()&&(j.contains("ат")||j.contains("ят"))))/*&&((j.at(j.length()-1)==U'а')||(j.at(j.length()-1)==U'я'))*/)
    {
        if(!poshuk(j)){
        if(!chetverta_vidm(j)){
        QMessageBox s;
        s.information(this,"ERROR!!!","Закінчення введено неправильно, змініть його");
        return;
        }
    }
    }
    }
    // Additional processing based on textBrowser content and input
    if(ui->textBrowser->toPlainText()!="")
    {
        if(ui->aaaa->toPlainText().length()!=0)
        {
            if(((QString::compare(j.left(7),"адютант")and QString::compare(j.left(9),"конюнктив"))and(QString::compare(j.left(9),"конюнктур")and QString::compare(j.left(4),"інєк")))!=0)
            {
                for(int i = 0; i<j.length()-1;i++)
                {

                    if((j[i]==U'б'||j[i]==U'п'||j[i]==U'в'||j[i]==U'м'||j[i]==U'ф')and((j[i+1]==U'я')||j[i+1]==U'ю'||j[i+1]==U'є'||j[i+1]==U'ї'))
                    {
                        if(i>0){
                            if(j[i-1] !=U'а'|| j[i-1] !=U'я'||j[i-1] !=U'у'||j[i-1] !=U'ю'||j[i-1] !=U'і'||j[i-1] !=U'ї'||j[i-1] !=U'е'||j[i-1] !=U'є'||j[i-1] !=U'о'||j[i-1] !=U'и')
                            {
                                break;
                            }
                        }
                        j.insert(i+1,U'’');
                        ui->aaaa->setText(j);
                        break;
                    }
                }
            }
            else if(QString::compare(j.left(7),"адютант")==0)
            {
                j.insert(2,U'’');
                ui->aaaa->setText(j);
            }
            else if(QString::compare(j.left(9),"конюнктив")==0)
            {
                j.insert(3,U'’');
                ui->aaaa->setText(j);
            }
            else if(QString::compare(j.left(9),"конюнктур")==0)
            {
                j.insert(3,U'’');
                ui->aaaa->setText(j);
            }
            else if(QString::compare(j.left(4),"інєк")==0)
            {
                j.insert(2,U'’');
                ui->aaaa->setText(j);
            }
            // Append the modified text to textBrowser
            text = text + ' ' + ui->aaaa->toPlainText();
            ui->textBrowser->setText(text);
        }
    }
    else
    {
        if(((QString::compare(j.left(7),"адютант")and QString::compare(j.left(9),"конюнктив"))and(QString::compare(j.left(9),"конюнктур")and QString::compare(j.left(4),"інєк")))!=0)
        {
            for(int i = 0; i<j.length()-1;i++)
            {
                if((j[i]==U'б'||j[i]==U'п'||j[i]==U'в'||j[i]==U'м'||j[i]==U'ф')and((j[i+1]==U'я')||j[i+1]==U'ю'||j[i+1]==U'є'||j[i+1]==U'ї'))
                {
                    if(i>0){
                        if(j[i-1] !=U'а'|| j[i-1] !=U'я'||j[i-1] !=U'у'||j[i-1] !=U'ю'||j[i-1] !=U'і'||j[i-1] !=U'ї'||j[i-1] !=U'е'||j[i-1] !=U'є'||j[i-1] !=U'о'||j[i-1] !=U'и')
                        {
                            break;
                        }
                    }
                    j.insert(i+1,U'’');
                    ui->aaaa->setText(j);
                    break;
                }
            }
        }
        else if(QString::compare(j.left(7),"адютант")==0)
        {
            j.insert(2,U'’');
            ui->aaaa->setText(j);
        }
        else if(QString::compare(j.left(9),"конюнктив")==0)
        {
            j.insert(3,U'’');
            ui->aaaa->setText(j);
        }
        else if(QString::compare(j.left(9),"конюнктур")==0)
        {
            j.insert(3,U'’');
            ui->aaaa->setText(j);
        }
        else if(QString::compare(j.left(4),"інєк")==0)
        {
            j.insert(2,U'’');
            ui->aaaa->setText(j);
        }
        QString k = ui->aaaa->toPlainText();
        QChar a = k.at(0);
        if((ui->radioButton_17->isChecked()||ui->radioButton_16->isChecked())==0)
        {
            if(a==U'ґ')
            {
                a.unicode()=a.unicode()-1;
            }
            else if(a==U'і'||a==U'ї'||a==U'є')
            {
                a.unicode()=a.unicode()-80;
            }
            else
            {
                a.unicode()=a.unicode()-32;
            }
            k.remove(0,1);
            k.push_front(a);
            text = text + ' ' + k;
            ui->textBrowser->setText(text);
        }
        else
        {
            text = text + ' ' + k;
            ui->textBrowser->setText(k);
        }

    }

   // 16 17 3 2 1
    // Set various radio buttons and checkboxes to unchecked
    bool loc = false;
    ui->buttonGroup->setExclusive(loc);
    ui->buttonGroup_5->setExclusive(loc);
    ui->radioButton_16->setChecked(loc);
    ui->radioButton_17->setChecked(loc);
    ui->radioButton_3->setChecked(loc);
    ui->radioButton_2->setChecked(loc);
    ui->radioButton->setChecked(loc);
    ui->buttonGroup_2->setExclusive(loc);
    ui->buttonGroup_3->setExclusive(loc);
    ui->buttonGroup_4->setExclusive(loc);
    // Clear the text in a text input field
    ui->aaaa->clear();
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    ui->buttonGroup_2->setExclusive(checked);
    if(checked == 0)
    {
        ui->im->setChecked(checked);
        ui->diya->setChecked(checked);
        ui->zaym->setChecked(checked);
        ui->chysl->setChecked(checked);
        ui->prykm->setChecked(checked);
        ui->prysl->setChecked(checked);
    }
    ui->im->setEnabled(checked);
    ui->diya->setEnabled(checked);
    ui->zaym->setEnabled(checked);
    ui->chysl->setEnabled(checked);
    ui->prykm->setEnabled(checked);
    ui->prysl->setEnabled(checked);

}

void MainWindow::on_im_toggled (bool checked)
{
    //if(ui->im->isChecked()||ui->diya->isChecked()||ui->zaym->isChecked()||ui->prykm->isChecked()){
    ui->buttonGroup_3->setExclusive(checked);
    if(checked==0)
    {
        ui->odn->setChecked(checked);
        ui->mnozh->setChecked(checked);
    }
    ui->odn->setEnabled(checked);
    ui->mnozh->setEnabled(checked);
    ui->buttonGroup_4->setExclusive(checked);
    if(checked==0)
    {
        ui->os1->setChecked(checked);
        ui->os2->setChecked(checked);
        ui->os3->setChecked(checked);
    }
    ui->os1->setEnabled(checked);
    ui->os2->setEnabled(checked);
    ui->os3->setEnabled(checked);


    //}
    /*else{
        ui->buttonGroup_3->setExclusive(false);
        ui->odn->setEnabled(false);
        ui->mnozh->setEnabled(false);
        ui->buttonGroup_4->setExclusive(false);
        ui->os1->setEnabled(false);
        ui->os2->setEnabled(false);
        ui->os3->setEnabled(false);
    }*/
}

void MainWindow::on_prykm_toggled(bool checked)
{
    ui->buttonGroup_3->setExclusive(checked);
    ui->odn->setEnabled(checked);
    ui->mnozh->setEnabled(checked);
    ui->buttonGroup_4->setExclusive(checked);
    ui->os1->setEnabled(checked);
    ui->os2->setEnabled(checked);
    ui->os3->setEnabled(checked);
}

void MainWindow::on_zaym_toggled(bool checked)
{
    ui->buttonGroup_3->setExclusive(checked);
    ui->odn->setEnabled(checked);
    ui->mnozh->setEnabled(checked);
    ui->buttonGroup_4->setExclusive(checked);
    ui->os1->setEnabled(checked);
    ui->os2->setEnabled(checked);
    ui->os3->setEnabled(checked);
}

void MainWindow::on_diya_toggled(bool checked)
{
    ui->buttonGroup_3->setExclusive(checked);
    ui->odn->setEnabled(checked);
    ui->mnozh->setEnabled(checked);
    ui->buttonGroup_4->setExclusive(checked);
    ui->os1->setEnabled(checked);
    ui->os2->setEnabled(checked);
    ui->os3->setEnabled(checked);
}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    if(checked==1)
    {
        ui->buttonGroup_2->setExclusive(!checked);
        ui->im->setEnabled(!checked);
        ui->im->setChecked(!checked);
        ui->diya->setEnabled(!checked);
        ui->diya->setChecked(!checked);
        ui->zaym->setEnabled(!checked);
        ui->zaym->setChecked(!checked);
        ui->chysl->setEnabled(!checked);
        ui->chysl->setChecked(!checked);
        ui->prykm->setEnabled(!checked);
        ui->prykm->setChecked(!checked);
        ui->prysl->setEnabled(!checked);
        ui->prysl->setChecked(!checked);
        ui->buttonGroup_3->setExclusive(!checked);
        ui->odn->setEnabled(!checked);
        ui->odn->setChecked(!checked);
        ui->mnozh->setEnabled(!checked);
        ui->mnozh->setChecked(!checked);
        ui->buttonGroup_4->setExclusive(!checked);
        ui->os1->setEnabled(!checked);
        ui->os1->setChecked(!checked);
        ui->os2->setEnabled(!checked);
        ui->os2->setChecked(!checked);
        ui->os3->setEnabled(!checked);
        ui->os3->setChecked(!checked);
    }
}
void MainWindow::on_chysl_toggled(bool checked)
{
    if(checked==1)
    {
        ui->buttonGroup_3->setExclusive(!checked);
        ui->odn->setEnabled(!checked);
        ui->odn->setChecked(!checked);
        ui->mnozh->setEnabled(!checked);
        ui->mnozh->setChecked(!checked);
        ui->buttonGroup_4->setExclusive(!checked);
        ui->os1->setEnabled(!checked);
        ui->os1->setChecked(!checked);
        ui->os2->setEnabled(!checked);
        ui->os2->setChecked(!checked);
        ui->os3->setEnabled(!checked);
        ui->os3->setChecked(!checked);
    }
}

void MainWindow::on_prysl_toggled(bool checked)
{
    if(checked==1)
    {
        ui->buttonGroup_3->setExclusive(!checked);
        ui->odn->setEnabled(!checked);
        ui->odn->setChecked(!checked);
        ui->mnozh->setEnabled(!checked);
        ui->mnozh->setChecked(!checked);
        ui->buttonGroup_4->setExclusive(!checked);
        ui->os1->setEnabled(!checked);
        ui->os1->setChecked(!checked);
        ui->os2->setEnabled(!checked);
        ui->os2->setChecked(!checked);
        ui->os3->setEnabled(!checked);
        ui->os3->setChecked(!checked);
    }
}

void MainWindow::on_radioButton_16_toggled(bool checked)
{
    if(checked==1)
    {
        QString tex = ui->aaaa->toPlainText();
        QChar a = tex.at(0);
        // Adjust the first character based on specific conditions
        if(a==U'ґ')
        {

            a.unicode()=a.unicode()-1;
        }
        else if(a==U'і'||a==U'ї'||a==U'є')
        {
            a.unicode()=a.unicode()-80;
        }
        else
        {
            a.unicode()=a.unicode()-32;
        }
        tex.remove(0,1);
        tex.push_front(a);
        ui->aaaa->clear();
        ui->aaaa->setText(tex);
    }
    else if(checked==0)
    {
        QString tex = ui->aaaa->toPlainText();
        QChar a = tex.at(0);
        // Adjust the first character based on specific conditions
                if(a==U'Ґ')
                {

                    a.unicode()=a.unicode()+1;
                }
                else if(a==U'І'||a==U'Ї'||a==U'Є')
                {
                    a.unicode()=a.unicode()+80;
                }
                else
                {
                    a.unicode()=a.unicode()+32;
                }
                tex.remove(0,1);
                tex.push_front(a);
                ui->aaaa->clear();
                ui->aaaa->setText(tex);
    }
}


void MainWindow::on_radioButton_17_toggled(bool checked)
{
    if(checked==1)
    {
        QString tex = ui->aaaa->toPlainText();
        int n = tex.length();
        int i = 0;
        QChar a = tex.at(0);
        QString s;
        // Iterate through the characters and adjust them based on specific conditions
        while(i<n)
        {
            a = tex.at(i);
        if(a==U'ґ')
        {
            a = a.unicode()-1;
        }
        else if(a==U'і'||a==U'ї'||a==U'є')
        {
            a.unicode()=a.unicode()-80;
        }
        else
        {
            a.unicode()=a.unicode()-32;
        }
        s.push_back(a);
        //text.replace(i,1,a);
        i++;
        }
        ui->aaaa->clear();
        ui->aaaa->setText(s);
    }
    else if(checked==0)
    {
        QString tex = ui->aaaa->toPlainText();
        int n = tex.length();
        int i = 0;
        QChar a = tex.at(0);
        QString s;
        // Iterate through the characters and adjust them based on specific conditions
        while(i<n)
        {
            a = tex.at(i);
        if(a==U'Ґ')
        {

            a.unicode()=a.unicode()+1;
        }
        else if(a==U'І'||a==U'Ї'||a==U'Є')
        {
            a.unicode()=a.unicode()+80;
        }
        else
        {
            a.unicode()=a.unicode()+32;
        }
        s.push_back(a);
        //text.remove(i,1);
        //text.insert(i,a);
        //text.replace(i,1,a);
        i++;
        }
        ui->aaaa->clear();
        ui->aaaa->setText(a);
    }
}

// Definition of a tree node structure for a trie
struct treeNode
{
    struct treeNode* children[A];
    bool isEnd;
};

// Function to create a new tree node
treeNode* getNode(void)
{
    treeNode* p = new treeNode;

    p->isEnd = false;
    for (int i = 0; i < A; i++)
        p->children[i] = NULL;

    return p;
}

// Function to insert a string into a trie
void insert(treeNode* root, QString key)
{

    treeNode* p = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index;
        // Handle special cases for specific characters in the key
        if (key[i] == U'і') //і
        {
            index = 26;
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
        }
        else if (key[i] == U'ї')//ї
        {
            index = 27;
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
        }
        else if (key[i] == U'є')//є
        {
            index = 29;
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
        }
        else if (key[i] == U'ґ')//ґ
        {
            index = 32;
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
        }
        else if (key[i] == U'’')//’
        {
            index = 33;
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
        }
        else if (key[i] == U'!')//’
        {
            index = 35;
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
        }
        else if (key[i] == U'-')//-
        {
            index = 34;
            if (not(p->children[index]))
            {
                p->children[index] = getNode();
            }
            p = p->children[index];
        }
        else
        {
            QChar t = U'а';
            index = abs(key[i].unicode() - t.unicode());
            if (!p->children[index]) p->children[index] = getNode();
            p = p->children[index];
        }

    }
    p->isEnd = true;
}

// Global variable representing the root of the trie
static treeNode* root = getNode();

// Function to build a trie from the content of a file
void derevo()
{
    QString line;
    QFile input("D:\\Documents\\q.txt");
    if (!input.exists()) {
        std::cout<<"Файл не існує";
    }
    input.open(QIODevice::ReadOnly|QIODevice::Text);

    if (!input.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        std::cout<<"Cannot open file for reading"; // если файл не найден, то выводим предупреждение и завершаем выполнение программы
    }
    QTextStream in(&input);
    QTextCodec *codec = QTextCodec::codecForName("CP1251");
    assert(codec);
    while (!input.atEnd())
    {
//          std::cout<<"kk";
    int i = 0;
        if(!input.atEnd())
        {
          line = in.readLine();

          line = codec->fromUnicode(line);
//        ui->textBrowser_3->setText(line);
//          line = line.toUtf8();
          insert(root, line);
//          std::cout<<line.toStdString()<<endl;
            i++;
        }
    }
    input.close();
}

// Global variable representing a vector of strings for storing search results
static vector<QString> n;

// Function to search for words in the trie based on a given prefix
void searchByPrefix(treeNode* trieNode, QString k, QString prefix, int index)
{
    if (index < prefix.length())
    {
            QChar ch = prefix[index];
            int position;
            // Handle special cases for specific characters in the prefix
            if (prefix[index] == U'і')
            {
                position = 26;
            }
            else if (prefix[index] == U'ї')
            {
                position = 27;
            }
            else if (prefix[index] == U'є')
            {
                position = 29;
            }
            else if (prefix[index] == U'ґ')
            {
                position = 32;
            }
            else if (prefix[index] == U'’')
            {
                position = 33;
            }
            else if (prefix[index] == U'-')
            {
                position = 34;
            }
            else if (prefix[index] == U'!')
            {
                position = 35;
            }
            else position = ch.unicode() - U'а';
            if (trieNode->children[position] != nullptr)
            {
                k += ch;
                // Check if the current node is the end of a word
                if (index == prefix.length() - 1 && trieNode->children[position]->isEnd)
                {
                    n.push_back(k); // Add the word to the result vector
                }
                // Recursively continue the search for the next character
                searchByPrefix(trieNode->children[position], k, prefix, index + 1);
                QString c = "";
                // Clear the last character for backtracking
                k[k.length() - 1] = NULL;
            }
    }
    else
    {
        // If the prefix is fully traversed, check all child nodes
            for (int i = 0; i < A; i++)
            {
                if (trieNode->children[i] != NULL)
                {
                    QChar c;
                    // Handle special cases for specific characters in the trie
                    if(i==26)
                    {
                        c =U'і';
                    }
                    else if(i==27)
                    {
                        c = U'ї';
                    }
                    else if(i==29)
                    {
                        c =U'є';
                    }
                    else if(i==32)
                    {
                        c =U'ґ';
                    }
                    else if(i==33)
                    {
                        c =U'’';
                    }
                    else if(i==34)
                    {
                        c =U'-';
                    }
                    else if(i==35)
                    {
                        c = U'!';
                    }
                    else
                    {
                        c = i+U'а';
                    }
                    k += c;
                    // Check if the current node is the end of a word
                    if (trieNode->children[i]->isEnd)
                    {
                        n.push_back(k);// Add the word to the result vector
                    }
                    // Recursively continue the search for the next character
                    searchByPrefix(trieNode->children[i], k, prefix, index + 1);
                    QString z = "";
                    // Clear the last character for backtracking
                    k[k.length() - 1] = NULL;
                }
            }
    }
}

// Function to clear a trie node
void del(treeNode* p)
{
    p->isEnd = false;
    for (int i = 0; i < A; i++)
        p->children[i] = NULL;
}

// Function to handle the text change event in the text edit field
void MainWindow::on_aaaa_textChanged()
{
    if(ui->aaaa->toPlainText()==' '){
        ui->aaaa->clear();
    }
    if(ui->aaaa->toPlainText()!="")
    {
    ui->textBrowser_3->clear();
    ui->textBrowser_2->clear();
    ui->textBrowser_5->clear();
    QString a =ui->aaaa->toPlainText();
    // Handle transformations based on radio button states
    if(ui->radioButton_16->isChecked())
    {
        QChar b = a.at(0);
                if(b==U'Ґ')
                {

                    b.unicode()=b.unicode()+1;
                }
                else if(a==U'І'||a==U'Ї'||a==U'Є')
                {
                    b.unicode()=b.unicode()+80;
                }
                else
                {
                    b.unicode()=b.unicode()+32;
                }
                a.remove(0,1);
                a.push_front(a);
    }
    if(ui->radioButton_17->isChecked())
    {

        int n = a.length();
        int i = 0;
        QChar b = a.at(0);
        QString s;
        while(i<n)
        {
            b = a.at(i);
        if(b==U'Ґ')
        {

            b.unicode()=b.unicode()+1;
        }
        else if(b==U'І'||b==U'Ї'||b==U'Є')
        {
            b.unicode()=b.unicode()+80;
        }
        else
        {
            b.unicode()=b.unicode()+32;
        }
        s.push_back(b);
        //text.remove(i,1);
        //text.insert(i,a);
        //text.replace(i,1,a);
        i++;
        }
        a = s;
    }
    QString u;
//    u = u.toLatin1();
//    q = q.toLatin1();
//    w = w.toLatin1();
//    e = e.toLatin1();
    //a = codec->fromUnicode(a);
    searchByPrefix(root, u, a, 0);
    //n[0] = codec->fromUnicode(n[0]);
    //n[1] = codec->fromUnicode(n[1]);
    //n[2] = codec->fromUnicode(n[2]);
    // 
    // Handle the case where the result vector size is less than 3
    if(n.size()==0)
    {
        n[0] = "";
        n[1] = "";
        n[2] = "";
    }
    else if(n.size()==1)
    {
        n[1] = "";
        n[2] = "";
    }
    else if(n.size()==2)
    {
        n[2] = "";
    }
    ui->textBrowser_3->setText(n[0]);
    ui->textBrowser_2->setText(n[1]);
    ui->textBrowser_5->setText(n[2]);
    n.clear();
    }
    else
    {
        ui->textBrowser_3->clear();
        ui->textBrowser_2->clear();
        ui->textBrowser_5->clear();
    }

}

// Function to set text according to pushButton_2 clicking
void MainWindow::on_pushButton_2_clicked()
{
    QString txt = ui->textBrowser_3->toPlainText();
    ui->aaaa->setText("");
    ui->aaaa->setText(txt);
}

// Function to set text according to pushButton_5 clicking
void MainWindow::on_pushButton_5_clicked()
{
    QString txt = ui->textBrowser_2->toPlainText();
    ui->aaaa->setText("");
    ui->aaaa->setText(txt);
}

// Function to set text according to pushButton_6 clicking
void MainWindow::on_pushButton_6_clicked()
{
    QString txt = ui->textBrowser_5->toPlainText();
    ui->aaaa->setText("");
    ui->aaaa->setText(txt);
}

// Function to check the first grammatical form
bool persha_vidm(QString tex,bool a,bool b)
{
    if(a)
    {
        if(tex.right(1)==U'а'||tex.right(1)==U'я'||tex.right(1)==U'ї'||tex.right(1)==U'ю'||tex.right(1)==U'и'||tex.right(1)==U'і'||tex.right(1)==U'у')
        {
            return 1;
        }
    }
    else if(b){
    if(tex.right(1)==U'а'||tex.right(1)==U'и'||tex.right(1)==U'і'||tex.right(1)==U'у'||tex.right(1)==U'ю'||tex.right(1)==U'я')
    {
        return 1;
    }
    }
    return 0;
}

// Function to check the second grammatical form
bool druga_vidm(QString tex,bool a,bool b)
{
    if(a)
    {
        if(tex.right(1)==U'а'||tex.right(1)==U'я'||tex.right(1)==U'о'||tex.right(1)==U'ю'||tex.right(1)==U'м'||tex.right(1)==U'і'||tex.right(1)==U'у')
        {
            return 1;
        }
    }
    else if(b){
    if(tex.right(1)==U'а'||tex.right(1)==U'и'||tex.right(1)==U'і'||tex.right(1)==U'у'||tex.right(1)==U'о'||tex.right(1)==U'м')
    {
        return 1;
    }
    }
    return 0;
}

// Function to check the third grammatical form
bool tretia_vidm(QString tex)
{

    if(tex.right(1)==U'ю' && (tex.at(tex.length()-2)==tex.at(tex.length()-3)))
    {
        return 1;
    }
    if(tex.right(1)==U'і'||tex.right(1)==U'у')
    {
        return 1;
    }
    return 0;
}

// Function to check the fourth grammatical form
bool chetverta_vidm(QString tex)
{

    if(tex.right(1)==U'я'||tex.right(1)==U'и'||tex.right(1)==U'і'||tex.right(1)==U'м'||tex.right(1)==U'у')
    {
        return 1;
    }
    return 0;
}

//build a trie
void MainWindow::on_derevtse_toggled(bool checked)
{
    derevo();
}

// Function to check if a given prefix exists in the trie
bool poshuk(QString prefix)
{
    treeNode* p = root;

        for (int i = 0; i < prefix.length(); i++)
        {
            QChar ch = prefix[i];
            int position;
            if (prefix[i] == U'і')
            {
                position = 26;
            }
            else if (prefix[i] == U'ї')
            {
                position = 27;
            }
            else if (prefix[i] == U'є')
            {
                position = 29;
            }
            else if (prefix[i] == U'ґ')
            {
                position = 32;
            }
            else if (prefix[i] == U'’')
            {
                position = 33;
            }
            else if (prefix[i] == U'-')
            {
                position = 34;
            }
            else if (prefix[i] == U'!')
            {
                position = 35;
            }
            else position = ch.unicode() - U'а';
            if (!p->children[position])
                return false;

            p = p->children[position];

        }
        return true;
}

// Function to insert a hyphen at specific positions in a word
QString defis(QString a)
{
    if(a.left(4)=="будь"&&(a.length()>4))
    {
        a.insert(4,U'-');

    }
    else if(a.right(6)=="небудь"&&(a.length()>6))
    {
        a.insert(a.length()-6,U'-');
    }
    else if(a.right(4)=="будь"&&(a.length()>4))
    {
        a.insert(a.length()-4,U'-');
    }
    else if(a.left(5)=="казна"&&(a.length()>5))
    {
        a.insert(5,U'-');
    }
    else if(a.left(6)=="хтозна"&&(a.length()>6))
    {
        a.insert(6,U'-');
    }
    return a;
}


// Function to handle the triggered event of the "action" menu
void MainWindow::on_action_triggered()
{
   ui->textBrowser->clear();
   ui->aaaa->clear();
   ui->radioButton->setChecked(0);
   ui->radioButton_2->setChecked(0);
   ui->radioButton_16->setChecked(0);
   ui->radioButton_17->setChecked(0);
   text.clear();

}

//save res to file
void MainWindow::on_pushButton_3_clicked()
{
    QString line;
    QFile output("D:\\Documents\\rec.txt");
    if (!output.exists()) {
        std::cout<<"Файл не існує";
    }
    output.open(QIODevice::Append|QIODevice::Text);

    if (!output.open(QIODevice::Append|QIODevice::Text))
    {
        std::cout<<"Cannot open file for reading"; 
    }
    QTextStream out(&output);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    out.setCodec(codec);
    assert(codec);
    line=ui->textBrowser->toPlainText();

    line = line+'.';
    out<<line<<endl;
    ui->textBrowser->clear();
    text.clear();
    output.close();
}

// Function to display an instruction
void MainWindow::on_action_4_triggered()
{
    QMessageBox s;
    s.information(this,"ІНСТРУКЦІЯ","Для початку роботи потрібно запустити застосунок та перевірити те, щоб у вас була встановлена українська розкладка для вводу та маленький регістр символів. Натисніть на поле, підпис якого відповідає напису «Введіть слово», починайте вводити слова посимвольно, якщо ж в 3 полях нижче ви побачите потрібне Вам слово – натисніть на нього. Тоді слово буде введено у поле вводу для слова. Якщо Вам потрібно ввести власну назву – натисніть на прапорець з підписом «Слово вживається в контексті власної назви», якщо Ви бажаєте ввести абревіатуру, то натисніть на прапорець з назвою «Слово вживається в контексті абревіатури», обирайте прапорець ПІСЛЯ введення слова, тоді перетворення буде коректним. Якщо ви бажаєте, щоб слово пройшло більш розширену перевірку за правилами орфографії та пунктуації – оберіть його характеристики з групи прапорців, що розташована в правій частині вікна. Для введення слова в речення натисніть кнопку з текстом «Ввести слово», якщо в реченні ще немає слів, то Ваше слово буде автоматично введено з великої літери. При натисненні кнопки з написом «Зберегти речення до файлу» речення заноситься до файлу rec.txt з автоматичним доданням крапки в кінці речення. Також користувач може скористуватися меню на верхній панелі застосунку для перегляду інструкції, відкриття програми в початковому форматі, збереження речення до файлу або ж для закриття застосунку. Також Ви можете скористуватися кнопкою з написом «Закрити застосунок», щоб завершити роботу з додатком.");
}
