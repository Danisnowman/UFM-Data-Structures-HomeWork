package com.danisnowman;

public class Saldos {
    private int pagado = 0;
    private int faltaDePago = 0;
    private int cantidad = 0;

    public void setCantidad(int cantidad){
        this.cantidad = cantidad;
    }

    public int getCantidad(){
        return this.cantidad;
    }

    public int getTotal(){
        return pagado;
    }




}
