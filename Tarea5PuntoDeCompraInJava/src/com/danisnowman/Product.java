package com.danisnowman;

public class Product {
    String name;
    int code;
    int price;

    public Product (String name, int code, int price){
        this.name = name;
        this.code = code;
        this.price = price;
    }

    public String getName(){
        return this.name;
    }

    public int getCode(){
        return this.code;
    }

    public int getPrice(){
        return this.price;
    }
}
