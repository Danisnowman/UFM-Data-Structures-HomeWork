
class Differentiate {


    public boolean check_if_constant(char tree_value){
        return ((Character.isDigit(tree_value) || Character.isAlphabetic(tree_value)) && tree_value != 'x');
    }

    public boolean isNumeric(String strNum) {
        return strNum.matches("-?\\d+(\\.\\d+)?");
    }

    public String restar_exp(String exp){
        if (isNumeric(exp)){
            return String.valueOf(Integer.parseInt(exp)-1);
        } else
            return String.valueOf(exp + "-1");
    }

    // DIFFERENTIATES EXPONENTIAL FUNCTIONS
    String derivate(Node tree){
        String differentiated = "";
        String exp = "";
        // x^2 LEFT
        if (tree.value == '^'){
            // If izq de exp es x y der de exp es constante, agregar a differentiated el valor de der
            if (tree.left.value == 'x' && check_if_constant(tree.right.value)){
                exp = String.valueOf(tree.right.value);
                differentiated += String.valueOf(tree.right.value) + " * " + String.valueOf(tree.left.value) + " ^ " + "(" + restar_exp(exp) + ")" ;
            }
            // e^x RIGHT
            else if (tree.right.value == 'x' && check_if_constant(tree.left.value))
                differentiated += String.valueOf(tree.left.value) + " ^ " + String.valueOf(tree.right.value);
            else if (tree.right.right != null){
                check_if_constant(tree.right.right.value);
                differentiated += String.valueOf(tree.right.right.value) + " * " + String.valueOf(tree.left.value) + " ^ " + String.valueOf(tree.right.value);
            }
        }
        if (tree.value == '+' || tree.value == '-') {
            // x + a
            if (check_if_constant(tree.right.value) && tree.left.value == 'x') {
                differentiated += "1" + " " + String.valueOf(tree.value) + " 0 ";
            } // a + b
            else if (check_if_constant(tree.right.value) && check_if_constant(tree.left.value)) {
                differentiated += "0" + " " + String.valueOf(tree.value) + " 0 ";
            }
            else if (tree.right.value == 'x' && tree.left.value == 'x'){
                differentiated += "1 + 1 ";
            }

        }
        return differentiated;
    }
}
