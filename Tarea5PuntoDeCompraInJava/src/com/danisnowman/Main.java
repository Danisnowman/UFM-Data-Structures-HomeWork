package com.danisnowman;

import java.util.Scanner;

public class Main {
    static boolean done = false;

    public static void main(String[] args) {
        Catalogo catalogo = new Catalogo();
        Scanner scanner = new Scanner(System.in);
        int option = 0;
        while(!done) {
            System.out.println("1. Comprar\n0.Exit");
            System.out.print("Opción: ");
            option = scanner.nextInt();
            switch (option){
                case 1:
                    catalogo.printCatalogo();
                    System.out.println("Código: ");
                    int selection = scanner.nextInt();
                    break;

                case 0:
                    done = true;
                    break;
            }
        }

    }
}
