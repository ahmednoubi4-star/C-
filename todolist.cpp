#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool is_done(int x, vector <string> y) {
    bool a = false;
    for (int i = 0; i < y.size(); i++) {
        if (x - 1 == i) {
            return a = true;
        }
    }
    return a;
}
void save_to_file(vector<string>tasks, vector <bool> g) {
    ofstream file("C:\\Users\\Ahmed\\Documents\\App_to_do_list.txt");
    for (int i = 0; i < tasks.size(); i++) {
        file << tasks[i] << endl;
        file << g[i] << endl;
    }
    file.close();
}
void load_fr_file(vector<string>& tasks, vector <bool>& g) {
    ifstream file("C:\\Users\\Ahmed\\Documents\\App_to_do_list.txt");
    if (!file) return;
    string task, G;
    while (getline(file, task)) {
        getline(file, G);
        tasks.push_back(task);
        g.push_back(G == "1");
    }
    file.close();
}
int main() {
    cout << "-----------TO DO LIST -----------" << endl;
    vector <string> tasks;
    vector <bool> g;
    load_fr_file(tasks, g);
    string task;
    while (true) {
        cout << "--------------------------" << endl;
        cout << "1-> ADD new task" << endl
            << "2-> show all the tasks" << endl
            << "3-> make a task done" << endl
            << "4-> delete a task" << endl
            << "5-> to quit" << endl;
        int n;
        int u = 1;
        cout << ": ";
        cin >> n;
        system("cls");
        //cin the to do 
        switch (n) {

        case 1: {
            bool x = true;
            cin.ignore();
            for (int i = 0;tasks.size() > i;i++) {
                if (g[i] == true) {
                    cout << i + 1 << ". " << tasks[i] << "-------> DONE " << endl;
                }
                else
                    cout << i + 1 << ". " << tasks[i] << endl;
            }
            cout << "ADD new tasks  (quit to quit) " << endl;
            while (x) {
                string temp;
                getline(cin, task);
                for (int i = 0; i < task.size(); i++) {
                    temp.push_back(tolower(task[i]));
                }
                if (temp == "quit") {
                    system("cls");
                    x = false;
                }
                else if(temp == ""){
                    
                }
                else{
                    tasks.push_back(task);
                    g.push_back(false);
                }
                    
            }
            save_to_file(tasks, g);
            break;
        }
              //print the to do list
        case 2:
            cout << "---------your TO DO list for today---------" << endl;
            for (int i = 0; i < tasks.size(); i++) {
                if (g[i] == true) {
                    cout << i + 1 << ". " << tasks[i] << "-------> DONE " << endl;
                }
                else {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
            }
            cout << "Keep it up !" << endl;
            break;
            //make a task done
        case 3: {
            int o;
            bool r = true;
            cout << " enter the number of  task you did (0 : quit)  " << endl;
            for (int i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". " << tasks[i] << endl;
            }
            while (r) {
                int s = 0;
                cin >> o;
                s += o;
                if (o == 0) {
                    r = false;
                }
                else if (s > tasks.size()) {
                    cout << "this number of task dosn't exist ." << endl;
                }
                else if (is_done(s, tasks)) {
                    g[s - 1] = true;
                }
            }
            save_to_file(tasks, g);
            system("cls");

            break;
        }
        case 4: {
            cout << "Enter task number to delete (0: quit, 99: clear all): ";
            int y;
            bool p = true;
            for (int i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". " << tasks[i] << endl;
            }
            while (p) {
                cout << " : ";cin >> y;
                int x = 0;
                x += y;
                if (y == 0) {
                    p = false;
                    system("cls");
                }
                else if (x == 99) {
                    tasks.clear();
                    g.clear();
                    p = false;
                }
                else {
                    tasks.erase(tasks.begin() + (x - 1));
                    g.erase(g.begin() + x - 1);
                    cout << "------------------------------" << endl
                        << "0 to quit " << endl;
                    for (int i = 0; i < tasks.size(); i++) {
                        cout << i + 1 << ". " << tasks[i] << endl;
                    }
                }
            }
            save_to_file(tasks, g);
            break;
        }
        case 5:
        { return false; }
        default: {
            cout << "the number does't exist" << endl;
            break;
        }
        }
    }
    return 0;
}