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
public class ExpressionTree {

    // A utility function to check if 'c'
    // is an operator

    private boolean check_is_operator(char unverified_char) {
    return (unverified_char == '+' || unverified_char == '-' || unverified_char == '*' || unverified_char == '/' || unverified_char == '^');
    }

    // Utility function to do inorder traversal
    void inorder(Node tree) {
        if (tree != null) {
            inorder(tree.left);
            System.out.print(tree.value + " ");
            inorder(tree.right);
        }
    }

    void differentiate_in_order(Node tree){
        if (tree != null) {
            differentiate_in_order(tree.left);
//            System.out.print(tree.value + " ");
            if (tree.value == '*' && Character.isDigit(tree.left.value) && Character.isAlphabetic(tree.right.value)){
                tree.right.value = 1;
            } else if (tree.value == '*' && Character.isDigit(tree.right.value) && Character.isAlphabetic(tree.left.value)){
                tree.left.value = 1;
            } else if (tree.value == '+' && Character.isDigit(tree.left.value) && Character.isAlphabetic(tree.left.value)){
                tree.left.value = 0;
                tree.right.value = 1;
            } else if (tree.value == '^'){

            }
            System.out.print(tree.value + " ");
            differentiate_in_order(tree.right);
        }
    }

    // Returns root of constructed tree for given
    // postfix expression
    Node constructTree(char postfix[]) {
        Stack<Node> stack = new Stack();
        Node tree, tree1, tree2;

        // Traverse through every character of
        // input expression
        for (int i = 0; i < postfix.length; i++) {

            // If operand, simply push into stack
            if (!check_is_operator(postfix[i])) {
                tree = new Node(postfix[i]);
                stack.push(tree);
            } else // operator
            {
                tree = new Node(postfix[i]);

                // Pop two top nodes
                // Store top
                tree1 = stack.pop();      // Remove top
                tree2 = stack.pop();

                //  make them children
                tree.right = tree1;
                tree.left = tree2;

                // System.out.println(tree1 + "" + tree2);
                // Add this subexpression to stack
                stack.push(tree);
            }
        }

        //  only element will be root of expression
        // tree
        tree = stack.peek();
        stack.pop();

        return tree;
    }

}
