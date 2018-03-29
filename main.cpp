#include <iostream>
#include <vector>
#include <string>

using namespace std;




string input;

string clean_string (string input) {
    string res;
    for (int i = 0; i < input.length(); i++) {
        if(input[i] != ' ')
            res.push_back (input[i]);
    }
    return res;
}

int ctoi (char c) { return (int) c - '0'; };

int evaluator (string equation) {
    vector<char> val;
}

string format (string input) {

    string art = clean_string(input);
    if (art.length() == 1)
        return input;
    cout << "to be formatted : " << art << '\n';
    string res;
    vector<char> val;
    vector<char> op;

    int op_state = 0;

    int lefbr = 0;
    int rigbr = 0;
    string br = "";

    for (int i = 0; i < art.length() || br != ""; i++) {

        if (op_state == 2) {   
            if (rigbr == lefbr && lefbr != 0) {
                res = res + format(br);
                op_state = 0;
                lefbr = 0;
                rigbr = 0;
                br = "";
                if (op.size() != 0)
                     res.push_back(op.back());
            } else {
                if(art[i] == '(') {
                     op_state = 2;
                     lefbr++;
                     if (lefbr > 1) 
                         br.push_back(art[i]);
                 } else if(art[i] == ')'){
                     rigbr++;
                     if (rigbr != lefbr) 
                         br.push_back(art[i]);
                } else 
                     br.push_back (art[i]);
            }
        } 
        
        if (op_state == 0 || op_state == 1) {
            if(art[i] == '(') {
                op_state = 2;
                lefbr++;
            }
            else if (art[i] < '0' || art[i] > '9') {
                op.push_back(art[i]);
                op_state = 1;
            }
            else {
                res.push_back(art[i]);
                if ( op_state == 1) {
                    res.push_back(op.back());
                    op.pop_back();
                }
                op_state = 0;
            }   
        }
    
    }
    return res;
}


int main() {

    do {
        cout << "[math]> ";
        getline(cin, input);
        cout <<  format (input) << '\n';
    } while (input != "exit");
    //input = "(1 * (2 - 2)) + (1 - 3) * 2";
}