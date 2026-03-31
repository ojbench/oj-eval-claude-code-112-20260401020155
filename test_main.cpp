#include <iostream>
#include "src.hpp"

using namespace std;

void test_function(int argc, char** argv) {
    cout << "argc = " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "] = \"" << argv[i] << "\"" << endl;
    }
}

int main() {
    // Test case 1: Basic command
    cout << "Test 1: ls -al /usr/bin" << endl;
    final::arguments args1("ls -al /usr/bin");
    cout << "argc = " << args1.argc() << endl;
    for (int i = 0; i < args1.argc(); i++) {
        cout << "argv[" << i << "] = \"" << args1.argv()[i] << "\"" << endl;
    }
    cout << endl;

    // Test case 2: Single argument
    cout << "Test 2: command" << endl;
    final::arguments args2("command");
    cout << "argc = " << args2.argc() << endl;
    for (int i = 0; i < args2.argc(); i++) {
        cout << "argv[" << i << "] = \"" << args2.argv()[i] << "\"" << endl;
    }
    cout << endl;

    // Test case 3: Multiple spaces
    cout << "Test 3: cmd  arg1   arg2" << endl;
    final::arguments args3("cmd  arg1   arg2");
    cout << "argc = " << args3.argc() << endl;
    for (int i = 0; i < args3.argc(); i++) {
        cout << "argv[" << i << "] = \"" << args3.argv()[i] << "\"" << endl;
    }
    cout << endl;

    // Test case 4: Empty string
    cout << "Test 4: empty string" << endl;
    final::arguments args4("");
    cout << "argc = " << args4.argc() << endl;
    cout << endl;

    // Test case 5: Using shell class
    cout << "Test 5: Using shell class" << endl;
    final::shell sh;
    sh.run(1, "ls -al /usr/bin", test_function);
    sh.subprocessExit(1, 0);
    cout << endl;

    // Test case 6: Leading space
    cout << "Test 6: leading space" << endl;
    final::arguments args6(" cmd arg");
    cout << "argc = " << args6.argc() << endl;
    for (int i = 0; i < args6.argc(); i++) {
        cout << "argv[" << i << "] = \"" << args6.argv()[i] << "\"" << endl;
    }
    cout << endl;

    return 0;
}
