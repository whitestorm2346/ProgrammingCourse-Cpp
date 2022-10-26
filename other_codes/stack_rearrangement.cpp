#include <iostream>
#include <string>
#include <stack>
#include <set>

#define PRINT '1'
#define PUSH '2'
#define POP '3'

std::set<std::string> result;

void rearrangement(std::string, std::string, std::string, std::stack<char>);

int main(){
    std::string input = "BCAD";
    std::stack<char> stack;

    rearrangement(input, "", "", stack);

    return 0;
}

void rearrangement(
    std::string input,
    std::string output,
    std::string step,
    std::stack<char> stack){
    if(input == ""){
        while(!stack.empty()){ // pop out all elements in stack
            output += stack.top();
            stack.pop();
            step += POP;
        }

        if(!result.count(output)){ // print out the result
            for(int i = 0; i < step.size(); i++){
                switch(step[i]){
                    case PRINT:
                        std::cout<< "print ";
                        break;

                    case PUSH:
                        std::cout<< "push ";
                        break;

                    case POP:
                        std::cout<< "pop ";
                        break;
                }
            }

            std::cout<< "\n--> " << output << "\n\n";
            result.insert(output);
        }
    }
    else{
        std::string tmp_in = input;
        std::string tmp_out = output;
        std::string tmp_stp = step;
        std::stack<char> tmp_stk = stack;

        // print
        tmp_out += tmp_in[0];
        tmp_in = tmp_in.substr(1, tmp_in.size() - 1);
        tmp_stp += PRINT;

        rearrangement(tmp_in, tmp_out, tmp_stp, tmp_stk);

        tmp_in = input;
        tmp_out = output;
        tmp_stp = step;

        // push
        tmp_stk.push(tmp_in[0]);
        tmp_in = tmp_in.substr(1, tmp_in.size() - 1);
        tmp_stp += PUSH;

        rearrangement(tmp_in, tmp_out, tmp_stp, tmp_stk);

        tmp_in = input;
        tmp_stk = stack;
        tmp_stp = step;

        // pop
        if(!tmp_stk.empty()){
            tmp_out += tmp_stk.top();
            tmp_stk.pop();
            tmp_stp += POP;

            rearrangement(tmp_in, tmp_out, tmp_stp, tmp_stk);
        }
    }
}
