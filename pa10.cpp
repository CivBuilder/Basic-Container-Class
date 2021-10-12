/// @file Container.h
/// @author Chris Catechis
/// @date 6/11/21
/// @brief This program implements the Container class.

#include "Container.h"
#include <iostream>

// function declaration phase
bool check(bool expr, const char msg[] = "");
void initialize_container(Container& container,
                          const Container::value_type list[], size_t size);
void test_constructor();
void test_size();
void test_empty();
void test_insert();
void test_erase();
void test_clear();
void test_count();
void test_contains();
void test_write();

int main() {

    std::cout << "testing Container.h functions...\n";

    // processing phase
    std::cout << "testing constructor...\n";
    test_constructor();
    std::cout << "testing size function...\n";
    test_size();
    std::cout << "testing empty function...\n";
    test_empty();
    std::cout << "testing insert function...\n";
    test_insert();
    std::cout << "testing erase function...\n";
    test_erase();
    std::cout << "testing clear function...\n";
    test_clear();
    std::cout << "testing count function...\n";
    test_count();
    std::cout << "testing contains function...\n";
    test_contains();
    std::cout << "testing write function...\n";
    test_write();

    // output phase
    std::cout << "All tests completed.\n";

    // return phase
    return 0;
}

/// Simple debugger. Compares expression with a bool
/// If check doesn't pass, displays message.
/// @param expr is expression to be tested.
/// @param msg is message to be displated in case of failure.
/// @return expression/
bool check(bool expr, const char msg[]) {
    if (expr == false) {
        std::cerr << "FAILED: " << msg << std::endl;
    }

    return expr;
}

/// initializes containers to hold a certain value size.
/// @param container is the container to be initialized.
/// @param list is an array of values to be inserted.
/// @param size is the amount of values to be inserted.
void initialize_container(Container& container,
                          const Container::value_type list[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        container.insert(list[i]);
    }
}

/// tests the constructor function.
void test_constructor() {
    Container trashcan;  // empty container.

    check(trashcan.empty() == true, "the trashcan should be empty.");
    check(trashcan.size() == 0, "the trashcan size should be 0.");
}

/// tests the size function.
void test_size() {
    Container trashcan;  // empty container.
    Container recycling;  // partially full container.
    Container dumpsterFire;  // full container.
    Container::value_type numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 10,
                                        11, 12, 13, 14, 14, 15, 19, 20
                                      };
    // values to initialize containers.

    initialize_container(recycling, numbers, 6);
    initialize_container(dumpsterFire, numbers, 20);

    check(trashcan.size() == 0, "the trashcan size should be 0.");
    check(recycling.size() == 6, "the recycling size should be 6.");
    check(dumpsterFire.size() == 20, "the dumpsterFire size should be 20.");
}

/// tests the empty function.
void test_empty() {
    Container trashcan;  // empty container.
    Container recycling;  // partially full container.
    Container dumpsterFire;  // full container.
    Container::value_type numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 10,
                                        11, 12, 13, 14, 14, 15, 19, 20
                                      };
    // values to initialize containers.

    initialize_container(recycling, numbers, 6);
    initialize_container(dumpsterFire, numbers, 20);

    check(trashcan.empty() == true, "the trashcan should be empty.");
    check(recycling.empty() == false, "the recycling shouldn't be empty.");
    check(dumpsterFire.empty() == false, "the dumpsterFire should be full.");
}

/// tests the insert function.
void test_insert() {
    Container trashcan;  // empty container.
    Container dumpsterFire;  // full container.
    Container::value_type numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 10,
                                        11, 12, 13, 14, 14, 15, 19, 20
                                      };
    // values to initialize containers.

    initialize_container(dumpsterFire, numbers, 20);

    trashcan.insert(8);
    check(trashcan.size() == 1, "the trashcan size should be 1.");
    std::cout << "Writing trashcan to test insert...\n";
    trashcan.write();
    std::cout << '\n';

    // dumpsterFire.insert(8);
    /// the program should fail due to the assert function.
    /// Comment in the above line to test.
}

/// tests the erase function.
void test_erase() {
    Container trashcan;  // empty container.
    Container recycling;  // partially full container.
    Container dumpsterFire;  // full container.
    Container::value_type numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 10,
                                        11, 12, 13, 14, 14, 15, 19, 20
                                      };
    // values to initialize containers.

    initialize_container(recycling, numbers, 6);
    initialize_container(dumpsterFire, numbers, 20);

    recycling.erase(2);
    check(recycling.contains(2) == false, "recycling should't contain 2.");

    dumpsterFire.erase(2);
    dumpsterFire.erase(8);
    dumpsterFire.erase(9);
    check(dumpsterFire.contains(2) == false, "dumpsterFire should't contain 2.");
    check(dumpsterFire.contains(8) == false, "dumpsterFire should't contain 8.");
    check(dumpsterFire.contains(9) == false, "dumpsterFire should't contain 9.");
}

/// tests the clear function.
void test_clear() {
    Container trashcan;  // empty container.

    trashcan.insert(2);  // insert 2 to have something to clear. 

    trashcan.clear();
    check(trashcan.empty() == true, "trashcan should be empty after clear.");
}

/// tests the count function.
void test_count() {
    Container recycling;  // partially full container.
    Container dumpsterFire;  // full container.
    Container::value_type numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 10,
                                        11, 12, 13, 14, 14, 15, 19, 20
                                      };
    // values to initialize containers.

    initialize_container(recycling, numbers, 6);
    initialize_container(dumpsterFire, numbers, 20);

    check(recycling.count(20) == 0, "recycling shouldn't contain 2.");
    check(dumpsterFire.count(8) == 3, "dumpsterFire should contain 3 8's.");
}

/// tests the contains function.
void test_contains(){
    Container trashcan;  // empty container.
    Container recycling;  // partially full container.
    Container dumpsterFire;  // full container.
    Container::value_type numbers[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 10,
        11, 12, 13, 14, 14, 15, 19, 20
    };
    // values to initialize containers.

    initialize_container(recycling, numbers, 6);
    initialize_container(dumpsterFire, numbers, 20);

    check(trashcan.contains(1) == false, "trashcan should't contain 1.");
    check(recycling.contains(78) == false, "recycling shouldn't contain 78.");
    check(dumpsterFire.contains(1) == true, "dumpsterFire should contain 1.");
}

/// tests the write function.
void test_write(){
    Container trashcan;  // empty container.
    Container recycling;  // partially full container.
    Container dumpsterFire;  // full container.
    Container::value_type numbers[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 10,
        11, 12, 13, 14, 14, 15, 19, 20
    };
    // values to initialize containers.

    initialize_container(recycling, numbers, 6);
    initialize_container(dumpsterFire, numbers, 20);

    trashcan.insert(777); 
    std::cout << "inserted 777 into trashcan...writing...\n";
    trashcan.write();
    std::cout << '\n';

    std::cout << "writing recycling...\n";
    recycling.write();
    std::cout << '\n';

    std::cout << "writing dumpsterFire...\n";
    dumpsterFire.write();
    std::cout << '\n';
}
