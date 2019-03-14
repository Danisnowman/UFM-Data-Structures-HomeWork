import java.util.Stack;

class Node {

    char value;
    Node left, right;

    Node(char item) {
        value = item;
        left = right = null;
    }
}

class ExpressionTree {

    public boolean isOperator(char maybe_operator) {
        return (maybe_operator == '+' ||
                maybe_operator == '-' ||
                maybe_operator == '*' ||
                maybe_operator == '/' ||
                maybe_operator == '^');
    }

    // print tree inorder traversal
    public void inorder(Node tree) {
        if (tree != null) {
//            System.out.print("(");
            inorder(tree.left);
            System.out.print(tree.value + " ");
            inorder(tree.right);
//            System.out.print(")");
        }
    }

    // Returns root of constructed tree for given
    // postfix expression
    Node constructTree(char postfix[]) {
        Stack<Node> st = new Stack();
        Node t, t1, t2;

        // Traverse through every character of
        // input expression
        for (char aPostfix : postfix) {

            // If operand, simply push into stack
            if (!isOperator(aPostfix)) {
                t = new Node(aPostfix);
                st.push(t);
            } else // operator
            {
                t = new Node(aPostfix);

                // Pop two top nodes
                // Store top
                t1 = st.pop();     // Remove top
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

