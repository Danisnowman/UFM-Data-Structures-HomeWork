// Java program to construct an expression tree

import java.util.Stack;

// Java program for expression tree
class Node {

    char value;
    Node left, right;

    Node(char item) {
        value = item;
        left = right = null;
    }
}

class ExpressionTree {

    // A utility function to check if 'maybe_operator'
    // is an operator

    boolean isOperator(char maybe_operator) {
        return (maybe_operator == '+' ||
                maybe_operator == '-' ||
                maybe_operator == '*' ||
                maybe_operator == '/' ||
                maybe_operator == '^');
    }

    // Utility function to print tree inorder traversal
    void inorder(Node tree) {
        if (tree != null) {
            inorder(tree.left);
            System.out.print(tree.value + " ");
            inorder(tree.right);
        }
    }

    // Returns root of constructed tree for given
    // postfix expression
    Node constructTree(char postfix[]) {
        Stack<Node> st = new Stack();
        Node t, t1, t2;

        // Traverse through every character of
        // input expression
        for (int i = 0; i < postfix.length; i++) {

            // If operand, simply push into stack
            if (!isOperator(postfix[i])) {
                t = new Node(postfix[i]);
                st.push(t);
            } else // operator
            {
                t = new Node(postfix[i]);

                // Pop two top nodes
                // Store top
                t1 = st.pop();	 // Remove top
                t2 = st.pop();

                // make them children
                t.right = t1;
                t.left = t2;

                // System.out.println(t1 + "" + t2);
                // Add this subexpression to stack
                st.push(t);
            }
        }

        // only element will be root of expression
        // tree
        t = st.peek();
        st.pop();

        return t;
    }
}

