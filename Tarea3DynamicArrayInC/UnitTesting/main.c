//
//  main.c
//  Tarea3DynamicArrayInC
//
//  Created by Daniel Hernández on 1/28/19.
//  Copyright © 2019 Daniel Hernández. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "commonFunctions.h"
#include "Stack.h"
#include <cgreen/cgreen.h>



Describe(Cgreen);
BeforeEach(Cgreen) {}
AfterEach(Cgreen) {}



Ensure(Cgreen, stack_100th_value_is_10) {
        Stack stack;
        stackInit(&stack);
        for (int i = 0; i<100; i++) {
            stackAppend(&stack, 10);
        }
        assert_that(&stack.data[11]==10);
}

TestSuite *our_tests() {
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, Cgreen, stack_100th_value_is_10);
    return suite;
}



int main(){
    
    
    //return run_test_suite(our_tests(), create_text_reporter());
    //stackFree(&stack);
    exit(0);
}
