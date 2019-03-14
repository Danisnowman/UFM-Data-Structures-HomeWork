
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
//        System.out.println("tree.v " + tree.value);
//        System.out.println("tree.left "+ tree.left.value);
//        System.out.println("tree.right "+ tree.right.value);
//        System.out.println("tree.left.left "+ tree.left.left.value);
//        System.out.println("tree,left,left.left " + tree.left.left.left.value);
//        System.out.println("tree.left.right "+ tree.left.right.value);
//        System.out.println("tree.left.right.left " + tree.left.right.left.value);
//        System.out.println("tree.left.right.right " + tree.left.right.right.value);
//
//        System.out.println("tree.right.right "+ tree.right.right.value);
//        System.out.println("tree.right.left "+ tree.right.left.value);

        String differentiated = "";
        String exp = "";
        // x^2 LEFT
        if (tree.value == '^'){
                // If izq de exp es x y der de exp es constante, agregar a differentiated el valor de der
                if (tree.left.value == 'x' && check_if_constant(tree.right.value)){
//                    System.out.println("IF 1");
                    exp = String.valueOf(tree.right.value);
//                    differentiated += String.valueOf(tree.right.value) + " * " + String.valueOf(tree.left.value) + " ^ " + "(" + restar_exp(exp) + ")" ;
                    System.out.print(String.valueOf(tree.right.value) + " * " + String.valueOf(tree.left.value) + " ^ " + "(" + restar_exp(exp) + ")");
                    derivate(tree.left);
                }
                // a^x RIGHT
                else if (tree.right.value == 'x' && check_if_constant(tree.left.value)) {
                    if (tree.left.value != 'e') {
//                        System.out.println("IF 2");
                        //                    differentiated += String.valueOf(tree.left.value) + " ^ " + String.valueOf(tree.right.value);
                        System.out.print(String.valueOf(tree.left.value) + " ^ " + String.valueOf(tree.right.value + " * ln(" + tree.left.value + ") "));
                    }
                    else {
                        System.out.println(String.valueOf(tree.left.value) + " ^ " + String.valueOf(tree.right.value));
                    }
                    derivate(tree.left);
                }
                // a ^ ( a * x )
                else if (tree.right.value == '*'){
//                    System.out.println("IF 3");
//                    differentiated += String.valueOf(tree.right.left.value) + " * " + String.valueOf(tree.left.value) + " ^ ( " + String.valueOf(tree.right.left.value) + " * " + String.valueOf(tree.right.right.value) + " ) ";
                    System.out.print(" ( " + String.valueOf(tree.right.left.value) + " * " + String.valueOf(tree.left.value) + " ^ ( " + String.valueOf(tree.right.left.value) + " * " + String.valueOf(tree.right.right.value) + " ) " + " ) " );
                    derivate(tree.left);
                }
//                else if (tree.right.right != null){
//                    System.out.println("IF 4");
//                    check_if_constant(tree.right.right.value);
//                    differentiated += String.valueOf(tree.right.right.value) + " * " + String.valueOf(tree.left.value) + " ^ " + String.valueOf(tree.right.value);
//                }
        }
        if (tree.value == '+' || tree.value == '-') {
                // x + a
                if (check_if_constant(tree.right.value) && tree.left.value == 'x') {
//                    System.out.println("IF 4");
//                    differentiated += "1" + " " + String.valueOf(tree.value) + " 0 ";
                    System.out.print("1" + " " + String.valueOf(tree.value) + " 0 ");
                    derivate(tree.left);
                } // a + b
                else if (check_if_constant(tree.right.value) && check_if_constant(tree.left.value)) {
//                    System.out.println("IF 5");
//                    differentiated += "0" + " " + String.valueOf(tree.value) + " 0 ";
                    System.out.print("0" + " " + String.valueOf(tree.value) + " 0 ");
                    derivate(tree.left);
                } // x + x
                else if (tree.right.value == 'x' && tree.left.value == 'x'){
//                    System.out.println("IF 5");
//                    differentiated += "1 + 1 ";
                    System.out.print("1 + 1 ");
                    derivate(tree.left);
                } // ends with const
                else if (check_if_constant(tree.right.value) && tree.left.value == '^'){
//                    System.out.println("IF 6");
                    differentiated += " + 0 ";
//                    System.out.print(" + 0 ");
                    derivate(tree.left);
                } // has two * (one at each branch)
                else if (tree.right.value == '*' && tree.left.value == '*' ){
                    System.out.println("THIS 1");
                    derivate(tree.left);
                }
        }
        return differentiated;
    }
}
