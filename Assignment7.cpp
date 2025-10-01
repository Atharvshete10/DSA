#include <iostream>
#include <string>
using namespace std;
template<typename T>
class Stack {
private:
T *array;
int topIndex;
int n;
public:
// Constructor
Stack(int n = 0) {
this->n = n;
array = new T[n];
topIndex = -1;
}
// Destructor
~Stack() {
delete[] array;
}
// Copy constructor
Stack(Stack& other) {
n = other.n;
topIndex = other.topIndex;
array = new T[n];
for (int i = 0; i <= topIndex; i++) {
array[i] = other.array[i];
}
}
// Assignment operator
Stack& operator=(Stack& other) {
if (this == &other) return *this;
delete[] array;
n = other.n;
topIndex = other.topIndex;
array = new T[n];
for (int i = 0; i <= topIndex; i++) {
array[i] = other.array[i];
}
return *this;
}
void push(T x) {
array[++topIndex] = x;
}
void pop() {
topIndex--;
}
T top() {
return array[topIndex];
}
bool isempty() {
return topIndex == -1;
}
bool isfull() {
return topIndex == n - 1;
}
};
// check if digit
bool isDigit(char ch) {
return ch >= '0' && ch <= '9';
}
// precedence
int precedence(char op) {
if (op == '+' || op == '-') return 1;
if (op == '*' || op == '/') return 2;
if (op == '^') return 3;
return 0;
}
// Infix → Postfix
string infixToPostfix(string infix) {
Stack<char> st(infix.size());
string postfix = "";
for (size_t i = 0; i < infix.size(); i++) {
char ch = infix[i];
if (ch == ' ') continue;
if (isDigit(ch)) {
while (i < infix.size() && isDigit(infix[i])) {
postfix += infix[i];
i++;
}
postfix += ' ';
i--;
}
else if (ch == '(') {
st.push(ch);
}
else if (ch == ')') {
while (!st.isempty() && st.top() != '(') {
postfix += st.top();
postfix += ' ';
st.pop();
}
if (!st.isempty()) st.pop(); // remove '('
}
else { // operator
while (!st.isempty() && precedence(st.top()) >= precedence(ch)) {
postfix += st.top();
postfix += ' ';
st.pop();
}
st.push(ch);
}
}
while (!st.isempty()) {
postfix += st.top();
postfix += ' ';
st.pop();
}
return postfix;
}
// power function
int power(int a, int b) {
int result = 1;
for (int i = 0; i < b; i++) result *= a;
return result;
}
// Evaluate Postfix
int evaluatePostfix(string postfix) {
Stack<int> st(postfix.size());
int i = 0;
while (i < (int)postfix.size()) {
if (postfix[i] == ' ') {
i++;
continue;
}
if (isDigit(postfix[i])) {
int num = 0;
while (i < (int)postfix.size() && isDigit(postfix[i])) {
num = num * 10 + (postfix[i] - '0');
i++;
}
st.push(num);
}
else {
int val2 = st.top(); st.pop();
int val1 = st.top(); st.pop();
switch (postfix[i]) {
case '+': st.push(val1 + val2); break;
case '-': st.push(val1 - val2); break;
case '*': st.push(val1 * val2); break;
case '/': st.push(val1 / val2); break;
case '^': st.push(power(val1, val2)); break;
}
i++;
}
}
return st.top();
}
/// independent function (not part of class)
template<typename T>
Stack<T> sort_stack(Stack<T> s, int n) {
Stack<T> temp(n);
while (!s.isempty()) {
T temp1 = s.top();
s.pop();
while (!temp.isempty() && temp1 > temp.top()) {
s.push(temp.top());
temp.pop();
}
temp.push(temp1);
}
return temp;
}
int main() {
string infix;
cout << "Enter infix expression: ";
getline(cin, infix);
string postfix = infixToPostfix(infix);
cout << "Postfix: " << postfix << endl;
int result = evaluatePostfix(postfix);
cout << "Evaluation: " << result << endl;
return 0;
}