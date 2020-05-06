/*
    Problem: tìm và sắp xếp theo thứ tụ từ điển tất cả các chuối nhị phân có độ dài 5 sao cho không có 2 số 1 nào đứng cạnh nhau
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

vector < vector < int > > bin;
vector < vector < int > > Breath_res, Depth_res;
int color[N];
vector < int > start_stage, end_stage;
int x[N];

int Pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int res = 1;
    for (int i = 1; i <= b; i++) {
        res *= a;
    }
    return res;
}

int To_Dec(vector < int > x) {
    int res = 0;
    res = x[0] * Pow(2, 4) + x[1] * Pow(2, 3) + x[2] * Pow(2, 2) + x[3] * Pow(2, 1) + x[4] * Pow(2, 0); 
    return res;
}

void Binary(int id) {
    if (id == 6) {
        vector < int > tmp;
        for (int i = 1; i <= 5; i++) {
            tmp.push_back(x[i]);
        }
        color[To_Dec(tmp)] = 0;
        bin.push_back(tmp);
    } else {
        for (int i = 0; i <= 1; i++) {
            x[id] = i;
            Binary(id + 1);
        }
    }
}

bool Identical(vector < int > x, vector < int > y) {
    int res = 0;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] != y[i]) {
            return false;
        }
    }
    return true;
}

bool Valid(vector < int > x) {
    for (int i = 0; i < x.size() - 1; i++) {
        if (x[i] == 1 && x[i + 1] == 1) {
            return false;
        }    
    }
    return true;
}

bool Neightbour(vector < int > x, vector < int > y) {
    if (Valid(x) && Valid(y)) {
        return true;
    } else {
        return false;
    }
}

vector < vector < int > > Find_Neightbour(vector < int > cur_node) {
    vector < vector < int > > res;
    for (int i = 0; i < bin.size(); i++) {
        vector < int > tmp = bin[i];
        if (Valid(cur_node) && Valid(tmp) && Neightbour(cur_node, tmp)) {
            res.push_back(tmp);
        }
    }
    return res;
}

bool Strategy(vector < int > prev, vector < int > cur, vector < vector < int > > listt) {
    int x = To_Dec(prev);
    int y = To_Dec(cur);
    vector < int > dec;
    for (int i = 0; i < listt.size(); i++) {
        int tmp = To_Dec(listt[i]);
        dec.push_back(tmp);
    }
    if (x >= y) return false;
    int z = 0;
    sort(dec.begin(), dec.end());
    for (int i = 0; i < dec.size(); i++) {
        if (dec[i] > x) {
            z = dec[i];
            break;
        }
    }
    if (z == y) {
        return true;
    } else {
        return false;
    }
}

vector < vector < int > > Breath_Search(vector < int > start_stage, vector < int > end_stage) {
    vector < vector < int > > res_tree;

    res_tree.push_back(start_stage);

    queue < vector < int > > q;
    q.push(start_stage);

    while (q.empty() == false) {
        vector < int > cur_node = q.front();
        q.pop();
        if (Identical(cur_node, end_stage)) {
            return (res_tree);
        } else {
            vector < vector < int > > neightbours = Find_Neightbour(cur_node);
            for (int i = 0; i < neightbours.size(); i++) {
                vector < int > neightbour = neightbours[i];
                if (true) {
                    if (Strategy(cur_node, neightbour, neightbours)) {
                        q.push(neightbour);
                        color[To_Dec(neightbour)] = 1;
                        res_tree.push_back(neightbour);
                    }
                }
            }
        }
    }
    vector < vector < int > > fail;
    return (fail);
}

vector < vector < int > > Depth_Search(vector < int > start_stage, vector < int > end_stage) {
    vector < vector < int > > res_tree;

    res_tree.push_back(start_stage);

    stack < vector < int > > q;
    q.push(start_stage);

    while (q.empty() == false) {
        vector < int > cur_node = q.top();
        q.pop();
        if (Identical(cur_node, end_stage)) {
            return (res_tree);
        } else {
            vector < vector < int > > neightbours = Find_Neightbour(cur_node);
            for (int i = 0; i < neightbours.size(); i++) {
                vector < int > neightbour = neightbours[i];
                if (true) {
                    if (Strategy(cur_node, neightbour, neightbours)) {
                        q.push(neightbour);
                        color[To_Dec(neightbour)] = 1;
                        res_tree.push_back(neightbour);
                    }
                }
            }
        }
    }
    vector < vector < int > > fail;
    return (fail);
}

void Print(vector < vector < int > > res) {
    cout << "Path length: " << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        vector < int > tmp = res[i];
        for (int j = 0; j < 5; j++) {
            cout << tmp[j];
        }
        cout << endl;
    }
}

int main()
{

    //  Tạo không gian mẫu: gồm tất cả các dãy nhị phân độ dài 5:
    Binary(1);

    //  Đưa ra trạng thái bắt đầu:
    for (int i = 1; i <= 5; i++) {
        start_stage.push_back(0);
    }

    //  Đưa ra trạng thái kết thúc:
    for (int i = 1; i <= 5; i++) {
        if (i % 2 == 0) end_stage.push_back(0);
        else end_stage.push_back(1);
    }

    //  Tìm kiếm kết quả: 
    Breath_res = Breath_Search(start_stage, end_stage);
    Depth_res = Depth_Search(start_stage, end_stage);

    //  Đưa ra kết quả:
    if (Breath_res.size() == 0) {
        cout << "Thuat toan Tim kiem chieu rong khong cho ra ket qua!\n";
    } else {
        cout << "Thuat toan tim kiem theo chieu rong: \n";
        Print(Breath_res);
    }
    if (Depth_res.size() == 0) {
        cout << "Thuat toan Tim kiem chieu sau khong cho ra ket qua!\n";
    } else {
        cout << "Thuat toan tim kiem theo chieu sau: \n";
        Print(Depth_res);
    }

    return 0;
}