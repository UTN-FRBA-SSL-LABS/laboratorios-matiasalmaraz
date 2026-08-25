#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

void test_compra_con_descuento()
{
    printf("\n[total: cinco productos, cantidad 1]\n");
    Carrito c;
    carrito_init(&c);
    
    Producto p1 = {"Pan", 200, 3};
    carrito_agregar(&c, p1);

    Producto p2 = {"Leche", 350, 2};
    carrito_agregar(&c, p2);

    ASSERT_IGUAL(1300, carrito_total(&c));
    ASSERT_IGUAL(1170, carrito_descuento(carrito_total(&c), 10));
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */

void test_agregar_hasta_llenar()
{
    printf("\n[total: cinco productos, cantidad 1]\n");
    Carrito c;
    carrito_init(&c);
    
    Producto p = {"Leche", 350, 2};
    carrito_agregar(&c, p);
    
    Producto p2 = {"Frutas", 200, 2};
    carrito_agregar(&c, p2);
    
    Producto p3 = {"Verduras", 100, 2};
    carrito_agregar(&c, p3);
    
    Producto p4 = {"Pan", 550, 2};
    carrito_agregar(&c, p4);

    Producto p5 = {"Carne", 1000, 1};

    ASSERT_IGUAL(0, carrito_agregar(&c, p5));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
