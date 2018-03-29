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

string format (string input) {

    string art = clean_string(input);
    cout << "to be formatted" << art << '\n';
    string res;
    vector<char> val;
    vector<char> op;

    int op_state = 0;

    int lefbr = 0;
    int rigbr = 0;
    string br = "";

    for (int i = 0; i < art.length(); i++) {
        cout << "current input" << art[i] << '\n';
        cout << "current res : " << res << '\n';
        cout << "current br : " << br << "\n\n";


        if (op_state == 2) {   
            if (rigbr == lefbr && lefbr != 0) {
                res = res + format(br);
                op_state = 0;
                lefbr = 0;
                rigbr = 0;
                br = "";
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
    //cin >> art;
    input = "(1 * 2) + (2 + 2) + 3";

    
    cout << format (input);


}