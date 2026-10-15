// 1 から N までの約数を列挙（vec[i]: i の約数が全部入っているリスト）
vector<int> vec[1000009];
for(int i=1; i<=N; i++) {
    for (int j=i; j<=N; j+=i) vec[j].push_back(i);
}

