import java.util.Stack;

public class ShuntingYard {

/*    public static void main(String[] args) {
        String infix = " 3 * x ^ 2 * ( x ^ 2 + 1 ) ^ ( 1 / 2 ) + e ^ ( 2 * x )";
        System.out.printf("infix:   %s%n", infix);
        System.out.printf("postfix: %s%n", infixToPostfix(infix));
    }*/

    public static String infixToPostfix(String infix) {
        /* To find out the precedence, we take the index of the
           token in the ops string and divide by 2 (rounding down).
           This will give us: 0, 0, 1, 1, 2 */
        final String ops = "-+/*^";

        StringBuilder stringbuilder = new StringBuilder();
        Stack<Integer> stack = new Stack<>();

        for (String token : infix.split("\\s")) {
            if (token.isEmpty())
                continue;
            char c = token.charAt(0);
            int idx = ops.indexOf(c);

            // check for operator
            if (idx != -1) {
                if (stack.isEmpty())
                    stack.push(idx);

                else {
                    while (!stack.isEmpty()) {
                        int prec2 = stack.peek() / 2;
                        int prec1 = idx / 2;
                        if (prec2 > prec1 || (prec2 == prec1 && c != '^'))
                            stringbuilder.append(ops.charAt(stack.pop())).append(' ');
                        else break;
                    }
                    stack.push(idx);
                }
            }
            else if (c == '(') {
                stack.push(-2); // -2 stands for '('
            }
            else if (c == ')') {
                // until '(' on stack, pop operators.
                while (stack.peek() != -2)
                    stringbuilder.append(ops.charAt(stack.pop())).append(' ');
                stack.pop();
            }
            else {
                stringbuilder.append(token).append(' ');
            }
        }
        while (!stack.isEmpty())
            stringbuilder.append(ops.charAt(stack.pop())).append(' ');
        return stringbuilder.toString();
    }
}