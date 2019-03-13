
public class Differentiate {

    private boolean check_if_constant(char tree_value){
        return ((Character.isDigit(tree_value) || Character.isAlphabetic(tree_value)) && tree_value != 'x');
    }

    private static boolean isNumeric(String strNum) {
        return strNum.matches("-?\\d+(\\.\\d+)?");
    }

    private String restar_exp(String exp){
        if (isNumeric(exp)){
            return String.valueOf(Integer.parseInt(exp)-1);
        } else
            return String.valueOf(exp + "-1");
    }

    String exp_diff(Node tree){
        String differentiated = "";
        String exp = "";
        // LEFT
        if (tree.value == '^'){
            // If izq de exp es x y der de exp es constante, agregar a differentiated el valor de der
            if (tree.left.value == 'x' && check_if_constant(tree.right.value)){
                if (tree.left.left != null /*&& tree.left.left.right != null*/){
                    if (tree.left.left.value == '/'){
                        exp += tree.left.value + tree.left.left.value + tree.left.left.left.value;
                    }
                } else
                    exp = String.valueOf(tree.right.value);
                differentiated = String.valueOf(tree.right.value) + " * " + String.valueOf(tree.left.value) + " ^ " + "(" + restar_exp(exp) + ")" ;
            }
        }
        // RIGHT
        if (tree.value == '^'){
            // If der de exp es x e izq de exp es constante, agregar a differentiated el valor de izq
            if (tree.right.value == 'x' && check_if_constant(tree.left.value)){
                differentiated = String.valueOf(tree.left.value) + " * " + String.valueOf(tree.right.value) + " ^ " + String.valueOf(tree.right.value - 1);
            }
        }
        return differentiated;
    }

}
