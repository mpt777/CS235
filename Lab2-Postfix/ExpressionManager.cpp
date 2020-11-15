#include "ExpressionManager.h"
#include <vector>
#include <sstream>
#include <ctype.h>


bool process_operator(stack<string> &operandStack, string &postfixExpression, string &currentOperand) {
  if (operandStack.empty() || operandStack.top() == "(" || operandStack.top() == "{" || operandStack.top() == "[" || currentOperand == "(" || currentOperand == "{" || currentOperand == "[") {
      operandStack.push(currentOperand);
      return(true);
  } else if ( currentOperand == ")" || currentOperand == "}" || currentOperand == "]") {
      while((currentOperand == ")" && operandStack.top() != "(") || (currentOperand == "}" && operandStack.top() != "{") || (currentOperand == "]" && currentOperand == "[")) {
        postfixExpression.append(operandStack.top() + " ");
     	 operandStack.pop();
          if (operandStack.empty()) { // needs to match as well
              return (false);
          }
        }
      operandStack.pop();
      return(true);
    } else {
        int current_PRECEDENCE = -1;
        int top_PRECEDENCE = -1;
        bool flopTest = false;
        string topPrecString = "*/%";
        string lowPrecString = "+-";

        if(topPrecString.find(currentOperand) != string::npos) {
            current_PRECEDENCE = 2;
        } else if (lowPrecString.find(currentOperand) != string::npos) {
            current_PRECEDENCE = 1;
        } else {
            current_PRECEDENCE = 0;
        }

        if(operandStack.size() != 0) {
            if (topPrecString.find(operandStack.top()) != string::npos) {
                top_PRECEDENCE = 2;
            } else if (lowPrecString.find(operandStack.top()) != string::npos) {
                top_PRECEDENCE = 1;
            } else {
                top_PRECEDENCE = 0;
            }
        }

        while(current_PRECEDENCE <= top_PRECEDENCE && operandStack.size() != 0) {
            flopTest = true;
            if(topPrecString.find(operandStack.top()) != string::npos) {
                top_PRECEDENCE = 2;
            } else if (lowPrecString.find(operandStack.top()) != string::npos) {
                top_PRECEDENCE = 1;
            } else {
                top_PRECEDENCE = 0;
            }
            if(current_PRECEDENCE > top_PRECEDENCE) {
                operandStack.push(currentOperand);
                current_PRECEDENCE = top_PRECEDENCE;
                break;
            }
            if(operandStack.empty()){
                operandStack.push(currentOperand);
            }
            postfixExpression.append(operandStack.top() + " ");
            operandStack.pop();

        }
        if(current_PRECEDENCE > top_PRECEDENCE) {
            operandStack.push(currentOperand);
        }
        //operandStack.push(currentOperand);
        if(operandStack.empty() && flopTest){
            operandStack.push(currentOperand);
        }
        return(true);
    }
}

bool ExpressionManager::isBalanced(string expression){
	cout << "isBalanced: " << expression << endl;

	stack<char> isBalancedStack;
	bool isBalancedBool = true;
	int i=0;
	char testChar = 'a';

	while(isBalancedBool == true && i < expression.length()) {
		testChar = expression.at(i);
		if (testChar == '(' || testChar == '[' || testChar == '{') {
			isBalancedStack.push(expression.at(i));	
		} else if (testChar == ')' || testChar == ']' || testChar == '}') {
			if(!isBalancedStack.empty()) {
				if(testChar == ')' && isBalancedStack.top() == '(') {
					isBalancedStack.pop();
				} else if(testChar == ']' && isBalancedStack.top() == '[') {
					isBalancedStack.pop();
				} else if(testChar == '}' && isBalancedStack.top() == '{') {
					isBalancedStack.pop();
				} else {
					isBalancedBool = false;
				}
			} else {
					isBalancedBool = false;
			}	
		}
		i += 1;
	}

	if(!isBalancedStack.empty()) {
		isBalancedBool = false;
	}
	
	return isBalancedBool; 
}




string ExpressionManager::postfixToInfix(string postfixExpression){
	cout << "postfixToInfix: " << postfixExpression << endl;
	        stack<string> postfixStack;
        vector<string> tokenVector;
        stringstream ss(postfixExpression);

        while (getline(ss, postfixExpression, ' ')) {
            tokenVector.push_back(postfixExpression);
        }

            for (int i = 0; i < tokenVector.size(); i++) {
                string currentToken = tokenVector.at(i);

                if (isdigit(currentToken.at(0))) {
									if(currentToken.find('.') != string::npos) {
               			 return("invalid");
            		}
                    postfixStack.push(currentToken);

                } else if (currentToken.at(0) == '+' || currentToken.at(0) == '-' || currentToken.at(0) == '*' ||
                           currentToken.at(0) == '/' || currentToken.at(0) == '%') {

                    if (i == 0) {
                        return("invalid");
                    }

										if(postfixStack.size() < 2){
                			return("invalid");
            				}

                    string rhs = postfixStack.top();
                    postfixStack.pop();
                    string lhs = postfixStack.top();
                    postfixStack.pop();

                    string tempString = "";

                    tempString = "( " + lhs + " " + currentToken + " " + rhs + " )";

                    postfixStack.push(tempString);
                } else {
                    return("invalid");
                }
            }

		    if(postfixStack.top().length() < 2 || postfixStack.size() > 1){
        return("invalid");
    }

        return(postfixStack.top());

}

string ExpressionManager::postfixEvaluate(string postfixExpression){
	cout << "postfixEvaluate: " << postfixExpression << endl;
	       stack<int> operandStack;
        vector<string> tokenVector;
        stringstream ss(postfixExpression);

        while (getline(ss, postfixExpression, ' ')) {
            tokenVector.push_back(postfixExpression);
        }

        for (int i=0; i < tokenVector.size(); i++) {
            string currentToken = tokenVector.at(i);
            if (isdigit(currentToken.at(0))) {
                int currentTokenInt  = stoi(currentToken);
                operandStack.push(currentTokenInt);
            } else {
							if (i==0) {
						 		return("invalid");
          		}
						
						     if(operandStack.size() < 2){
                return("invalid");
            }

                int rhs = operandStack.top();
                operandStack.pop();
                int lhs = operandStack.top();
                operandStack.pop();
                int result = -999;


                switch(currentToken.at(0)) {
                    case '+' : result = lhs + rhs;
                        break;
                    case '-' : result = lhs - rhs;
                        break;
                    case '*' : result = lhs * rhs;
                        break;
                    case '/' : if(rhs==0) {
                        return("invalid");
                    	}	result = lhs / rhs;
                        break;
                    case '%' : result = lhs % rhs;
                        break;
                    default:
                        return("invalid");
                }
                operandStack.push(result);
            }	
        }
				
        int finalResult = operandStack.top();
        string finalResultStr = to_string(finalResult);
        return (finalResultStr);
}

string ExpressionManager::infixToPostfix(string infixExpression){
	cout << "infixToPostfix: " << infixExpression << endl;

	string postfixExpression;
	stack<string> operandStack;
	vector<string> tokenVector;
	stringstream ss(infixExpression);
	string allOperands = "+-*/%(){}[]";
	while (getline(ss, infixExpression, ' ')) {
    tokenVector.push_back(infixExpression);
  }

	for (int i = 0; i < tokenVector.size(); i++) {
  	string currentToken = tokenVector.at(i);
		  if(currentToken.find('.') != string::npos) {
                return("invalid");
            }
	
 	if(currentToken == ""){
            return("invalid");
        }

  	if (isdigit(currentToken.at(0))) {
    	postfixExpression.append(currentToken + " ");
		 	} else if (allOperands.find(currentToken) != string::npos) {
        if (!process_operator(operandStack,postfixExpression,currentToken)) {
            return("invalid");
        }
		} else {
    	return("invalid");
    	}
  	}
if(!operandStack.empty()) {
    for(int i = 0; i<=operandStack.size(); i++) {
        postfixExpression.append(operandStack.top() + " ");
        operandStack.pop();
    }
}
        string allParen = "[]{}()";
    for (int i=0; i<postfixExpression.length(); i++) {
        if (allParen.find(postfixExpression.at(i)) != string::npos) {
            return ("invalid");
        }
    }

	postfixExpression.pop_back();
if(ExpressionManager::postfixEvaluate(postfixExpression) != "invalid"){
	return(postfixExpression);
} else {
	return("invalid");
}
    
}

