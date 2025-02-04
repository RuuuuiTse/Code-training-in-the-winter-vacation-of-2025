#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    // 读取 n 和 m
    int n, m;
    cin >> n >> m;

    // 读取变量定义
    map<string, string> variables;
    for (int i = 0; i < n; ++i) {
        string varName;
        string varValue;
        cin >> varName >> varValue;
        variables[varName] = varValue;
    }

    // 读取句子并替换占位符
    cin.ignore(); // 忽略换行符
    for (int i = 0; i < m; ++i) {
        string sentence;
        getline(cin, sentence); // 读取一行句子

        string result; // 存储替换后的结果
        int pos = 0;   // 当前处理的位置

        while (pos < sentence.length()) {
            // 查找 '{' 的位置
            size_t start = sentence.find('{', pos);
            if (start == string::npos) {
                // 如果没有找到 '{'，直接添加剩余部分
                result += sentence.substr(pos);
                break;
            }

            // 添加 '{' 之前的部分
            result += sentence.substr(pos, start - pos);

            // 查找 '}' 的位置
            size_t end = sentence.find('}', start);
            if (end == string::npos) {
                // 如果没有找到 '}'，直接添加剩余部分
                result += sentence.substr(start);
                break;
            }

            // 提取占位符中的变量名
            string varName = sentence.substr(start + 1, end - start - 1);

            // 查找变量值并替换
            if (variables.find(varName) != variables.end()) {
                result += variables[varName]; // 替换为变量值
            } else {
                result += "{" + varName + "}"; // 如果变量未定义，保留原占位符
            }

            // 更新处理位置
            pos = end + 1;
        }

        // 输出替换后的句子
        cout << result << endl;
    }

    return 0;
}