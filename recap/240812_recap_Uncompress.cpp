// Uva 24941 Uncompress
// 題目細節： 每個被uncompress的那個字會移動到最前面，ex.
/*
當然，我很樂意更詳細地解釋這個過程。讓我們一步一步地分析整個解壓縮過程，特別關注 "And 4 6" 這部分。
讓我們從頭開始，逐字分析輸入：
    "Dear" - 添加到列表：[Dear]
    "Sally" - 添加到列表前面：[Sally, Dear]
    "Please" - 添加到列表前面：[Please, Sally, Dear]
    "please" - 添加到列表前面：[please, Please, Sally, Dear]
    "do" - 添加到列表前面：[do, please, Please, Sally, Dear]
    "it" - 添加到列表前面：[it, do, please, Please, Sally, Dear]
    "1" - 引用第1個單詞 "it"，輸出 "it"，移動到前面：[it, do, please, Please, Sally, Dear]（沒有變化，因為已經在前面）
    "would" - 添加到列表前面：[would, it, do, please, Please, Sally, Dear]
    "4" - 引用第4個單詞 "please"，輸出 "please"，移動到前面：[please, would, it, do, Please, Sally, Dear]
    "Mary" - 添加到列表前面：[Mary, please, would, it, do, Please, Sally, Dear]
    "very" - 添加到列表前面：[very, Mary, please, would, it, do, Please, Sally, Dear]
    "1" - 引用第1個單詞 "very"，輸出 "very"，移動到前面：[very, Mary, please, would, it, do, Please, Sally, Dear]（沒有變化）
    "much" - 添加到列表前面：[much, very, Mary, please, would, it, do, Please, Sally, Dear]

現在我們來到關鍵的 "And 4 6" 部分：
    "And" - 添加到列表前面：[And, much, very, Mary, please, would, it, do, Please, Sally, Dear]
    "4" - 引用第4個單詞 "Mary"，輸出 "Mary"，移動到前面：[Mary, And, much, very, please, would, it, do, Please, Sally, Dear]
    "6" - 現在引用第6個單詞 "would"，輸出 "would"，移動到前面：[would, Mary, And, much, very, please, it, do, Please, Sally, Dear]
所以 "And 4 6" 實際上解壓縮為 "And Mary would"。

這裡的關鍵點是：
    每次我們使用一個數字引用時，相應的單詞不僅被輸出，還被移動到列表的最前面。
    這種移動會改變列表中所有其他單詞的位置。
    當我們處理 "6" 時，"would" 已經不再是第6個單詞了，因為在處理 "4" 時，"Mary" 被移到了最前面，改變了 "would" 的位置。
*/
#include <bits/stdc++.h>
using namespace std;

void insertWord(string wordTmp, vector<string>& words){
    string wordToPut = wordTmp;
    //先挖格子，不然會不夠！
    words.push_back(wordTmp);
    for(int i = words.size()-1; i > 0; i--){
        words[i] = words[i-1];
    } 
    words[0] = wordToPut;
}

void printWord(string wordTmp, vector<string>& words){
    insertWord(wordTmp, words);
    printf("%s", wordTmp.c_str());
}

void printNum(int pivot, vector<string>& words){
    string output = words[pivot-1];
    printf("%s", output.c_str());
    for(int i = pivot-1; i > 0; i--){
        words[i] = words[i-1];
    }
    words[0] = output;
}

int main(){
    string s;
    vector<string> words;
    while(getline(cin, s)){
        if(s == "0") break;
        s += '\n';
        string wordTmp = "";
        int numTmp = 0;
        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])){
                wordTmp += s[i];
            }
            else if(isdigit(s[i])){
                numTmp = numTmp * 10 + s[i] - '0';
            }
            else{
                if(wordTmp != "") printWord(wordTmp, words); 
                else if(numTmp) printNum(numTmp, words);
                wordTmp = "";
                numTmp = 0;
                printf("%c", s[i]);
            }
        }
    }
}