// //并查集
// //并查集
// //并查集

// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <list>
// #include <unordered_map>
// #include <stack>
// #include <map>

// using namespace std;

// class element
// {
// public:
//     string value;

// public:
//     element(string value);
// };

// element::element(string value)
// {
//     this->value = value;
// }

// class unionFindSet
// {
// public:
//     //每个类对应一个结构类
//     map<string, element> elementMap;
//     // key 某个元素value该元素的父
//     map<element, element> fatherMap;
//     // key 某个集合的代表元素，value为该集合的大小
//     map<element, int> rankMap;

// public:
//     unionFindSet(vector<string> arr);
//     element findHead(element item);
//     bool isSameSet(string a, string b);
//     void unionSet(string a, string b);
// };

// unionFindSet::unionFindSet(vector<string> arr)
// {
//     for (int i = 0; i < arr.size(); i++)
//     {
//         element item(arr[i]);
//         elementMap[arr[i]] = item;
//         fatherMap[item] = item;
//         rankMap[item] = 1;
//     }
// }

// element unionFindSet::findHead(element item)
// {
//     stack<element> path;
//     while (item != fatherMap.at(item))
//     {
//         path.push(item);
//         item = fatherMap.at(item);
//     }
//     while (!path.empty())
//     {
//         fatherMap[path.top()] = item;
//         path.pop();
//     }
//     return item;
// }

// bool unionFindSet::isSameSet(string a, string b)
// {
//     if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
//     {
//         return findHead(elementMap.at(a)) == findHead(elementMap.at(b));
//     }
//     return false;
// }

// void unionFindSet::unionSet(string a, string b)
// {
//     if (elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end())
//     {
//         element aF = findHead(elementMap.at(a));
//         element bF = findHead(elementMap.at(b));
//         if (aF != bF)
//         {
//             element big = rankMap.at(aF) >= rankMap.at(bF) ? aF : bF;
//             element small = (big == aF ? bF : aF);
//             fatherMap.insert(small, big);
//             rankMap.insert(pair<element, int>(big, rankMap.at(aF) + rankMap.at(bF)));
//             rankMap.erase(small);
//         }
//     }
// }

// int main()
// {
//     system("chcp 65001");
//     vector<string> arr;
//     arr.push_back("123");
//     arr.push_back("456");
//     arr.push_back("789");
//     arr.push_back("abc");
//     arr.push_back("def");
//     arr.push_back("ghi");
//     unionFindSet set(arr);
//     system("pause");
//     return 0;
// }