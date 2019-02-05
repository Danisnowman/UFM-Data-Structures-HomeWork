package com.danisnowman;

public class Catalogo {
    public Product[] catalogo = new Product[10];

    public Catalogo (){
        for (int i = 0; i < 10; i++) {
            catalogo[i] = new Product("Producto "+i,i+1,(i+1)*20);
        }
    }

    public Product[] getCatalogo(){
        return catalogo;
    }

    public void printCatalogo(){
        for (int i = 0; i <10; i++) {
            System.out.println("Nombre: " + catalogo[i].getName());
            System.out.println("Código: " + catalogo[i].getCode());
            System.out.println("Precio: Q." + catalogo[i].getPrice());
            System.out.println("");
        }
    }

    public int getPrecioPorCodigo(int codigo){
        int precio = 0;
        for (int i = 0; i < 10 ; i++) {
            if(catalogo[i].getCode() == codigo){
            precio = catalogo[i].getPrice();
            }else System.out.println("Not found!");
        } return precio;
    }

    public int promedioDePrecios(){
        int total = 0;
        for (int i = 0; i < 10 ; i++) {
            total += catalogo[i].getPrice();
        } return total/catalogo.length;
    }

}
