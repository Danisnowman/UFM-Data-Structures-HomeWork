// 3 * x ^ 2 * ( x ^ 2 + 1 ) ^ ( 1 / 2 ) + e ^ ( 2 * x )
// 3 * x ^ 2 * ( x ^ 2 + 1 ) ^ ( 1 / 2 ) + e ^ ( 2 * x )
// 3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3

public class  Main {
    public static void main(String[] args) {
//        Scanner scanf = new Scanner(System.in);
        ExpressionTree algebraic_tree = new ExpressionTree();
        Differentiate diff = new Differentiate();
//        System.out.println("Enter an infix expression:");
//        String infix = scanf.nextLine();
//        String infix = "3 * x ^ 2 * ( x ^ 2 + 1 ) ^ ( 1 / 2 ) + e ^ ( 2 * x )";
          String infix = "x + x";
        System.out.printf("infix:   %s%n", infix);
        String postfix =  ShuntingYard.infixToPostfix(infix);
        System.out.printf("postfix: %s%n", postfix);
        char[] charArray = postfix.replaceAll("\\s","").toCharArray();
        Node root = algebraic_tree.constructTree(charArray);
//        BTreePrinterTest.main(root);
        System.out.print("infix read from tree: ");
        algebraic_tree.inorder(root);
        System.out.println("\n\n Derivative:");
        System.out.println(diff.derivate(root));

    }
}
